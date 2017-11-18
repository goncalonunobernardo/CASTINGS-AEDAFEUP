#include "exceptions.h"
#include <iostream>
#include <iomanip>
#include <string>

// Definicao da classe ExcecaoPessoa
ExcecaoPessoa::ExcecaoPessoa(string nome) : nome(nome) {}

void ExcecaoPessoa::handler()
{
}

ostream & operator<<(ostream &os, const ExcecaoPessoa & p1) {
	os << "NOME: " << p1.nome << endl;

	return os;
}

// Definicao da classe ExcecaoSessao

ExcecaoSessao::ExcecaoSessao(int id) : id(id) {}

void ExcecaoSessao::handler()
{
}

ostream & operator<<(ostream &os, const ExcecaoSessao & s1) {
	cout << "ID: " << s1.id << endl;
	
	return os;
}

// Definicao da classe CandidatoRepetido

CandidatoRepetido::CandidatoRepetido(Candidato * c) : ExcecaoPessoa(c->getNome()) {}

void CandidatoRepetido::handler() {
	ExcecaoPessoa * p1 = this;
	cout << "CANDIDATO REPETIDO" << endl;
	cout << *p1;
}

// Definicao da classe CandidatoInexistente

CandidatoInexistente::CandidatoInexistente(Candidato * c) : ExcecaoPessoa(c->getNome()) {}

void CandidatoInexistente::handler() {
	ExcecaoPessoa * p1 = this;
	cout << "CANDIDATO INEXISTENTE" << endl;
	cout << *p1;
}

// Definicao da classe JuradoRepetido

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

// Definicao da classe SessaoInexistente

SessaoInexistente::SessaoInexistente(Sessao  &s) : ExcecaoSessao(s.getId()) {}

void SessaoInexistente::handler() {
	ExcecaoSessao * s1 = this;
	cout << "SESSAO INEXISTENTE" << endl;
	cout << *s1;
}

// Definicao da classe JuradosCompleto

JuradosCompleto::JuradosCompleto() {}

void JuradosCompleto::handler() {
	cout << "JURI COMPLETO" << endl;
	cout << "Nao pode adicionar mais jurados a sessao." << endl;
}