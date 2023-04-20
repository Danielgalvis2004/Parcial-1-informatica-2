#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int FILAS = 45; //tamaño de filas
const int MAX_LONGITUD_PALABRA = 20; // Máxima longitud de palabra permitida
ifstream fin;             //leer
ofstream fout;          //escribir
//funcion para calcular horas pa estudiar por materia
int creditos(int X){
    int Y;
    Y = (X*48)/16; //formula para saber horas de estudio
    if ((Y%2)!=0){  //en caso de ser impar las horas de estudio, estudiar 1 más
        Y=Y+1;
    }

    return Y;
}
int main() {

    //crear matriz para materia, codigo y horas de estudio
    int X;
    cout<<"Cuantas materias desea ingresar: ";
    cin>>X;
    char** matriz1 = new char*[X];
    for (int i=0;i<X;++i){
        matriz1[i] = new char[20];
    }
    char** matriz2 = new char*[X];
    for (int i=0;i<X;++i){
        matriz2[i] = new char[20];
    }

    int matriz3[X];


    for (int i=0;i<X;i++){
        cout<<"Ingrese el nombre de la materia: ";
        cin>>matriz1[i];

        cout<<"Ingrese el codigo de la materia: ";
        cin>>matriz2[i];

        int Z;
        cout<<"Ingrese los creditos de la materia: ";
        cin>>Z;
        matriz3[i]=creditos(Z); //se guardan las horas de estudio en la matriz de horas de estudio

    }

    // Crear la matriz para horario
    char** matriz = new char*[FILAS]; //se crea una matriz de arreglos de caracteres char con el tamaño de filas
    for (int i = 0; i < FILAS; ++i) { //incrementa hasta que se llega al tamaño de filas, para crear matriz
        matriz[i] = new char[MAX_LONGITUD_PALABRA + 1]; // +1 para el carácter nulo al final de la palabra \0
    }

    cout<<"En este horario se esta manejando un formato, en la que el horario de sueno es de 22pm a 6am"<<endl;
    cout<<"Se manejan bloques de estudio de 2 horas, en orden(es decir 6am-8am,etc..., hasta llegar a 22pm"<<endl;
    cout<<"Cuando sale el dia de la semana hay que ingresar este mismo, esto solo para tener mejor orden del horario"<<endl;
    cout<<"Si usted no tiene clase en estas horas por favor colocar un 0"<<endl;
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

    //Entregar horas a estudiar
    int cont=0;
    int clasesfaltantes;
    for (int i=0;i<X;i++){
        for (int j=0;j<45;j++){
            if (matriz1[i]==matriz[j]){
                cont =cont+1;
            }
        }
        clasesfaltantes=(matriz3[i]-(cont*2))/2;
        srand(time(NULL));
        int D;
        while (clasesfaltantes!=0){
            for (int s=0;s<45;s++){
                D= rand() % (46-1);
                if (matriz[D]==0){
                    matriz[D]=matriz1[i];
                }
            }
            clasesfaltantes=clasesfaltantes-1;
        }
    }
    ofstream archivo1("hoariofinal.txt"); //abrimos archivo para escritura
    if (archivo1.is_open()) { //si el archivo esta abierto
        for (int i = 0; i < FILAS; ++i) {
            archivo1 << matriz[i] << endl; //escribimos fila por fila la matriz al archivo
        }
        archivo1.close(); //cerramos archivo
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
