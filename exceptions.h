#include <iostream>
#include <iomanip>
#include <string>

#include "castings.h"

class ExcecaoPessoa {
	string nome;
protected:
	ExcecaoPessoa(string nome);
	friend ostream & operator<<(ostream &os, const ExcecaoPessoa & p1);
	virtual void handler();
};

class ExcecaoSessao {
	int id;
protected:
	ExcecaoSessao(int id);
	friend ostream & operator<<(ostream &os, const ExcecaoSessao & s1);
	virtual void handler();
};

class CandidatoRepetido : public ExcecaoPessoa {
public:
	CandidatoRepetido(Candidato * c);
	void handler();
};

class CandidatoInexistente : public ExcecaoPessoa {
public:
	CandidatoInexistente(Candidato * c);
	void handler();
};

class JuradoRepetido : public ExcecaoPessoa {
public:
	JuradoRepetido(Jurado * j);
	void handler();
};

class JuradoInexistente : public ExcecaoPessoa {
public:
	JuradoInexistente(Jurado * j);
	void handler();
};

class SessaoInexistente : public ExcecaoSessao{
public:
	SessaoInexistente(Sessao  &s);
	void handler();
};

class JuradosCompleto {
public:
	JuradosCompleto();
	void handler();
};
