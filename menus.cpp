
#include "menus.h"
#include "exceptions.h"
#include <ctime>

Castings C;
int main() {

	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< endl;
	C.setFicheiroCandidatos("candidatos.txt");
	C.setFicheiroJurados("jurados.txt");
	C.setFicheiroPontuacoes("pontuacoes.txt");
	C.setFicheiroSessoes("sessoes.txt");
	C.setUpCandidatos();
	C.setUpJurados();
	C.setUpSessoes();
	C.setUpPontuacoes();

	//Funcao para tratar do Menu Principal
	//C.informacao_map();
	/*string genero;
	cin >> genero;
	cout << endl;
	C.informacao_genero(genero);*/
	Menu();
	system("PAUSE");
	return 0;
}
void Menu() {
	cout << "=============================================================================================================\n";
	cout << "    ____  ________  ___   _    _______   ______  ____ \n";
	cout << "   / __ )/ ____/  |/  /  | |  / /  _/ | / / __ \\/ __ \\    ____  ____  \n";
	cout << "  / __  / __/ / /|_/ /   | | / // //  |/ / / / / / / /   / __ `/ __ \\ \n";
	cout << " / /_/ / /___/ /  / /    | |/ // // /|  / /_/ / /_/ /   / /_/ / /_/ / \n";
	cout << "/_____/_____/_/  /_/     |___/___/_/ |_/_____/\_____/    \\__,_/\\____/ \n";
	cout << " _ _  ___    __________   ___   _                               __  _\n";
	cout << "( | )/   |  / ____ / __ \\/   | ()_____    __________ __  ____ _/ /_(_)   _____\n";
	cout << "|/| / /| | / __/  / / / / /| | |/_ __  / / ___/ ___/ _ \\/ __ `/ __/ / | / / _ \\\n";
	cout << "   / ___ |/ /___ / /_/ / ___ |  ___/  / / /__/ / /  __// /_/ / / / /| |/ /  __/\n";
	cout << "  /_/  |_/_____//_____/_/  |_| /____ /  \\___/_/  \\___/ \\__,_/\\__/_/ |___/\\___/ \n\n";
	cout << "   _________   ________________   __________________  ____  ______  ____  ___   ___  ____  ____  ___ _ _ \n";
	cout << "  / ____/   | / ___/_  __/  _/ | / / ____/_  __/ __ \\/ __ \\/  _/ / / /  |/  /  |__ \\/ __ \\/ __ \\/ __ ( | )\n";
	cout << " / /   / /| | \\__ \\ / /  /  /  |/ / / __  / / / / / / /_/ // // / / / /|_/ /   __/ / / / / / / / / / //|/    (TM)  \n";
	cout << "/ /___/ ___ |___/ // / _/ /  /|  / /_/ / / / / /_/ / _, _// // /_/ / /  / /   / __/ /_/ / /_/ / /_/ / \n";
	cout << "\\____/_/  |_/____//_/ /___/_/ |_/\\__ _/ /_/  \\____/_/ |_/___/\\____/_/  /_/   /____|____/\\____/\\____/  \n\n";
	cout << "=============================================================================================================\n\n";
	//Funcao para tratar do Menu Principal
	Menu_Principal();
	system("PAUSE");
	return;
}

void Menu_Principal() {
	int opcao = -1;

	cout << "=============================================================================================================\n\n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << " 1) Adicionar...\n";
	cout << " 2) Remover...\n";
	cout << " 3) Informacoes.\n";
	cout << " 4) Gravar Ficheiro\n";
	cout << " 5) Exibir vencedores \n";
	cout << " 0) Terminar programa.\n";
	cout << "=============================================================================================================\n";
	while (!cin.fail())
	{
		cin >> opcao;
		switch (opcao) {
		case 0:
			void Termina_Programa();
			break;
			Termina_Programa();
		case 1:
			Menu_Adicionar();
			break;
		case 2:
			Menu_Remover();
			break;
		case 3:
			Menu_Informacoes();
			break;
		case 4:
			Menu_Gravar_Ficheiro();
			break;
		case 5:
			mostrarVencedores();
			Menu_Principal();
			break;
		default:
			InvalidInputMenu();
			break;
		}
		return;
	}
}

