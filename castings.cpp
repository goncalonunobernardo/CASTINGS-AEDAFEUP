#include "castings.h"
#include "exceptions.h"

using namespace std;

Data data_atual;
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


Jurado::Jurado(string nome, string morada, string genero, string telemovel) :Pessoa(nome, morada, genero)
{
	this->telemovel = telemovel;
}

Jurado::Jurado(string ficheiro_jurados)
{
	istringstream juradoStream(ficheiro_jurados);
	string nomeS, moradaS, generoS;
	
	getline(juradoStream, nomeS, ';');
	nome = nomeS.substr(0, nomeS.size() - 1);
	getline(juradoStream, moradaS, ';');
	morada = moradaS.substr(0, moradaS.size() - 1);
	getline(juradoStream, generoS, ';');
	genero = generoS.substr(0,generoS.size() - 1);
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


// Classe Sessao

int Sessao::ids = 0;

Sessao::Sessao() { this->id = ++ids; 


}

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
	genero = genero.substr(1, genero.size()-2);
	sessaoStream >> numMaxCandidatos;
	sessaoStream.ignore(1000, ';');
	getline(sessaoStream, concorrentes_I, ';');
	istringstream concorrentesI_stream(concorrentes_I);
	while (getline(concorrentesI_stream, inicial_temp, ','))
	{
		inicial_temp = inicial_temp.substr(1, inicial_temp.size()-2);
		concorrentes_iniciais.push_back(inicial_temp);

	}
	getline(sessaoStream, concorrentes_F, ';');
	istringstream concorrentesF_stream(concorrentes_F);
	while (getline(concorrentesF_stream, final_temp, ','))
	{
		final_temp = final_temp.substr(1, final_temp.size()-2);
		concorrentes_finais.push_back(final_temp);
	}
	getline(sessaoStream, jurados_S, ';');
	istringstream juradoStream(jurados_S);
	getline(juradoStream, responsavel, ',');
	responsavel = responsavel.substr(1, responsavel.size() - 2);
	jurados_sessao.push_back(responsavel);
	while (getline(juradoStream, jurado_push, ',')) {
		jurado_push = jurado_push.substr(1, jurado_push.size()-2);
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
	this->numVagas = numMaxCandidatos - concorrentes_iniciais.size();
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

vector<Pontuacao> Sessao::getPontuacoes()
{
	return pontuacoes;
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

int Sessao::getNumVagas() const
{
	int vagas = numMaxCandidatos - concorrentes_iniciais.size();
	return vagas;
}

int Sessao::getIds() {
	return ids;
}

void Sessao::setNumMaxCandidatos(int numMaxCandidatos)
{
	this->numMaxCandidatos = numMaxCandidatos;
}

void Sessao::setResponsavel(string responsavel)
{
	this->responsavel = responsavel;
}

void Sessao::setConcorrentesIniciais(vector<string> concorrentes_iniciais)
{
	this->concorrentes_iniciais = concorrentes_iniciais;
}

int Sessao::getNumMaxCandidatos() const
{
	return numMaxCandidatos;
}

void Sessao::setData(Data data)
{
	this->data = data;
}


void Sessao::setId(int id)
{
	this->id = id;
}

void Sessao::setNumVagas(int vagas) {
	numVagas = vagas;
}

bool Sessao::operator==(Sessao & s1)
{
	if (s1.getGenero() == this->genero && this->data == s1.getData()) return true;
	return false;
}



bool Sessao::juriCompleto() const {
	return (jurados_sessao.size() >= 3);
}

bool Sessao::juradoPresente(string nome)
{
	for (size_t i = 0; i < getJurados_sessao().size(); i++) {
		string nome = getJurados_sessao().at(i);
		if (getJurados_sessao().at(i) ==nome)return true;
	}
	return false;
}



bool Sessao::operator<(Sessao & s1)
{
	if (s1.getGenero() == this->genero)
	return (this->data < s1.getData());
	else return (this->genero < s1.getGenero());
}

priority_queue<Candidato*>& Sessao::getEntrevistas()
{
	return entrevistas;
}

void Sessao::setEntrevistas(priority_queue<Candidato*> entrevista)
{
	this->entrevistas = entrevista;
}

void Sessao::adicionarEntrevista(Candidato * c1)
{
	entrevistas.push(c1);
}



void Sessao::setConcorrentes_finais(vector<string> finais) {
	this->concorrentes_finais = finais;
}

void Sessao::setGenero(string genero)
{
	this->genero = genero;
}

void Sessao::setJurados(vector<string> jurados)
{
	this->jurados_sessao = jurados;
}

void Sessao::setFase(int fase) {
	this->fase = fase;
}

//NOTCOMPLETE
void Sessao::realizar_entrevista(string genero, unsigned int n_entrevistas)
{
	priority_queue<Candidato*> aux = entrevistas;
	unsigned int i = 0;
	//current interview must be different than the second one, and so on...
	aux.pop();

	while (i < n_entrevistas)
	{
		if (entrevistas.top() != aux.top())
		{
			if (data_atual < data)
			{
				entrevistas.pop();
				i++;
				aux.pop();
			}
			else
				break;
		}
	}
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
	string d, dia, mes, ano,nomeS;
	getline(candidatosStream, nomeS, ';');
	nome = nomeS.substr(0, nomeS.size() - 1);
	getline(candidatosStream, morada, ';');
	morada = morada.substr(0, morada.size() - 1);
	getline(candidatosStream, genero, ';');
	genero = genero.substr(1, genero.size() - 2);
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

bool Candidato::operator==(Candidato *c1)
{
	if (this->getNome() == c1->getNome()) return true;
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


vector<Pontuacao> Candidato::getPontuacoes()
{
	return pontuacoes;
}

bool Candidato::operator<(Candidato * c1)
{
	sort(this->sessoes.begin(), this->sessoes.end(),comparaDataSessao);
	sort(c1->sessoes.begin(), c1->sessoes.end(), comparaDataSessao);
	if (this->sessoes.at(0).getData() == c1->sessoes.at(0).getData()) return (this->sessoes.at(0).getGenero() < c1->sessoes.at(0).getGenero());
	else
		return (this->sessoes.at(0).getData() < c1->sessoes.at(0).getData());
}



void Candidato::setDataNascimento(Data data)
{
	this->data_nascimento = data;
}

void Candidato::setNumInscricoes(int num) {
	numInscricoesAtual = num;
}

double Candidato::getPontuacao(int sessaoId, int fase) {
	for (size_t i = 0; i < pontuacoes.size(); i++) {
		if (pontuacoes.at(i).getId() == sessaoId && pontuacoes.at(i).getFase() == fase)
			return pontuacoes.at(i).getClassificacao();
	}
	return -1;
}

// Classe Castings

Castings::Castings() {}

pair<pair<Data, Data>, string> Candidato::getIndisponibilidade() const {
	return indisponibilidade;
}

void Candidato::setIndisponibilidade(pair<pair<Data, Data>, string> indisp) {
	indisponibilidade.first.first = indisp.first.first;	indisponibilidade.first.second = indisp.first.second;	indisponibilidade.second = indisp.second;
}

void Candidato::setIndisponibilidade(Data dataI, Data dataF, string razao) {
	pair<Data, Data> periodo(dataI, dataF);
	pair<pair<Data, Data>, string> indisp(periodo, razao);
	setIndisponibilidade(indisp);
}
Castings::Castings(string ficheiroCandidatos, string ficheiroJurados, string ficheiroSessoes,string ficheiroPontuacoes)
{
	this->ficheiroCandidatos = ficheiroCandidatos;
	this->ficheiroJurados = ficheiroJurados;
	this->ficheiroSessoes = ficheiroSessoes;
	this->ficheiroPontuacoes = ficheiroPontuacoes;
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

multimap<string, Candidato*> Castings::getCandidatos_genero()
{
	return candidatos_genero;
}

vector<string> Castings::getVencedores()
{
	return vencedores;
}

int Castings::juradoExiste(Jurado * j1) {
	int ind = -1;
	for (size_t i = 0; i < jurados.size(); i++) {
		if (j1->getNome() == jurados.at(i)->getNome())
			ind = i;
	}
	return ind;
}

int Castings::juradoExiste(string nome) {
	int ind = -1;
	
	for (size_t i = 0; i < jurados.size(); i++) {
		if (jurados.at(i)->getNome() == nome) // para simplificar, dois jurados sao iguais se tiverem o mesmo nome
			ind = i;
	}
	return ind;
}

int Castings::candidatoExiste(Candidato * c1) {


	for (auto it : candidatos_genero) {
		if (it.second->getNome() == c1->getNome())
		{
			cout << it.second->getNome() << endl;
			return 0;

		}
	}
	return -1;
}

 int Castings::candidatoExiste(string nome) {

	for (auto it: candidatos_genero) {
		if (it.second->getNome() == nome) // para simplificar, dois candidatos sao iguais se tiverem o mesmo nome
			return 0;
		
	}
	return -1;
}

int Castings::sessaoExiste(Sessao &s1) {
	int ind = -1;

	for (size_t j = 0; j < sessoes.size(); j++) {
		if (s1 == sessoes.at(j))
			ind = j;
	}

	return ind;
}

int Castings::juradoExisteSessao(Jurado * j1, Sessao &s1) {
	int i, ind = -1;
	i = sessaoExiste(s1);

	for (size_t j = 0; j < sessoes.at(i).getJurados_sessao().size(); j++) {
		if (j1->getNome() == sessoes.at(i).getJurados_sessao().at(j))
			ind = j;
	}

	return ind;
}

void Castings::setFicheiroSessoes(string ficheiroSessoes)
{
	this->ficheiroSessoes = ficheiroSessoes;
}

void Castings::setFicheiroJurados(string ficheiroJurados)
{
	this->ficheiroJurados = ficheiroJurados;
}

void Castings::setFicheiroCandidatos(string ficheiroCandidatos)
{
	this->ficheiroCandidatos = ficheiroCandidatos;
}

void Castings::setFicheiroPontuacoes(string ficheiroPontuacoes)
{
	this->ficheiroPontuacoes = ficheiroPontuacoes;
}

bool Castings::adicionaCandidato(Candidato *c1)
{
	if (candidatoExiste(c1) != -1) 
		throw CandidatoRepetido(c1);
	
	//candidatos.push_back(c1);
	candidatos_genero.insert(make_pair(c1->getGenero(), c1));
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
					string x = sessoes.at(i).getConcorrentes_iniciais().at(j);
					if (sessoes.at(i).getConcorrentes_iniciais().at(j) == c1->getNome()) {
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

void Castings::adicionaJuradoSessao(string nome, Sessao &s1)
{
	int countS = sessaoExiste(s1);

	if (juradoExiste(nome) == -1)
		throw JuradoInexistente(nome);

	if (countS == -1)
		throw SessaoInexistente(s1);

	for (size_t k = 0; k < sessoes.at(countS).getJurados_sessao().size(); k++) {
		if (sessoes.at(countS).getJurados_sessao().at(k) == nome)
			throw JuradoRepetido(nome);
	}

	if (sessoes.at(countS).juriCompleto())
		throw JuradosCompleto();
	else {
		sessoes.at(countS).getJurados_sessao().push_back(nome);
	}
}

bool Castings::eliminaCandidato(string nome)
{
	
	
	for (size_t i = 0; i < sessoes.size(); i++) {
		for (size_t j = 0; j < sessoes.at(i).getConcorrentes_iniciais().size(); j++) {
			if (sessoes.at(i).getConcorrentes_iniciais().at(j) == nome) {
				sessoes.at(i).getConcorrentes_iniciais().erase(sessoes.at(i).getConcorrentes_iniciais().begin() + j);
			}
		}
	}
	for (auto it = candidatos_genero.begin(); it != candidatos_genero.end(); it++) {
		if ((*it).second->getNome() == nome) {
			candidatos_genero.erase(it);
			return true;
		}


	}


		throw CandidatoInexistente(nome);
	return false;
}

void Castings::eliminaJurado(string nome)
{

	for (size_t j = 0; j < sessoes.size(); j++) {
		if (sessoes.at(j).juradoPresente(nome))
			throw JuradoPresente(nome);//Nao e possivel eliminar um jurado quando ele esta presente numa sessao							
	}
	for (size_t i = 0; i < jurados.size(); i++) {
		if (jurados.at(i)->getNome() ==nome ) {
			jurados.erase(jurados.begin() + i);
		}
	}
	throw JuradoInexistente(nome);
}

void Castings::eliminaCandidatoSessao(string nome, Sessao &s1) {
	Candidato * c = nullptr;
	int  index = -1;

	for (size_t i = 0; i < candidatos.size(); i++) {
		if (candidatos.at(i)->getNome() == nome)
			c = candidatos.at(i);
	}

	if (c == nullptr)
		throw CandidatoInexistente(nome);

	for (size_t i = 0; i < sessoes.size(); i++) {
		if (s1 == sessoes.at(i))
			index = i;
	}

	if (index == -1)
		throw SessaoInexistente(s1);

	for (size_t i = 0; i < sessoes.at(index).getConcorrentes_iniciais().size(); i++) {
		if (nome == sessoes.at(index).getConcorrentes_iniciais().at(i)) {
			sessoes.at(index).getConcorrentes_iniciais().erase(sessoes.at(index).getConcorrentes_iniciais().begin() + i);
		}
	}

	for (size_t i = 0; i < sessoes.at(index).getConcorrentes_finais().size(); i++) {
		if (nome == sessoes.at(index).getConcorrentes_finais().at(i)) {
			sessoes.at(index).getConcorrentes_finais().erase(sessoes.at(index).getConcorrentes_finais().begin() + i);
			
		}
	}


}

bool comparaDataNascimento(Candidato * c1, Candidato *c2)
{
	
	if (c1->getDataNascimento() == c2->getDataNascimento()) {
		return(c1->getNome() < c2->getNome());
	}
	else (c1->getDataNascimento() < c2->getDataNascimento());
}

void Castings::ordenaCandidatosData()
{
	sort(candidatos.begin(), candidatos.end(),comparaDataNascimento);
}

void Castings::setUpCandidatos()
{
	ifstream file(ficheiroCandidatos);
	string candidato,genero;
	bool existe = false;
	vector <Candidato*>temp;
	while (getline(file, candidato))
	{
		candidatos.push_back(new Candidato(candidato));
		Candidato* aux = new Candidato(candidato);
		temp.push_back(aux);
		
	}
	sort(temp.begin(), temp.end(),comparaDataNascimento);
	for (size_t i = 0; i < temp.size(); i++) {
		genero = temp.at(i)->getGenero();
		candidatos_genero.insert(pair<string, Candidato*>(genero, temp.at(i)));
		for (size_t j = 0; j < generos.size(); j++) {
			if (generos.at(j) == genero)
				existe = true;
		}
		if (!existe)
			generos.push_back(genero);
		existe = false;
	}
}

void Castings::setUpJurados()
{
	ifstream file(ficheiroJurados);
	string  jurado;
	while (getline(file, jurado)) {
		jurados.push_back(new Jurado(jurado));
	}
}

void Castings::setUpSessoes()
{
	ifstream file(ficheiroSessoes);
	string sessao;
	Sessao aux;
	int count = 0;
	sessao.clear();
	while (getline(file, sessao)) {
		priority_queue<Candidato*>eq;
		aux = Sessao(sessao);
		for (size_t count = 0; count < Sessao(sessao).getConcorrentes_iniciais().size(); count++) {
			for (size_t i = 0; i < candidatos.size(); i++) {
				string temp = candidatos.at(i)->getNome();
				string x = aux.getConcorrentes_iniciais().at(count);
				if (candidatos.at(i)->getNome() == aux.getConcorrentes_iniciais().at(count)) {
					candidatos.at(i)->adicionarSessao(aux);
					aux.adicionarEntrevista(candidatos.at(i));
			
				}
			}
		}
		sessoes.push_back(aux);
	}
}

void Castings::setUpPontuacoes()
 {
	ifstream file(ficheiroPontuacoes);
	string pontuacao;
	while (getline(file, pontuacao)) {
		pontuacoes.push_back(Pontuacao(pontuacao));

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

void Castings::atribuirPontuacao(Sessao & s1) {
	double p1, p2, p3;
	double pontuacao_final;
	int pos = 0;
	int pont_temp = 0;
	int pos_pont = 0;
	vector<string> nomesTemp;
	vector<string> temp;
	int count = 0;
	if (sessaoExiste(s1) == -1) throw SessaoInexistente(s1);
	for (size_t i = 0; i < sessoes.size(); i++) {
		if (sessoes.at(i) == s1) {
			pos = i;
			if (sessoes.at(i).getJurados_sessao().size() != 3) {
				throw JuradosIncompleto(s1.getId());
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
		if (sessoes.at(pos).getFase() == 1)
			pontuacao_final = (p1 + p2 + p3) / 3;

		else
			pontuacao_final = (0.5*p1) + 0.5*((p1 + p2) / 2);
		cout << "Pontuacao final: " << pontuacao_final << endl;

		p.push_back(p3);
		cout << endl;
		Pontuacao P(sessoes.at(pos).getConcorrentes_iniciais().at(i), sessoes.at(pos).getIds(), sessoes.at(pos).getFase(), p);
		P.setFase(sessoes.at(pos).getFase());
		sessoes.at(pos).getPontuacoes().push_back(P);
		for (auto it : candidatos_genero) {
			if (it.second->getNome() == sessoes.at(pos).getConcorrentes_iniciais().at(i))
				it.second->getPontuacoes().push_back(P);
		}
		/*for (size_t j = 0; j < candidatos.size(); j++) {
			if (candidatos.at(j)->getNome() == sessoes.at(pos).getConcorrentes_iniciais().at(i))
				candidatos.at(j)->getPontuacoes().push_back(P);
		}*/
	}
	if (sessoes.at(pos).getFase() == 1)
	{
		Sessao s;
		string datastr, dia, mes, ano;
		Data d;
		s.setFase(2);
		s.setId(sessoes.at(pos).getId());
		s.setGenero(sessoes.at(pos).getGenero());
		cout << "Data da 2fase: (dd-mm-aaaa)" << endl;
		cin.ignore(1000, '\n');
		getline(cin, datastr);
		istringstream dataS(datastr);
		getline(dataS, dia, '-');
		int diaI = stoi(dia);
		d.setDia(diaI);
		getline(dataS, mes, '-');
		int mesI = stoi(mes);
		d.setMes(mesI);
		getline(dataS, ano);
		int anoI = stoi(ano);
		d.setAno(anoI);
		while (d < sessoes.at(pos).getData()|| d==sessoes.at(pos).getData())
		{
			cout << "Data invalida.Insira outra" << endl;
			getline(cin, datastr);
			istringstream dataS(datastr);
			getline(dataS, dia, '-');
			diaI = stoi(dia);
			d.setDia(diaI);
			getline(dataS, mes, '-');
			mesI = stoi(mes);
			d.setMes(mesI);
			getline(dataS, ano);
			anoI = stoi(ano);
			d.setAno(anoI);
		}
		if (sessoes.at(pos).getConcorrentes_iniciais().size() < 5) {
			s.setConcorrentesIniciais(sessoes.at(pos).getConcorrentes_iniciais());
			s.setConcorrentes_finais(sessoes.at(pos).getConcorrentes_iniciais());
			sessoes.push_back(s);
		}
		else {
			while (count < 5) {
				for (size_t i = count; i < sessoes.at(pos).getConcorrentes_iniciais().size(); i++) {

					if (pont_temp < sessoes.at(pos).getPontuacoes().at(i).getClassificacao()) {
						pont_temp = sessoes.at(pos).getPontuacoes().at(i).getClassificacao();
						pos_pont = i;
					}
					nomesTemp.push_back(sessoes.at(pos).getConcorrentes_iniciais().at(pos_pont));
					count++;
				}
			}
			s.setConcorrentesIniciais(nomesTemp);
			s.setConcorrentes_finais(nomesTemp);
		}
		s.setData(d);
		int numMax = 5;
		s.setNumMaxCandidatos(numMax);
		string nome;
		vector<string>jurados;
		while (jurados.size() < 3) {
			cout << "Nome jurado:";
			getline(cin, nome);
			while (juradoExiste(nome) == -1) {
				cout << "Jurado inexistente." << endl;
				cout << "Nome do jurado: ";
				getline(cin, nome);
			}
			jurados.push_back(nome);

		}
		s.setJurados(jurados);
		s.setResponsavel(jurados.at(0));
		sessoes.erase(sessoes.begin() + pos);
		sessoes.erase(sessoes.begin()+sessoes.size()-1);
		sessoes.push_back(s);
	
	}
	else {
		for (size_t i = 0; i < sessoes.at(pos).getPontuacoes().size(); i++) {
			if (sessoes.at(pos).getPontuacoes().at(i).getClassificacao() > pont_temp) {
				pont_temp = sessoes.at(pos).getPontuacoes().at(i).getClassificacao();
				pos_pont = i;
			}
		}
		cout << "VENCEDOR: " << sessoes.at(pos).getConcorrentes_iniciais().at(pos_pont) << endl;
		vencedores.push_back(sessoes.at(pos).getConcorrentes_iniciais().at(pos_pont));
		//cout << "PONTUACAO: " << pont_temp << endl;
		sessoes.erase(sessoes.begin() + pos); // Quando se atribui a pontuacao a sessao é automaticamente eliminada
	}
	
}
void Castings::eliminaJuradoSessao(string nome, Sessao & s1)
{
	int index = -1;
	int pos = 0;
	pos = juradoExiste(nome) - 1;
	if (juradoExiste(nome) == -1) {
		throw JuradoInexistente(nome);
	}
	for (size_t i = 0; i < sessoes.size(); i++) {
		if (s1 == sessoes.at(i))
			index = i;
	}

	if (index == -1)
		throw SessaoInexistente(s1);

	for (size_t i = 0; i < sessoes.at(index).getJurados_sessao().size(); i++) {
		if (nome == sessoes.at(index).getJurados_sessao().at(i)) {
			sessoes.at(index).getJurados_sessao().erase(sessoes.at(index).getJurados_sessao().begin() + i);
			return;
		}
	}

}

void Castings::adicionaSessao(Sessao s1)
{
	sessoes.push_back(s1);
}
void Castings::eliminarSessao()
{
	Sessao s1;
	string datastr, dia, mes, ano, genero;
	Data d;
	cout << "Genero: ";
	cin >> genero;
	s1.setGenero(genero);
	cout << "Data  (dd-mm-aaaa)" << endl;
	cin.ignore(1000, '\n');
	getline(cin, datastr);
	istringstream dataS(datastr);
	getline(dataS, dia, '-');
	int diaI = stoi(dia);
	d.setDia(diaI);
	getline(dataS, mes, '-');
	int mesI = stoi(mes);
	d.setMes(mesI);
	getline(dataS, ano);
	int anoI = stoi(ano);
	d.setAno(anoI);
	s1.setData(d);
	for (size_t i = 0; i < sessoes.size(); i++) {
		if (sessoes.at(i).getData() == d && sessoes.at(i).getGenero() == genero)
		{
			sessoes.erase(sessoes.begin()+i);
			return;
		}
	}
	throw SessaoInexistente(s1);
}

void Castings::informacao_map()
{
	for (auto it : candidatos_genero) 
		cout << it.first << " " << it.second->getNome() << " " << it.second->getDataNascimento() << endl;
}

void Castings::informacao_genero(string genero)
{
	for (auto it : candidatos_genero) {
		if (it.first == genero)
			cout << it.second<< endl;
	}
}

vector<string> Castings::getGeneros()
{
	return generos;
}

void Castings::adicionarGenero(string genero)
{
	for (size_t i = 0; i < generos.size(); i++) {
		if (generos.at(i) == genero)
			return;
	}
	generos.push_back(genero);
}

void Castings::informacao_genero_queue(string genero)
{
	priority_queue<Candidato*>aux;
	for (size_t i = 0; i < sessoes.size(); i++) {
		if (sessoes.at(i).getGenero() == genero) {
			aux = sessoes.at(i).getEntrevistas();
			cout << sessoes.at(i).getFase() << endl;
			cout << sessoes.at(i).getData() << endl;
			while (!aux.empty()) {
				cout << aux.top() << endl;
				aux.pop();
			}

		}
	}
}

void Castings::alterarMorada(string nome, string morada)
{
	int op;
	for (auto it : candidatos_genero)
	{
		if (it.second->getNome() == nome) {
			cout << "Morada atual : " << it.second->getMorada() << endl;
			cout << "Pretende alterar ? SIM[0] NAO[1]" << endl;
			cin >> op;
			if (op == 0) {
				it.second->setMorada(morada);
			}
			return;
		}

	}
	throw CandidatoInexistente(nome);
}

void Castings::alterarGenero(string nome, string genero)
{
	int op;
	for (auto it : candidatos_genero)
	{
		if (it.second->getNome() == nome) {
			
			
			cout << "Genero atual : " << it.second->getGenero() << endl;
			cout << "Pretende alterar ? SIM[0] NAO[1]" << endl;
			cin >> op;
			if (op == 0) {
				it.second->setGenero(genero);
			}
			return;
		}

	}
	throw CandidatoInexistente(nome);
}

void Castings::alterarDataNascimento(string nome, Data data)
{
	int op;
	for (auto it : candidatos_genero)
	{
		if (it.second->getNome() == nome) {
		
			cout << "Data de nascimento atual : " << it.second->getDataNascimento() << endl;
			cout << "Pretende alterar ? SIM[0] NAO[1]" << endl;
			cin >> op;
			if (op == 0) {
				it.second->setDataNascimento(data);
			}
			return;
		}
	}
	throw CandidatoInexistente(nome);
}

void Castings::sort_map()
{
	vector<Candidato*>temp;
	for (auto it : candidatos_genero) {
		temp.push_back(it.second);
	}
	candidatos_genero.erase(candidatos_genero.begin(), candidatos_genero.end());
	sort(temp.begin(), temp.end(), comparaDataNascimento);
	for (size_t i = 0; i < temp.size(); i++) {
		candidatos_genero.insert(pair <string, Candidato*>(temp.at(i)->getGenero(), temp.at(i)));
	}
}




unordered_set<Candidato*,hstr,eqstr> Castings::getIndisponiveis() const {
	return indisponiveis;
}

void Castings::adicionarIndisponivel(Candidato * c1) {
	indisponiveis.insert(c1);
}

Data Castings::obter_data_atual()
{
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	data_atual.setDia(now->tm_mday);	data_atual.setMes(now->tm_mon + 1);	data_atual.setAno(now->tm_year + 1900);	return data_atual;}

void Castings::mostrar_data_atual()
{
	cout << data_atual << endl;
}

Pontuacao::Pontuacao()
{
}

// Classe Pontuacao
Pontuacao::Pontuacao(string ficheiroPontuacao) {
	istringstream pontuacaoStream(ficheiroPontuacao);
	string id, fase, nome, p1, p2, p3, pontuacoesS;
	getline(pontuacaoStream, id, ';');
	pontuacaoStream >> id;
	pontuacaoStream.ignore(1000, ';');

	pontuacaoStream >> fase;
	pontuacaoStream.ignore(1000, ';');

	getline(pontuacaoStream, nome, ';');
	getline(pontuacaoStream, pontuacoesS);
	istringstream pontuacoesStream(pontuacoesS);
	while (getline(pontuacoesStream, p1, ','))
	{
		int p = stoi(p1);
		classificacoes.push_back(p);
	}

}



Pontuacao::Pontuacao(string nomeCandidato, int id_sessao, int fase, vector<int> classificacoes)
{
	this->nomeCandidato = nomeCandidato;
	this->id_sessao = id_sessao;
	this->fase = fase;
	this->classificacoes = classificacoes;
}

void Pontuacao::setFase(int fase)
{
	this->fase = fase;
}

void Pontuacao::setNome(string nome)
{
	this->nomeCandidato = nome;
}

void Pontuacao::setId(int id)
{
	this->id_sessao = id;
}

void Pontuacao::setClassificacoes(vector<int> classificacoes)
{
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

vector<int> Pontuacao::getClassificacoes()
{
	return classificacoes;
}

double Pontuacao::getClassificacao() 
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
				if (this->mes == d1.mes && this->dia < d1.dia) return true;
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

	// TODO: inserir instrucao de retorno aqui
}

ostream & operator<<(ostream & os, const Candidato * c1)
{
	os << c1->getNome() << " ; " << c1->getMorada() << " ; " << c1->getGenero() << " ; " << c1->getDataNascimento() << endl;
	return os;
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

bool comparaDataSessao(Sessao & s1, Sessao & s2)
{
	return (s2.getData() <  s1.getData());
}







