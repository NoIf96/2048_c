#include <iostream>

#include "Pie.h"
#include "tool_base.h"

using namespace std;

//空块
Pie::Pie()
{
	value = 0;
}

//值块
Pie::Pie(int Value,int Size)
{
	value = Value;
	size = Size;
}

Pie::~Pie()
{
}

//打印块
void Pie::display_pie(int x, int y)
{
	//坐标数组
	int posx[4] = { 6,12,18,24};
	int posy[4] = { 45,56,67,78};

	//定位光标
	if (size == 4) {
		Pos(posx[x], posy[y]);
		if (value)
			cout << value << "   ";
		else
			cout << "  ";
	}
	else if (size == 4) {
		Pos(posx[x]-2, posy[y]-2);
		if (value)
			cout << value << " ";
		else
			cout << "";
	}
}
