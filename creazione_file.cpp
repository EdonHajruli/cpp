#include <cmath>
#include <iostream>
#include <string>
using namespace std;

struct atleta
{
	char nome[20];
	float peso;
	float altezza;
	int medaglie;
};

struct atleta recordfile;
FILE* puntfile;
int i,N, sizeatleta,sizefile,nrecordfile, trovato, sizerecord = sizeof(atleta);

int main()
{
	string gestione, aggiunta, percorso;
	cout<<"vuoi creare un file, aggiungere record, leggere, sovvrascrivere record, fare record? si-no: ";
	cin>>gestione;
	while(gestione == "si")
	{
		char percorso[40];
		cout<<"dammi il percorso del file da aprire: ";
		cin>>percorso;
		puntfile = fopen(percorso,"a"); //appertura file in modalita append al assegnazione dell'indirizzo di memoria di inizio file al puntatore
		cout<<"vuoi aggiungere record di tipo atleta? si-no: ";
		cin>>aggiunta;
		
		while(aggiunta == "si")
		{
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
			fseek(puntfile,0,SEEK_END);
			sizefile=ftell(puntfile);
			nrecordfile=sizefile/sizeatleta;
			cout<<"la lunghezza in byte del record 'atleta' e' pari a = "<<sizeatleta<<endl;
			cout<<"la lunghezza in byte del file "<<percorso<<" = "<<sizefile<<endl;
			cout<<"il numero di record nel file e' pari a "<<nrecordfile<<endl<<endl<<endl<<endl;
			cout<<"TABELLONE DATI"<<endl;
			cout<<"NOME\tPESO\tALTEZZA\tMEDAGLIE\n";
			for(i=0;i<nrecordfile;i++)
			{
				fseek(puntfile,sizeof(struct atleta)*i,SEEK_SET);
				fread(&recordfile,sizeof(struct atleta),1,puntfile);
				cout<<recordfile.nome<<"\t"<<recordfile.peso<<"\t"<<recordfile.altezza<<"\t"<<recordfile.medaglie<<"\n";
			}
			fclose(puntfile);
		}
		
        
        string sovra;
        int recordnumero;
        cout<<"vuoi sovrascrivere un record?si-no: ";
        cin>>sovra;
        while(sovra == "si"){
            cout<<"dammi il percorso del file: ";
            cin>>percorso;
            cout<<"dammi il numero del record da sovrascrivere (il primo record ha numero 0): ";
            cin>>recordnumero;
            puntfile=fopen(percorso,"r+");
            cout<<"NUOVI DATI\n\n";
            cout<<"dammi il nome dell'atleta: ";
            cin>>recordfile.nome;
            cout<<endl<<"dammi il peso: ";
            cin>>recordfile.peso;
            cout<<endl<<"dammi l'altezza: ";
            cin>>recordfile.altezza;
            cout<<endl<<"dammi il numero di medaglie: ";
            cin>>recordfile.medaglie;
            
            fseek(puntfile,sizeof(struct atleta)*recordnumero,SEEK_SET);
            fwrite(&recordfile,sizeof(struct atleta),1,puntfile);
            fclose(puntfile);
            cout<<"vuoi sovrascrivere un altro record? si-no: ";
            cin>>sovra;
            
        }
        
        string ricercanome, nomeatleta;
        cout<<"vuoi la ricerca per nome?"<<endl;
        cin>>ricercanome;
        while (ricercanome=="si") {
            cout<<"dammi il nome da cercare: ";
            cin>>nomeatleta;
            cout<<"dammi il percorso del file: ";
            cin>>percorso;
            puntfile=fopen(percorso,"r");
            trovato = 0;
            sizeatleta = sizeof(struct atleta);
            fseek(puntfile,0,SEEK_END);
            sizefile = ftell(puntfile);
            nrecordfile = sizefile/sizeatleta;
            cout<<"TABELLONE DATI"<<endl;
            cout<<"NOME\tPESO\tALTEZZA\tMEDAGLIE\n";
            for(i=0; i<nrecordfile; i++){
                fseek(puntfile,sizeof(struct atleta)*i,SEEK_SET);
                fread(&recordfile,sizeof(struct atleta),1,puntfile);
                if(recordfile.nome == nomeatleta){
                    cout<<recordfile.nome<<"\t"<<recordfile.peso<<"\t"<<recordfile.altezza<<"\t"<<recordfile.medaglie<<"\n";
                    trovato = 1;
                }
            }
            if(trovato == 0){
                cout<<"\n\nnessun atleta e' stato trovato!\n";
            }
            fclose(puntfile);
            cout<<"vuoi fare un altra ricerca per nome? si-no: ";
            cin>>ricercanome;
        }
        
        string elencomaxmed;
        cout<<"vuoi elencare i posessori del max numero di medaglie? si-no: ";
        cin>>elencomaxmed;
        int max;
        cout<<"dammi il percorso del file: ";
        cin>>percorso;
        puntfile=fopen(percorso,"r");
        fseek(puntfile,0,SEEK_END);//mi posziono a fine file
        sizefile=ftell(puntfile);
        nrecordfile=sizefile/sizerecord;
        fseek(puntfile,0,SEEK_SET);//si posiziona all'inizio
        fread(&recordfile, sizerecord,1,puntfile);//leggo il file
        max = recordfile.medaglie;
        for(i=0;i<nrecordfile;i++){
            fseek(puntfile,sizerecord*i,SEEK_SET);//si posiziona all'inizio
            fread(&recordfile, sizerecord,1,puntfile);//leggo il file
            if(recordfile.medaglie>max){
                max=recordfile.medaglie;
            }
        }
        cout<<"il numero massimo di medaglie e' pari a "<<max;
        
        cout<<"\n\n\tTABELLA DATI"<<endl;
        cout<<"NOME\tPESO\tALTEZZA\tMEDAGLIE\n";
        for(i=0;i<nrecordfile;i++){
            fseek(puntfile,sizerecord*i,SEEK_SET);//si posiziona all'inizio
            fread(&recordfile, sizerecord,1,puntfile);//leggo il file
            if(recordfile.medaglie == max){
                cout<<recordfile.nome<<"\t"<<recordfile.peso<<"\t"<<recordfile.altezza<<"\t"<<recordfile.medaglie<<"\n";
            }
        
            fclose(puntfile);
        }
        
        cout<<"vuoi rimanere nel programma? si-no: ";
        cin>>gestione;
	}
	
	
	return 0;
}
