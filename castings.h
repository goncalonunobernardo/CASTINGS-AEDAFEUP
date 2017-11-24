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
	/**
	@brief function to get the day
	@return the day
	*/
	int getDia();
	/**
	@brief function to get the month
	@return the month of the phase
	*/
	int getMes();
	/**
	@brief function to get the year 
	@return the year of the phase
	*/
	int getAno();
	/**
	@brief function to set the day 
	@param dia - The day to set
	*/
	void setDia(int dia);
	/**
	@brief function to set the month 
	@param mes - The month to set
	*/
	void setMes(int mes);
	/**
	@brief function to set the year
	@param ano - The year to set
	*/
	void setAno(int ano);
	/**
	@brief function to overload the == operator
	@param Data &d1 - The date settled
	@return true if the whole date is equal to the second one to establish
	*/
	bool operator==(Data &d1);
	/**
	@brief function to overload the < operator
	@param Data &d1 - The date settled
	@return true if the date to establish is lower than the first date
	*/
	bool operator<(Data &d1) const;
	/**	
	@brief function to overload the = operator by declaring the Date to establish to the first one
	@param Data &d1 - The year to settled
	*/
	void operator=(Data &d1);
	/**
	@brief function to overload the << operator
	@param ostream &os -ostream to be able to print; const Data & d1 - the date settled
	@return a print of the date estabilished, all divided by "-"
	*/
	friend ostream & operator<<(ostream &os, const Data & d1);
};
class Pessoa {
protected:
	string nome;
	string morada;
	string genero;
public:
	/**
	@brief Default Constructor of a person
	*/
	Pessoa();
	/**
	@brief Constructor of a person
	@param nome - name of the person; morada - address of the person; genero - genre of the art chosen
	*/
	Pessoa(string nome, string morada, string genero);
	/**
	@brief function to get the name of a person
	@return the name of the person
	*/
	string getNome() const;
	/**
	@brief function to get the address of a person
	@return the address of the person
	*/
	string getMorada() const;
	/**
	@brief function to get the genre of the art chosen
	@return the genre of the art chosen
	*/
	string getGenero() const;
	/**
	@brief function to set the name of a person
	@param nome - The name of a person
	*/
	void setNome(string nome);
	/**
	@brief function to set the address of a person
	@param morada - The address of a person
	*/
	void setMorada(string morada);
	/**
	@brief function to set the genre of the art chosen
	@param genero - The genre of the art chosen
	*/
	void setGenero(string genero);
	/**
	@brief function to overload the == operator
	@param Pessoa &p1 - the person estabilished
	@return False if one person if equal to another
	*/
	virtual bool operator==(Pessoa &p1);
};

