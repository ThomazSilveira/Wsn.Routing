#pragma once
#include "Path.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class OutputClass
{
public:
	Path paths;
	void EscreveSaida(string v);
	vector<double> distances;
	OutputClass();
	~OutputClass();
};

