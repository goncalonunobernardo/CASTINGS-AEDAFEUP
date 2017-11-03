#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

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
	void setTelemovel(string telemovel) const;
	

};
class Sessao {
private:
	int ordem; //1,2,3,...
	vector <int> classificacao;//Em que  a primeira classifica��o � dada pelo primeiro jurado, a segunda pelo segundo e a terceira pelo terceiro
	int fase; //1 ou 2
	int numMaxCandidatos; 
	string responsavel;
	string genero;
	string data; //A empresa n�o organiza mais que uma sessao do mesmo g�nero por dia
	vector<Jurado> jurados_sessao; //Cada sessao � composta por 3 jurados
	vector <Candidato> concorrentes_iniciais; //vector composto por todos os candidatos � 1�fase
	vector <Candidato> concorrentes_finais; //concorrentes que passam � 2�fase;
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
	static int numInscricao; //atribuido  automaticamente quando realizam a 1�inscricao
	vector<Sessao> sessoes;
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