#include "InputClass.h"

InputClass::InputClass()
{
}

InputClass::~InputClass()
{
}

void InputClass::PrintNodes()
{
	std::cout << "Nodes " << std::endl;
	std::cout << "Qtd nodes " << this->totalNodos << std::endl;

	for (int i = 0; i < this->totalNodos; i++)
		std::cout << this->Nodos[i].Id << " " << this->Nodos[i].Coordenada.X << " " << this->Nodos[i].Coordenada.Y << std::endl;

}

void InputClass::PrintConexoes()
{
	std::cout << "Conexoes " << std::endl;
	std::cout << "Qtd conexoes " << this->totalConexoes << std::endl;

	for (int i = 0; i < this->totalConexoes; i++)
		std::cout << this->Conexoes[i].N1.Id << " " << this->Conexoes[i].N2.Id << " " << this->Conexoes[i].getEnergia() << " " << this->Conexoes[i].getWeigth() << std::endl;

}

void InputClass::PrintMapa()
{
	std::cout << "Matriz" << std::endl;
	std::cout << "Qtd colunas X linhas " << this->coluna << " X " << this->linha << std::endl;


	for (int i = 0; i < this->coluna; i++)
	{
		for (int j = 0; j < this->linha; j++)
			std::cout << this->MatrizMapa[j][i];
		std::cout << endl;
	}

}

void InputClass::LeRede(string s)
{
	std::ifstream infile(s);

	if (!infile)
		return;

	string linha;

	getline(infile, linha);
	istringstream str(linha);
	int totalNodos;
	str >> totalNodos;

	this->totalNodos = totalNodos;
	this->Nodos = new Nodo[this->totalNodos];

	for (int i = 0; i < totalNodos; i++)
	{
		getline(infile, linha);
		istringstream str(linha);
		int id;
		double posX, posY;
		int energia;
		if (!(str >> id >> posX >> posY >> energia)) { break; }
		this->Nodos[i] = *new Nodo(*new Ponto(posX, posY), id);
	}

	PrintNodes();

	getline(infile, linha);
	istringstream str1(linha);
	int totalConexoes;
	str1 >> totalConexoes;

	this->totalConexoes = totalConexoes;
	this->Conexoes = new conexao[this->totalConexoes];

	for (int i = 0; i < this->totalConexoes; i++)
	{
		getline(infile, linha);
		istringstream str(linha);
		int n0, n1;
		int energia;
		if (!(str >> n0 >> n1 >> energia)) { break; }
		this->Conexoes[i] = *new conexao(Nodos->findNode(this->Nodos, this->totalNodos, n0), Nodos->findNode(this->Nodos, this->totalNodos, n1), energia);
	}

	PrintConexoes();

	infile.close();

}

void InputClass::LeMapa(string s)
{
	std::ifstream infile(s);

	if (!infile)
		return;

	string linha;

	getline(infile, linha);
	istringstream str(linha);
	int col = 0;
	int lin = 0;
	str >> col >> lin;

	// Dados da Matriz
	this->linha = lin;
	this->coluna = col;

	// Inicializa Linhas da Matriz
	this->MatrizMapa = new double*[this->linha];

	// Inicializa Colunas da Matriz
	for (int i = 0; i < this->linha; ++i) {
		this->MatrizMapa[i] = new double[this->coluna];
	}

	for (int i = 0; i < this->coluna; i++)
	{
		getline(infile, linha);
		istringstream str(linha);
		double element;
		for (int j = 0; j < this->linha; j++)
		{
			if (!(str >> element)) { break; }
			this->MatrizMapa[j][i] = element;
		}

		//this.MatrizMapa 


		//this->Nodos[i] = *new Nodo(*new Ponto(posX, posY), id);
	}

	PrintMapa();

	infile.close();
}

