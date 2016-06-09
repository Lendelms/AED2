#include <iostream>
#include "ord2.cpp"
using namespace std;

int main(){
 Ordenacao *o = new Ordenacao();
 o->mostra();
 o->go();
 cout << "\nVetor ordenado QuickSort " << endl;
 o->mostra();
 delete o;
 }
