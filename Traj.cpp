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

void Traj::Afficher()const{
#ifdef MAP
	cout << "[DEBUG - Traj] Appel de'Afficher" << endl;
#endif
	cout<<"Ville de depart: "<<villeDep<<endl;
	cout<<"Ville d'arrivee: "<<villeArr<<endl;
} // ----- Fin d'Afficher

char* Traj::getDep()const{
	return villeDep;
} // ----- Fin de getDep

char* Traj::getArr()const{
	return villeArr;
} // ----- Fin de getArr

string Traj::toString() const
{
#ifdef MAP
	cout << "[DEBUG - Traj] Appel de toString" << endl;
#endif
	string tmp = "1;";
	tmp.append(getDep());
	tmp.append(";");
	tmp.append(getArr());
	tmp.append(";");
	return tmp;
} // ----- Fin de toString

//------------------------------------------------- Surcharge d'opérateurs

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

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
