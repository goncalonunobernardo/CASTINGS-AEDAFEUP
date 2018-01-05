#pragma once
#pragma warning(disable:4996)


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>
#include <utility>

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
	int getDia() const;
	/**
	@brief function to get the month
	@return the month of the phase
	*/
	int getMes() const;
	/**
	@brief function to get the year
	@return the year of the phase
	*/
	int getAno() const;
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
	bool operator==(Data &d1) const;
	/**
	@brief function to overload the < operator
	@param Data &d1 - The date settled
	@return true if the date to establish is lower than the first date
	*/
	bool operator<(Data &d1) const;
	/**
	@brief function to overload the > operator
	@param d1 Date settled
	@return Returns true if the date is higher that the second date
	*/
	bool operator>(Data &d1) const;

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
	pair<pair<Data, Data>, string> indisponibilidade; 
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
	@brief function to get sign-up number of a candidate
	@return sign-up number
	*/
	int getNumInscricao() const;
	/**
	@brief function to get the score of a candidate according to a certain session and phase
	@param sessaoId - the specific id of the session; fase - the number of the current phase
	@return the score of a candidate according to a certain session and phase
	*/
	double getPontuacao(int sessaoId, int fase);
	/**
	@brief function to get the number of candidate sign-ups up until now
	@return the number of sign-ups
	*/
	static int getNumInscricoes();
	/**
	@brief function to set the date in which the candidates was born
	@param data - the date in which the candidates was born
	*/
	void setDataNascimento(Data data);
	/**
	@brief function to set the number of candidate sign-ups up until now
	@param num - the number of sign-ups
	*/
	void setNumInscricoes(int num); 

	/**
	@brief function to set sign-up number of a candidate
	*/
	void setNumInscricao();

	/**
	@brief function to set the unavailability of sessions
	@param indisp - string
	*/
	void setIndisponibilidade(pair<pair<Data, Data>, string> indisp);
	/**
	@brief function to set the unavailability of sessions
	@param Data: dataI, dataF, razao
	*/
	void setIndisponibilidade(Data dataI, Data dataF, string razao);

	/**
	@brief Function to set the reason of unavailability
	*/
	void setRazao(string razao);

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
	/**
	@brief function to overload the < operator
	@param Candidato *c1 - the candidate estabilished
	@return True if the session of one candidate is more recent than one another
	*/
	bool operator<(Candidato *c1);
	/**
	@brief function to overload the << operator
	@param ostream &os, const Candidato *c1
	@return an ostream with the information of a candidate
	*/
	friend ostream & operator<<(ostream &os, const Candidato *c1);

	/**
	@brief Returns the pair with the unavailability of the candidate. The pair consists of another pair with two dates (period of unavailability) and a string with the reason
	*/
	pair<pair<Data, Data>, string> getIndisponibilidade() const;
	
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
	priority_queue<Candidato*> entrevistas;

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
	@brief function to set the juries in the current session, according to the vector
	@param jurados - the vector of the juries in the current session, according to the vector
	*/
	void setJurados(vector<string> jurados);
	/**
	@brief function to get the number of available spots in a session
	@return the number of available spots in a session
	*/
	int getNumVagas() const;
	/**
	@brief function to overload the == operator
	@param Sessao &s1 - the session estabilished
	@return True if one session is equal to another one existent
	*/
	bool operator==(Sessao &s1);
	/**
	@brief function to test if the jury board is complete
	@return True if the jury board is complete
	*/
	bool juriCompleto() const;
	/**
	@brief function to test if a certain jury is present
	@param nome - name of a certain jury
	@return True if the specific jury is present
	*/
	bool juradoPresente(string nome);
	/**
	@brief function to overload the < operator
	@param Sessao &s1 - the session estabilished
	@return True if one session is more recent to another existent
	*/
	bool operator<(Sessao &s1);
	/**
	@brief function to add an interview to the priority queue
	@param Candidato *c1 - candidate in which has the interview
	*/
	void adicionarEntrevista(Candidato * c1);
	/**
	@brief function to set the interviews of a certain genre
	@param priority_queue<Candidato*> entrevista - a priority queue of candidates in which it represents the interviews available of each genre
	*/
	void setEntrevistas(priority_queue<Candidato*> entrevista);
	/**
	@brief function to get the interviews according to a genre and according to the vector
	@return the vector of the interviews according to a genre and according to the vector
	*/
	priority_queue<Candidato*> &getEntrevistas();
	/**
	@brief function to remove interviews that are NOW complete
	@param string genero - genre of the session in regards to the interviews, unsigned int n_entrevistas - number of interviews in which the user wants to do
	*/
	void realizar_entrevista(string genero, unsigned int n_entrevistas);
};


