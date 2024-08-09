#ifndef LIVE_H // Si LIVE_H no está definido
#define LIVE_H // Define LIVE_H

#include <vector>
#include <queue>
#include <functional>
#include <iostream>

#include "Simplex.h"
#include "Subproblem.h"

using namespace std;

// Comparador para la cola de prioridad (max-heap basado en la cota superior)
struct CompareCotaSuperior {
    bool operator()(const Subproblem& a, const Subproblem& b) {
        return a.c_sup < b.c_sup;
    }
};


class Live {
    
    public:    
        
        std::priority_queue<Subproblem, std::vector<Subproblem>, CompareCotaSuperior> listaSubproblemas;
        double Z_sup, Z_inf; // Cota superior e inferior global
        
        Subproblem best; // Mejor solución encontrada

        // Constructor
        Live();

        // Agregar un nuevo subproblema a la lista de vivos
        void addSubproblem(Subproblem sp);

        // Obtener y eliminar el subproblema con la mejor cota superior
        Subproblem getBestSubproblem();

        // Verificar si la lista de subproblemas vivos está vacía
        bool isEmpty();

        // Imprimir la solución de una matriz a
        void printSolutionMatrix(std::vector<float> r);

        // Algoritmo BB
        void branchAndBound(Simplex s);



};

#endif