#include <iostream>
#include <cstring>
#include <fstream>
#include "Traj.h"
#include "TrajComp.h"
#include "TrajSimp.h"
#include "Cata.h"
//#define MAP
using namespace std;
char villeCompare[100];
int currNum = 0;
int rangeN = 1;
int rangeM = 0;
void chercherSimp(Cata* ca){
#ifdef MAP
	cout << "[DEBUG - main] Appel au chercherSimp" << endl;
#endif
	char* dep=new char[20];
	char* arr=new char[20];
	cout<<"Composez la position de depart."<<endl;
	cin>>dep;
	cout<<"Composez la position d'arrive"<<endl;
	cin>>arr;
	ca->RechercherSimp(dep,arr);
	delete []dep;
	delete []arr;
} // ----- Fin de chercherSimp

void chercherAva(Cata* ca){
#ifdef MAP
	cout << "[DEBUG - main] Appel au chercherAva" << endl;
#endif
	char* dep=new char[20];
	char* arr=new char[20];
	cout<<"Composez la position de depart."<<endl;
	cin>>dep;
	cout<<"Composez la position d'arrive"<<endl;
	cin>>arr;
	ca->RechercherAva(dep,arr);
	delete []dep;
	delete []arr;
} // ----- Fin de chercherAva

void ajouteTrajSimp(Cata* ca){
#ifdef MAP
	cout << "[DEBUG - main] Appel au ajouteTrajSimp" << endl;
#endif
	char* dep=new char[20];
	char* arr=new char[20];
	int i;
	cout<<"Composez la position de depart de ce Trajet Simple."<<endl;
	cin>>dep;
	cout<<"Composez la position d'arrive de ce Trajet Simple."<<endl;
	cin>>arr;
	cout<<"Composez une moyen de transport."<<endl;
	cout<<"0 pour Avion"<<endl;
	cout<<"1 pour Bateau"<<endl;
	cout<<"2 pour Auto"<<endl;
	cout<<"3 pour Train"<<endl;
	cin>>i;
	Traj* t = new TrajSimp(dep,arr,(MOY_TRANS)i);   //probleme
	ca->Ajouter(t);
	delete []dep;
	delete []arr;
} // ----- Fin de ajouteTrajSimp


void ajouteTrajComp(Cata* ca){
#ifdef MAP
	cout << "[DEBUG - main] Appel au ajouteTrajComp" << endl;
#endif
	int n;
	cout<<"Composez le nombre de Trajet Simple contient le Trajet Compose."<<endl;
	cin>>n;
	const Traj** l=new const Traj*[n];
	char* dep=new char[20];
	char* arr=new char[20];
	int a;
	cout<<"Composez la position de depart de ce Trajet Composez."<<endl;
	cin>>dep;
	for(int i=0;i<n;i++){
		cout<<"Composez la position d'arrive de ce Trajet."<<endl;
		cin>>arr;
		cout<<"Composez une moyen de transport."<<endl;
		cout<<"0 pour Avion"<<endl;
		cout<<"1 pour Bateau"<<endl;
		cout<<"2 pour Auto"<<endl;
		cout<<"3 pour Train"<<endl;
		cin>>a;
		Traj* t = new TrajSimp(dep,arr,(MOY_TRANS)a);    //probleme
		l[i]=t;
		delete []dep;
		dep=arr;   //probleme
		arr=new char[20];
	}
	TrajComp* tc=new TrajComp(l,n);
	ca->Ajouter(tc);
	delete []dep;
	delete []arr;
	delete [] l;
}  // ----- Fin de ajouteTrajComp

bool sauvegarde(Cata* cata, string nomFichier, bool doitEtreSauvegarde(const Traj*))
// Mode d'emploi :
// Sauvegarder un fichier csv de la même dossier comme cette application.
// 
// Contrat :
// cata: instance d'objet Cata
// nomFichier: nom du fichier pour sauvegarder (peut inclure un path)
// doitEtreSauvegarde: fonctionne anonyme pour déterminer quels trajets devent être sauvegardé
{
#ifdef MAP
	cout << "[DEBUG] Appel au sauvegarde" << endl;
#endif
	ofstream fic;
	fic.open(nomFichier);

	const Traj** liste = cata -> getListe();
	int i;
	bool first = true;
	for (i = 0; i < cata -> getUsed(); i++) {
		if (doitEtreSauvegarde(liste[i]) && fic.good()) {
			if(!first) fic << endl << liste[i] -> toString();
			else fic << liste[i] -> toString();
			first = false;
		}
	}

	fic.close();
	return true;
}  // ----- Fin de sauvegarde

