/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#ifndef _REPTIL_H_
#define _REPTIL_H_
#include "mamifero.h"
#include <string>
using std::string;
/**
@brief Criação da classe Reptil
@details A classe Reptil herda os parâmetros da classe Memifero
*/
class Reptil : public Mamifero
{
protected:
/**
@brief Criação dos parâmetros da classe Reptil
@param int venenoso para guardar se o animal é venenoso ou não
@param string tipo_veneno para guardar o tipo do veneno
*/
	int venenoso;
	string tipo_veneno;
public:
/**
	@brief Criação do Contrutor e Destrutor
*/
	Reptil();
	~Reptil();
/**
@brief Criação dos métodos Setters
*/
	void SetId(int id_);
	void SetClasse(string classe_);
	void SetNome(string nome_);
	void SetCientifico(string cientifico_);
	void SetSexo(string sexo_);
	void SetTamanho(float tamanho_);
	void SetDieta(string dieta_);
	void SetVeterinario(int veterinario_);
	void SetTratador(int tratador_);
	void SetBatismo(string batismo);
	void SetVenenoso(int venenoso_);
	void SetTipoVeneno(string veneno_);
/**
@brief Criação dos métodos Getters
*/
	int GetId(void);
	string GetClasse(void);
	string GetNome(void);
	string GetCientifico(void);
	string GetSexo(void);
	float GetTamanho(void);
	string GetDieta(void);
	int GetVeterinario(void);
	int GetTratador(void);
	string GetBatismo(void);
	int GetVenenoso(void);
	string GetTipoVeneno(void);
};

#endif