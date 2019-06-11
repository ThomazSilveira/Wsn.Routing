#pragma once
#include "conexao.h"
#include <queue>
#include <list>

using namespace std;

typedef pair<char, list<conexao>> conPair;

class Path
{
private:
	
public:

	list<conPair> *Paths;

	void caminhoCompleto(char index);
	void insereConexaoEm(int index, conexao conexao);
	void insertPath(int pos,conPair pair);
	Path(int v);
	~Path();
};

