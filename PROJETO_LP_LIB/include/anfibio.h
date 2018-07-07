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
	void SetClasse(void);
	void SetNome(void);
	void SetCientifico(void);
	void SetSexo(void);
	void SetTamanho(void);
	void SetDieta(void);
	void SetVeterinario(void);
	void SetTratador(void);
	void SetBatismo(void);
	void SetTotal(void);
	void SetUltima(void);
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