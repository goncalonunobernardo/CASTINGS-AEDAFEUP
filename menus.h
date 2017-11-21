#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "castings.h"
using namespace std;

void InvalidInputMenu(Castings C);
void Menu_Principal(Castings C);
void Menu_Adicionar(Castings C);
void Menu_Remover(Castings C);
/*
void Menu_Alterar();*/
void Menu_Informacoes(Castings C);
void Menu_Artes(Castings C);
void Termina_Programa();

void Menu_Gravar_Ficheiro(Castings C);
void Grava_Ficheiro_Candidatos(Castings C);
void Grava_Ficheiro_Jurados(Castings C);
void Grava_Ficheiro_Sessoes(Castings C);

//void Menu_MostrarResultados();

Candidato criar_Candidato(Castings C);
Jurado criar_Jurado(Castings C);
Sessao criar_Sessao(Castings C);

void txt_candidatos(Castings C);
void txt_jurados(Castings C);
void txt_sessoes(Castings C);