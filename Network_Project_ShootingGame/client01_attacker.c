# include <stdio.h>
# include <Windows.h>
// # include <shooting_game.h>

void gotoXY(int x, int y);
void MakeBullet(int x, int y, int iter);

typedef struct position { // position 구조체 정의
	int x;
	int y;
} position;

position bullet[100] = { 0, 0 }; // 총알 위치 저장할 배열 선언 및 초기화

int main(void) {

	int attacker_X=60, attacker_Y=20;
	int iter = 0;

	// 1. 콘솔 창 크기 지정
	system("mode con cols=80 lines=40");
	gotoXY(attacker_X, attacker_Y);
	printf("*");

	// 2. 방향키 입력 처리 
	while (1) {
		int key;
		if (kbhit() == 0) {

			key = getch();
			if (key == 224) {
				key = getch();
				switch (key) {
				case 72: // up
					gotoXY(attacker_X, attacker_Y);		// 이 두 라인으로 공격자: 연속 출력 -> 단일 출력
					printf(" ");							// 잔상 출력 cls로 해결
					attacker_Y --;						// (0,0)이 좌상단, 위로 움직이려면 - 연산
					break;
				case 75: // left
					gotoXY(attacker_X, attacker_Y);
					printf(" ");
					attacker_X --;
					break;
				case 77: //right
					gotoXY(attacker_X, attacker_Y);
					printf(" ");
					attacker_X ++;
					break;
				case 80: // down
					gotoXY(attacker_X, attacker_Y);
					printf(" ");
					attacker_Y ++;
					break;
				default:
					break;
				}
				gotoXY(attacker_X, attacker_Y);
				printf("*");
			}
			else if (key == 32) {				// spacebar - (ASCII) DEC: 32
				// 총알 생성 함수(MakeBullet()) 호출, 총알은 (1초마다 자동으로 위로 이동) -> 그냥 반복문돌때마다 -1
				MakeBullet(attacker_X, attacker_Y, iter);
				// for (int i = 0; i <= iter; i++) {
					gotoXY(bullet[iter].x, bullet[iter].y);
					//bullet[iter].y--;
					if (bullet[iter].y >= 0) {
						printf("!");
						bullet[iter].y = bullet[iter].y - 1;
					}
				//}
				iter++;
			}
			else {}
		}
	}
	return 0;
}

void MakeBullet(int x, int y, int iter) {
	position pos;
	pos.x = x;
	pos.y = y - 1;
	bullet[iter] = pos;							// 좌상단이 (0,0)이니까 위로 발사하려면 - 해야지
}

void gotoXY(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}