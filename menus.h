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

void Menu_Gravar_Ficheiro();
void Grava_Ficheiro_Candidatos();
void Grava_Ficheiro_Jurados();
void Grava_Ficheiro_Sessoes();

//void Menu_MostrarResultados();

Candidato criar_Candidato();
Jurado criar_Jurado();
Sessao criar_Sessao();

void txt_candidatos();
void txt_jurados();
void txt_sessoes();