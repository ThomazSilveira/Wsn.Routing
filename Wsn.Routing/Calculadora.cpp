#include "Calculadora.h"

using namespace std;

Calculadora::Calculadora()
{
}

Calculadora::~Calculadora()
{
}

double Calculadora::CalculaA(Ponto P1, Ponto P2)
{
	return ((P1.Y - P2.Y) / (P1.X - P2.X));
}

double Calculadora::CalculaB(Ponto P1, double A)
{
	return (P1.Y - (P1.X*A));
}

double Calculadora::CalculaY(Ponto P1, double A, double B)
{
	return ((P1.X*A) + B);
}

double Calculadora::CalculaX(Ponto P1, double A, double B)
{
	return ((P1.Y - B) / A);
}

vector<double> Calculadora::CalculaPontos(double X1, double X2)
{
	vector<double> retorno((int)floor(X2) - (int)floor(X1) + 2);
	retorno[0] = X1;
	for (int i = (int)ceil(retorno[0]); i < floor(X2) - floor(X1) + 1; i++)
	{
		retorno[i] = i;
	}

	retorno[(int)floor(X2) - (int)floor(X1) + 1] = X2;

	return retorno;
}

vector<Ponto> Calculadora::CalculaDimensaoVetor(Ponto P1, Ponto P2)
{
	if (P1.X > P2.X)
		return vector<Ponto>(abs((int)floor(P1.X) - (int)floor(P2.X)) + 1 + abs((int)floor(P2.Y) - (int)floor(P1.Y)) + 1);
	else
		return vector<Ponto>(abs((int)floor(P1.X) - (int)floor(P2.X)) + abs((int)floor(P2.Y) - (int)floor(P1.Y)) + 2);
}

vector<Ponto> Calculadora::CalculaPontosEmXY(Ponto P1, Ponto P2, double a, double b)
{
	int index = 1;
	vector<Ponto> retorno = CalculaDimensaoVetor(P1, P2);
	retorno[0] = P1;
	retorno[retorno.size() - 1] = P2;

#pragma region CalculaValoresDeX
	if (P1.X > P2.X)
	{
		int valor = (int)floor(retorno[0].X);
		for (int i = 0; i < floor(P1.X) - floor(P2.X); i++)
		{
			retorno[index] = *new Ponto(valor, 0);
			retorno[index].Y = CalculaY(retorno[index], a, b);
			valor--;
			index++;
		}
	}
	else if (P2.X > P1.X)
	{
		int valor = (int)ceil(retorno[0].X);
		for (int i = 0; i < floor(P2.X) - floor(P1.X); i++)
		{
			retorno[index] = *new Ponto(valor, 0);
			retorno[index].Y = CalculaY(retorno[index], a, b);
			valor++;
			index++;
		}
	}
#pragma endregion

#pragma region CalculaValoresDeY

	if (P1.Y > P2.Y)
	{
		int valor = (int)floor(retorno[0].Y);
		for (int i = 0; i < floor(P1.Y) - floor(P2.Y); i++)
		{
			retorno[index] = *new Ponto(0, valor);
			retorno[index].X = CalculaX(retorno[index], a, b);
			valor--;
			index++;
		}
	}
	if (P2.Y > P1.Y)
	{
		int valor = (int)ceil(retorno[0].Y);
		for (int i = 0; i < floor(P2.Y) - floor(P1.Y); i++)
		{
			retorno[index] = *new Ponto(0, valor);
			retorno[index].X = CalculaX(retorno[index], a, b);
			valor++;
			index++;
		}
	}

#pragma endregion

	return retorno;
}

vector<Ponto> Calculadora::CalculaPontosEmXY2(Ponto P1, Ponto P2, double a, double b)
{
	int index = 0;
	vector<Ponto> retorno(((int)floor(P2.X) - (int)floor(P1.X)) + ((int)floor(P2.Y) - (int)floor(P1.Y)) + 2);
	retorno[0] = P1;
	retorno[retorno.size() - 1] = P2;
	for (int i = (int)ceil(retorno[0].X); i < floor(P2.X) - floor(P1.X) + 1; i++)
	{
		retorno[i] = *new Ponto(i, 0);
		retorno[i].Y = CalculaY(retorno[i], a, b);
		index++;
	}

	for (int i = (int)ceil(P1.Y); i < floor(P2.Y) - floor(P1.Y) + 1; i++)
	{
		index++;
		retorno[index] = *new Ponto(0, i);
		retorno[index].X = CalculaX(retorno[index], a, b);
	}

	return retorno;
}

struct myclass {
	bool operator() (Ponto i, Ponto j) { return (i.X < j.X); }
} myobject;

vector<double> Calculadora::CalculaDistancias(vector <Ponto> pontos)
{
	vector<double> distancias(pontos.size() - 1);

	for (int i = 0; i < pontos.size() - 1; i++)
	{
		distancias[i] = sqrt(pow((pontos[i].X - pontos[i + 1].X), 2) + pow((pontos[i].Y - pontos[i + 1].Y), 2));
	}

	return distancias;
}

