#pragma once
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//Nuevo tipo de dato para representar un para llave valor 
class KeyValue {
private:
	std::string key;
	std::string value;
	char* cadena = (char*)"hello";

public:
	KeyValue(std::string k, std::string v, const char* cadena);
	KeyValue(); //Solamente para demostrar la sobrecarga de constructores
	KeyValue(const KeyValue& src);
	std::string getKey() const;
	std::string getValue() const;
	void setKey(std::string);
	void setValue(std::string);
	// Leer el reporte sobre la palabra clave friend en moodle
	friend std::ostream& operator<<(std::ostream& os, const KeyValue& kv);
	KeyValue& operator=(const KeyValue& src);



};

std::ostream& operator<<(std::ostream& os, const std::vector<KeyValue>& vec);

void buscaVariableEntorno(int argc, char** argv, char* env[]);

/*********************************************************************
Comparador personalizado para ordenar por 'key' cuando usamos
std::vector<KeyValue>
*********************************************************************/
bool compareByKey(const KeyValue& kv1, const KeyValue& kv2);

/*********************************************************************
Comparador personalizado para ordenar por 'key' cuando usamos
std::map<std::string, std::string>. Los items de un map se ordenan
por la clave, no por el valor y son de tipo std::pair
*********************************************************************/
bool KeyCompare(std::pair<const std::string, const std::string >pair1,
	std::pair<const std::string, const std::string >pair2);

void micopia(char** dest, const char* src);

void micopia1(char*& dest, const char* src);

void parcial(map<string, string>& dic);

void parcial1(map<string, string>& dic);