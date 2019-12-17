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

    void Ajouter(const Traj *);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher()const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int RechercherSimp(const char* Dep, const char* Arr);
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Traj** getListe();
    // Mode d'emploi :
    //
    // Contrat :
    //

	int RechercherAva(const char* Dep, const char* Arr);
    // Mode d'emploi :
    //
    // Contrat :
    //

	int getUsed() const;
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
    
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	void recFind(int idx, int * listTraj, const char* Dep, const char* Arr, int * total);
    // Mode d'emploi :
    //
    // Contrat :
    //

	void affiTraj(const int * listTraj, int idx, int nbr);
    // Mode d'emploi :
    //
    // Contrat :
    //

	bool parsed(const Traj* curr, int idx, int * listTraj);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
//----------------------------------------------------- Attributs protégés
	const Traj** liste;
	int taille;
	int used;
};

//-------------------------------- Autres définitions dépendantes de <Cata>

#endif // CATA_H