vector<Ponto> Calculadora::CalculaIndiciesDaMatriz(vector <Ponto> pontos)
{
	vector<Ponto> distancias(pontos.size() - 1);

	distancias[0] = *new Ponto(floor(pontos[0].X), floor(pontos[0].Y));

	double valX = 0.0;
	double valY = 0.0;

	for (int i = 1; i < pontos.size() - 1; i++)
	{
		if (floor(pontos[i - 1].X) == floor(pontos[i].X) && (ceil(pontos[i].X) != floor(pontos[i].X)))
			valX = floor(pontos[i].X);
		else
			valX = floor(pontos[i + 1].X);

		if (floor(pontos[i - 1].Y) == floor(pontos[i].Y) && (ceil(pontos[i].Y) != floor(pontos[i].Y)))
			valY = floor(pontos[i].Y);
		else
			valY = floor(pontos[i + 1].Y);

		distancias[i] = *new Ponto(valX, valY);
	}

	//for (int i = 1; i < distancias.size() -1; i++)
	//{
	//	/*se sim entao tem erro*/
	//	if (distancias[i].X == distancias[i + 1].X && distancias[i].Y == distancias[i + 1].Y)
	//	{
	//		/*descobrir se eh em X ou em Y*/
	//		if (distancias[i - 1].X == distancias[i].X) /*tem erro no Y*/
	//		{
	//			if (distancias[i - 1].Y > distancias[i].Y)
	//				distancias[i].Y = distancias[i].Y + 1;
	//			else
	//				distancias[i].Y = distancias[i].Y - 1;
	//		}
	//		else /*tem erro no X*/
	//		{
	//			if (distancias[i - 1].X > distancias[i].X)
	//				distancias[i].X = distancias[i].X + 1;
	//			else
	//				distancias[i].X = distancias[i].X - 1;
	//		}
	//	}
	//}

	for (int i = 1; i < distancias.size() - 1; i++)
	{
		if (abs(distancias[i - 1].X - distancias[i].X) > 1)
		{
			if (distancias[i].X > distancias[i - 1].X)
				distancias[i].X = distancias[i].X - 1;
			else
				distancias[i].X = distancias[i].X + 1;
		}
		if (abs(distancias[i - 1].Y - distancias[i].Y) > 1)
		{
			if (distancias[i].Y > distancias[i - 1].Y)
				distancias[i].Y = distancias[i].Y - 1;
			else
				distancias[i].Y = distancias[i].Y + 1;
		}
	}


	return distancias;
}

vector<Ponto> Calculadora::RetiraValoresDuplicados(vector <Ponto> pontos)
{
	vector<Ponto> distancias(pontos.size() - 1);

	for (int i = 0; i < pontos.size(); i++)
	{
		distancias[i] = *new Ponto(floor(pontos[i].X), floor(pontos[i].Y));
	}

	return distancias;
}

vector<double> Calculadora::CalculaDistancias(vector<conexao> conexoes)
{
	vector<double> distancias(conexoes.size());

	for (int i = 0; i < conexoes.size(); i++)
	{
		vector<Ponto> pontos(2);
		pontos[0] = conexoes[i].N1.Coordenada;
		pontos[1] = conexoes[i].N2.Coordenada;
		distancias[i] = CalculaDistancias(pontos)[0];
	}

	return distancias;
}

double Calculadora::CalculaSigma(Nodo n1, Nodo n2)
{
	Ponto P1 = n1.Coordenada;
	Ponto P2 = n2.Coordenada;
	/*Calcula A da equacao da reta*/
	double a = CalculaA(P1, P2);
	/*Calcula B da equacao da reta*/
	double b = CalculaB(P1, a);

	/*verificacao se P1.X > P2.X && P1.Y > P2.Y, se sim entao deve alterar de posicao P1=P2 e P2=P1, pois nao cobri o caso em que P1 � maior que P2 em ambas direcoes justamente pq poderia ser corrigido apenas invertendo-os. Demais casos o algoritmo j� trata.*/
	if (P1.X > P2.X && P1.Y > P2.Y)
	{
		Ponto *pAux = &P1;
		P1 = P2;
		P2 = *pAux;
	}

	/*lista com os pontos a serem calculados, agora basta ordenar pelos valores de X*/
	vector<Ponto> Pontos;
	Pontos = CalculaPontosEmXY(P1, P2, a, b);

	/*Ordena o vetor pelos valores de X*/
	std::sort(Pontos.begin(), Pontos.end(), myobject);

	/*calculo de para cada dois pontos da lista calcular sqrt( abs(p1.x - p2.x) + abs( p1.y - p2.y) ), e colocar em um vetor */
	vector<double> distancias;
	distancias = CalculaDistancias(Pontos);

	/*indicies da matriz que deve ser pego o rssi para cada ponto em quest�o, e colocar em um vetor*/
	vector<Ponto> indiciesDaMatriz;
	indiciesDaMatriz = CalculaIndiciesDaMatriz(Pontos);
	//vector<Ponto> indiciesDaMatrizCorrigidos;
	//indiciesDaMatrizCorrigidos = CorrigeIndiciesDaMatriz(indiciesDaMatriz);
	/*pegar na matriz os valores de rssi dos indicies definidos no vetor indiciesDaMatriz*/
	vector<double> rssis(indiciesDaMatriz.size());
	for (int i = 0; i < indiciesDaMatriz.size(); i++)
	{
		rssis[i] = m_input.MatrizMapa[(int)indiciesDaMatriz[i].X][(int)indiciesDaMatriz[i].Y];
	}

	/*com o vetor dos indicies e o vetor dos rssi's realizar o calculo final do coeficiente.*/
	double sigma = 0.0;
	for (int i = 0; i < distancias.size(); i++)
	{
		sigma += distancias[i] * rssis[i];
	}

	return sigma;
}

vector<double> Calculadora::CalculaSigmas(InputClass input)
{
	m_input = input;

	vector<double> sigmas(input.totalConexoes);
	for (int i = 0; i < input.totalConexoes; i++) {
		sigmas[i] = CalculaSigma(input.Conexoes[i].N1, input.Conexoes[i].N2);
	}
	return sigmas;
}
