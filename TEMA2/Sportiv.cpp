#include <Sportiv.h>


Sportiv::Sportiv(std::string nume, int varsta, int greutate) {

	this->nume = nume;
	this->varsta = varsta;
	this->greutate = greutate;
}

Sportiv::Sportiv(const Sportiv& sportiv) {
	this->nume = sportiv.nume;
	this->varsta = sportiv.varsta;
	this->palmares = sportiv.palmares;
	this->greutate = sportiv.greutate;
}


Sportiv& Sportiv::operator=(const Sportiv& sportiv) {

	this->nume = sportiv.nume;
	this->varsta = sportiv.varsta;
	this->palmares = sportiv.palmares;
	this->greutate = sportiv.greutate;

	return *this;

}

std::ostream& Sportiv::print(std::ostream& out) {

	out << "\nNume sportiv: "<<nume <<"\nVarsta: "<<varsta<<" ani"<<"\nGreutate: "<<greutate<<" kg";
	return out;

}

std::ostream& operator<<(std::ostream& out, Sportiv& sportiv) {

	return sportiv.print(out);

}


void Sportiv::AdaugaPremiu(const Premiu& premiu) {

	palmares.push_back(premiu);

}

float Sportiv::DeterminaVitezaMedie() {

	return 8.f * (varsta / greutate);
}