void Menu_Adicionar() {
	int opcao;
	Candidato novo;
	Jurado jurado;
	Sessao s1;
	string genero;

	opcao = -1;

	cout << "=============================================================\n";
	cout << "Indique o elemento que pretende adicionar ao programa: \n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << "1) Candidato ao CASTINGTORIUM 2000\n";
	cout << "2) Candidato a Sessao\n";
	cout << "3) Jurado ao CASTINGTORIUM 2000\n";
	cout << "4) Jurado a Sessao\n";
	cout << "5) Classificacoes\n";
	cout << "6) Adicionar sessao\n";
	cout << "0) Menu Principal\n";
	cout << "=============================================================\n";
	while (!cin.fail())
	{
		cin >> opcao;
		switch (opcao) {
		case 0:
			Menu_Principal();
			break;
		case 1:
			try {
				novo = criar_Candidato();
			}
			catch (CandidatoRepetido c1) {
				c1.handler();
				Menu_Adicionar();
				break;
			}
			try {
				C.adicionaCandidato(&novo);
			}
			catch (CandidatoRepetido c1) {
				c1.handler();
				Menu_Adicionar();
				break;
			}
			cout << "=============================================================\n";
			cout << "Candidato adicionado ao CASTINGTORIUM 200! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 2:
			novo.setNome(nome());
			cout << "Genero da sessao: ";
			cin >> genero;
			if (genero != "Escultura" && genero != "Danca" && genero != "Teatro" && genero != "Musica" && genero != "Malabarismo" && genero != "Cinema" && genero != "Speedrun" && genero != "Comedia")
			{
				cout << "Tente novamente!... Retornando ao Menu Principal\n";
				Menu_Principal();
			}
			cout << endl;
			s1.setGenero(genero);
			s1.setData(dataSessao());
			try {
				C.adicionaCandidatoSessao(&novo, s1);
			}
			catch (CandidatoInexistente candidato) {
				candidato.handler();
				Menu_Adicionar();
				break;
			}
			catch (CandidatoRepetido candidato) {
				candidato.handler();
				Menu_Adicionar();
				break;
			}
			catch (SessaoInexistente sessao) {
				sessao.handler();
				Menu_Adicionar();
				break;
			}

			s1.getEntrevistas().push(&novo);

			cout << "=============================================================\n";
			cout << "Candidato adicionado a Sessao! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 3:
			try {
				jurado = criar_Jurado();
			}
			catch (JuradoRepetido &j1) {
				j1.handler();
				Menu_Adicionar();
				break;
			}
			C.adicionaJurado(&jurado);
			cout << "=============================================================\n";
			cout << "Jurado adicionado ao CASTINGTORIUM 200! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 4:
		{
			Jurado jurado;
			Sessao s1;
			try {
				cout << "Genero da sessao: ";
				cin >> genero;
				cout << endl;
				s1.setGenero(genero);
				s1.setData(dataSessao());
				C.adicionaJuradoSessao(nome(), s1);
			}
			catch (JuradoInexistente jurado) {
				jurado.handler();
				Menu_Adicionar();
				break;
			}
			catch (JuradoRepetido jurado) {
				jurado.handler();
				Menu_Adicionar();
				break;
			}
			catch (SessaoInexistente sessao) {
				sessao.handler();
				Menu_Adicionar();
				break;
			}
			catch (JuradosCompleto completo) {
				completo.handler();
				Menu_Principal();
				break;
			}
			cout << "=============================================================\n";
			cout << "Jurado adicionado a Sessao! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		}
		case 5:
			try {
				cout << "Genero da sessao: ";
				cin >> genero;
				cout << endl;
				s1.setGenero(genero);
				s1.setData(dataSessao());
				C.atribuirPontuacao(s1);
			}
			catch (JuradosIncompleto jurado) {
				jurado.handler();
				Menu_Adicionar();
				break;
			}
			catch (SessaoInexistente sessao) {
				sessao.handler();
				Menu_Adicionar();
				break;
			}
			Menu_Adicionar();
			break;
		case 6:
			try {
				s1 = criarSessao();
				C.adicionaSessao(s1);
				Menu_Adicionar();

			}
			catch (SessaoRepetida sessao) {
				sessao.handler();
				Menu_Adicionar();
				break;
			}
			cout << "=============================================================\n";
			cout << "Sessao adicionada! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();

		default:
			InvalidInputMenu();
			break;
		}
		return;
	}
}

