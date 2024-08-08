#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

#include "Simplex.h"
#include "Subproblem.h"

using namespace std;

int main(){
    // Se declaran variables para uso general
    int option = 1;
    time_t start, end;

    // Se crea un ciclo para que el usuario pueda elegir entre las opciones
    while (option != 2){
         // Se declaran e inicializan variables de posicion y tamanio
      
        string filename;
        ifstream inputFile;


        std::cout << "Seleccione una opción: \n";
        std::cout << "1. Seleccionar Archivo\n";
        std::cout << "2. Salir\n";

        std::cin >> option;

        // Se crea un switch para manejar las opciones
        switch (option){
            case 1:{
                cout << "Nombre de archivo: ";
                cin >> filename;
                cout << "Leyendo archivo " << filename << endl;
    
                // Se abre el archivo
                inputFile.open(filename);
                if (!inputFile) {
                    std::cout << "No se pudo abrir el archivo.";
                    return 1;
                }

                // Se lee el archivo  y se crea un simplex
                Simplex s(filename);

                //Se guarda la matriz del probelma en una variable
                std::vector<std::vector<float>> matriz = s.a;

                // Se imprime la matriz del problema
                s.printProblemMatrix();

                // Se resuelve el problema y se guarda la solucion
               std::vector<float> r = s.solve();
                //Se saca el Zmax
                float Zmax = r[0];

                // Se imprime la solucion
                cout << "Solucion: ";
                for (int i = 0; i < r.size(); i++){
                    cout << r[i] << " ";
                }

                //Se crea un subproblema
                Subproblem sp(s.a, 0, 0);


                sp.c_sup = Zmax;


               
                // Se cierra el archivo
                inputFile.close();


               

                // Se inicia el tiempo
                clock_t start = clock();
              
                // Se termina el tiempo
                clock_t end = clock();
                
                double time = double(end - start) / CLOCKS_PER_SEC;

                    

                //Se imprime el resultado
                

                // Se imprime el tiempo de ejecucion
                cout << "\nTiempo de ejecución: " << time << " segundos\n" << endl;
                break;
            
            }
            
            
            
            case 2:{
                //Se quiere salir del programa
                cout << "Saliendo del programa\n";
                break;
            }
           
            
            
            default:
                cout << "Opción no válida\n";
                break;
        }
    }



}