class Jurado : public Pessoa {
private:
	string telemovel;
public:
	/**
	@brief Default Constructor of a jury member
	*/
	Jurado();
	/**
	@brief  fuction that divides the information in regards to the juries and its corresponding file
	@param ficheiro_jurados - a line of the jury file .txt
	*/
	Jurado(string ficheiro_jurados);
	/**
	@brief  Constructor of a jury member
	@param nome - name of the person; morada - address of the person; genero - genre of the art chosen; telemovel - phone number of the person
	*/
	Jurado(string nome, string morada, string genero, string telemovel);
	/**
	@brief function to get the phone number of a jury member
	@return the address of the phone number of a jury member
	*/
	string getTelemovel() const;
	/**
	@brief function to set the phone number of a jury member
	@param telemovel - The phone number of a jury member
	*/
	void setTelemovel(string telemovel);
	/**
	@brief function to overload the == operator
	@param Jurado &j1 - the jury estabilished
	@return True if one jury is equal to another one existent
	*/
	bool operator==(Jurado &j1);

};
class Candidato : public Pessoa {
private:
	Data data_nascimento;
	int numInscricao;
	static int numInscricoesAtual; //atribuido  automaticamente quando realizam a 1a inscricao
	vector<Sessao> sessoes;
	vector<Pontuacao> pontuacoes;
public:
	/**
	@brief Default Constructor of a candidate
	*/
	Candidato();
	/**
	@brief  fuction that divides the information in regards to the candidates and their corresponding file
	@param ficheiro_candidatos - a line of the candidate file .txt
	*/
	Candidato(string ficheiro_candidatos);
	/**
	@brief  Constructor of a candidate
	@param nome - name of the candidate; morada - address of the candidate; genero - genre of the art chosen; data_nascimento - date of when candidate was born, separated by "-"
	*/
	Candidato(string nome, string morada, string genero, Data data_nascimento);
	/**
	@brief function to get the date of when candidate was born, separated by "-"
	@return the date of when candidate was born, separated by "-"
	*/
	Data getDataNascimento() const;
	/**
	@brief function to get the number of sign-ups of a candidate
	@return the number of sign-ups of a candidate
	*/
	int getNumInscricao() const;
	/**
	@brief function to get the score of a candidate according to a certain session and phase
	@param sessaoId - the specific id of the session; fase - the number of the current phase
	@return the score of a candidate according to a certain session and phase
	*/
	double getPontuacao(int sessaoId, int fase);
	/**
	@brief function to get the number of sign-ups of a candidate
	@return the number of sign-ups of a candidate
	*/
	static int getNumInscricoes();
	/**
	@brief function to set the date in which the candidates was born
	@param data - the date in which the candidates was born
	*/
	void setDataNascimento(Data data);
	/**
	@brief function to set the number of sign-ups of a candidate
	@param num - the number of sign-ups of a candidate
	*/
	void setNumInscricoes(int num); 
	/**
	@brief function to get all sessions, according to the vector estabilished
	@return the vector all sessions available
	*/
	vector<Sessao> getSessoes() const;
	/**
	@brief function to overload the == operator
	@param Candidato &c1 - the candidate estabilished
	@return True if one candidate is equal to another one existent
	*/
	bool operator==(Candidato *c1);
	/**
	@brief function in which adds a session we create
	@param Sessao &s1 - the session that's about to be added
	*/
	void adicionarSessao(Sessao &s1);
	/**
	@brief function to get the scores of the candidates, according to the vector
	@return the vector scores of the candidates, according to the vector
	*/
	vector<Pontuacao> getPontuacoes();

};


