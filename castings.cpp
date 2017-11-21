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

void Pessoa::mostraInformacaoNome()
{
}

Pessoa::Pessoa(string nome, string morada, string genero) {
	this->nome = nome;
	this->morada = morada;
	this->genero = genero;
}

// Classe Jurado

Jurado::Jurado() {} // DEFAULT CONSTRUCTOR


Jurado::Jurado(string nome, string morada, string genero, string telemovel) :Pessoa(nome, morada, genero)
{
	this->telemovel = telemovel;
}

Jurado::Jurado(string ficheiro_jurados)
{
	istringstream juradoStream(ficheiro_jurados);

	getline(juradoStream, nome, ';');
	getline(juradoStream, morada, ';');
	getline(juradoStream, genero, ';');
	getline(juradoStream, telemovel);

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
	if (this->getNome() == j1.getNome()) return true;

	return false;
}

void Jurado::mostraInformacao()
{
	cout << "NOME: " << nome << endl;
	cout << "MORADA: " << morada << endl;
	cout << "GENERO: " << genero << endl;
	cout << "CONTACTO: " << telemovel << endl;
}

// Classe Sessao

int Sessao::ids = 0;

Sessao::Sessao() { this->id = ++ids; }

Sessao::Sessao(string ficheiro_sessao)
{
	string concorrentes_I, inicial_temp, concorrentes_F, final_temp, jurados_S, resp, jurado_push;
	string d, dia, mes, ano;

	istringstream sessaoStream(ficheiro_sessao);
	sessaoStream >> id;
	sessaoStream.ignore(1000, ';');
	sessaoStream >> fase;
	sessaoStream.ignore(1000, ';');
	getline(sessaoStream, genero, ';');
	getline(sessaoStream, concorrentes_I, ';');
	istringstream concorrentesI_stream(concorrentes_I);
	while (getline(concorrentesI_stream, inicial_temp, ','))
	{
		inicial_temp = inicial_temp.substr(1, inicial_temp.size());
		concorrentes_iniciais.push_back(inicial_temp);
	}
	getline(sessaoStream, concorrentes_F, ';');
	istringstream concorrentesF_stream(concorrentes_F);
	while (getline(concorrentesF_stream, final_temp, ','))
	{
		final_temp = final_temp.substr(1, final_temp.size());
		concorrentes_finais.push_back(final_temp);
	}
	getline(sessaoStream, jurados_S, ';');
	istringstream juradoStream(jurados_S);
	getline(juradoStream, responsavel, ',');
	jurados_sessao.push_back(responsavel);

	while (getline(juradoStream, jurado_push, ',')) {
		jurado_push = jurado_push.substr(1, jurado_push.size());
		jurados_sessao.push_back(jurado_push);
	}
	getline(sessaoStream, d);
	istringstream dataStream(d);
	getline(dataStream, dia, '-');
	int diaI = stoi(dia);
	data.setDia(diaI);
	getline(dataStream, mes, '-');
	int mesI = stoi(mes);
	data.setMes(mesI);
	getline(dataStream, ano);
	int anoI = stoi(ano);
	data.setAno(anoI);

	this->id = ++ids;
}

int Sessao::getId() const {
	return id;
}

string Sessao::getGenero() const
{
	return genero;
}

Data Sessao::getData()
{
	return data;
}

int Sessao::getFase() const {
	return fase;
}

string Sessao::getResponsavel() const
{
	return responsavel;
}

vector<string>& Sessao::getJurados_sessao()
{
	return jurados_sessao;
}

vector<string> & Sessao::getConcorrentes_iniciais()
{
	return concorrentes_iniciais;
}

vector <string> & Sessao::getConcorrentes_finais() {
	return concorrentes_finais;
}

vector<Pontuacao>& Sessao::getPontuacoes()
{
	return pontuacoes;
	// TODO: inserir instrução de retorno aqui
}

int Sessao::getNumVagas() const
{
	int vagas = numMaxCandidatos - concorrentes_iniciais.size();
	return vagas;
}

int Sessao::getIds() {
	return ids;
}

void Sessao::setData(Data data)
{
	this->data = data;
}

