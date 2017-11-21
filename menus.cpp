
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "menus.h"
#include "castings.h"
#include "exceptions.h"

using namespace std;
void Menu_Principal(Castings C) {
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
			Menu_Adicionar(C);
			break;
		case 2:
			Menu_Remover(C);
			break;
		case 3:
			//Menu_Alterar();
			break;
		case 4:
			Menu_Informacoes(C);
			break;
		case 5:
			Menu_Gravar_Ficheiro(C);
			break;
		case 6:
			//Menu_MostrarResultados();
			break;
		default:
			InvalidInputMenu(C);
			break;
		}
		return;
	}
}
	
void Menu_Adicionar(Castings C) {
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
			Menu_Principal(C);
			break;
		case 1:
			try { 
				candidato=criar_Candidato(C); 
			}
			catch (CandidatoRepetido c1) {
				c1.handler();
				Menu_Adicionar(C);
				break;
			}
			try { 
				C.adicionaCandidato(&candidato); 
			}
			catch (CandidatoRepetido c1) {
				c1.handler();
				Menu_Adicionar(C);
				break;
			}
			cout << "=============================================================\n";
			cout << "Candidato adicionado ao CASTINGTORIUM 200! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal(C);
			break;
		case 2:
		
			try {
				C.adicionaCandidatoSessao(&candidato, s1);
			}
			catch (CandidatoInexistente candidato) {
				candidato.handler();
				Menu_Adicionar(C);
				break;
			}
			catch (CandidatoRepetido candidato) {
				candidato.handler();
				Menu_Adicionar(C);
				break;
			}
			catch (SessaoInexistente sessao) {
				sessao.handler();
				Menu_Adicionar(C);
				break;
			}
			cout << "=============================================================\n";
			cout << "Candidato adicionado a Sessao! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal( C);
			break;
		case 3:
			C.adicionaJurado(&jurado);
			cout << "=============================================================\n";
			cout << "Jurado adicionado ao CASTINGTORIUM 200! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal( C);
			break;
		case 4:
			try {
				C.adicionaJuradoSessao(&jurado, s1);
			}
			catch (JuradoInexistente jurado){
				jurado.handler();
				Menu_Adicionar(C);
				break;
			}
			catch (SessaoInexistente sessao) {
				sessao.handler();
				Menu_Adicionar(C);
				break;
			}
			catch (JuradoRepetido jurado) {
				jurado.handler();
				Menu_Adicionar(C);
				break;
			}
			catch (JuradosCompleto completo) {
				completo.handler();
				Menu_Principal(C);
				break;
			}
			cout << "=============================================================\n";
			cout << "Jurado adicionado a Sessao! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal(C);
			break;
		default:
			InvalidInputMenu(C);
			break;
		}
		return;
	}
}

void Menu_Remover(Castings C) {
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
			Menu_Principal(C);
			break;
		case 1:
			try {
				C.eliminaCandidato(&candidato);
			}
			catch (CandidatoInexistente candidato) {
				candidato.handler();
				Menu_Remover(C);
				break;
			}
			cout << "=============================================================\n";
			cout << "Candidato removido do CASTINGTORIUM2000... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal(C);
			break;
		case 2:
			try {
				C.eliminaCandidatoSessao(&candidato, s1);
			}
			catch (CandidatoInexistente candidato) {
				candidato.handler();
				Menu_Remover(C);
				break;
			}
			catch (SessaoInexistente sessao) {
				sessao.handler();
				Menu_Remover(C);
				break;
			}

			cout << "=============================================================\n";
			cout << "Candidato removido da Sessao... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal(C);
			break;
		case 3:
			//FUNCAO PARA REMOVER JURADO DO CASTINGTORIUM2000

			cout << "=============================================================\n";
			cout << "Jurado removido da CASTINGTORIUM2000... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal(C);
			break;
		case 4:
			//FUNCAO PARA REMOVER JURADO DA SESS�O

			cout << "=============================================================\n";
			cout << "Jurado removido da Sess�o... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal(C);
		default:
			InvalidInputMenu(C);
			break;
		}
		return;
	}
}

