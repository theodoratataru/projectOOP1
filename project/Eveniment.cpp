#include "Eveniment.h"
#include "Bilet.h"

Eveniment::Eveniment() {
	numeEveniment = nullptr;
	locatie = nullptr;
	oreDisponibile = NULL;
	nrOreDisponibile = 0;
}

Eveniment::Eveniment(char* numeEveniment, char* locatie, int* oreDisponibile, int nrOreDisponibile) {
	if (numeEveniment != nullptr) {
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		for (int i = 0; i < strlen(numeEveniment) + 1; i++) {
			this->numeEveniment[i] = numeEveniment[i];
		}
	}
	else {
		this->numeEveniment = nullptr;
	}
	if (locatie != nullptr) {
		this->locatie = new char[strlen(locatie) + 1];
		for (int i = 0; i < strlen(locatie) + 1; i++) {
			this->locatie[i] = locatie[i];
		}
	}
	else {
		this->locatie = nullptr;
	}
	if (oreDisponibile != NULL && nrOreDisponibile > 0) {
		this->nrOreDisponibile = nrOreDisponibile;
		this->oreDisponibile = new int[nrOreDisponibile];
		for (int i = 0; i < nrOreDisponibile; i++) {
			this->oreDisponibile[i] = oreDisponibile[i];
		}
	}
	else {
		this->nrOreDisponibile = 0;
		this->oreDisponibile = NULL;
	}
}

void Eveniment::setNumeEveniment(const char* numeEveniment) {
	if (numeEveniment != nullptr) {
		if (this->numeEveniment != nullptr) {
			delete[] this->numeEveniment;
		}
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		for (int i = 0; i < strlen(numeEveniment) + 1; i++) {
			this->numeEveniment[i] = numeEveniment[i];
		}
	}
}

char* Eveniment::getNumeEveniment() {
	if (this->numeEveniment != nullptr) {
		char* copy = new char[strlen(numeEveniment) + 1];
		for (int i = 0; i < strlen(numeEveniment) + 1; i++) {
			copy[i] = this->numeEveniment[i];
		}
		return copy;
	}
	return nullptr;
}

void Eveniment::setLocatie(const char* locatie) {
	if (locatie != nullptr) {
		if (this->locatie != nullptr) {
			delete[] this->locatie;
		}
		this->locatie = new char[strlen(locatie) + 1];
		for (int i = 0; i < strlen(locatie) + 1; i++) {
			this->locatie[i] = locatie[i];
		}
	}
}

char* Eveniment::getLocatie() {
	if (this->locatie != nullptr) {
		char* copy = new char[strlen(locatie) + 1];
		for (int i = 0; i < strlen(locatie) + 1; i++) {
			copy[i] = this->locatie[i];
		}
		return copy;
	}
	return nullptr;
}


void Eveniment::setNrOreDisponibile(int nrOreDisponibile) {
	if (nrOreDisponibile > 0) {
		this->nrOreDisponibile = nrOreDisponibile;
	}
}

int Eveniment::getNrOreDisponibile() {
	return this->nrOreDisponibile;
}

void Eveniment::setOreDisponibile(int* oreDisponibile, int nrOreDisponibile) {
	//validez parametrii
	if (oreDisponibile != nullptr && nrOreDisponibile > 0) {
		//dezaloc memoria din atributul clasei
		if (this->oreDisponibile != nullptr) {
			delete[] this->oreDisponibile;
			this->oreDisponibile = nullptr;
		}

		//aloc memorie
		this->nrOreDisponibile = nrOreDisponibile;
		this->oreDisponibile = new int[nrOreDisponibile];
		for (int i = 0; i < nrOreDisponibile; i++) {
			this->oreDisponibile[i] = oreDisponibile[i];
		}
	}
}

int* Eveniment::getOreDisponibile() {
	if (oreDisponibile != nullptr && nrOreDisponibile > 0) {
		int* copie = new int[nrOreDisponibile];
		for (int i = 0; i < nrOreDisponibile; i++) {
			copie[i] = oreDisponibile[i];
		}
		return copie;
	}
	return nullptr;
}

int Eveniment::operator[](int index) {
	if (index >= 0 && index < nrOreDisponibile){
			return oreDisponibile[index];
	}
	return -1;
}

bool Eveniment::operator!() {
	return nrOreDisponibile != 0;
}

int Eveniment::getMinOraPerLocatie(Eveniment* eveniment, int nrOreDisponibile, char* locatie) {
	int Min = INT_MAX;
	if (nrOreDisponibile > 0) {
		for (int i = 0; i < nrOreDisponibile; i++) {
			for (int j = 0; j < strlen(locatie) + 1; j++) {
				if (eveniment[i].locatie[j] == locatie[j]) {
					if (oreDisponibile[i] < Min) {
						Min = oreDisponibile[i];
					}
				}
			}
		}
	}
	return Min;
}

int Eveniment::getMaxOraPerLocatie(Eveniment* eveniment, int nrOreDisponibile, char* locatie) {
	int Max = INT_MIN;
	if (nrOreDisponibile > 0) {
		for (int i = 0; i < nrOreDisponibile; i++) {
			for (int j = 0; j < strlen(locatie) + 1; j++) {
				if (eveniment[i].locatie[j] == locatie[j]) {
					if (oreDisponibile[i] > Max) {
						Max = oreDisponibile[i];
					}
				}
			}
		}
	}
	return Max;
}

istream& operator>>(istream& in, Eveniment& eveniment) {
	string buf1;
	in >> buf1;
	eveniment.setNumeEveniment(buf1.c_str());

	in >> eveniment.nrOreDisponibile;

	delete[] eveniment.oreDisponibile;
	eveniment.oreDisponibile = new int[eveniment.nrOreDisponibile];

	for (int i = 0; i < eveniment.nrOreDisponibile; i++) {
		in >> eveniment.oreDisponibile[i];
	}

	string buf2;
	in >> buf2;
	eveniment.setLocatie(buf2.c_str());

	return in;
}

ostream& operator<<(ostream& out, Eveniment eveniment) {
	if (eveniment.numeEveniment != nullptr) {
		out << "Nume: " << eveniment.numeEveniment << endl;
	}
	if (eveniment.locatie != nullptr) {
		out << "Locatie: " << eveniment.locatie << endl;
	}
	out <<"Nr de ore disponibile: " << eveniment.nrOreDisponibile << endl;
	out << "Orele disponibile: " << endl;
	for (int i = 0; i < eveniment.nrOreDisponibile; i++) {
		out << eveniment.oreDisponibile[i] << endl;
	}
	return out;
}

Eveniment::~Eveniment() {
	if (numeEveniment != nullptr) {
		delete[] numeEveniment;
		numeEveniment = nullptr;
	}
	if (locatie != nullptr) {
		delete[] locatie;
		locatie = nullptr;
	}
	if (oreDisponibile != nullptr) {
		delete[] oreDisponibile;
		oreDisponibile = nullptr;
	}
}