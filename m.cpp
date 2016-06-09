#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "Pessoa.hpp"
using namespace std;

Pessoa *raiz,*pp = NULL,*p;

int main(){
  stringstream out;
  raiz = NULL;
  string nome,ax;
  int id,opcao,esq,dir;
  string n[5][2];

  do {
      std::cout << "\n========= Menu =========" << std::endl;
      cout << "1 - Inserir" << endl;
      cout << "2 - Listar Pré" << endl;
      cout << "3 - Listar Ordem" << endl;
      cout << "4 - Listar Pós" << endl;
      cout << "5 - Buscar" << endl;
      cout << "6 - Deletar Pessoa" << endl;
      std::cout << "7 - Fator de balanceamento de todos" << std::endl;
      cout << "0 - Sair" << endl;
      cout << "\nDigite opcao : ";
      cin >> opcao;

      switch (opcao) {
          case 1:
          std::cout << "\n========= Adicionar =========" << std::endl;
          cout << "\nDigite idade Pessoa : ";
          cin >> id;
          cout << "\nDigite nome Pessoa : ";
          cin >> nome;
          p = new Pessoa(id,nome);
          if(raiz == NULL){
            p->pai = NULL;
            raiz = p;
          }else{
            raiz->inseri(p);
          }

          break;

          case 2:
          system("clear");
          cout << "\nLista em Pre ordem:"<< endl;
          if(raiz != NULL){
            raiz->listaPre();
          }
          else{
            cout << "Arvore Vazia X_X ";
          }
          break;

          case 3:
          system("clear");
          cout << "\nLista em Ordem:"<< endl;
          if(raiz != NULL){
            raiz->listaOrdem();
          }
          else{
            cout << "Arvore Vazia X_X ";
          }
          break;

          case 4:
          system("clear");
          cout << "\nLista em Pos Ordem:"<< endl;
          if(raiz != NULL){
            raiz->listaPos();
          }
          else{
            cout << "Arvore Vazia X_X ";
          }
          break;

          case 5:
          cout << "\nBuscar"<< endl;
          cout << "\nDigite idade Pessoa : ";
          cin >> id;
          if(raiz != NULL) {
            pp = raiz->busca(id);
            if(pp != NULL){
              cout << "\nEncontrado!";
              cout << "\nNome : " << pp->nome << " Idade : " << pp->id;
            }
            else{
              cout << "\nNAO Encontrado pessoa com idade : "<< id;
            }
          }
          else{
             std::cout << "\nRaiz Sem registro X " << std::endl;
          }
          break;

          case 6:
          cout << "\nDeletar Pessoa"<< endl;
          cout << "\nDigite idade Pessoa para Deletar : ";
          cin >> id;
          pp = raiz->busca(id);
          if(pp != NULL){
          		cout << "Encontrado Pessoa idade: " << pp->id << endl;
            	raiz->Delet(pp);
          }
          else{
             cout << "\nSem registro na Arvore " << endl;
          }
          break;

          case 7:
          dir = raiz->Altura(raiz->filhoDireito);
          esq = raiz->Altura(raiz->filhoEsquerdo);
          cout <<"\n Fator de balanceamento geral : " << (esq-dir);
          raiz->calcFb(raiz);
          break;

          case 8:
          for (int i = 0; i < 7; i++){
             p = new Pessoa(4,"l");
             raiz = p;
             p = new Pessoa(6,"k");
             raiz->inseri(p);
             p = new Pessoa(1,"k");
             //raiz->inseri(p);
             p = new Pessoa(7,"k");
             raiz->inseri(p);
             p = new Pessoa(5,"k");
             //raiz->inseri(p);
             p = new Pessoa(3,"k");
             //raiz->inseri(p);
             p = new Pessoa(2,"k");
             //raiz->inseri(p);
          }
          break;

          case 9:
            raiz->Avl(raiz);
          break;

          case 0:
          cout << "\n Saindo e limpando Memoria: "<< endl;
          if(raiz != NULL){
            raiz->delTotal();
          }
          else{
            cout << "Arvore Vazia X_X ";
          }
          break;


      }

  }while(opcao != 0);


}
