/*************************************************************

NOMBRE: Roberto perez Zamora
FECHA: 22/02/24
PROGRAMA: Actividad de programacion - 7.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION:Elaborar una calculadora de matrices cuadradas que realice la suma, resta y multiplicación de 2 matrices. Las condiciones son la siguientes:

Matriz cuadrada mínima es de 2x2 y máxima 10x10
El valor los puede meter el usuario e indicar en qué matriz irá dicho valor
Tendrá la opción de ser llenada con valores aleatorios entre - 100  y 100
Realizar la operación que indique el usuario final
Borrado y edición de elementos
Vaciado de matrices

***************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM_MAX = 10;

// Función para imprimir matriz
void printMatrix(int matrix[TAM_MAX][TAM_MAX], int dimension)
{
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}


//  Función para generar un número aleatorio entre dos números enteros
int main() {
    int dimension, operation;

    do {
        cout << "Ingrese la dimension de las matrices (entre 2 y 10): ";
        cin >> dimension;

        if (dimension < 2 || dimension > 10)
        {
            cout << "Dimension no valida. Debe estar entre 2 y 10." << endl;
            return 1;
        }

        // Declarar matrices
        int A[TAM_MAX][TAM_MAX], B[TAM_MAX][TAM_MAX], result[TAM_MAX][TAM_MAX];

        // Generar números aleatorios para las matrices
        srand(time(0)); // Semilla de numeros aleatorios
        for (int i = 0; i < dimension; ++i)
        {
            for (int j = 0; j < dimension; ++j)
            {
                A[i][j] = rand() % 201 - 100; // N aleatorios entre -100 y 100
                B[i][j] = rand() % 201 - 100; // N aleatorios entre -100 y 100
            }
        }

        // Imprimir matrices
        cout << "Matriz A:" << endl;
        printMatrix(A, dimension);
        
        // Imprimir matrices
        cout << "Matriz B:" << endl;
        printMatrix(B, dimension);

        // Menú de opciones
        cout << "Seleccione la operacion a realizar:" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Editar elemento" << endl;
        cout << "5. Borrar elemento" << endl;
        cout << "6. Vaciar matriz" << endl;
        cout << "7. Salir" << endl;
        cin >> operation;

        // Realizar la operación seleccionada
        switch (operation)
        {
            // Suma
            case 1: {
                cout << "Resultado de la suma:" << endl;
                for (int i = 0; i < dimension; ++i)
                {
                    for (int j = 0; j < dimension; ++j)
                    {
                        result[i][j] = A[i][j] + B[i][j];
                        cout << result[i][j] << "\t";
                    }
                    cout << endl;
                }
                break;
            }

            // Resta
            case 2:
            {
                cout << "Resultado de la resta:" << endl;

                for (int i = 0; i < dimension; ++i)
                {
                    for (int j = 0; j < dimension; ++j)
                    {
                        result[i][j] = A[i][j] - B[i][j];
                        cout << result[i][j] << "\t";
                    }
                    cout << endl;
                }
                break;
            }

            // Multiplicación
            case 3:
            {
                cout << "Resultado de multiplicacion:" << endl;

                for (int i = 0; i < dimension; ++i)
                {
                    for (int j = 0; j < dimension; ++j)
                    {
                        result[i][j] = 0;
                        for (int k = 0; k < dimension; ++k)
                        {
                            result[i][j] += A[i][k] * B[k][j];
                        }
                        cout << result[i][j] << "\t";
                    }
                    cout << endl;
                }
                break;
            }

            // Editar elemento
            case 4:
            {
                int row, col, newValue;
                cout << "Fila de elemento a editar (Posible entre 0 y " << dimension - 1 << "): ";
                cin >> row;
                cout << "Columna de elemento a editar (Posible entre 0 y " << dimension - 1 << "): ";
                cin >> col;
                cout << "Nuevo valor: ";
                cin >> newValue;

                // Verificar que la posición sea válida
                if (row >= 0 && row < dimension && col >= 0 && col < dimension) 
                {
                    A[row][col] = newValue;
                    cout << "Elemento editado." << endl;
                } else
                {
                    cout << "Posicion invalida." << endl;
                }
                break;
            }

            // Borrar elemento
            case 5:
            {
                int row, col;
                cout << "Fila de elemento a borrar (Disponible entre 0 y " << dimension - 1 << "): ";
                cin >> row;
                cout << "Columna de elemento a borrar (Disponible entre 0 y " << dimension - 1 << "): ";
                cin >> col;

                // Verificar que la posición sea válida
                if (row >= 0 && row < dimension && col >= 0 && col < dimension)
                {
                    A[row][col] = 0; //Bborra elemento asignándo el valor 0
                    cout << "Elemento borrado." << endl;
                } else

                // Si la posición no es válida
                {
                    cout << "Posicion invalida." << endl;
                }
                break;
            }

            // Vaciar matriz
            case 6:
            {
                for (int i = 0; i < dimension; ++i)
                {
                    for (int j = 0; j < dimension; ++j)
                    {
                        A[i][j] = 0; // Asignar 0 en todos los elementos
                    }
                }
                cout << "Matriz vaciada." << endl;
                break;
            }

            // Salir
            case 7:
            {
                cout << "Saliendo del programa." << endl;
                break;
            }

            // Opción no válida
            default:
                cout << "Operacion no valida." << endl;
                break;
        }

    } while (operation != 7);

    return 0;
}