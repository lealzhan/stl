#include "bird.h"

Lark::Lark()
{
}
Lark::~Lark()
{
}

void Lark::Fly()
{
	pos.x = pos.x + 10;
	pos.y = pos.y + 10;
	pos.z = pos.z + 10;
}