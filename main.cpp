//
//  main.cpp
//  daatabase_studenti_funzioni_record
//
//  Created by Apple on 21/01/18.
//  Copyright © 2018 Edon Hajruli. All rights reserved.
//

#include <cmath>
#include <string>
#include <iostream>
using namespace std;

struct voti{
    float votoit;
    float votomat;
    float votosis;
};
struct data{
    float giorno;
    float mese;
    float anno;
};
struct alunno{
    string nome;
    float anni;
    int note;
    data datanascita;
    voti votoalunno;
    string magmin;
};

void tabellone(alunno cl[], int dim);

int i;

int main(){
    int N;
    float giornoCor;
    float meseCor;
    float annoCor;
    
    cout<<"\tDammi il numero di alunni: ";
    cin>>N;
    cout<<"\n\tDammi il giorno corrente: ";
    cin>>giornoCor;
    cout<<"\n\tDammi il mese corrente: ";
    cin>>meseCor;
    cout<<"\n\tDammi l'anno corrente: ";
    cin>>annoCor;
    
    alunno classe[N];
    
    for(i=0;i<N;i++){
        cout<<"\n\n\tDammi il nome del "<<i+1<<" alunno: ";
        cin>>classe[i].nome;
        cout<<"\n\tDammi il numero di note: ";
        cin>>classe[i].note;
        cout<<"\n\tDammi il voto di italiano: ";
        cin>>classe[i].votoalunno.votoit;
        cout<<"\n\tDammi il voto di matematica: ";
        cin>>classe[i].votoalunno.votomat;
        cout<<"\n\tDammi il voto di sistemi: ";
        cin>>classe[i].votoalunno.votosis;
        cout<<"\n\tDammi la data di nascita(clicca invio ogni digitazione fatta mettendo prima il giorno poi mese e anno): ";
        cin>>classe[i].datanascita.giorno>>classe[i].datanascita.mese>>classe[i].datanascita.anno;
        
        // algoritmo determinazione maggiorenne/minorenne
        if((annoCor - classe[i].datanascita.anno)>18){
            classe[i].magmin = "Maggiorenne";
        }
        if((annoCor - classe[i].datanascita.anno)<18){
            classe[i].magmin = "Minorenne";
        }
        if((annoCor - classe[i].datanascita.anno)==18){
            if(meseCor > classe[i].datanascita.mese){
                classe[i].magmin = "Maggiorenne";
            }
            if(meseCor < classe[i].datanascita.mese){
                classe[i].magmin = "Minorenne";
            }
            if(meseCor == classe[i].datanascita.mese){
                if(giornoCor >= classe[i].datanascita.giorno){
                    classe[i].magmin = "Maggiorenne";
                }
                if(giornoCor < classe[i].datanascita.giorno){
                    classe[i].magmin = "Minorenne";
                }
            }
        }
        //fine algoritmo
        //______________________________________________________________
        //algoritmo calcolo anni
        classe[i].anni = (annoCor - classe[i].datanascita.anno);
        
        if(classe[i].datanascita.mese < meseCor) {
            classe[i].anni--;
        }
        if(classe[i].datanascita.mese == meseCor) {
            if(classe[i].datanascita.giorno < giornoCor){
                classe[i].anni--;
            }
        }
        //fine algoritmo
        //______________________________________________________________
    }// fine for
    
    tabellone(classe,N);
    return 0;
}

void tabellone(alunno cl[], int dim){
    system("clear");
    cout<<"\n\n\t\tTabellone dati\n\tNome\tnote\tIta\tMate\tSitemi\tdatanascita\tanni\teta'\n";
    
    for(i=0;i<dim;i++){
        cout<<"\n\t"<<cl[i].nome<<"\t"<<cl[i].note<<"\t"<<cl[i].votoalunno.votoit<<"\t"<<cl[i].votoalunno.votomat<<"\t"<<cl[i].votoalunno.votosis<<"\t"<<cl[i].datanascita.giorno<<"."<<cl[i].datanascita.mese<<"."<<cl[i].datanascita.anno<<"\t"<<cl[i].anni<<"\t"<<cl[i].magmin;
    }
    
}

//la modifica è stata fatta