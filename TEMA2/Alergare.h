#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Proba.h>

class Alergare : public Proba {


private:
	int lungime_traseu;

public:

	Alergare(std::string nume, int durata_proba, int nr_maxim, int lungime_traseu);

	void DeterminaCastigatori();

	std::ostream& print(std::ostream& out);

	~Alergare();

};