#pragma once
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

/***************************
 *         ��ͼ��          *
 ***************************/

class Map
{
public:
	Map();
	~Map();
	void SeleMap(int sele);     //ѡ���ͼ
	void CreatMapSize_4();      //4*4��ͼ���캯��
	void CreatMapSize_5();      //5*5��ͼ���캯��
	void display_map(int size, int map_num[9][9]); // ���ݺ�ģ��ͼת��

private:

};












#endif
