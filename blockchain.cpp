#include "header.h"

int main()
{
	Chain Blocky = Chain();

	vector <User> vartotojai;

	vector <Transaction> Visos;
	vector <Transaction> Atrinktos;

	skaitymas(vartotojai);

	size_t MaxNonce = 100;

	uint32_t index = 2;

	bool found = false;

	kurimas(vartotojai, Visos);

	while (Visos.size() > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			BlokoKurimas(Visos, vartotojai, Blocky, index, found, MaxNonce, i);
			if (found)
			{
				index++;
				break;
			}
			else if (!found)
			{
				cout << "Nepavyko iskasti " << i + 1 << " bloko" << endl;
				MaxNonce += 100;
			}
		}
		found = false;
	}


}