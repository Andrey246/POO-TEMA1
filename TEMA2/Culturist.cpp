#include <Culturist.h>

Culturist::Culturist(std::string nume, int varsta, int greutate, float body_fat) :Sportiv(nume, varsta, greutate) {

	this->body_fat = body_fat;

}

std::ostream& Culturist::print(std::ostream& out) {

	Sportiv::print(out);
	std::cout << "\nGrasime corporala(%): "<<body_fat * 100.f;
	return out;
}

float Culturist::DeterminaVitezaMedie() {

	return 5.f * (varsta/greutate) + body_fat * 2.f;
}

Culturist::~Culturist() {}
