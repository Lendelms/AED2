#include <iostream>
using namespace std;

class Pessoa{
public:
Pessoa *filhoEsquerdo,*filhoDireito,*pai;
int id;
string nome;

public:
Pessoa(int a,string n){
  id = a;
  nome = n;
};

Pessoa(){ };

void inseri(Pessoa *raiz){
  if(this->id < raiz->id){
    if(this->filhoEsquerdo == NULL){
      this->filhoEsquerdo = raiz;
      this->filhoEsquerdo->pai = this;
    }
    else{
      this->filhoEsquerdo->inseri(raiz);
    }
  }
  else{
    if(this->filhoDireito == NULL){
      this->filhoDireito = raiz;
      this->filhoDireito->pai = this;
    }
    else{
      this->filhoDireito->inseri(raiz);
    }
  }
};

void listaPre(){
  if(this->pai != NULL){
    cout << "NomePai: "<< this->pai->nome;
  }

  cout << "\nNome: "<< this->nome << "\nId: " << this->id << endl;

  if(this->filhoEsquerdo != NULL){
    this->filhoEsquerdo->listaPre();
  }
  if(this->filhoDireito != NULL){
    filhoDireito->listaPre();
  }
};

void  listaOrdem(){
  if(this->filhoEsquerdo != NULL){
    this->filhoEsquerdo->listaOrdem();
  }
  cout << "Id: " << this->id << endl;
  if(this->filhoDireito != NULL){
    filhoDireito->listaOrdem();
  }
};

void  listaPos(){
  if(this->filhoEsquerdo != NULL){
    this->filhoEsquerdo->listaPos();
  }
  if(this->filhoDireito != NULL){
    filhoDireito->listaPos();
  }
  cout << "Id: " << this->id << endl;
};

void  delTotal(){
  if(this->filhoEsquerdo != NULL){
    this->filhoEsquerdo->delTotal();
  }
  if(this->filhoDireito != NULL){
    filhoDireito->delTotal();
  }
  delete this;
  std::cout << "Deletado !" << std::endl;
};

Pessoa * busca(int idd){
  Pessoa *aux = NULL;

  if(idd == this->id){
    aux = this;
    return aux;
  }
  else{
    if(idd > this->id){
      if(this->filhoEsquerdo != NULL){
        this->filhoEsquerdo->busca(idd);
      }
  }
  else{
      if(this->filhoDireito != NULL){
        this->filhoDireito->busca(idd);
      }
  }
}

};

void Delet(Pessoa *p){
  if(this->filhoDireito == NULL && this->filhoEsquerdo == NULL){
    delSimple(p);
  }
  else if(this->filhoDireito != NULL && this->filhoEsquerdo != NULL){
    //delCompl(p);
  }
  else{
    //delSimple2(p)
  }
};

void delSimple(Pessoa *p){
  if(p->pai->id < p->id){
    p->pai->filhoDireito = NULL;
  }
  else{
    p->pai->filhoEsquerdo = NULL;
  }
  delete this;
}

};
