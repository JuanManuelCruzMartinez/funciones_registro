#include <iostream>
#include <string>
using namespace std;
 
struct tipoDatos
{
    string nombreFich;        
    long tamanyo;            
};

int numeroFichas=0;  
int i;               
int opcion;          
 
string textoTemporal; 
int numeroTemporal;
 
int main()
{
    tipoDatos *fichas = new tipoDatos[1000];
 
    do
    {
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo fichero" << endl;
        cout << "2.- Mostrar los nombres de todos los ficheros" << endl;
        cout << "3.- Mostrar ficheros que sean de mas de un cierto tamaño" << endl;
        cout << "4.- Ver datos de un fichero" << endl;
        cout << "5.- Salir" << endl;

        cin >> opcion;
        switch(opcion)
        {
            case 1: 
                if (numeroFichas < 1000)   
                {
                    cout << "Introduce el nombre del fichero: ";
                    cin >> fichas[numeroFichas].nombreFich;
                    cout << "Introduce el tamaño en KB: ";
                    cin >> fichas[numeroFichas].tamanyo;
                    numeroFichas++;  
                }
                else   
                    cout << "Máximo de fichas alcanzado (1000)!" << endl;
                break;
 
            case 2: 
                for (i=0; i<numeroFichas; i++)
                    cout << "Nombre: " << fichas[i].nombreFich
                        << "; Tamaño: " << fichas[i].tamanyo
                        << "Kb" << endl;
                break;
 
            case 3: 
                cout << "¿A partir de que tamaño quieres que te muestre? ";
                cin >> numeroTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].tamanyo >= numeroTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tamaño: " << fichas[i].tamanyo
                            << " Kb" << endl;
                break;
 
            case 4: 
                cout << "¿De qué fichero quieres ver todos los datos?";
                cin >> textoTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].nombreFich == textoTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tamaño: " << fichas[i].tamanyo
                            << " Kb" << endl;
                break;
 
            case 5: 
                cout << "Fin del programa" << endl;
                break;
 
            default: 
                cout << "Opción desconocida!" << endl;
                break;
        }
    } while (opcion != 5); 
 
    return 0;
}