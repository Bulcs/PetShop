/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#ifndef AVE_H
#define AVE_H
#include <iostream>
#include <string>
#include "ave.h"
using namespace std;
using std::string;
/**
@brief Chamada do contrutor e destrutor()
*/
Ave::Ave(){}
Ave::~Ave(){}
/**
@brief Chamada do metodo SetId()
*/
void Ave::SetId(int id_){
	id = id_;
}
/**
@brief Chamada do metodo GetId()
*/
int Ave::GetId(void){
	return id;
}
//
//
/**
@brief Chamada do metodo SetClasse()
*/
void Ave::SetClasse(void){
	string classe_;
	cin >> classe_;
	classe = classe_;
}
/**
@brief Chamada do metodo GetClasse()
*/
string Ave::GetClasse(void){
	return classe;
}
//
//
/**
@brief Chamada do metodo SetNome()
*/
void Ave::SetNome(void){
	string nome_;
	cin >> nome_;
	nome = nome_;
}
/**
@brief Chamada do metodo GetNome()
*/
string Ave::GetNome(void){
	return nome;
}
//
//
/**
@brief Chamada do metodo SetCientifico()
*/
void Ave::SetCientifico(void){
	string cientifico_;
	cin >> cientifico_;
	cientifico = cientifico_;
}
/**
@brief Chamada do metodo GetCientifico()
*/
string Ave::GetCientifico(void){
	return cientifico;
}
//
//
/**
@brief Chamada do metodo SetSexo()
*/
void Ave::SetSexo(void){
	char sexo_;
	cin >> sexo_;
	sexo = sexo_;
}
/**
@brief Chamada do metodo GetSexo()
*/
char Ave::GetSexo(void){
	return sexo;
}
//
//
/**
@brief Chamada do metodo SetTamanho()
*/
void Ave::SetTamanho(void){
	float tamanho_;
	cin >> tamanho_;
	tamanho = tamanho_;
}
/**
@brief Chamada do metodo GetTamanho()
*/
float Ave::GetTamanho(void){
	return tamanho;
}
//
//
/**
@brief Chamada do metodo SetDieta()
*/
void Ave::SetDieta(void){
	string dieta_;
	cin >> dieta_;
	dieta = dieta_;
}
/**
@brief Chamada do metodo GetDieta()
*/
string Ave::GetDieta(void){
	return dieta;
}
//
//
/**
@brief Chamada do metodo GetDieta()
*/
void Ave::SetVeterinario(void){
	int veterinario_;
	cin >> veterinario_;
	veterinario = veterinario_;
}
/**
@brief Chamada do metodo GetVeterinario()
*/
int Ave::GetVeterinario(void){
	return veterinario;
}
//
//
/**
@brief Chamada do metodo SetTratador()
*/
void Ave::SetTratador(void){
	int tratador_;
	cin >> tratador_;
	tratador = tratador_;
}
/**
@brief Chamada do metodo GetTratador()
*/
int Ave::GetTratador(void){
	return tratador;
}
//
//
/**
@brief Chamada do metodo SetBatismo()
*/
void Ave::SetBatismo(void){
	string batismo_;
	cin >> batismo_;
	batismo = batismo_;
}
/**
@brief Chamada do metodo GetBatismo()
*/
string Ave::GetBatismo(void){
	return batismo;
}
//
//
/**
@brief Chamada do metodo SetTamanhoBico()
*/
void Ave::SetTamanhoBico(void){
	float tamanho_bico_;
	cin >> tamanho_bico_;
	tamanho_bico=tamanho_bico_;
}
/**
@brief Chamada do metodo GetTamanhoBico()
*/
float Ave::GetTamanhoBico(void){
	return tamanho_bico;
}
//
//
/**
@brief Chamada do metodo SetEnvergadura()
*/
void Ave::SetEnvergadura(void){
	float envergadura_;
	cin >> envergadura_;
	envergadura=envergadura_;
}
/**
@brief Chamada do metodo GetEnvergadura()
*/
float Ave::GetEnvergadura(void){
	return envergadura;
}
#endif