#pragma once
#ifndef PIE_H_INCLUDED
#define PIE_H_INCLUDED

/***************************
 *          ����           *
 ***************************/

class Pie
{
public:
	Pie();                              //�տ�
	Pie(int Value, int Size);           //ֵ��
	~Pie(); 
	void display_pie(int x, int y);     //��ӡ��

private:
	int value;                          //���ֵ
	int size;                           //��Ĵ�С
};





#endif
