#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Pessoa;
class Jurado;
class Candidato;
class Sessao;
class Pontuacao;
class Castings;
class Data;

class Data {
private:
	int dia;
	int mes;
	int ano;
public:
	int getDia() const;
	int getMes() const;
	int getAno() const;
	bool operator==(Data &d1);

};
class Pessoa {
protected:
	string nome;
	string morada;
	string genero;
public:
	Pessoa();
	Pessoa (string nome, string morada, string genero);
	string getNome() const;
	string getMorada() const;
	string getGenero() const;
	void setMorada(string morada);
	virtual bool operator==(Pessoa &p1);
};

class Jurado : public Pessoa {
private:
	string telemovel;
public:
	Jurado(string ficheiro);
	Jurado(string nome, string morada, string genero, string telemovel);
	string getTelemovel() const;
	void setTelemovel(string telemovel);
	bool operator==(Jurado &j1);
	

};
class Candidato : public Pessoa {
private:
	Data data_nascimento;
	static int numInscricao; //atribuido  automaticamente quando realizam a 1ªinscricao
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
public:
	Candidato(string nome, string morada, string genero, Data data_nascimento);
	Data getDataNascimento() const;
	vector<Sessao> getSessoes() const;
	bool operator==(Candidato &c1);
};
class Pontuacao {
private:
	int id_sessao;
	int fase;
	vector<int> classificacoes; // vetor c/3 posições em que índice 0 equivale à primeira classificação.

public:
	int getId() const;
	int getFase() const;
	vector<int> getClassificacoes() const;
	double getClassificacao() const;

};

class Sessao {
protected:
	 int id;
	int fase; //1 ou 2
	int numMaxCandidatos; 
	int numVagas;
	string responsavel;
	string genero;
	Data data; //A empresa não organiza mais que uma sessao do mesmo género por dia
	vector<Jurado*> &jurados_sessao; //Cada sessao é composta por 3 jurados
	vector <Candidato*> &concorrentes_iniciais; //vector composto por todos os candidatos à 1ªfase
	vector <Candidato*> &concorrentes_finais; //concorrentes que passam à 2ªfase;
public:
	int getId() const;
	string getGenero() const;
	Data getData() const;
	string getResponsavel() const;
	vector<Jurado*> & getJurados_sessao() const;
	vector <Candidato*> & getConcorrentes_iniciais() const;
	int getNumVagas() const;
	void setData(Data data);
	bool operator==(Sessao &s1);
	bool eliminaCandidatoSessao(Candidato *c1);
	bool juradoPresente(Jurado *j1);
};



class Castings {
private:
	vector<Jurado*> jurados;
	vector <Candidato*> candidatos;
	vector<Sessao> sessoes;
public:
	Castings();
	bool adicionaCandidato(Candidato *c1);
	bool adicionaJurado(Jurado *j1);
	bool adicionaCandidatoSessao(Candidato *c1, Sessao &s1);
	bool adicionaJuradoSessao(Jurado *j1, Sessao &s1);
	bool eliminaCandidato(Candidato *c1);
	bool eliminaJurado(Jurado *j1);
	
};


