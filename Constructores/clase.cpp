#include "Constructores.h"
/***********************************************************************
* Se definen los métodos de la clase KeyValue. Es necesario especificar
* el nombre de la clase para indicar que son miembros de esa clase.
************************************************************************/

KeyValue::KeyValue(std::string key, std::string value, const char* cadena) {
	//cout << "constructor normal" << endl;
	this->key = key;
	this->value = value;
	micopia1((this->cadena), (char*)cadena);
	//micopia(&(this->cadena), (char*)cadena);

};

KeyValue::KeyValue() {
	this->key = "LLave1";
	(*this).value = "Valor1";
}

KeyValue::KeyValue(const KeyValue& src) {
	//cout << "Se esta ejecutando el constructor copia" << endl;
	this->key = src.key;
	this->value = src.value;
	micopia(&(this->cadena), src.cadena);
	//micopia1((this->cadena), (char*)cadena);
}


std::string KeyValue::getKey() const {
	return key;
}

std::string KeyValue::getValue() const {
	return value;
}

void KeyValue::setKey(std::string key) {
	this->key = key;
}

void KeyValue::setValue(std::string v) {
	std::string value;
	this->value = v;
}
KeyValue& KeyValue::operator=(const KeyValue& src) {
	//cout << "Se ejecuta el operador de asignación" << endl;
	this->key = src.key;
	this->value = src.value;
	micopia(&(this->cadena), src.cadena);
	//micopia1((this->cadena), (char*)cadena);
	return *this;
}
