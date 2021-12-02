/*
 *  hasher.h
 *  Integral AB
 *  José Sebastián Pedrero Jiménez
 *  A01703331
*/ 


#ifndef HASHER_H
#define HASHER_H

#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

template <class Player, class Time>
class HashTable {
private:
	unsigned int (*gear) (const Player p);
	unsigned int tamanio;
	unsigned int count;

	Player *players;
	Player GuestA;
	Time *times;

	long indexOf(const Player) const;

public:
	HashTable(unsigned int, Player,unsigned int (*g) (const Player));
	~HashTable();
	bool full() const;
	void insert(Player, Time) ;
	bool existance(const Player) const;
	Time getTotalTime(const Player);
	void clear();
	std::string printTime(int) const;
	std::string printBestTimes() const;
};

template <class Player, class Time>
HashTable<Player, Time>::HashTable(unsigned int tmn, Player guest, unsigned int (*g) (const Player)) {
	tamanio = tmn;
	players = new Player[tamanio];
	GuestA = guest;
	for (unsigned int i = 0; i < tamanio; i++) {
		players[i] = guest;
	}
	times = new Time[tamanio];
	for (int i = 0; i  < tmn; i++){
        times[i] = 0;
    }
	gear = g;
	count = 0;
}

template <class Player, class Time>
HashTable<Player, Time>::~HashTable() {
	delete [] players;
	players = NULL;
	delete [] times;
	times = NULL;
	tamanio = 0;
	count = 0;
}

template <class Player, class Time>
bool HashTable<Player, Time>::full() const {
	return (count > tamanio);
}

template <class Player, class Time>
long HashTable<Player, Time>::indexOf(const Player p) const {
	unsigned int i, start;

	start = i = gear(p) % tamanio;
	do {
		if (players[i] == p) {
			return i;
		}
		i = (i + 1) % tamanio;
	} while (start != i);
	return -1;
}

template <class Player, class Time>
void HashTable<Player, Time>::insert(Player p, Time t) {
	unsigned int i, start;
	long pos;

	pos = indexOf(p);
	if (pos != -1) {
        if (times[pos] >= t){
		    times[pos] = t;
		    return;
        }
        return;
	}

	start = i = gear(p) % tamanio;
	do {
		if (players[i] == GuestA) {
			players[i] = p;
			times[i] = t;
			count++;
			return;
		}
		i = (i + 1) % tamanio;
	} while (start != i);
	return;
}

template <class Player, class Time>
bool HashTable<Player, Time>::existance(const Player p) const {
	long pos;

	pos = indexOf(p);
	return (pos != -1);
}

template <class Player, class Time>
Time HashTable<Player, Time>::getTotalTime(const Player p){
	unsigned int i, start;
	long pos;

	pos = indexOf(p);
	if (pos != -1) {
		return times[pos];
	}
	return -1;
}

template <class Player, class Time>
void HashTable<Player, Time>::clear() {
	count = 0;
	for (unsigned int i = 0; i < tamanio; i++) {
		players[i] = GuestA;
	}
}

template <class Player, class Time>
std::string HashTable<Player,Time>::printTime(int Tseconds) const{
	std::stringstream aux;
    int seconds = Tseconds;
    int minutes = floor(Tseconds/60);
    int hours = floor(minutes/60);

    if (hours>0){
        aux << hours << ":";
    }
	if (minutes%60 < 10){
		aux << "0";
	}
    aux << minutes%60 << ":";
	if (seconds%60 < 10){
		aux << "0";
	}
    aux << seconds%60;
    return aux.str();
}

template <class Player, class Time>
std::string HashTable<Player, Time>::printBestTimes() const {
	std::stringstream aux;
	for (unsigned int i	 = 0; i < tamanio; i++) {
		//if (players[i] != GuestA)
			aux << players[i] << "," << printTime(times[i]) << "\n";
	}
	return aux.str();
}

#endif
