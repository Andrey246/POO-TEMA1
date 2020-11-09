#include <iostream>
#include <vector>

class Premiu {

private:
	std::string nume_premiu;
	std::string data_acordarii;

public:
	Premiu() {}

	Premiu(std::string nume,std::string data_acordarii) {

		this->nume_premiu = nume;
		this->data_acordarii = data_acordarii;

	}

	Premiu(const Premiu& premiu) {

		this->nume_premiu = premiu.nume_premiu;
		this->data_acordarii = premiu.data_acordarii;

	}

	Premiu& operator=(const Premiu& premiu) {

		this->nume_premiu = premiu.nume_premiu;
		this->data_acordarii = premiu.data_acordarii;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Premiu& premiu) {
		out << "Premiu: "<<premiu.nume_premiu << " Data acordarii: " << premiu.data_acordarii;
		return out;
	}


	~Premiu() {}
};


class Palmares {

private:
	std::vector<Premiu> lista_premii;

public:
	Palmares() {}

	Palmares(const Palmares& palmares) {
		this->lista_premii = palmares.lista_premii;
	}

	Palmares& operator=(const Palmares& palmares) {
		this->lista_premii = palmares.lista_premii;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Palmares& palmares) {

		for (int i = 0; i < palmares.lista_premii.size(); i++)
			out <<  palmares.lista_premii[i] << '\n';

		return out;
	}

	void AdaugaPremiu(const Premiu& premiu) {
		lista_premii.push_back(premiu);
	}

	~Palmares() {}
};


class Sportiv {

private:
	std::string nume;
	int varsta;
	Palmares palmares;

public:

	Sportiv() {}

	Sportiv(std::string nume, int varsta) {

		this->nume = nume;
		this->varsta = varsta;
	}

	Sportiv(const Sportiv& sportiv) {
		this->nume = sportiv.nume;
		this->varsta = sportiv.varsta;
		this->palmares = sportiv.palmares;
	}

	Sportiv& operator=(const Sportiv& sportiv) {

		this->nume = sportiv.nume;
		this->varsta = sportiv.varsta;
		this->palmares = sportiv.palmares;

		return *this;

	}

	friend std::ostream& operator<<(std::ostream& out, Sportiv& sportiv) {

		out <<"Nume: "<<sportiv.nume << " Varsta: " << sportiv.varsta << " \nLista premii:\n" << sportiv.palmares;
		return out;
	}

	void AdaugaPremiu(const Premiu& premiu){
		palmares.AdaugaPremiu(premiu);
	}

	~Sportiv(){}
};

class Proba {

private:
	std::string nume_proba;
	std::vector<Sportiv> participanti;
	int start = 0;
	int durata_proba = 0;

public:
	Proba(){}

	Proba(std::string nume,int durata_proba) {
		nume_proba = nume;
		this->durata_proba = durata_proba;
	}

	Proba(const Proba& proba) {
		this->nume_proba = proba.nume_proba;
		this->participanti = proba.participanti;
		this->durata_proba = proba.durata_proba;

	}

	Proba& operator=(const Proba& proba) {
		this->nume_proba = proba.nume_proba;
		this->participanti = proba.participanti;
		this->durata_proba = proba.durata_proba;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out,Proba& proba) {
		out << "Nume: "<<proba.nume_proba << " Ora incepere: "<< proba.start << '\n' ;
		out << "Participanti:\n";
		for (int i = 0; i < proba.participanti.size(); i++)
			out << proba.participanti[i] << '\n';

	
		return out;
	}

	void InscrieParticipant(const Sportiv& sportiv) {

		participanti.push_back(sportiv);

	}

	void SetStartTime(int start) {

		this->start = start;

	}

	int GetTime() {

		return durata_proba;
	}

	~Proba(){}
};

class Concurs {

private:
	std::string nume;
	std::vector<Proba> lista_probe;
	int ora_inceput = 3;

public:

	Concurs(std::string nume) {
		
		this->nume = nume;
	}

	Concurs(const Concurs& concurs) {

		this->nume = concurs.nume;
		this->lista_probe = concurs.lista_probe;
		this->ora_inceput = concurs.ora_inceput;

	}

	Concurs& operator=(const Concurs& concurs) {

		this->nume = concurs.nume;
		this->lista_probe = concurs.lista_probe;
		this->ora_inceput = concurs.ora_inceput;


		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Concurs& concurs) {

		out << concurs.nume <<'\n';
		for (int i = 0; i < concurs.lista_probe.size(); i++)
			out << concurs.lista_probe[i] << '\n';
	   
		return out;
	}

	void AdaugaProba(const Proba& proba) {

		lista_probe.push_back(proba);
	}

	void ProgrameazaProbe() {

		int timp = ora_inceput;

		for (int i = 0; i < this->lista_probe.size(); i++) {
			this->lista_probe[i].SetStartTime(timp);
			timp += this->lista_probe[i].GetTime();
		}
		
	}

	~Concurs(){}
};

int main() {

	Sportiv sp1("Ionescu", 23), sp2("Ionel", 21);
    sp1.AdaugaPremiu(Premiu("Locul 2 football", "12-01-2020"));
	sp1.AdaugaPremiu(Premiu("Locul 1 maraton", "01-01-2001"));

	sp2.AdaugaPremiu(Premiu("locul 2 culturism", "21-10-2019"));

	Proba prob1("alergare", 80), prob2("tenis", 90);
	prob1.InscrieParticipant(sp1);
	prob2.InscrieParticipant(sp2);


	Concurs conc("Bucharest Fitness 2021");
	conc.AdaugaProba(prob1);
	conc.AdaugaProba(prob2);

	conc.ProgrameazaProbe();

	std::cout << conc;
}
