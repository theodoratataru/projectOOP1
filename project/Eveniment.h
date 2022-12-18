#pragma once
#include <iostream>
#include <string>
using namespace std;
class Eveniment
{
private:
	char* numeEveniment;
	char* locatie;
	int* oreDisponibile;
	int nrOreDisponibile;

public:
	Eveniment();
	Eveniment(char* numeEveniment, char* locatie, int* oreDisponibile, int nrOreDisponibile);

	void setNumeEveniment(const char* numeEveniment);
	char* getNumeEveniment();

	void setLocatie(const char* locatie);
	char* getLocatie();

	void setNrOreDisponibile(int nrOreDisponibile);
	int getNrOreDisponibile();

	void setOreDisponibile(int* oreDisponibile,int nrOreDisponibile);
	int* getOreDisponibile();

	int operator[](int index);
	bool operator!();

	//nr total de bilete in functie de locatie
	int getMinOraPerLocatie(Eveniment* event, int nrOreDisponibile, char* locatie);
	int getMaxOraPerLocatie(Eveniment* event, int nrOreDisponibile, char* locatie);

	friend ostream& operator<<(ostream& out, Eveniment eveniment);
	friend istream& operator>>(istream& in, Eveniment& eveniment);

	~Eveniment();
};

