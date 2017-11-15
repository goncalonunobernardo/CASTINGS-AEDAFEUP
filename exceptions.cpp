#include "exceptions.h"
#include <iostream>
#include <iomanip>
#include <string>

// Defini��o da classe CandidatoRepetido

CandidatoRepetido::CandidatoRepetido(Candidato * c) : nome(c->getNome()) {}

ostream & operator<<(ostream &os, const CandidatoRepetido & c1) {
	os << "CANDIDATO REPETIDO" << endl;
	os << "NOME: " << c1.nome;
	return os;

}

// Defini��o da classe CandidatoInexistente

CandidatoInexistente::CandidatoInexistente(Candidato * c) : nome(c->getNome()) {}

ostream & operator<<(ostream &os, const CandidatoInexistente & c1) {
	os << "CANDIDATO INEXISTENTE" << endl;
	os << "NOME: " << c1.nome;
	return os;
}

// Defini��o da classe JuradoRepetido

JuradoRepetido::JuradoRepetido(Jurado * j) : nome(j->getNome()) {}

ostream & operator<<(ostream &os, const JuradoRepetido & j1) {
	os << "JURADO REPETIDO" << endl;
	os << "NOME: " << j1.nome;
	return os;
}

// Defini��o da classe JuradoInexistente

JuradoInexistente::JuradoInexistente(Jurado * j) : nome(j->getNome()) {}

ostream & operator<<(ostream &os, const JuradoInexistente & j1) {
	os << "JURADO INEXISTENTE" << endl;
	os << "NOME: " << j1.nome;
	return os;
}

// Defini��o da classe SessaoInexistente

SessaoInexistente::SessaoInexistente(Sessao &s) : id(s.getId()) {}

ostream & operator<<(ostream &os, const SessaoInexistente & s1) {
	os << "SESS�O INEXISTENTE" << endl;
	os << "ID: " << s1.id;
	return os;
}