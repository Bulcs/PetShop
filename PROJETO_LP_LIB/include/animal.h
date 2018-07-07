/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using std::string;
/**
@brief Criação da classe Animal
*/
class Animal
{
protected:
/**
@brief Criação dos parâmetros da classe Animal
@param int id para guardar o id do animal
@param string classe para a classe do animal
@param string nome guarda o nome do animal
@param string cientifico guarda o termo cientifico do animal
@param char sexo guarda o sexo do animal
@param float tamanho guarda o tamanho do animal
@param string dieta guarda a dieta do animal
@param int veterinario verifica se tem algum veterinario tratando o animal
@param int tratador verifica se tem algum tratador tratando o animal
@param string batismo guarda o nome de batismo do animal
*/
	int id;
	string classe;
	string nome;
	string cientifico;
	char sexo;
	float tamanho;
	string dieta;
	int veterinario;
	int tratador;
	string batismo;
};