void InvalidInputMenu(Castings C) {
		if (cin.fail())
		{
			cout << "\nIntroduziu uma resposta invalida. Por favor, tente de novo. \n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			Menu_Principal(C);
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			Menu_Principal(C);
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

void Menu_Informacoes(Castings C) {
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
			Menu_Principal( C);
			break;
		case 1:
			//FUNCAO QUE LE CANDIDATOS E INFO BASICAS DELES + TIPO DE SESSAO
			break;
		case 2:
			//FUNCAO QUE LE JURADOS E INFO BASICAS
			break;
		case 3:
			Menu_Artes(C);
			break;
		case 4:
			txt_candidatos(C);
			break;
		case 5:
			txt_jurados(C);
			break;
		case 6:
			txt_sessoes(C);
			break;
		default:
			InvalidInputMenu(C);
			break;
		}
		return;
	}
}
void Menu_Artes(Castings C) {
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
			Menu_Principal(C);
			break;
		case 5:
			cout << "\t5.1)Malabarismo\n";
			cout << "\t5.2)Cinema\n";
			cout << "\t5.3)Speedrun\n";
			cout << "\t5.4)Comedia\n";
			cout << "0) Voltar Atras\n";
			switch (opcao) {
			case 0:
				Menu_Artes(C);
				break;
			default:
				InvalidInputMenu(C);
				break;
			}
		default:
			InvalidInputMenu(C);
			break;
		}
		return;
	}
}


//FUNCOES SAVE DE FICHEIROS
void Menu_Gravar_Ficheiro(Castings C) {
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
			InvalidInputMenu(C);
			break;
		}
	}
}


void Grava_Ficheiro_Candidatos(Castings C) {
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
	Menu_Principal(C);
}
void Grava_Ficheiro_Jurados(Castings C) {
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
	Menu_Principal(C);
}
void Grava_Ficheiro_Sessoes(Castings C) {
	Sessao sessoes;
	string ficheiro_sessoes;
	cout << "=============================================================\n";
	cout << "Insira o nome do ficheiro de sessoes que pretende gravar: \n";
	cin >> ficheiro_sessoes;

	ofstream Ficheiro_Sessoes;

	Ficheiro_Sessoes.open(ficheiro_sessoes);
	for (unsigned int i = 0; i < C.getSessao().size(); i++)
	{
		Ficheiro_Sessoes << C.getSessao().at(i).getId() << " ; " << C.getSessao().at(i).getFase() << " ; " << C.getSessao().at(i).getGenero() << " ; " << C.getSessao().at(i).getNumVagas() << " ; ";

		if (C.getSessao().at(i).getFase() == 2) {
			for (size_t j = 0; j < C.getSessao().at(i).getConcorrentes_finais().size(); j++) {
				cout << C.getSessao().at(i).getConcorrentes_finais().at(j) << " , ";
			}
			cout << " ; " << C.getSessao().at(i).getData();
		}
		else {
			for (size_t j = 0; j < C.getSessao().at(i).getConcorrentes_iniciais().size(); j++) {
				cout << C.getSessao().at(i).getConcorrentes_iniciais().at(j) << " , ";
			}
			cout << " ; " << C.getSessao().at(i).getData();
		}

		cout << endl;
	}
	Ficheiro_Sessoes.close();
	cout << "\n\nFicheiro gravado! Retornando ao Menu Principal...\n";
	cout << "=============================================================\n\n";
	Menu_Principal(C);
}

