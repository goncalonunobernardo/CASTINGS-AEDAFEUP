#pragma once

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
protected:
	string nome;
	string morada;
	string genero;
public:
	Pessoa();
	Pessoa(string nome, string morada, string genero);
	string getNome() const;
	string getMorada() const;
	string getGenero() const;
	void setNome(string nome);
	void setMorada(string morada);
	void setGenero(string genero);
	virtual bool operator==(Pessoa &p1);
};

class Jurado : public Pessoa {
private:
	string telemovel;
public:
	Jurado();
	Jurado(string nome, string morada, string genero, string telemovel);
	string getTelemovel() const;
	void setTelemovel(string telemovel);
	bool operator==(Jurado &j1);
	

};
class Candidato : public Pessoa {
private:
	string data_nascimento;
	static int numInscricao; //atribuido  automaticamente quando realizam a 1ªinscricao
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
public:
	Candidato();
	Candidato(string nome, string morada, string genero, string data_nascimento);
	string getDataNascimento() const;
	vector<Sessao> getSessoes() const;
	bool operator==(Candidato &c1);
	void adicionarSessao(Sessao &s1);
};
class Pontuacao { //resultados de um candidato numa determinada sessão e fase
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
	static int id;
	int fase; //1 ou 2
	int numMaxCandidatos; 
	int numVagas;
	Jurado responsavel;
	string genero;
	string data; //A empresa não organiza mais que uma sessao do mesmo género por dia
	vector<Jurado*> jurados_sessao; //Cada sessao é composta por 3 jurados
	vector <Candidato*> concorrentes_iniciais; //vector composto por todos os candidatos à 1ªfase
	vector <Candidato*> concorrentes_finais; //concorrentes que passam à 2ªfase;
public:
	Sessao();
	int getId() const;
	string getGenero() const;
	string getData() const;
	Jurado getResponsavel() const;
	vector<Jurado*> & getJurados_sessao();
	vector <Candidato*> & getConcorrentes_iniciais();
	vector <Candidato*> & getConcorrentes_finais();
	int getNumVagas() const;
	void setResponsavel(Jurado j1);
	bool operator==(Sessao &s1);
	bool juriCompleto() const;
};



class Castings {
private:
	vector<Jurado*> jurados;
	vector <Candidato*> candidatos;
	vector<Sessao> sessoes;
public:
	size_t juradoExiste(Jurado * j1); // retorna -1 se o jurado não existir no vetor jurados, retorna o seu indice se existir
	size_t candidatoExiste(Candidato * c1); // retorna -1 se o candidato não existir no vetor candidatos, retorna o seu indice se existir
	size_t sessaoExiste(Sessao &s1); // retorna -1 se a sessão não existir no vetor sessoes, retorna o seu indice se existir
	size_t juradoExisteSessao(Jurado * j1, Sessao &s1); // retorna -1 se o jurado não existir no vetor jurados_sessao, retorna o seu indice se existir
	bool adicionaCandidato(Candidato *c1);
	bool adicionaJurado(Jurado *j1);
	bool adicionaCandidatoSessao(Candidato *c1, Sessao &s1);
	bool adicionaJuradoSessao(Jurado *j1, Sessao &s1);
	bool eliminaCandidato(Candidato *c1);
	bool eliminaCandidatoSessao(Candidato *c1, Sessao &s1);
	bool eliminaJurado(Jurado * j1);
	bool tornaJuradoResponsavel(Jurado * j1, Sessao &s1);
	bool substituiJuradoResponsavel(Jurado * j1, Sessao &s1);
};