void Sessao::setResponsavel(string j1) {
	this->responsavel = j1;
}

void Sessao::setNumVagas(int vagas) {
	numVagas = vagas;
}

bool Sessao::operator==(Sessao & s1)
{
	if (s1.getGenero() == this->genero && this->data == s1.getData()) return true;
	return false;
}

bool Sessao::eliminaCandidatoSessao(Candidato * c1)
{
	return false;
}

bool Sessao::juriCompleto() const {
	return (jurados_sessao.size() >= 3);
}

bool Sessao::juradoPresente(Jurado * j1)
{
	for (size_t i = 0; i < getJurados_sessao().size(); i++) {
		if (getJurados_sessao().at(i) == j1->getNome())return true;
	}
	return false;
}

void Sessao::setConcorrentes_finais(vector<string> &finais) {
	concorrentes_iniciais = finais;
}

void Sessao::setFase(int fase) {
	this->fase = fase;
}

// Classe Candidato

int Candidato::numInscricoesAtual = 0;

Candidato::Candidato(string nome, string morada, string genero, Data data_nascimento) :Pessoa(nome, morada, genero)
{
	this->numInscricao = ++numInscricoesAtual;
	this->data_nascimento = data_nascimento;
}

Candidato::Candidato(string ficheiro_candidatos)
{
	istringstream candidatosStream(ficheiro_candidatos);
	string d, dia, mes, ano;
	getline(candidatosStream, nome, ';');
	getline(candidatosStream, morada, ';');
	getline(candidatosStream, genero, ';');
	getline(candidatosStream, d);
	istringstream dataStream(d);
	getline(dataStream, dia, '-');
	int diaI = stoi(dia);
	data_nascimento.setDia(diaI);
	getline(dataStream, mes, '-');
	int mesI = stoi(mes);
	data_nascimento.setMes(mesI);
	getline(dataStream, ano);
	int anoI = stoi(ano);
	data_nascimento.setAno(anoI);
	this->numInscricao = ++numInscricoesAtual;

}

Candidato::Candidato() { this->numInscricao = ++numInscricoesAtual; }; // DEFAULT CONSTRUCTOR

Data Candidato::getDataNascimento() const
{
	return data_nascimento;
}

vector<Sessao> Candidato::getSessoes() const
{
	return sessoes;
}

bool Candidato::operator==(Candidato & c1)
{
	if (this->getNome() == c1.getNome()) return true;
	return false;
}

int Candidato::getNumInscricao() const {
	return numInscricao;
}

int Candidato::getNumInscricoes() {
	return numInscricoesAtual;
}

void Candidato::adicionarSessao(Sessao &s1) {
	sessoes.push_back(s1);
}

void Candidato::mostraInformacao()
{
	cout << "NOME: " << nome << endl;
	cout << "MORADA: " << morada << endl;
	cout << "GENERO: " << genero << endl;
	cout << "DATA DE NASCIMENTO: " << this->data_nascimento << endl;
}

void Candidato::setDataNascimento(Data data)
{
	this->data_nascimento = data;
}

void Candidato::setNumInscricoes(int num) {
	numInscricoesAtual = num;
}

double Candidato::getPontuacao(int sessaoId, int fase) const {
	for (size_t i = 0; i < pontuacoes.size(); i++) {
		if (pontuacoes.at(i).getId() == sessaoId && pontuacoes.at(i).getFase() == fase)
			return pontuacoes.at(i).getClassificacao();
	}
	return -1;
}

// Classe Castings

Castings::Castings() {}

Castings::Castings(string ficheiroCandidatos, string ficheiroJurados, string ficheiroSessoes)
{
	this->ficheiroCandidatos = ficheiroCandidatos;
	this->ficheiroJurados = ficheiroJurados;
	this->ficheiroSessoes = ficheiroSessoes;
}

vector<Jurado*> Castings::getJurados()
{
	return jurados;
}

vector<Candidato*> Castings::getCandidatos()
{
	return candidatos;
}

vector<Sessao> Castings::getSessao()
{
	return sessoes;
}

