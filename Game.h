#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Map.h"
#include "Pie.h"


/***************************
 *         游戏集类        *
 ***************************/

class Game
{
public:
	Game();
	~Game();
	void Set_size(int Size);      //size属性修改器
	void rand_num();      //随机生成数据
	char MainMenu();              //主菜单
	void Game_x();                 //4*4游戏

	void op_w();                        //w操作
	void op_s();                        //s操作
	void op_a();                        //a操作
	void op_d();                        //d操作

private:
	Map map;                      //地图
	int Map_Num[9][9] = { 0 };    //游戏所用数据数组

	int score;
	int seed;
	int size;

};








#endif
