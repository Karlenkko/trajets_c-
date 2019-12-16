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
#define MAP


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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


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
    virtual void Afficher()const;
    // Mode d'emploi :
    // Afficher la villeDep et ville d'arrivee de chaque trajet 
    // Contrat :
    // Non
    virtual char* getDep()const;
    // Mode d'emploi :
    // Permet de utiliser la valeur de villeDep dans les autres class, par example appel de strcpy, etc.
    // Contrat :
    // Non
    virtual char* getArr()const;
    // Mode d'emploi :
    // Permet de utiliser la valeur de villeArr dans les autres class, par example appel de strcpy, etc.
    // Contrat :
    // Non    
	virtual void toString(ofstream fic) const;
	virtual void toString1(ofstream fic) const;
	//virtual int sizeTraj() const;
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	virtual void toString1(ofstream fic) const;
//----------------------------------------------------- Attributs protégés
	char* villeDep;
	char* villeArr;
	char* strT;
};

//-------------------------------- Autres définitions dépendantes de <Traj>

#endif // TRAJ_H

