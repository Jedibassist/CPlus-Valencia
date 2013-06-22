#pragma once

class welcome
{
public:
	welcome(void);
	virtual ~welcome(void);
	
	static void sayHello(HDC &hdc);
	HWND MyButton;
};

