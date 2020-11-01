#include <iostream>
#include <vector>

class Premiu {

private:
	std::string nume_premiu;

public:
	Premiu() {}

	Premiu(std::string nume) {
		this->nume_premiu = nume;
	}

	Premiu(const Premiu& premiu) {
		this->nume_premiu = premiu.nume_premiu;
	}

	Premiu& operator=(const Premiu& premiu) {
		this->nume_premiu = premiu.nume_premiu;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Premiu& premiu) {
		out << premiu.nume_premiu;
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
	}

	Sportiv& operator=(const Sportiv& sportiv) {

		this->nume = sportiv.nume;
		this->varsta = sportiv.varsta;

		return *this;

	}

	friend std::ostream& operator<<(std::ostream& out, Sportiv& sportiv) {

		out <<"Nume: "<<sportiv.nume << " Varsta: " << sportiv.varsta << " Lista premii: " << sportiv.palmares;
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

public:
	Proba(){}

	Proba(std::string nume) {
		nume_proba = nume;
	}

	Proba(const Proba& proba) {
		this->nume_proba = proba.nume_proba;
	}

	Proba& operator=(const Proba& proba) {
		this->nume_proba = proba.nume_proba;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out,Proba& proba) {
		out << proba.nume_proba;
		return out;
	}


	~Proba(){}
};

class Concurs {

private:
	std::string nume;
	std::vector<Sportiv> lista_sportivi;
	Proba proba;

public:

	Concurs(std::string nume,const Proba& proba) {
		
		this->nume = nume;
		this->proba = proba;
	}

	Concurs(const Concurs& concurs) {

		this->nume = concurs.nume;
	}

	Concurs& operator=(const Concurs& concurs) {

		this->nume = concurs.nume;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Concurs& concurs) {

		out << "Nume concurs: "<<concurs.nume << '\n';
		out << "Proba: " << concurs.proba <<'\n';
		out << "Participanti:\n";

		for (int i = 0; i < concurs.lista_sportivi.size(); i++)
			out << concurs.lista_sportivi[i] << '\n';

		return out;
	}

	void InscrieSportiv(const Sportiv& sportiv) {

		lista_sportivi.push_back(sportiv);
	}

	~Concurs(){}
};

int main() {

	Sportiv s0("Ionel Popa", 24), s1("Liviu Pana", 31),s2;
	s2 = s0;
	Premiu p1("1st tennis player"), p2("2nd football player"), p3("3rd chess player");
	s1.AdaugaPremiu(p1);
	s1.AdaugaPremiu(p2);
	s2.AdaugaPremiu(p1);

	Proba b1("Alergare");
	Concurs c1("Maraton Bucuresti 2020",b1);

	c1.InscrieSportiv(s1);
	c1.InscrieSportiv(s2);

	std::cout << c1;

}