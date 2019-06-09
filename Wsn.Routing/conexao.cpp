#include "conexao.h"


conexao::conexao()
{
}

conexao::~conexao()
{
}

conexao::conexao(Nodo n1, Nodo n2, char energia)
{
	this->N1 = n1;
	this->N2 = n2;
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