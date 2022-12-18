#include "DataEveniment.h"
DataEveniment::DataEveniment() {
	an = NULL;
	luna = NULL;
	zi = NULL;
	durata = NULL;
}

DataEveniment::DataEveniment(int an, int luna, int zi,int durata) {
	if (an >= 2022) {
		this->an = an;
	}
	else {
		this->an = 0;
	}

	if (luna >= 1 && luna <= 12) {
		this->luna = luna;
	}
	else {
		this->luna = 0;
	}

	if (luna == 2) {

		if (zi >= 1 && zi <= 28) {
			this->zi = zi;
		}
		else {
			this->zi = 0;
		}
	}
	else if (luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12) {

		if (zi >= 1 && zi <= 31) {
			this->zi = zi;
		}
		else {
			this->zi = 0;
		}
	}
	else if (luna == 4 || luna == 6 || luna == 9 || luna == 11) {

		if (zi >= 1 && zi <= 30) {
			this->zi = zi;
		}
		else {
			this->zi = 0;
		}
	}
	else {
		this->zi = 0;
	}
	
	if (durata >= 1 && durata <= 3) {
		this->durata = durata;
	}
	else {
		this->durata = NULL;
	}
}

void DataEveniment::setAn(int an) {
	if (an >= 2022) {
		this->an = an;
	}
}

int DataEveniment::getAn() {
	return this->an;
}

void DataEveniment::setLuna(int luna) {
	if (luna >= 1 && luna <= 12) {
		this->luna = luna;
	}
}

int DataEveniment::getLuna() {
	return this->luna;
}

void DataEveniment::setZi(int zi) {
	if (zi >= 1 && zi <= 31) {
		this->zi = zi;
	}
}

int DataEveniment::getZi() {
	return this->zi;
}

void DataEveniment::setDurata(int durata) {
	if (durata >= 1 && durata <= 3) {
		this->durata = durata;
	}
}

int DataEveniment::getDurata() {
	return this->durata;
}

DataEveniment& DataEveniment::operator=(const DataEveniment& time) {
	if (this != &time) {
		this->an = time.an;
		this->luna = time.luna;
		this->zi = time.zi;
		this->durata = durata;
	}
	return *this;
}

DataEveniment::DataEveniment(const DataEveniment& time) {
	this->an = time.an;
	this->luna = time.luna;
	this->zi = time.zi;
	this->durata = time.durata;
}

istream& operator>>(istream& in, DataEveniment& time) {
	in >> time.an;
	in >> time.luna;
	in >> time.zi;
	in >> time.durata;
	return in;
}

ostream& operator<<(ostream& out, DataEveniment time) {
	if (time.an != NULL) {
		out <<"Anul: " << time.an << endl;
	}
	if (time.luna != NULL) {
		out <<"Luna: " << time.luna << endl;
	}
	if (time.zi != NULL) {
		out <<"Zi: "<< time.zi << endl;
	}
	if (time.durata != NULL) {
		out <<"Durata evenimentului: " << time.durata << endl;
	}
	return out;
}

DataEveniment DataEveniment::operator+(int x) {
	DataEveniment copie = *this;
	if (copie.zi + x >= 1 && copie.zi + x <= 31) {
		copie.zi = copie.zi + x;
	}
	return copie;
}

//pentru comutativitate
DataEveniment operator+(int x, DataEveniment data) {
	if (data.zi + x >= 1 && data.zi + x <= 31) {
		data.zi = data.zi + x;
	}
	return data;
}

DataEveniment DataEveniment::operator-(int x) {
	DataEveniment copie = *this;
	if (copie.zi - x >= 1 && copie.zi - x <= 31) {
		copie.zi = copie.zi - x;
	}
	return copie;
}

bool DataEveniment::checkDate(DataEveniment data) {
	if (data.an == NULL || data.luna == NULL || data.zi == NULL) {
		return false;
	}
	return true;
}

bool DataEveniment::isBisect(int an) {
	if ((an % 4 == 0 && an % 100 != 0) || an % 400 == 0) {
		return true;
	}
	return false;
}

