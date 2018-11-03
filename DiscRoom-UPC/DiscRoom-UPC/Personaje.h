#ifndef _PERSONAJE_H_
#define _PERSONAJE_H_
using namespace System;
using namespace System::Drawing;
class CPersonaje
{
public:
	CPersonaje(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	~CPersonaje() {}

	virtual void dibujar(Graphics^g, Bitmap^bmpBatman) abstract;
protected:
	int x;
	int y;

};

#endif // !_PERSONAJE_H_

