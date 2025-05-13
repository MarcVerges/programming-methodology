//
//  main.cpp
//  Tema 2 - Sessió 15
//
//  Created by Marc Verges on 28/4/23.
//
#include <iostream>
#include <string>
#include "Estudiant.h"
using namespace std;

int main()
{
    string assignatura;
    Estudiant estudiant;

    int grade;

    grade = 0;
    cout << endl << endl;
    cout << "Comment :=>> INICIANT TEST" << endl;
    cout << "Comment :=>> =============" << endl;
    cout << "Comment :=>> " << endl;



    cout << "Comment :=>> TEST afegir assignatura alfabeticament a estudiant" << endl;
    cout << "Comment :=>> ------------------------------------------" << endl;
    cout << "Comment :=>> Afegint assignatures..." << endl;
    cout << "Comment :=>> Metodologia de la Programacio" << endl;
    estudiant.insereixAssignatura("Metodologia de la Programacio");
    cout << "Comment :=>> Fonaments d'informatica" << endl;
    estudiant.insereixAssignatura("Fonaments d'informatica");
    cout << "Comment :=>> Xarxes" << endl;
    estudiant.insereixAssignatura("Xarxes");
    cout << "Comment :=>> Grafics" << endl;
    estudiant.insereixAssignatura("Grafics");
    cout << "Comment :=>> ---------" << endl;
    cout << "Comment :=>> Comprovant assignatura a la posicio 2 del vector..." << endl;
    assignatura = estudiant.getAssignatura(2);
    if (assignatura == "Metodologia de la Programacio") {
        cout << "Comment :=>> Assignatura Metodologia de la Programacio correcte" << endl;
        grade = 5;
    }
    else {
        cout << "Comment :=>> Error a l'afegir assignatura" << endl;
    }
    cout << "Grade :=>> " << grade;

    cout << "Comment :=>> ------------------------------------------" << endl;
    cout << "Comment :=>> TEST eliminar assignatura a estudiant" << endl;
    cout << "Comment :=>> ------------------------------------------" << endl;
    cout << "Comment :=>> Eliminant assignatures..." << endl;
    cout << "Comment :=>> Grafics" << endl;
    estudiant.eliminaAssignatura("Grafics");
    cout << "Comment :=>> Fonaments d'informatica" << endl;
    estudiant.eliminaAssignatura("Fonaments d'informatica");
    cout << "Comment :=>> Xarxes" << endl;
    estudiant.eliminaAssignatura("Xarxes");
    assignatura = estudiant.getAssignatura(0);
    cout << "Comment :=>> ---------" << endl;
    cout << "Comment :=>> Comprovant assignatura a la posicio 0 del vector..." << endl;
    if (assignatura == "Fonaments de informatica" || assignatura != "Metodologia de la Programacio") {

        cout << "Comment :=>> Error a l'eliminar assignatura" << endl;
    }
    else {
        cout << "Comment :=>> Eliminar assignatura correcte" << endl;
        grade = grade +5;
    }
    

    cout << "Comment :=>> TEST mostrar assignatures estudiant" << endl;
    cout << "Comment :=>> ------------------------------------------" << endl;
    estudiant.mostraAssignatures();
    cout << "Grade :=>> " << grade;
    

     return 0;
}
