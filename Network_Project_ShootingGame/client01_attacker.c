# include <stdio.h>
# include <Windows.h>
// # include <shooting_game.h>

void gotoXY(int x, int y);
void MakeBullet(int x, int y, int iter);

typedef struct position { // position ����ü ����
	int x;
	int y;
} position;

position bullet[100] = { 0, 0 }; // �Ѿ� ��ġ ������ �迭 ���� �� �ʱ�ȭ

int main(void) {

	int attacker_X=60, attacker_Y=20;
	int iter = 0;

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
					attacker_Y --;						// (0,0)�� �»��, ���� �����̷��� - ����
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
				// �Ѿ� ���� �Լ�(MakeBullet()) ȣ��, �Ѿ��� (1�ʸ��� �ڵ����� ���� �̵�) -> �׳� �ݺ����������� -1
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
	bullet[iter] = pos;							// �»���� (0,0)�̴ϱ� ���� �߻��Ϸ��� - �ؾ���
}

void gotoXY(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}