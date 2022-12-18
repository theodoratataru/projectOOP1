#pragma once
#include <string>
#include <iostream>
using namespace std;
class Bilet{

private:
	double ID;
	double** loc;
	const int nrRanduri;
	const int nrColoane;
	float pret;
	char* zona;
	int rand;
	int coloana;
	static int nrBileteGenerateVIP;
	static int nrBileteGenerateStandard;
	static int counter;

public:
	//constructorii
	Bilet();
	Bilet(int rand,int coloana, float pret,char* zona);
	
	//constructor de copiere
	Bilet(const Bilet& bilet);
	
	//setteri si getteri
	double getID();

	double getLoc(int rand,int coloana);

	void setNrRanduri(int nrRanduri);
	int getNrRanduri();

	void setNrColoane(int nrColoane);
	int getNrColoane();

	void setRand(int rand);
	int getRand();

	void setColoana(int coloana);
	int getColoana();

	void setPret(float pret, char* zona);
	float getPret();

	void setZona(char* zona);
	char* getZona();

	//operator=
	Bilet& operator=(const Bilet& bilet);

	friend istream& operator>>(istream& in, Bilet& bilet);
	friend ostream& operator<<(ostream& out, Bilet bilet);
	
	//metoda care returneaza numarul de bilete ramase pe total
	int getNrTotalTicketsLeftPerTotal();
	//metoda care returneaza numarul de bilete ramase pe zona
	int getNrTotalTicketsLeftPerArea(char* zona);

	//supraincarcare operator ++ si -- de postincrementare cu parametru pentru a modifica pretul
	Bilet operator++(int i);
	Bilet operator--(int i);
	
	//destructor
	~Bilet();
};

