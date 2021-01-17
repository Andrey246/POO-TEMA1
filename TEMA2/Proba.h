#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Sportiv.h>


class Proba {

protected:

	std::string nume_proba;
	std::vector<std::shared_ptr<Sportiv>> participanti;
	int start = 0;
	int durata_proba = 0;
	int nr_maxim, nr_curent = 0;

public:
	Proba() {}

	Proba(std::string nume, int durata_proba, int nr_maxim);

	Proba(const Proba& proba);

	Proba& operator=(const Proba& proba);

	virtual std::ostream& print(std::ostream& out);

	friend std::ostream& operator<<(std::ostream& out, Proba& proba);

	void InscrieParticipant(const std::shared_ptr<Sportiv> sportiv);

	void SetStartTime(int start);

	int GetTime();

	virtual void DeterminaCastigatori();

	virtual ~Proba() {}
};