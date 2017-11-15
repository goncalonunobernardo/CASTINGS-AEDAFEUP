#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "menus.h"
#include "castings.h"

using namespace std;

void Menu_Principal() {
	cout << "=============================================================================================================\n\n";
	cout << "	 ____                        _           __                   \n";
	cout << "	/ __ )___  ____ ___   _   __(_)___   ___/ /__    ____ _____\n";
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
			//Menu_Informacoes();
		case 5:
			//MenuGravarFicheiro();
			break;
		default:
			//InvalidInputMenu();
			break;
		}
		return;
	}
}
	
void Menu_Adicionar() {
	int opcao;
	Castings casting;
	Candidato candidato;
	Jurado jurado;
	Sessao s1;

	opcao = -1;
	
	cout << "=============================================================\n";
	cout << "Indique o elemento que pretende adicionar ao programa: \n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << "1) Candidato ao CASTINGTORIUM 2000\n";
	cout << "2) Candidato a Sessão";
	cout << "3) Jurado ao CASTINGTORIUM 2000\n";
	cout << "4) Jurado a Sessão";
	cout << "0) Menu Principal\n";
	cout << "=============================================================\n";
	while (!cin.fail())
	{
		cin >> opcao;
		switch (opcao) {
		case 0:
			Termina_Programa();
		case 1:
			casting.adicionaCandidato(&candidato);

			cout << "=============================================================\n";
			cout << "Candidato adicionado ao CASTINGTORIUM 200! \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 2:
			casting.adicionaCandidatoSessao(&candidato, s1);
			cout << "=============================================================\n";
			cout << "Candidato adicionado à Sessão! \nRetornando ao Menu Principal...\n";
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
			casting.adicionaJuradoSessao(&jurado, s1);

			cout << "=============================================================\n";
			cout << "Jurado adicionado à Sessão! \nRetornando ao Menu Principal...\n";
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
	Castings casting;
	Candidato candidato;
	Jurado jurado;
	Sessao s1;

	opcao = -1;

	cout << "=============================================================\n";
	cout << "Indique o elemento que pretende remover no programa: \n";
	cout << "Por favor escolha um numero como opcao. \n";
	cout << "1) Candidato ao Castingtorium 2000\n";
	cout << "2) Candidato a Sessão";
	cout << "3) Jurado ao Castingtorium 2000\n";
	cout << "4) Jurado a Sessão";
	cout << "0) Menu Principal\n";
	cout << "=============================================================\n";
	while (!cin.fail())
	{
		cin >> opcao;
		switch (opcao) {
		case 0:
			Termina_Programa();
		case 1:
			casting.eliminaCandidato(&candidato);

			cout << "=============================================================\n";
			cout << "Candidato removido do CASTINGTORIUM2000... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 2:
			s1.eliminaCandidatoSessao(&candidato);

			cout << "=============================================================\n";
			cout << "Candidato removido da Sessão... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 3:
			//FUNÇÃO PARA REMOVER JURADO DO CASTINGTORIUM2000

			cout << "=============================================================\n";
			cout << "Jurado removido da CASTINGTORIUM2000... \nRetornando ao Menu Principal...\n";
			cout << "=============================================================\n";
			Menu_Principal();
			break;
		case 4:
			//FUNÇÃO PARA REMOVER JURADO DA SESSÃO

			cout << "=============================================================\n";
			cout << "Jurado removido da Sessão... \nRetornando ao Menu Principal...\n";
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
		cout << "\nTerminando programa, aguarde...\n";
		cout << "\nObrigado pela sua colaboracao, volte em breve!\n\n";
		cout << "=============================================================";
		cout << "\n\n";
		exit(0);
	}