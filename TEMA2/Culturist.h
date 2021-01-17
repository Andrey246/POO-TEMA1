#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Sportiv.h>

class Culturist : public Sportiv {

private:
	float body_fat;

public:

	Culturist(std::string nume, int varsta, int greutate, float body_fat);

	std::ostream& print(std::ostream& out);

	float DeterminaVitezaMedie();

	~Culturist();
};