void Menu_Remover() {
	int opcao;
	string sessao;
	Candidato candidato;
	Sessao s1;
	Data d1;

	opcao = -1;

	cout << "=============================================================\n";
	cout << "Indique o elemento que pretende remover no programa: \n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << "1) Candidato do Castingtorium 2000\n";
	cout << "2) Candidato da Sessao\n";
	cout << "3) Jurado do Castingtorium 2000\n";
	cout << "4) Jurado da Sessao\n";
	cout << "5) Sessao\n";
	cout << "0) Menu Principal\n";
	cout << "=============================================================\n";
	while (!cin.fail())
	{
		cin >> opcao;
		switch (opcao) {
		case 0:
			Menu_Principal();
		case 1:
			try {

				C.eliminaCandidato(nome());
			}
			catch (CandidatoInexistente candidato) {
				candidato.handler();
				Menu_Remover();
				break;
			}
			cout << "=============================================================\n";
			cout << "Candidato removido do CASTINGTORIUM2000... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 2:
			try {
				string genero;
				cout << "Genero da sessao: ";
				cin >> genero;
				cout << endl;
				s1.setGenero(genero);
				s1.setData(dataSessao());
				C.eliminaCandidatoSessao(nome(), s1);
			}
			catch (CandidatoInexistente candidato) {
				candidato.handler();
				Menu_Remover();
				break;
			}
			catch (SessaoInexistente sessao) {
				sessao.handler();
				Menu_Remover();
				break;
			}

			cout << "=============================================================\n";
			cout << "Candidato removido da Sessao... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 3:
			try {
				C.eliminaJurado(nome());
			}
			catch (JuradoPresente jurado) {
				jurado.handler();
				Menu_Remover();

			}
			cout << "=============================================================\n";
			cout << "Jurado removido da CASTINGTORIUM2000... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 4:
			try {
				string genero;
				cout << "Genero da sessao: ";
				cin >> genero;
				cout << endl;
				s1.setGenero(genero);
				s1.setData(dataSessao());
				C.eliminaJuradoSessao(nome(), s1);
			}
			catch (JuradoInexistente jurado) {
				jurado.handler();
				Menu_Remover();

			}
			catch (SessaoInexistente s1) {
				s1.handler();
				Menu_Remover();
			}

			cout << "=============================================================\n";
			cout << "Jurado removido da Sessao... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();

		case 5:
			try {
				C.eliminarSessao();
			}
			catch (SessaoInexistente s1)
			{
				s1.handler();
				Menu_Remover();
			}
			cout << "=============================================================\n";
			cout << "Sessao removida... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
		default:
			InvalidInputMenu();
			break;
		}
	}
	return;
}

void InvalidInputMenu() {
	if (cin.fail())
	{
		cout << "\nIntroduziu uma resposta invalida. Por favor, tente de novo. \n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		Menu_Principal();
	}
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		Menu_Principal();
	}
}
void Termina_Programa() {
	cout << "=============================================================\n";
	cout << "Terminando programa, aguarde...\n";
	cout << "\nObrigado pela sua colaboracao, volte em breve!\n";
	cout << "=============================================================";
	cout << "\n\n";
	system("PAUSE");
	exit(0);
}

