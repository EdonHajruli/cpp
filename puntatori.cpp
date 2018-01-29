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
    long double valorestorico;
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
    
    cout<<"\n\nIndirizzi delle variabili\nL'indirizzo di memoria della variabile num = "<<puntint;
    puntint =& N;
    
    cout<<"\nL'indirizzo di memoria della variabile N = "<<puntint;
    cout<<"\nL'indirizzo di memoria della variabile prova = "<<puntstring;
    cout<<"\nL'indirizzo di memoria della variabile prezzo = "<<puntnumero;

    cout<<"\nL'indirizzo di memoria della variabile vett[0] = "<<puntvettore;
    cout<<"\nL'indirizzo di memoria della variabile vett[1] = "<<puntvettore + 1;
    cout<<"\nL'indirizzo di memoria della variabile vett[2] = "<<puntvettore + 2;
    cout<<"\nL'indirizzo di memoria del record = "<<puntrecord;
    cout<<"\nL'indirizzo di memoria di un secondo record = "<<puntrecord + 1;
    cout<<"\nL'indirizzo di memoria di un terzo record = "<<puntrecord + 2;
    cout<<"\n\nL'indirizzo di memoria del campo titolo del record = "<<&puntrecord -> titolo;
    cout<<"\nL'indirizzo di memoria del campo costo del record = "<<&puntrecord -> costo;
    cout<<"\nL'indirizzo di memoria del campo numero pagine del record = "<<&puntrecord -> npagine;
    cout<<"\nL'indirizzo di memoria del campo valorestorico del record = "<<&puntrecord -> valorestorico;
    cout<<"\nL'indirizzo di memoria del campo autore del record = "<<&puntrecord -> autore;
    
    //aggiungere la grandezza delle variabili col sizeof();
	cout<<"\n\n\nGrandezza"
	cout<<"\n\n\n\n"<<sizeof(num);
	cout<<"\n\n\n\n";
    
    //AGGIUNGERE ANCHE TABELLA CONTENUTO DELLE VARIABILI
    cout<<"\n\n";
    cout<<"ACQUSIZIONE VALORI DA METTERE NELLE VARIE TIPOLOGIE DI VARIABILI";
    cout<<"\ndammi un valore per la variabile num(int)";
    cin>>num;
    cout<<"\ndammi un valore per la variabile prova(string)";
    cin>>prova;
    cout<<"\ndammi un valore per la variabile prezzo(float)";
    cin>>prezzo;
    for(i=0;i<N;i++){
    	cout<<""
	}
    
    
    
    

    return 0;
}
