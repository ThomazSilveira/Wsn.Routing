#include "Path.h"



void Path::caminhoCompleto(int index)
{
	/*cria o caminho completo de cada rota*/


	for (int i = 0; i < Paths->size(); i++)
	{
		std::list<conPair>::iterator it;
		for (it = Paths->begin(); it != Paths->end(); it++)
		{
			std::list<conexao>::iterator itCon;
			for (itCon = (*it).second.begin(); itCon != (*it).second.end(); itCon++)
			{
				if (itCon->N1.Id != index) /*entao quer dizer que a rota nao esta completa*/
				{
					std::list<conPair>::iterator it2;
					for (it2 = Paths->begin(); it2 != it; it2++)
					{
						if ((*it).second.begin()->N1.Id == index)
							break;

						std::list<conexao>::iterator itCon2;
						for (itCon2 = (*it2).second.begin(); itCon2 != (*it2).second.end(); itCon2++)
						{
							if (itCon2->N2.Id == itCon->N1.Id) /*se sim insere no inicio, pois achou a ligacao que faltava*/
							{
								//if ((*it).second.end()->N1.Id == index)
									//break;
								//(*it).second.push_back(*itCon2);
								(*it).second.push_front(*itCon2);
							}
						}
					}
				}
			}
		}
	}
}

void Path::insereConexaoEm(int index, conexao conexao)
{
	std::list<conPair>::iterator it;

	it = Paths->begin();
	for (int i = 0; i < index; i++)
	{
		it++;
	}

	if ((*it).second.size() > 0)
	{
		if (conexao.N2.Id == (*it).first) /*achou um caminho melhor para o destino*/
		{
			(*it).second.clear();
		}
	}

	(*it).second.push_back(conexao);

}

void Path::insertPath(int pos, conPair pair)
{
	std::list<conPair>::iterator it;

	it = Paths->begin();
	for (int i = 0; i < pos; i++)
		it++;

	Paths->insert(it, pair);

}

Path::Path(int V)
{
	Paths = new list<conPair>(V);

	for (std::list<conPair>::iterator it = Paths->begin(); it != Paths->end(); it++)
	{
		(*it).first = std::distance(Paths->begin(), it);
		(*it).second = *new list<conexao>();
	}
}

Path::Path()
{
}




Path::~Path()
{
}
