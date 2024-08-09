#include <vector>
#include <queue>
#include <functional>
#include <iostream>

#include "Simplex.h"
#include "Subproblem.h"

using namespace std;

Subproblem::Subproblem(){
}

Subproblem::Subproblem(std::vector<std::vector<float>> Matriz, double c_sup, double c_inf, Simplex simplex){
    this->Matriz = Matriz;
    this->c_sup = c_sup;
    this->c_inf = c_inf;
    this->simplex = simplex;
    
}

// void Subproblem::adddSimplex(Simplex simplex){
//     this->simplex = simplex;
// }


 //Calculamos la cota inferior, remplazando con 0 en la función a optimizar, el valor de la variable más cercana a 0,5 del vector solución
int Subproblem::indexCotaInferior(std::vector<float> r){              
     //Encontramos la posición del valor más cercano a 0.5
     float min = 1000000;
     int index = 0;
       for (int i = 1; i < (simplex.m1 + simplex.m2 + simplex.m3)-1; i++){
                     if (abs(r[i] - 0.5) < min){
                         min = abs(r[i] - 0.5);
                         index = i;
                     }
       }
       return index;
}

void Subproblem::calculateCotas(std::vector<float> r){
    int index = indexCotaInferior(r);
    //Calculamos la cota inferior
    
    float Zinf = 0;
    for (int i = 1; i < (simplex.m1 + simplex.m2 + simplex.m3)-1; i++){
        if (i == index){
        }
        else{
           Zinf=  simplex.a[0][i] + Zinf;
        }
    }
    c_inf = Zinf;
    c_sup = r[0];
    cout << "Cota inferior: " << Zinf << endl;
}

    



