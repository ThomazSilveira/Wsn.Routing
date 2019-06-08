#include "InputClass.h"



InputClass::InputClass(double **matriz, conexao *conexoes, Nodo *nodos)
{
	this->MatrizMapa = matriz;
	this->Conexoes = conexoes;
	this->Nodos = nodos;
}

InputClass::InputClass()
{
}

InputClass::~InputClass()
{
}
