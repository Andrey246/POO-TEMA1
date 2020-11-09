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
		out << "Premiu: "<<premiu.nume_premiu << " Data acordarii: " << premiu.data_acordarii<<'\n';
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
			out <<  palmares.lista_premii[i];

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

		out <<"\nNume: "<<sportiv.nume << " Varsta: " << sportiv.varsta << " \nLista premii participant:\n" << sportiv.palmares;
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
		out << "\nProba: "<<proba.nume_proba << " Ora incepere: "<< proba.start / 60<<":"<<proba.start%60<< '\n' ;
		out << "\nParticipanti:\n";
		for (int i = 0; i < proba.participanti.size(); i++)
			out << proba.participanti[i];

	
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
	int ora_inceput;
	std::string data;

public:

	Concurs() {}

	Concurs(std::string nume,std::string data,int ora_inceput) {
		
		this->nume = nume;
		this->ora_inceput = ora_inceput;
		this->data = data;
	}

	Concurs(const Concurs& concurs) {

		this->nume = concurs.nume;
		this->lista_probe = concurs.lista_probe;
		this->ora_inceput = concurs.ora_inceput;
		this->data = concurs.data;


	}

	Concurs& operator=(const Concurs& concurs) {

		this->nume = concurs.nume;
		this->lista_probe = concurs.lista_probe;
		this->ora_inceput = concurs.ora_inceput;
		this->data = concurs.data;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Concurs& concurs) {

		out <<"Nume concurs: "<< concurs.nume <<" data:"<<concurs.data<<'\n';
		for (int i = 0; i < concurs.lista_probe.size(); i++)
			out << concurs.lista_probe[i];
	   
		return out;
	}

	void AdaugaProba(const Proba& proba) {

		lista_probe.push_back(proba);
	}

	void ProgrameazaProbe() {

		int timp = ora_inceput;

		for (int i = 0; i < this->lista_probe.size(); i++) {
			this->lista_probe[i].SetStartTime(timp);
			timp += this->lista_probe[i].GetTime() + 15;
		}
		
	}

	~Concurs(){}
};

int main() {

	Sportiv sp4("Andrei Ionescu", 23), sp5("Ion Ionel", 41),sp6("Liviu Pana",34);
	Sportiv sp1, sp2, sp3;
	sp1 = sp4;
	sp2 = sp5;
	sp3 = sp6;
	
    sp1.AdaugaPremiu(Premiu("Locul 2 football", "12-01-2020"));
	sp1.AdaugaPremiu(Premiu("Locul 1 maraton", "01-01-2018"));

	sp2.AdaugaPremiu(Premiu("locul 2 culturism", "21-10-2019"));

	sp3.AdaugaPremiu(Premiu("locul 6 sah", "21-10-2019"));

	std::cout << sp1 << sp2 << sp3 << "\n=============\n";


	Proba prob4("alergare", 70), prob5("tenis", 90),prob6("Aruncare minge medicinala",35);
	Proba prob1, prob2, prob3;
	prob1 = prob4;
	prob2 = prob5;
	prob3 = prob6;

	prob1.InscrieParticipant(sp1);
	prob1.InscrieParticipant(sp3);

	prob3.InscrieParticipant(sp2);


	std::cout << prob1 << prob2 << prob3 << "\n=============\n";


	Concurs conctmp("Bucharest Fitness 2021","03-03-2021",8*60),concurs;
	concurs = conctmp;
	concurs.AdaugaProba(prob1);
	concurs.AdaugaProba(prob3);

	concurs.ProgrameazaProbe();

	std::cout << concurs;
}