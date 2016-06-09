#include <iostream>
using namespace std;

class Pessoa{
public:
Pessoa *filhoEsquerdo,*filhoDireito,*pai;
int id,fb;
string nome;

public:
Pessoa(int a,string n){
  id = a;
  nome = n;
  filhoDireito = NULL;
  filhoEsquerdo = NULL;
  pai = NULL;
};

Pessoa(){ };

void inseri(Pessoa *p){
  if(this->id < p->id){
    if(this->filhoEsquerdo == NULL){
      this->filhoEsquerdo = p;
      this->filhoEsquerdo->pai = this;
    }
    else{
      this->filhoEsquerdo->inseri(p);
    }
  }
  else{
    if(this->filhoDireito == NULL){
      this->filhoDireito = p;
      this->filhoDireito->pai = this;
    }
    else{
      this->filhoDireito->inseri(p);
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
  cout << "Id: " << this->id << "  fb: "<< fb << endl;
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
  if(p->filhoDireito == NULL && p->filhoEsquerdo == NULL){
  	this->delSimple(p);
  }
  else if(p->filhoDireito != NULL && p->filhoEsquerdo != NULL){
    this->delCompl(p);
  }
  else{
    this->delSimple2(p);
  }
};

void delSimple(Pessoa *p){
	if(p->pai != NULL){
  		if(p->pai->id > p->id){
    		p->pai->filhoDireito = NULL;
  		}
  		else{
    		p->pai->filhoEsquerdo = NULL;
  		}
  		cout << "Deletado";
  		delete p;
	}
	else{
		cout << "Deletado2";
	}
};

void delSimple2(Pessoa *p){
	if(p->pai != NULL){
  		if(p->pai->id > p->id){
  			if(p->filhoDireito != NULL){
				      p->pai->filhoDireito = p->filhoDireito;
				      p->filhoDireito->pai = p->pai;
			  }
			  else{
				      p->pai->filhoDireito = p->filhoEsquerdo;
				      p->filhoEsquerdo->pai = p->pai;
			  }
  		}
  		else{
    		if(p->filhoDireito != NULL){
				      p->pai->filhoEsquerdo = p->filhoDireito;
				          p->filhoDireito->pai = p->pai;
			  }
			  else{
				      p->pai->filhoEsquerdo = p->filhoEsquerdo;
				      p->filhoEsquerdo->pai = p->pai;
			  }
  		}
  		cout << "Deletado";
  		delete p;
	}
	else{
    Pessoa *aux = this;
		if(p->filhoDireito != NULL){
			aux = p->filhoDireito;
		}
		else{
			aux = p->filhoEsquerdo;
		}
		delete p;
		cout << "Deletado!";
	}
};

void delCompl(Pessoa *p){
	Pessoa *aux = p;
	if(p->pai != NULL){
		aux = p->filhoDireito;
		while(aux->filhoEsquerdo != NULL){
			aux = aux->filhoEsquerdo;
		}
		if(p->id > p->pai->id){
			aux->filhoEsquerdo = p->filhoEsquerdo;
			aux->pai = p->pai;
			p->pai->filhoDireito = aux;
		}
		else{
			aux->filhoEsquerdo = p->filhoEsquerdo;
			aux->pai = p->pai;
			p->pai->filhoEsquerdo = aux;
		}
		delete p;
	}
	else{
		p->filhoEsquerdo->pai = p->filhoDireito;
		p->filhoDireito->pai = NULL;
    aux = this;
		aux = p->filhoDireito;
		delete p;
	}
};

int Altura(Pessoa *inicio){
    if (!inicio)
        return -1;
    else {
        int alturaesquerda, alturadireita;
        alturaesquerda = Altura(inicio->filhoEsquerdo);
        alturadireita  = Altura(inicio->filhoDireito);
      if (alturaesquerda < alturadireita){
         return alturadireita + 1;
       }
      else{
         return alturaesquerda + 1;
       }
    }
};

void calcFb(Pessoa *inicio){
    int esq,dir;
    dir = Altura(inicio->filhoDireito);
    esq = Altura(inicio->filhoEsquerdo);
    inicio->fb = esq-dir;

    if(inicio->filhoEsquerdo != NULL){
        inicio->calcFb(inicio->filhoEsquerdo);
    }

    if(inicio->filhoDireito != NULL){
        inicio->calcFb(inicio->filhoDireito);
    }
};

void simEsq(Pessoa *p){
    Pessoa *aux,*aux2;
    aux = p->filhoDireito;
    aux2 = aux->filhoEsquerdo;
    aux->filhoEsquerdo = p;
    p->filhoDireito = aux2;
    p = aux;
};

void simDir(Pessoa *p){
  Pessoa *aux,*aux2;
  aux = p->filhoEsquerdo;
  aux2 = aux->filhoDireito;
  aux->filhoDireito = p;
  p->filhoEsquerdo = aux2;
  p = aux;
};

void Avl(Pessoa *inicio){
  if(inicio->filhoEsquerdo != NULL){
      inicio->Avl(inicio->filhoEsquerdo);
  }

  if(inicio->filhoDireito != NULL){
      inicio->Avl(inicio->filhoDireito);
  }

  if(inicio->fb > 1){
      if(inicio->filhoDireito->fb >= 0){
        inicio->simEsq(inicio);
      }
      else{
        //inicio->dupEsq(inicio);
      }
  }
  if(inicio->fb < -1){
    if(inicio->filhoEsquerdo->fb <= -1){
      inicio->simDir(inicio);
    }
    else{
      //inicio->dupDir(inicio);
    }
  }
};

};
