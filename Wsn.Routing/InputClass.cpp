#include "InputClass.h"
#include <algorithm>

InputClass::InputClass()
{
}

InputClass::~InputClass()
{
}

/*  Grafo com 5 nodos e leve simetria da posicao dos nodos. Mapa com 2 raios de interferencia */
void InputClass::Entrada_1()
{
	// Dados da Matriz
	this->linha = 6;
	this->coluna = 6;

	// Inicializa Linhas da Matriz
	this->MatrizMapa = new double* [this->linha];

	// Inicializa Colunas da Matriz
	for (int i = 0; i < this->linha; ++i) {
		this->MatrizMapa[i] = new double[this->coluna];
	}

	// Inicializa Valores da Matriz
	for (int i = 0; i < this->linha; i++) {
		for (int j = 0; j < this->coluna; j++) {
			this->MatrizMapa[i][j] = 0.1;
		}
	}
	
	// Valores Predefinidos
	this->MatrizMapa[2][0] = 1;
	this->MatrizMapa[2][1] = 1;
	this->MatrizMapa[3][1] = 1;
	this->MatrizMapa[3][0] = 2;
	this->MatrizMapa[4][1] = 1;
	this->MatrizMapa[4][0] = 1;

	this->MatrizMapa[5][1] = 1;
	this->MatrizMapa[4][2] = 1;
	this->MatrizMapa[4][3] = 1;
	this->MatrizMapa[5][3] = 1;
	this->MatrizMapa[5][2] = 2;

	// Inicializa Nodos
	this->totalNodos = 5;

	this->Nodos = new Nodo[this->totalNodos];
	this->Nodos[0] = *new Nodo(*new Ponto(0.8, 2.2), '0');
	this->Nodos[1] = *new Nodo(*new Ponto(2.2, 0.3), '1');
	this->Nodos[2] = *new Nodo(*new Ponto(2.1, 4.3), '2');
	this->Nodos[3] = *new Nodo(*new Ponto(5.2, 0.2), '3');
	this->Nodos[4] = *new Nodo(*new Ponto(5.4, 4.2), '4');

	// Inicializa Conexoes
	this->totalConexoes = 8;

	this->Conexoes = new conexao[this->totalConexoes];
	this->Conexoes[0] = *new conexao(Nodos[0].Coordenada, Nodos[1].Coordenada, -45);
	this->Conexoes[1] = *new conexao(Nodos[0].Coordenada, Nodos[2].Coordenada, -5);
	this->Conexoes[2] = *new conexao(Nodos[1].Coordenada, Nodos[2].Coordenada, -35);
	this->Conexoes[3] = *new conexao(Nodos[1].Coordenada, Nodos[3].Coordenada, -25);
	this->Conexoes[4] = *new conexao(Nodos[2].Coordenada, Nodos[4].Coordenada, -55);
	this->Conexoes[5] = *new conexao(Nodos[3].Coordenada, Nodos[4].Coordenada, -65);
	this->Conexoes[6] = *new conexao(Nodos[1].Coordenada, Nodos[4].Coordenada, -15);
	this->Conexoes[7] = *new conexao(Nodos[2].Coordenada, Nodos[3].Coordenada, -5);
}

/* Grafo de 10 nodos esparços. Mapa com 2 raios de interferencia */
void InputClass::Entrada_2()
{

}