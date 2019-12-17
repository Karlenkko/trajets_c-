/*************************************************************************
                           TrajComp  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajComp> (fichier TrajComp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "TrajComp.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajComp::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*TrajComp & TrajComp::operator = ( const TrajComp & unTrajComp )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
/*TrajComp::TrajComp ( const TrajComp & unTrajComp )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
	int longeurDep = strlen(unTrajComp.villeDep);
	this->villeDep=new char[longeurDep+1];
	strcpy(this->villeDep,unTrajComp.villeDep);
	int longeurArr = strlen(unTrajComp.villeArr);
	this->villeArr =new char[longeurArr+1 ];
	strcpy(this->villeArr,unTrajComp.villeArr);
	this->taille=unTrajComp.taille;

	this->liste=new Traj*[unTrajComp.taille];
	for(int i=0;i<taille;i++){
		this->liste[i]=unTrajComp.liste[i];
	}
	
	
	
} //----- Fin de TrajComp (constructeur de copie)
*/

TrajComp::TrajComp (const Traj** l,int taille):Traj(l[0]->getDep(),l[taille-1]->getArr())
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajComp>" << endl;
#endif
	//taille=verifier(l,taille);
	
	this->taille=taille;
	this->liste=new const Traj*[taille];
	for(int i=0;i<taille;i++){
		liste[i]=l[i];
	}
	
} //----- Fin de TrajComp


TrajComp::~TrajComp ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajComp>" << endl;
#endif
	for(int i=0;i<taille;i++){
		delete liste[i];
	}
	delete []liste;
	//delete []villeDep;
	//delete []villeArr;
} //----- Fin de ~TrajComp

void TrajComp::Afficher()const{
	for(int i=0;i<taille;i++){
		liste[i]->Afficher();
	}
}

//void TrajComp::toString()const{
	//int size = 3; // nbr de TrajSimp
	//for(int i = 0; i < taille; i ++){
		//size += liste[i]->sizeTraj();
	//}
	//char* strTC  = new char [size+1];
	//char temp;
	//strcat(strTC, itoa(taille, temp, 10));
	//temp = ';';
	//for (int i = 0; i < taille; i++){

		
	//}
//}
/*
void TrajComp::toString(ofstream fic) const{
	fic<< taille;
	for(int i = 0; i < taille; i ++){
		liste[i]->toString1(fic);
	}
	fic<< endl;
}

void TrajComp::toString1(ofstream fic) const{
	for(int i = 0; i < taille; i ++){
		liste[i]->toString1(fic);
	}
}
*/

//int TrajComp::sizeTraj()const{
	//int size = 1;
	//for (int i = 0; i < taille; i ++){
		//size += liste[i]->sizeTraj();
	//}
//}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool TrajComp::verifier(const Traj** l, int taille){
	//int result = 1;
	for(int i = 0; i < taille - 1; i ++) {
		if(strcmp(l[i]->getArr(),l[i+1]->getDep())!=0){
			return false;
		}
	
	}	
	return true;
	
}
