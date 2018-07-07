/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#include <string>
using std::string;
/**
@brief Criação da classe funcionário
*/
class funcionario
{
protected:
/**
@brief Criação dos parâmetros da classe funcionário
@param int id serve para guardar o ID do funcionário
@param string nome para guardar o nome
@param string cpf para guardar o cpf
@param int idade para guardar a idade
@param string tipo_sanguineo para guardar o tipo sanguineo
@param string fatorRH para guardar o RH 
@param string especialidade para guardar a especialidade do funcionário
*/
	int id;
	string nome;
	string cpf;
	int idade;
	string tipo_sanguineo;
	string fatorRH;
	string especialidade;
};