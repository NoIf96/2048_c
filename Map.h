#pragma once
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

/***************************
 *         地图类          *
 ***************************/

class Map
{
public:
	Map();
	~Map();
	void SeleMap(int sele);     //选择地图
	void CreatMapSize_4();      //4*4地图构造函数
	void CreatMapSize_5();      //5*5地图构造函数
	void display_map(int size, int map_num[9][9]); // 数据和模块图转化

private:

};












#endif