struct eqstr {
	bool operator() (const Candidato * c1, const Candidato * c2) const {
		return (c1 == c2);
	}
};

struct hstr {
	size_t operator() (const Candidato * c1) const {
		size_t ind;
		ind = c1->getMorada().length() % 47 + c1->getNumInscricao();
		return ind;
	}
};

class Castings {
private:
	vector<Jurado*> jurados;
	vector <Candidato*> candidatos;
	vector<Sessao> sessoes;
	vector<string>generos;
	vector<Pontuacao> pontuacoes;
	vector<string> vencedores;
	unordered_set<Candidato*, hstr, eqstr> indisponiveis;
	string ficheiroCandidatos;
	string ficheiroJurados;
	string ficheiroSessoes;
	string ficheiroPontuacoes;
	multimap<string, Candidato*> candidatos_genero;
public:
	/**
	@brief Default Constructor of an Audition
	*/
	Castings();
	/**
	@brief  function that divides the information in regards all files (candidates, juries, sessions and scores)
	@param ficheiroCandidatos - candidates' txt file; ficheiroJurados - juries' txt file; ficheiroSessoes - sessions' txt file; ficheiroPontuacoes - scores' txt file
	*/
	Castings(string ficheiroCandidatos, string ficheiroJurados, string ficheiroSessoes,string ficheiroPontuacoes);
	/**
	@brief function to get juries in the audition
	@return the vector of the juries in the audition
	*/
	vector <Jurado *> getJurados();
	/**
	@brief function to get candidates in the audition
	@return the vector of the candidates in the audition
	*/
	vector<Candidato*> getCandidatos();
	/**
	@brief function to get the vector of sessions in the audition
	@return the vector of the sessions in the audition
	*/
	vector<Sessao> getSessao();
	/**
	@brief function to get winners in the present session and audition
	@return the vector of the winners in the present session and audition
	*/
	;
	vector<string> getVencedores();
	/**
	@brief
	@return
	*/
	multimap<string, Candidato*> getCandidatos_genero();

