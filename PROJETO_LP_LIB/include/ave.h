/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#ifndef _AVE_H_
#define _AVE_H_
#include <string>
#include "reptil.h"
using std::string;
/**
@brief Criação da classe Ave
@details A classe veterinário herda os parâmetros da classe Reptil
*/
class Ave : public Reptil
{
public:
/**
@brief Criação dos parâmetros da classe Ave
@param float tamanho_bico para guardar o tamanho do bico do animal
@param float envergadura para guardar a envergadura do animal
*/
	float tamanho_bico;
	float envergadura;
/**
	@brief Criação do Contrutor e Destrutor
*/
	Ave();
	~Ave();
/**
@brief Criação dos métodos Setters
*/
	void SetId(int id_);
	void SetClasse(string classe_);
	void SetNome(string nome_);
	void SetCientifico(string cientifico_);
	void SetSexo(char sexo_);
	void SetTamanho(float tamanho_);
	void SetDieta(string dieta_);
	void SetVeterinario(int veterinario_);
	void SetTratador(int tratador_);
	void SetBatismo(string batismo);
	void SetTamanhoBico(float tamanho_bico_);
	void SetEnvergadura(float envergadura_);
/**
@brief Criação dos métodos Getters
*/
	int GetId(void);
	string GetClasse(void);
	string GetNome(void);
	string GetCientifico(void);
	char GetSexo(void);
	float GetTamanho(void);
	string GetDieta(void);
	int GetVeterinario(void);
	int GetTratador(void);
	string GetBatismo(void);
	float GetTamanhoBico(void);
	float GetEnvergadura(void);
};
#endif