class Pontuacao { //resultados de um candidato numa determinada sessao e fase
private:
	string nomeCandidato;
	int id_sessao;
	int fase;
	vector<int> classificacoes; // vetor c/3 posi??es em que ?ndice 0 equivale ? primeira classifica??o.
	string ficheiroPontuacao;

public:
	/**
	@brief Default Constructor of a score
	*/
	Pontuacao();
	/**
	@brief  fuction that divides the information in regards to the scores and their corresponding file
	@param ficheiroPontuacao - a line of the scores file .txt
	*/
	Pontuacao(string ficheiroPontuacao);
	/**
	@brief  Constructor of a score
	@param nomeCandidato - name of the candidate; id_sessao - ID of the session; fase - current phase; classificacoes - vector of the scores of a candidate
	*/
	Pontuacao(string nomeCandidato, int id_sessao, int  fase, vector<int> classificacoes);
	/**
	@brief function to set the phase of the current session
	@param fase - The phase of the current session
	*/
	void setFase(int fase);
	/**
	@brief function to set the name of the candidate
	@param nome - The name of the candidate
	*/
	void setNome(string nome);
	/**
	@brief function to set the id of the session
	@param id - The id of the session
	*/
	void setId(int id);
	/**
	@brief function to set the score of the candidates
	@param classificacoes - The score of the candidates
	*/
	void setClassificacoes(vector<int>classificacoes);
	/**
	@brief function to get the ID of the current session
	@return The ID of the current session
	*/
	int getId() const;
	/**
	@brief function to get the phase of the current session
	@return the phase of the current session
	*/
	int getFase() const;
	/**
	@brief function to get the score of the candidates, according to the vector
	@return the vector of scores of the candidates, according to the vector
	*/
	vector<int> getClassificacoes();
	/**
	@brief function to get the score of a candidate
	@return The score of a candidate
	*/
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
	/**
	@brief Default Constructor of a Session
	*/
	Sessao();
	/**
	@brief  function that divides the information in regards to the sessions and their corresponding file
	@param ficheiro_sessao - a line of the Sessions file .txt
	*/
	Sessao(string ficheiro_sessao);
	/**
	@brief function to get the ID of the current session
	@return The ID of the current session
	*/
	int getId() const;
	/**
	@brief function to get the IDs of the current session
	@return The IDs of the current session
	*/
	static int getIds();
	/**
	@brief function to set the number of max candidates in each session
	@param numMaxCandidatos - the number of max candidates in each session
	*/
	void setNumMaxCandidatos(int numMaxCandidatos);
	/**
	@brief function to set the main responsible jury
	@param responsavel - name of the main responsible jury
	*/
	void setResponsavel(string responsavel);
	/**
	@brief function to set the initial candidates in each session
	@param concorrentes_iniciais - vector with a string of the name of inital candidates
	*/
	void setConcorrentesIniciais(vector<string> concorrentes_iniciais);
	/**
	@brief function to set the id of the session
	@param id - The id of the session
	*/
	void setId(int id);
	/**
	@brief function to set the date of the session with the specific art genre
	@param data - the date of the session with the specific art genre
	*/
	void setData(Data data);
	/**
	@brief function to set the phase of the session with the specific art genre
	@param fase - The phase of the session with the specific art genre
	*/
	void setFase(int fase);
	/**
	@brief function to set the number of available spots in each session
	@param vagas - number of available spots in each session
	*/
	void setNumVagas(int vagas);
	/**
	@brief function to get the number of max candidates in each session
	@return the number of max candidates in each session
	*/
	int getNumMaxCandidatos() const;
	/**
	@brief function to get the genre of the art chosen
	@return the genre of the art chosen
	*/
	string getGenero() const;
	/**
	@brief function to get the date of any session
	@return the date of any session
	*/
	Data getData();
	/**
	@brief function to get the phase of the current session
	@return the phase of the current session
	*/
	int getFase() const;
	/**
	@brief function to get the main responsible jury
	@return the name of the main responsible jury
	*/
	string getResponsavel() const;
	/**
	@brief function to get the score of the candidates in the current session, according to the vector
	@return the vector of scores of the candidates in the current session, according to the vector
	*/
	vector<Pontuacao>getPontuacoes();
	/**
	@brief function to get the juries in the current session, according to the vector
	@return the vector of the juries in the current session, according to the vector
	*/
	vector<string> & getJurados_sessao();
	/**
	@brief function to get the initial candidates in the current session, according to the vector
	@return the vector of the initial candidates in the current session, according to the vector
	*/
	vector <string> & getConcorrentes_iniciais();
	/**
	@brief function to get the final candidates in the current session, according to the vector
	@return the vector of the final candidates in the current session, according to the vector
	*/
	vector <string> &getConcorrentes_finais();
	/**
	@brief function to set the final candidates in the current session, according to the vector
	@param the vector of the final candidates in the current session
	*/
	void setConcorrentes_finais(vector<string> finais);
	/**
	@brief function to set the genre of the art chosen
	@param genero - the genre of the art chosen
	*/
	void setGenero(string genero);
	/**
	@brief function to get the juries in the current session, according to the vector
	@return the vector of the juries in the current session, according to the vector
	*/
	/**
	@brief function to set the juries in the current session, according to the vector
	@param jurados - the vector of the juries in the current session, according to the vector
	*/
	void setJurados(vector<string> jurados);
	/**
	@brief function to get the number of max candidates in each session
	@return the number of max candidates in each session
	*/
	int getNumVagas() const;
	/**
	@brief function to overload the == operator
	@param Jurado &j1 - the jury estabilished
	@return True if one jury is equal to another one existent
	*/
	bool operator==(Sessao &s1);
	/**
	@brief function to overload the == operator
	@param Jurado &j1 - the jury estabilished
	@return True if one jury is equal to another one existent
	*/
	bool juriCompleto() const;
	/**
	@brief function to overload the == operator
	@param Jurado &j1 - the jury estabilished
	@return True if one jury is equal to another one existent
	*/
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