#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Map.h"
#include "Pie.h"


/***************************
 *         ��Ϸ����        *
 ***************************/

class Game
{
public:
	Game();
	~Game();
	void Set_size(int Size);      //size�����޸���
	void rand_num();      //�����������
	char MainMenu();              //���˵�
	void Game_x();                 //4*4��Ϸ

	void op_w();                        //w����
	void op_s();                        //s����
	void op_a();                        //a����
	void op_d();                        //d����

private:
	Map map;                      //��ͼ
	int Map_Num[9][9] = { 0 };    //��Ϸ������������

	int score;
	int seed;
	int size;

};








#endif
