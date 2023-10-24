//Domeniu: agronomie
#include <iostream>

using namespace std;

class Cereale
{
public:
	char* nume;
	const string soi;
	int durataPerioadaVegetatie;
	bool consumUman;
	float temperatura;
	static float cantitateMaximaPesticide;

	Cereale() : soi("dur")
	{
		this->nume = new char[strlen("Grau") + 1];
		strcpy_s(this->nume, strlen("Grau") + 1, "Grau");
		this->durataPerioadaVegetatie = 0;
		this->consumUman = 0;
		this->temperatura = 0;
	}

	Cereale(char* nume, string soiNou) : soi(soiNou)
	{
		this->nume = nume;
		this->durataPerioadaVegetatie = 0;
		this->consumUman = 0;
		this->temperatura = 0;
	}

	Cereale(char* nume, string soiNou, int durataPerioadaVegetatie, bool consumUman, float temperatura) : soi(soiNou)
	{
		this->nume = nume;
		this->durataPerioadaVegetatie = durataPerioadaVegetatie;
		this->consumUman = consumUman;
		this->temperatura = temperatura;
	}

	~Cereale()
	{
		delete[]this->nume;
	}

	void afisareCereale()
	{
		cout << "Cereala " << nume << " " << soi << " are perioada de vegetatie de " << durataPerioadaVegetatie << " zile. ";
		if (consumUman)
		{
			cout << "Aceasta este destinata consumului uman. ";
		}
		else
		{
			cout << "Aceasta este de tip furajer. ";
		}
		cout << "Temperatura optima pentru acest tip de cereale este in jur de " << temperatura << " grade Celsius. ";
		cout << "Cantitatea maxima de pesticide admisa este de " << cantitateMaximaPesticide << " l/ha." << endl << endl;
	}

};
float Cereale::cantitateMaximaPesticide = 60;

class Legume
{
public:
	char* nume;
	string categoriePlantaDurataVegetatie;
	bool rezistentaSeceta;
	const float pHSol;
	int distantaIntrePlante;
	static float cantitateMaximaPesticide;

	Legume() : pHSol(0)
	{
		this->nume = new char[strlen("Rosie") + 1];
		strcpy_s(this->nume, strlen("Rosie") + 1, "Rosie");
		this->categoriePlantaDurataVegetatie = "anuala";
		this->rezistentaSeceta = 0;
		this->distantaIntrePlante = 0;
	}

	Legume(bool rezistentaSeceta) : pHSol(0)
	{
		this->nume = new char[strlen("Rosie") + 1];
		strcpy_s(this->nume, strlen("Rosie") + 1, "Rosie");
		this->categoriePlantaDurataVegetatie = "anuala";
		this->rezistentaSeceta = rezistentaSeceta;
		this->distantaIntrePlante = 0;
	}

	Legume(char* nume, string categoriePlantaDurataVegetatie, bool rezistentaSeceta, float pHSolNou, int distantaIntrePlante) : pHSol(pHSolNou)
	{
		this->nume = nume;
		this->categoriePlantaDurataVegetatie = categoriePlantaDurataVegetatie;
		this->rezistentaSeceta = rezistentaSeceta;
		this->distantaIntrePlante = distantaIntrePlante;
	}

	~Legume()
	{
		delete[]this->nume;
	}

	void afisareLegume()
	{
		cout << "Leguma " << nume << " este o leguma " << categoriePlantaDurataVegetatie << ". " << (rezistentaSeceta
			? "Aceasta este rezistenta la seceta. " : "Aceasta nu este rezistenta la seceta. ");
		cout << "PH-ul solului in care este cultivata planta trebuie sa fie " << pHSol;
		cout << ". Pentru ca planta sa se poata dezvolta, este nevoie de o distanta de " << distantaIntrePlante << " cm, intre plante. ";
		cout << "Cantitatea maxima de pesticide admisa este de " << cantitateMaximaPesticide << " l/mp." << endl << endl;
	}
};
float Legume::cantitateMaximaPesticide = 0.8;

