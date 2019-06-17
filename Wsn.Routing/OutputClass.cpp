#include "OutputClass.h"

void OutputClass::EscreveSaida(string v)
{
	ofstream myfile;
	myfile.open(v);

	//for (int i = 0; i < this->Paths->size(); i++)
	//{
	int i = 0;
	std::list<conPair>::iterator it;
	for (it = this->paths.Paths->begin(); it != this->paths.Paths->end(); it++)
	{
		myfile << "(" << (*it).first << ") ";
		//myfile << "Writing this to a file.\n";

		std::list<conexao>::iterator itCon;
		for (itCon = (*it).second.begin(); itCon != (*it).second.end(); itCon++)
		{
			myfile << (*itCon).N1.Id << " " << (*itCon).N2.Id << " " << (*itCon).getWeigth() << " || ";
		}

		myfile << this->distances[i] << endl;
		i++;
	}
	//cout << endl;
//}

	myfile.close();

}

OutputClass::OutputClass()
{
}


OutputClass::~OutputClass()
{
}
