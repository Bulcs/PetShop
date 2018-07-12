/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/

#ifndef _VETERINARIO_H_
#define _VETERINARIO_H_

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
void Veterinario::SetProfissao(string profissao_){
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
void Veterinario::SetNome(string nome_){
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
void Veterinario::SetCPF(string cpf_){
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
void Veterinario::SetIdade(string idade_){
	idade = idade_;
}
/**
@brief Chamada do parâmetro GetIdade()
*/
string Veterinario::GetIdade(void){
	return idade;
}
//
//
/**
@brief Chamada do metodo SetTipo()
*/
void Veterinario::SetTipo(string tipo_){
	tipo_sanguineo = tipo_;
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
void Veterinario::SetRH(string rh_){
	fatorRH = rh_;
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
void Veterinario::SetEspec(string espec_){
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

std::ostream& operator<<(std::ostream &o,Veterinario f){
	o <<"Id: "<< f.id << "\n" << "Cargo: " << f.profissao << "\n" << "Nome: " << f.nome << "\n" << "CPF: " << f.cpf << "\n" << "Idade: "<< f.idade << "\n"<< "Tipo Sanguineo: " << f.tipo_sanguineo << "\n" << "Fator RH: "<< f.fatorRH<< "\n" << "Especialidade: " << f.especialidade << endl; 
	return o;
}


#endif