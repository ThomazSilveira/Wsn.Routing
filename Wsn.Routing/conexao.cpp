#include "conexao.h"


conexao::conexao()
{
}

conexao::~conexao()
{
}

conexao::conexao(Ponto p1, Ponto p2, char energia)
{
	P1 = p1;
	P2 = p2;
}

char conexao::getEnergia()
{
	return this->energia;
}

void conexao::setEnergia(char energia)
{
	// Valor de RSSI em dB
	if (energia >= -90 && energia <= 0) {
		this->energia = energia;
	}
}