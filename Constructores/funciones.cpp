#include "Constructores.h"
ostream& operator<<(ostream& os, const KeyValue& kv) {
	os << "Llave: " << kv.key << endl;
	os << "Valor: " << kv.value << endl;
	os << "cadena:  " << kv.cadena << endl;
	return os;
}

ostream& operator<<(ostream& os, const vector<KeyValue>& vec) {
	for (auto& item : vec) {
		cout << item << endl;
	}
	return os;
}

/*********************************************************************
Comparador personalizado para ordenar por 'key' cuando usamos
map<string, string>. Los items de un map se ordenan
por la clave, no por el valor y son de tipo pair
*********************************************************************/
bool KeyCompare(pair<const string, const string >pair1,
	pair<const string, const string >pair2) {
	return pair1.first < pair2.first;
}
/*********************************************************************
Comparador personalizado para ordenar por 'key' cuando usamos
vector<KeyValue>
*********************************************************************/
bool compareByKey(const KeyValue& kv1, const KeyValue& kv2) {
	return kv1.getKey() < kv2.getKey();
}

void buscaVariableEntorno(int argc, char** argv, char* env[]) {

	if (argc != 2) {
		cout << "Uso: " << argv[0] << " <variable_de_entorno>" << endl;
		return;
	}
	string variable = argv[1]; // Nombre de la variable de entorno

	// Creación de un vector de objetos KeyValue
	vector<KeyValue> collection;

	//Creación de un diccionario de tipo map compuesto por pair<string, string>
	map<string, string> diccionario;

	// Recorrer las variables de entorno disponibles
	/**************************************************************
	* Recorrer las variables de entorno disponible.
	* Imprimimos algunas líneas recorridas para entender lo que ese
	* lazo realiza
	* 0000016A8AA63148: 0000016A8AA5FED0: HOMEDRIVE=C:
	* 0000016A8AA63150: 0000016A8AA5D7F0: HOMEPATH=\Users\barba
	**************************************************************/
	for (char** envVar = env; *envVar != nullptr; envVar++) {

		cout << static_cast<const void*>(envVar) << ": "
			<< static_cast<const void*>(*envVar) << ": "
			<< *envVar
			<< endl;
		/*******************************************************
		* Creamos un objeto de clase string línea por línea que
		* contiene la variable de entorno y su valor. Ejemplo
		* " ALLUSERSPROFILE=C:\ProgramData".
		* Buscamos la ocurrencia del caracter '=' en la cadena
		* con el método find de la clase string. Si se encuentra
		* el caracter nos devolverá su posición en la cadena; de
		* lo contrario nos devolverá el valor especial npos
		* definido en la clase string.
		* Dividimos la cadena en dos para obtener la llave o
		* nombre de la variable de entorno y su valor.
		* Con esas dos cadenas creamos un objeto de tipo
		* KeyValue y lo almacenamos en el vector.
		* También lo almacenamos en el diccionario.
		* La sintaxis para almacenar en el vector y en el
		* diccionario son diferentes
		*******************************************************/
		string envString(*envVar);
		size_t pos = envString.find('=');
		if (pos != string::npos) {
			string key = envString.substr(0, pos);
			string value = envString.substr(pos + 1);
			KeyValue kv(key, value, "");

			//Almacenamos el objeto kv en el vector
			collection.push_back(kv);

			// Aquí metemos el par key-value en el diccionario
			diccionario[key] = value; //pair<key,value>
			// O de esta forma
			//diccionario.insert(std::make_pair(key, value));
		}
	}
	KeyValue* begin = &collection[0];
	KeyValue* end = begin + collection.size();

	sort(begin, end, compareByKey);
	//La impresión del vecbrgintor no es necesaria. Queremos ver que funciona
	cout << "vector: " << collection << endl;
	//El objeto que queremos buscar en el vector. variable es argv[1]
	const KeyValue  targetKeyValue(variable, "", "");

	//Leer la explicacion de binary_search en la presentación que tienen en moodle
	bool found = binary_search(
		collection.begin(), collection.end(), targetKeyValue, compareByKey);

	// Leer la explicacion de lower_bound en la presentación que tienen en moodle
	auto it = lower_bound(collection.begin(), collection.end(), targetKeyValue, compareByKey);
	const std::type_info& info = typeid(it);
	cout << "Tipo de dato de it: " << info.name() << endl;
	cout << "Busqueda binaria en el vector" << endl;
	if (it != collection.end() && it->getKey() == variable) {
		cout << "Se encuentra la clave '" << variable
			<< "', el valor es '" << it->getValue() << "'" << endl;
	}
	else {
		cout << "No se encuentra la clave '" << variable
			<< "' en el vector." << endl;
	}

	//Ahora hacemos lo mismo pero con map
	// No necesitamos ordenarlo pues la clase map los ordena
	//El item que queremos buscar en el mapa o diccionario
	pair<const string, const string > item = { variable, "" };

	auto it1 = lower_bound(diccionario.begin(), diccionario.end(),
		item, KeyCompare);
	cout << "Busqueda binaria en el diccionario" << endl;
	if (it1 != diccionario.end() && it1->first == variable) {
		cout << "Se encuentra la clave en el diccionario '" << variable
			<< "', el valor es '" << it1->second << "'" << endl;
	}
	else {
		cout << "No se encuentra la clave " << variable
			<< " en el diccionario." << endl;
	}



	/***********************************************************************
	* Una búsqueda secuencial en el vector
	************************************************************************/
	// Buscar la variable en la colección y mostrar su valor si existe
	found = false;
	cout << "Busqueda secuencial en el vector" << endl;
	for (auto& kvp : collection) {
		if (kvp.getKey() == variable) {
			cout << "Valor de " << variable << " en el vector: " << kvp.getValue() << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "No se encuentra la clave '" << variable << "' en el vector." << endl;
	}

	/***********************************************************************
	* Una búsqueda secuencial en el mapa
	************************************************************************/
	// Buscar la variable en la colección y mostrar su valor si existe
	found = false;
	cout << "Busqueda secuencial en el diccionario" << endl;
	for (auto& kvp : diccionario) {
		if (kvp.first == variable) {
			cout << "Valor de " << variable << " en el mapa: " << kvp.second << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "No se encuentra la clave '" << variable << "' en el mapa." << endl;
	}
	parcial1(diccionario);

}
void micopia(char** dest, const char* src) {
	int contador;
	for (contador = 0; src[contador] != '\0'; contador++);
	*dest = new char[contador + 1];
	for (int i = 0; i < contador; i++) {
		(*dest)[i] = src[i];
	}
	(*dest)[contador] = '\0';
}

void micopia1(char*& dest, const char* src) {
	int contador;
	for (contador = 0; src[contador] != '\0'; contador++);
	dest = new char[contador + 1];
	for (int i = 0; i < contador; i++) {
		(dest)[i] = src[i];
	}
	(dest)[contador] = '\0';
}
