#include <iostream>
#include "liberia.h"
#include "in_out.h"
#include "functions.h"
using namespace std;

int main()
{

	int n, n2;
	do {
		cout << "Quanti aziende vuoi inserire?" << endl;
		cin >> n;

	} while (n <= 0);
	azienda* elenco_aziende = new azienda[n];
	if (!elenco_aziende) {
		cout << "memoria non disponibile";
		return -1;
	}

	inserisci_aziende(elenco_aziende, n);

	for (int i = 0; i < n; i++)
	{
		if (i != 0 && verifica(elenco_aziende, i, elenco_aziende[i].tipologia))
		{
			continue;
		}
		else
		{
			float media = fatturato_medio(elenco_aziende, n, elenco_aziende[i].tipologia);
			cout << "la media per la tipologia " << elenco_aziende[i].tipologia << " e': " << media<<endl;
		}


	}
	int k = 0, count = 0;
	cout << "Inserisci la soglia K:" << endl;
	cin >> k;
	
	azienda* nuovo_elenco = nuovo_elenco_kmagg(elenco_aziende, n, count, k);
	if (!nuovo_elenco) {
		cout << "memoria non disponibile";
		return -1;
	}
	ordinamento_vettore(nuovo_elenco, count);
	stampa_aziende(nuovo_elenco, count);
	delete[] nuovo_elenco;
	delete[] elenco_aziende;
}