#pragma once 
#include <iostream>
#include <iomanip>
#include <string>
#include "castings.h"

class ExcecaoPessoa {
	string nome;
protected:
	/**
	@brief default constructor
	*/
	ExcecaoPessoa();
	/**
	@brief Constructor of ExcecaoPessoa
	@param name of person
	*/
	ExcecaoPessoa(string nome);
	/**
	@brief Overload of operator <<
	@param Ostream os and ExcecaoPessoa p1
	*/
	friend ostream & operator<<(ostream &os, const ExcecaoPessoa & p1);
	/**
	@brief Virtual function that show information about Person exception
	@param
	*/
	virtual void handler();
};

class ExcecaoSessao {
	int id;
protected:
	/**
	@brief default constructor
	*/
	ExcecaoSessao();
	/**
	@brief Constructor
	@param Sessio id
	*/
	ExcecaoSessao(int id);
	/**
	@brief Overload of operator <<
	@param Ostream os and ExcecaoSessao s1
	*/
	friend ostream & operator<<(ostream &os, const ExcecaoSessao & s1);
	/**
	@brief Virtual function that show information about exception
	@param Ostream os and ExcecaoPessoa s1
	*/
	virtual void handler();
};

class CandidatoRepetido : public ExcecaoPessoa {
public:
	/**
	@brief Repeated Candidate Constructor
	@param Candidate 
	*/
	CandidatoRepetido(Candidato * c);
	/**
	@brief Repeated Candidate Constructor
	@param Name of candidate
	*/
	CandidatoRepetido(string nome);
	/**
	@brief Function that show information about repeated candidate
	@param
	*/
	void handler();
};

class CandidatoInexistente : public ExcecaoPessoa {
public:
	/**
	@brief Inexistent candidate exception
	@param Candidate 
	*/
	CandidatoInexistente(Candidato * c);
	/**
	@brief Inexistent Candidate Constructor
	@param Name of  inexistent candidate 
	*/
	CandidatoInexistente(string nome);
	/**
	@brief Function that show information about inexistent candidate
	@param 
	*/
	void handler();
};

class JuradoRepetido : public ExcecaoPessoa {
public:
	/**
	@brief Repeated jury Constructor
	@param Repeated jury j1
	*/
	JuradoRepetido(Jurado * j);
	/**
	@brief Repeated jury Constructor
	@param Name of repetead jury
	*/
	JuradoRepetido(string nome);
	/**
	@brief Function that show information about repeated jury
	@param 
	*/
	void handler();
};

class JuradoInexistente : public ExcecaoPessoa {
public:
	/**
	@brief Inexistent jury Constructor
	@param Inexistent jury j1
	*/
	JuradoInexistente(Jurado * j);
	/**
	@brief Inexistent jury Constructor
	@param Name of inexistent jury
	*/
	JuradoInexistente(string nome);
	/**
	@brief Function that show information about the exception
	@param 
	*/
	void handler();
};

class SessaoInexistente : public ExcecaoSessao{
public:
	/**
	@brief Inexistent session Constructor
	@param Session
	*/
	SessaoInexistente( Sessao  &s);
	/**
	@brief Function that show information about the Inexistent session exception
	@param
	*/
	void handler();
};
class SessaoRepetida : public ExcecaoSessao {
public:
	/**
	@brief Repeated session constructor
	@param
	*/
	SessaoRepetida();
	/**
	@brief Function that show information about the Repeated session exception
	@param
	*/
	void handler();
};
class JuradosCompleto : public ExcecaoPessoa{
public:
	/**
	@brief Complete juries default constructor
	@param
	*/
	JuradosCompleto();
	/**
	@brief Function that show information about the Complete juries exception
	@param
	*/
	void handler();
};
class JuradoPresente : public ExcecaoPessoa{
public:
	/**
	@brief Present jury constructor
	@param Jury
	*/
	JuradoPresente(Jurado * j);
	/**
	@brief Present jury constructor
	@param name of present jury
	*/
	JuradoPresente(string nome);
	/**
	@brief Function that show information about the present jury exception
	@param
	*/
	void handler();
};
class JuradosIncompleto :public ExcecaoSessao {
public:
	/**
	@brief Incomplete juries constructor
	@param Id session that has number os juries incomplete
	*/
	JuradosIncompleto(int id);
	/**
	@brief Function that show information about the Juries incomplete exception
	@param
	*/
	void handler();
};
