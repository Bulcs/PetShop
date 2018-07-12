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
#include <string>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <map>
#include <bits/stdc++.h>
#include "veterinario.h"
#include "anfibio.h"
#include "mamifero.h"
#include "reptil.h"
#include "ave.h"

using std::map;
using std::string;
using std::invalid_argument;
using std::ostringstream;
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
	int aux,controle_classe=0,id_veterinario,id_funcionario,j=0,cont_anfibio=0,cont_mamifero=0,cont_reptil=0,cont_ave=0,auxiliar_func=0;
	string classe_,print_stl;
	char cont_arquivo;
	cout << "Bem-Vindo ao PetShopMania" << endl;
/**
	@brief parâmetros funcionário
*/
	string profissao,nome,cpf,tipo,rh,espec,idade;

/**
	@brief parâmetros animais
*/
	string nome_animal,cientifico,dieta,batismo,cor,tipo_veneno,classe_animal,cont_veterinario,cont_tratador,total,venenoso,tamanho,tamanho_bico,envergadura,sexo;
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
	
	inicio:
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
		auxiliar_func++;
		
		veterinario = new Veterinario[100];

		cout << "Deseja usar arquivo CSV ou não?[s/n]"<< endl;
		cin >> cont_arquivo;
		veterinario[j].SetId(j);
		if(cont_arquivo == 's'){

			ifstream ip("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/funcionarioIn.csv");
			if(!ip.is_open()) cout << "Erro: File " << endl;
			while(ip.good()){
				getline(ip,profissao,';');
				getline(ip,nome,';');
				getline(ip,cpf,';');
				getline(ip,idade,';');
				getline(ip,tipo,';');
				getline(ip,rh,';');
				getline(ip,espec,'\n');
			
				veterinario[j].SetProfissao(profissao);
				veterinario[j].SetNome(nome);
				veterinario[j].SetCPF(cpf);
				veterinario[j].SetIdade(idade);
				veterinario[j].SetTipo(tipo);
				veterinario[j].SetRH(rh);
				veterinario[j].SetEspec(espec);
				veterinario[j].SetAnimaisSendoCuidados("nenhum",0);
			}
	/**
	@brief inserindo as informações na STL Map
	*/
		p.insert(pair<int,string>(j,"Cargo: "+veterinario[j].GetProfissao()+"\n"+"Nome: "+veterinario[j].GetNome()+"\n"+"CPF: "+veterinario[j].GetCPF()+"\n"+"Idade: "+veterinario[j].GetIdade()+"\n"+"Tipo Sanguíneo: "+veterinario[j].GetTipo()+"\n"+"RH: "+veterinario[j].GetRH()+"\n"+"Especialidade: "+veterinario[j].GetEspec()));
		cout << "----------------------------------------"<< endl;
		cout<< "\nImpressão na stl"<< endl;
		cout << veterinario[j];
		cout << "----------------------------------------"<< endl;

			ip.close();

			ofstream op;

			op.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/funcionarioOut.csv");

			op << j << ";"<<veterinario[j].GetProfissao()<<";"<<veterinario[j].GetNome()<<";"<<veterinario[j].GetCPF()<<";"<<veterinario[j].GetIdade()<<";"<<veterinario[j].GetTipo()<<";"<<veterinario[j].GetRH()<<";"<<veterinario[j].GetEspec()<<endl;

			op.close();

		}
		else if (cont_arquivo=='n'){
		cout << "Digite se é veterinario ou tratador" << endl;
		cin>>profissao;
		veterinario[j].SetProfissao(profissao);
		cout << "Digite o seu nome" << endl;
		cin>>nome;
		veterinario[j].SetNome(nome);
		cout << "Digite o seu CPF" << endl;
		cin>>cpf;
		veterinario[j].SetCPF(cpf);
		cout << "Digite sua idade" << endl;
		cin>>idade;
		veterinario[j].SetIdade(idade);
		cout << "Digite o seu Tipo sanguineo sem o fator RH(+/-)" << endl;
		cin>>tipo;
		veterinario[j].SetTipo(tipo);

		try{
			if(veterinario[j].GetTipo()!= "o" && veterinario[j].GetTipo()!= "a" && veterinario[j].GetTipo()!= "ab" && veterinario[j].GetTipo()!= "b") throw ErroTipoSanguineo();
		}catch(ErroTipoSanguineo &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o seu Fator RH[+/-]" << endl;
		cin>>rh;
		veterinario[j].SetRH(rh);

		try{
			if(veterinario[j].GetRH()!= "+" && veterinario[j].GetRH()!= "-") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite a sua especialidade" << endl;
		cin>>espec;
		veterinario[j].SetEspec(espec);
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
		
		ofstream op;

			op.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/funcionarioOut.csv");

			op << j << ";"<<veterinario[j].GetProfissao()<<";"<<veterinario[j].GetNome()<<";"<<veterinario[j].GetCPF()<<";"<<veterinario[j].GetIdade()<<";"<<veterinario[j].GetTipo()<<";"<<veterinario[j].GetRH()<<";"<<veterinario[j].GetEspec()<<endl;

			op.close();

		}	
	}

/**
@brief Caso for digitado 2 no sistema inicial, criar animal
*/
	if(aux== 2){
		i++;

		cout << "Deseja usar arquivo CSV ou não?[s/n]"<< endl;
		cin >> cont_arquivo;
		if(cont_arquivo == 's'){

			ifstream animaisIn("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalIn.csv");
			if(!animaisIn.is_open()) cout << "Erro: File " << endl;
			while(animaisIn.good()){
				getline(animaisIn,nome_animal,';');
				getline(animaisIn,classe_animal,';');
				getline(animaisIn,cientifico,';');
				getline(animaisIn,sexo,';');
				getline(animaisIn,tamanho,';');
				getline(animaisIn,dieta,';');
				getline(animaisIn,cont_veterinario,';');
				getline(animaisIn,cont_tratador,';');
				getline(animaisIn,batismo,';');
				if(classe_animal=="anfibio"){
					getline(animaisIn,total,'\n');

				float tamanho_ = atoi(tamanho.c_str());
				int cont_veterinario_ = atoi(cont_veterinario.c_str());
				int cont_tratador_ = atoi(cont_tratador.c_str());
				int total_ = atoi(total.c_str());

				anfibio = new Anfibio[500];
				cont_anfibio++;
				anfibio[i].SetId(i);
				anfibio[i].SetClasse(classe_animal);
				anfibio[i].SetNome(nome_animal);
				anfibio[i].SetCientifico(cientifico);
				anfibio[i].SetSexo(sexo);
				anfibio[i].SetTamanho(tamanho_);
				anfibio[i].SetDieta(dieta);
				anfibio[i].SetVeterinario(cont_veterinario_);
				anfibio[i].SetTratador(cont_tratador_);
				anfibio[i].SetBatismo(batismo);
				anfibio[i].SetTotal(total_);

				string resultVeterinario = ToString(anfibio[i].GetVeterinario());
				string resultTratador = ToString(anfibio[i].GetTratador());
				string resultTamanho = ToString(anfibio[i].GetTamanho());
				string resultMudas = ToString(anfibio[i].GetTotal());
				string resultSexo = ToString(anfibio[i].GetSexo());
				
				animal.insert(pair<int,string>(i,"Nome: "+anfibio[i].GetNome()+"\nClasse: "+anfibio[i].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+anfibio[i].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome de Batismo: "+anfibio[i].GetBatismo()+"\nMudas: "+resultMudas));
				
				cout<< "\nImpressão na stl"<< endl;
				cout << "Id: "<<i << "\n" << animal[i]<< endl;

				animaisIn.close();

				ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<anfibio[i].GetNome()<<";"<<anfibio[i].GetClasse()<<";"<<anfibio[i].GetCientifico()<<";"<<anfibio[i].GetSexo()<<";"<<anfibio[i].GetTamanho()<<";"<<anfibio[i].GetDieta()<<";"<<anfibio[i].GetVeterinario()<<";"<<anfibio[i].GetTratador()<<";"<<anfibio[i].GetBatismo()<<";"<<anfibio[i].GetTotal()<<endl;

				animalOut.close();

				}else if(classe_animal=="mamifero"){
					getline(animaisIn,cor,'\n');

				float tamanho_ = atoi(tamanho.c_str());
				int cont_veterinario_ = atoi(cont_veterinario.c_str());
				int cont_tratador_ = atoi(cont_tratador.c_str());

				mamifero = new Mamifero[500];
				cont_mamifero++;
				mamifero[i].SetId(i);
				mamifero[i].SetClasse(classe_animal);
				mamifero[i].SetNome(nome_animal);
				mamifero[i].SetCientifico(cientifico);
				mamifero[i].SetSexo(sexo);
				mamifero[i].SetTamanho(tamanho_);
				mamifero[i].SetDieta(dieta);
				mamifero[i].SetVeterinario(cont_veterinario_);
				mamifero[i].SetTratador(cont_tratador_);
				mamifero[i].SetBatismo(batismo);
				mamifero[i].SetCorPelo(cor);

				/** @brief tranformação de inteiro e char para string */
				string resultVeterinario = ToString(mamifero[i].GetVeterinario());
				string resultTratador = ToString(mamifero[i].GetTratador());
				string resultTamanho = ToString(mamifero[i].GetTamanho());
				string resultSexo = ToString(mamifero[i].GetSexo());
			/** @brief Inserção na stl */
				animal.insert(pair<int,string>(i,"Nome: "+mamifero[i].GetNome()+"\nClasse: "+mamifero[i].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+mamifero[i].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome de Batismo: "+mamifero[i].GetBatismo()+"\nCor: "+mamifero[i].GetCorPelo()));
				
				cout<< "\nImpressão na stl"<< endl;
				cout <<"Id: "<<i << "\n" << animal[i]<< endl;

				animaisIn.close();

				ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<mamifero[i].GetNome()<<";"<<mamifero[i].GetClasse()<<";"<<mamifero[i].GetCientifico()<<";"<<mamifero[i].GetSexo()<<";"<<mamifero[i].GetTamanho()<<";"<<mamifero[i].GetDieta()<<";"<<mamifero[i].GetVeterinario()<<";"<<mamifero[i].GetTratador()<<";"<<mamifero[i].GetBatismo()<<";"<<mamifero[i].GetCorPelo()<<endl;

				animalOut.close();

				}else if(classe_animal=="reptil"){
					getline(animaisIn,venenoso,';');
					getline(animaisIn,tipo_veneno,'\n');

					float tamanho_ = atoi(tamanho.c_str());
					int cont_veterinario_ = atoi(cont_veterinario.c_str());
					int cont_tratador_ = atoi(cont_tratador.c_str());
					int venenoso_ = atoi(venenoso.c_str());

				reptil = new Reptil[500];
				cont_reptil++;

				reptil[i].SetId(i);
				reptil[i].SetClasse(classe_animal);
				reptil[i].SetNome(nome_animal);
				reptil[i].SetCientifico(cientifico);
				reptil[i].SetSexo(sexo);
				reptil[i].SetTamanho(tamanho_);
				reptil[i].SetDieta(dieta);
				reptil[i].SetVeterinario(cont_veterinario_);
				reptil[i].SetTratador(cont_tratador_);
				reptil[i].SetBatismo(batismo);
				reptil[i].SetVenenoso(venenoso_);
				reptil[i].SetTipoVeneno(tipo_veneno);

				string resultVeterinario = ToString(reptil[i].GetVeterinario());
				string resultTratador = ToString(reptil[i].GetTratador());
				string resultTamanho = ToString(reptil[i].GetTamanho());
				string resultSexo = ToString(reptil[i].GetSexo());
				string resultVeneno = ToString(reptil[i].GetVenenoso());
				
				animal.insert(pair<int,string>(i,"Nome: "+reptil[i].GetNome()+"\nClasse: "+reptil[i].GetClasse()+"\nSexo: "+resultSexo+"\nTamanho: "+resultTamanho+"\nDieta: "+reptil[i].GetDieta()+"\nVeterinario: "+resultVeterinario+"\nTratador: "+resultTratador+"\nNome de Batismo: "+reptil[i].GetBatismo()+"\nVenenoso: "+resultVeneno+"\nTipo do Veneno: "+reptil[i].GetTipoVeneno()));
				
				cout<< "\nImpressão na stl"<< endl;
				cout <<"Id: "<<i << "\n" << animal[i]<< endl;

				animaisIn.close();

				ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<reptil[i].GetNome()<<";"<<reptil[i].GetClasse()<<";"<<reptil[i].GetCientifico()<<";"<<reptil[i].GetSexo()<<";"<<reptil[i].GetTamanho()<<";"<<reptil[i].GetDieta()<<";"<<reptil[i].GetVeterinario()<<";"<<reptil[i].GetTratador()<<";"<<reptil[i].GetBatismo()<<";"<<reptil[i].GetVenenoso()<<";"<<reptil[i].GetTipoVeneno()<<endl;

				animalOut.close();

				}else if(classe_animal=="ave"){
					getline(animaisIn,tamanho_bico,';');
					getline(animaisIn,envergadura,'\n');

					float tamanho_ = atoi(tamanho.c_str());
					int cont_veterinario_ = atoi(cont_veterinario.c_str());
					int cont_tratador_ = atoi(cont_tratador.c_str());
					float tamanho_bico_ = atoi(tamanho_bico.c_str());
					float envergadura_ = atoi(envergadura.c_str());

				ave = new Ave[500];
				cont_ave++;
				ave[i].SetId(i);
				ave[i].SetClasse(classe_animal);
				ave[i].SetNome(nome_animal);
				ave[i].SetCientifico(cientifico);
				ave[i].SetSexo(sexo);
				ave[i].SetTamanho(tamanho_);
				ave[i].SetDieta(dieta);
				ave[i].SetVeterinario(cont_veterinario_);
				ave[i].SetTratador(cont_tratador_);
				ave[i].SetBatismo(batismo);
				ave[i].SetTamanhoBico(tamanho_bico_);
				ave[i].SetEnvergadura(envergadura_);

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

				animaisIn.close();

				ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<ave[i].GetNome()<<";"<<ave[i].GetClasse()<<";"<<ave[i].GetCientifico()<<";"<<ave[i].GetSexo()<<";"<<ave[i].GetTamanho()<<";"<<ave[i].GetDieta()<<";"<<ave[i].GetVeterinario()<<";"<<ave[i].GetTratador()<<";"<<ave[i].GetBatismo()<<";"<<ave[i].GetTamanhoBico()<<";"<<ave[i].GetEnvergadura()<<endl;

				animalOut.close();

				}
				
			}
			}else if(cont_arquivo=='n'){

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
		cont_anfibio++;

		anfibio[i].SetId(i);
		cout << "Digite o nome do animal" << endl;
		cin >> nome_animal;
		anfibio[i].SetNome(nome_animal);
		anfibio[i].SetClasse("anfibio");
		cout << "Digite o nome cientifico" << endl;
		cin >> cientifico;
		anfibio[i].SetCientifico(cientifico);
		cout << "Digite o sexo do animal[m/f]" << endl;
		cin >> sexo;
		anfibio[i].SetSexo(sexo);

		try{
			if(anfibio[i].GetSexo()!= "m" && anfibio[i].GetSexo()!= "f") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		cin >> tamanho;
		float tamanho_ = atoi(tamanho.c_str());
		anfibio[i].SetTamanho(tamanho_);
		cout << "Digite a dieta" << endl;
		cin >> dieta;
		anfibio[i].SetDieta(dieta);
		cout << "Digite se possui veterinario ou nao[1-Sim/0-Não]" << endl;
		cin >> cont_veterinario;
		int cont_veterinario_ = atoi(cont_veterinario.c_str());
		anfibio[i].SetVeterinario(cont_veterinario_);

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
		cin >> cont_tratador;
		int cont_tratador_ = atoi(cont_tratador.c_str());
		anfibio[i].SetTratador(cont_tratador_);
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
		cin >> batismo;
		anfibio[i].SetBatismo(batismo);
		cout << "Digite o total de mudas do animal" << endl;
		cin >> total;
		int total_ = atoi(total.c_str());
		anfibio[i].SetTotal(total_);

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

		ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<anfibio[i].GetNome()<<";"<<anfibio[i].GetClasse()<<";"<<anfibio[i].GetCientifico()<<";"<<anfibio[i].GetSexo()<<";"<<anfibio[i].GetTamanho()<<";"<<anfibio[i].GetDieta()<<";"<<anfibio[i].GetVeterinario()<<";"<<anfibio[i].GetTratador()<<";"<<anfibio[i].GetBatismo()<<";"<<anfibio[i].GetTotal()<<endl;

				animalOut.close();

		}
/** 
@brief Caso o controle de classe for igual a 2
*/
		if(controle_classe == 2){

		
		mamifero = new Mamifero[500];
		cont_mamifero++;

		mamifero[i].SetId(i);
		cout << "Digite o nome do animal" << endl;
		cin >> nome;
		mamifero[i].SetNome(nome);
		mamifero[i].SetClasse("mamifero");
		cout << "Digite o nome cientifico" << endl;
		cin >> cientifico;
		mamifero[i].SetCientifico(cientifico);
		cout << "Digite o sexo do animal[m/f]" << endl;
		cin >> sexo;
		mamifero[i].SetSexo(sexo);

		try{
			if(mamifero[i].GetSexo()!= "m" && mamifero[i].GetSexo()!= "f") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		cin >> tamanho;
		float tamanho_ = atoi(tamanho.c_str());
		mamifero[i].SetTamanho(tamanho_);
		cout << "Digite a dieta" << endl;
		cin >> dieta;
		mamifero[i].SetDieta(dieta);
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		cin >> cont_veterinario;
		int cont_veterinario_ = atoi(cont_veterinario.c_str());
		mamifero[i].SetVeterinario(cont_veterinario_);

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
		cin >> cont_tratador;
		int cont_tratador_ = atoi(cont_tratador.c_str());
		mamifero[i].SetTratador(cont_tratador_);

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
		cin >> batismo;
		mamifero[i].SetBatismo(batismo);
		cout << "Informe a cor do pelo" << endl;
		cin >> cor;
		mamifero[i].SetCorPelo(cor);

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

		ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<mamifero[i].GetNome()<<";"<<mamifero[i].GetClasse()<<";"<<mamifero[i].GetCientifico()<<";"<<mamifero[i].GetSexo()<<";"<<mamifero[i].GetTamanho()<<";"<<mamifero[i].GetDieta()<<";"<<mamifero[i].GetVeterinario()<<";"<<mamifero[i].GetTratador()<<";"<<mamifero[i].GetBatismo()<<";"<<mamifero[i].GetCorPelo()<<endl;

				animalOut.close();

		}

/** 
@brief Caso o controle de classe for igual a 3
*/
	if(controle_classe==3){

		
		reptil = new Reptil[500];
		cont_reptil++;

		reptil[i].SetId(i);
		cout << "Digite o nome do animal" << endl;
		cin >> nome_animal;
		reptil[i].SetNome(nome_animal);
		reptil[i].SetClasse("reptil");
		cout << "Digite o nome cientifico" << endl;
		cin >> cientifico;
		reptil[i].SetCientifico(cientifico);
		cout << "Digite o sexo do animal[m/f]" << endl;
		cin >> sexo;
		reptil[i].SetSexo(sexo);

		try{
			if(reptil[i].GetSexo()!= "m" && reptil[i].GetSexo()!= "f") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		cin >> tamanho;
		float tamanho_ = atoi(tamanho.c_str());
		reptil[i].SetTamanho(tamanho_);
		cout << "Digite a dieta" << endl;
		cin >> dieta;
		reptil[i].SetDieta(dieta);
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		cin >> cont_veterinario;
		int cont_veterinario_ = atoi(cont_veterinario.c_str());
		reptil[i].SetVeterinario(cont_veterinario_);

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
		cin >> cont_tratador;
		int cont_tratador_ = atoi(cont_tratador.c_str());
		reptil[i].SetTratador(cont_tratador_);

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
		cin >> batismo;
		reptil[i].SetBatismo(batismo);
		cout << "Informe se é venenoso ou não[1-sim/0-não]" << endl;
		cin >> venenoso;
		int venenoso_ = atoi(venenoso.c_str());
		reptil[i].SetVenenoso(venenoso_);

		try{
			if(reptil[i].GetVenenoso()!= 1 && reptil[i].GetVenenoso()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(reptil[i].GetVenenoso()==1){
			cout << "Agora informe o tipo do veneno" << endl;
			cin >> tipo_veneno;
			reptil[i].SetTipoVeneno(tipo_veneno);
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

		ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<reptil[i].GetNome()<<";"<<reptil[i].GetClasse()<<";"<<reptil[i].GetCientifico()<<";"<<reptil[i].GetSexo()<<";"<<reptil[i].GetTamanho()<<";"<<reptil[i].GetDieta()<<";"<<reptil[i].GetVeterinario()<<";"<<reptil[i].GetTratador()<<";"<<reptil[i].GetBatismo()<<";"<<reptil[i].GetVenenoso()<<";"<<reptil[i].GetTipoVeneno()<<endl;

				animalOut.close();

		

		}
/** 
@brief Caso o controle de classe for igual a 4
*/
	if(controle_classe == 4){

		
		ave = new Ave[500];
		cont_ave++;

		ave[i].SetId(i);
		cout << "Digite o nome do animal" << endl;
		cin >> nome_animal;
		ave[i].SetNome(nome_animal);
		ave[i].SetClasse("ave");
		cout << "Digite o nome cientifico" << endl;
		cin >> cientifico;
		ave[i].SetCientifico(cientifico);
		cout << "Digite o sexo do animal[m/f]" << endl;
		cin >> sexo;
		ave[i].SetSexo(sexo);

		try{
			if(ave[i].GetSexo()!= "m" && ave[i].GetSexo()!= "f") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		cin >> tamanho;
		float tamanho_ = atoi(tamanho.c_str());
		ave[i].SetTamanho(tamanho_);
		cout << "Digite a dieta" << endl;
		cin >> dieta;
		ave[i].SetDieta(dieta);
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		cin >> cont_veterinario;
		int cont_veterinario_ = atoi(cont_veterinario.c_str());
		ave[i].SetVeterinario(cont_veterinario_);

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
		cin >> cont_tratador;
		int cont_tratador_ = atoi(cont_tratador.c_str());
		ave[i].SetTratador(cont_tratador_);

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
		cin >> batismo;
		ave[i].SetBatismo(batismo);
		cout << "Digite o tamanho do bico" << endl;
		cin >> tamanho_bico;
		float tamanho_bico_ = atoi(tamanho_bico.c_str());
		ave[i].SetTamanhoBico(tamanho_bico_);
		cout << "Digite a envergadura da ave" << endl;
		cin >> envergadura;
		float envergadura_ = atoi(envergadura.c_str());
		ave[i].SetEnvergadura(envergadura_);

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

		ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<ave[i].GetNome()<<";"<<ave[i].GetClasse()<<";"<<ave[i].GetCientifico()<<";"<<ave[i].GetSexo()<<";"<<ave[i].GetTamanho()<<";"<<ave[i].GetDieta()<<";"<<ave[i].GetVeterinario()<<";"<<ave[i].GetTratador()<<";"<<ave[i].GetBatismo()<<";"<<ave[i].GetTamanhoBico()<<";"<<ave[i].GetEnvergadura()<<endl;

				animalOut.close();

		}
	}
	}

/**
@brief Caso for digitado 3 no sistema inicial, Consultar funcionário
*/
	if(aux==3){
		auxiliar_func++;
		int auxi;
		ifstream ip("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/funcionarioOut.csv");
			if(ip.is_open()){
			string id;
			veterinario = new Veterinario[100];
			while(ip.good()){
				getline(ip,id,';');
				getline(ip,profissao,';');
				getline(ip,nome,';');
				getline(ip,cpf,';');
				getline(ip,idade,';');
				getline(ip,tipo,';');
				getline(ip,rh,';');
				getline(ip,espec,'\n');
				
				int id_;
				istringstream (id) >> id_;

				auxi=id_;

				veterinario[auxi].SetProfissao(profissao);
				veterinario[auxi].SetNome(nome);
				veterinario[auxi].SetCPF(cpf);
				veterinario[auxi].SetIdade(idade);
				veterinario[auxi].SetTipo(tipo);
				veterinario[auxi].SetRH(rh);
				veterinario[auxi].SetEspec(espec);
				veterinario[auxi].SetAnimaisSendoCuidados("nenhum",0);
			}
	/**
	@brief inserindo as informações na STL Map
	*/
		p.insert(pair<int,string>(auxi,"Cargo: "+veterinario[auxi].GetProfissao()+"\n"+"Nome: "+veterinario[auxi].GetNome()+"\n"+"CPF: "+veterinario[auxi].GetCPF()+"\n"+"Idade: "+veterinario[auxi].GetIdade()+"\n"+"Tipo Sanguíneo: "+veterinario[auxi].GetTipo()+"\n"+"RH: "+veterinario[auxi].GetRH()+"\n"+"Especialidade: "+veterinario[auxi].GetEspec()));
		cout << "----------------------------------------"<< endl;
		cout<< "\nImpressão na stl"<< endl;
		cout <<"Id: "<<auxi<< "\n" << p[auxi]<< endl;
		cout << "----------------------------------------"<< endl;

			ip.close();
			goto inicio;
		}else{cout << "Arquivo inexistente"<<endl;}

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
		
		string id_animal;
		ifstream animaisIn("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");
			if(!animaisIn.is_open()) cout << "Erro: File " << endl;
			while(animaisIn.good()){
				getline(animaisIn,id_animal,';');
				getline(animaisIn,nome_animal,';');
				getline(animaisIn,classe_animal,';');
				getline(animaisIn,cientifico,';');
				getline(animaisIn,sexo,';');
				getline(animaisIn,tamanho,';');
				getline(animaisIn,dieta,';');
				getline(animaisIn,cont_veterinario,';');
				getline(animaisIn,cont_tratador,';');
				getline(animaisIn,batismo,';');
				if(classe_animal=="anfibio"){
					getline(animaisIn,total,'\n');
				
				animal.insert(pair<int,string>(i,"Nome: "+nome_animal+"\nClasse: "+classe_animal+"\nCientifico: "+cientifico+"\nSexo: "+sexo+"\nTamanho: "+tamanho+"\nDieta: "+dieta+"\nVeterinario: "+cont_veterinario+"\nTratador: "+cont_tratador+"\nNome de Batismo: "+batismo+"\nMudas: "+total));
				cout<< "\n------------------------------------------------:"<< endl;
				cout<< "\nO ANIMAL:"<< endl;
				cout << "Id: "<<i << "\n" << animal[i]<< endl;

				animaisIn.close();

				}else if(classe_animal=="mamifero"){
					getline(animaisIn,cor,'\n');

			/** @brief Inserção na stl */
				animal.insert(pair<int,string>(i,"Nome: "+nome_animal+"\nClasse: "+classe_animal+"\nCientifico: "+cientifico+"\nSexo: "+sexo+"\nTamanho: "+tamanho+"\nDieta: "+dieta+"\nVeterinario: "+cont_veterinario+"\nTratador: "+cont_tratador+"\nNome de Batismo: "+batismo+"\nCor: "+cor));
				cout<< "\n------------------------------------------------:"<< endl;
				cout<< "\nO ANIMAL:"<< endl;
				cout <<"Id: "<<i << "\n" << animal[i]<< endl;

				animaisIn.close();

				}else if(classe_animal=="reptil"){
					getline(animaisIn,venenoso,';');
					getline(animaisIn,tipo_veneno,'\n');
				
				animal.insert(pair<int,string>(i,"Nome: "+nome_animal+"\nClasse: "+classe_animal+"\nCientifico: "+cientifico+"\nSexo: "+sexo+"\nTamanho: "+tamanho+"\nDieta: "+dieta+"\nVeterinario: "+cont_veterinario+"\nTratador: "+cont_tratador+"\nNome de Batismo: "+batismo+"\nVenenoso: "+venenoso+"\nTipo Veneno: "+tipo_veneno));
				cout<< "\n------------------------------------------------:"<< endl;
				cout<< "\nO ANIMAL:"<< endl;
				cout <<"Id: "<<i << "\n" << animal[i]<< endl;

				animaisIn.close();

				}else if(classe_animal=="ave"){
					getline(animaisIn,tamanho_bico,';');
					getline(animaisIn,envergadura,'\n');
				cout<< "\n------------------------------------------------:"<< endl;
				cout << "\nO ANIMAL:" << endl;
				
				animal.insert(pair<int,string>(i,"Nome: "+nome_animal+"\nClasse: "+classe_animal+"\nCientifico: "+cientifico+"\nSexo: "+sexo+"\nTamanho: "+tamanho+"\nDieta: "+dieta+"\nVeterinario: "+cont_veterinario+"\nTratador: "+cont_tratador+"\nNome de Batismo: "+batismo+"\nTamanho do Bico: "+tamanho_bico+"\nEnvergadura: "+envergadura));
				
				cout<< "\nImpressão na stl"<< endl;
				cout <<"Id: "<<i << "\n" << animal[i]<< endl;

				animaisIn.close();

				}
				
			}

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
		cin >> nome_animal;
		anfibio[id_funcionario].SetNome(nome_animal);
		anfibio[id_funcionario].SetClasse("anfibio");
		cout << "Digite o nome cientifico" << endl;
		cin>> cientifico;
		anfibio[id_funcionario].SetCientifico(cientifico);
		cout << "Digite o sexo do animal[m/f]" << endl;
		cin >> sexo;
		anfibio[id_funcionario].SetSexo(sexo);

		try{
			if(anfibio[id_funcionario].GetSexo()!= "m" && anfibio[id_funcionario].GetSexo()!= "f") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		cin >> tamanho;
		float tamanho_ = atoi(tamanho.c_str());
		anfibio[id_funcionario].SetTamanho(tamanho_);
		cout << "Digite a dieta" << endl;
		cin >> dieta;
		anfibio[id_funcionario].SetDieta(dieta);
		cout << "Digite se possui veterinario ou nao[1-Sim/0-Não]" << endl;
		cin >> cont_veterinario;
		int cont_veterinario_ = atoi(cont_veterinario.c_str());
		anfibio[id_funcionario].SetVeterinario(cont_veterinario_);

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
		cin >> cont_tratador;
		int cont_tratador_ = atoi(cont_tratador.c_str());
		anfibio[id_funcionario].SetTratador(cont_tratador_);
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
		cin >> batismo;
		anfibio[id_funcionario].SetBatismo(batismo);
		cout << "Digite o total de mudas do animal" << endl;
		cin >> total;
		int total_ = atoi(total.c_str());
		anfibio[id_funcionario].SetTotal(total_);

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

		ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<anfibio[i].GetNome()<<";"<<anfibio[i].GetClasse()<<";"<<anfibio[i].GetCientifico()<<";"<<anfibio[i].GetSexo()<<";"<<anfibio[i].GetTamanho()<<";"<<anfibio[i].GetDieta()<<";"<<anfibio[i].GetVeterinario()<<";"<<anfibio[i].GetTratador()<<";"<<anfibio[i].GetBatismo()<<";"<<anfibio[i].GetTotal()<<endl;

		animalOut.close();

		}

else if(classe_=="mamifero"){
		mamifero = new Mamifero[500];

		cout << "Digite o nome do animal" << endl;
		cin >> nome;
		mamifero[id_funcionario].SetNome(nome);
		mamifero[id_funcionario].SetClasse("mamifero");
		cout << "Digite o nome cientifico" << endl;
		cin >> cientifico;
		mamifero[id_funcionario].SetCientifico(cientifico);
		cout << "Digite o sexo do animal[m/f]" << endl;
		cin >> sexo;
		mamifero[id_funcionario].SetSexo(sexo);

		try{
			if(mamifero[id_funcionario].GetSexo()!= "m" && mamifero[id_funcionario].GetSexo()!= "f") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		cin >> tamanho;
		float tamanho_ = atoi(tamanho.c_str());
		mamifero[id_funcionario].SetTamanho(tamanho_);
		cout << "Digite a dieta" << endl;
		cin >> dieta;
		mamifero[id_funcionario].SetDieta(dieta);
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		cin >> cont_veterinario;
		int cont_veterinario_ = atoi(cont_veterinario.c_str());
		mamifero[id_funcionario].SetVeterinario(cont_veterinario_);

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
		cin >> cont_tratador;
		int cont_tratador_ = atoi(cont_tratador.c_str());
		mamifero[id_funcionario].SetTratador(cont_tratador_);

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
		cin >> batismo;
		mamifero[id_funcionario].SetBatismo(batismo);
		cout << "Informe a cor do pelo" << endl;
		cin >> cor;
		mamifero[id_funcionario].SetCorPelo(cor);

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

		ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<mamifero[i].GetNome()<<";"<<mamifero[i].GetClasse()<<";"<<mamifero[i].GetCientifico()<<";"<<mamifero[i].GetSexo()<<";"<<mamifero[i].GetTamanho()<<";"<<mamifero[i].GetDieta()<<";"<<mamifero[i].GetVeterinario()<<";"<<mamifero[i].GetTratador()<<";"<<mamifero[i].GetBatismo()<<";"<<mamifero[i].GetCorPelo()<<endl;

				animalOut.close();

		}


else if(classe_=="reptil"){
		reptil = new Reptil[500];

		cout << "Digite o nome do animal" << endl;
		cin >> nome;
		reptil[id_funcionario].SetNome(nome);
		reptil[id_funcionario].SetClasse("reptil");
		cout << "Digite o nome cientifico" << endl;
		cin >> cientifico;
		reptil[id_funcionario].SetCientifico(cientifico);
		cout << "Digite o sexo do animal[m/f]" << endl;
		cin >> sexo;
		reptil[id_funcionario].SetSexo(sexo);

		try{
			if(reptil[id_funcionario].GetSexo()!= "m" && reptil[id_funcionario].GetSexo()!= "f") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		cin >> tamanho;
		float tamanho_ = atoi(tamanho.c_str());
		reptil[id_funcionario].SetTamanho(tamanho_);
		cout << "Digite a dieta" << endl;
		cin >> dieta;
		reptil[id_funcionario].SetDieta(dieta);
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		cin >> cont_veterinario;
		int cont_veterinario_ = atoi(cont_veterinario.c_str());
		reptil[id_funcionario].SetVeterinario(cont_veterinario_);

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
		cin >> cont_tratador;
		int cont_tratador_ = atoi(cont_tratador.c_str());
		reptil[id_funcionario].SetTratador(cont_tratador_);

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
		cin >> batismo;
		reptil[id_funcionario].SetBatismo(batismo);
		cout << "Informe se é venenoso ou não[1-sim/0-não]" << endl;
		cin >> venenoso;
		int venenoso_ = atoi(venenoso.c_str());
		reptil[id_funcionario].SetVenenoso(venenoso_);

		try{
			if(reptil[id_funcionario].GetVenenoso()!= 1 && reptil[id_funcionario].GetVenenoso()!= 0) throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		if(reptil[id_funcionario].GetVenenoso()==1){
			cout << "Agora informe o tipo do veneno" << endl;
			cin >> tipo_veneno;
			reptil[id_funcionario].SetTipoVeneno(tipo_veneno);
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

		ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<reptil[i].GetNome()<<";"<<reptil[i].GetClasse()<<";"<<reptil[i].GetCientifico()<<";"<<reptil[i].GetSexo()<<";"<<reptil[i].GetTamanho()<<";"<<reptil[i].GetDieta()<<";"<<reptil[i].GetVeterinario()<<";"<<reptil[i].GetTratador()<<";"<<reptil[i].GetBatismo()<<";"<<reptil[i].GetVenenoso()<<";"<<reptil[i].GetTipoVeneno()<<endl;

				animalOut.close();

		}


else if(classe_=="ave"){
		ave = new Ave[500];

		cout << "Digite o nome do animal" << endl;
		cin >> nome_animal;
		ave[id_funcionario].SetNome(nome_animal);
		ave[id_funcionario].SetClasse("ave");
		cout << "Digite o nome cientifico" << endl;
		cin >> cientifico;
		ave[id_funcionario].SetCientifico(cientifico);
		cout << "Digite o sexo do animal[m/f]" << endl;
		cin >> sexo;
		ave[id_funcionario].SetSexo(sexo);

		try{
			if(ave[id_funcionario].GetSexo()!= "m" && ave[id_funcionario].GetSexo()!= "f") throw ErroDeInsercao();
		}catch(ErroDeInsercao &e){
			cout << "ERRO: " << e.what() << endl;
			exit(0);
		}

		cout << "Digite o tamanho" << endl;
		cin >> tamanho;
		float tamanho_ = atoi(tamanho.c_str());
		ave[id_funcionario].SetTamanho(tamanho_);
		cout << "Digite a dieta" << endl;
		cin >> dieta;
		ave[id_funcionario].SetDieta(dieta);
		cout << "Digite se possui veterinario ou nao[1/0]" << endl;
		cin >> cont_veterinario;
		int cont_veterinario_ = atoi(cont_veterinario.c_str());
		ave[id_funcionario].SetVeterinario(cont_veterinario_);

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
		cin >> cont_tratador;
		int cont_tratador_ = atoi(cont_tratador.c_str());
		ave[id_funcionario].SetTratador(cont_tratador_);

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
		cin >> batismo;
		ave[id_funcionario].SetBatismo(batismo);
		cout << "Digite o tamanho do bico" << endl;
		cin >> tamanho_bico;
		float tamanho_bico_ = atoi(tamanho_bico.c_str());
		ave[id_funcionario].SetTamanhoBico(tamanho_bico_);
		cout << "Digite a envergadura da ave" << endl;
		cin >> envergadura;
		float envergadura_ = atoi(envergadura.c_str());
		ave[id_funcionario].SetEnvergadura(envergadura_);
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

		ofstream animalOut;

				animalOut.open("/home/vinicius/Desktop/LP/PROJETO_LP_LIB/include/animalOut.csv");

				animalOut << i << ";"<<ave[i].GetNome()<<";"<<ave[i].GetClasse()<<";"<<ave[i].GetCientifico()<<";"<<ave[i].GetSexo()<<";"<<ave[i].GetTamanho()<<";"<<ave[i].GetDieta()<<";"<<ave[i].GetVeterinario()<<";"<<ave[i].GetTratador()<<";"<<ave[i].GetBatismo()<<";"<<ave[i].GetTamanhoBico()<<";"<<ave[i].GetEnvergadura()<<endl;

				animalOut.close();

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
		while(auxiliar_func>0){
			auxiliar_func--;
			delete[] veterinario;
		}
		while(cont_anfibio>0){
			delete[] anfibio;
			cont_anfibio--;
		}
		while(cont_mamifero>0){
			delete[] mamifero;
			cont_mamifero--;
		}
		while(cont_reptil>0){
			delete[] reptil;
			cont_reptil--;
		}
		while(cont_ave>0){
			delete[] ave;
			cont_ave--;
		}
		exit(0);
	}
}
}

#endif