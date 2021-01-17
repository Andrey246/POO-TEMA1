#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Premiu.h>

class Sportiv {

protected:
	std::string nume;
	int varsta;
	int greutate;
	std::vector<Premiu> palmares;

public:

	Sportiv() {}

	Sportiv(std::string nume, int varsta, int greutate);

	Sportiv(const Sportiv& sportiv);

	Sportiv& operator=(const Sportiv& sportiv);

	virtual std::ostream& print(std::ostream& out);

	friend std::ostream& operator<<(std::ostream& out, Sportiv& sportiv);

	void AdaugaPremiu(const Premiu& premiu);

	virtual float DeterminaVitezaMedie();

	virtual ~Sportiv() {}
};