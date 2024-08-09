#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include "Simplex.h"

using namespace std;

class Subproblem {

    public:
        std::vector<std::vector<float>> Matriz; // Matriz del problema.
        double c_sup;                             // Cota superior del subproblema
        double c_inf;                             // Cota inferior del subproblema
        Simplex simplex;                          // Simplex asociado al subproblema
        vector<float> sol;                       // Solucion del subproblema

        //Constructor
        Subproblem(); 
        Subproblem(std::vector<std::vector<float>> Matriz, double c_sup, double c_inf, Simplex simplex);

        void adddSimplex(Simplex simplex);
        int Subproblem::indexCotaInferior(std::vector<float> r);
        void Subproblem::calculateCotas(std::vector<float> r);
};
