#include <Alergare.h>

bool comparator(std::shared_ptr<Sportiv> s1, std::shared_ptr<Sportiv> s2) {

	return (s1->DeterminaVitezaMedie() > s2->DeterminaVitezaMedie());
}

Alergare::Alergare(std::string nume, int durata_proba, int nr_maxim, int lungime_traseu) : Proba(nume, durata_proba, nr_maxim) {
	this->lungime_traseu = lungime_traseu;
}

void Alergare::DeterminaCastigatori() {
	
	std::sort(participanti.begin(), participanti.end());

	for (int i = 0; i < 3; i++) {
		std::cout << *participanti[i] << '\n';
	}

}

std::ostream& Alergare::print(std::ostream& out) {

	out << "Lungime traseu: " << lungime_traseu;
	Proba::print(out);
	return out;
}

Alergare::~Alergare(){}