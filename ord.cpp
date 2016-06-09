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

void buble(){
  b = 1;
  for(a = 0;a < MAX;a++){
    while(b < MAX){
      if(v[a] > v[b]){
        c = v[a];
        v[a] = v[b];
        v[b] = c;
      }
      b++;
    }
    b = a+1;
  }

};

void select(){
  int m;
  for(a = 0;a < MAX;a++){
    m = v[a];
    for(c = a+1;c < MAX;c++){
      if(v[c] < m){
        b = m;
        m = v[c];
        v[c] = b;
      }
    }
    v[a] = m;
  }
};

void insert(){
  for(a = 0; a < MAX; a++){
		b = a;
		while(b > 0 && v[b] < v[b-1]){
			  c = v[b];
			  v[b] = v[b-1];
			  v[b-1] = c;
			  b--;
			  }
		}
};

void shell(){
  int k = MAX / 2;
  while(k > 0){
      for(b = 0; b < MAX; b++){
        if( (b+k) < MAX && v[b] > v[b+k]){
          c = v[b];
          v[b] = v[b+k];
          v[b+k] = c;
        }
      }
  k--;
  }

};

void mostra(){
  for(a = 0;a < MAX;a++){
    cout << " v: " << v[a] << endl;
  }
};

};
