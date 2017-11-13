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

class Pessoa {
private:
	string nome;
	string morada;
	string genero;
public:
	Pessoa(string nome, string morada, string genero);
	string getNome() const;
	string getMorada() const;
	string getGenero() const;
	void setMorada(string morada);
};

class Jurado : Pessoa {
private:
	string telemovel;
public:
	Jurado(string nome, string morada, string genero, string telemovel);
	string getTelemovel() const;
	void setTelemovel(string telemovel);
	

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
private:
	vector <int> classificacao;//Em que a primeira classificação é dada pelo primeiro jurado, a segunda pelo segundo e a terceira pelo terceiro
	int fase; //1 ou 2
	int numMaxCandidatos; 
	string responsavel;
	string genero;
	string data; //A empresa não organiza mais que uma sessao do mesmo género por dia
	vector<Jurado> jurados_sessao; //Cada sessao é composta por 3 jurados
	vector <Candidato> concorrentes_iniciais; //vector composto por todos os candidatos à 1ªfase
	vector <Candidato> concorrentes_finais; //concorrentes que passam à 2ªfase;
public:
	int getOrdem() const;
	vector<int> getClassificacao() const;
	string getResponsavel() const;
	vector<Jurado> getJurados_sessao() const;
	vector <Candidato> getConcorrentes_iniciais() const;
};
class Candidato : Pessoa {
private:
	string data_nascimento;
	static int numInscricao; //atribuido  automaticamente quando realizam a 1ªinscricao
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
public:
	Candidato(string nome, string morada, string genero, string data_nascimento);
	string getDataNascimento() const;
	vector<Sessao> getSessoes() const;
};


class Castings {
private:
	vector<Jurado> jurados;
	vector <Candidato> candidatos;
public:
	Castings();
	vector <Jurado> getJurados() const;
	vector<Candidato> getCandidatos() const;
};