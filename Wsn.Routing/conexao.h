#pragma once
#include "Ponto.h"
class conexao
{
	char energia;

public:
	Ponto P1;
	Ponto P2;

	conexao();
	~conexao();
	conexao(Ponto p1, Ponto p2, char energia);

	char getEnergia();
	void setEnergia(char energia);
};

