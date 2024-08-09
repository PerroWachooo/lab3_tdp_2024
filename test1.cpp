#include <iostream>
#include "Simplex.h"

using namespace std;

int main() {
    Simplex s("f2.txt");

    s.insertConstraint(5, 2,1); // insertamos variable x2 con restricion  x2 <= 5
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


    float min = 1000000;
    int index = 0;
      for (int i = 1; i < (s.m1 + s.m2 + s.m3)-1; i++){
                    if (abs(sol[i] - 0.5) < min){
                        min = abs(sol[i] - 0.5);
                        index = i;
                    }
                }

    float c_inferior = 0;
    for (int i = 1; i < (s.m1 + s.m2 + s.m3)-1; i++){
        if (i == index){
            
        }
        else{
           c_inferior=  matriz2[0][i] + c_inferior;
        }
    }

    cout << "Cota inferior: " << c_inferior << endl;
     

}