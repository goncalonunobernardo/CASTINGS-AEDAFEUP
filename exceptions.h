#include <iostream>
#include <iomanip>
#include <string>

#include "castings.h"

class CandidatoRepetido {
	string nome;
public:
	CandidatoRepetido(Candidato * c);
	friend ostream & operator<<(ostream &os, const CandidatoRepetido & c1);

};

class CandidatoInexistente {
	string nome;
public:
	CandidatoInexistente(Candidato * c);
	friend ostream & operator<<(ostream &os, const CandidatoInexistente & c1);
};

class JuradoRepetido {
	string nome;
public:
	JuradoRepetido(Jurado * j);
	friend ostream & operator<<(ostream &os, const JuradoRepetido & j1);
};

class JuradoInexistente {
	string nome;
public:
	JuradoInexistente(Jurado * j);
	friend ostream & operator<<(ostream &os, const JuradoInexistente & j1);
};

class SessaoInexistente {
	int id;
public:
	SessaoInexistente(Sessao & s);
	friend ostream & operator<<(ostream &os, const SessaoInexistente & s1);
};