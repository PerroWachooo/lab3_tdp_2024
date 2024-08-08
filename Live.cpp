#include <vector>
#include <queue>
#include <functional>
#include <iostream>

#include "Live.h"
#include "Subproblem.h"


using namespace std;

// Constructor
Live::Live() {
 
};


// Agregar un nuevo subproblema a la lista de Live
void Live::addSubproblem(vector<std::vector<float>> Matriz,double c_sup, double c_inf) {
    Subproblem newSubproblem(Matriz, c_sup, c_inf);
    listaSubproblemas.push(newSubproblem);
    };

// Obtener y eliminar el subproblema con la mejor cota superior
Subproblem Live:: getBestSubproblem() {
    if (listaSubproblemas.empty()) {
        throw std::runtime_error("No more subproblems available");
    }
    Subproblem best = listaSubproblemas.top();
    listaSubproblemas.pop();
    return best;
};

// Verificar si la lista de subproblemas vivos está vacía
bool Live::isEmpty() {
    return listaSubproblemas.empty();
};