size_t Castings::juradoExiste(Jurado * j1) {
	size_t ind = -1;
	for (size_t i = 0; i < jurados.size(); i++) {
		if (j1 == jurados.at(i))
			ind = i;
	}
	return ind;
}

size_t Castings::juradoExiste(string nome) {
	size_t ind = -1;
	
	for (size_t i = 0; i < jurados.size(); i++) {
		if (jurados.at(i)->getNome() == nome) // para simplificar, dois jurados são iguais se tiverem o mesmo nome
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

size_t Castings::candidatoExiste(string nome) {
	size_t ind = -1;

	for (size_t i = 0; i < candidatos.size(); i++) {
		if (candidatos.at(i)->getNome() == nome) // para simplificar, dois candidatos são iguais se tiverem o mesmo nome
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
		if (j1->getNome() == sessoes.at(i).getJurados_sessao().at(j))
			ind = j;
	}

	return ind;
}

bool Castings::adicionaCandidato(Candidato *c1)
{
	if (candidatoExiste(c1) != -1)
		throw CandidatoRepetido(c1);
	for (size_t i = 0; i < candidatos.size(); i++) {
		if (candidatos.at(i) == c1)
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
					if (sessoes.at(i).getConcorrentes_iniciais().at(i) == c1->getNome()) {
						throw CandidatoRepetido(c1);
						return false;
					}
				}
				sessoes.at(i).getConcorrentes_iniciais().push_back(c1->getNome());
				c1->adicionarSessao(s1);
				s1.setNumVagas(s1.getNumVagas() - 1);
				return true;
			}
			else {
				cout << "Nao existem mais vagas na sessao indicada. \n";
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
		if (sessoes.at(countS).getJurados_sessao().at(k) == j1->getNome())
			throw JuradoRepetido(j1);
	}

	if (sessoes.at(countS).juriCompleto())
		throw JuradosCompleto();
	else {
		sessoes.at(countS).getJurados_sessao().push_back(j1->getNome());
		return true;
	}

	return false;
}

bool Castings::eliminaCandidato(Candidato * c1)
{
	Candidato *c = nullptr;
	for (size_t i = 0; i < sessoes.size(); i++) {
		for (size_t j = 0; j < sessoes.at(i).getConcorrentes_iniciais().size(); j++) {
			if (sessoes.at(i).getConcorrentes_iniciais().at(j) == c1->getNome()) {
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

bool Castings::eliminaJurado(Jurado * j1)
{
	bool presente = false;
	for (size_t j = 0; j < sessoes.size(); j++) {
		if (sessoes.at(j).juradoPresente(j1))
			return false; //N?o ? poss?vel eliminar um jurado quando ele est? presente numa sess?o
	}
	for (size_t i = 0; i < jurados.size(); i++) {
		if (jurados.at(i) == j1) {
			jurados.erase(jurados.begin() + i);
			return true;
		}
	}
	getchar(); getchar();
	return false;
}

bool Castings::eliminaCandidatoSessao(Candidato *c1, Sessao &s1) {
	Candidato * c = nullptr, *c2 = nullptr;
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
		if (c1->getNome() == sessoes.at(index).getConcorrentes_iniciais().at(i)) {
			c2 = c1;
			sessoes.at(index).getConcorrentes_iniciais().erase(sessoes.at(index).getConcorrentes_iniciais().begin() + i);
			return true;
		}
	}

	for (size_t i = 0; i < sessoes.at(index).getConcorrentes_finais().size(); i++) {
		if (c1->getNome() == sessoes.at(index).getConcorrentes_finais().at(i)) {
			c2 = c1;
			sessoes.at(index).getConcorrentes_finais().erase(sessoes.at(index).getConcorrentes_finais().begin() + i);
			return true;
		}
	}

	if (c2 == nullptr)
		throw CandidatoInexistente(c1);

	return false;
}

bool comparaDataNascimento(Candidato * c1, Candidato *c2)
{
	if (c1->getDataNascimento() < c2->getDataNascimento())
		return true;
	if (c1->getDataNascimento() == c2->getDataNascimento()) {
		if (c1->getNome() < c2->getNome()) return true;
	}
	return false;
}

void Castings::ordenaCandidatosData()
{
	sort(candidatos.begin(), candidatos.end(), comparaDataNascimento);
}

void Castings::setUpCandidatos()
{
	ifstream file(ficheiroCandidatos);
	string candidato;

	while (getline(file, candidato))
	{
		candidatos.push_back(&Candidato(candidato));
	}
}

void Castings::setUpJurados()
{
	ifstream file(ficheiroJurados);
	string  jurado;
	while (getline(file, jurado)) {
		jurados.push_back(&Jurado(jurado));
	}
}

void Castings::setUpSessoes()
{
	ifstream file(ficheiroSessoes);
	string sessao;
	while (getline(file, sessao)) {
		sessoes.push_back(Sessao(sessao));
	}
}

void Castings::mostraInformacaoCandidatos()
{
	for (size_t i = 0; i < candidatos.size(); i++) {
		cout << endl;
		candidatos.at(i)->mostraInformacao();
	}
}

void Castings::mostraInformacaoJurados()
{
	for (size_t i = 0; i < jurados.size(); i++) {
		cout << endl;
		jurados.at(i)->mostraInformacao();
	}
}

bool Castings::tornaJuradoResponsavel(Jurado * j1, Sessao &s1) {
	size_t i = sessaoExiste(s1), j = juradoExisteSessao(j1, s1);
	vector<string> temp(3);
	vector<string> * vj;

	if (juradoExiste(j1) == -1)
		throw JuradoInexistente(j1);
	if (i == -1)
		throw SessaoInexistente(s1);
	if (j == -1)
		throw JuradoInexistente(j1);
	if (sessoes.at(i).juriCompleto())
		throw JuradosCompleto();

	sessoes.at(i).setResponsavel(j1->getNome());
	temp.at(0) = j1->getNome();

	for (size_t k = 0; k < sessoes.at(i).getJurados_sessao().size(); k++) {
		if (sessoes.at(i).getJurados_sessao().at(k) != "")
			temp.push_back(sessoes.at(i).getJurados_sessao().at(k));
	}

	vj = &sessoes.at(i).getJurados_sessao();

	temp = sessoes.at(i).getJurados_sessao();
	return true;
}

bool Castings::comecarFase2(Sessao &s1) {
	if (s1.getFase() == 2)
		return false;

	vector<string> concorrentes = s1.getConcorrentes_iniciais();
	int i = -1, id = s1.getId(), fase = s1.getFase();
	double pontuacao;
	multimap<double, string> concorrentesOrdenado;
	vector<string> apurados;

	for (auto nome : concorrentes) {
		i = candidatoExiste(nome);
		pontuacao = candidatos.at(i)->getPontuacao(id, fase);
		concorrentesOrdenado.insert(pair<double, string>(pontuacao, nome));
	}

	if (concorrentesOrdenado.size() <= 5) {
		for (multimap<double,string>::iterator it=concorrentesOrdenado.begin(); it != concorrentesOrdenado.end() ; it++) 
			apurados.push_back(it->second);
		s1.setConcorrentes_finais(apurados);
		s1.setFase(2);
		return true;
	}

	sort(concorrentesOrdenado.begin(), concorrentesOrdenado.end());

	multimap<double, string>::iterator it0 = concorrentesOrdenado.begin(), it5 = concorrentesOrdenado.begin();
	
	for (int n = 0; n < 5; n++) // multimap não suporta random iterators
		it5++; 
	// it5 aponta agora para o 6º par

	while (it0 != it5) {
		apurados.push_back(it0->second);
		it0++;
	}

	s1.setConcorrentes_finais(apurados);
	s1.setFase(2);
	return true;
}

void Castings::atribuirPontuacao(Sessao & s1)
{
	int p1, p2, p3;
	int pos = 0;
	bool juradosC = true;
	for (size_t i = 0; i < sessoes.size(); i++) {
		if (sessoes.at(i) == s1) {
			pos = i;
			if (sessoes.at(i).getJurados_sessao().size() != 3) {
				cout << "FALTA ATRIBUIR JURADOS." << endl;
				juradosC = false;
			}
		}
	}
	vector<int>p;
	for (size_t i = 0; i < sessoes.at(pos).getConcorrentes_iniciais().size(); i++) {
		cout << "PONTUACOES|| CONCORRENTE: " << sessoes.at(pos).getConcorrentes_iniciais().at(i) << endl;
		cout << sessoes.at(pos).getJurados_sessao().at(0) << ": ";
		cin >> p1;
		while (p1 > 10 || p1 < 0) {
			cout << "PONTUACAO INVALIDA. INSIRA UMA PONTUACAO ENTRE 0-10";
			cin >> p1;
			cout << endl;
		}
		p.push_back(p1);
		cout << endl;
		cout << sessoes.at(pos).getJurados_sessao().at(1) << ": ";
		cin >> p2;
		while (p2 > 10 || p2 < 0) {
			cout << "PONTUACAO INVALIDA. INSIRA UMA PONTUACAO ENTRE 0-10";
			cin >> p2;
			cout << endl;
		}
		p.push_back(p2);
		cout << endl;
		cout << sessoes.at(pos).getJurados_sessao().at(2) << ": ";
		cin >> p3;
		while (p3 > 10 || p3 < 0) {
			cout << "PONTUACAO INVALIDA. INSIRA UMA PONTUACAO ENTRE 0-10";
			cin >> p3;
			cout << endl;
		}
		p.push_back(p3);
		cout << endl;
		Pontuacao P(sessoes.at(pos).getConcorrentes_iniciais().at(i), sessoes.at(pos).getIds(), sessoes.at(pos).getFase(), p);
		sessoes.at(pos).getPontuacoes().push_back(P);
	}

	

}

// Classe Pontuacao

Pontuacao::Pontuacao(string nomeCandidato, int id_sessao, int fase, vector<int> classificacoes)
{
	this->nomeCandidato = nomeCandidato;
	this->id_sessao = id_sessao;
	this->fase = fase;
	this->classificacoes = classificacoes;
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
	double classificacao = 0;
	if (fase == 1) {
		for (size_t i = 0; i < classificacoes.size(); i++) {
			classificacao += classificacoes.at(i);
		}
		classificacao = classificacao / 3;
		//1aFASE
		//Media das 3 classificacoes
	}
	else {
		classificacao = 0.5*classificacoes.at(0) + 0.50*((classificacoes.at(1) + classificacoes.at(2)) / 2);
		//2aFASE
		//Pois esta estabelecido que, por pre-definicao, o jurado responsavel e o primeiro.
	}

	return classificacao;
}

// definicao da classe Data

int Data::getDia()
{
	return dia;
}

int Data::getMes()
{
	return mes;
}

int Data::getAno()
{
	return ano;
}

void Data::setDia(int dia)
{
	this->dia = dia;
}

void Data::setMes(int mes)
{
	this->mes = mes;
}

void Data::setAno(int ano)
{
	this->ano = ano;
}

bool Data::operator==(Data & d1)
{
	if (this->getDia() == d1.getDia() && this->getMes() == d1.getMes() && this->getAno() == d1.getAno())return true;
	return false;
}

bool Data::operator<(Data & d1) const
{
	if (this->ano < d1.ano)return true;
	else
		if (this->ano == d1.ano) {
			if (this->mes < d1.mes)return true;
			else
				if (this->mes == d1.mes && this->dia < dia) return true;
		}
	return false;
}

void Data::operator=(Data & d1)
{
	this->dia = d1.dia;
	this->mes = d1.mes;
	this->ano = d1.ano;

}
 
ostream & operator<<(ostream & os, const Data & d1)
{
	 os << d1.dia << "-" << d1.mes << "-" << d1.ano;
	 return os;

	// TODO: inserir instrução de retorno aqui
}

ostream & operator<<(ostream & os, const vector<string> & c1) {
	for (size_t i = 0; i < c1.size(); i++)
	{
		if (i == c1.size() - 1) {
			cout << c1.at(i);
			break;
		}
		os << c1.at(i) << ", ";
	}
	return os;
}






