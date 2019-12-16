#include <iostream>
#include <cstring>
#include "Traj.h"
#include "TrajComp.h"
#include "TrajSimp.h"
#include "Cata.h"
using namespace std;



//int main(){
	
	/*Traj* t1=new TrajSimp("Paris","Lyon",AVION);
	Traj* t2=new TrajSimp("Lyon","Marseille",TRAIN);
	//Traj* t4=new TrajSimp("Lyon","Paris",BATEAU);
	const Traj** l=new const Traj*[2];
	l[0]=t1;
	l[1]=t2; 
	//l[2]=t4;
	if(TrajComp::verifier(l,2)){
	        TrajComp* t3=new TrajComp(l,2);
		delete t3;
		delete l;
	}
	else {
		cout<<"\n\nFaux\n\n";
		delete t1;
		delete t2;
		//delete t4;
	        delete l;
	}*/
	//t3->Afficher();


// desous seulement cree, desus pour la 
/*
	Traj* t1=new TrajSimp("Paris","Lyon",AVION);
	Traj* t2=new TrajSimp("Lyon","Marseille",TRAIN);
	Traj* t4=new TrajSimp("Lyon","Paris",BATEAU);
	const Traj** l=new const Traj*[2];
	l[0]=t1;
	l[1]=t2; 
	TrajComp* t3=new TrajComp(l,2);
	Cata* ca=new Cata();
	
	ca->Ajouter(t1);
	ca->Ajouter(t2);
	ca->Ajouter(t3);
	ca->Ajouter(t4);
	
	ca->Afficher();
	ca->RechercherSimp("Paris","Lyon");
	//delete t1;
	//delete t2;
	delete t3;
	delete t4;
	delete ca;
	delete l;
	return 0;
}



*/
void chercherSimp(Cata* ca){
	char* dep=new char[20];
	char* arr=new char[20];
	cout<<"Composez la position de depart."<<endl;
	cin>>dep;
	cout<<"Composez la position d'arrive"<<endl;
	cin>>arr;
	ca->RechercherSimp(dep,arr);
	delete []dep;
	delete []arr;
}

void chercherAva(Cata* ca){
	char* dep=new char[20];
	char* arr=new char[20];
	cout<<"Composez la position de depart."<<endl;
	cin>>dep;
	cout<<"Composez la position d'arrive"<<endl;
	cin>>arr;
	ca->RechercherAva(dep,arr);
	delete []dep;
	delete []arr;
}

void ajouteTrajSimp(Cata* ca){
	char* dep=new char[20];
	char* arr=new char[20];
	int i;
	cout<<"Composez la position de depart de ce Trajet Simple."<<endl;
	cin>>dep;
	cout<<"Composez la position d'arrive de ce Trajet Simple."<<endl;
	cin>>arr;
	cout<<"Composez une moyen de transport."<<endl;
	cout<<"0 pour Avion"<<endl;
	cout<<"1 pour Bateau"<<endl;
	cout<<"2 pour Auto"<<endl;
	cout<<"3 pour Train"<<endl;
	cin>>i;
	Traj* t = new TrajSimp(dep,arr,(MOY_TRANS)i);   //probleme
	ca->Ajouter(t);
	delete []dep;
	delete []arr;
}


void ajouteTrajComp(Cata* ca){
	int n;
	cout<<"Composez le nombre de Trajet Simple contient le Trajet Compose."<<endl;
	cin>>n;
	const Traj** l=new const Traj*[n];
	char* dep=new char[20];
	char* arr=new char[20];
	int a;
	cout<<"Composez la position de depart de ce Trajet Composez."<<endl;
	cin>>dep;
	for(int i=0;i<n;i++){
		cout<<"Composez la position d'arrive de ce Trajet."<<endl;
		cin>>arr;
		cout<<"Composez une moyen de transport."<<endl;
		cout<<"0 pour Avion"<<endl;
		cout<<"1 pour Bateau"<<endl;
		cout<<"2 pour Auto"<<endl;
		cout<<"3 pour Train"<<endl;
		cin>>a;
		Traj* t = new TrajSimp(dep,arr,(MOY_TRANS)a);    //probleme
		l[i]=t;
		delete []dep;
		dep=arr;   //probleme
		arr=new char[20];
	}
	TrajComp* tc=new TrajComp(l,n);
	ca->Ajouter(tc);
	delete []dep;
	delete []arr;
	delete [] l;  
}

int main(){
	int nbr=0,b=1;
	char n;
	Cata* ca = new Cata();
	cout<<"<Catalogue de trajet>"<<endl;
	while(b==1){
		cout<<"Composer les chiffres pour faire des instructions."<<endl;
		cout<<"1.Ajouter un trajet Simple dans la catalogue."<<endl;
		cout<<"2.Ajouter un trajet Compose dans la catalogue."<<endl;
		cout<<"3.Afficher des trajets qui sont deja existe dans la catalogue."<<endl;
		cout<<"4.Chercher un trajets en utilisant le facon simple."<<endl;
		cout<<"5.Chercher un trajets en utilisant le facon avancee."<<endl;
		cout<<"6.Terminer."<<endl;
		cin>>n;
		switch(n){
			case '1':
				ajouteTrajSimp(ca);
				nbr++;
				break;
			case '2':
				ajouteTrajComp(ca);
				nbr++;
				break;
			case '3':
				ca->Afficher();
				break;
			case '4':
				chercherSimp(ca);
				break;
			case '5':
				chercherAva(ca);
				break;
			case '6':
				b=0;
				for(int i=0;i<nbr;i++){
					delete ca->getListe()[i];
				}
				delete ca;
				break;
			default:
				cout<<"input error"<<endl;
				cin.clear();
		}
		if(b==0){
			break;
		}
	}
	return 0;
}
