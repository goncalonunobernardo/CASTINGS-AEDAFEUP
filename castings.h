#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

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
	Jurado(string ficheiro_jurados);
	Jurado(string nome, string morada, string genero, string telemovel);
	string getTelemovel() const;
	void setTelemovel(string telemovel);
	bool operator==(Jurado &j1);
	

};
class Candidato : public Pessoa {
private:
	string data_nascimento;
	static int numInscricao; //atribuido  automaticamente quando realizam a 1�inscricao
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
public:
	Candidato();
	Candidato(string ficheiro_candidatos);
	Candidato(string nome, string morada, string genero, string data_nascimento);
	string getDataNascimento() const;
	vector<Sessao> getSessoes() const;
	bool operator==(Candidato &c1);
	void adicionarSessao(Sessao &s1);
};
class Pontuacao { //resultados de um candidato numa determinada sess�o e fase
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
	Jurado responsavel;
	string genero;
	string data; //A empresa n�o organiza mais que uma sessao do mesmo g�nero por dia
	vector<Jurado*> jurados_sessao; //Cada sessao � composta por 3 jurados
	vector <Candidato*> concorrentes_iniciais; //vector composto por todos os candidatos � 1�fase
	vector <Candidato*> concorrentes_finais; //concorrentes que passam � 2�fase;
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
	string ficheiroCandidatos;
	string ficheiroJurados;
	string ficheiroSessoes;
public:
	size_t juradoExiste(Jurado * j1); // retorna -1 se o jurado n�o existir no vetor jurados, retorna o seu indice se existir
	size_t candidatoExiste(Candidato * c1); // retorna -1 se o candidato n�o existir no vetor candidatos, retorna o seu indice se existir
	size_t sessaoExiste(Sessao &s1); // retorna -1 se a sess�o n�o existir no vetor sessoes, retorna o seu indice se existir
	size_t juradoExisteSessao(Jurado * j1, Sessao &s1); // retorna -1 se o jurado n�o existir no vetor jurados_sessao, retorna o seu indice se existir
	void setUpCandidatos();
	void setUpJurados();
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
