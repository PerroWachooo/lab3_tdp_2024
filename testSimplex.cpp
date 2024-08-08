#include <iostream>
#include "Simplex.h"

using namespace std;

int main() {
    Simplex s("P1.txt");
    s.printProblemMatrix();
    s.insertConstraint(5, 2,1); // insertamos variable x2 con restricion  x2 <= 5
    s.printProblemMatrix();
    vector<float> sol = s.solve(); //
    for(auto x : sol) {
        cout << x << " ";
   }
    cout << endl;
}