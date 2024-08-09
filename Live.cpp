#include <vector>
#include <queue>
#include <functional>
#include <iostream>

#include "Live.h"
#include "Subproblem.h"


using namespace std;

// Constructor
Live::Live() {
    this->Z_sup = 0;
    this->Z_inf = 0;
 
};


// Agregar un nuevo subproblema a la lista de Live
void Live::addSubproblem(Subproblem sp) {
    listaSubproblemas.push(sp);
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





void printSolutionMatrix(std::vector<float> r ){
    // Se imprime la solucion
    cout << "Solucion: ";
    for (int i = 0; i < r.size(); i++){
    cout << r[i] << " ";
    }
}



// Algoritmo BB
void Live::branchAndBound(Simplex s){
    
    //Se crea un subproblema
    Subproblem sp(s.a, 0, 0, s);

    // Se guarda el subproblema en la lista Live
    addSubproblem(sp);

    //Se inicializa el ciclo de BB
    while(!isEmpty()){
        //Se obtiene el subproblema con la mejor cota superior
        Subproblem sp_aux = getBestSubproblem();
        //Se calcula las cotas inferior y superior
        sp_aux.calculateCotas(sp_aux.simplex.solve());
        
        //Se guarda la solución con mayor cota superior
        if (sp_aux.c_sup > Z_sup){
            Z_sup = sp_aux.c_sup;
            best = sp_aux;
        }
        if(sp_aux.c_sup < Z_inf){  //Si la cota superior es menor a la cota inferior, se descarta el subproblema (Poda por cota)
            continue;
        }

    }

    //Se calcula las cotas inferior y superior
    sp.calculateCotas(s.solve());
    if (sp.c_sup > Z_sup){
        Z_sup = sp.c_sup;
    }



    
}