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
#include <fstream>
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
MOY_TRANS TrajSimp::getEnumDuTransport(int nbr)
{
#ifdef MAP
	cout << "[DEBUG - TrajSimp] Appel de getEnumDuTransport" << endl;
#endif
	switch(nbr) {
		case 1:
			return AVION;
			break;
		case 2:
			return BATEAU;
			break;
		case 3:
			return AUTO;
			break;
		case 4:
			return TRAIN;
			break;
		default:
			cout << "[ERREUR] getEnumDuTransport de TrajSimp à retourné un valeur AVION parce que le numéro de paramètre est inférièure au numéro possible!" << endl;
			return AVION;
	}
} // ----- Fin de getEnumDuTransport


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
	
	this->toString();
} //----- Fin de TrajSimp (constructeur de copie)


TrajSimp::TrajSimp (const char* villeDep, const char* villeArr, MOY_TRANS mt):Traj(villeDep,villeArr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajSimp>" << endl;
#endif
	this->toString();
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

//void TrajSimp::toString()const{
	//int size = strlen(strT) + 3;
	//char * temp = new char[size + 1];
	//char tmp[10];
	//strcat(temp, itoa(1, tmp, 10)); // nbr de TrajSimp
	//strcat(temp, strT);
	//strcat(temp, itoa((int) mt, tmp, 10)); // moy de transp
	//strcat(temp, '\n');
	//delete []strT;
	//strT = temp;
//}

void TrajSimp::toString(ofstream fic) const{
	fic<<1;
	Traj::toString1(fic);
	fic<<(int)mt<<endl;
}

void TrajSimp::toString1(ofstream fic) const{
	Traj::toString1(fic);
	fic<<(int)mt;
}

//int TrajSimp::sizeTraj()const{
	//int size = Traj::sizeTraj() + 1;
	//return size;
//}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

