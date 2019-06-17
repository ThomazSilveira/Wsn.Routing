#include "Nodo.h"

Nodo *Nodo::findNode(Nodo *nodos,int size, int id)
{
	for (int i = 0; i < size; i++)
		if (nodos[i].Id == id)
		{
			return &nodos[i];
		}
	return nullptr;
}

void Nodo::imprimeNodes(Nodo *nodos,int size) //deprecated
{
	std::cout << "Nodes" << std::endl;
	std::cout << "Qtd nodes" << size << std::endl;

	for (int i = 0; i < size; i++)
		std::cout << nodos[i].Id << " " << nodos[i].Coordenada.X << nodos[i].Coordenada.Y << std::endl;
}

Nodo::Nodo()
{
	this->Coordenada = *new Ponto();
	this->Id = '-';
}

Nodo::Nodo(Ponto ponto, int id)
{
	this->Coordenada = ponto;
	this->Id = id;
}

Nodo::~Nodo()
{
}
