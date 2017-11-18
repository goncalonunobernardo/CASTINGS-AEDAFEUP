
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "menus.h"
#include "castings.h"
#include "exceptions.h"

using namespace std;

Castings casting;

void Menu_Principal() {
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

int opcao = -1;	

	cout << "=============================================================================================================\n\n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << " 1) Adicionar...\n";
	cout << " 2) Remover...\n";
	cout << " 3) Alterar...\n";
	cout << " 4) Informacoes.\n";
	cout << " 5) Gravar Ficheiro\n";
	cout << " 6) Exibir classificacoes \n";
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
			//Menu_Alterar();
			break;
		case 4:
			Menu_Informacoes();
			break;
		case 5:
			Menu_Gravar_Ficheiro();
			break;
		case 6:
			//Menu_MostrarResultados();
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
	Candidato candidato;
	Jurado jurado;
	Sessao s1;

	opcao = -1;
	
	cout << "=============================================================\n";
	cout << "Indique o elemento que pretende adicionar ao programa: \n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << "1) Candidato ao CASTINGTORIUM 2000\n";
	cout << "2) Candidato a Sessao\n";
	cout << "3) Jurado ao CASTINGTORIUM 2000\n";
	cout << "4) Jurado a Sessao\n";
	cout << "5) Classificacoes\n";
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
			criar_Candidato(candidato);
			try {
				casting.adicionaCandidato(&candidato);
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
			cout << "Escolha uma opção (1/2)";
			cout << "1 - Criar um novo candidato e inscrevê-lo numa sessão \n";
			cout << "2 - Inscrever um candidato já existente numa sessão \n";
			char op;
			cin >> op;
			switch (op) {
			case 1:
				criar_Candidato(candidato);
				break;
			default: {
				cout << "Não inseriu uma resposta valida.\n"; Menu_Adicionar(); break;
			}
			}
			try {
				casting.adicionaCandidatoSessao(&candidato, s1);
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
			cout << "=============================================================\n";
			cout << "Candidato adicionado a Sessao! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 3:
			casting.adicionaJurado(&jurado);
			cout << "=============================================================\n";
			cout << "Jurado adicionado ao CASTINGTORIUM 200! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 4:
			try {
				casting.adicionaJuradoSessao(&jurado, s1);
			}
			catch (JuradoInexistente jurado){
				jurado.handler();
				Menu_Adicionar();
				break;
			}
			catch (SessaoInexistente sessao) {
				sessao.handler();
				Menu_Adicionar();
				break;
			}
			catch (JuradoRepetido jurado) {
				jurado.handler();
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
		default:
			InvalidInputMenu();
			break;
		}
		return;
	}
}

void Menu_Remover() {
	int opcao;
	Candidato candidato;
	Jurado jurado;
	Sessao s1;

	opcao = -1;

	cout << "=============================================================\n";
	cout << "Indique o elemento que pretende remover no programa: \n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << "1) Candidato ao Castingtorium 2000\n";
	cout << "2) Candidato a Sessao";
	cout << "3) Jurado ao Castingtorium 2000\n";
	cout << "4) Jurado a Sessao";
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
				casting.eliminaCandidato(&candidato);
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
				casting.eliminaCandidatoSessao(&candidato, s1);
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
			//FUNCAO PARA REMOVER JURADO DO CASTINGTORIUM2000

			cout << "=============================================================\n";
			cout << "Jurado removido da CASTINGTORIUM2000... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 4:
			//FUNCAO PARA REMOVER JURADO DA SESS�O

			cout << "=============================================================\n";
			cout << "Jurado removido da Sess�o... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
		default:
			InvalidInputMenu();
			break;
		}
		return;
	}
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
	opcao = -1;

	cout << "=============================================================\n";
	cout << "Indique o elemento que pretende visualizar no programa: \n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << "1) Candidatos";
	cout << "2) Jurados";
	cout << "3) Tipos de Sessao";
	cout << "4) Ficheiro de Candidatos";
	cout << "5) Ficheiro de Jurados";
	cout << "6) Ficheiro de Sessoes";
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
			//FUNCAO QUE LE CANDIDATOS E INFO BASICAS DELES + TIPO DE SESSAO
			break;
		case 2:
			//FUNCAO QUE LE JURADOS E INFO BASICAS
			break;
		case 3:
			Menu_Artes();
			break;
		case 4:
			txt_candidatos();
			break;
		case 5:
			txt_jurados();
			break;
		case 6:
			txt_sessoes();
			break;
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
	cout << "1) Danca";
	cout << "2) Teatro";
	cout << "3) Musica";
	cout << "4) Escultura";
	cout << "5) Diversos...";
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


