#pragma once
#ifndef PIE_H_INCLUDED
#define PIE_H_INCLUDED

/***************************
 *          块类           *
 ***************************/

class Pie
{
public:
	Pie();                              //空块
	Pie(int Value, int Size);           //值块
	~Pie(); 
	void display_pie(int x, int y);     //打印块

private:
	int value;                          //块的值
	int size;                           //块的大小
};





#endif
