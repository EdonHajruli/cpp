//
//  main.cpp
//  Puntatori
//
//  Created by Apple on 29/01/18.
//  Copyright © 2018 Edon Hajruli. All rights reserved.
//



#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct libro
{
    char titolo[20];
    float costo;
    int npagine;
    char autore[16];
};


int main() {
    int i,N,num;
    float prezzo;
    string prova;
    
    struct libro volume;
    
    cout<<"dammi il numero di elementi del vettore";
    cin>>N;
    
    float vett[N];
    int* puntint;
    float* puntnumero;
    string* puntstring;
    float* puntvettore;
    struct libro* puntrecord;
    
    puntint =& num;
    puntstring =& prova;
    puntvettore =& vett[0];
    puntrecord =& volume;
    puntnumero =& prezzo;
    
    cout<<"\n\nIndirizzi delle variabili\nL'indirizzo di memoria della variabile num = "<<puntint<<endl;
    puntint =& N;
    
    cout<<"\nL'indirizzo di memoria della variabile N = "<<puntint<<endl;
    cout<<"\nL'indirizzo di memoria della variabile prova = "<<puntstring<<endl;
    cout<<"\nL'indirizzo di memoria della variabile prezzo = "<<puntnumero<<endl;

    cout<<"\nL'indirizzo di memoria della variabile vett[0] = "<<puntvettore<<endl;
    cout<<"\nL'indirizzo di memoria della variabile vett[1] = "<<puntvettore + 1<<endl;
    cout<<"\nL'indirizzo di memoria della variabile vett[2] = "<<puntvettore + 2<<endl;
    cout<<"\nL'indirizzo di memoria del record = "<<puntrecord<<endl;
    cout<<"\nL'indirizzo di memoria di un secondo record = "<<puntrecord + 1 <<endl;
    cout<<"\nL'indirizzo di memoria di un terzo record = "<<puntrecord + 2 <<endl;
    cout<<"\n\nLindirizzo di memoria del campo titolo del record = "<<&puntrecord -> titolo;
    cout<<"\n\nLindirizzo di memoria del campo costo del record = "<<&puntrecord -> costo;
    cout<<"\n\nLindirizzo di memoria del campo numero pagine del record = "<<&puntrecord -> npagine;
    cout<<"\n\nLindirizzo di memoria del campo autore del record = "<<&puntrecord -> autore;

    return 0;
}
