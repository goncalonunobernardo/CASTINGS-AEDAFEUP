#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "castings.h"
#include <unordered_set>
using namespace std;

/**
@brief function to display full logo of company
*/
void Menu();
/**
@brief function to display invalid inputs
*/
void InvalidInputMenu();
/**
@brief function to display our Main Menu
*/
void Menu_Principal();
/**
@brief function to display option on what to add to the auditions
*/
void Menu_Adicionar();
/**
@brief function to display option on what to remove from the auditions
*/
void Menu_Remover();
/**
@brief function to display option on informations to show
*/
void Menu_Informacoes();
/**
@brief function to display ALL genres available
*/
void Menu_Artes();
/**
@brief function to change elements
*/
void Menu_Alterar();
/**
@brief function to end program
*/
void Termina_Programa();
/**
@brief function to display option on what files to save
*/
void Menu_Gravar_Ficheiro();
/**
@brief function to save Candidates'file
*/
void Grava_Ficheiro_Candidatos();
/**
@brief function to save Juries'file
*/
void Grava_Ficheiro_Jurados();
/**
@brief function to save Sessions'file
*/
void Grava_Ficheiro_Sessoes();
/**
@brief object to create Candidates
*/
Candidato criar_Candidato();
/**
@brief object to create Juries
*/
Jurado criar_Jurado();
/**
@brief object to create Sessions
*/
Sessao criar_Sessao();
/**
@brief object to create Dates
*/
Data data();
/**
@brief object to create Sessions
*/
Sessao criarSessao();
/**
@brief function to show information of candidates on program just like if you were seeing in txt file
*/
void txt_candidatos();
/**
@brief function to show information of juries on program just like if you were seeing in txt file
*/
void txt_jurados();
/**
@brief function to show information of sessions on program just like if you were seeing in txt file
*/
void txt_sessoes();
/**
@brief function to show winners of the auditions
*/
void mostrarVencedores();
/**
@brief function in order to create new genres
*/
void generoX();
/**
@brief function to read the data of an event
*/
Data lerData(string datastr);

/**
@brief function to get candidates info for interviews
*/
void getCandidatosparaEntrevistas(string genero);
string nome();
/**
@brief function to show unavailable candidates at the time
*/
void mostrarIndisponiveis();