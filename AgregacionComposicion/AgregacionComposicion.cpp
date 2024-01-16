#include <iostream>
#include <string>
#include <vector>

class Chip{
      public:
      std::string empresa;
      int numero;

      Chip(std::string empresa, int num ){
            this->empresa = empresa;
            this->numero = num;
        }
      void mostrar(){
            std::cout << "Empresa: " << empresa << std::endl;
            std::cout << "Numero: " << numero << std::endl;
        }

};

class Bateria{
      public:
      int mAh;
      std::string marca;

      Bateria(int mAh, std::string marca){
            this->mAh = mAh;
            this-> marca = marca;
        }
      void mostrar(){
            std::cout << "mAh: " << mAh << std::endl;
            std::cout << "Marca: " << marca << std::endl;
        }
};
class SmartPhone{
      public:
      std::string modelo;
      Bateria bateria;
      int numChips;
      std::vector<Chip> chips;

      SmartPhone(std::string modelo, std::string marca, int cantMAh): 
      modelo(modelo), bateria(cantMAh, modelo), numChips(0), chips(2){}


      std::ostream& operator<<(std::ostream& os, const SmartPhone& phone) {
            os << "Smartphone Model: " << phone.modelo << std::endl;
            os << "Battery Info: " << phone.bateria.mAh << " mAh, " << phone.bateria.marca << std::endl;
            os << "Number of Chips: " << phone.chips.size() << std::endl;

            for (const Chip& chip : phone.chips) {
                  os << "Chip Info: " << chip.empresa << ", " << chip.numero << std::endl;
              }

            return os;
        }

};

int main(){
      SmartPhone samsung = SmartPhone("s6", "Samsung", 100);
      std::cout << samsung << std::endl;
      return 0;
}