void Menu_Informacoes() {
	int opcao;
	string genero;
	opcao = -1;
	int opcaoCandidato = -1;
	cout << "=============================================================\n";
	cout << "Indique o elemento que pretende visualizar no programa: \n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << "1) Candidatos\n";
	cout << "2) Jurados\n";
	cout << "3) Tipos de Sessao\n";
	cout << "4) Sessoes\n";
	cout << "5) Entrevistas\n";
	cout << "0) Menu Principal\n";
	cout << "=============================================================\n";
	while (!cin.fail())
	{
		cin >> opcao;
		switch (opcao) {
		case 0:
			Menu_Principal();
			break;
		case 1:
			cout << "1) Por genero\n";
			cout << "2) Todos\n";
			cout << "0) Menu Informacoes\n";
			cin >> opcaoCandidato;
			switch (opcaoCandidato) {
			case 1:
				generoX();
				Menu_Informacoes();
				break;
			case 2:
				txt_candidatos();
				break;
			case 0: 
				Menu_Informacoes();
				break;
			}
			break;
		case 2:
			txt_jurados();
			//FUNCAO QUE LE JURADOS E INFO BASICAS
			break;
		case 3:
			//Menu_Artes();
			//sort(C.getGeneros().begin(),C.getGeneros().end());
				for (size_t i = 0; i < C.getGeneros().size(); i++) {
				cout << C.getGeneros().at(i) << "    ";
			}
			break;
		case 4:
			txt_sessoes();
			break;
		case 5:
			cout << "Insira o género da arte cujas entrevistas vão ocorrer: ";
			cin >> genero;
			getCandidatosparaEntrevistas(genero);
		default:
			InvalidInputMenu();
			break;
		}
		return;
	}
}
void Menu_Artes() {
	int opcao;
	opcao = -1;

	cout << "=============================================================\n";
	cout << "Artes disponiveis para Sessoes no CASTINGTORIUM 2000: \n";
	cout << "1) Danca\n";
	cout << "2) Teatro\n";
	cout << "3) Musica\n";
	cout << "4) Escultura\n";
	cout << "5) Diversos...\n";
	cout << "0) Menu Principal\n";
	cout << "=============================================================\n";
	while (!cin.fail())
	{
		cin >> opcao;
		switch (opcao) {
		case 0:
			Menu_Principal();
			break;
		case 5:
			cout << "\t5.1)Malabarismo\n";
			cout << "\t5.2)Cinema\n";
			cout << "\t5.3)Speedrun\n";
			cout << "\t5.4)Comedia\n";
			cout << "0) Voltar Atras\n";
			switch (opcao) {
			case 0:
				Menu_Artes();
				break;
			default:
				InvalidInputMenu();
				break;
			}
		default:
			InvalidInputMenu();
			break;
		}
		return;
	}
}

void generoX() {
	string genero;
	cout << "Insira genero" << endl;
	cin >> genero;
	int op = -1;
	bool existe = false;
	for (size_t i = 0; i < C.getGeneros().size(); i++) {
		if (genero == C.getGeneros().at(i))
			existe = true;
	}
	if (existe) {
		C.informacao_genero(genero);
	}
	else {

		cout << "Genero inexistente.Pretende adicionar?\n";
		cout << "SIM[0] NÃO[1]\n";
		cin >> op;
		if (op == 0) {
			C.adicionarGenero(genero);
		}
	}
}
//FUNCOES SAVE DE FICHEIROS
void Menu_Gravar_Ficheiro() {
	int opcao;
	opcao = -1;
	cout << "========================================================================================================";
	cout << "\nGRAVAR FICHEIROS \n";
	cout << "Insira a sua opcao (1,2,...)\n";
	cout << "1) Gravar ficheiro de candidatos\n";
	cout << "2) Gravar ficheiro de jurados\n";
	cout << "3) Gravar ficheiro de sessoes\n";
	cout << "0) Menu Principal\n";
	cout << "========================================================================================================\n\n";

	while (!cin.fail()) {
		cin >> opcao;
		switch (opcao) {
		case 0:
			Menu_Principal();
			break;
		case 1:
			Grava_Ficheiro_Candidatos();
			break;
		case 2:
			Grava_Ficheiro_Jurados();
			break;
		case 3:
			Grava_Ficheiro_Sessoes();
			break;
		default:
			InvalidInputMenu();
			break;
		}
	}
}


