/*************************************************************************
                           TrajSimp  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajSimp> (fichier TrajSimp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajSimp.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajSimp::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*TrajSimp & TrajSimp::operator = ( const TrajSimp & unTrajSimp )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
TrajSimp::TrajSimp ( const TrajSimp & unTrajSimp ) 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajSimp>" << endl;
#endif
	int longeurDep = strlen(unTrajSimp.villeDep);
	this->villeDep=new char[longeurDep+1];
	strcpy(this->villeDep,unTrajSimp.villeDep);
	int longeurArr = strlen(unTrajSimp.villeArr);
	this->villeArr =new char[longeurArr+1];
	strcpy(this->villeArr,unTrajSimp.villeArr);
	this->mt=unTrajSimp.mt;
} //----- Fin de TrajSimp (constructeur de copie)


TrajSimp::TrajSimp (const char* villeDep, const char* villeArr, MOY_TRANS mt):Traj(villeDep,villeArr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajSimp>" << endl;
#endif
	this->mt=mt;
} //----- Fin de TrajSimp


TrajSimp::~TrajSimp ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajSimp>" << endl;
#endif
	//delete []villeDep;
	//delete []villeArr;

} //----- Fin de ~TrajSimp

void TrajSimp::Afficher()const{
	Traj::Afficher();
	cout<<"Moyen de transport: ";
	switch(mt){
		case 0:
			cout<<"Avion"<<endl;
			break;
		case 1: 
			cout<<"Bateau"<<endl;
			break;
		case 2:
			cout<<"Auto"<<endl;
			break;
		case 3:
			cout<<"Train"<<endl;
			break;
		default: 
			cout<<"Marcher!"<<endl;
	}
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

