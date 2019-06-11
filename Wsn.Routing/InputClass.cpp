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
	this->Nodos[0] = *new Nodo(*new Ponto(0.8, 2.2), 0);
	this->Nodos[1] = *new Nodo(*new Ponto(2.2, 0.3), 1);
	this->Nodos[2] = *new Nodo(*new Ponto(2.1, 4.3), 2);
	this->Nodos[3] = *new Nodo(*new Ponto(5.2, 0.2), 3);
	this->Nodos[4] = *new Nodo(*new Ponto(5.4, 4.2), 4);

	// Inicializa Conexoes
	this->totalConexoes = 8;

	this->Conexoes = new conexao[this->totalConexoes];
	this->Conexoes[0] = *new conexao(Nodos[0], Nodos[1], -45);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[2], -5);
	this->Conexoes[2] = *new conexao(Nodos[1], Nodos[2], -35);
	this->Conexoes[3] = *new conexao(Nodos[1], Nodos[3], -25);
	this->Conexoes[4] = *new conexao(Nodos[2], Nodos[4], -55);
	this->Conexoes[5] = *new conexao(Nodos[3], Nodos[4], -65);
	this->Conexoes[6] = *new conexao(Nodos[1], Nodos[4], -15);
	this->Conexoes[7] = *new conexao(Nodos[2], Nodos[3], -5);
}

