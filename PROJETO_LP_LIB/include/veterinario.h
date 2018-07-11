/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#include <iostream>
#include <string>
#include "funcionario.h"
using std::string;
/**
@brief Criação da classe Veterinario
@details A classe veterinário herda os parâmetros da classe funcionario
*/
class Veterinario : funcionario
{
public:
/**
@brief Criação dos parâmetros da classe Veterinario
@param string animalCuidado para guardar o animal guardado
@param string profissao para guardar a profissao
@param int id_animal para guardar o id do animal para ser tratado
*/
	string animalCuidado;
	string profissao;
	int id_animal;
/**
@brief Criação dos métodos Setters
*/
	void SetId(int id_);
	void SetProfissao(string profissao_);	
	void SetNome(string nome_);
	void SetCPF(string cpf_);
	void SetIdade(string idade_);
	void SetTipo(string tipo_);
	void SetRH(string rh_);
	void SetEspec(string espec_);
	void SetAnimaisSendoCuidados(string animal, int id_ani);
/**
@brief Criação dos métodos Getters
*/
	int GetId(void);
	string GetProfissao(void);
	string GetNome(void);
	string GetCPF(void);
	string GetIdade(void);
	string GetTipo(void);
	string GetRH(void);
	string GetEspec(void);
	void GetAnimaisSendoCuidados(void);
};