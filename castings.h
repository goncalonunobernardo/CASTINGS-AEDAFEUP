#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

class Pessoa;
class Jurado;
class Candidato;
class Sessao;
class Pontuacao;
class Castings;

class Data {
private:
	int dia;
	int mes;
	int ano;
public:
	int getDia();
	int getMes();
	int getAno();
	void setDia(int dia);
	void setMes(int mes);
	void setAno(int ano);
	bool operator==(Data &d1);
	bool operator<(Data &d1) const;
	void operator=(Data &d1);
	friend ostream & operator<<(ostream &os, const Data & d1);
};
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
	virtual void mostraInformacaoNome();
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
	void mostraInformacaoNome();


};
class Candidato : public Pessoa {
private:
	Data data_nascimento;
	int numInscricao;
	static int numInscricoesAtual; //atribuido  automaticamente quando realizam a 1a inscricao
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
public:
	Candidato();
	Candidato(string ficheiro_candidatos);
	Candidato(string nome, string morada, string genero, Data data_nascimento);
	Data getDataNascimento() const;
	int getNumInscricao() const;
	double getPontuacao(int sessaoId, int fase) const;
	static int getNumInscricoes();
	void setDataNascimento(Data data);
	void setNumInscricoes(int num); 
	vector<Sessao> getSessoes() const;
	bool operator==(Candidato &c1);
	void adicionarSessao(Sessao &s1);
	void mostraInformacao();
};


class Pontuacao { //resultados de um candidato numa determinada sess?o e fase
private:
	string nomeCandidato;
	int id_sessao;
	int fase;
	vector<int> classificacoes; // vetor c/3 posi??es em que ?ndice 0 equivale ? primeira classifica??o.

public:
	Pontuacao(string ficheiroPontuacao);
	Pontuacao(string nomeCandidato, int id_sessao, int  fase, vector<int> classificacoes);
	int getId() const;
	int getFase() const;
	vector<int> getClassificacoes() const;
	double getClassificacao() const;

};

class Sessao {
protected:
	static int ids;
	int id; // atribuido automaticamente
	int fase; //1 ou 2
	int numMaxCandidatos;
	int numVagas;
	string responsavel;
	string genero;
	Data data; //A empresa nao organiza mais que uma sessao do mesmo genero por dia
	vector<string> jurados_sessao; //Cada sessao e composta por 3 jurados
	vector <string> concorrentes_iniciais; //vector composto por todos os candidatos a 1fase
	vector <string> concorrentes_finais; //concorrentes que passam  2fase;
	vector <Pontuacao> pontuacoes;
public:
	Sessao();
	Sessao(string ficheiro_sessao);
	int getId() const;
	static int getIds();
	int getNumMaxCandidatos() const;
	string getGenero() const;
	Data getData();
	int getFase() const;
	string getResponsavel() const;
	vector<Pontuacao>getPontuacoes();
	vector<string> & getJurados_sessao();
	vector <string> & getConcorrentes_iniciais();
	vector <string> &getConcorrentes_finais();
	void setConcorrentes_finais(vector<string> &finais);
	int getNumVagas() const;
	bool operator==(Sessao &s1);
	bool eliminaCandidatoSessao(Candidato *c1);
	void setData(Data data);
	void setResponsavel(string j1);
	void setFase(int fase);
	void setNumVagas(int vagas);
	bool juriCompleto() const;
	bool juradoPresente(Jurado * j1);
	
};



class Castings {
private:
	vector<Jurado*> jurados;
	vector <Candidato*> candidatos;
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
	string ficheiroCandidatos;
	string ficheiroJurados;
	string ficheiroSessoes;
	string ficheiroPontuacoes;
public:
	Castings();
	Castings(string ficheiroCandidatos, string ficheiroJurados, string ficheiroSessoes);
	vector <Jurado *> getJurados();
	vector<Candidato*> getCandidatos();
	vector<Sessao> getSessao();
	int juradoExiste(Jurado * j1); // retorna -1 se o jurado nao existir no vetor jurados, retorna o seu indice se existir
	int juradoExiste(string nome);
	int candidatoExiste(Candidato * c1); // retorna -1 se o candidato nao existir no vetor candidatos, retorna o seu indice se existir
	int candidatoExiste(string nome);
	int sessaoExiste(Sessao &s1); // retorna -1 se a sessao nao existir no vetor sessoes, retorna o seu indice se existir
	int juradoExisteSessao(Jurado * j1, Sessao &s1); // retorna -1 se o jurado nao existir no vetor jurados_sessao, retorna o seu indice se existir
	void setFicheiroSessoes(string ficheiroSessoes);
	void setFicheiroJurados(string ficheiroJurados);
	void setFicheiroCandidatos(string ficheiroCandidatos);
	void setFicheiroPontuacoes(string ficheiroPontuacoes);
	void setUpCandidatos();
	void setUpJurados();
	void setUpSessoes();
	void setUpPontuacoes();
	void mostraInformacaoCandidatos();
	void mostraInformacaoJurados();
	bool adicionaCandidato(Candidato *c1);
	bool adicionaJurado(Jurado *j1);
	bool adicionaCandidatoSessao(Candidato *c1, Sessao &s1);
	bool adicionaJuradoSessao(Jurado *j1, Sessao &s1);
	bool eliminaCandidato(string nome);
	bool tornaJuradoResponsavel(Jurado * j1, Sessao &s1);
	bool eliminaJurado(Jurado * j1);
	bool eliminaCandidatoSessao(Candidato *c1, Sessao &s1);
	void ordenaCandidatosData();
	bool comecarFase2(Sessao &s1);
	void atribuirPontuacao(Sessao &s1);
};

bool  comparaDataNascimento(Candidato *c1, Candidato *c2);
ostream & operator<<(ostream & os, const vector<string> & c1);