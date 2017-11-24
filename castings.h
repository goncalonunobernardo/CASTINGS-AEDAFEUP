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
	/**
	@brief function to get the day 
	@return the day 
	*/
	int getMes();
	/**
	@brief function to get the month 
	@return the month of the phase
	*/
	int getAno();
	/**
	@brief function to get the year 
	@return the year of the phase
	*/
	void setDia(int dia);
	/**
	@brief function to set the day 
	@param dia - The day to set
	*/
	void setMes(int mes);
	/**
	@brief function to set the month 
	@param mes - The month to set
	*/
	void setAno(int ano);
	/**
	@brief function to set the year
	@param ano - The year to set
	*/
	bool operator==(Data &d1);
	/**
	@brief function to overload the == operator
	@param Data &d1 - The date settled
	@return true if the whole date is equal to the second one to establish
	*/
	bool operator<(Data &d1) const;
	/**
	@brief function to overload the < operator
	@param Data &d1 - The date settled
	@return true if the date to establish is lower than the first date
	*/
	void operator=(Data &d1);
	/**	
	@brief function to overload the = operator by declaring the Date to establish to the first one
	@param Data &d1 - The year to settled
	*/
	friend ostream & operator<<(ostream &os, const Data & d1);
	/**
	@brief function to overload the << operator
	@param ostream &os -ostream to be able to print; const Data & d1 - the date settled
	@return a print of the date estabilished, all divided by "-"
	*/
};
class Pessoa {
protected:
	string nome;
	string morada;
	string genero;
public:
	Pessoa();
	/**
	@brief Default Constructor of a person
	*/
	Pessoa(string nome, string morada, string genero);
	/**
	@brief Constructor of a person
	@param nome - name of the person; morada - address of the person; genero - genre of the art chosen
	*/
	string getNome() const;
	/**
	@brief function to get the name of a person
	@return the name of the person
	*/
	string getMorada() const;
	/**
	@brief function to get the address of a person
	@return the address of the person
	*/
	string getGenero() const;
	/**
	@brief function to get the genre of the art chosen
	@return the genre of the art chosen
	*/
	void setNome(string nome);
	/**
	@brief function to set the name of a person
	@param nome - The name of a person
	*/
	void setMorada(string morada);
	/**
	@brief function to set the address of a person
	@param morada - The address of a person
	*/
	void setGenero(string genero);
	/**
	@brief function to set the genre of the art chosen
	@param genero - The genre of the art chosen
	*/
	virtual bool operator==(Pessoa &p1);
	/**
	@brief function to overload the == operator
	@param Pessoa &p1 - the person estabilished
	@return False if one person if equal to another
	*/
};

class Jurado : public Pessoa {
private:
	string telemovel;
public:
	Jurado();
	/**
	@brief Default Constructor of a jury member
	*/
	Jurado(string ficheiro_jurados);
	/**
	@brief  fuction that divides the information in regards to the juries and its corresponding file
	@param ficheiro_jurados - a line of the jury file .txt
	*/
	Jurado(string nome, string morada, string genero, string telemovel);
	/**
	@brief  Constructor of a jury member
	@param nome - name of the person; morada - address of the person; genero - genre of the art chosen; telemovel - phone number of the person
	*/
	string getTelemovel() const;
	/**
	@brief function to get the phone number of a jury member
	@return the address of the phone number of a jury member
	*/
	void setTelemovel(string telemovel);
	/**
	@brief function to set the phone number of a jury member
	@param telemovel - The phone number of a jury member
	*/
	bool operator==(Jurado &j1);
	/**
	@brief function to overload the == operator
	@param Jurado &j1 - the jury estabilished
	@return True if one jury is equal to another one existent
	*/
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
	/**
	@brief Default Constructor of a candidate
	*/
	Candidato(string ficheiro_candidatos);
	/**
	@brief  fuction that divides the information in regards to the candidates and their corresponding file
	@param ficheiro_candidatos - a line of the candidate file .txt
	*/
	Candidato(string nome, string morada, string genero, Data data_nascimento);
	/**
	@brief  Constructor of a candidate
	@param nome - name of the candidate; morada - address of the candidate; genero - genre of the art chosen; data_nascimento - date of when candidate was born, separated by "-"
	*/
	Data getDataNascimento() const;
	/**
	@brief function to get the date of when candidate was born, separated by "-"
	@return the date of when candidate was born, separated by "-"
	*/
	int getNumInscricao() const;
	/**
	@brief function to get the number of sign-ups of a candidate
	@return the number of sign-ups of a candidate
	*/
	double getPontuacao(int sessaoId, int fase);
	/**
	@brief function to get the score of a candidate according to a certain session and phase
	@param sessaoId - the specific id of the session; fase - the number of the current phase
	@return the score of a candidate according to a certain session and phase
	*/
	static int getNumInscricoes();
	/**
	@brief function to get the number of sign-ups of a candidate
	@return the number of sign-ups of a candidate
	*/
	void setDataNascimento(Data data);
	/**
	@brief function to set the date in which the candidates was born
	@param data - the date in which the candidates was born
	*/
	void setNumInscricoes(int num); 
	/**
	@brief function to set the number of sign-ups of a candidate
	@param num - the number of sign-ups of a candidate
	*/
	vector<Sessao> getSessoes() const;
	/**
	@brief function to get all sessions, according to the vector estabilished
	@return all sessions available
	*/
	bool operator==(Candidato *c1);
	/**
	@brief function to overload the == operator
	@param Candidato &c1 - the candidate estabilished
	@return True if one candidate is equal to another one existent
	*/
	void adicionarSessao(Sessao &s1);
	/**
	@brief function in which adds a session we create
	@param Sessao &s1 - the session that's about to be added
	*/
	vector<Pontuacao> getPontuacoes();
	/**
	@brief function to get the scores of the candidates, according to the vector
	@return the scores of the candidates, according to the vector
	*/
};


