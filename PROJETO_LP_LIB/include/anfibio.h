/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#ifndef _ANFIBIO_H_
#define _ANFIBIO_H_
#include "animal.h"
#include <string>
using std::string;
/**
@brief Criação da classe Anfibio
@details A classe Anfibio herda os parâmetros da classe Animal
*/
class Anfibio : public Animal
{
protected:
/**
@brief Criação dos parâmetros da classe Anfibio
@param int total_mudas para guardar o o total de mudas
@param string ultima_muda para guardar a ultima muda
*/
	int total_mudas;
	string ultima_muda;
public:
/**
	@brief Criação do Contrutor e Destrutor
*/
	Anfibio();
	~Anfibio();
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
	void SetBatismo(string batismo_);
	void SetTotal(int total_);
	void SetUltima(int ultima_);
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
	int GetTotal(void);
	string GetUltima(void);
};

#endif