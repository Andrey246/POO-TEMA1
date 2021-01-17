#include "Concurs.h"


Concurs::Concurs(std::string nume, std::string data, int ora_inceput) {
	this->nume = nume;
	this->ora_inceput = ora_inceput;
	this->data = data;
}


Concurs::Concurs(const Concurs& concurs) {

	this->nume = concurs.nume;
	this->lista_probe = concurs.lista_probe;
	this->ora_inceput = concurs.ora_inceput;
	this->data = concurs.data;


}

Concurs& Concurs::operator=(const Concurs& concurs) {

	this->nume = concurs.nume;
	this->lista_probe = concurs.lista_probe;
	this->ora_inceput = concurs.ora_inceput;
	this->data = concurs.data;

	return *this;
}


std::ostream& operator<<(std::ostream& out, Concurs& concurs) {

	out << "Nume concurs: " << concurs.nume << " data:" << concurs.data << '\n';
	for (int i = 0; i < concurs.lista_probe.size(); i++)
		out << *concurs.lista_probe[i];

	return out;
}

void Concurs::ProgrameazaProbe() {

	int timp = ora_inceput;

	for (int i = 0; i < this->lista_probe.size(); i++) {
		this->lista_probe[i]->SetStartTime(timp);
		timp += this->lista_probe[i]->GetTime() + 15;
	}

}


void Concurs::AdaugaProba(std::shared_ptr<Proba> proba) {

	lista_probe.push_back(proba);

}

void Concurs::DeterminaCastigatori() {

	for (int i = 0; i < lista_probe.size(); i++) {
		lista_probe[i]->DeterminaCastigatori();
	}
}

Concurs::~Concurs() {}