void Grava_Ficheiro_Candidatos() {
	string ficheiro_candidatos;
	cout << "=============================================================\n";
	cout << "Insira o nome do ficheiro de candidatos que pretende gravar: \n";
	cin >> ficheiro_candidatos;

	ofstream Ficheiro_Candidato;

	Ficheiro_Candidato.open(ficheiro_candidatos);

	for (unsigned int i = 0; i < C.getCandidatos().size(); i++)
	{
		Ficheiro_Candidato << C.getCandidatos().at(i)->getNome() << " ; " << C.getCandidatos().at(i)->getMorada() << " ; " << C.getCandidatos().at(i)->getGenero() << " ; " << C.getCandidatos().at(i)->getDataNascimento().getDia() << "-" << C.getCandidatos().at(i)->getDataNascimento().getMes() << "-" << C.getCandidatos().at(i)->getDataNascimento().getAno() << endl;
	}
	Ficheiro_Candidato.close();
	cout << "\n\nFicheiro gravado! Retornando ao Menu Principal...\n";
	cout << "=============================================================\n\n";
	Menu_Principal();
}
void Grava_Ficheiro_Jurados() {
	Jurado jurados;
	string ficheiro_jurados;
	cout << "=============================================================\n";
	cout << "Insira o nome do ficheiro de jurados que pretende gravar: \n";
	cin >> ficheiro_jurados;

	ofstream Ficheiro_Jurado;

	Ficheiro_Jurado.open(ficheiro_jurados);
	for (unsigned int i = 0; i < C.getJurados().size(); i++)
	{
		Ficheiro_Jurado << C.getJurados().at(i)->getNome() << " ; " << C.getJurados().at(i)->getMorada() << " ; " << C.getJurados().at(i)->getGenero() << " ; " << C.getJurados().at(i)->getTelemovel() << endl;
	}
	Ficheiro_Jurado.close();
	cout << "\n\nFicheiro gravado! Retornando ao Menu Principal...\n";
	cout << "=============================================================\n\n";
	Menu_Principal();
}
void Grava_Ficheiro_Sessoes() {
	Sessao sessoes;
	string ficheiro_sessoes;
	cout << "=============================================================\n";
	cout << "Insira o nome do ficheiro de jurados que pretende gravar: \n";
	cin >> ficheiro_sessoes;

	ofstream Ficheiro_Sessoes;

	Ficheiro_Sessoes.open(ficheiro_sessoes);
	for (unsigned int i = 0; i < C.getSessao().size(); i++)
	{
		Ficheiro_Sessoes << C.getSessao().at(i).getId() << " ; " << C.getSessao().at(i).getFase() << " ; " << C.getSessao().at(i).getGenero() << " ; " << C.getSessao().at(i).getNumVagas() << " ; ";
		int sizep = C.getSessao().at(i).getConcorrentes_iniciais().size() - 1;
		for (size_t k = 0; i < C.getSessao().at(i).getConcorrentes_iniciais().size() - 1; i++) {
			Ficheiro_Sessoes << C.getSessao().at(i).getConcorrentes_iniciais().at(k) << ", ";

		}
		Ficheiro_Sessoes << C.getSessao().at(i).getConcorrentes_iniciais().at(sizep) << " ; ";
		sizep = C.getSessao().at(i).getConcorrentes_finais().size() - 1;
		for (size_t j = 0; i < C.getSessao().at(i).getConcorrentes_finais().size() - 1; i++) {
			Ficheiro_Sessoes << C.getSessao().at(i).getConcorrentes_finais().at(j) << ", ";

		}
		sizep = C.getSessao().at(i).getJurados_sessao().size() - 1;
		for (size_t l = 0; C.getSessao().at(i).getJurados_sessao().size() - 1; i++) {
			Ficheiro_Sessoes << C.getSessao().at(i).getJurados_sessao().at(l) << ",";
		}
		Ficheiro_Sessoes << C.getSessao().at(i).getJurados_sessao().at(sizep) << " ; ";
		Ficheiro_Sessoes << C.getSessao().at(i).getConcorrentes_finais().at(sizep) << " ; " << C.getSessao().at(i).getData();
		Ficheiro_Sessoes << endl;
	}
	Ficheiro_Sessoes.close();
	cout << "\n\nFicheiro gravado! Retornando ao Menu Principal...\n";
	cout << "=============================================================\n\n";
	Menu_Principal();
}

// nota: esta funçao lança excecoes ---> chamar esta funcao dentro de um try
Candidato criar_Candidato() {
	string nome, morada, genero, datastr;
	Data d;
	string dia, mes, ano;

	cout << "=============================================================\n";
	cout << "Insira o nome. \n";
	cin.ignore(1000, '\n');
	getline(cin, nome);

	for (auto it : C.getCandidatos_genero()) {
		if (it.second->getNome() == nome)throw CandidatoRepetido(nome);
	}
	/*int j = C.getCandidatos().size();
	for (size_t i = 0; i < C.getCandidatos().size(); i++) {
		string n = C.getCandidatos().at(i)->getNome();
		if (C.getCandidatos().at(i)->getNome() == nome)
			throw CandidatoRepetido(nome);
	}*/

	Candidato novo;
	novo.setNome(nome);
	cout << "Insira a morada. \n";
	getline(cin, morada);
	novo.setMorada(morada);
	cout << "Insira o genero de arte performativa em que o candidato e mais forte. \n";
	getline(cin, genero);
	novo.setGenero(genero);
	cout << "Insira a data de nascimento. (no formato dd-mm-aaaa) \n";
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
	novo.setDataNascimento(d);

	char i;
	string lixo;
	cout << "Indisponibilidade para sessões? (s/n) \n";
	cin >> i;
	getline(cin, lixo);
	
	string strdata, razao;
	Data d1, d2;

	switch (i) {
	case 's':
		cout << "Período de indisponibilidade: \n data de começo: (dd-mm-aaaa) \n";
		getline(cin, strdata);
		d1 = lerData(strdata);
		cout << "data de fim: (dd-mm-aaaa) \n";
		getline(cin, strdata);
		d2 = lerData(strdata);
		cout << "Motivo de indisponibilidade: \n";
		getline(cin, razao);
		novo.setIndisponibilidade(d1, d2, razao);
		C.adicionarIndisponivel(&novo);
		break;
		
	default:
		break;
	}

	cout << "Candidato criado. O numero de inscricao do candidato e: " << novo.getNumInscricao() << endl;
	cout << "=============================================================\n\n";

	return novo;
}

