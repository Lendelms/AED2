#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#define MAX 8

using namespace std;

class Ordenacao{
  int v[MAX],a,b,c;

public:
  Ordenacao(){
    srand(time(NULL));
    for(a = 0;a < MAX;a++){
      b = rand()%(20) + 1;
      v[a] = b;
    }
  };

  void go() {
    QuickSort(0,MAX);
  };

  void QuickSort(int i, int f){
    int pivo;
    if (f > i){
			pivo = divide(i, f);
			QuickSort(i, pivo - 1);
			QuickSort(pivo + 1, f);
		}
};

int divide(int i, int f){
  int p = i;
  int l = p, r = f;
      while(r >= l){
        if(p < r){
          if(v[l] > v[r]){
            p = r;
            a = v[l];
            v[l] = v[r];
            v[r] = a;
          }
          else{
            r--;
          }
      }
      else{
        if(v[l] > v[r]){
          p = l;
          a = v[l];
          v[l] = v[r];
          v[r] = a;
        }
        else{
          l++;
        }
      }

  }
  return p;

};

  void mostra(){
    for(a = 0;a < MAX;a++){
      cout << " v: " << v[a] << endl;
    }
  };

  };
