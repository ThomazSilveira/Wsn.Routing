#include "Nodo.h"

Nodo::Nodo()
{
	this->Coordenada = *new Ponto();
	this->Id = '-';
}

Nodo::Nodo(Ponto ponto, char id)
{
	this->Coordenada = ponto;
	this->Id = id;
}

Nodo::~Nodo()
{
}
