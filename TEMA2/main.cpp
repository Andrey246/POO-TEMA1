#include <iostream>
#include <vector>
#include <string>
#include "Premiu.h"
#include "Sportiv.h"
#include "Proba.h"
#include "Concurs.h"
#include "Maratonist.h"
#include "Culturist.h"
#include "Alergare.h"

int main(){

	Concurs c1("Bucuresti Fitness 2021","10-01-2021",480);

	//Sportivi
	std::shared_ptr<Sportiv> sp1 = std::make_shared<Maratonist>("Alexei", 22, 67, 180);
	std::shared_ptr<Sportiv> sp2 = std::make_shared<Culturist>("Smith", 28, 90, 0.08f);
	std::shared_ptr<Sportiv> sp3 = std::make_shared<Culturist>("Oleg", 31, 78, 0.1f);

	//Probe
	std::shared_ptr<Proba> prob1 = std::make_shared<Alergare>("Maraton", 45, 20, 8000);

	//Inscrie participanti intr-o proba
	prob1->InscrieParticipant(sp1);
	prob1->InscrieParticipant(sp2);
	prob1->InscrieParticipant(sp3);

	//Desfasoara concursul
	c1.AdaugaProba(prob1);
	c1.ProgrameazaProbe();

	std::cout << c1;

	std::cout << "\nCastigatori concurs:\n";
	c1.DeterminaCastigatori();

	

}