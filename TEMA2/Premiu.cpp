#include <Premiu.h>

Premiu::Premiu(std::string nume, std::string data_acordarii) {

	this->nume_premiu = nume;
	this->data_acordarii = data_acordarii;

}


Premiu::Premiu(const Premiu& premiu) {

	this->nume_premiu = premiu.nume_premiu;
	this->data_acordarii = premiu.data_acordarii;

}

Premiu& Premiu::operator=(const Premiu& premiu) {

	this->nume_premiu = premiu.nume_premiu;
	this->data_acordarii = premiu.data_acordarii;

	return *this;
}

std::ostream& operator<<(std::ostream& out, Premiu& premiu) {
	out << "Premiu: " << premiu.nume_premiu << " Data acordarii: " << premiu.data_acordarii << '\n';
	return out;
}
