#include <iostream>
#include "Bilet.h"
#include "Client.h"
#include "DataEveniment.h"
#include "Eveniment.h"
using namespace std;
int main() {
	cout << "Un client: " << endl;
	char* categorie = new char[100];
	cout << "categorie: ";
	cin >> categorie;
	Client c("Popescu", "Ana", 18, categorie);
	cout << c;

	cout << "Eveniment: " << endl;
	char* numeEveniment = new char[100];
	cin >> numeEveniment;
	char* locatie = new char[100];
	cin >> locatie;
	int* oreDisp = new int[5];
	for (int i = 0; i < 5; i++) {
		oreDisp[i] = i + 1;
	}
	Eveniment e(numeEveniment, locatie, oreDisp, 5);
	cout << e;
}