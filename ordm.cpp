#include <iostream>
#include "ord.cpp"
using namespace std;

int main(){

 Ordenacao *o = new Ordenacao();
cout << "Vetor numero qualquer desordenado" << endl;
 o->mostra();
 //o->buble();
//cout << "\nVetor ordenado Buble " << endl;
 //o->mostra();
 //o->select();
//cout << "\nVetor ordenado Select " << endl;
//o->mostra();
//o->insert();
//cout << "\nVetor ordenado Insert " << endl;
//o->mostra();
o->shell();
cout << "\nVetor ordenado Shell " << endl;
o->mostra();

delete o;

}
