#include "Header.h"

using std::string;
using std::endl;

void generatorius(int n,vector<Vartotojas>& vartotojai) {
	Vartotojas V;
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(100, 1000000); // define the range
	std::ofstream fr("users.txt");
	for (int i = 0; i < n; i++) {
		V.identifikacija("Vartotojas" + std::to_string(i+1));
		V.pinigai(distr(gen));
		fr << V.GautiVarda() << " " << V.GautiRakta() << " " << V.GautiBalansa() << endl;
		vartotojai.push_back(V);
	}
	for (int i = 0; i < n; i++) {
		
	}
}
void transaction(int n, vector<Transakcijos>& transakcija, vector<Vartotojas>& vartotojai) {
	Vartotojas S, R;
	Transakcijos D;
	string test;
	std::ofstream fr("transakcijos.txt");
	int kiek;
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, vartotojai.size()-1);
	std::uniform_int_distribution<> distribution2(1, 10000);
	for (int i = 0; i < n; i++) {
		S = vartotojai[distribution(generator)];
		R = vartotojai[distribution(generator)];
		while (S.GautiRakta() == R.GautiRakta()) {
			R = vartotojai[distribution(generator)];
		}
		kiek = distribution2(generator);
		D.transakcijosID(S.GautiRakta(), R.GautiRakta(), kiek);
		D.raktai(S.GautiRakta(), R.GautiRakta());
		D.suma(kiek);
		transakcija.push_back(D);
		fr << D.gautiID() << " " << D.gautiSiunteja() << " " << D.gautiGaveja() << " " << D.gautiKieki() << endl;
	


	}

		cout << transakcija.size() << endl;



}