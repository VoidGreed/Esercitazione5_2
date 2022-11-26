#include "liberia.h"
#include "functions.h"

bool verifica(azienda* elenco_aziende, int i, string tipo)
{
	for (int j = 0; j < i; j++)
	{
		if(elenco_aziende[j].tipologia == tipo)
		{
			return true;
		}
		return false;
	}
}


float fatturato_medio(azienda elenco_azienda[], int n,string tipo)
{	
	float count=0;
	float media=0;
	
	for (int i = 0; i < n; i++)
	{
		if (elenco_azienda[i].tipologia == tipo)
		{
			media += elenco_azienda[i].fatturato;
			count++;
		}
	}
	media = media/ count++;

	return media;
}

azienda* nuovo_elenco_kmagg(azienda* elenco_aziende, int n, int& count, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (elenco_aziende[i].fatturato > k)
		{
			count++;
		}
	}

	azienda* nuova_azienda = new azienda[count];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (elenco_aziende[i].fatturato > k)
		{
			*(nuova_azienda+j) = *(elenco_aziende+i);
			j++;
		}
	}
	return nuova_azienda;
}
void ordinamento_vettore(azienda elenco_azienda[], int n)
{
	bool swap;
	do {
		int i = 0, lastwap = 0;
		swap = false;

		for (int j = n - 1; j > i; j--)
		{
			if (elenco_azienda[j].ragione_sociale < elenco_azienda[j - 1].ragione_sociale)
			{
				azienda temp = elenco_azienda[j - 1];
				elenco_azienda[j - 1] = elenco_azienda[j];
				elenco_azienda[j] = temp;
				swap = true;
				lastwap = j;
			}
		}

		i = lastwap;

	} while (swap);
}