#include "bird.h"
#include <iostream>

int main()
{
	Lark lark_0;
	std::cout << lark_0.pos.x << lark_0.pos.y << lark_0.pos.z << std::endl;
	lark_0.Fly();
	std::cout << lark_0.pos.x << lark_0.pos.y << lark_0.pos.z << std::endl;

	return 0;
}