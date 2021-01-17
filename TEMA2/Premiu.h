#pragma once 
#include <iostream>
#include <string>

class Premiu {

private:
	std::string nume_premiu;
	std::string data_acordarii;

public:
	Premiu() {}

	Premiu(std::string nume, std::string data_acordarii);

	Premiu(const Premiu& premiu);

	Premiu& operator=(const Premiu& premiu);

	friend std::ostream& operator<<(std::ostream& out, Premiu& premiu);

	~Premiu() {}
};