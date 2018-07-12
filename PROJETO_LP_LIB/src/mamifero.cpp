/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#ifndef MAMIFERO_H
#define MAMIFERO_H
#include <iostream>
#include <string>
#include "mamifero.h"
using namespace std;
using std::string;
/**
@brief Chamada do contrutor e destrutor()
*/
Mamifero::Mamifero(){}
Mamifero::~Mamifero(){}
/**
@brief Chamada do metodo SetId()
*/
void Mamifero::SetId(int id_){
	id = id_;
}
/**
@brief Chamada do metodo GetId()
*/
int Mamifero::GetId(void){
	return id;
}
//
//
/**
@brief Chamada do metodo SetClasse()
*/
void Mamifero::SetClasse(string classe_){
	classe = classe_;
}
/**
@brief Chamada do metodo GetClasse()
*/
string Mamifero::GetClasse(void){
	return classe;
}
//
//
/**
@brief Chamada do metodo SetNome()
*/
void Mamifero::SetNome(string nome_){
	nome = nome_;
}
/**
@brief Chamada do metodo GetNome()
*/
string Mamifero::GetNome(void){
	return nome;
}
//
//
/**
@brief Chamada do metodo SetCientifico()
*/
void Mamifero::SetCientifico(string cientifico_){
	cientifico = cientifico_;
}
/**
@brief Chamada do metodo GetCientifico()
*/
string Mamifero::GetCientifico(void){
	return cientifico;
}
//
//
/**
@brief Chamada do metodo SetSexo()
*/
void Mamifero::SetSexo(string sexo_){
	sexo = sexo_;
}
/**
@brief Chamada do metodo GetSexo()
*/
string Mamifero::GetSexo(void){
	return sexo;
}
//
//
/**
@brief Chamada do metodo SetTamanho()
*/
void Mamifero::SetTamanho(float tamanho_){
	tamanho = tamanho_;
}
/**
@brief Chamada do metodo GetTamanho()
*/
float Mamifero::GetTamanho(void){
	return tamanho;
}
//
//
/**
@brief Chamada do metodo SetDieta()
*/
void Mamifero::SetDieta(string dieta_){
	dieta = dieta_;
}
/**
@brief Chamada do metodo GetDieta()
*/
string Mamifero::GetDieta(void){
	return dieta;
}
//
//
/**
@brief Chamada do metodo SetVeterinario()
*/
void Mamifero::SetVeterinario(int veterinario_){
	veterinario = veterinario_;
}
/**
@brief Chamada do metodo GetVeterinario()
*/
int Mamifero::GetVeterinario(void){
	return veterinario;
}
//
//
/**
@brief Chamada do metodo SetTratador()
*/
void Mamifero::SetTratador(int tratador_){
	tratador = tratador_;
}
/**
@brief Chamada do metodo GetTratador()
*/
int Mamifero::GetTratador(void){
	return tratador;
}
//
//
/**
@brief Chamada do metodo SetBatismo()
*/
void Mamifero::SetBatismo(string batismo_){
	batismo = batismo_;
}
/**
@brief Chamada do metodo GetBatismo()
*/
string Mamifero::GetBatismo(void){
	return batismo;
}
/**
@brief Chamada do metodo SetCorPelo()
*/
void Mamifero::SetCorPelo(string cor_pelo_){
	cor_pelo=cor_pelo_;
}
/**
@brief Chamada do metodo GetCorPelo()
*/
string Mamifero::GetCorPelo(void){
	return cor_pelo;
}

#endif