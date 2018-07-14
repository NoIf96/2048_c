#include<iostream>

#include "Map.h"
#include "Pie.h"
#include "tool_base.h"

/***************************
 *         地图类          *
 ***************************/

Map::Map()
{
}

Map::~Map()
{
}

//选择地图
void Map::SeleMap(int sele)
{
	switch (sele)
	{
	case 4:
		CreatMapSize_4();
		break;

	case 5:
		CreatMapSize_5();
		break;

	default:
		break;
	}
}

//构造4*4地图
void Map::CreatMapSize_4()
{
	Table_border(3, 40, 45, 25, '-', '|');
	Table_lines(9, 41, 43, '-', 3, 6);
	Table_llines(4, 51, 23, '|', 3, 11);
}

//5*5地图构造函数
void Map::CreatMapSize_5()
{
	Table_border(3, 40, 46, 26, '-', '|');
	Table_lines(8, 41, 44, '-', 4, 5);
	Table_llines(4, 49, 24, '|', 4, 9);
}



//数据块图转化
void Map::display_map(int size, int map_num[9][9])
{
	for (int i = 0;i < size;i++)
		for (int j = 0;j < size;j++) {
			Pie pie(map_num[i][j],size);
			pie.display_pie(i, j);
		}
}