	/**
	@brief function to test if a specific jury exists
	@param Jurado * j1 - jury
	@return -1 if the jury doesn't exist in the vector of juries; returns index if exists
	*/
	int juradoExiste(Jurado * j1);
	/**
	@brief function to test if a specific jury exists
	@param nome - name of jury
	@return -1 if the jury doesn't exist in the vector of juries; returns index if exists
	*/
	int juradoExiste(string nome);
	/**
	@brief function to test if a specific candidate exists
	@param Candidato * c1 - candidate
	@return -1 if the candidate doesn't exist in the vector; returns 0 if exists
	*/
	int candidatoExiste(Candidato * c1);
	/**
	@brief function to test if a specific candidate exists
	@param Candidato * c1 - candidate
	@return -1 if the candidate doesn't exist in the vector; returns 0 if exists
	*/
	int candidatoExiste(string nome);
	/**
	@brief function to test if a specific session exists
	@param Sessao &s1 - session
	@return -1 if the session doesn't exist in the vector; returns index if exists
	*/
	int sessaoExiste(Sessao &s1); 
	/**
	@brief function to test if a specific jury exists in a session
	@param Jurado * j1 - jury; Sessao &s1 - session
	@return -1 if the jury doesn't exist in the vector jurados_sessao; returns index if exists
	*/
	int juradoExisteSessao(Jurado * j1, Sessao &s1); 
	/**
	@brief function to get the name of the give Sessions' file
	@param ficheiroSessoes
	*/
	void setFicheiroSessoes(string ficheiroSessoes);
	/**
	@brief function to get the name of the give Juries' file
	@param ficheiroJurados
	*/
	void setFicheiroJurados(string ficheiroJurados);
	/**
	@brief function to get the name of the give Candidates' file
	@param ficheiroCandidatos
	*/
	void setFicheiroCandidatos(string ficheiroCandidatos);
	/**
	@brief function to get the name of the give Scores' file
	@param ficheiroPontuacoes
	*/
	void setFicheiroPontuacoes(string ficheiroPontuacoes);
	/**
	@brief function to open the Candidates' file and push the information to the corresponding vector
	*/
	void setUpCandidatos();
	/**
	@brief function to open the Juries' file and push the information to the corresponding vector
	*/
	void setUpJurados();
	/**
	@brief function to open the Sessions' file and push the information to the corresponding vector
	*/
	void setUpSessoes();
	/**
	@brief function to open the Scores' file and push the information to the corresponding vector
	*/
	void setUpPontuacoes();
	/**
	@brief function to add a Candidate to the program
	@param Candidato *c1 - candidate
	@return True if success
	*/
	bool adicionaCandidato(Candidato *c1);
	/**
	@brief function to add a Jury to the program
	@param Jurado *j1 - Jury
	@return True if success
	*/
	bool adicionaJurado(Jurado *j1);
	/**
	@brief function to add a Candidate to a session
	@param Candidato *c1 - candidate; Sessao &s1 - session
	@return True if success
	*/
	bool adicionaCandidatoSessao(Candidato *c1, Sessao &s1);
	/**
	@brief function to add a Jury to a session
	@param Jurado *j1 - Jury; Sessao &s1 - session
	*/
	void adicionaJuradoSessao(string nome, Sessao &s1);
	/**
	@brief function to eliminate a Candidate from program
	@param nome - name of candidate
	@return True if success
	*/
	bool eliminaCandidato(string nome);
	/**
	@brief function to make a certain jury responsible for the session
	@param Jurado * j1 - Jury; Sessao &s1 - Session
	@return True if success
	*/
	bool tornaJuradoResponsavel(Jurado * j1, Sessao &s1);
	/**
	@brief function to eliminate a Jury from program
	@param nome - name of jury
	*/
	void eliminaJurado(string nome);
	/**
	@brief function to eliminate a candidate from a session
	@param Candidato *c1 - candidate; Sessao &s1 - session
	*/
	void eliminaCandidatoSessao(string nome, Sessao &s1);
	/**
	@brief function to get all candidates sorted by their birth-date
	*/
	void ordenaCandidatosData();
	/**
	@brief function to set a full Score
	@param Sessao &s1 - Session
	*/
	void atribuirPontuacao(Sessao &s1);
	/**
	@brief function to eliminate a Jury from a session
	@param nome - name of the Jury; Sessao &s1 - session
	*/
	void eliminaJuradoSessao(string nome, Sessao &s1);
	/**
	@brief function to add a Session to the program
	@param Sessao s1 - Session
	*/
	void adicionaSessao(Sessao s1);
	/**
	@brief function to eliminate a Session from program
	*/
	void eliminarSessao();
	/**
	@brief function that show information present in binary tree
	*/
	void informacao_map();
	/**
	@brief function that show information about all genres
	@param string genero - genre
	*/
	void informacao_genero(string genero);
	/**
	@brief function to get total genres made, according to the vector
	@return the vector of total genres made
	*/
	vector<string>getGeneros();
	/**
	@brief function that adds a new genre to the program
	@param string genero - genre
	*/
	void adicionarGenero(string genero);
	/**
	@brief function that checks the information of a genre placed in queue
	@param string genero - the genre in which we want to know information about
	*/
	void informacao_genero_queue(string genero);
	/**
	@brief function that changes the address of a candidate
	@param string nome - name of candidate; string morada - address of candidate
	*/
	void alterarMorada(string nome, string morada);
	/**
	@brief function that changes the genre in which the candidate is participating
	@param string nome - name of candidate; string genero - genre of the candidate
	*/
	void alterarGenero(string nome, string genero);
	/**
	@brief function that changes the birthdate of a candidate
	@param string nome - name of candidate; Data data - the date in which we want to set
	*/
	void alterarDataNascimento(string nome, Data data);
	/**
	@brief function that gets the current date
	*/
	Data obter_data_atual();
	/**
	@brief function that shows the current date
	*/
	void mostrar_data_atual();
	
	//
	void sort_map();
	/**
	@brief returns the set of unavailable candidates at the time
	*/
	unordered_set<Candidato*, hstr, eqstr> getIndisponiveis() const;

	/**
	@brief Adds the candidate c1 to the set of unavailable candidates at the time
	@param c1 Candidate
	@return Returns true upon success and false otherwise
	*/
	bool adicionarIndisponivel(Candidato * c1);
	/**
	@brief Updates unavailable candidates depending on the current date
	*/
	void updateIndisponiveis();
};

/**
@brief function to compare birth-dates of each candidate, in order to sort them out
@param Candidato *c1 - candidate 1; Candidato *c2 - candidate 2
@return True if the birth-date of the first candidate is lower than the birth-date of the second
*/
bool  comparaDataNascimento(Candidato *c1, Candidato *c2);
/**
@brief function to overload the << operator and print names of all candidates
@param ostream &os -ostream to be able to print; const vector<string> & c1 - vector that contains strings of the names of all candidates on the whole audition program
@return a print of the names of all candidates on the whole audition program all divided by ","
*/
ostream & operator<<(ostream & os, const vector<string> & c1);

/**
@brief function to compare the dates of two sessions in order to sort them out
@param Sessao &s1 - 1st session; Sessao &s2 - 2nd session
@return True if one session is more recent than one another
*/
bool comparaDataSessao(Sessao &s1, Sessao &s2);