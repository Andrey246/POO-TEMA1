#include <Maratonist.h>

Maratonist::Maratonist(std::string nume, int varsta, int greutate, int inaltime) :Sportiv(nume, varsta, greutate) {

	this->inaltime = inaltime;

}

std::ostream& Maratonist::print(std::ostream& out) {

	Sportiv::print(out);
	std::cout << "\nInaltime: "<<inaltime;
	return out;

}

float Maratonist::DeterminaVitezaMedie() {

	return 11.f * (varsta/greutate) + (inaltime / 10);
}

Maratonist::~Maratonist(){}
