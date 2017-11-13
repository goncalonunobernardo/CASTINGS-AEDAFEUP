#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Pessoa;
class Jurado;
class Candidato;
class Sessao;
class Pontuacao;
class Castings;
class CandidatoRepetido;
class Pessoa {
protected:
	string nome;
	string morada;
	string genero;
public:
	Pessoa(string nome, string morada, string genero);
	string getNome() const;
	string getMorada() const;
	string getGenero() const;
	void setMorada(string morada);
	virtual bool operator==(Pessoa &p1);
};

class Jurado : Pessoa {
private:
	string telemovel;
public:
	Jurado(string nome, string morada, string genero, string telemovel);
	string getTelemovel() const;
	void setTelemovel(string telemovel);
	bool operator==(Jurado &j1);
	

};
class Candidato : Pessoa {
private:
	string data_nascimento;
	static int numInscricao; //atribuido  automaticamente quando realizam a 1�inscricao
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
public:
	Candidato(string nome, string morada, string genero, string data_nascimento);
	string getDataNascimento() const;
	vector<Sessao> getSessoes() const;
	bool operator==(Candidato &c1);
};
class Pontuacao {
private:
	int id_sessao;
	int fase;
	vector<int> classificacoes; // vetor c/3 posi��es em que �ndice 0 equivale � primeira classifica��o.

public:
	int getId() const;
	int getFase() const;
	vector<int> getClassificacoes() const;
	double getClassificacao() const;

};
class Sessao {
private:
	static int id;
	int fase; //1 ou 2
	int numMaxCandidatos; 
	int numVagas;
	string responsavel;
	string genero;
	string data; //A empresa n�o organiza mais que uma sessao do mesmo g�nero por dia
	vector<Jurado> &jurados_sessao; //Cada sessao � composta por 3 jurados
	vector <Candidato> &concorrentes_iniciais; //vector composto por todos os candidatos � 1�fase
	vector <Candidato> &concorrentes_finais; //concorrentes que passam � 2�fase;
public:
	string getGenero() const;
	string getData() const;
	string getResponsavel() const;
	vector<Jurado> & getJurados_sessao() const;
	vector <Candidato> & getConcorrentes_iniciais() const;
	int getNumVagas() const;
	bool operator==(Sessao &s1);
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
	bool adicionaCandidatoSessao(Candidato &c1, Sessao &s1);
};
class CandidatoRepetido {
	Candidato &c1;
public:
	CandidatoRepetido(Candidato &c2) : c1(c2) {};
	Candidato & getCandidato() const {
		return c1;
	}

};
ostream & operator<<(ostream &os, const CandidatoRepetido &c1) {
	os << "CANDIDATO REPETIDO" << endl;
	//os << "NOME: " << c1.getCandidato().getNome();
	return os;

}