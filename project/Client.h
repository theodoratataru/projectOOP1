#pragma once
#include <string>
#include <iostream>
#include <limits.h>
using namespace std;
class Client
{
private:
	string nume;
	string prenume;
	int varsta;
	char* categorie;
public:
	//constructori
	Client();
	Client(string nume, string prenume, int varsta, char* categorie);

	//setteri si getteri
	void setNume(string nume);
	string getNume();

	void setPrenume(string prenume);
	string getPrenume();

	void setVarsta(int varsta);
	int getVarsta();

	void setCategorie(const char* categorie);
	char* getCategorie(); //sau char getCategorie() metoda cu index

	//operator= -> regula celor 3
	Client& operator=(const Client& c);

	//constructor de copiere -> regula celor 3
	Client(const Client& c);

	//operatorii << si >>
	friend istream& operator>>(istream& in, Client& c);
	friend ostream& operator<<(ostream& out, Client c);

	bool operator>=(int value);
	void operator<(int value);

	static int getMaxAgePerCategory(Client* c, int nrClienti, char* categorie) {
		int Max = INT_MIN;
		if (nrClienti > 0) {
			for (int i = 0; i < nrClienti; i++) {
				for (int j = 0; j < strlen(categorie) + 1; j++) {
					if (c[i].categorie[j] == categorie[j]) {
						if (c[i].varsta > Max) {
							Max = c[i].varsta;
						}
					}
				}
			}
		}
		return Max;
	}
	
	static int getMinAgePerCategory(Client* c, int nrClienti, char* categorie) {
		int Min = INT_MAX;
		if (nrClienti > 0) {
			for (int i = 0; i < nrClienti; i++) {
				for (int j = 0; j < strlen(categorie) + 1; j++) {
					if (c[i].categorie[j] == categorie[j]) {
						if (c[i].varsta < Min) {
							Min = c[i].varsta;
						}
					}
				}
			}
		}
		return Min;
	}


	//destructori
	~Client();
};

