#include "exceptions.h"
#include <iostream>
#include <iomanip>
#include <string>

// Defini��o da classe ExcecaoPessoa
ExcecaoPessoa::ExcecaoPessoa(string nome) : nome(nome) {}

ostream & operator<<(ostream &os, const ExcecaoPessoa & p1) {
	os << "NOME: " << p1.nome << endl;
}

// Defini��o da classe ExcecaoSessao

ExcecaoSessao::ExcecaoSessao(int id) : id(id) {}

ostream & operator<<(ostream &os, const ExcecaoSessao & s1) {
	cout << "ID: " << s1.id << endl;
}

// Defini��o da classe CandidatoRepetido

CandidatoRepetido::CandidatoRepetido(Candidato * c) : ExcecaoPessoa(c->getNome()) {}

void CandidatoRepetido::handler() {
	ExcecaoPessoa * p1 = this;
	cout << "CANDIDATO REPETIDO" << endl;
	cout << *p1;
}

// Defini��o da classe CandidatoInexistente

CandidatoInexistente::CandidatoInexistente(Candidato * c) : ExcecaoPessoa(c->getNome()) {}

void CandidatoInexistente::handler() {
	ExcecaoPessoa * p1 = this;
	cout << "CANDIDATO INEXISTENTE" << endl;
	cout << *p1;
}

// Defini��o da classe JuradoRepetido

JuradoRepetido::JuradoRepetido(Jurado * j) : ExcecaoPessoa(j->getNome()) {}

void JuradoRepetido::handler() {
	ExcecaoPessoa * p1 = this;
	cout << "JURADO REPETIDO" << endl;
	cout << *p1;
}

// Defini��o da classe JuradoInexistente

JuradoInexistente::JuradoInexistente(Jurado * j) : ExcecaoPessoa(j->getNome()) {}

void JuradoInexistente::handler() {
	ExcecaoPessoa * p1 = this;
	cout << "JURADO INEXISTENTE" << endl;
	cout << *p1;
}

// Defini��o da classe SessaoInexistente

SessaoInexistente::SessaoInexistente(Sessao  &s) : ExcecaoSessao(s.getId()) {}

void SessaoInexistente::handler() {
	ExcecaoSessao * s1 = this;
	cout << "SESS�O INEXISTENTE" << endl;
	cout << *s1;
}

// Defini��o da classe JuradosCompleto

JuradosCompleto::JuradosCompleto() {}

void JuradosCompleto::handler() {
	cout << "JURI COMPLETO" << endl;
	cout << "N�o pode adicionar mais jurados � sess�o." << endl;
}