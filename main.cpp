#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

#include "Simplex.h"
#include "Subproblem.h"
#include "Live.h"

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


                //Se crea un LIVE
                Live live;


                // Se lee el archivo  y se crea un simplex
                Simplex s(filename);


                //Se guarda la matriz del probelma en una variable
                std::vector<std::vector<float>> matriz = s.a;

                // Se imprime la matriz del problema
                //s.printProblemMatrix();  <------- Causa error en archivos grandes

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
                Subproblem sp(s.a, 0, 0, s);



                //Calculamos la cota inferior, remplazando con 0 en la función a optimizar, el valor de la variable más cercana a 0,5 del vector solución
                
                //Encontramos la posición del valor más cercano a 0.5
                float min = 1000000;
                int index = 0;
                  for (int i = 1; i < (s.m1 + s.m2 + s.m3)-1; i++){
                                if (abs(r[i] - 0.5) < min){
                                    min = abs(r[i] - 0.5);
                                    index = i;
                                }
                            }

                
                //Calculamos la cota inferior
                float Zinf = 0;
                for (int i = 1; i < (s.m1 + s.m2 + s.m3)-1; i++){
                    if (i == index){

                    }
                    else{
                       Zinf=  matriz[0][i] + Zinf;
                    }
                }
                cout << "Cota inferior: " << Zinf << endl;

                //Definimos los valores de la cota superior e inferior en el subproblema
                sp.c_sup = Zmax;
                sp.c_inf = Zinf;

                //Se crean  2 subroblemas más, uno con la restrición de la variable más cercana a 0 y otro con la restricción de la variable más cercana a 1
                Simplex simplex_aux_menor_cero = s.copy();
                simplex_aux_menor_cero.insertConstraint(0, index, 1); //Se inserta la restricción x[index] <= 0
                Simplex simplex_aux_mayor_cero = s.copy();
                simplex_aux_mayor_cero.insertConstraint(1, index, 2); //Se inserta la restricción x[index] >= 1
                
                Subproblem sp1(simplex_aux_menor_cero.a, 0, 0, simplex_aux_menor_cero);
                Subproblem sp2(simplex_aux_mayor_cero.a, 0, 0, simplex_aux_mayor_cero);

                //Se agregan los subproblemas al vector live
                live.addSubproblem(sp);
                live.addSubproblem(sp1);
                live.addSubproblem(sp2);



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