bool telecharge(Cata* cata, string nomFichier, bool doitEtreTelecharge(const Traj*))
// Mode d'emploi :
// Télécharger un fichier csv de la même dossier comme cette application.
// 
// Contrat :
// cata: instance d'objet Cata
// nomFichier: nom du fichier pour télécharger
// doitEtreTelecharge: fonctionne anonyme pour déterminer quels trajets devent être téléchargé
{
#ifdef MAP
	cout << "[DEBUG] Appel au telecharge" << endl;
#endif
	ifstream fic;
	fic.open(nomFichier);
	string ligne;
	while (!fic.eof()) {
		getline(fic, ligne, '\n');
		
		if(ligne == ""|| ligne == "\n") continue;
		int cursor = ligne.find(';');
		int nbrTrajets = stoi(ligne.substr(0, cursor));
		ligne.erase(0, cursor + 1);

		if (nbrTrajets == 1) { // trajet simple
			cursor = ligne.find(';');
			string tmpDepart = ligne.substr(0, cursor);
			ligne.erase(0, cursor + 1);

			cursor = ligne.find(';');
			string tmpArrive = ligne.substr(0, cursor);
			ligne.erase(0, cursor + 1);

			cursor = ligne.find('\n');
			int tmpMT = stoi(ligne.substr(0, cursor));
			ligne.erase(0, cursor + 1);
			
			Traj* trajet = new TrajSimp(tmpDepart.c_str(), tmpArrive.c_str(),(MOY_TRANS) tmpMT);
			
			#ifdef MAP
				cout << "[IMPORT] Trajet simple trouvé: " << trajet -> toString() << endl;
			#endif
			if(doitEtreTelecharge(trajet)) cata -> Ajouter(trajet);
			else delete trajet;
		} else { // trajet composé
			const Traj** trajetsArr = new const Traj*[nbrTrajets];
			int i;
			for (i = 0; i < nbrTrajets; i++) {
				cursor = ligne.find(';');
				string tmpDepart = ligne.substr(0, cursor);
				ligne.erase(0, cursor + 1);

				cursor = ligne.find(';');
				string tmpArrive = ligne.substr(0, cursor);
				ligne.erase(0, cursor + 1);

				cursor = ligne.find(';');
				cout << "Input lit: " << cursor << endl;
				int tmpMT = stoi(ligne.substr(0, cursor));
				ligne.erase(0, cursor + 1);

				Traj* trajet = new TrajSimp(tmpDepart.c_str(), tmpArrive.c_str(), (MOY_TRANS) tmpMT);
				#ifdef MAP
					cout << "[IMPORT] Trajet simple ajouté au trajet composé: " << trajet -> toString() << endl;
				#endif
				trajetsArr[i] = trajet;
			}

			Traj* nouvTrajet = new TrajComp(trajetsArr, nbrTrajets);
			#ifdef MAP
				cout << "[IMPORT] Trajet composé trouvé: " << nouvTrajet -> toString() << endl;
			#endif
			if(doitEtreTelecharge(nouvTrajet)) cata -> Ajouter(nouvTrajet);
			else delete nouvTrajet;
			delete [] trajetsArr;
			
			
		}	
	}
	fic.close();
	return true;
} // ----- Fin de telecharge

bool isSimple(const Traj* trajet){
	if (trajet->getTaille() == 1) return true; // TODO
	else return false;
}

bool isDep(const Traj* trajet, const char* ville){
	return (strcmp(ville, trajet->getDep()) == 0);
}

bool isArr(const Traj* trajet, const char* ville){
	return (strcmp(ville, trajet->getArr()) == 0);
}

void getNM (){
	string temp;
	do{
		cout<< "Saisir n"<< endl;
		cin>>temp;
		rangeN = stoi(temp);
		cout<< "Saisir m"<< endl;
		cin>>temp;
		rangeM = stoi(temp);
	}while (rangeM - rangeN + 1 < 1);
}