class Pomi
{
public:
	string nume;
	float inaltime;
	const bool autopolenizator;
	int nrSoiuri;
	string* soiuri;
	static float cantitateMaximaPesticide;

	Pomi() : autopolenizator(0)
	{
		this->nume = "Mar";
		this->inaltime = 0;
		this->nrSoiuri = 0;
		this->soiuri = NULL;
	}

	Pomi(float inaltime, bool autopolenizator) : autopolenizator(autopolenizator)
	{
		this->nume = "Mar";
		this->inaltime = inaltime;
		this->nrSoiuri = 0;
		this->soiuri = NULL;
	}

	Pomi(string nume, float inaltime, bool autopolenizator, int nrSoiuri, string* soiuri) : autopolenizator(autopolenizator)
	{
		this->nume = nume;
		this->inaltime = inaltime;
		this->nrSoiuri = nrSoiuri;
		this->soiuri = new string[nrSoiuri];
		if (nrSoiuri != NULL)
		{
			for (int i = 0; i < nrSoiuri; i++)
			{
				this->soiuri[i] = soiuri[i];
			}
		}
		else
		{
			this->soiuri = NULL;
		}
	}

	~Pomi()
	{
		if (this->soiuri != NULL)
			delete[]this->soiuri;
	}

	void afisarePomi()
	{
		cout << "Pomul " << nume << " are inaltimea de " << inaltime << " metri.";
		if (autopolenizator)
		{
			cout << " In aceasta specie putem intalni soiuri autopolenizatoare. ";
		}
		else
		{
			cout << " In aceasta specie nu putem intalni soiuri autopolenizatoare. ";
		}

		if (nrSoiuri != 0)
		{
			cout << nrSoiuri << " dintre cele mai intalnite soiuri ale acestei specii sunt: " << endl;
			int i;
			for (i = 0; i < nrSoiuri - 1; i++)
			{
				cout << soiuri[i] << ", ";
			}
			cout << soiuri[i] << "." << endl;
		}
		else
		{
			cout << endl;
		}
		cout << "Cantitatea maxima de pesticide admisa este de " << cantitateMaximaPesticide << " l/pom." << endl << endl;
	}
};
float Pomi::cantitateMaximaPesticide = 1;

void main()
{
	Cereale c1;
	c1.afisareCereale();

	char* nume2;
	nume2 = new char[strlen("Porumb") + 1];
	strcpy_s(nume2, strlen("Porumb") + 1, "Porumb");
	Cereale c2(nume2, "dulce");
	c2.afisareCereale();

	char* nume3;
	nume3 = new char[strlen("Secara") + 1];
	strcpy_s(nume3, strlen("Secara") + 1, "Secara");
	Cereale c3(nume3, "comuna", 100, 1, 15);
	c3.afisareCereale();

	cout << endl << endl;

	Legume l1;
	l1.afisareLegume();

	Legume l2(1);
	l2.afisareLegume();

	char* leguma;
	leguma = new char[strlen("Ceapa") + 1];
	strcpy_s(leguma, strlen("Ceapa") + 1, "Ceapa");
	Legume l3(leguma, "bienala", 1, 6.5, 30);
	l3.afisareLegume();

	cout << endl << endl;

	Pomi p1;
	p1.afisarePomi();

	Pomi p2(2.3, 1);
	p2.afisarePomi();

	int nrSoiuri = 3;
	/*cout << "Introduceti numarul de soiuri: ";
	cin >> nrSoiuri;*/
	string* soiuri = new string[nrSoiuri];
	/*for (int i = 0; i < nrSoiuri; i++)
	{
		cout << "Soiul " << i+1 << ": ";
		cin >> soiuri[i];
	}*/
	soiuri[0] = "Williams";
	soiuri[1] = "Kieffer";
	soiuri[2] = "Santa Maria";
	Pomi p3("Par", 1.9, 1, nrSoiuri, soiuri);
	p3.afisarePomi();

}

