# include <windows.h>
# include <stdio.h>
#include <stdlib.h>
# include "console.h"
# include "shooting_game.h"
# include "Queue.h"



int main(void) {
	// 0. 지역변수들 선언
	int attacker_X = 40, attacker_Y = 20;
	// int bx = 0, by = 0;

	pos bullet, tmp;			// 총알 위치 저장 구조체
	Queue b_Queue;		// 총알 위치 저장할 큐
	InitQueue(&b_Queue, 70);
	// 1. 콘솔 창 크기 지정
	system("mode con cols=80 lines=40");
	

	// 2. 방향키 입력 처리 
	while (1) {
		int key;
		if (kbhit()) {									// 이전코드: kbhit() == 0

			key = getch();
			if (key == 224) {
				key = getch();
				switch (key) {
				case 72: // up						
					attacker_Y--;						
					break;
				case 75: // left
					attacker_X--;
					break;
				case 77: //right
					attacker_X++;
					break;
				case 80: // down
					attacker_Y++;
					break;
				default:
					break;
				}
				gotoXY(attacker_X, attacker_Y);
				printf("△");
			}
			if (key == 32) {				// spacebar - (ASCII) DEC: 32
				bullet.x = attacker_X;
				bullet.y = attacker_Y - 1;
				// b_Queue.Enqueue(bullet); 아 c언어는 메소드가 없었지
				Enqueue(&b_Queue, bullet);
			}
		} // if(kbhit() != 0)
	

		// Draw() 부분
		gotoXY(attacker_X, attacker_Y);
		printf("●");

		for (int i = 0; i < b_Queue.count; i++) {
			tmp = Dequeue(&b_Queue);
			gotoXY(tmp.x, tmp.y);
			printf("|");
			if (tmp.y > 0) {
				tmp.y--;
				Enqueue(&b_Queue, tmp);
			}
			else {
				printf(" ");
			}
		}

		Sleep(10);
		system("cls");
		 
	} // while(1) 끝
	
	DisposeQueue(&b_Queue);
	return 0;
}


