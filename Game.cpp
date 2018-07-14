#include <iostream>
#include <conio.h>
#include <ctime>
#include <random>

#include "Game.h"
#include "Map.h"
#include "tool_base.h"

using namespace std;

Game::Game()
{
	srand((unsigned)time(NULL));
	seed = rand() % 10000;
	score = 0;
	size = 0;
}

Game::~Game()
{
}

//size�����޸���
void Game::Set_size(int Size)
{
	size = Size;
}

//�������
void Game::rand_num()
{
	int r_n, r_i, r_j, n;
	//Լ�����ֵ
	uniform_int_distribution<unsigned> u(0, size - 1);
	default_random_engine e(seed);

	r_n = u(e);
	seed *= r_n * r_n;     //�޸�����

	if (r_n % 2 || r_n % 3)
		n = 2;
	else
		n = 4;

	for (int i = 0;n;i++)
	{
		//��ȡ�����ַ
		default_random_engine e1((unsigned)(seed + i));
		default_random_engine e2((unsigned)(seed + 2*i));
		
		r_i = u(e1);
		r_j = u(e2);

		if (!Map_Num[r_i][r_j]) {
			Map_Num[r_i][r_j] = n;
			n = 0;
		}

	}
}

//���˵������������ѡ������
char Game::MainMenu()
{
	int pos_x, pos_y;
	char sele;

	pos_x = 3;    pos_y = 40;

	Table_border(2, 25, 68, 18, '-', '|');
	Table_line(8, 26, 66, '-');

	Posx(pos_x, pos_y);
	cout << " ---      ----       /        ---- " << endl;
	Posx(pos_x, pos_y);
	cout << "    |    |    |     /  |     |    |" << endl;
	Posx(pos_x, pos_y);
	cout << " ---     |    |    /   |      ---- " << endl;
	Posx(pos_x, pos_y);
	cout << "|        |    |    ----|---  |    |" << endl;
	Posx(pos_x, pos_y);
	cout << " ---      ----         |      ---- " << endl;

	Pos(10, 26);
	cout << "            1.4 * 4                        2. 5 * 5(ľ��) " << endl;
	Pos(12, 26);
	cout << " ������Ӧ����" << endl;

	Pos(18, 50);
	cout << "--˫��ESC���˳�--" << endl;
	Pos(20, 0);

	return sele = _getch();

}

//��Ϸ��
void Game::Game_x()
{
	char flag_dir;

	//���
	Table_line(0, 0, 120, '-');
	Table_llines(1, 20, 28, '|', 1, 0);
	Pos(3, 0);
	cout << "    W   " << endl;
	cout << " A  S  D  ���Ʒ��� " << endl;
	cout << "\n\n   ESC    ���� " << endl;

	//��ͼ
	map.SeleMap(size);
	//��ʼ�����
	rand_num();
	rand_num();
	map.display_map(size, Map_Num);

	//����
	do
	{
		flag_dir = _getch();

		switch (flag_dir)
		{
		case 'W':
		case 'w':
			op_w();
			rand_num();

			break;

		case 'S':
		case 's':
			op_s();
			rand_num();

			break;

		case 'A':
		case 'a':
			op_a();
			rand_num();

			break;

		case 'D':
		case 'd':
			op_d();
			rand_num();

			break;

		case 27:
			Pos(29, 0);
			cout << "�˳���Ϸ" << endl;
			break;

		default:
			Pos(29, 0);
			cout << "�����W,S,A,D" << endl;
			break;
		}
		
		map.display_map(size, Map_Num);
		Pos(29, 0);

	} while (flag_dir != 27);
	system("cls");
}

//w����
void Game::op_w()
{
	for (int i = 1;i < size;i++)
		for (int j = 0;j < size;j++) {
			int flag = 0;
			for (int k = i - 1;k >= 0;k--)
				if (Map_Num[i][j])
					if (!Map_Num[0][j]) {
						Map_Num[0][j] = Map_Num[i][j];
						Map_Num[i][j] = 0;
					}
					else if (Map_Num[k][j]) {
						if (Map_Num[k][j] == Map_Num[i][j] && !flag) {
							Map_Num[k][j] *= 2;
							Map_Num[i][j] = 0;
							flag = 1;
						}
						else if (!Map_Num[k + 1][j]) {
							Map_Num[k + 1][j] = Map_Num[i][j];
							Map_Num[i][j] = 0;
						}
						flag = 1;
					}
		}
}

//s����
void Game::op_s()
{
	for (int i = size-1;i >= 0;i--)
		for (int j = 0;j < size;j++) {
			int flag = 0;
			for (int k = i + 1;k < size;k++)
				if (Map_Num[i][j])
					if (!Map_Num[size-1][j]) {
						Map_Num[size-1][j] = Map_Num[i][j];
						Map_Num[i][j] = 0;
					}
					else if (Map_Num[k][j]) {
						if (Map_Num[k][j] == Map_Num[i][j] && !flag) {
							Map_Num[k][j] *= 2;
							Map_Num[i][j] = 0;
							flag = 1;
						}
						else if (!Map_Num[k - 1][j]) {
							Map_Num[k - 1][j] = Map_Num[i][j];
							Map_Num[i][j] = 0;
						}
						flag = 1;
					}
		}
}

//a����
void Game::op_a()
{
	for (int j = 1;j < size;j++)
		for (int i = 0;i < size;i++) {
			int flag = 0;
			for (int k = j - 1;k >= 0;k--)
				if (Map_Num[i][j])
					if (!Map_Num[i][0]) {
						Map_Num[i][0] = Map_Num[i][j];
						Map_Num[i][j] = 0;
					}
					else if (Map_Num[i][k]) {
						if (Map_Num[i][k] == Map_Num[i][j] && !flag) {
							Map_Num[i][k] *= 2;
							Map_Num[i][j] = 0;
							flag = 1;
						}
						else if (!Map_Num[i][k + 1]) {
							Map_Num[i][k + 1] = Map_Num[i][j];
							Map_Num[i][j] = 0;
						}
						flag = 1;
					}
		}
}

//s����
void Game::op_d()
{
	for (int j = size-1;j >= 0;j--)
		for (int i = 0;i < size;i++) {
			int flag = 0;
			for (int k = j + 1;k < size;k++)
				if (Map_Num[i][j])
					if (!Map_Num[i][size-1]) {
						Map_Num[i][size-1] = Map_Num[i][j];
						Map_Num[i][j] = 0;
					}
					else if (Map_Num[i][k]) {
						if (Map_Num[i][k] == Map_Num[i][j] && !flag) {
							Map_Num[i][k] *= 2;
							Map_Num[i][j] = 0;
							flag = 1;
						}
						else if (!Map_Num[i][k - 1]) {
							Map_Num[i][k - 1] = Map_Num[i][j];
							Map_Num[i][j] = 0;
						}
						flag = 1;
					}
		}
}
