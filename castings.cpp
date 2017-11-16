#include "castings.h"
#include "exceptions.h"
using namespace std;

// Classe Pessoa

Pessoa::Pessoa() {} // DEFAULT CONSTRUCTOR

string Pessoa::getNome() const
{
	return nome;
}

string Pessoa::getMorada() const
{
	return morada;
}

string Pessoa::getGenero() const
{
	return genero;
}

void Pessoa::setNome(string nome) {
	this->nome = nome;
}

void Pessoa::setMorada(string morada)
{
	this->morada = morada;
}

void Pessoa::setGenero(string genero) {
	this->genero = genero;
}

bool Pessoa::operator==(Pessoa & p1)
{
	
	return false;
}

Pessoa::Pessoa(string nome, string morada, string genero) {
	this->nome = nome;
	this->morada = morada;
	this->genero = genero;
}

// Classe Jurado

Jurado::Jurado() {} // DEFAULT CONSTRUCTOR

Jurado::Jurado(string nome, string morada, string genero, string telemovel):Pessoa(nome, morada,genero)
{
	this->telemovel = telemovel;
}

string Jurado::getTelemovel() const
{
	return telemovel;
}

void Jurado::setTelemovel(string telemovel) 
{
	this->telemovel = telemovel;
}

bool Jurado::operator==(Jurado & j1)
{
	if (this->getNome() == j1.getNome() && this->getMorada() == j1.getMorada() && this->getTelemovel()==j1.getTelemovel()) return true;
	return true;

	return false;
}

// Classe Sessao

int Sessao::getId() const {
	return id;
}

string Sessao::getGenero() const
{
	return genero;
}

string Sessao::getData() const
{
	return data;
}

Jurado Sessao::getResponsavel() const
{
	return responsavel;
}

vector<Jurado*>& Sessao::getJurados_sessao() 
{
	return jurados_sessao;
	// TODO: inserir instrução de retorno aqui
}

vector<Candidato*> & Sessao::getConcorrentes_iniciais() 
{
	return concorrentes_iniciais;
}

vector <Candidato*> & Sessao::getConcorrentes_finais()  {
	return concorrentes_finais;
}

int Sessao::getNumVagas() const
{
	int vagas = numMaxCandidatos - concorrentes_iniciais.size();
	return vagas;
}

void Sessao::setResponsavel(Jurado j1) {
	responsavel = j1;
}

bool Sessao::operator==(Sessao & s1)
{
	if (s1.getGenero() == this->genero && this->data == s1.getData()) return true;
	return false;
}

bool Sessao::juriCompleto() const {
	return (jurados_sessao.size() >= 3);
}

// Classe Candidato

Candidato::Candidato(string nome, string morada, string genero, string data_nascimento):Pessoa(nome,morada,genero)
{
	this->data_nascimento = data_nascimento;
}

Candidato::Candidato() {}; // DEFAULT CONSTRUCTOR

string Candidato::getDataNascimento() const
{
	return data_nascimento;
}

vector<Sessao> Candidato::getSessoes() const
{
	return sessoes;
}

bool Candidato::operator==(Candidato & c1)
{
	if (this->getNome() == c1.getNome() && this->getMorada() == c1.getMorada() && this->getDataNascimento()==c1.getDataNascimento()) return true;
	return false;
}

void Candidato::adicionarSessao(Sessao &s1) {
	sessoes.push_back(s1);
}

// Classe Castings

size_t Castings::juradoExiste(Jurado * j1) {
	size_t ind = -1;
	for (size_t i = 0; i < jurados.size(); i++) {
		if (j1 == jurados.at(i))
			ind = i;
	}
	return ind;
}

size_t Castings::candidatoExiste(Candidato * c1) {
	size_t ind = -1;
	
	for (size_t i = 0; i < candidatos.size(); i++) {
		if (c1 == candidatos.at(i))
			ind = i;
	}
	return ind;
}

size_t Castings::sessaoExiste(Sessao &s1) {
	size_t ind = -1;

	for (size_t j = 0; j < sessoes.size(); j++) {
		if (s1 == sessoes.at(j))
			ind = j;
	}

	return ind;
}

size_t Castings::juradoExisteSessao(Jurado * j1, Sessao &s1) {
	size_t i, ind = -1;
	i = sessaoExiste(s1);
	
	for (size_t j = 0; j < sessoes.at(i).getJurados_sessao().size(); j++) {
		if (j1 == sessoes.at(i).getJurados_sessao().at(j))
			ind = j;
	}

	return ind;
}

bool Castings::adicionaCandidato(Candidato *c1)
{
	for (size_t i = 0; i < candidatos.size(); i++) {
			if (candidatos.at(i)==c1)
			return false;
		}
	candidatos.push_back(c1);
	return true;
}

bool Castings::adicionaJurado(Jurado *j1)
{
	if (juradoExiste(j1) != -1)
		throw JuradoRepetido(j1);
	jurados.push_back(j1);
	return true;
}

bool Castings::adicionaCandidatoSessao(Candidato *c1, Sessao &s1)
{
	if (candidatoExiste(c1) == -1)
		throw CandidatoInexistente(c1);

	for (size_t i = 0; i < sessoes.size(); i++) {
		if (s1 == sessoes.at(i)) {
			if (sessoes.at(i).getNumVagas() > 0)
			{
				for (size_t j = 0; j < sessoes.at(i).getConcorrentes_iniciais().size(); j++) {
					if (sessoes.at(i).getConcorrentes_iniciais().at(i) == c1) throw CandidatoRepetido(c1);
				}
				sessoes.at(i).getConcorrentes_iniciais().push_back(c1);
				c1->adicionarSessao(s1);
				return true;
			}
			else {
				cout << "Não existem mais vagas na sessão indicada. \n";
				return false;
			}
		}
	}

	throw SessaoInexistente(s1);
}

