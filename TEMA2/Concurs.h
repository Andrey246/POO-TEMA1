#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Proba.h>


class Concurs {

private:
	std::string nume;
	std::vector<std::shared_ptr<Proba>> lista_probe;
	int ora_inceput = 0;
	std::string data;

public:

	Concurs() {}
	
	Concurs(std::string nume, std::string data, int ora_inceput);

	Concurs(const Concurs& concurs);

	Concurs& operator=(const Concurs& concurs);

	friend std::ostream& operator<<(std::ostream& out, Concurs& concurs);

	void AdaugaProba(std::shared_ptr<Proba> proba);

	void ProgrameazaProbe();

	void DeterminaCastigatori();

	~Concurs();
};