/*************************************************************************
                           TrajSimp  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajSimp> (fichier TrajSimp.h) ----------------
#if ! defined ( TRAJSIMP )
#define TRAJSIMP_H
#include <fstream>
#include"Traj.h"
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
enum MOY_TRANS{AVION,BATEAU,AUTO,TRAIN};
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajSimp>
//
//
//------------------------------------------------------------------------

class TrajSimp: public Traj
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Afficher()const;
    // Mode d'emploi :
    // Afficher la villeDep et ville d'arrivee et le moyen de transport de chaque trajet.
    // Contrat :
    // Non

    virtual string toString() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    MOY_TRANS getMoyenTransport() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    //TrajSimp & operator = ( const TrajSimp & unTrajSimp );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajSimp( const TrajSimp & unTrajSimp );
    // Mode d'emploi (constructeur de copie) :
    // Pas tres utile, peut etre negliger dans ce TP.
    // Contrat :
    // Non

    TrajSimp (const char* villeDep, const char* villeArr, MOY_TRANS mt)/*:Traj(villeDep,villeArr)*/;
    // Mode d'emploi :
    // Creer un objet trajet avec une ville de depart et une ville et indiquer obligatoire le moyen de transport.
    // Contrat :
    // Non

    virtual ~TrajSimp ( );
    // Mode d'emploi :
    // On fait rien dans ce destructeur car les villeDep et les villeArr vont destruire dans le class Traj.
    // Contrat :
    // Non

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    
//----------------------------------------------------- Attributs protégés
	MOY_TRANS mt;
};

//-------------------------------- Autres définitions dépendantes de <TrajSimp>

#endif // TRAJSIMP_H