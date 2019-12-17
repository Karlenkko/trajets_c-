/*************************************************************************
                           Traj  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Traj> (fichier Traj.h) ----------------
#if ! defined ( TRAJ_H )
#define TRAJ_H
#include <iostream>
#include <fstream>
using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Traj>
//
//
//------------------------------------------------------------------------

class Traj
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    virtual void Afficher()const;
    // Mode d'emploi :
    // Afficher la villeDep et ville d'arrivee de chaque trajet 
    // Contrat :
    // Non
    char* getDep()const;
    // Mode d'emploi :
    // Permet de utiliser la valeur de villeDep dans les autres class, par example appel de strcpy, etc.
    // Contrat :
    // Non
    char* getArr()const;
    // Mode d'emploi :
    // Permet de utiliser la valeur de villeArr dans les autres class, par example appel de strcpy, etc.
    // Contrat :
    // Non    

    virtual string toString() const;
    // Mode d'emploi :
    //
    // Contrat :
    // Non


//------------------------------------------------- Surcharge d'opérateurs
    //Traj & operator = ( const Traj & unTraj );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Traj( const Traj & unTraj );
    // Mode d'emploi (constructeur de copie) :
    // Pas tres utile, peut etre negliger dans ce TP.
    // Contrat :
    // Non

    Traj (const char* villeDep="none", const char* villeArr="none");
    // Mode d'emploi :
    // Creer un objet trajet avec une ville de depart et une ville d'arrivee avec les valeur par defaut "none"(Valeur par default n'est pas tres important apres une amelioration de interface de main).
    // Contrat :
    // Non

    virtual ~Traj ( );
    // Mode d'emploi :
    // Detuire le villeDep et villeArr dans chaque objet a la fin d'execution
    // Contrat :
    // Non
	
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	
//----------------------------------------------------- Attributs protégés
	char* villeDep;
	char* villeArr;
};

//-------------------------------- Autres définitions dépendantes de <Traj>

#endif // TRAJ_H