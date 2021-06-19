# include <stdio.h>
# include <Windows.h>
// # include <shooting_game.h>

void gotoXY(int x, int y);


int main(void) {

	int attacker_X = 60, attacker_Y = 20;
	int bx = 0, by = 0;
	int bullet = 0;

	// 1. �ܼ� â ũ�� ����
	system("mode con cols=80 lines=40");
	gotoXY(attacker_X, attacker_Y);
	printf("*");

	// 2. ����Ű �Է� ó�� 
	while (1) {
		int key;
		if (kbhit() == 0) {

			key = getch();
			if (key == 224) {
				key = getch();
				switch (key) {
				case 72: // up
					gotoXY(attacker_X, attacker_Y);		// �� �� �������� ������: ���� ��� -> ���� ���
					printf(" ");							// �ܻ� ��� cls�� �ذ�
					attacker_Y--;						// (0,0)�� �»��, ���� �����̷��� - ����
					break;
				case 75: // left
					gotoXY(attacker_X, attacker_Y);
					printf(" ");
					attacker_X--;
					break;
				case 77: //right
					gotoXY(attacker_X, attacker_Y);
					printf(" ");
					attacker_X++;
					break;
				case 80: // down
					gotoXY(attacker_X, attacker_Y);
					printf(" ");
					attacker_Y++;
					break;
				default:
					break;
				}
				gotoXY(attacker_X, attacker_Y);
				printf("*");
			}
			if (key == 32) {				// spacebar - (ASCII) DEC: 32
				bx = attacker_X;
				by = attacker_Y - 1;
				bullet = 1;

			}
		}
		while (bullet) {
			gotoXY(bx, by);
			printf("!");
			by--;
			gotoXY(bx, by + 1);
			printf(" ");
			Sleep(100);
			if (by < 0) bullet = 0;
		}
	}
	return 0;
}


void gotoXY(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}