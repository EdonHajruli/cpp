#include <cmath>
#include <iostream>
#include <string>
using namespace std;

struct atleta{
	char nome[20];
	float peso;
	float altezza;
	int medaglie;
};

struct atleta recordfile;
FILE* puntfile;
int i,N, sizeatleta,sizefiel,ricercanelfile;
int main(){
	string gestione, aggiunta, percorso;
	cout<<"vuoi creare un file, aggiungere recordm, leggere, sovvrascrivere record, fare record? si-no: ";
	cin>>gestione;
	while(gestione == "si"){
		char percorso[40];
		cout<<"dammi il percorso del file da aprire: ";
		cin>>percorso;
		puntfile = fopen(percorso,"a"); //appertura file in modalita append al assegnazione dell'indirizzo di memoria di inizio file al puntatore
		cout<<"vuoi aggiungere record di tipo atleta? si-no: ";
		cin>>aggiunta;
		while(aggiunta == "si"){
			cout<<"dammi il nome dell'atleta: ";
			cin>>recordfile.nome;
			cout<<endl<<"dammi il peso: ";
			cin>>recordfile.peso;
			cout<<endl<<"dammi l'altezza: ";
			cin>>recordfile.altezza;
			cout<<endl<<"dammi il numero di medaglie: ";
			cin>>recordfile.medaglie;
			
			fwrite(&recordfile, sizeof(struct atleta),1,puntfile);
			cout<<"vuoi inserire un altro record? si-no"<<endl;
			cin>>aggiunta;
		}
		fclose(puntfile);
		string lettura;
		cout<<"\nvuoi vedere il contenuto del file? si-no: ";
		cin>>lettura;
		
		if(lettura == "si")
		{
			cout<<"dammi il percorso del file da stampare?"<<endl;
			cin>>percorso;
			puntfile = fopen(percorso,"r"); //apertura file in modalità "read"
			sizeatleta = sizeof(struct atleta);
		}
		
	}
	
	
	return 0;
}
