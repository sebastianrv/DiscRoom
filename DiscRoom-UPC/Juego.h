#ifndef _JUEGO_H_
#define _JUEGO_H_
#include "Jugador.h"
#include "ArrDiscos.h"
#include "Mapa.h"

class CJuego
{
public:
	CJuego()
	{
		objJugador = new CJugador(70, 50);
	}
	void dibujarJuego(Graphics ^g, Bitmap^ bmpNivel1,Bitmap^bmpBatman)
	{
		objMapa->dibujarNivel1(g,bmpNivel1);
		objJugador->mover(g, bmpBatman);
	}
	CJugador * getObjJugador()
	{
		return objJugador;
	};
	~CJuego(){}

private:
	CMapa * objMapa;
	CJugador * objJugador;
};



#endif // !_JUEGO_H_