int main(){
	int nbr=0,b=1;
	char n;
	Cata* ca = new Cata();

	string nomFichier = "Catalogue.csv";
	
	cout<<"<Catalogue de trajet>"<<endl;
	while(b==1){
		cout<<"Composer les chiffres pour faire des instructions."<<endl;
		cout<<"1.Ajouter un trajet Simple dans la catalogue."<<endl;
		cout<<"2.Ajouter un trajet Compose dans la catalogue."<<endl;
		cout<<"3.Afficher des trajets qui sont deja existe dans la catalogue."<<endl;
		cout<<"4.Chercher un trajets en utilisant le facon simple."<<endl;
		cout<<"5.Chercher un trajets en utilisant le facon avancee."<<endl;
		cout<<"6.Sauvegarde le catalogue."<<endl;
		cout<<"7.Télécharge le catalogue."<<endl;
		cout<<"8.Terminer."<<endl;
		cin>>n;
		switch(n){
			case '1':
				ajouteTrajSimp(ca);
				nbr++;
				break;
			case '2':
				ajouteTrajComp(ca);
				nbr++;
				break;
			case '3':
				ca->Afficher();
				break;
			case '4':
				chercherSimp(ca);
				break;
			case '5':
				chercherAva(ca);
				break;
			case '6':
				cout<<"Composer les chiffres pour faire des instructions."<<endl;
				cout<<"1.Sauvegarde tous trajets."<<endl;
				cout<<"2.Sauvegarde tous trajets simples."<<endl;
				cout<<"3.Sauvegarde tous trajets composés."<<endl;
				cout<<"4.Sauvegarde selon ville de depart."<<endl;
				cout<<"5.Sauvegarde selon ville d'arrivee."<<endl;
				cout<<"6.Sauvegarde selon un intervalle."<<endl;
				cout<<"8.Terminer."<<endl;
				cin>>n;
				switch(n){
					case '1':
						sauvegarde(ca, nomFichier, [](const Traj* trajet) -> bool {return true;});
						break;
					case '2':
						sauvegarde(ca, nomFichier, [](const Traj* trajet) -> bool {
							return isSimple(trajet);
						});
						break;
					case '3':
						sauvegarde(ca, nomFichier, [](const Traj* trajet) -> bool {
							return (!isSimple(trajet));
						});
						break;
					case '4':
						cout<<"Saisir la ville de depart"<<endl;
						cin>>villeCompare;
						sauvegarde(ca, nomFichier, [](const Traj* trajet) -> bool {
							return isDep(trajet, villeCompare);
						});
						break;
					case '5':
						cout<<"Saisir la ville d'arrivee"<<endl;
						cin>>villeCompare;
						sauvegarde(ca, nomFichier, [](const Traj* trajet) -> bool {
							return isArr(trajet, villeCompare);
						});
						break;
					case '6':
						getNM();
						currNum = 0;
						sauvegarde(ca, nomFichier, [](const Traj* trajet) -> bool {
							currNum ++;
							if((currNum - 1) >= rangeN && (currNum - 1) <= rangeM) return true;
							else return false;
						});
						break;
					case '8':
						break;
					default:
						break;
				}
				break;
			case '7':
				cout<<"Composer les chiffres pour faire des instructions."<<endl;
				cout<<"1.Télécharge tous trajets."<<endl;
				cout<<"2.Télécharge tous trajets simples."<<endl;
				cout<<"3.Télécharge tous trajets composés."<<endl;
				cout<<"4.Télécharge selon ville de depart."<<endl;
				cout<<"5.Télécharge selon ville d'arrivee."<<endl;
				cout<<"6.Télécharge selon un intervalle."<<endl;
				cout<<"8.Terminer."<<endl;
				cin>>n;
				switch(n){
					case '1':
						telecharge(ca, nomFichier, [](const Traj* trajet) -> bool {return true;});
						break;
					case '2':
						telecharge(ca, nomFichier, [](const Traj* trajet) -> bool {
							return isSimple(trajet);
							//return true; // TODO
						});
						break;
					case '3':
						telecharge(ca, nomFichier, [](const Traj* trajet) -> bool {
							return (!isSimple(trajet));
							//return true; // TODO
						});
						break;
					case '4':
						cout<<"Saisir la ville de depart"<<endl;
						cin>>villeCompare;				
						telecharge(ca, nomFichier, [](const Traj* trajet) -> bool {
							return isDep(trajet, villeCompare);
						});
						break;
					case '5':
						cout<<"Saisir la ville d'arrivee"<<endl;
						cin>>villeCompare;					
						telecharge(ca, nomFichier, [](const Traj* trajet) -> bool {
							return isArr(trajet, villeCompare);
						});
						break;
					case '6':
						getNM();
						currNum = 0;
						telecharge(ca, nomFichier, [](const Traj* trajet) -> bool {
							currNum ++;
							cout<< rangeN<<endl;
							cout<<rangeM<<endl;
							cout << ((currNum - 1) >= rangeN && (currNum - 1) <= rangeM)<<endl;
							if((currNum - 1) >= rangeN && (currNum - 1) <= rangeM) return true;
							else return false;
						});
						break;
					case '8':
						break;
					default:
						break;
				}
				break;
			case '8':
				b=0;
				//for(int i=0;i<(ca->getUsed());i++){
					//delete ca->getListe()[i];
				//}
				delete ca;
				break;
			default:
				cout<<"input error"<<endl;
				cin.clear();
		}
		if(b==0){
			break;
		}
	}
	return 0;
}