/*  Grafo com 5 nodos e leve simetria da posicao dos nodos. Mapa com 2 raios de interferencia */
void InputClass::Entrada_1()
{
	// Dados da Matriz
	this->linha = 6;
	this->coluna = 6;

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
	this->totalConexoes = 8 + 2;

	this->Conexoes = new conexao[this->totalConexoes];
	this->Conexoes[0] = *new conexao(Nodos[0], Nodos[1], -45);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[2], -5);
	this->Conexoes[2] = *new conexao(Nodos[1], Nodos[2], -35);
	this->Conexoes[3] = *new conexao(Nodos[1], Nodos[3], -25);
	this->Conexoes[4] = *new conexao(Nodos[2], Nodos[4], -55);
	this->Conexoes[5] = *new conexao(Nodos[3], Nodos[4], -65);
	this->Conexoes[6] = *new conexao(Nodos[1], Nodos[4], -15);
	this->Conexoes[7] = *new conexao(Nodos[2], Nodos[3], -5);

	this->Conexoes[8] = *new conexao(Nodos[0], Nodos[3], -45);
	this->Conexoes[9] = *new conexao(Nodos[0], Nodos[4], -45);

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
			this->MatrizMapa[i][j] = 1;//0.3;
		}
	}

	// TODO PEGAR VALORES DO MAPA

	// Valores Predefinidos
	// Ruido na parte Superior
	this->MatrizMapa[13][24] = 3;
	this->MatrizMapa[13][25] = 3;
	this->MatrizMapa[13][26] = 3;
	this->MatrizMapa[13][27] = 3;

	this->MatrizMapa[14][23] = 3;
	this->MatrizMapa[14][24] = 3;
	this->MatrizMapa[14][25] = 3;
	this->MatrizMapa[14][26] = 3;
	this->MatrizMapa[14][27] = 3;
	this->MatrizMapa[14][28] = 3;

	this->MatrizMapa[15][23] = 3;
	this->MatrizMapa[15][24] = 3;
	this->MatrizMapa[15][25] = 6;
	this->MatrizMapa[15][26] = 6;
	this->MatrizMapa[15][27] = 3;
	this->MatrizMapa[15][28] = 3;

	this->MatrizMapa[16][23] = 3;
	this->MatrizMapa[16][24] = 3;
	this->MatrizMapa[16][25] = 6;
	this->MatrizMapa[16][26] = 6;
	this->MatrizMapa[16][27] = 3;
	this->MatrizMapa[16][28] = 3;

	this->MatrizMapa[17][23] = 3;
	this->MatrizMapa[17][24] = 3;
	this->MatrizMapa[17][25] = 3;
	this->MatrizMapa[17][26] = 3;
	this->MatrizMapa[17][27] = 3;
	this->MatrizMapa[17][28] = 3;

	this->MatrizMapa[18][24] = 3;
	this->MatrizMapa[18][25] = 3;
	this->MatrizMapa[18][26] = 3;
	this->MatrizMapa[18][27] = 3;

	// Ruido na parte Inferior

	this->MatrizMapa[18][7] = 3;
	this->MatrizMapa[18][8] = 3;
	this->MatrizMapa[18][9] = 3;
	this->MatrizMapa[18][10] = 3;

	this->MatrizMapa[19][6] = 3;
	this->MatrizMapa[19][7] = 3;
	this->MatrizMapa[19][8] = 3;
	this->MatrizMapa[19][9] = 3;
	this->MatrizMapa[19][10] = 3;
	this->MatrizMapa[19][11] = 3;

	this->MatrizMapa[20][6] = 3;
	this->MatrizMapa[20][7] = 3;
	this->MatrizMapa[20][8] = 6;
	this->MatrizMapa[20][9] = 6;
	this->MatrizMapa[20][10] = 3;
	this->MatrizMapa[20][11] = 3;

	this->MatrizMapa[21][6] = 3;
	this->MatrizMapa[21][7] = 3;
	this->MatrizMapa[21][8] = 6;
	this->MatrizMapa[21][9] = 6;
	this->MatrizMapa[21][10] = 3;
	this->MatrizMapa[21][11] = 3;

	this->MatrizMapa[22][6] = 3;
	this->MatrizMapa[22][7] = 3;
	this->MatrizMapa[22][8] = 3;
	this->MatrizMapa[22][9] = 3;
	this->MatrizMapa[22][10] = 3;
	this->MatrizMapa[22][11] = 3;

	this->MatrizMapa[23][7] = 3;
	this->MatrizMapa[23][8] = 3;
	this->MatrizMapa[23][9] = 3;
	this->MatrizMapa[23][10] = 3;

	// Inicializa Nodos
	this->totalNodos = 10;

	this->Nodos = new Nodo[this->totalNodos];
	this->Nodos[0] = *new Nodo(*new Ponto(2.9, 1.7), 0);
	this->Nodos[1] = *new Nodo(*new Ponto(3.1, 4.8), 1);
	this->Nodos[2] = *new Nodo(*new Ponto(5.6, 2.2), 2);
	this->Nodos[3] = *new Nodo(*new Ponto(4.2, 11.8), 3);
	this->Nodos[4] = *new Nodo(*new Ponto(17.9, 5.3), 4);
	this->Nodos[5] = *new Nodo(*new Ponto(7.5, 20.5), 5);
	this->Nodos[6] = *new Nodo(*new Ponto(25.1, 15.1), 6);
	this->Nodos[7] = *new Nodo(*new Ponto(14.0, 26.0), 7);
	this->Nodos[8] = *new Nodo(*new Ponto(20.9, 28.7), 8);
	this->Nodos[9] = *new Nodo(*new Ponto(26.3, 29.5), 9);


	// Inicializa Conexoes
	this->totalConexoes = 45;

	this->Conexoes = new conexao[this->totalConexoes];
	this->Conexoes[0] = *new conexao(Nodos[0], Nodos[1], -5);
	this->Conexoes[1] = *new conexao(Nodos[0], Nodos[2], -5);
	this->Conexoes[2] = *new conexao(Nodos[0], Nodos[3], -5);
	this->Conexoes[3] = *new conexao(Nodos[0], Nodos[4], -5);
	this->Conexoes[4] = *new conexao(Nodos[0], Nodos[5], -5);
	this->Conexoes[5] = *new conexao(Nodos[0], Nodos[6], -5);
	this->Conexoes[6] = *new conexao(Nodos[0], Nodos[7], -5);
	this->Conexoes[7] = *new conexao(Nodos[0], Nodos[8], -5);
	this->Conexoes[8] = *new conexao(Nodos[0], Nodos[9], -5);

	this->Conexoes[9] = *new conexao(Nodos[1], Nodos[2], -5);
	this->Conexoes[10] = *new conexao(Nodos[1], Nodos[3], -5);
	this->Conexoes[11] = *new conexao(Nodos[1], Nodos[4], -5);
	this->Conexoes[12] = *new conexao(Nodos[1], Nodos[5], -5);
	this->Conexoes[13] = *new conexao(Nodos[1], Nodos[6], -5);
	this->Conexoes[14] = *new conexao(Nodos[1], Nodos[7], -5);
	this->Conexoes[15] = *new conexao(Nodos[1], Nodos[8], -5);
	this->Conexoes[16] = *new conexao(Nodos[1], Nodos[9], -5);

	this->Conexoes[17] = *new conexao(Nodos[2], Nodos[3], -5);
	this->Conexoes[18] = *new conexao(Nodos[2], Nodos[4], -5);
	this->Conexoes[19] = *new conexao(Nodos[2], Nodos[5], -5);
	this->Conexoes[20] = *new conexao(Nodos[2], Nodos[6], -5);
	this->Conexoes[21] = *new conexao(Nodos[2], Nodos[7], -5);
	this->Conexoes[22] = *new conexao(Nodos[2], Nodos[8], -5);
	this->Conexoes[23] = *new conexao(Nodos[2], Nodos[9], -5);

	this->Conexoes[24] = *new conexao(Nodos[3], Nodos[4], -5);
	this->Conexoes[25] = *new conexao(Nodos[3], Nodos[5], -5);
	this->Conexoes[26] = *new conexao(Nodos[3], Nodos[6], -5);
	this->Conexoes[27] = *new conexao(Nodos[3], Nodos[7], -5);
	this->Conexoes[28] = *new conexao(Nodos[3], Nodos[8], -5);
	this->Conexoes[29] = *new conexao(Nodos[3], Nodos[9], -5);

	this->Conexoes[30] = *new conexao(Nodos[4], Nodos[5], -5);
	this->Conexoes[31] = *new conexao(Nodos[4], Nodos[6], -5);
	this->Conexoes[32] = *new conexao(Nodos[4], Nodos[7], -5);
	this->Conexoes[33] = *new conexao(Nodos[4], Nodos[8], -5);
	this->Conexoes[34] = *new conexao(Nodos[4], Nodos[9], -5);

	this->Conexoes[35] = *new conexao(Nodos[5], Nodos[6], -5);
	this->Conexoes[36] = *new conexao(Nodos[5], Nodos[7], -5);
	this->Conexoes[37] = *new conexao(Nodos[5], Nodos[8], -5);
	this->Conexoes[38] = *new conexao(Nodos[5], Nodos[9], -5);

	this->Conexoes[39] = *new conexao(Nodos[6], Nodos[7], -5);
	this->Conexoes[40] = *new conexao(Nodos[6], Nodos[8], -5);
	this->Conexoes[41] = *new conexao(Nodos[6], Nodos[9], -5);

	this->Conexoes[42] = *new conexao(Nodos[7], Nodos[8], -5);
	this->Conexoes[43] = *new conexao(Nodos[7], Nodos[9], -5);

	this->Conexoes[44] = *new conexao(Nodos[8], Nodos[9], -5);
}