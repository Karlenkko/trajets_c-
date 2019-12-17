/*************************************************************************
                           Traj  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Traj> (fichier Traj.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Traj.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Traj::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Traj & Traj::operator = ( const Traj & unTraj )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
Traj::Traj ( const Traj & unTraj )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Traj>" << endl;
#endif
	int longeurDep = strlen(unTraj.villeDep);
	this->villeDep=new char[longeurDep+1];
	strcpy(this->villeDep,unTraj.villeDep);
	int longeurArr = strlen(unTraj.villeArr);
	this->villeArr =new char[longeurArr+1];
	strcpy(this->villeArr,unTraj.villeArr);
} //----- Fin de Traj (constructeur de copie)


Traj::Traj (const char* villeDep, const char* villeArr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Traj>" << endl;
#endif
	int longeurDep = strlen(villeDep);
	this->villeDep=new char[longeurDep+1];
	strcpy(this->villeDep,villeDep);
	int longeurArr = strlen(villeArr);
	this->villeArr =new char[longeurArr+1 ];
	strcpy(this->villeArr,villeArr);
} //----- Fin de Traj


Traj::~Traj()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Traj>" << endl;
#endif
	delete []villeDep;
	delete []villeArr;
} //----- Fin de ~Traj

void Traj::Afficher()const{
	cout<<"Ville de depart: "<<villeDep<<endl;
	cout<<"Ville d'arrivee: "<<villeArr<<endl;
	//cout<<"Moyen de transport: ";
	/*switch(ms){
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
			cout<<"Marcher!"endl;
	}*/
}

char* Traj::getDep()const{
	return villeDep;
}

char* Traj::getArr()const{
	return villeArr;
}

//void Traj::toString()const{
	//int size = sizeTraj();
	//delete []strT;
	//strT = new char [size + 1];
	//char temp = ';';
	//strcat(strT, temp);
	//strcat(strT, liste[i]->getDep());
	//strcat(strT, temp);
	//strcat(strT, liste[i]->getArr());
	//strcat(strT, temp);
//}

/*
void Traj::toString1(ofstream fic)const{
	fic<<";"<< this->getDep() << ";"<< this->getArr() <<";";
}
*/

//int Traj::sizeTraj()const{
	//int size = 3;
	//size += strlen(villeDep);
	//size += strlen(villeArr);
	//return size;
//}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
