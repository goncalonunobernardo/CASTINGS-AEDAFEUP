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
	cout << "=============================================================================================================\n\n";
	cout << "	 ____                        _           __                   \n";
	cout << "	/ __ )___  ____ ___   _   __(_)___   ___/ /__     ____ _____\n";
	cout << "  / __  / _ \/ __ `__ \ | | / / / __ \/ __ / __ \  / __ `/  __ \\n";
	cout << " / /_/ /  __/ / / / / / | |/ / / / / //_/ / /_/ / / /_/_/ //_//\n";
	cout << "/_____/\___/_/ /_/ /_/  |___/_/_/ /_/\___/\____/  \__,_/\____/\n\n";
	cout << " _ _  ___    __________   ___   _                                __  _\n";
	cout << "( | )/   |  / ____ / __ \/   | () _____    __________ __  ____ _/ /_(_)   _____\n";
	cout << "|/| / /| | / __/  / / / / /| | |/_ ___/   / ___/ ___/ _ \/ __ `/ __/ / | / / _ \\n";
	cout << "   / ___ |/ /___ / /_/ / ___ |  ___/  /  / /__/ / /  __// /_/ / / / /| |/ /  __/\n";
	cout << "  /_/  |_/_____//_____/_/  |_| /____ /   \___/_/  \___/ \__,_/\__/_/ |___/\___/ \n\n";
	cout << "   _________   ________________   __________________  ____  ______  ____  ___   ___  ____  ____  ___ _ _ \n";
	cout << "  / ____/   | / ___/_  __/  _/ | / / ____/_  __/ __ \/ __ \/  _/ / / /  |/  /  |__ \/ __ \/ __ \/ __ ( | )\n";
	cout << " / /   / /| | \__ \ / /  / //  |/ / / __  / / / / / / /_/ // // / / / /|_/ /   __/ / / / / / / / / / //|/    (TM)  \n";
	cout << "/ /___/ ___ |___/ // / _/ // /|  / /_/ / / / / /_/ / _, _// // /_/ / /  / /   / __/ /_/ / /_/ / /_/ / \n";
	cout << "\____/_/  |_/____//_/ /___/_/ |_/\____/ /_/  \____/_/ |_/___/\____/_/  /_/   /____|____/\____/\____/  \n\n";
	cout << "=============================================================================================================\n\n";

