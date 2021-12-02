/*
 *  main.cpp
 *  Integral B
 *  José Sebastián Pedrero Jiménez
 *  A01703331
*/ 

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>
#include "hasher.h" 

using namespace std;

unsigned int Hash(const string s) {
	unsigned int sum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		sum += (int) s[i];
	}
	return sum;
};

int main(int argc, char* argv[]) {
    HashTable<std::string, int> Kitsune(30, "Mario", Hash);
    std::ofstream Runs("SMO-besttimes.csv"); // Toma un archivo de salida
    Runs << "Player,Time" << "\n";
    
    Kitsune.insert("ML",4381);
    Kitsune.insert("Trop",5012);
    Kitsune.insert("Ren",8429);
    Kitsune.insert("ML",4223);
    Kitsune.insert("ML",4294);
    Kitsune.insert("Goro",4203);
    Kitsune.insert("Tari",5231);
    Kitsune.insert("Saber",4932);
    Kitsune.insert("NecoArc",4423);
    Kitsune.insert("Pringle",3523);
    Kitsune.insert("SMG3",6969);
    Kitsune.insert("SMG4",6969);

    Runs << Kitsune.printBestTimes();
    Runs.close();

    return 0;
}