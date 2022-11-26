#include "in_out.h"
void inserisci_aziende(azienda* elenco_aziende, int n)
{
	

	for (int i = 0; i < n; i++)
	{
		*(elenco_aziende+i) = inserimento_azienda();
	}

}
azienda inserimento_azienda()
{
	azienda x;
	cin.ignore();
	cout << "Inserisci ragione sociale:" << endl;
	getline(cin, x.ragione_sociale);
	cout << "Inserisci tipologia " << endl;
	getline(cin, x.tipologia);
	cout << "Inserisci numero di dipendenti " << endl;
	cin >> x.n_dipendenti;
	cout << "Inserisci il fatturato (in milioni di euro)" << endl;
	cin >> x.fatturato;
	cout << "----------------------------------------------------------------" << endl;
	return x;
}

void stampa_aziende(azienda elenco_aziende[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "ragione sociale:" << endl;
		cout << elenco_aziende[i].ragione_sociale << endl;
		cout << "Tipologia:" << endl;
		cout << elenco_aziende[i].tipologia << endl;
		cout << "Numero di dipendenti:" << endl;
		cout << elenco_aziende[i].n_dipendenti << endl;
		cout << "Fatturato" << endl;
		cout << elenco_aziende[i].fatturato << endl;
		cout << "----------------------------------------------------------------" << endl;
	}
}
