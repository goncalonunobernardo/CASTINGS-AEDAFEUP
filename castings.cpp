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

Jurado::Jurado(string nome, string morada, string genero, int telemovel):Pessoa(nome, morada,genero)
{
	this->telemovel = telemovel;
}

int Jurado::getTelemovel() const
{
	return telemovel;
}

void Jurado::setTelemovel(string telemovel) const
{
	this->telemovel = telemovel;
}

int Sessao::getOrdem() const
{
	return ordem;
}

int Sessao::getClassificacao() const
{
	return classificacao;
}

string Sessao::getResponsavel() const
{
	return responsavel;
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
