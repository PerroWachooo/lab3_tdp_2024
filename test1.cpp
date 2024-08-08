#include <iostream>
#include "Simplex.h"

using namespace std;

int main() {
    Simplex s("P2.txt");

    s.insertConstraint(5, 2,1); // insertamos variable x2 con restricion  x2 <= 5
    s.printProblemMatrix();
// Se guarda la matriz en una variable

    std::vector<std::vector<float>> matriz2 = s.a;


    cout << "A: " << endl;
    for (int i = 0; i < matriz2.size(); i++){
        for (int j = 0; j < matriz2[i].size(); j++){
            cout << matriz2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nSolución:" << endl;
    vector<float> sol = s.solve(); //
    for(auto x : sol) {
        cout << x << " ";
   }
    cout << "";

    cout << "\nEcuación de la solución: " << endl;
    for (int i = 1; i < (s.m1 + s.m2 + s.m3)-1; i++){
        cout << matriz2[0][i] << "x" << i << " + ";
    }
     

}