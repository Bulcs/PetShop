/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/

#include <iostream>
#include "veterinario.h"
#include <string>

using namespace std;
using std::string;
/**
@brief Chamada do metodo SetId()
*/
void Veterinario::SetId(int id_){
	id = id_;
}
/**
@brief Chamada do metodo GetId()
*/
int Veterinario::GetId(void){
	return id;
}
//
//
/**
@brief Chamada do metodo SetProfissao()
*/
void Veterinario::SetProfissao(void){
	string profissao_;
	cin >> profissao_;
	profissao = profissao_;
}
/**
@brief Chamada do metodo GetProfissao()
*/
string Veterinario::GetProfissao(void){
	return profissao;
}
//
//
/**
@brief Chamada do metodo SetNome()
*/
void Veterinario::SetNome(void){
	string nome_;
	cin >> nome_;
	nome = nome_;
}
/**
@brief Chamada do metodo GetNome()
*/
string Veterinario::GetNome(void){
	return nome;
}
//
//
/**
@brief Chamada do metodo SetCPF()
*/
void Veterinario::SetCPF(void){
	string cpf_;
	cin >> cpf_;
	cpf = cpf_;
}
/**metodo
@brief Chamada do metodo GetCPF()
*/
string Veterinario::GetCPF(void){
	return cpf;
}
//
//
/**
@brief Chamada do metodo SetIdade()
*/
void Veterinario::SetIdade(void){
	int idade_;
	cin >> idade_;
	idade = idade_;
}
/**
@brief Chamada do parâmetro GetIdade()
*/
int Veterinario::GetIdade(void){
	return idade;
}
//
//
/**
@brief Chamada do metodo SetTipo()
*/
void Veterinario::SetTipo(void){
	string tipo;
	cin >> tipo;
	tipo_sanguineo = tipo;
}
/**
@brief Chamada do metodo GetTipo()
*/
string Veterinario::GetTipo(void){
	return tipo_sanguineo;
}
//
//
/**
@brief Chamada do metodo SetRH()
*/
void Veterinario::SetRH(void){
	string RH;
	cin >> RH;
	fatorRH = RH;
}
/**
@brief Chamada do metodo GetRH()
*/
string Veterinario::GetRH(void){
	return fatorRH;
}
//
//
/**
@brief Chamada do metodo SetEspec()
*/
void Veterinario::SetEspec(void){
	string espec_;
	cin >> espec_;
	especialidade = espec_;
}
/**
@brief Chamada do metodo GetEspec()
*/
string Veterinario::GetEspec(void){
	return especialidade;
}
//
//
/**
@brief Chamada do metodo SetAnimaisSendoCuidados()
*/
void Veterinario::SetAnimaisSendoCuidados(string animais, int id_ani){
	animalCuidado = animais;
	id_animal = id_ani;
}
/**
@brief Chamada do metodo GetAnimaisSendoCuidados()
*/
void Veterinario::GetAnimaisSendoCuidados(void){
	cout << "O funcionário está cuidando do " << animalCuidado << " de id:" << id_animal<< endl;
}