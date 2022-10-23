#pragma once
#include "sha256.h"
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <sstream>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Vartotojas {
private:
	int balansas;
	string  vardas, public_key;

public:
	Vartotojas() { balansas = 0;  vardas = ""; public_key = "";}
	~Vartotojas() {}
	void identifikacija(string s){
		vardas = s;
		public_key = sha256(s);
	}
	void pinigai(int sk) {
		balansas = sk;
	}
	string GautiVarda() {
		return vardas;
	}
	string GautiRakta() {
		return public_key;
	}
	int GautiBalansa() {
		return balansas;
	}

};
class Transakcijos {
private:
	string id;
	string siuntejas;
	string gavejas;
	int kiekis;


public:
	Transakcijos() { 
		id = "";
		siuntejas = "";
		gavejas = ""; 
		kiekis = 0;
}
	~Transakcijos() {}

	void transakcijosID(string s, string g, int k) {
		id = sha256(s + g + std::to_string(k));
	}
	void raktai(string s, string g) {
		siuntejas = s;
		gavejas = g;
	}
	void suma(int k) {
		kiekis = k;
	}
	string gautiID() {
		return id;
	}
	string gautiSiunteja() {
		return siuntejas;
	}
	string gautiGaveja() {
		return gavejas;
	}
	int gautiKieki() {
		return kiekis;
	}
    

};



void generatorius(int n, vector<Vartotojas>& vartotojai);
void transaction(int n, vector<Transakcijos>& transakcija, vector<Vartotojas>& vartotojai);