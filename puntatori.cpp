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

	for(i=0;i<N;i++){
		cout<<"\n\nL'indirizzo di memoria del vettore vett["<<i<<"] = "<<puntvettore;
		puntvettore++;
	}
    
    
    cout<<"\n\nL'indirizzo di memoria del record libro = "<<puntrecord;
    cout<<"\nL'indirizzo di memoria di un secondo record = "<<puntrecord + 1;
    cout<<"\nL'indirizzo di memoria di un terzo record = "<<puntrecord + 2;
    
    cout<<"\n\nL'indirizzo di memoria del campo titolo del record = "<<&puntrecord -> titolo;
    cout<<"\nL'indirizzo di memoria del campo costo del record = "<<&puntrecord -> costo;
    cout<<"\nL'indirizzo di memoria del campo numero pagine del record = "<<&puntrecord -> npagine;
    cout<<"\nL'indirizzo di memoria del campo valorestorico del record = "<<&puntrecord -> valorestorico;
    cout<<"\nL'indirizzo di memoria del campo autore del record = "<<&puntrecord -> autore;
    
    //aggiungere la grandezza delle variabili col sizeof();
    
	cout<<"\n\n\nLa grandezza di memoria della variabile num(int) = "<<sizeof(num);
	cout<<"\nLa grandezza di memoria della variabile N(int) = "<<sizeof(N);
	cout<<"\nLa grandezza di memoria della variabile prova = "<<sizeof(prova);
	cout<<"\nLa grandezza di memoria della variabile prezzo = "<<sizeof(prezzo);
	cout<<"\n\nLa grandezza di memoria del vettore vett[0] = "<<sizeof(vett[0]);
	cout<<"\nLa grandezza di memoria del vettore vett[1] = "<<sizeof(vett[1]);
	cout<<"\nLa grandezza di memoria del vettore vett[2] = "<<sizeof(vett[2]);
	cout<<"\n\nLa grandezza di memoria del record libro = "<<sizeof(struct libro);
	cout<<"\nLa grandezza di memoria della var. titolo nel record libro = "<<sizeof(volume.titolo);
	cout<<"\nLa grandezza di memoria della var. costo nel record libro = "<<sizeof(volume.costo);
	cout<<"\nLa grandezza di memoria della var. npagine nel record libro = "<<sizeof(volume.npagine);
	cout<<"\nLa grandezza di memoria della var. valorestorico nel record libro = "<<sizeof(volume.valorestorico);
	cout<<"\nLa grandezza di memoria della var. autore nel record libro = "<<sizeof(volume.autore);

    
    
    
    
    //AGGIUNGERE ANCHE TABELLA CONTENUTO DELLE VARIABILI
    cout<<"\n\n\n";
    cout<<"ACQUSIZIONE VALORI DA METTERE NELLE VARIE TIPOLOGIE DI VARIABILI";
    cout<<"\nDammi un valore per la variabile num(int): ";
    cin>>num;
    cout<<"\nDammi un valore per la variabile prova(string): ";
    cin>>prova;
    cout<<"\nDammi un valore per la variabile prezzo(float): ";
    cin>>prezzo;
    for(i=0;i<N;i++){
    	cout<<"\nDammiil valore del vettore (float) vett["<<i<<"]:  ";
    	cin>>vett[i];
	}
	cout<<"\nDammi campo titolo( <20 carattri ): ";
	cin>>volume.titolo;
	cout<<"\nDammi il campo costo (float): ";
    cin>>volume.costo;
    cout<<"\nDammi il campo npagine (int): ";
    cin>>volume.npagine;
    cout<<"\nDammi il campo autore ( <16 caratteri ): ";
    cin>>volume.autore;
    
    puntint =& num;
    cout<<"\n\n\nSTAMPA VALORI ACQUISITI DELLE VARIE TIPOLOGIE DI VARIABILI";
    cout<<"\nIl valore della variabile num = "<<num<<endl<<*puntint;
    puntint =& N;
    cout<<"\nIl valore della variabile N = "<<N<<endl<<*puntint;
    cout<<"\nIl valore della variabile prova = "<<prova<<endl<<*puntstring;
    cout<<"\nIl valore della variabile prezzo = "<<prezzo<<endl<<*puntnumero<<"\n";
    
    for(i=0;i<N;i++){
    	cout<<"\nIl valore del vettore vett["<<i<<"] = "<<puntvettore;
    	puntvettore++;
	}
	
    return 0;
}