// nota: esta funçao lança excecoes ---> chamar esta funcao dentro de um try
Jurado criar_Jurado() {
	string nome, morada, genero, telemovel;

	cout << "=============================================================\n";
	cout << "Insira o nome. \n";
	cin.ignore(1000, '\n');
	getline(cin, nome);

	if (C.juradoExiste(nome) != -1)
		throw JuradoRepetido(nome);
	Jurado novo;
	novo.setNome(nome);

	cout << "Insira o numero de telemovel. \n";
	getline(cin, telemovel);
	novo.setTelemovel(telemovel);
	cout << "Insira a morada. \n";
	getline(cin, morada);
	novo.setMorada(morada);
	cout << "Insira o genero de arte performativa em que o jurado e mais forte. \n";
	getline(cin, genero);
	novo.setGenero(genero);

	cout << "Jurado criado. \n";
	cout << "=============================================================\n";

	return novo;
}
Sessao criar_Sessao() {
	Sessao s1;
	return s1;
}

void txt_candidatos() {
	int input = -1;
	for (auto it : C.getCandidatos_genero()) {

		cout << it.second->getNome() << " ; " << it.second->getMorada() << " ; " << it.second->getGenero() << " ; " << it.second->getDataNascimento() << endl;

	}
	cout << "\nVoltar atras? [0] SIM \t [1] MENU PRINCIPAL \n";
	cin >> input;
	if (input == 0)
		Menu_Informacoes();
	else
		Menu_Principal();

	return;
}

void txt_jurados() {
	int input = -1;
	for (unsigned int i = 0; i < C.getJurados().size(); i++)
	{
		cout << C.getJurados().at(i)->getNome() << " ; " << C.getJurados().at(i)->getMorada() << " ; " << C.getJurados().at(i)->getGenero() << " ; " << C.getJurados().at(i)->getTelemovel() << endl;
	}

	cout << "\nVoltar atras? [0] SIM \t [1] MENU PRINCIPAL \n";
	cin >> input;
	if (input == 0)
		Menu_Informacoes();
	else
		Menu_Principal();

	return;
}

void txt_sessoes() {
	int input = -1;
	int size = 0;
	int sizeP = 0;
	for (unsigned int i = 0; i < C.getSessao().size(); i++)
	{
		cout << C.getSessao().at(i).getId() << " ; " << C.getSessao().at(i).getFase() << " ; " << C.getSessao().at(i).getNumMaxCandidatos() << " ; " << C.getSessao().at(i).getGenero() << " ; " << C.getSessao().at(i).getNumVagas() << " ; ";
		cout << C.getSessao().at(i).getConcorrentes_iniciais() << " ; ";
		cout << C.getSessao().at(i).getJurados_sessao() << " ; ";
		cout << C.getSessao().at(i).getData();
		cout << endl;
	}
	cout << "\nVoltar atras? [0] SIM \t [1] MENU PRINCIPAL \n";
	cin >> input;
	if (input == 0)
		Menu_Informacoes();
	else
		Menu_Principal();

	return;
}

string nome() {
	string nome;
	cin.ignore(1000, '\n');
	cout << "Nome: " << endl;
	getline(cin, nome);
	return nome;
}


