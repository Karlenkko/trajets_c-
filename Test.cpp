#include <iostream>
#include <cstring>
using namespace std;
#include "Catalogue.h"

int testCases = 0;
int failed = 0;

void test(string title, bool successful) 
// Algorithme :
// Use with lambda function to create test cases and to print an error message
// if the specific test failed.
{
    ++testCases;
    if (!successful) {
        cout << "T(" << testCases << "): Test " << title << " failed.\r\n" << endl;
        ++failed;
    }
}

int main() {
    char departString [] = {'B', 'e', 'r', 'l', 'i', 'n'};
    char arriveString [] = {'L', 'y', 'o', 'n'};
    char transportString [] = {'a', 'v', 'i', 'o', 'n'};

    // ---------------------------------------------------------------- Trajet
    test("constructor of Trajet", [](char* departString, char* arriveString) -> bool {
        bool passed = true;
        Trajet* tmp = new Trajet(departString, arriveString);
        if (tmp -> getDepart() == NULL || tmp -> getArrive() == NULL) {passed = false; cout << "[TEST] Trajet::Trajet(...) didn't initalize depart or arrive string" << endl;};

        return passed;
    });

    Trajet* testTrajet = new Trajet(departString, arriveString);

    test("Trajet::getDepart()", [](Trajet* testTrajet) -> bool {
        if (strcmp(testTrajet -> getDepart(), "Berlin") == 0) return true;
        else return false;
    });

    test("Trajet::getArrive()", [](Trajet* testTrajet) -> bool {
        if (strcmp(testTrajet -> getArrive(), "Lyon") == 0) return true;
        else return false;
    });

    // ---------------------------------------------------------- TrajetSimple
    test("Constructor of TrajetSimple", [](char* departString, char* arriveString, char* transportString) -> bool {
        bool passed = true;
        TrajetSimple* tmp = new TrajetSimple(departString, arriveString, transportString);
        if (tmp -> getDepart() == NULL || tmp -> getArrive() == NULL) {passed = false; cout << "[TEST] TrajetSimple::TrajetSimple(...) didn't initalize depart or arrive string" << endl;};
        if (tmp -> getTransport() == NULL) {passed = false; cout << "[TEST] TrajetSimple::TrajetSimple(...) didn't initalize transport string" << endl;};

        return passed;
    });

    TrajetSimple* testTrajetSimple = new TrajetSimple(departString, arriveString, transportString);
    
    // --------------------------------------------------------- TrajetCompose
    test("Constructor of TrajetCompose", [](char* departString, char* arriveString, char* transportString) -> bool {
        bool passed = true;
        TrajetSimple* trajetSimple = new TrajetSimple(departString, arriveString, transportString);
        TrajetCompose* tmp = new TrajetCompose(trajetSimple);
        if (tmp -> getDepart() == NULL || tmp -> getArrive() == NULL) {passed = false; cout << "[TEST] TrajetCompose::TrajetCompose(...) didn't initalize depart or arrive string" << endl;};
        if (tmp -> getNumeroDeTrajets() != 1) {passed = false; cout << "[TEST] TrajetCompose::TrajetCompose(...) has to have exactly one simple connections after initialization" << endl;};
        if (tmp -> getTrajetsSimples() == NULL) {passed = false; cout << "[TEST] TrajetCompose::TrajetCompose(...) didn't initialize the array of simple connections" << endl;};

        return passed;
    });

    TrajetCompose* testTrajetCompose = new TrajetCompose(testTrajetSimple);

    test("TrajetCompose::ajouterTrajetEnFin ne doit pas fonctionner avec le même trajet", [](Catalogue* testCat, TrajetSimple* testTrajetSimple, TrajetCompose* testTrajetCompose) -> bool {
        bool passed = true;
        int oldNbr = testTrajetCompose -> getNumeroDeTrajets();
        if (testTrajetCompose -> ajouterTrajetEnFin(testTrajetSimple)) passed = false;
        if (testTrajetCompose -> getNumeroDeTrajets() == oldNbr + 1) passed = false;

        return false;
    });

    // -------------------------------------------------------------- Catalogue
    Catalogue* testCat = new Catalogue();
    
    test("if catalogue constructor works", [](Catalogue* testCat) -> bool {
        if (testCat == NULL) return false;
        else return true;
    });

    test("Catalogue::ajouterNouveauTrajet", [](Catalogue* testCat, char* departString, char* arriveString, char* transportString) -> bool {
        bool passed = true;
        TrajetSimple* tmpTrajet = new TrajetSimple(departString, arriveString, transportString);
        int oldSize = testCat -> getNumeroDeTrajets();
        if (!testCat -> ajouterNouvTrajet(tmpTrajet)) {cout << "[TEST] Method ajouterNouvTrajet returned false" << endl; return false;};
        if (oldSize == testCat -> getNumeroDeTrajets()) {passed = false; cout << "[TEST] Number of connections stayed the same after ajouterNouvTrajet" << endl;};
        if ((testCat -> getTrajets())[0] == NULL) {passed = false; cout << "[TEST] First element of catalogue should be filled after ajouterNouvTrajet call" << endl;};

        return passed;
    });

    testCat -> ajouterNouvTrajet(testTrajetSimple);

    test("Catalogue::queryTrajet", [](Catalogue* testCat) -> bool {
        bool passed = true;
        Trajet* resTrajet = testCat -> chercherTrajet(0);
        if (resTrajet == NULL) {std::cout << "[TEST] Catalogue::queryTrajet returned NULL" << endl; return false;};

        return passed;
    });



    cout << "Failed " << failed << " of " << testCases << " tests.\r\n" << endl;

} // ----- Fin de main
