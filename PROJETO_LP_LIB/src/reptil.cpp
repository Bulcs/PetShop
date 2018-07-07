/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#ifndef REPTIL_H
#define REPTIL_H
#include <iostream>
#include <string>
#include "reptil.h"
using namespace std;
using std::string;
/**
@brief Chamada do contrutor e destrutor()
*/
Reptil::Reptil(){}
Reptil::~Reptil(){}

/**
@brief Chamada do metodo SetId()
*/
void Reptil::SetId(int id_){
	id = id_;
}
/**
@brief Chamada do metodo GetId()
*/
int Reptil::GetId(void){
	return id;
}
//
//
/**
@brief Chamada do metodo SetClasse()
*/
void Reptil::SetClasse(void){
	string classe_;
	cin >> classe_;
	classe = classe_;
}
/**
@brief Chamada do metodo GetClasse()
*/
string Reptil::GetClasse(void){
	return classe;
}
//
//
/**
@brief Chamada do metodo SetNome()
*/
void Reptil::SetNome(void){
	string nome_;
	cin >> nome_;
	nome = nome_;
}
/**
@brief Chamada do metodo GetNome()
*/
string Reptil::GetNome(void){
	return nome;
}
//
//
/**
@brief Chamada do metodo SetCientifico()
*/
void Reptil::SetCientifico(void){
	string cientifico_;
	cin >> cientifico_;
	cientifico = cientifico_;
}
/**
@brief Chamada do metodo GetCientifico()
*/
string Reptil::GetCientifico(void){
	return cientifico;
}
//
//
/**
@brief Chamada do metodo SetSexo()
*/
void Reptil::SetSexo(void){
	char sexo_;
	cin >> sexo_;
	sexo = sexo_;
}
/**
@brief Chamada do metodo GetSexo()
*/
char Reptil::GetSexo(void){
	return sexo;
}
//
//
/**
@brief Chamada do metodo SetTamanho()
*/
void Reptil::SetTamanho(void){
	float tamanho_;
	cin >> tamanho_;
	tamanho = tamanho_;
}
/**
@brief Chamada do metodo GetTamanho()
*/
float Reptil::GetTamanho(void){
	return tamanho;
}
//
//
/**
@brief Chamada do metodo SetDieta()
*/
void Reptil::SetDieta(void){
	string dieta_;
	cin >> dieta_;
	dieta = dieta_;
}
/**
@brief Chamada do metodo GetDieta()
*/
string Reptil::GetDieta(void){
	return dieta;
}
//
//
/**
@brief Chamada do metodo SetVeterinario()
*/
void Reptil::SetVeterinario(void){
	int veterinario_;
	cin >> veterinario_;
	veterinario = veterinario_;
}
/**
@brief Chamada do metodo GetVeterinario()
*/
int Reptil::GetVeterinario(void){
	return veterinario;
}
//
//
/**
@brief Chamada do metodo SetTratador()
*/
void Reptil::SetTratador(void){
	int tratador_;
	cin >> tratador_;
	tratador = tratador_;
}
/**
@brief Chamada do metodo GetTratador()
*/
int Reptil::GetTratador(void){
	return tratador;
}
//
//
/**
@brief Chamada do metodo SetBatismo()
*/
void Reptil::SetBatismo(void){
	string batismo_;
	cin >> batismo_;
	batismo = batismo_;
}
/**
@brief Chamada do metodo GetBatismo()
*/
string Reptil::GetBatismo(void){
	return batismo;
}
//
//
/**
@brief Chamada do metodo SetVenenoso()
*/
void Reptil::SetVenenoso(void){
	int venenoso_;
	cin >> venenoso_;
	venenoso=venenoso_;
}
/**
@brief Chamada do metodo GetVenenoso()
*/
int Reptil::GetVenenoso(void){
	return venenoso;
}
//
//
/**
@brief Chamada do metodo SetTipoVeneno()
*/
void Reptil::SetTipoVeneno(void){
	string veneno_;
	cin >> veneno_;
	tipo_veneno=veneno_;
}
/**
@brief Chamada do metodo GetTipoVeneno()
*/
string Reptil::GetTipoVeneno(void){
	return tipo_veneno;
}

#endif