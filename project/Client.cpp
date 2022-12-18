#include "Client.h"
#include "Bilet.h"
Client::Client()
{
	nume = "";
	prenume = "";
	varsta = 0;
	string ch = "N/A";
	categorie = new char[ch.length() + 1];
	strcpy_s(categorie, ch.length() + 1, ch.c_str());
}

Client::Client(string nume, string prenume, int varsta, char* categorie) 
{
	this->nume = nume;
	this->prenume = prenume;
	this->varsta = varsta;

	if (categorie != nullptr) {
		this->categorie = new char[strlen(categorie) + 1];
		for (int i = 0; i < strlen(categorie) + 1; i++) {
			this->categorie[i] = categorie[i];
		}
	}
	else {
		string ch = "N/A";
		this->categorie = new char[ch.length() + 1];
		strcpy_s(this->categorie, ch.length() + 1, ch.c_str());
	}
}

void Client::setNume(string nume) {
	if (nume.length() >= 3) {
		this->nume = nume;
	}
}

string Client::getNume() {
	return this->nume;
}

void Client::setPrenume(string prenume) {
	if (prenume.length() >= 3) {
		this->prenume = prenume;
	}
}

string Client::getPrenume() {
	return this->prenume;
}

void Client::setVarsta(int varsta) {
	if (varsta >= 16) {
		this->varsta = varsta;
	}
}

int Client::getVarsta() {
	return this->varsta;
}

void Client::setCategorie(const char* categorie) {
	if (categorie != nullptr) {
		if (this->categorie != nullptr) {
			delete[] this->categorie;
		}
		this->categorie = new char[strlen(categorie) + 1];
		for (int i = 0; i < strlen(categorie) + 1; i++) {
			this->categorie[i] = categorie[i];
		}
	}
}

char* Client::getCategorie() {
	if (this->categorie != nullptr){
		char* copy = new char[strlen(categorie) + 1];
		for (int i = 0; i < strlen(categorie) + 1; i++) {
			copy[i] = this->categorie[i];
		}
		return copy;
	}
	return nullptr;
}

Client& Client::operator=(const Client& c) {
	if (this != &c) {
		if (categorie != nullptr) {
			delete[] categorie;
			categorie = nullptr;
		}
		this->nume = c.nume;
		this->prenume = c.prenume;
		this->varsta = c.varsta;
		this->categorie = new char[strlen(c.categorie) + 1];
		for (int i = 0; i < strlen(c.categorie) + 1; i++) {
			this->categorie[i] = c.categorie[i];
		}
	}
	return *this;
}

Client::Client(const Client& c) {
	this->nume = c.nume;
	this->prenume = c.prenume;
	this->varsta = c.varsta;
	if (c.categorie != nullptr) {
		this->categorie = new char[strlen(c.categorie) + 1];
		for (int i = 0; i < strlen(c.categorie) + 1; i++) {
			this->categorie[i] = c.categorie[i];
		}
	}
	else {
		this->categorie = nullptr;
	}
}

istream& operator>>(istream& in, Client& c) {
	in >> c.nume;
	in >> c.prenume;
	in >> c.varsta;
	string buffer;
	if (_strcmpi(buffer.c_str(), "pensionar") == 0 || _strcmpi(buffer.c_str(), "adult") == 0 || _strcmpi(buffer.c_str(), "student") == 0 || _strcmpi(buffer.c_str(), "copil") == 0) {
		in >> buffer;
		c.setCategorie(buffer.c_str());
	}
	return in;
}

ostream& operator<<(ostream& out, Client c) {
	out <<"Nume: " << c.nume << endl;
	out <<"Prenume: " << c.prenume << endl;
	out <<"Varsta: " << c.varsta << endl;
	out << "Categorie: ";
	if (c.categorie != nullptr) {
		if (_strcmpi(c.categorie, "pensionar") == 0 || _strcmpi(c.categorie, "adult") == 0 || _strcmpi(c.categorie, "student") == 0 || _strcmpi(c.categorie, "copil") == 0) {
			out << c.categorie << endl;
		}
	}
	return out;
}

bool Client::operator>=(int value) {
	if (value == 16) {
		if (this->varsta >= value) {
			return true;
		}
	}
	return false;
}

void Client::operator<(int value) {
	if (value < 16) {
		if (this->varsta < 16) {
			cout << "Acces interzis !";
		}
	}
}

Client::~Client() {
	if (categorie != nullptr) {
		delete[] categorie;
		categorie = nullptr;
	}
}