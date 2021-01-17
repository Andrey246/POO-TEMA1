#include <Proba.h>

Proba::Proba(std::string nume, int durata_proba, int nr_maxim) {
	this->nume_proba = nume;
	this->durata_proba = durata_proba;
	this->nr_maxim = nr_maxim;
}

Proba::Proba(const Proba& proba) {
	this->nume_proba = proba.nume_proba;
	this->participanti = proba.participanti;
	this->durata_proba = proba.durata_proba;

}

Proba& Proba::operator=(const Proba& proba) {
	this->nume_proba = proba.nume_proba;
	this->participanti = proba.participanti;
	this->durata_proba = proba.durata_proba;

	return *this;
}


std::ostream& Proba::print(std::ostream& out) {
	
	out <<"\nNume proba: "<<nume_proba<<"\nOra de inceput "<< start/60 <<":"<<start%60 << "\nSportivi inscrisi:\n";
	for (int i = 0; i < participanti.size(); i++)
		out << '\n' << *participanti[i] << '\n';
	return out;
}


std::ostream& operator<<(std::ostream& out, Proba& proba) {

	return proba.print(out);
}

void Proba::InscrieParticipant(const std::shared_ptr<Sportiv> sportiv) {

	nr_curent++;
	try {
		if (nr_curent > nr_maxim)
			throw std::string("Nu mai exista locuri libere");
	}
	catch (std::string msg) {
		std::cout << msg;
	};

	participanti.push_back(sportiv);


}

void Proba::SetStartTime(int start) {

	this->start = start;

}

int Proba::GetTime() {

	return durata_proba;
}

void Proba::DeterminaCastigatori() { 

	std::cout << "Concurs nespecific";

}