class Pontuacao { //resultados de um candidato numa determinada sessao e fase
private:
	string nomeCandidato;
	int id_sessao;
	int fase;
	vector<int> classificacoes; // vetor c/3 posi??es em que ?ndice 0 equivale ? primeira classifica??o.
	string ficheiroPontuacao;

public:
	Pontuacao();
	Pontuacao(string ficheiroPontuacao);
	Pontuacao(string nomeCandidato, int id_sessao, int  fase, vector<int> classificacoes);
	void setFase(int fase);
	void setNome(string nome);
	void setId(int id);
	void setClassificacoes(vector<int>classificacoes);
	int getId() const;
	int getFase() const;
	vector<int> getClassificacoes();
	double getClassificacao();

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
	void setNumMaxCandidatos(int numMaxCandidatos);
	void setResponsavel(string responsavel);
	void setConcorrentesIniciais(vector<string> concorrentes_iniciais);
	void setId(int id);
	void setData(Data data);
	void setFase(int fase);
	void setNumVagas(int vagas);
	int getNumMaxCandidatos() const;
	string getGenero() const;
	Data getData();
	int getFase() const;
	string getResponsavel() const;
	vector<Pontuacao>getPontuacoes();
	vector<string> & getJurados_sessao();
	vector <string> & getConcorrentes_iniciais();
	vector <string> &getConcorrentes_finais();
	void setConcorrentes_finais(vector<string> finais);
	void setGenero(string genero);
	void setJurados(vector<string> jurados);
	int getNumVagas() const;
	bool operator==(Sessao &s1);
	bool juriCompleto() const;
	bool juradoPresente(string nome);
	
};



class Castings {
private:
	vector<Jurado*> jurados;
	vector <Candidato*> candidatos;
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
	vector<string> vencedores;
	string ficheiroCandidatos;
	string ficheiroJurados;
	string ficheiroSessoes;
	string ficheiroPontuacoes;
public:
	Castings();
	Castings(string ficheiroCandidatos, string ficheiroJurados, string ficheiroSessoes,string ficheiroPontuacoes);
	vector <Jurado *> getJurados();
	vector<Candidato*> getCandidatos();
	vector<Sessao> getSessao();
	vector<string> getVencedores();
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
	bool adicionaCandidato(Candidato *c1);
	bool adicionaJurado(Jurado *j1);
	bool adicionaCandidatoSessao(Candidato *c1, Sessao &s1);
	void adicionaJuradoSessao(string nome, Sessao &s1);
	bool eliminaCandidato(string nome);
	bool tornaJuradoResponsavel(Jurado * j1, Sessao &s1);
	void eliminaJurado(string nome);
	void eliminaCandidatoSessao(string nome, Sessao &s1);
	void ordenaCandidatosData();
	void atribuirPontuacao(Sessao &s1);
	void eliminaJuradoSessao(string nome, Sessao &s1);
	void adicionaSessao(Sessao s1);
	void eliminarSessao();
};

bool  comparaDataNascimento(Candidato *c1, Candidato *c2);
ostream & operator<<(ostream & os, const vector<string> & c1);