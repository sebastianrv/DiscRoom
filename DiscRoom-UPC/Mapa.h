#ifndef _MAPA_H_
#define _MAPA_H_
using namespace System;
using namespace System::Drawing;

class CMapa
{
public:
	CMapa()
	{
	//	matriz = new int*[FILAS];
	}
	~CMapa(){}
	void dibujarNivel1(Graphics ^g, Bitmap ^bmpNivel1)
	{
		int ancho = bmpNivel1->Width;
		int alto = bmpNivel1->Height;
		Rectangle u = Rectangle(15, 50, ancho / 2.5, alto / 2.5);
		Rectangle p = Rectangle(0, 0, ancho, alto);
		g->DrawImage(bmpNivel1, u, p, GraphicsUnit::Pixel);
	}
//void crearMatriz()
//	{
//		for (int i = 0; i < FILAS; i++)
//		{
//			matriz[i] = new int[COLUMNAS];
//		}
//		for (int i = 0; i < FILAS; i++)
//		{
//			for (int j = 0; j < COLUMNAS; j++)
//			{
//				if (i == 0 || j == 0 || i == FILAS - 1 || j == COLUMNAS - 1)//bordes
//					matriz[i][j] = 1;
//			}
//		}
//	}

private:
//	int **matriz;
};

#endif // !_MAPA_H_
