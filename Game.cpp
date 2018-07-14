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

//size属性修改器
void Game::Set_size(int Size)
{
	size = Size;
}

//随机数据
void Game::rand_num()
{
	int r_n, r_i, r_j, n;
	//约束随机值
	uniform_int_distribution<unsigned> u(0, size - 1);
	default_random_engine e(seed);

	r_n = u(e);
	seed *= r_n * r_n;     //修改种子

	if (r_n % 2 || r_n % 3)
		n = 2;
	else
		n = 4;

	for (int i = 0;n;i++)
	{
		//获取随机地址
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

//主菜单，并返回玩家选择数据
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
	cout << "            1.4 * 4                        2. 5 * 5(木有) " << endl;
	Pos(12, 26);
	cout << " 请点击对应按键" << endl;

	Pos(18, 50);
	cout << "--双击ESC后退出--" << endl;
	Pos(20, 0);

	return sele = _getch();

}

//游戏集
void Game::Game_x()
{
	char flag_dir;

	//框架
	Table_line(0, 0, 120, '-');
	Table_llines(1, 20, 28, '|', 1, 0);
	Pos(3, 0);
	cout << "    W   " << endl;
	cout << " A  S  D  控制方向 " << endl;
	cout << "\n\n   ESC    返回 " << endl;

	//地图
	map.SeleMap(size);
	//初始随机块
	rand_num();
	rand_num();
	map.display_map(size, Map_Num);

	//操作
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
			cout << "退出游戏" << endl;
			break;

		default:
			Pos(29, 0);
			cout << "请键入W,S,A,D" << endl;
			break;
		}
		
		map.display_map(size, Map_Num);
		Pos(29, 0);

	} while (flag_dir != 27);
	system("cls");
}

//w操作
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

//s操作
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

//a操作
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

//s操作
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
