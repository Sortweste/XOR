#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

int main() {
    std::string x, key;
    std::string cipher="";
    int value;
    //Ingresamos la clave:
    std::getline(std::cin,key);
    std::bitset<8> clave (key);
    //Ingresamos la cadena de texto:
    std::getline(std::cin,x);
    std::transform(x.begin(), x.end(),x.begin(), ::toupper);
    for(int i=0; i<x.length();i++) {
        value = (int) (std::bitset<8>(x[i]) ^= clave).to_ulong();
        cipher += (value % 26 == 0) ? (char) 90 : (char) (value % 26 + 64);
    }
    std::cout<<cipher<<'\n';
    return 0;
}