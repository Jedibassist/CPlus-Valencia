#include "stdafx.h"
#include "welcome.h"

LPCWSTR Hello = L"Hello";

welcome::welcome(void)
{
}

welcome::~welcome(void)
{
}

void welcome::sayHello(HDC &hdc)
{
	TextOut (hdc, 5, 5, Hello, 8);
}