// nota: esta funçao lança exceções ---> chamar esta função dentro de um try
Candidato criar_Candidato(Castings C) {
	string nome, morada, genero, datastr;
	Data d;
	string dia, mes, ano;

	cout << "=============================================================\n";
	cout << "Insira o nome. \n";
	cin.ignore(1000, '\n');
	getline(cin, nome);

	if (C.candidatoExiste(nome) != -1)
		throw CandidatoRepetido(nome);

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
	novo.setDataNascimento(d);

	cout << "Candidato criado. O número de inscrição do candidato é: " << novo.getNumInscricao() << endl;
	cout << "=============================================================\n";

	return novo;
}

// nota: esta funçao lança exceções ---> chamar esta função dentro de um try
Jurado criar_Jurado(Castings C) {
	string nome, morada, genero, telemovel;

	cout << "=============================================================\n";
	cout << "Insira o nome. \n";
	getline(cin, nome);

	if (C.juradoExiste(nome) != -1)
		throw JuradoRepetido(nome);

	Jurado novo;
	novo.setNome(nome);

	cout << "Insira o número de telemóvel. \n";
	getline(cin, telemovel);
	novo.setTelemovel(telemovel);
	cout << "Insira a morada. \n";
	getline(cin, morada);
	novo.setMorada(morada);
	cout << "Insira o genero de arte performativa em que o candidato e mais forte. \n";
	getline(cin, genero);
	novo.setGenero(genero);

	cout << "Jurado criado. \n";
	cout << "=============================================================\n";

	return novo;
}
Sessao criar_Sessao(Castings C) {
	Sessao s1;
	return s1;
}

void txt_candidatos(Castings C) {
	int input = -1;
	for (unsigned int i = 0; i < C.getCandidatos().size(); i++)
	{
		cout << C.getCandidatos().at(i)->getNome() << " ; " << C.getCandidatos().at(i)->getMorada() << " ; " << C.getCandidatos().at(i)->getGenero() << " ; " << C.getCandidatos().at(i)->getDataNascimento().getDia() << "-" << C.getCandidatos().at(i)->getDataNascimento().getMes() << "-" << C.getCandidatos().at(i)->getDataNascimento().getAno() << endl;
	}
	
	cout << "\nVoltar atras? [0] SIM \t [1] MENU PRINCIPAL \n";
	cin >> input;
	if (input == 0)
		Menu_Informacoes(C);
	else
		Menu_Principal(C);

	return;
}

void txt_jurados(Castings C) {
	int input = -1;
	for (unsigned int i = 0; i < C.getJurados().size(); i++)
	{
		cout << C.getJurados().at(i)->getNome() << " ; " << C.getJurados().at(i)->getMorada() << " ; " << C.getJurados().at(i)->getGenero() << " ; " << C.getJurados().at(i)->getTelemovel() << endl;
	}

	cout << "\nVoltar atras? [0] SIM \t [1] MENU PRINCIPAL \n";
	cin >> input;
	if (input == 0)
		Menu_Informacoes(C);
	else
		Menu_Principal(C);

	return;
}

void txt_sessoes(Castings C) {
	int input = -1;
	for (unsigned int i = 0; i < C.getSessao().size(); i++)
	{
		if (C.getSessao().at(i).getFase() == 2) {
			for (size_t j = 0; j < C.getSessao().at(i).getConcorrentes_finais().size(); j++) {
				cout << C.getSessao().at(i).getConcorrentes_finais().at(j) << " , ";
			}
			cout << " ; " << C.getSessao().at(i).getData();
		}
		else {
			for (size_t j = 0; j < C.getSessao().at(i).getConcorrentes_iniciais().size(); j++) {
				cout << C.getSessao().at(i).getConcorrentes_iniciais().at(j) << " , ";
			}
			cout << " ; " << C.getSessao().at(i).getData();
		}

		cout << endl;
	}
	cout << "\nVoltar atras? [0] SIM \t [1] MENU PRINCIPAL \n";
	cin >> input;
	if (input == 0)
		Menu_Informacoes(C);
	else
		Menu_Principal(C);

	return;
}