/**
* @file main.cpp
* @author Vinícius Ribeiro Bulcão
* @brief criaçao de um programa no qual simula um PetShop
* @since 18/06/2018
* @date 07/07/2018
*/
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <map>
#include "veterinario.h"
#include "anfibio.h"
#include "mamifero.h"
#include "reptil.h"
#include "ave.h"

using std::map;
using std::string;
using std::invalid_argument;
using namespace std;
/**
@brief Criado um template
@details O template tem o intuito de mudar qualquer parâmetro para string
*/
template <typename T>
string ToString ( T Number )
{
	std::stringstream ss;
	ss << Number;
	return ss.str();
}
/**
@brief Um tratamento de excessão 
@details Utilizado para quando houver um erro de inserção geral
*/
class ErroDeInsercao : public invalid_argument {
public:
ErroDeInsercao() : invalid_argument("Operacao invalida: Não digitado da maneira desejada") {}
};
/**
@brief Um tratamento de excessão 
@details Utilizado para quando houver um erro de inserção no Tipo sanguineo
*/
class ErroTipoSanguineo : public invalid_argument {
public:
ErroTipoSanguineo() : invalid_argument("Tipo sanguíneo inválido"){}
};
/**
@brief Um tratamento de excessão 
@details Utilizado para quando houver um erro na chamada do ID
*/
class ErroId : public invalid_argument {
public:
ErroId() : invalid_argument("ID inexistente"){}
};
/**
@brief Um tratamento de excessão 
@details Utilizado para quando houver um erro na chamada de um funcionário
*/
class ErroFuncionario : public invalid_argument {
public:
ErroFuncionario() : invalid_argument("Operacao invalida: Nenhum funcionário cadastrado") {}
};
/**
@brief Um tratamento de excessão 
@details Utilizado para quando houver um erro na chamada de um Animal
*/
class ErroAnimal : public invalid_argument {
public:
ErroAnimal() : invalid_argument("Operacao invalida: Nenhum Animal cadastrado") {}
};

