#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int global = 0;
int global2= 0;

vector<int> generaVector(int tam){
  vector<int> v;
  /* initialize random seed: */
  srand (time(NULL));
  /* generate secret number between 1 and 10: */
  for(int i = 0;i<tam;i++){
    int random = rand() % 1000 + 1;
    v.push_back(random);
  }
  return v;
}

void printVect(vector<int> v, string nombre){
  cout<<"El arreglo ordenado con "<<nombre<<" es:"<<endl;
    for (int i=0; i<v.size();++i) {
          cout<<v[i]<<" ";
    }
    cout<<"\n";
}

//Algoritmo de ordenamiento por el metodo de Burbuja
//Complejidad temporal O(n^2)
void ordenaBurbuja(vector<int> &lista,int tam){
  int swaps=0;
  for (int i=0;i<tam-1;i++){
    for(int j=0;j<tam-1-i;j++){
      swaps++;
      if (lista[j]>lista[j+1]){
        int temp=lista[j];
        lista[j]=lista[j+1];
        lista[j+1]=temp;
      }
    }
  }
  cout<<"El arreglo ordenado con bubble es:"<<endl;
  for (int i=0; i<lista.size();++i) {
        cout<<lista[i]<<" ";
  }
  cout<<"\n";
  cout<<"Numero de comparaciones: "<<swaps<<"\n";
  cout<<endl;

}

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int partition(vector<int> &v, int inicio, int fin){
  int pivote = v[fin];
  int i = inicio-1;
  for(int j = inicio; j<=fin-1 ;j++){
    global++;
    if(v[j] <= pivote){
      i++;
      swap(v[i],v[j]);
    }
  }
  swap(v[i+1],v[fin]);

  return (i+1);
}

void ordenaQuickSort(vector<int> &v, int inicio, int fin){
  if (inicio < fin) {
    int part = partition(v, inicio, fin);
    ordenaQuickSort(v, inicio, part - 1);
    ordenaQuickSort(v, part + 1, fin);
  }   
}


//Algoritmo de ordenamiento por fusion(Merge) Division & Fusion.
void merge(vector<int> &lista, int low, int m, int high){
  vector<int> temp;

  int i, j;
  i = low;
  j = m+1;
  
  while ( i <= m && j <= high){
    global2++;
    if (lista[i] <= lista[j]){
      temp.push_back(lista[i]);
      i++;
    } else {
      temp.push_back(lista[j]);
      j++;
    }
  }

  while (i <= m){
      temp.push_back(lista[i]);
      i++;
  }
  while (j <= high){
      temp.push_back(lista[j]);
      j++;
  }
  for(int i = low; i<= high; i++)
    lista[i] = temp[i-low];
}

//Algoritmo de ordenamiento por fusion(Merge) 
//Complejidad temporal O(n log n)
void ordenaMerge(vector<int> &lista, int low, int high){
  if (low<high) {
    int m = (low + high) / 2;
    ordenaMerge(lista, low, m);
    ordenaMerge(lista, m+1, high);
    merge(lista, low, m, high);
  }
}

int main(){
  int tam;
  cout<<"Cuantos datos va a tener el vector?\n";
  cin>>tam;
  vector<int> v = generaVector(tam);
  vector<int> v_1 = v;
  vector<int> v_2 = v;

  cout<<"\n";
  cout<<"Ordenado de un vector de dimension "<<tam<<" con bubble sort\n";
  ordenaBurbuja(v, v.size());
  ordenaBurbuja(v, v.size());
  reverse(v.begin(), v.end());
  ordenaBurbuja(v, v.size());

  cout<<"\n";
  cout<<"Ordenado de un vector de dimension "<<tam<<" con Quick sort\n";
  global = 0;
  ordenaQuickSort(v_1, 0, v_1.size()-1);
  printVect(v_1,"QuickSort");
  cout<<"El numero de comparaciones es: "<<global<<"\n";
  cout<<"\n";
  global = 0;
  ordenaQuickSort(v_1, 0, v_1.size()-1);
  printVect(v_1,"QuickSort");
  cout<<"El numero de comparaciones es: "<<global<<"\n";
  cout<<"\n";
  reverse(v_1.begin(), v_1.end());
  global = 0;
  ordenaQuickSort(v_1, 0,v_1.size()-1);
  printVect(v_1,"QuickSort");
  cout<<"El numero de comparaciones es: "<<global<<"\n";

  cout<<"\n";
  cout<<"Ordenado de un vector de dimension "<<tam<<" con Merge sort\n";
  global2 = 0;
  ordenaMerge(v_2, 0, v_2.size() - 1);
  printVect(v_2,"Merge");
  cout<<"Numero de comparaciones: "<<global2<<"\n";  
  cout<<"\n";
  global2 = 0;
  ordenaMerge(v_2, 0, v_2.size() - 1);
  printVect(v_2,"Merge");
  cout<<"Numero de comparaciones: "<<global2<<"\n";  
  cout<<"\n";
  reverse(v_2.begin(), v_2.end());
  global2 = 0;
  ordenaMerge(v_2, 0, v_2.size() - 1);
  printVect(v_2,"Merge");
  cout<<"Numero de comparaciones: "<<global2<<"\n";  
  cout<<"\n";

  return 0;
}