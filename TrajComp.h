/*************************************************************************
                           TrajComp  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajComp> (fichier TrajComp.h) ----------------
#if ! defined ( TRAJCOMP_H )
#define TRAJCOMP_H
#include <fstream>
#include"Traj.h"
#define MAP
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajComp>
//
//
//------------------------------------------------------------------------

class TrajComp : public Traj
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
    //TrajComp & operator = ( const TrajComp & unTrajComp );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajComp ( const TrajComp & unTrajComp );
    // Mode d'emploi (constructeur de copie) :
    // Pas tres utile, peut etre negliger dans ce TP.
    // Contrat :
    // Non

    TrajComp (const Traj** l,int taille);
    // Mode d'emploi :
    // Prendre une liste de pointeur de Traj en indiquant leur taille, et les copier dans le attribut privee de ce class.
    // Contrat :
    // Non

    virtual ~TrajComp ( );
    // Mode d'emploi :
    // delete chaque objet pointeur par la liste de ce class et delete le liste a la fin.
    // Contrat :
    // Non
    void Afficher()const;
    // Mode d'emploi :
    // Afficher la villeDep et ville d'arrivee et le moyen de transport de chaque trajet.
    // Contrat :
    // Non
    static bool verifier(const Traj** l, int taille);
    // Mode d'emploi :
    // Pour verifier est-ce l'arrivee de trajet precedent est la depart de trajet suivant.(C'est pas tres important apres une amelioration de interface de main)
    // Contrat :
    // Non
    virtual void toString(ofstream fic) const;
    virtual void toString1(ofstream fic) const;
    //virtual int sizeTraj()const;
    
//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées
    
//----------------------------------------------------- Attributs protégés
	const Traj** liste;
	int taille; //Noter la taille de la liste pour faciliter l'affichage.
	
};

//-------------------------------- Autres définitions dépendantes de <TrajComp>

#endif // TRAJCOMP_H

