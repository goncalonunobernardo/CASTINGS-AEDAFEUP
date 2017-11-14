#include <iostream>
#include <iomanip>
#include <string>
#include "castings.h"

class CandidatoRepetido {
	string nome;
public:
	CandidatoRepetido(string nome);
	friend ostream & operator<<(ostream &os, const CandidatoRepetido & c1);

};

class CandidatoInexistente {
	string nome;
public:
	CandidatoInexistente(string nome);
	friend ostream & operator<<(ostream &os, const CandidatoInexistente & c1);
};
