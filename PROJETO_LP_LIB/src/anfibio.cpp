/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#ifndef ANFIBIO_H
#define ANFIBIO_H
#include <iostream>
#include <string>
#include "anfibio.h"
using namespace std;
using std::string;
/**
@brief Chamada do contrutor e destrutor()
*/
Anfibio::Anfibio(){}
Anfibio::~Anfibio(){}
/**
@brief Chamada do metodo SetId()
*/
void Anfibio::SetId(int id_){
	id = id_;
}
/**
@brief Chamada do metodo GetId()
*/
int Anfibio::GetId(void){
	return id;
}
//
//
/**
@brief Chamada do metodo SetClasse()
*/
void Anfibio::SetClasse(void){
	string classe_;
	cin >> classe_;
	classe = classe_;
}
/**
@brief Chamada do metodo GetClasse()
*/
string Anfibio::GetClasse(void){
	return classe;
}
//
//
/**
@brief Chamada do metodo SetNome()
*/
void Anfibio::SetNome(void){
	string nome_;
	cin >> nome_;
	nome = nome_;
}
/**
@brief Chamada do metodo GetNome()
*/
string Anfibio::GetNome(void){
	return nome;
}
//
//
/**
@brief Chamada do metodo SetCientifico()
*/
void Anfibio::SetCientifico(void){
	string cientifico_;
	cin >> cientifico_;
	cientifico = cientifico_;
}
/**
@brief Chamada do metodo GetCientifico()
*/
string Anfibio::GetCientifico(void){
	return cientifico;
}
//
//
/**
@brief Chamada do metodo SetSexo()
*/
void Anfibio::SetSexo(void){
	char sexo_;
	cin >> sexo_;
	sexo = sexo_;
}
/**
@brief Chamada do metodo GetSexo()
*/
char Anfibio::GetSexo(void){
	return sexo;
}
//
//
/**
@brief Chamada do metodo SetTamanho()
*/
void Anfibio::SetTamanho(void){
	float tamanho_;
	cin >> tamanho_;
	tamanho = tamanho_;
}
/**
@brief Chamada do metodo GetTamanho()
*/
float Anfibio::GetTamanho(void){
	return tamanho;
}
//
//
/**
@brief Chamada do metodo SetDieta()
*/
void Anfibio::SetDieta(void){
	string dieta_;
	cin >> dieta_;
	dieta = dieta_;
}
/**
@brief Chamada do metodo GetDieta()
*/
string Anfibio::GetDieta(void){
	return dieta;
}
//
//
/**
@brief Chamada do metodo SetVeterinario()
*/
void Anfibio::SetVeterinario(void){
	int veterinario_;
	cin >> veterinario_;
	veterinario = veterinario_;
}
/**
@brief Chamada do metodo GetVeterinario()
*/
int Anfibio::GetVeterinario(void){
	return veterinario;
}
//
//
/**
@brief Chamada do metodo SetTratador()
*/
void Anfibio::SetTratador(void){
	int tratador_;
	cin >> tratador_;
	tratador = tratador_;
}
/**
@brief Chamada do metodo GetTratador()
*/
int Anfibio::GetTratador(void){
	return tratador;
}
//
//
/**
@brief Chamada do metodo SetBatismo()
*/
void Anfibio::SetBatismo(void){
	string batismo_;
	cin >> batismo_;
	batismo = batismo_;
}
/**
@brief Chamada do metodo GetBatismo()
*/
string Anfibio::GetBatismo(void){
	return batismo;
}
//
//
/**
@brief Chamada do metodo SetTotal()
*/
void Anfibio::SetTotal(void){
	int total_;
	cin >> total_;
	total_mudas = total_;
}
/**
@brief Chamada do metodo GetTotal()
*/
int Anfibio::GetTotal(void){
	return total_mudas;
}
//
//
/**
@brief Chamada do metodo SetUltima()
*/
void Anfibio::SetUltima(void){
	string ultima_;
	cin >> ultima_;
	ultima_muda = ultima_;
}
/**
@brief Chamada do metodo GetUltima()
*/
string Anfibio::GetUltima(void){
	return ultima_muda;
}
#endif