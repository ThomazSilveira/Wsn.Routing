#pragma once
#include "Ponto.h"
#include "Nodo.h"

class conexao
{
	char energia;

public:
	Nodo N1;
	Nodo N2;

	conexao();
	~conexao();
	conexao(Nodo n1, Nodo n2, char energia);

	char getEnergia();
	void setEnergia(char energia);
};