void InputClass::Entrada_2()
{
	// Dados da Matriz
	this->linha = 30;
	this->coluna = 30;

	// Inicializa Linhas da Matriz
	this->MatrizMapa = new double*[this->linha];

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

	// TODO PEGAR VALORES DO MAPA

	// Valores Predefinidos
	// Ruido na parte Superior
	this->MatrizMapa[13][24] = 1;
	this->MatrizMapa[13][25] = 1;
	this->MatrizMapa[13][26] = 1;
	this->MatrizMapa[13][27] = 1;

	this->MatrizMapa[14][23] = 1;
	this->MatrizMapa[14][24] = 1;
	this->MatrizMapa[14][25] = 1;
	this->MatrizMapa[14][26] = 1;
	this->MatrizMapa[14][27] = 1;
	this->MatrizMapa[14][28] = 1;

	this->MatrizMapa[15][23] = 1;
	this->MatrizMapa[15][24] = 1;
	this->MatrizMapa[15][25] = 2;
	this->MatrizMapa[15][26] = 2;
	this->MatrizMapa[15][27] = 1;
	this->MatrizMapa[15][28] = 1;

	this->MatrizMapa[16][23] = 1;
	this->MatrizMapa[16][24] = 1;
	this->MatrizMapa[16][25] = 2;
	this->MatrizMapa[16][26] = 2;
	this->MatrizMapa[16][27] = 1;
	this->MatrizMapa[16][28] = 1;

	this->MatrizMapa[17][23] = 1;
	this->MatrizMapa[17][24] = 1;
	this->MatrizMapa[17][25] = 1;
	this->MatrizMapa[17][26] = 1;
	this->MatrizMapa[17][27] = 1;
	this->MatrizMapa[17][28] = 1;

	this->MatrizMapa[18][24] = 1;
	this->MatrizMapa[18][25] = 1;
	this->MatrizMapa[18][26] = 1;
	this->MatrizMapa[18][27] = 1;

	// Ruido na parte Inferior

	this->MatrizMapa[18][7] = 1;
	this->MatrizMapa[18][8] = 1;
	this->MatrizMapa[18][9] = 1;
	this->MatrizMapa[18][10] = 1;

	this->MatrizMapa[19][6] = 1;
	this->MatrizMapa[19][7] = 1;
	this->MatrizMapa[19][8] = 1;
	this->MatrizMapa[19][9] = 1;
	this->MatrizMapa[19][10] = 1;
	this->MatrizMapa[19][11] = 1;

	this->MatrizMapa[20][6] = 1;
	this->MatrizMapa[20][7] = 1;
	this->MatrizMapa[20][8] = 2;
	this->MatrizMapa[20][9] = 2;
	this->MatrizMapa[20][10] = 1;
	this->MatrizMapa[20][11] = 1;

	this->MatrizMapa[21][6] = 1;
	this->MatrizMapa[21][7] = 1;
	this->MatrizMapa[21][8] = 2;
	this->MatrizMapa[21][9] = 2;
	this->MatrizMapa[21][10] = 1;
	this->MatrizMapa[21][11] = 1;

	this->MatrizMapa[22][6] = 1;
	this->MatrizMapa[22][7] = 1;
	this->MatrizMapa[22][8] = 1;
	this->MatrizMapa[22][9] = 1;
	this->MatrizMapa[22][10] = 1;
	this->MatrizMapa[22][11] = 1;

	this->MatrizMapa[23][7] = 1;
	this->MatrizMapa[23][8] = 1;
	this->MatrizMapa[23][9] = 1;
	this->MatrizMapa[23][10] = 1;

	// Inicializa Nodos
	this->totalNodos = 10;

	this->Nodos = new Nodo[this->totalNodos];
	this->Nodos[0] = *new Nodo(*new Ponto(2.9, 1.7), 0);
	this->Nodos[1] = *new Nodo(*new Ponto(3.1, 4.8), 1);
	this->Nodos[2] = *new Nodo(*new Ponto(5.6, 2.2), 2);
	this->Nodos[3] = *new Nodo(*new Ponto(4.2, 11.8), 3);
	this->Nodos[4] = *new Nodo(*new Ponto(17.9, 5.3), 4);
	this->Nodos[4] = *new Nodo(*new Ponto(7.5, 20.5), 5);
	this->Nodos[4] = *new Nodo(*new Ponto(25.1, 15.1), 6);
	this->Nodos[4] = *new Nodo(*new Ponto(14.0, 26.0), 7);
	this->Nodos[4] = *new Nodo(*new Ponto(20.9, 28.7), 8);
	this->Nodos[4] = *new Nodo(*new Ponto(26.3, 29.5), 9);


	// Inicializa Conexoes
	this->totalConexoes = 45;

	this->Conexoes = new conexao[this->totalConexoes];
	this->Conexoes[0] = *new conexao(Nodos[0], Nodos[1], -5);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[2], -5);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[3], -5);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[4], -5);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[5], -5);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[6], -5);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[7], -5);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[8], -5);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[9], -5);

	this->Conexoes[1] = *new conexao(Nodos[1], Nodos[2], -5);
	this->Conexoes[1] = *new conexao(Nodos[1], Nodos[3], -5);
	this->Conexoes[1] = *new conexao(Nodos[1], Nodos[4], -5);
	this->Conexoes[1] = *new conexao(Nodos[1], Nodos[5], -5);
	this->Conexoes[1] = *new conexao(Nodos[1], Nodos[6], -5);
	this->Conexoes[1] = *new conexao(Nodos[1], Nodos[7], -5);
	this->Conexoes[1] = *new conexao(Nodos[1], Nodos[8], -5);
	this->Conexoes[1] = *new conexao(Nodos[1], Nodos[9], -5);

	this->Conexoes[1] = *new conexao(Nodos[2], Nodos[3], -5);
	this->Conexoes[1] = *new conexao(Nodos[2], Nodos[4], -5);
	this->Conexoes[1] = *new conexao(Nodos[2], Nodos[5], -5);
	this->Conexoes[1] = *new conexao(Nodos[2], Nodos[6], -5);
	this->Conexoes[1] = *new conexao(Nodos[2], Nodos[7], -5);
	this->Conexoes[1] = *new conexao(Nodos[2], Nodos[8], -5);
	this->Conexoes[1] = *new conexao(Nodos[2], Nodos[9], -5);

	this->Conexoes[1] = *new conexao(Nodos[3], Nodos[4], -5);
	this->Conexoes[1] = *new conexao(Nodos[3], Nodos[5], -5);
	this->Conexoes[1] = *new conexao(Nodos[3], Nodos[6], -5);
	this->Conexoes[1] = *new conexao(Nodos[3], Nodos[7], -5);
	this->Conexoes[1] = *new conexao(Nodos[3], Nodos[8], -5);
	this->Conexoes[1] = *new conexao(Nodos[3], Nodos[9], -5);

	this->Conexoes[1] = *new conexao(Nodos[4], Nodos[5], -5);
	this->Conexoes[1] = *new conexao(Nodos[4], Nodos[6], -5);
	this->Conexoes[1] = *new conexao(Nodos[4], Nodos[7], -5);
	this->Conexoes[1] = *new conexao(Nodos[4], Nodos[8], -5);
	this->Conexoes[1] = *new conexao(Nodos[4], Nodos[9], -5);

	this->Conexoes[1] = *new conexao(Nodos[5], Nodos[6], -5);
	this->Conexoes[1] = *new conexao(Nodos[5], Nodos[7], -5);
	this->Conexoes[1] = *new conexao(Nodos[5], Nodos[8], -5);
	this->Conexoes[1] = *new conexao(Nodos[5], Nodos[9], -5);

	this->Conexoes[1] = *new conexao(Nodos[6], Nodos[7], -5);
	this->Conexoes[1] = *new conexao(Nodos[6], Nodos[8], -5);
	this->Conexoes[1] = *new conexao(Nodos[6], Nodos[9], -5);

	this->Conexoes[1] = *new conexao(Nodos[7], Nodos[8], -5);
	this->Conexoes[1] = *new conexao(Nodos[7], Nodos[9], -5);

	this->Conexoes[1] = *new conexao(Nodos[8], Nodos[9], -5);
}