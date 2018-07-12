/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#ifndef _MAMIFERO_H_
#define _MAMIFERO_H_
#include "anfibio.h"
#include <string>
using std::string;
/**
@brief Criação da classe Mamifero
@details A classe Mamifero herda os parâmetros da classe Anfibio
*/
class Mamifero : public Anfibio
{
protected:
/**
@brief Criação dos parâmetros da classe Memifero
@param int cor_pelo para guardar a cor do animal
*/
	string cor_pelo;
public:
/**
	@brief Criação do Contrutor e Destrutor
*/
	Mamifero();
	~Mamifero();
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
	void SetCorPelo(string cor_pelo_);
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
	string GetCorPelo(void);
};
#endif