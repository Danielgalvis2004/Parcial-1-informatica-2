#include <iostream>
#include <fstream>

using namespace std;

const int FILAS = 45; //tamaño de filas
const int MAX_LONGITUD_PALABRA = 20; // Máxima longitud de palabra permitida

int main() {
    // Crear la matriz
    char** matriz = new char*[FILAS]; //se crea una matriz de arreglos de caracteres char con el tamaño de filas
    for (int i = 0; i < FILAS; ++i) { //incrementa hasta que se llega al tamaño de filas, para crear matriz
        matriz[i] = new char[MAX_LONGITUD_PALABRA + 1]; // +1 para el carácter nulo al final de la palabra \0
    }

    cout<<"En este horario se esta manejando un formato, en la que el horario de sueno es de 22pm a 6am"<<endl;
    cout<<"Se manejan bloques de estudio de 2 horas, en orden(es decir 6am-8am,etc..., hasta llegar a 22pm"<<endl;
    cout<<"Cuando sale el dia de la semana hay que ingresar este mismo, esto solo para tener mejor orden del horario"<<endl;
    cout << "Ingrese su horario"<< endl;
    int Z=6; //hora de inicio clase
    int Y=8; //hora fin clase
    for (int i = 0; i < FILAS; ++i) { //incrementa hasta que se llega al tamaño de filas, para asignar valores a la matriz

        if (i==0){ //posicion lunes
            cout << "Lunes " <<": ";
            cin >> matriz[i]; //ingresamos en la matriz
        }
        else if (i<9){ //clases para el lunes, si se pasa de 9 es martes
            cout << Z<<":00 - "<<Y<<":00"<<": "; //imprime horas en las que va a estar la clase
            cin >> matriz[i]; //ingresamos a la matriz
            Y=Y+2; //aumentamos 2, porque es lo que dura un bloque de estudio (2horas)
            Z=Z+2;
        }

        else if (i==9){
            cout << "Martes " << ": ";
            cin >> matriz[i];
        }
        else if (i<18){
            cout << Z<<":00 - "<<Y<<":00"<<": ";
            cin >> matriz[i];
            Y=Y+2;
            Z=Z+2;
        }

        else if (i==18){
            cout << "miercoles " << ": ";
            cin >> matriz[i];
        }
        else if (i<27){
            cout << Z<<":00 - "<<Y<<":00"<< ": ";
            cin >> matriz[i];
            Y=Y+2;
            Z=Z+2;
        }

        else if (i==27){
            cout << "jueves " << ": ";
            cin >> matriz[i];
        }
        else if (i<36){
            cout << Z<<":00 - "<<Y<<":00"<< ": ";
            cin >> matriz[i];
            Y=Y+2;
            Z=Z+2;
        }

        else if (i==36){
            cout << "viernes " << ": ";
            cin >> matriz[i];
        }
        else if (i<45){
            cout << Z<<":00 - "<<Y<<":00"<< ": ";
            cin >> matriz[i];
            Y=Y+2;
            Z=Z+2;
        }

        if (Y>22){ //cuando llega al horario de sueño, reiniciamos variables
            Z=6;
            Y=8;
        }

    }

    // Guardar datos en archivo.txt
    ofstream archivo("matriz.txt"); //abrimos archivo para escritura
    if (archivo.is_open()) { //si el archivo esta abierto
        for (int i = 0; i < FILAS; ++i) {
            archivo << matriz[i] << endl; //escribimos fila por fila la matriz al archivo
        }
        archivo.close(); //cerramos archivo
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    // Liberar la memoria de la matriz
    for (int i = 0; i < FILAS; ++i) {
        delete[] matriz[i]; //se vacia la matriz
    }
    delete[] matriz;

    return 0;
}
