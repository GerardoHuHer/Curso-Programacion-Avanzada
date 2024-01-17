// entorno.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Constructores.h"

int main(int argc, char** argv, char* env[]) {
    buscaVariableEntorno(argc, argv, env);
    /*
    KeyValue kv1 = KeyValue("key1", "value1", "Hola Mundo"); //constructor
    KeyValue kv3 = KeyValue("key3", "value5", "Hello World");//constructor
    KeyValue kv2 = kv1; //constructor copia
    KeyValue kv4 = kv3; //constructor copia
    cout << "Objeto kv2 " << kv1 << endl; //Uso del operador << para KeyValue
    cout << "Objeto kv4 " << kv4 << endl; //Uso del operador << para KeyValue
    kv4 = kv1; //Uso del operador = para KeyVaalue
    cout << "Objeto kv4 " << kv4 << endl;
    */

    return 0;

}