bool Castings::adicionaJuradoSessao(Jurado * j1, Sessao &s1)
{	
	int countS = sessaoExiste(s1);

	if (juradoExiste(j1) == -1)
		throw JuradoInexistente(j1);

	if (countS == -1) 
		throw SessaoInexistente(s1);
	
	for (size_t k = 0; k < sessoes.at(countS).getJurados_sessao().size(); k++) {
		if (sessoes.at(countS).getJurados_sessao().at(k) == j1) 
			throw JuradoRepetido(j1);	
	}

	if (sessoes.at(countS).juriCompleto())
		throw JuradosCompleto();
	else {
		sessoes.at(countS).getJurados_sessao().push_back(j1);
		return true;
	}

	return false;
}

bool Castings::eliminaCandidato(Candidato * c1)
{
	Candidato *c = nullptr;
	for (size_t i = 0; i < sessoes.size(); i++) {
		for (size_t j = 0; j < sessoes.at(i).getConcorrentes_iniciais().size(); j++) {
			if (sessoes.at(i).getConcorrentes_iniciais().at(j) == c1) {
				sessoes.at(i).getConcorrentes_iniciais().erase(sessoes.at(i).getConcorrentes_iniciais().begin() + j);
			}
		}
	}
	for (size_t i = 0; i < candidatos.size(); i++) {
		if (candidatos.at(i) == c1) {
			c = candidatos.at(i);
			candidatos.erase(candidatos.begin() + i);
			return true;
		}
	}

	if (c == nullptr) {
		throw CandidatoInexistente(c1);
	}
	return false;
}

bool Castings::eliminaCandidatoSessao(Candidato *c1, Sessao &s1) {
	Candidato * c = nullptr, * c2 = nullptr;
	size_t index = -1;

	for (size_t i = 0; i < candidatos.size(); i++) {
		if (candidatos.at(i) == c1) 
			c = candidatos.at(i);
	}

	if (c == nullptr)
		throw CandidatoInexistente(c1);

	for (size_t i = 0; i < sessoes.size(); i++) {
		if (s1 == sessoes.at(i))
			index = i;
	}

	if (index == -1)
		throw SessaoInexistente(s1);

	for (size_t i = 0; i < sessoes.at(index).getConcorrentes_iniciais().size(); i++) {
		if (c1 == sessoes.at(index).getConcorrentes_iniciais().at(i)) {
			c2 = c1;
			sessoes.at(index).getConcorrentes_iniciais().erase(sessoes.at(index).getConcorrentes_iniciais().begin() + i);
			return true;
		}
	}

	for (size_t i = 0; i < sessoes.at(index).getConcorrentes_finais().size(); i++) {
		if (c1 == sessoes.at(index).getConcorrentes_finais().at(i)) {
			c2 = c1;
			sessoes.at(index).getConcorrentes_finais().erase(sessoes.at(index).getConcorrentes_finais().begin() + i);
			return true;
		}
	}

	if (c2 == nullptr)
		throw CandidatoInexistente(c1);

	return false;
}

// por completar
bool Castings::eliminaJurado(Jurado * j1) {
	for (unsigned int i = 0; i < sessoes.size(); i++) {
		for (unsigned int j = 0; j < sessoes.at(i).getJurados_sessao().size(); j++) {

		}
	}
	return true; //TO DO 
}

bool Castings::tornaJuradoResponsavel(Jurado * j1, Sessao &s1) {
	size_t i = sessaoExiste(s1), j = juradoExisteSessao(j1, s1);
	vector<Jurado *> temp(3);
	vector<Jurado *> * vj;

	if (juradoExiste(j1) == -1)
		throw JuradoInexistente(j1);
	if (i == -1)
		throw SessaoInexistente(s1);
	if (j == -1)
		throw JuradoInexistente(j1);
	if (sessoes.at(i).juriCompleto())
		throw JuradosCompleto();
	
	sessoes.at(i).setResponsavel(*j1);
	temp.at(0) = j1;

	for (size_t k = 0; i < sessoes.at(i).getJurados_sessao().size(); k++) {
		if (sessoes.at(i).getJurados_sessao().at(k) != nullptr)
			temp.push_back(sessoes.at(i).getJurados_sessao().at(k));
	}

	vj = &sessoes.at(i).getJurados_sessao();

	sessoes.at(i).getJurados_sessao() = temp;
	return true;
}

// Classe Pontuacao

int Pontuacao::getId() const
{
	return id_sessao;
}

int Pontuacao::getFase() const
{
	return fase;
}

vector<int> Pontuacao::getClassificacoes() const
{
	return classificacoes;
}

double Pontuacao::getClassificacao() const
{
	double classificacao=0;
	if (fase == 1) {
		for (size_t i = 0; i < classificacoes.size(); i++) {
			classificacao += classificacoes.at(i);
		}
		classificacao = classificacao / 3;
		//1ªFASE
		//Média das 3 classificações
	}
	else {
		classificacao = 0.5*classificacoes.at(0)+0.50*((classificacoes.at(1)+classificacoes.at(2))/2);
		//2ªFASE
		//Pois está estabelecido que, por pre-definição, o jurado responsável é o primeiro.
	}
		
	return classificacao;
}
