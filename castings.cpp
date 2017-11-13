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
bool Pessoa::operator==(Pessoa & p1)
{
	
	return false;
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

bool Jurado::operator==(Jurado & j1)
{
	if (this->getNome() == j1.getNome() && this->getMorada() == j1.getMorada() && this->getTelemovel()==j1.getTelemovel()) return true;
	return true;

	return false;
}




string Sessao::getGenero() const
{
	return genero;
}

string Sessao::getData() const
{
	return data;
}

string Sessao::getResponsavel() const
{
	return responsavel;
}

vector<Jurado> & Sessao::getJurados_sessao()const 
{
	return jurados_sessao;
}

vector<Candidato> & Sessao::getConcorrentes_iniciais() const
{
	return concorrentes_iniciais;
}

int Sessao::getNumVagas() const
{
	int vagas = numMaxCandidatos - concorrentes_iniciais.size();
	return vagas;
}

bool Sessao::operator==(Sessao & s1)
{
	if (s1.getGenero() == this->genero && this->data == s1.getData()) return true;
	return false;
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

bool Candidato::operator==(Candidato & c1)
{
	if (this->getNome() == c1.getNome() && this->getMorada() == c1.getMorada() && this->getDataNascimento()==c1.getDataNascimento()) return true;
	return false;
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
	for (size_t i = 0; i < jurados.size(); i++) {
		if (jurados.at(i) == j1) return false;
	}
	jurados.push_back(j1);
	return true;
}

bool Castings::adicionaCandidatoSessao(Candidato & c1, Sessao &s1)
{

	for (size_t i = 0; i < sessoes.size(); i++) {
		if (s1 == sessoes.at(i)) {
			if (sessoes.at(i).getNumVagas() > 0)
			{
				for (size_t j = 0; j < sessoes.at(i).getConcorrentes_iniciais().size(); j++) {
					if (sessoes.at(i).getConcorrentes_iniciais().at(i) == c1) throw CandidatoRepetido(c1);
				}
				sessoes.at(i).getConcorrentes_iniciais().push_back(c1);
				return true;
			}
			else
				return false;
		}
	}
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