//FUNCOES SAVE DE FICHEIROS
void Menu_Gravar_Ficheiro() {
	int opcao;
	opcao = -1;
	cout << "========================================================================================================";
	cout << "\nGRAVAR FICHEIROS \n";
	cout << "Insira a sua opcao (1,2,...)\n";
	cout << "1) Gravar ficheiro de candidatos\n";
	cout << "2) Gravar ficheiro de jurados\n";
	cout << "3) Gravar ficheiro de sessoes";
	cout << "0) Menu Principal\n";
	cout << "========================================================================================================\n\n";

	while (!cin.fail()) {
		cin >> opcao;
		switch (opcao) {
            case 0:

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

	for (unsigned int i = 0; i < casting.getCandidatos().size(); i++)
	{
		Ficheiro_Candidato << casting.getCandidatos().at(i)->getNome() << " ; " << casting.getCandidatos().at(i)->getMorada() << " ; " << casting.getCandidatos().at(i)->getGenero() << " ; " << casting.getCandidatos().at(i)->getDataNascimento().getDia() << "-" << casting.getCandidatos().at(i)->getDataNascimento().getMes() << "-" << casting.getCandidatos().at(i)->getDataNascimento().getAno() << endl;
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
	for (unsigned int i = 0; i < casting.getJurados().size(); i++)
	{
		Ficheiro_Jurado << casting.getJurados().at(i)->getNome() << " ; " << casting.getJurados().at(i)->getMorada() << " ; " << casting.getJurados().at(i)->getGenero() << " ; " << casting.getJurados().at(i)->getTelemovel() << endl;
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
	for (unsigned int i = 0; i < casting.getSessao().size(); i++)
	{
		//GETFASE???Ficheiro_Sessoes << casting.getSessao().at(i).getId() << " ; " << casting.getSessao().at(i).g() << " ; " << casting.getJurados().at(i)->getGenero() << " ; " << casting.getJurados().at(i)->getTelemovel() << endl;
	}
	Ficheiro_Sessoes.close();
	cout << "\n\nFicheiro gravado! Retornando ao Menu Principal...\n";
	cout << "=============================================================\n\n";
	Menu_Principal();
}

void criar_Candidato(Candidato & novo) {
	string nome, morada, genero, datastr;
	Data d;
	string dia, mes, ano;
	cout << "=============================================================\n";
	cout << "Insira o nome. \n";
	getline(cin, nome);
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
	novo.setDataNascimento(d);
}

void txt_candidatos() {
	int input = -1;
	for (unsigned int i = 0; i < casting.getCandidatos().size(); i++)
	{
		cout << casting.getCandidatos().at(i)->getNome() << " ; " << casting.getCandidatos().at(i)->getMorada() << " ; " << casting.getCandidatos().at(i)->getGenero() << " ; " << casting.getCandidatos().at(i)->getDataNascimento().getDia() << "-" << casting.getCandidatos().at(i)->getDataNascimento().getMes() << "-" << casting.getCandidatos().at(i)->getDataNascimento().getAno() << endl;
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
	for (unsigned int i = 0; i < casting.getJurados().size(); i++)
	{
		cout << casting.getJurados().at(i)->getNome() << " ; " << casting.getJurados().at(i)->getMorada() << " ; " << casting.getJurados().at(i)->getGenero() << " ; " << casting.getJurados().at(i)->getTelemovel() << endl;
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
	for (unsigned int i = 0; i < casting.getSessao().size(); i++)
	{
		//GETFASE?imcomplete?? cout << casting.getSessao().at(i).getId() << " ; " << casting.getSessao().at(i).g() << " ; " << casting.getJurados().at(i)->getGenero() << " ; " << casting.getJurados().at(i)->getTelemovel() << endl;
	}

	cout << "\nVoltar atras? [0] SIM \t [1] MENU PRINCIPAL \n";
	cin >> input;
	if (input == 0)
		Menu_Informacoes();
	else
		Menu_Principal();

	return;
}