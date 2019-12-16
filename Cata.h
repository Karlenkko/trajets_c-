/*************************************************************************
                           Cata  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Cata> (fichier Cata.h) ----------------
#if ! defined ( CATA_H )
#define CATA_H
#include "Traj.h"
#define MAP
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cata>
//
//
//------------------------------------------------------------------------

class Cata
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //Cata & operator = ( const Cata & unCata );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Cata ( const Cata & unCata );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cata( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cata ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Ajouter(const Traj *);
    void Afficher()const;
    int RechercherSimp(const char* Dep, const char* Arr);
    const Traj** getListe();
	int RechercherAva(const char* Dep, const char* Arr);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	void recFind(int idx, int * listTraj, const char* Dep, const char* Arr, int * total);
	void affiTraj(const int * listTraj, int idx, int nbr);
	bool parsed(const Traj* curr, int idx, int * listTraj);
//----------------------------------------------------- Attributs protégés
	const Traj** liste;
	int taille;
	int used;
};

//-------------------------------- Autres définitions dépendantes de <Cata>

#endif // CATA_H

