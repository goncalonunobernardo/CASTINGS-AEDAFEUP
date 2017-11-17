#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "castings.h"


using namespace std;

void InvalidInputMenu();
void Menu_Principal();
void Menu_Adicionar();
void Menu_Remover();
/*
void Menu_Alterar();*/
void Menu_Informacoes();
void Menu_Artes();
void Termina_Programa();

void Menu_Gravar_Ficheiros();
void Grava_Ficheiro_Candidatos();
void Grava_Ficheiro_Jurados();

void Menu_MostrarResultados();
void criar_Candidato(Candidato & novo);