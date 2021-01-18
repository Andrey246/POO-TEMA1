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

class Maraton_factory {

public:

	static std::shared_ptr<Proba> Sprint() { return std::make_shared<Alergare>("Sprint", 2, 10, 20); }
	static std::shared_ptr<Proba> Maraton_Incepatori() { return std::make_shared<Alergare>("Maraton Incepatori", 15, 100, 2000); }
	static std::shared_ptr<Proba> Maraton_Complet() { return std::make_shared<Alergare>("Maraton Complet", 600, 3000, 42000); }
	static std::shared_ptr<Proba> Alergare_Usoara() { return std::make_shared<Alergare>("Alergare Usoara", 10, 50, 1000); }

};

int main(){

	Concurs c1("Bucuresti Fitness 2021","10-01-2021",480);

	//Sportivi
	std::shared_ptr<Sportiv> sp1 = std::make_shared<Maratonist>("Alexei", 22, 67, 180);
	std::shared_ptr<Sportiv> sp2 = std::make_shared<Culturist>("Smith", 28, 90, 0.08f);
	std::shared_ptr<Sportiv> sp3 = std::make_shared<Culturist>("Oleg", 31, 78, 0.1f);

	//Probe
	std::shared_ptr<Proba> prob1 = Maraton_factory::Maraton_Incepatori();

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