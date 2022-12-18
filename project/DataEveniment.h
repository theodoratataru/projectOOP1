#pragma once
#include <string>
#include <iostream>
using namespace std;

class DataEveniment
{
private:
	int an;
	int luna;
	int zi;
	int durata;

public:
	//constructori
	DataEveniment();
	DataEveniment(int an, int luna, int zi,int durata);

	//setteri si getteri
	void setAn(int an);
	int getAn();

	void setLuna(int luna);
	int getLuna();

	void setZi(int zi);
	int getZi();

	void setDurata(int durata);
	int getDurata();

	// operator=
	DataEveniment& operator=(const DataEveniment& time);

	// deep copy, constructor de copiere
	DataEveniment(const DataEveniment& time);
	
	// operatori << si >>
	friend istream& operator>>(istream& in, DataEveniment& time);
	friend ostream& operator<<(ostream& out, DataEveniment time);

	DataEveniment operator+(int x);
	friend DataEveniment operator+(int x, DataEveniment t);
	DataEveniment operator-(int x);
	
	bool checkDate(DataEveniment data);
	bool isBisect(int an);
};

