/*************************************************************************
                           Cata.cpp  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Cata> (fichier Cata.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Cata.h"
#include "Traj.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Cata::Ajouter(const Traj * l){
#ifdef MAP
	cout << "[DEBUG - Cata] Appel au Ajouter" << endl;
#endif
	if(used==taille){
		taille+=5;
		const Traj** tmp=new const Traj*[taille];
		for(int i=0;i<used;i++){
			tmp[i]=liste[i];
		}
		delete []liste;
		liste=tmp;
	}
	liste[used]=l;
	used++;
} // ----- Fin d'Ajouter

void Cata::Afficher()const{
#ifdef MAP
	cout << "[DEBUG - Cata] Appel au Afficher" << endl;
#endif
	cout<<"\n\nDans le catalogue:\n";
	for(int i=0;i<used;i++){
		cout<<"Le "<<i<<"eme trajet: \n";
		liste[i]->Afficher();
		cout<<"\n";
	}
	cout<<"\nIl y a en total "<<used<<" trajets dans la catalogue.\n"<<endl;
} // ----- Fin d'Afficher

const Traj** Cata::getListe(){
	return liste;
} // ----- Fin de getListe

int Cata::getUsed() const {
	return used;
} // ----- Fin de getUsed

int Cata::RechercherSimp(const char* Dep, const char* Arr){
#ifdef MAP
	cout << "[DEBUG - Cata] Appel au RechercherSimp" << endl;
#endif
	int nbr=0;
	
	cout<<"\n\nRechercher la(les) solution(s) de "<<Dep<<" a "<<Arr<<".\n";	
	
	for(int i=0;i<used;i++){
		// check every traj
		if(strcmp(liste[i]->getDep(),Dep)==0 && strcmp(liste[i]->getArr(),Arr)==0){
			cout<<"Le "<<i<<"eme trajet: \n";
			liste[i]->Afficher();
			cout<<"\n";
			nbr++;
		}
	}
	cout<<"Il y a en total "<<nbr<<" solution(s).\n";
	
	return nbr;
} // ----- Fin de RechercherSimp

int Cata::RechercherAva(const char* Dep, const char* Arr){
#ifdef MAP
	cout << "[DEBUG - Cata] Appel au RechercherAva" << endl;
#endif
	if(used == 0 || strcmp(Dep, Arr) == 0){
		cout << "Il n'y a pas de trajet possible dans le catalogue" << endl;
		return 0;
	}
	int * nbr = new int (0);
	int * listTraj = new int[used];
	for(int i = 0; i < used; i ++){
		listTraj[i] = 0;
	}
	
	cout<< "start RechercheAva"<< endl;
	recFind(0, listTraj, Dep, Arr, nbr);
	cout<<"Il y a en total "<<*nbr<<" solution(s).\n\n";
	int temp = *nbr;
	delete [] listTraj;
	delete nbr;
	return temp;
} // ----- Fin de RechercherAva

//------------------------------------------------- Surcharge d'opérateurs
//Cata & Cata::operator = ( const Cata & unCata )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Cata::Cata( const Cata & unCata )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cata>" << endl;
#endif
} //----- Fin de Cata (constructeur de copie)


Cata::Cata ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cata>" << endl;
#endif
	liste=new const Traj*[5];
	used=0;
	taille=5;
	
} //----- Fin de Cata


Cata::~Cata ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cata>" << endl;
#endif
	for(int i=0;i<used;i++){
		delete liste[i];
	}
	delete []liste;
} //----- Fin de ~Cata

//----------------------------------------------------- Méthodes protégées

void Cata::recFind(int idx, int * listTraj, const char* Dep, const char* Arr, int * nbr){
#ifdef MAP
	cout << "[DEBUG - Cata] Appel au recFind" << endl;
#endif
	idx++;
	for(int i = 0; i < used; i ++){
		// check every traj
		if(strcmp(liste[i]->getDep(), Dep) == 0){
			if(strcmp(liste[i]->getArr(), Arr) == 0){
				// found
				listTraj[idx - 1] = i;
				affiTraj(listTraj, idx, *nbr);
				*nbr +=1;
				continue;
			}else{
				if(!parsed(liste[i], idx, listTraj)){
					// not visited, and have a new dest other than Arr
					listTraj[idx - 1] = i;
					recFind(idx, listTraj, liste[i]->getArr(), Arr, nbr);
					// search trajs with a Dep which is the current Arr
				}
			}
		}
	}
} // ----- Fin de recFind

void Cata::affiTraj (const int * listTraj, int idx, int nbr){
#ifdef MAP
	cout << "[DEBUG - Cata] Appel au affiTraj" << endl;
#endif
	// show a valid traj from RechercheAva
	cout<<endl;
	cout<<"Le "<<nbr<<"eme trajet: \n";
	for(int i = 0; i < idx; i ++){
		liste[listTraj[i]]->Afficher();
	}
	cout<<endl;
} // ----- Fin d'affiTraj

bool Cata::parsed(const Traj* curr, int idx, int * listTraj){
#ifdef MAP
	cout << "[DEBUG - Cata] Appel au parsed" << endl;
#endif
	// check every ville parsed, avoid revisit
	if(idx >= 2 && strcmp(liste[listTraj[0]]->getDep(), curr -> getArr()) == 0){
		// at least one saved traj
		//cout<< "parsed"<< endl;
		//curr->Afficher();
		return true;
	}
	for(int i = 0; i < idx - 1; i ++){
		if(strcmp(liste[listTraj[i]] -> getArr(), curr -> getArr()) == 0){
			//cout<< "parsed"<< endl;
			//curr->Afficher();
			return true;
		}
	}
	return false;
} // ----- Fin de parsed

//------------------------------------------------------------------ PRIVE



//int Cata::recFind(int idx, int * listTraj, const char* Dep, const char* Arr, int * total){
	//cout<< "doing recFind"<< total << endl;
	//if(strcmp(Dep, Arr) == 0) {
		//// case found trajs
		//affiTraj(listTraj, idx);
		//*total ++;
		//return * total;
	//}
	//if(idx == 0){
		//// not found
		//return * total;
	//}
	//bool noPreced = false;
	//for(int i = 0; i < used; i ++){

		//cout<<"parsing traj"<<i<<endl;
		//if(strcmp(liste[i]->getArr(), Arr) == 0){
			//if(cycleFound(liste[i], idx, listTraj)){
				//// check cycle
				//continue;
			//}
			//listTraj[idx - 1] = i;
			//listTraj[used] ++;
			//noPreced = true;
			//recFind(idx - 1, listTraj, Dep, liste[i]->getDep(), total);
		//}
	//}
	//if(noPreced){
		//return * total;
	//}
	
//}
