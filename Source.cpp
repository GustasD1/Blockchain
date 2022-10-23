#include "Header.h"


int main() {
	vector<Vartotojas> vartotojai;
	vector<Transakcijos> transakcija;
	generatorius(1000, vartotojai);
	transaction(10000, transakcija,vartotojai);

}