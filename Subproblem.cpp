#include <vector>
#include <queue>
#include <functional>
#include <iostream>

#include "Simplex.h"
#include "Subproblem.h"

using namespace std;


Subproblem::Subproblem(std::vector<std::vector<float>> Matriz, double c_sup, double c_inf){
    this->Matriz = Matriz;
    this->c_sup = c_sup;
    this->c_inf = c_inf;
    
}

// void Subproblem::adddSimplex(Simplex simplex){
//     this->simplex = simplex;
// }

