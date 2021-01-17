#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <Sportiv.h>

class Maratonist : public Sportiv {

private:
	int inaltime;

public:

	Maratonist(std::string nume, int varsta, int greutate, int inaltime);
	
	std::ostream& print(std::ostream& out);

	float DeterminaVitezaMedie();

	~Maratonist();
};
