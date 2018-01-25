


//changes made at 15:18




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
float massimo(alunno vett[], int dim, string tipo);
float trovamedia(alunno vett[], int dim);
void elencomassimi(alunno vett[], int dim, string tipo);

int i;

int main(){
    int N;
    
    float giornoCor;
    float meseCor;
    float annoCor;
    
    string ricerca, scelta,tipomax;
    
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
            classe[i].magmin = "Maggiorenne";}
        if((annoCor - classe[i].datanascita.anno)<18){
            classe[i].magmin = "Minorenne";}
        if((annoCor - classe[i].datanascita.anno)==18){
            if(meseCor > classe[i].datanascita.mese){
                classe[i].magmin = "Maggiorenne";}
            if(meseCor < classe[i].datanascita.mese){
                classe[i].magmin = "Minorenne";}
            if(meseCor == classe[i].datanascita.mese){
                if(giornoCor >= classe[i].datanascita.giorno){
                    classe[i].magmin = "Maggiorenne";}
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
    
    cout<<"\n\tVuoi fare una ricerca? si/no";
    cin>>ricerca;
    while(ricerca == "si"){
        
        string tipomax;
        
        cout<<"\n\tDammi la ricerca da fare(ricercamassimo / elencomassimi / media): ";
        cin>>scelta;
        
        if(scelta == "ricercamassimo"){
            
            cout<<"\n\tDammi il massimo da cercare(italiano / matematica / sistemi / note): ";
            cin>>tipomax;
            
            cout<<"\n\tIl massimo della tipologia "<<tipomax<<" e' "<<massimo(classe,N,tipomax);
        }
        
        if(scelta == "elencomassimi"){
            cout<<"\n\tDammi il tipo di elenco dei massimi da fare(italiano / matematica / sistemi / note): ";
            cin>>tipomax;
            
            elencomassimi(classe,N,tipomax);
        }
        
        if(scelta == "media"){
            cout<<"\n\tDammi quale media fare(italiano / matematica / sistemi / note): ";
            cin>>tipomax;
            
            cout<<"\n\tLa media della tipologia "<<tipomax<<" e' "<<trovamedia(classe,N,tipomax);
        }
    }
    return 0;
}


void tabellone(alunno cl[], int dim){
    system("clear");
    cout<<"\n\n\t\tTabellone dati\n\tNome\tnote\tIta\tMate\tSitemi\tdatanascita\tanni\teta'\n";
    for(i=0;i<dim;i++){
        cout<<"\n\t"<<cl[i].nome<<"\t"<<cl[i].note<<"\t"<<cl[i].votoalunno.votoit<<"\t"<<cl[i].votoalunno.votomat<<"\t"<<cl[i].votoalunno.votosis<<"\t"<<cl[i].datanascita.giorno<<"."<<cl[i].datanascita.mese<<"."<<cl[i].datanascita.anno<<"\t"<<cl[i].anni<<"\t"<<cl[i].magmin;
    }
}

float massimo(alunno vett[], int dim, string tipo){
    float max;
    
    if(tipo == "italiano"){
        max = vett[0].votoalunno.votoit;
        for(i=0; i<dim; i++){
            if(vett[i].votoalunno.votoit>max){
                max = vett[i].votoalunno.votoit;
            }
        }
    }
    if(tipo == "matematica"){
        max = vett[0].votoalunno.votoimat;
        for(i=0; i<dim; i++){
            if(vett[i].votoalunno.votoimat>max){
                max = vett[i].votoalunno.votomat;
            }
        }
    }
    if(tipo == "sistemi"){
        max = vett[0].votoalunno.votosis;
        for(i=0; i<dim; i++){
            if(vett[i].votoalunno.votosis>max){
                max = vett[i].votoalunno.votosis;
            }
        }
    }
    if(tipo == "note"){
        max = vett[0].votoalunno.votosis;
        for(i=0; i<dim; i++){
            if(vett[i].votoalunno.votosis>max){
                max = vett[i].note;
            }
        }
    }
    return max;
}

void elencomassimi(alunno vett[], int dim, string tipo){
    int max = massimo(vett,dim,tipo);
    cout<<"\tNOME\tMASSIMO IN "<<tipo<<" = "<<max<<endl;
    for(i=0;i<dim;i++){
        if(tipo == "italiano" and vett[i].votoalunno.votoit==max){
            cout<<"\t"<<vett[i].nome<<endl;
        }
        if(tipo == "matematica" and vett[i].votoalunno.votoimat==max){
            cout<<"\t"<<vett[i].nome<<endl;
        }
        if(tipo == "sistemi" and vett[i].votoalunno.votoisis==max){
            cout<<"\t"<<vett[i].nome<<endl;
        }
        if(tipo == "note" and vett[i].note==max){
            cout<<"\t"<<vett[i].nome<<endl;
        }
    }
}

void trovamedia(alunno vett[], int dim){
    float media = 0, somma = 0;
    
    for(i=0;i<dim;i++){
        if(tipo == "italiano"){
            somma = somma + vett[i].votoalunno.votoit;
        }
        if(tipo == "matematica"){
            somma = somma + vett[i].votoalunno.votomat;
        }
        if(tipo == "sistemi"){
            somma = somma + vett[i].votoalunno.votosis;
        }
        if(tipo == "note"){
            somma = somma + vett[i].note;
        }
    }
    
    media = somma / dim;
    
    return media;
}



//changes made at 15:18








