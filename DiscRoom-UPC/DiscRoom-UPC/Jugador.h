#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "Personaje.h"
enum Direcciones { Arriba, Abajo, Izquierda, Derecha, Ninguno };

class CJugador :public CPersonaje
{
public:
	CJugador(int x, int y) : CPersonaje(x, y)
	{
		this->x = x;
		this->y = y;
		dx = 0;
		dy = 0;
		ancho = 25;
		alto = 60;
		indiceX = 0;
		indiceY = 0;

		direcciones = Direcciones::Ninguno;
		ultimaT = Direcciones::Abajo;
	}
	void setDirecciones(Direcciones direccion)
	{
		this->direcciones = direccion;
	}
	void dibujar(Graphics^g, Bitmap ^bmpBatman)
	{
		//CDI=Rectangle
		Rectangle usar = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
		Rectangle hacerGrande = Rectangle(x, y, ancho * 2, alto * 2);
		g->DrawImage(bmpBatman, hacerGrande, usar, GraphicsUnit::Pixel);
		
		if (dx < 0 )
		{
			if((x + dx) >= 60)
				x +=  dx;
		}
		else
		{
			if ((x + dx) <= 410)
				x +=  dx;
		}

		if (dy < 0)
		{
			if ((y + dy) >= 10)
				y +=  dy;
		}
		else
		{
			if ((y + dy) <= 370)
				y += dy;
		}
		
	}
	void mover(Graphics^g, Bitmap ^bmpBatman)
	{
		//	direcciones == Arriba ? ancho = 17 : ancho = 18;
		switch (direcciones)
		{
		case Direcciones::Arriba:
			indiceX = 2;
			if (indiceY >= 1 && indiceY <= 2)
				indiceY++;
			else
				indiceY = 0;

			dx = 0;
			dy = -10;
			ultimaT = Arriba;
			break;
		case Direcciones::Abajo:
			indiceX = 0;
			if (indiceY >= 1 && indiceY <= 2)
				indiceY++;

			{
				indiceY = 0;
			}
			dx = 0;
			dy = 10;
			ultimaT = Abajo;
			break;
		case Direcciones::Izquierda:
			indiceX = 1;
			if (indiceY >= 1 && indiceY <= 2)
				indiceY++;
			else
			{
				indiceY = 0;
			}
			dx = -10;
			dy = 0;
			ultimaT = Izquierda;
			break;
		case Direcciones::Derecha:
			indiceX = 3;
			if (indiceY >= 1 && indiceY <= 2)
				indiceY++;
			else
			{
				indiceY = 0;
			}
			dx = 10;
			dy = 0;
			ultimaT = Derecha;
			break;
		case Direcciones::Ninguno:
			dx = 0;
			dy = 0;
			switch (ultimaT)
			{
			case Direcciones::Arriba:
				indiceX = 2;
				indiceY = 0;
				break;
			case Direcciones::Abajo:
				indiceX = 0;
				indiceY = 0;

				break;
			case Direcciones::Izquierda:
				indiceX = 1;
				indiceY = 0;

				break;
			case Direcciones::Derecha:
				indiceX = 3;
				indiceY = 0;

				break;
			}
			break;

		}
		dibujar(g, bmpBatman);
	}
	~CJugador() {}

private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	Direcciones direcciones;
	Direcciones ultimaT;

	Rectangle CDI;
	Rectangle CAA;
};



#endif // !_JUGADOR_H_