/**
@brief Chamada do método showMenu1
*/
void showMenu1(int i){
/**
@brief Criação dos parâmetros int e string
@param int aux é um auxiliar para o menu
@param int controle_classe serve para controlar a entrada de classes no programa
@param int id_veterinario refere-se a um id no sistema
@param int id_funcionario refere-se a um id no sistema
@param int j é um controle para a classe funcionario e veterinario
@param string classe_ pergunta a classe para entrar no if
@param string print_stl printa a stl
*/
	int aux,controle_classe=0,id_veterinario,id_funcionario,j=0;
	string classe_,print_stl;
	cout << "Bem-Vindo ao PetShopMania" << endl;
/**
@brief Criação de ponteiros no qual apontarao para as classes criadas
*/
	Veterinario *veterinario;
	Anfibio *anfibio;
	Mamifero *mamifero;
	Reptil *reptil;
	Ave *ave;
/**
@brief Criação e Utilização da stl map, criada para o p = funcionario e animal = animal
*/
	map <int,string> p;
	map <int,string> animal;
	

	while(aux!=7){
	cout << "\nDigite o número do que deseja fazer" << endl;
	cout << "1 - Criar conta para funcionário" << endl;
	cout << "2 - Criar conta para Animal" << endl;
	cout << "3 - Consultar veterinario/tratador" << endl;
	cout << "4 - Consultar dados de um Animal" << endl;
	cout << "5 - Alterar dados de um Animal" << endl;
	cout << "6 - Remover um animal" << endl;
	cout << "7 - Para sair do programa" << endl;
	cin >> aux;
	
/**
@brief Caso for digitado 1 no sistema inicial, criar funcionario
*/
	if(aux == 1){
		j++;
		
		veterinario = new Veterinario[100];

		veterinario[j].SetId(j);
		cout << "Digite se é veterinario ou tratador" << endl;
		veterinario[j].SetProfissao();
		cout << "Digite o seu nome" << endl;
		veterinario[j].SetNome();
		cout << "Digite o seu CPF" << endl;
		veterinario[j].SetCPF();
		cout << "Digite sua idade" << endl;
		veterinario[j].SetIdade();
		cout << "Digite o seu Tipo sanguineo sem o fator RH(+/-)" << endl;
		veterinario[j].SetTipo();

		try{
			if(veterinario[j].GetTipo()!= "o" && veterinario[j].GetTipo()!= "a" && veterinario[j].GetTipo()!= "ab" && veterinario[j].GetTipo()!= "b") throw ErroTipoSanguineo();
		}catch(ErroTipoSanguineo &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o seu Fator RH[+/-]" << endl;
		veterinario[j].SetRH();

		try{
			if(veterinario[j].GetRH()!= "+" && veterinario[j].GetRH()!= "-") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite a sua especialidade" << endl;
		veterinario[j].SetEspec();
		veterinario[j].SetAnimaisSendoCuidados("nenhum",0);

		cout << "------------------------------------" << endl;

		cout << "Conta criada com sucesso" << endl;
	/** 
	@brief Convertendo inteiro para string 
		*/
		string resultIDADE = ToString(veterinario[j].GetIdade());
	/**
	@brief inserindo as informações na STL Map
	*/
		p.insert(pair<int,string>(j,"Cargo: "+veterinario[j].GetProfissao()+"\n"+"Nome: "+veterinario[j].GetNome()+"\n"+"CPF: "+veterinario[j].GetCPF()+"\n"+"Idade: "+resultIDADE+"\n"+"Tipo Sanguíneo: "+veterinario[j].GetTipo()+"\n"+"RH: "+veterinario[j].GetRH()+"\n"+"Especialidade: "+veterinario[j].GetEspec()));
		cout << "----------------------------------------"<< endl;
		cout<< "\nImpressão na stl"<< endl;
		cout <<"Id: "<<j<< "\n" << p[j]<< endl;
		cout << "----------------------------------------"<< endl;
	}

/**
@brief Caso for digitado 2 no sistema inicial, criar animal
*/
	if(aux== 2){
		i++;
		cout << "Digite se o animal é \n1-Anfibio\n2-Mamífero\n3-Réptil\n4-Ave" << endl;
		cin >> controle_classe;

		try{
			if(controle_classe!= 1 && controle_classe!= 2 && controle_classe!= 3 && controle_classe!= 4) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

/** 
@brief Caso o controle de classe for igual a 1
*/
	if(controle_classe==1){

		
		anfibio = new Anfibio[500];

		anfibio[i].SetId(i);
		cout << "Digite o nome do animal" << endl;
		anfibio[i].SetNome();
		cout << "Digite a sua classe" << endl;
		anfibio[i].SetClasse();
		cout << "Digite o nome cientifico" << endl;
		anfibio[i].SetCientifico();
		cout << "Digite o sexo do animal[m/f]" << endl;
		anfibio[i].SetSexo();

		try{
			if(anfibio[i].GetSexo()!= 'm' && anfibio[i].GetSexo()!= 'f') throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		anfibio[i].SetTamanho();
		cout << "Digite a dieta" << endl;
		anfibio[i].SetDieta();
		cout << "Digite se possui veterinario ou nao[1-Sim/0-Não]" << endl;
		anfibio[i].SetVeterinario();

		try{
			if(anfibio[i].GetVeterinario()!= 1 && anfibio[i].GetVeterinario()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(anfibio[i].GetVeterinario()==1){
			cout << "Digite o id do Veterinario" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(anfibio[i].GetClasse(), anfibio[i].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite se possui tratador ou nao[1-Sim/0-Não]" << endl;
		anfibio[i].SetTratador();
		if(anfibio[i].GetTratador()==1){

		try{
			if(anfibio[i].GetTratador()!= 1 && anfibio[i].GetTratador()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			cout << "Digite o id do Tratador" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(anfibio[i].GetClasse(), anfibio[i].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite o nome de batismo" << endl;
		anfibio[i].SetBatismo();
		cout << "Digite o total de mudas do animal" << endl;
		anfibio[i].SetTotal();

		cout << "-------------------------------------------" << endl;
		
		cout << "Conta criada com sucesso" << endl;
		/* @brief convertendo inteiro e char para string **/
		string resultVeterinario = ToString(anfibio[i].GetVeterinario());
		string resultTratador = ToString(anfibio[i].GetTratador());
		string resultTamanho = ToString(anfibio[i].GetTamanho());
		string resultMudas = ToString(anfibio[i].GetTotal());
		string resultSexo = ToString(anfibio[i].GetSexo());
		
		animal.insert(pair<int,string>(i,"Nome: "+anfibio[i].GetNome()+"\nClasse: "+anfibio[i].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+anfibio[i].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome de Batismo: "+anfibio[i].GetBatismo()+"\nMudas: "+resultMudas));
		
		cout<< "\nImpressão na stl"<< endl;
		cout << "Id: "<<i << "\n" << animal[i]<< endl;
		}
/** 
@brief Caso o controle de classe for igual a 2
*/
		if(controle_classe == 2){

		
		mamifero = new Mamifero[500];

		mamifero[i].SetId(i);
		cout << "Digite o nome do animal" << endl;
		mamifero[i].SetNome();
		cout << "Digite a sua classe" << endl;
		mamifero[i].SetClasse();
		cout << "Digite o nome cientifico" << endl;
		mamifero[i].SetCientifico();
		cout << "Digite o sexo do animal[m/f]" << endl;
		mamifero[i].SetSexo();

		try{
			if(mamifero[i].GetSexo()!= 'm' && mamifero[i].GetSexo()!= 'f') throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		mamifero[i].SetTamanho();
		cout << "Digite a dieta" << endl;
		mamifero[i].SetDieta();
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		mamifero[i].SetVeterinario();

		try{
			if(mamifero[i].GetVeterinario()!= 1 && mamifero[i].GetVeterinario()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(mamifero[i].GetVeterinario()==1){
			cout << "Digite o id do Veterinario" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(mamifero[i].GetClasse(), mamifero[i].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite se possui tratador ou nao[1/0]" << endl;
		mamifero[i].SetTratador();

		try{
			if(mamifero[i].GetTratador()!= 1 && mamifero[i].GetTratador()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(mamifero[i].GetTratador()==1){
			cout << "Digite o id do Tratador" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(mamifero[i].GetClasse(), mamifero[i].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite o nome de batismo" << endl;
		mamifero[i].SetBatismo();
		cout << "Informe a cor do pelo" << endl;
		mamifero[i].SetCorPelo();

		cout << "-------------------------------------------" << endl;
		
		cout << "Conta criada com sucesso" << endl;
		
	/** @brief tranformação de inteiro e char para string */
		string resultVeterinario = ToString(mamifero[i].GetVeterinario());
		string resultTratador = ToString(mamifero[i].GetTratador());
		string resultTamanho = ToString(mamifero[i].GetTamanho());
		string resultSexo = ToString(mamifero[i].GetSexo());
	/** @brief Inserção na stl */
		animal.insert(pair<int,string>(i,"Nome: "+mamifero[i].GetNome()+"\nClasse: "+mamifero[i].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+mamifero[i].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome de Batismo: "+mamifero[i].GetBatismo()+"\nCor: "+mamifero[i].GetCorPelo()));
		
		cout<< "\nImpressão na stl"<< endl;
		cout <<"Id: "<<i << "\n" << animal[i]<< endl;
		}

/** 
@brief Caso o controle de classe for igual a 3
*/
	if(controle_classe==3){

		
		reptil = new Reptil[500];

		reptil[i].SetId(i);
		cout << "Digite o nome do animal" << endl;
		reptil[i].SetNome();
		cout << "Digite a sua classe" << endl;
		reptil[i].SetClasse();
		cout << "Digite o nome cientifico" << endl;
		reptil[i].SetCientifico();
		cout << "Digite o sexo do animal[m/f]" << endl;
		reptil[i].SetSexo();

		try{
			if(reptil[i].GetSexo()!= 'm' && reptil[i].GetSexo()!= 'f') throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		reptil[i].SetTamanho();
		cout << "Digite a dieta" << endl;
		reptil[i].SetDieta();
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		reptil[i].SetVeterinario();

		try{
			if(reptil[i].GetVeterinario()!= 1 && reptil[i].GetVeterinario()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(reptil[i].GetVeterinario()==1){
			cout << "Digite o id do Veterinario" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(reptil[i].GetClasse(), reptil[i].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite se possui tratador ou nao[1/0]" << endl;
		reptil[i].SetTratador();

		try{
			if(reptil[i].GetTratador()!= 1 && reptil[i].GetTratador()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(reptil[i].GetTratador()==1){
			cout << "Digite o id do Tratador" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(reptil[i].GetClasse(), reptil[i].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite o nome de batismo" << endl;
		reptil[i].SetBatismo();
		cout << "Informe se é venenoso ou não[1-sim/0-não]" << endl;
		reptil[i].SetVenenoso();

		try{
			if(reptil[i].GetVenenoso()!= 1 && reptil[i].GetVenenoso()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(reptil[i].GetVenenoso()==1){
			cout << "Agora informe o tipo do veneno" << endl;
			reptil[i].SetTipoVeneno();
		}

		cout << "-------------------------------------------" << endl;
		
		if(reptil[i].GetVenenoso()==1){
			cout << "É venenoso" << endl;
			cout << "Veneno: " << reptil[i].GetTipoVeneno() << endl;
		}
		else if(reptil[i].GetVenenoso()==0)
			cout << "Não é venenoso" << endl;

		cout << "Conta criada com sucesso" << endl;
		/* @brief tranformação de inteiro e char para string **/
		string resultVeterinario = ToString(reptil[i].GetVeterinario());
		string resultTratador = ToString(reptil[i].GetTratador());
		string resultTamanho = ToString(reptil[i].GetTamanho());
		string resultSexo = ToString(reptil[i].GetSexo());
		string resultVeneno = ToString(reptil[i].GetVenenoso());
		
		animal.insert(pair<int,string>(i,"Nome: "+reptil[i].GetNome()+"\nClasse: "+reptil[i].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+reptil[i].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome de Batismo: "+reptil[i].GetBatismo()+"\nVenenoso: "+resultVeneno+"\nTipo do Veneno: "+reptil[i].GetTipoVeneno()));
		
		cout<< "\nImpressão na stl"<< endl;
		cout <<"Id: "<<i << "\n" << animal[i]<< endl;
		}
/** 
@brief Caso o controle de classe for igual a 4
*/
	if(controle_classe == 4){

		
		ave = new Ave[500];

		ave[i].SetId(i);
		cout << "Digite o nome do animal" << endl;
		ave[i].SetNome();
		cout << "Digite a sua classe" << endl;
		ave[i].SetClasse();
		cout << "Digite o nome cientifico" << endl;
		ave[i].SetCientifico();
		cout << "Digite o sexo do animal[m/f]" << endl;
		ave[i].SetSexo();

		try{
			if(ave[i].GetSexo()!= 'm' && ave[i].GetSexo()!= 'f') throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		ave[i].SetTamanho();
		cout << "Digite a dieta" << endl;
		ave[i].SetDieta();
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		ave[i].SetVeterinario();

		try{
			if(ave[i].GetVeterinario()!= 1 && ave[i].GetVeterinario()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(ave[i].GetVeterinario()==1){
			cout << "Digite o id do Veterinario" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(ave[i].GetClasse(), ave[i].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite se possui tratador ou nao[1/0]" << endl;
		ave[i].SetTratador();

		try{
			if(ave[i].GetTratador()!= 1 && ave[i].GetTratador()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(ave[i].GetTratador()==1){
			cout << "Digite o id do Tratador" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(ave[i].GetClasse(), ave[i].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite o nome de batismo" << endl;
		ave[i].SetBatismo();
		cout << "Digite o tamanho do bico" << endl;
		ave[i].SetTamanhoBico();
		cout << "Digite a envergadura da ave" << endl;
		ave[i].SetEnvergadura();

		cout << "-------------------------------------------" << endl;
		
		cout << "Conta criada com sucesso" << endl;
		/* @brief tranformação de inteiro e char para string **/
		string resultVeterinario = ToString(ave[i].GetVeterinario());
		string resultTratador = ToString(ave[i].GetTratador());
		string resultTamanho = ToString(ave[i].GetTamanho());
		string resultSexo = ToString(ave[i].GetSexo());
		string resultTamanhoBico = ToString(ave[i].GetTamanhoBico());
		string resultEnvergadura = ToString(ave[i].GetEnvergadura());

		cout << "\nSaída por uma STL(MAP)" << endl;
		
		animal.insert(pair<int,string>(i,"Nome: "+ave[i].GetNome()+"\nClasse: "+ave[i].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+ave[i].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome do Batismo: "+ave[i].GetBatismo()+"\nTamanho do Bico: "+resultTamanhoBico+"\nEnvergadura: "+resultEnvergadura));
		
		cout<< "\nImpressão na stl"<< endl;
		cout <<"Id: "<<i << "\n" << animal[i]<< endl;
		}
	}

/**
@brief Caso for digitado 3 no sistema inicial, Consultar funcionário
*/
	if(aux==3){
		try{
			if(j==0) throw ErroFuncionario();
		}catch(ErroFuncionario &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Deseja consultar que funcionário? digite o ID: "<< endl;
		cin >> id_funcionario;

		try{
			if(id_funcionario>j) throw ErroFuncionario();
		}catch(ErroFuncionario &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}


		cout<< "\nImpressão na stl"<< endl;
		cout <<id_funcionario << "\n" << p[id_funcionario]<< endl;
	}

/**
@brief Caso for digitado 4 no sistema inicial, consultar animal
*/

	if(aux==4){
		try{
			if(i==0) throw ErroAnimal();
		}catch(ErroAnimal &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}
		cout << "Deseja consultar que Animal, digite o ID: "<< endl;
		cin >> id_funcionario;
	
		cout << "-------------------------------------------" << endl;
		cout<< "\nImpressão na stl"<< endl;
		cout <<"Id: "<<id_funcionario << "\n" << animal[id_funcionario]<< endl;
		cout << "-------------------------------------------" << endl;
	}

/**
@brief Caso for digitado 2 no sistema inicial, alterar dados do animal
*/

	if(aux==5){

		try{
			if(i==0) throw ErroAnimal();
		}catch(ErroAnimal &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Para alterar os dados de um animal informe seu ID: " << endl;
		cin >> id_funcionario;
		cout << "Agora informe sua a classe do animal" << endl;
		cin >> classe_;

if(classe_=="anfibio"){
		anfibio = new Anfibio[500];

		cout << "Digite o nome do animal" << endl;
		anfibio[id_funcionario].SetNome();
		cout << "Digite a sua classe" << endl;
		anfibio[id_funcionario].SetClasse();
		cout << "Digite o nome cientifico" << endl;
		anfibio[id_funcionario].SetCientifico();
		cout << "Digite o sexo do animal[m/f]" << endl;
		anfibio[id_funcionario].SetSexo();

		try{
			if(anfibio[id_funcionario].GetSexo()!= 'm' && anfibio[id_funcionario].GetSexo()!= 'f') throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		anfibio[id_funcionario].SetTamanho();
		cout << "Digite a dieta" << endl;
		anfibio[id_funcionario].SetDieta();
		cout << "Digite se possui veterinario ou nao[1-Sim/0-Não]" << endl;
		anfibio[id_funcionario].SetVeterinario();

		try{
			if(anfibio[id_funcionario].GetVeterinario()!= 1 && anfibio[id_funcionario].GetVeterinario()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(anfibio[id_funcionario].GetVeterinario()==1){
			cout << "Digite o id do Veterinario" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(anfibio[id_funcionario].GetClasse(), anfibio[id_funcionario].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite se possui tratador ou nao[1-Sim/0-Não]" << endl;
		anfibio[id_funcionario].SetTratador();
		if(anfibio[id_funcionario].GetTratador()==1){

		try{
			if(anfibio[id_funcionario].GetTratador()!= 1 && anfibio[id_funcionario].GetTratador()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			cout << "Digite o id do Tratador" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(anfibio[id_funcionario].GetClasse(), anfibio[id_funcionario].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite o nome de batismo" << endl;
		anfibio[id_funcionario].SetBatismo();
		cout << "Digite o total de mudas do animal" << endl;
		anfibio[id_funcionario].SetTotal();

		cout << "Conta alterada com sucesso" << endl;
		/* @brief convertendo inteiro e char para string **/
		string resultVeterinario = ToString(anfibio[id_funcionario].GetVeterinario());
		string resultTratador = ToString(anfibio[id_funcionario].GetTratador());
		string resultTamanho = ToString(anfibio[id_funcionario].GetTamanho());
		string resultMudas = ToString(anfibio[id_funcionario].GetTotal());
		string resultSexo = ToString(anfibio[id_funcionario].GetSexo());

		cout << "\nSaída por uma STL(MAP)" << endl;
		animal.erase(id_funcionario);
		animal.insert(pair<int,string>(id_funcionario,"Nome: "+anfibio[id_funcionario].GetNome()+"\nClasse: "+anfibio[id_funcionario].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+anfibio[id_funcionario].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome de Batismo: "+anfibio[id_funcionario].GetBatismo()+"\nMudas: "+resultMudas));
		cout << "-------------------------------------------" << endl;
		cout<< "\nImpressão na stl"<< endl;
		cout << "Id: "<<id_funcionario << "\n" << animal[id_funcionario]<< endl;
		cout << "-------------------------------------------" << endl;
		}

else if(classe_=="mamifero"){
		mamifero = new Mamifero[500];
		cout << "Digite o nome do animal" << endl;
		mamifero[id_funcionario].SetNome();
		cout << "Digite a sua classe" << endl;
		mamifero[id_funcionario].SetClasse();
		cout << "Digite o nome cientifico" << endl;
		mamifero[id_funcionario].SetCientifico();
		cout << "Digite o sexo do animal[m/f]" << endl;
		mamifero[id_funcionario].SetSexo();

		try{
			if(mamifero[id_funcionario].GetSexo()!= 'm' && mamifero[id_funcionario].GetSexo()!= 'f') throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		mamifero[id_funcionario].SetTamanho();
		cout << "Digite a dieta" << endl;
		mamifero[id_funcionario].SetDieta();
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		mamifero[id_funcionario].SetVeterinario();

		try{
			if(mamifero[id_funcionario].GetVeterinario()!= 1 && mamifero[id_funcionario].GetVeterinario()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(mamifero[id_funcionario].GetVeterinario()==1){
			cout << "Digite o id do Veterinario" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(mamifero[id_funcionario].GetClasse(), mamifero[id_funcionario].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite se possui tratador ou nao[1/0]" << endl;
		mamifero[id_funcionario].SetTratador();

		try{
			if(mamifero[id_funcionario].GetTratador()!= 1 && mamifero[id_funcionario].GetTratador()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(mamifero[id_funcionario].GetTratador()==1){
			cout << "Digite o id do Tratador" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(mamifero[id_funcionario].GetClasse(), mamifero[id_funcionario].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite o nome de batismo" << endl;
		mamifero[id_funcionario].SetBatismo();
		cout << "Informe a cor do pelo" << endl;
		mamifero[id_funcionario].SetCorPelo();

		cout << "Conta alterada com sucesso" << endl;
		
		/* @brief tranformação de inteiro e char para string **/
		string resultVeterinario = ToString(mamifero[id_funcionario].GetVeterinario());
		string resultTratador = ToString(mamifero[id_funcionario].GetTratador());
		string resultTamanho = ToString(mamifero[id_funcionario].GetTamanho());
		string resultSexo = ToString(mamifero[id_funcionario].GetSexo());

		cout << "\nSaída por uma STL(MAP)" << endl;
		animal.erase(id_funcionario);
		animal.insert(pair<int,string>(id_funcionario,"Nome: "+mamifero[id_funcionario].GetNome()+"\nClasse: "+mamifero[id_funcionario].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+mamifero[id_funcionario].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome de Batismo: "+mamifero[id_funcionario].GetBatismo()+"\nCor: "+mamifero[id_funcionario].GetCorPelo()));
		cout << "-------------------------------------------" << endl;
		cout<< "\nImpressão na stl"<< endl;
		cout <<"Id: "<<id_funcionario << "\n" << animal[id_funcionario]<< endl;
		cout << "-------------------------------------------" << endl;
		}


else if(classe_=="reptil"){
		reptil = new Reptil[500];
		cout << "Digite o nome do animal" << endl;
		reptil[id_funcionario].SetNome();
		cout << "Digite a sua classe" << endl;
		reptil[id_funcionario].SetClasse();
		cout << "Digite o nome cientifico" << endl;
		reptil[id_funcionario].SetCientifico();
		cout << "Digite o sexo do animal[m/f]" << endl;
		reptil[id_funcionario].SetSexo();

		try{
			if(reptil[id_funcionario].GetSexo()!= 'm' && reptil[id_funcionario].GetSexo()!= 'f') throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		reptil[id_funcionario].SetTamanho();
		cout << "Digite a dieta" << endl;
		reptil[id_funcionario].SetDieta();
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		reptil[id_funcionario].SetVeterinario();

		try{
			if(reptil[id_funcionario].GetVeterinario()!= 1 && reptil[id_funcionario].GetVeterinario()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(reptil[id_funcionario].GetVeterinario()==1){
			cout << "Digite o id do Veterinario" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(reptil[id_funcionario].GetClasse(), reptil[id_funcionario].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite se possui tratador ou nao[1/0]" << endl;
		reptil[id_funcionario].SetTratador();

		try{
			if(reptil[id_funcionario].GetTratador()!= 1 && reptil[id_funcionario].GetTratador()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(reptil[id_funcionario].GetTratador()==1){
			cout << "Digite o id do Tratador" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(reptil[id_funcionario].GetClasse(), reptil[id_funcionario].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite o nome de batismo" << endl;
		reptil[id_funcionario].SetBatismo();
		cout << "Informe se é venenoso ou não[1-sim/0-não]" << endl;
		reptil[id_funcionario].SetVenenoso();

		try{
			if(reptil[id_funcionario].GetVenenoso()!= 1 && reptil[id_funcionario].GetVenenoso()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(reptil[id_funcionario].GetVenenoso()==1){
			cout << "Agora informe o tipo do veneno" << endl;
			reptil[id_funcionario].SetTipoVeneno();
		}

		cout << "Conta alterada com sucesso" << endl;
		/* @brief tranformação de inteiro e char para string **/
		string resultVeterinario = ToString(reptil[id_funcionario].GetVeterinario());
		string resultTratador = ToString(reptil[id_funcionario].GetTratador());
		string resultTamanho = ToString(reptil[id_funcionario].GetTamanho());
		string resultSexo = ToString(reptil[id_funcionario].GetSexo());
		string resultVeneno = ToString(reptil[id_funcionario].GetVenenoso());

		cout << "\nSaída por uma STL(MAP)" << endl;
		animal.erase(id_funcionario);
		animal.insert(pair<int,string>(id_funcionario,"Nome: "+reptil[id_funcionario].GetNome()+"\nClasse: "+reptil[id_funcionario].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+reptil[id_funcionario].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome de Batismo: "+reptil[id_funcionario].GetBatismo()+"\nVenenoso: "+resultVeneno+"\nTipo do Veneno: "+reptil[id_funcionario].GetTipoVeneno()));
		cout << "-------------------------------------------" << endl;
		cout<< "\nImpressão na stl"<< endl;
		cout <<"Id: "<<id_funcionario << "\n" << animal[id_funcionario]<< endl;
		cout << "-------------------------------------------" << endl;
		}


else if(classe_=="ave"){
		ave = new Ave[500];
		cout << "Digite o nome do animal" << endl;
		ave[id_funcionario].SetNome();
		cout << "Digite a sua classe" << endl;
		ave[id_funcionario].SetClasse();
		cout << "Digite o nome cientifico" << endl;
		ave[id_funcionario].SetCientifico();
		cout << "Digite o sexo do animal[m/f]" << endl;
		ave[id_funcionario].SetSexo();

		try{
			if(ave[id_funcionario].GetSexo()!= 'm' && ave[id_funcionario].GetSexo()!= 'f') throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		ave[id_funcionario].SetTamanho();
		cout << "Digite a dieta" << endl;
		ave[id_funcionario].SetDieta();
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		ave[id_funcionario].SetVeterinario();

		try{
			if(ave[id_funcionario].GetVeterinario()!= 1 && ave[id_funcionario].GetVeterinario()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(ave[id_funcionario].GetVeterinario()==1){
			cout << "Digite o id do Veterinario" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(ave[id_funcionario].GetClasse(), ave[id_funcionario].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite se possui tratador ou nao[1/0]" << endl;
		ave[id_funcionario].SetTratador();

		try{
			if(ave[id_funcionario].GetTratador()!= 1 && ave[id_funcionario].GetTratador()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(ave[id_funcionario].GetTratador()==1){
			cout << "Digite o id do Tratador" << endl;
			cin >> id_veterinario;

			try{
			if(id_veterinario> j) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

			veterinario[id_veterinario].SetAnimaisSendoCuidados(ave[id_funcionario].GetClasse(), ave[id_funcionario].GetId());
			veterinario[id_veterinario].GetAnimaisSendoCuidados();
		}
		cout << "Digite o nome de batismo" << endl;
		ave[id_funcionario].SetBatismo();
		cout << "Digite o tamanho do bico" << endl;
		ave[id_funcionario].SetTamanhoBico();
		cout << "Digite a envergadura da ave" << endl;
		ave[id_funcionario].SetEnvergadura();
		cout << "Conta alterada com sucesso" << endl;
		/* @brief tranformação de inteiro e char para string **/
		string resultVeterinario = ToString(ave[id_funcionario].GetVeterinario());
		string resultTratador = ToString(ave[id_funcionario].GetTratador());
		string resultTamanho = ToString(ave[id_funcionario].GetTamanho());
		string resultSexo = ToString(ave[id_funcionario].GetSexo());
		string resultTamanhoBico = ToString(ave[id_funcionario].GetTamanhoBico());
		string resultEnvergadura = ToString(ave[id_funcionario].GetEnvergadura());

		cout << "\nSaída por uma STL(MAP)" << endl;
		animal.erase(id_funcionario);
		animal.insert(pair<int,string>(id_funcionario,"Nome: "+ave[id_funcionario].GetNome()+"\nClasse: "+ave[id_funcionario].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+ave[id_funcionario].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome do Batismo: "+ave[id_funcionario].GetBatismo()+"\nTamanho do Bico: "+resultTamanhoBico+"\nEnvergadura: "+resultEnvergadura));
		cout << "-------------------------------------------" << endl;
		cout<< "\nImpressão na stl"<< endl;
		cout <<"Id: "<<id_funcionario << "\n" << animal[id_funcionario]<< endl;
		cout << "-------------------------------------------" << endl;
	}
	}


/**
@brief Caso for digitado 6 no sistema inicial, deletar algum animal
*/


	if(aux==6){
		try{
			if(i==0) throw ErroAnimal();
		}catch(ErroAnimal &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}
		cout << "Qual animal deseja deletar, digite seu Id: " << endl;
		cin >> id_funcionario;
		try{
			if(id_funcionario> i) throw ErroId();
		}catch(ErroId &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}
		animal.erase(id_funcionario);
		
	}

/**
@brief Caso for digitado 7 no sistema inicial, sair do programa
*/

	if(aux==7){
		exit(0);
	}
}
}
