#include "Constructores.h"

void parcial( map<string, string>& dic) {
	vector<pair<int, string>> vect;
	pair<int, string> par; 
	for (auto& item : dic) {
		int cont = 0;
		int suma = 0;
		while (item.first[cont] != '\0') {
			suma += item.first[cont];
			cont++;
		}
		par.first = suma;
		string cifrado = "";
		int shift = 3;
		//*******
		for (char c : item.second) {
			if (isalpha(c)) {
				char base = (isupper(c)) ? 'A' : 'a';
				cifrado += static_cast<char>((c - base + shift) % 26 + base);
			}
			else {
				cifrado += c; 
			}
		}
		//**********
		par.second = cifrado;
		vect.push_back(par);
	}
	
	for (int i = 0; i < 5; i++) {
		cout << "\n" << endl;
		cout << "El elemento " << i + 1 << " del vector tiene los siguientes elementos: " << endl;
		cout << "La suma de la llave es: " << vect[i].first << endl;
		cout << "El cifrado del valor es: " << vect[i].second << endl;
		cout << "\n" << endl;
	}

}

void parcial1(map<string, string>& dic) {
	vector<pair<int, string>> vect;
	pair<int, string> par;
	for (auto& item : dic) {
		int cont = 0;
		int suma = 0;
		while (item.first[cont] != '\0') {
			suma += item.first[cont];
			cont++;
		}
		par.first = suma;
		string cifrado = "";
		int shift = suma;
		//*******
		for (char c : item.second) {
			if (isalpha(c)) {
				char base = (isupper(c)) ? 'A' : 'a';
				cifrado += static_cast<char>((c - base + shift) % 26 + base);
			}
			else {
				cifrado += c;
			}
		}
		//**********
		par.second = cifrado;
		vect.push_back(par);
	}

	for (int i = 0; i < 5; i++) {
		cout << "\n" << endl;
		cout << "El elemento " << i + 1 << " del vector tiene los siguientes elementos: " << endl;
		cout << "La suma de la llave es: " << vect[i].first << endl;
		cout << "El cifrado del valor es: " << vect[i].second << endl;
		cout << "\n" << endl;
	}

}

