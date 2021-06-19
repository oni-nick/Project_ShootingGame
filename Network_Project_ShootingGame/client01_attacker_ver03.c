/*
* 0620 - am 1:10
스레드 생성해서 총알 찍는 함수, 매개변수 전달... 잘 안됨. 
*/

# include <stdio.h>
# include <Windows.h>
// # include <shooting_game.h>

void gotoXY(int x, int y);
unsigned WINAPI BulletThread(void* arg);

typedef struct bullet {
	int bx;
	int by;
	int is_bullet;
} bullet;

int main(void) {

	int attacker_X = 60, attacker_Y = 20;
	int bx = 0, by = 0;
	int is_bullet = 0;
	bullet blt; // 총알 위치 저장할 구조체, 스레드 함수에 넘겨줄 매개변수
	// 1. 콘솔 창 크기 지정
	system("mode con cols=80 lines=40");
	gotoXY(attacker_X, attacker_Y);
	printf("△");

	// 2. 방향키 입력 처리 
	while (1) {
		int key;
		if (kbhit()) {									// 이전코드: kbhit() == 0

			key = getch();
			if (key == 224) {
				key = getch();
				switch (key) {
				case 72: // up
					gotoXY(attacker_X, attacker_Y);		// 이 두 라인으로 공격자: 연속 출력 -> 단일 출력
					printf("  ");							// 잔상 출력 cls로 해결
					attacker_Y--;						// (0,0)이 좌상단, 위로 움직이려면 - 연산
					break;
				case 75: // left
					gotoXY(attacker_X, attacker_Y);
					printf("  ");
					attacker_X--;
					break;
				case 77: //right
					gotoXY(attacker_X, attacker_Y);
					printf("  ");
					attacker_X++;
					break;
				case 80: // down
					gotoXY(attacker_X, attacker_Y);
					printf("  ");
					attacker_Y++;
					break;
				default:
					break;
				}
				gotoXY(attacker_X, attacker_Y);
				printf("△");
			}
			if (key == 32) {				// spacebar - (ASCII) DEC: 32
				bx = attacker_X;
				by = attacker_Y - 2;
				is_bullet = 1;
				blt.bx = bx;
				blt.by = by;
				blt.is_bullet = is_bullet;
			}
		} // if(kbhit() != 0)
		if (is_bullet) {
			Sleep(500);
			_beginthreadex(NULL, 0, BulletThread, (void*)&blt, 0, 0);
		}
	} // while(1)
	return 0;
}


void gotoXY(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


unsigned WINAPI BulletThread(void* arg) {
	bullet blt = *(bullet*)arg;
	if (blt.is_bullet) {
		gotoXY(blt.bx, blt.by + 1);
		printf(" ");
		gotoXY(blt.bx, blt.by);
		printf("|");
		blt.by --;
		Sleep(100);
		if (blt.by < 0) {
			blt.is_bullet = 0;
			gotoXY(blt.bx, 0); // (bx, by); by는 -1이니까 안지워지지, 0으로해야지 
			printf(" ");
			return 0;
		}
		return 0;
	}

}