int opcao = -1;	

	cout << "=============================================================================================================\n\n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << " 1) Adicionar...\n";
	cout << " 2) Remover...\n";
	cout << " 3) Alterar...\n";
	cout << " 4) Informacoes.\n";
	cout << " 5) Gravar Ficheiro\n";
	cout << " 6) Exibir classifica��es \n";
	cout << " 0) Terminar programa.\n";
	cout << "=============================================================================================================\n";
	while (!cin.fail())
	{
		cin >> opcao;
		switch (opcao) {
		case 0:
			void Termina_Programa();
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
		case 5:
			Menu_Gravar_Ficheiros();
			break;
		case 6:
			Menu_MostrarResultados();
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
	cout << "2) Candidato a Sess�o";
	cout << "3) Jurado ao CASTINGTORIUM 2000\n";
	cout << "4) Jurado a Sess�o";
	cout << "5) Classifica��es";
	cout << "0) Menu Principal\n";
	cout << "=============================================================\n";
	while (!cin.fail())
	{
		cin >> opcao;
		switch (opcao) {
		case 0:
			Menu_Principal();
		case 1:

			casting.adicionaCandidato(&candidato);
			cout << "=============================================================\n";
			cout << "Candidato adicionado ao CASTINGTORIUM 200! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 2:
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
			cout << "Candidato adicionado � Sess�o! \nRetornando ao Menu Principal...\n";
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
			cout << "Jurado adicionado � Sess�o! \nRetornando ao Menu Principal...\n";
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
	Candidato candidato;
	Jurado jurado;
	Sessao s1;

	opcao = -1;

	cout << "=============================================================\n";
	cout << "Indique o elemento que pretende remover no programa: \n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << "1) Candidato ao Castingtorium 2000\n";
	cout << "2) Candidato a Sess�o";
	cout << "3) Jurado ao Castingtorium 2000\n";
	cout << "4) Jurado a Sess�o";
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
			cout << "Candidato removido da Sess�o... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 3:
			//FUN��O PARA REMOVER JURADO DO CASTINGTORIUM2000

			cout << "=============================================================\n";
			cout << "Jurado removido da CASTINGTORIUM2000... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 4:
			//FUN��O PARA REMOVER JURADO DA SESS�O

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
	cout << "3) Tipos de Sess�o";
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
		case 1:
			//FUN��O QUE L� CANDIDATOS E INFO B�SICAS DELES + TIPO DE SESSAO
			break;
		case 2:
			//FUN��O QUE L� JURADOS E INFO B�SICAS
			break;
		case 3:
			Menu_Artes();
			break;
		case 4:
			//FUN��O QUE MOSTRA FICHEIRO DE CANDIDATOS COMO SE FOSSE LER NUM .TXT
			break;
		case 5:
			//FUN��O QUE MOSTRA FICHEIRO DE JURADOS COMO SE FOSSE LER NUM .TXT
		case 6:
			//FUN��O QUE MOSTRA FICHEIRO DE SESSOES COMO SE FOSSE LER NUM .TXT
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
	cout << "Artes dispon�veis para Sess�es no CASTINGTORIUM 2000: \n";
	cout << "1) Dan�a";
	cout << "2) Teatro";
	cout << "3) M�sica";
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
			cout << "\t5.2)Voice Acting\n";
			cout << "\t5.3)Concurso de Beleza\n";
			cout << "\t5.4)Stand-Up Comedy\n";
			cout << "0) Voltar Atr�s\n";

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


//FUN��ES SAVE DE FICHEIROS
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
			Menu_Principal();
			break;
		case 1:
			Grava_Ficheiro_Candidatos();
		case 2:
			Grava_Ficheiro_Jurados();
		case 3:
			//Grava_Ficheiro_Sessoes();
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
//Como aceder ao vetor de candidatos??
	/*for (unsigned int i = 0; i < candidatos.size(); i++)
	{
		Ficheiro_Candidato << Condutores.at(i).ID_Motorista << " ; " << Condutores.at(i).Nome << " ; " << Condutores.at(i).NHoras_Turno << " ; " << Condutores.at(i).NHoras_Semanais << " ; " << Condutores.at(i).NHoras_Descanso << endl;
	}*/
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
	//Como aceder ao vetor de jurados??
	/*for (unsigned int i = 0; i < candidatos.size(); i++)
	{
	Ficheiro_Candidato << Condutores.at(i).ID_Motorista << " ; " << Condutores.at(i).Nome << " ; " << Condutores.at(i).NHoras_Turno << " ; " << Condutores.at(i).NHoras_Semanais << " ; " << Condutores.at(i).NHoras_Descanso << endl;
	}*/
	Ficheiro_Jurado.close();
	cout << "\n\nFicheiro gravado! Retornando ao Menu Principal...\n";
	cout << "=============================================================\n\n";
	Menu_Principal();
}

void criar_Candidato(Candidato & novo) {
	string nome, morada, genero, datastr;
	cout << "Insira o nome. \n";
	getline(cin, nome);
	novo.setNome(nome);
	cout << "Insira a morada. \n";
	getline(cin, morada);
	novo.setMorada(morada);
	cout << "Insira o género de arte performativa em que o candidato é mais forte. \n";
	getline(cin, genero);
	novo.setGenero(genero);
	cout << "Insira a data de nascimento. (no formato dd/mm/aaaa) \n";
	getline(cin, datastr);
	novo.setDataNascimento(datastr);
	
}