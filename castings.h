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
	void setMorada();
};

class Jurado : Pessoa {
private:
	int telemovel;
public:
	int getTelemovel() const;
	Jurado(string nome, string morada, string genero, string telemovel);

};
class Sessao {
private:
	int ordem; //1,2,3,...
	int classificacao;//1-10
	string responsavel;
public:
	string getOrdem() const;
	string getClassificacao() const;
	string getResponsavel() const;
	void setOrdem();
	void setClassificacao();
	void setResponsavel();

};
class Candidato : Pessoa {
private:
	string data_nascimento;
	static int numInscricao; //atribuido  automaticamente quando realizam a 1ªinscricao
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