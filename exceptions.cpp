#include "exceptions.h"
#include <iostream>
#include <iomanip>
#include <string>

CandidatoRepetido::CandidatoRepetido(string nome) : nome(nome) {}

ostream & operator<<(ostream &os, const CandidatoRepetido & c1) {
	os << "CANDIDATO REPETIDO" << endl;
	os << "NOME: " << c1.nome;
	return os;

}

CandidatoInexistente::CandidatoInexistente(string nome) : nome(nome) {}

ostream & operator<<(ostream &os, const CandidatoInexistente & c1) {
	os << "CANDIDATO INEXISTENTE" << endl;
	os << "NOME: " << c1.nome;
	return os;
}