void getCandidatosparaEntrevistas(string genero)
{
	int input;

	for (size_t i = 0; i < C.getSessao().size(); i++)
	{
		if (C.getSessao().at(i).getGenero() == genero)
		{
			vector<Candidato*> temp_fila;
			while (!C.getSessao().at(i).getEntrevistas().empty())
			{
				temp_fila.push_back(C.getSessao().at(i).getEntrevistas().top());
				C.getSessao().at(i).getEntrevistas().pop();
			}
			cout << "===============================================================" << endl;
			cout << "# \t\t CANDIDATO \t\t DATA DE ENTREVISTA \t\t DATA DE SESSAO" << endl;

			for (size_t j = 0; j < temp_fila.size(); j++)
			{
				cout << "[" << j + 1 << "]\t\t" << temp_fila.at(j)->getNome() << "\t\t";
				for (size_t k = 0; k < temp_fila.at(j)->getSessoes().size(); k++)
				{
					cout << "[" << j + 1 << "]\t\t" << temp_fila.at(j)->getNome() << "\t\t";
					cout << temp_fila.at(j)->getSessoes().at(k).getData() << "\t\t";
					/*cout << temp_fila.at(j)->getSessoes().at(j).getData().getDia() - 1 << "-";
					cout << temp_fila.at(j).getSessoes().at(j).getData().getMes() << "-";
					cout << temp_fila.at(j).getSessoes().at(j).getData().getAno();
					cout << "\t\t";*/
					cout << temp_fila.at(j)->getSessoes().at(j).getData().getDia() << "-";
					cout << temp_fila.at(j)->getSessoes().at(j).getData().getMes() << "-";
					cout << temp_fila.at(j)->getSessoes().at(j).getData().getAno() << endl;
				}
			}

			cout << "===============================================================" << endl;

			for (size_t j = 0; j < temp_fila.size(); j++)
			{
				C.getSessao().at(i).getEntrevistas().push(temp_fila.at(j));
			}

			cout << "\nVoltar atras? [0] SIM \t [1] MENU PRINCIPAL \n";
			cin >> input;
			if (input == 0)
				Menu_Informacoes();
			else
				Menu_Principal();
		}
	}
}

Data dataSessao() {
	string datastr, dia, mes, ano;
	Data d;
	cout << "Data (dd-mm-aaaa): ";
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
	return d;
}
Sessao criarSessao() {
	Sessao s1;
	string genero, nome;
	vector<string> jurados, concorrentes_iniciais, concorrentes_finais;
	int continuar = 0;
	string responsavel;
	s1.setFase(1);
	s1.setData(dataSessao());
	cout << "Genero: ";
	cin >> genero;
	s1.setGenero(genero);
	if (C.sessaoExiste(s1) != -1) throw SessaoRepetida();
	cout << "Numero maximo de candidatos: ";
	int num;
	cin >> num;
	s1.setNumMaxCandidatos(num);
	while (continuar == 0 && concorrentes_iniciais.size() < num) {
		cout << "Nome do candidato: ";
		cin.ignore(1000, '\n');
		getline(cin, nome);
		while (C.candidatoExiste(nome) == -1) {
			cout << "Candidato inexistente. Insira um nome valido. " << endl;
			getline(cin, nome);
		}
		concorrentes_iniciais.push_back(nome);
		concorrentes_finais.push_back(nome);
		cout << "Deseja continuar? (Sim-0, Nao-1)\n";
		cin >> continuar;
	}
	s1.setConcorrentesIniciais(concorrentes_iniciais);
	s1.setConcorrentes_finais(concorrentes_finais);
	cin.ignore(1000, '\n');
	while (jurados.size() < 3) {
		cout << "Nome do jurado:";
		getline(cin, nome);
		while (C.juradoExiste(nome) == -1) {
			cout << "Jurado inexistente." << endl;
			cout << "Nome do jurado: ";
			getline(cin, nome);
		}
		jurados.push_back(nome);
	}
	s1.setJurados(jurados);
	s1.setResponsavel(jurados.at(0));
	return s1;
}
void mostrarVencedores() {
	if (C.getVencedores().size() == 0) {
		cout << "Nao ha vencedores ate ao momento" << endl;
		return;
	}
	cout << "=============================================================\n";
	cout << "						VENCEDORES\n";
	cout << "=============================================================\n";
	Menu_Principal();
	for (size_t i = 0; i < C.getVencedores().size(); i++) {

		cout << C.getVencedores().at(i) << endl;
	}
}

Data lerData(string datastr) {
	string dia, mes, ano;
	Data d;
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

	return d;
}