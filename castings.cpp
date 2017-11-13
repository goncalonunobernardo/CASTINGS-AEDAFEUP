#include "castings.h"
using namespace std;

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
void Pessoa::setMorada(string morada)
{
	this->morada = morada;
}
Pessoa::Pessoa(string nome, string morada, string genero) {
	this->nome = nome;
	this->morada = morada;
	this->genero = genero;
}

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


vector<int> Sessao::getClassificacao() const
{
	return classificacao;
}

string Sessao::getResponsavel() const
{
	return responsavel;
}

vector<Jurado> Sessao::getJurados_sessao()const 
{
	return jurados_sessao;
}

vector<Candidato> Sessao::getConcorrentes_iniciais() const
{
	return concorrentes_iniciais;
}

Candidato::Candidato(string nome, string morada, string genero, string data_nascimento):Pessoa(nome,morada,genero)
{
	this->data_nascimento = data_nascimento;
}

string Candidato::getDataNascimento() const
{
	return data_nascimento;
}

vector<Sessao> Candidato::getSessoes() const
{
	return sessoes;
}

vector<Jurado> Castings::getJurados() const
{
	return jurados;
}

vector<Candidato> Castings::getCandidatos() const
{
	return candidatos;
}

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
