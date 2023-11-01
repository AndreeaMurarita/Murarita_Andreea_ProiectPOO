//Domeniul: agronomie
#include <iostream>

using namespace std;

class Cereale
{
private:
	char* nume;
	const string soi;
	int durataPerioadaVegetatie;
	bool consumUman;
	float temperatura;
	static float cantitateMaximaPesticide;

public:
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

	Cereale(const Cereale& c) : soi(c.soi)
	{
		this->nume = new char[strlen(c.nume) + 1];
		strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
		this->durataPerioadaVegetatie = c.durataPerioadaVegetatie;
		this->consumUman = c.consumUman;
		this->temperatura = c.temperatura;
	}

	~Cereale()
	{
		delete[]this->nume;
	}


	char* getNume()
	{
		return this->nume;
	}

	void setNume(char* nume)
	{
		if (strlen(nume) + 1 > 1)
		{
			this->nume = nume;
		}
	}

	const string getSoi()
	{
		return this->soi;
	}

	int getDurataPerioadaVegetatie()
	{
		return this->durataPerioadaVegetatie;
	}

	void setDurataPerioadaVegetatie(int durataPerioadaVegetatie)
	{
		if (durataPerioadaVegetatie > 0)
		{
			this->durataPerioadaVegetatie = durataPerioadaVegetatie;
		}
	}

	bool getConsumUman()
	{
		return this->consumUman;
	}

	void setConsumUman(bool consumUman)
	{
		this->consumUman = consumUman;
	}

	float getTemperatura()
	{
		return this->temperatura;
	}

	void setTemperatura(float temperatura)
	{
		if (temperatura > 0)
		{
			this->temperatura = temperatura;
		}
	}

	static float getCantitateMaximaPesticide()
	{
		return Cereale::cantitateMaximaPesticide;
	}

	static void setCantitateMaximaPesticide(float cantitate)
	{
		if (cantitate > 0)
		{
			Cereale::cantitateMaximaPesticide = cantitate;
		}
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
		cout << "Temperatura optima de coacere pentru acest tip de cereale este in jur de " << temperatura << " grade Celsius. ";
		cout << "Cantitatea maxima de pesticide admisa in Romania este, in medie,  de " << cantitateMaximaPesticide << " kg/ha." << endl << endl;
	}

	friend float temperaturaIncoltire(Cereale c);

};
float Cereale::cantitateMaximaPesticide = 60;

float temperaturaIncoltire(Cereale c)
{
	return c.temperatura - 15;
}


class Legume
{
private:
	char* nume;
	string categoriePlantaDurataVegetatie;
	bool rezistentaSeceta;
	const float pHSol;
	int distantaIntrePlante;
	static int nrTotalSpecii;

public:
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

	Legume(const Legume& l) : pHSol(l.pHSol)
	{
		this->nume = new char[strlen(l.nume) + 1];
		strcpy_s(this->nume, strlen(l.nume) + 1, l.nume);
		this->categoriePlantaDurataVegetatie = l.categoriePlantaDurataVegetatie;
		this->rezistentaSeceta = l.rezistentaSeceta;
		this->distantaIntrePlante = l.distantaIntrePlante;
	}

	~Legume()
	{
		delete[]this->nume;
	}

	char* getNume()
	{
		return this->nume;
	}

	void setNume(char* nume)
	{
		if (strlen(nume) + 1 > 1)
		{
			this->nume = nume;
		}
	}

	string getCategoriePlantaDurataVegetatie()
	{
		return this->categoriePlantaDurataVegetatie;
	}

	void setCategoriePlantaDurataVegetatie(string categorie)
	{
		if (categorie.length() > 0)
		{
			this->categoriePlantaDurataVegetatie = categorie;
		}
	}

	bool getRezistentaSeceta()
	{
		return this->rezistentaSeceta;
	}

	void setRezistentaSeceta(bool rezistenta)
	{
		this->rezistentaSeceta = rezistenta;
	}

	const float getPHSol()
	{
		return this->pHSol;
	}

	int getDistantaIntrePlante()
	{
		return this->distantaIntrePlante;
	}

	void setDistantaIntrePlante(int distanta)
	{
		if (distanta > 0)
		{
			this->distantaIntrePlante = distanta;
		}
	}

	static int getNrTotalSpecii()
	{
		return Legume::nrTotalSpecii;
	}

	static void setNrTotalSpecii(int nrTotalSpecii)
	{
		if (nrTotalSpecii > 0)
		{
			Legume::nrTotalSpecii = nrTotalSpecii;
		}
	}

	void afisareLegume()
	{
		cout << "Leguma " << nume << " este o leguma " << categoriePlantaDurataVegetatie << ". " << (rezistentaSeceta
			? "Aceasta este rezistenta la seceta. " : "Aceasta nu este rezistenta la seceta. ");
		cout << "PH-ul solului in care este cultivata planta trebuie sa fie " << pHSol;
		cout << ". Pentru ca planta sa se poata dezvolta, este nevoie de o distanta de " << distantaIntrePlante << " cm, intre plante. ";
		cout << "In lume se estimeaza a fi undeva pe la " << nrTotalSpecii << " de soiuri de plante." << endl << endl;
	}
};
int Legume::nrTotalSpecii = 10000;

class Pomi
{
private:
	string nume;
	float inaltime;
	const bool autopolenizator;
	int nrSoiuri;
	string* soiuri;
	static int nrTotalSpecii;

public:
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

	Pomi(const Pomi& p) : autopolenizator(p.autopolenizator)
	{
		this->nume = p.nume;
		this->inaltime = p.inaltime;
		this->nrSoiuri = p.nrSoiuri;
		if (nrSoiuri > 0)
		{
			this->soiuri = new string[nrSoiuri];
			for (int i = 0; i < nrSoiuri; i++)
			{
				this->soiuri[i] = p.soiuri[i];
			}
		}
	}

	~Pomi()
	{
		if (this->soiuri != NULL)
			delete[]this->soiuri;
	}

	string getNume()
	{
		return this->nume;
	}

	void setNume(string nume)
	{
		if (nume.length() > 1)
		{
			this->nume = nume;
		}
	}

	float getInaltime()
	{
		return this->inaltime;
	}

	void setInaltime(float inaltime)
	{
		if (inaltime > 0)
		{
			this->inaltime = inaltime;
		}
	}

	const bool getAutopolenizator()
	{
		return this->autopolenizator;
	}

	int getNrSoiuri()
	{
		return this->nrSoiuri;
	}

	string* getSoiuri()
	{
		return this->soiuri;
	}

	/*char* getSoi(int index)
	{
		if (index >= 0)
		{
			return this->soiuri[index];
		}
	}*/

	void setSoiuri(int nrSoiuri, string* soiuri)
	{
		if (nrSoiuri > 0)
		{
			this->nrSoiuri = nrSoiuri;
			if (this->soiuri != NULL)
			{
				delete[]this->soiuri;
			}
			this->soiuri = new string[nrSoiuri];
			for (int i = 0; i < nrSoiuri; i++)
			{
				this->soiuri[i] = soiuri[i];
			}
		}
	}

	void setNrSoiuri(int nrSoiuri)
	{
		if (nrSoiuri > 0)
		{
			this->nrSoiuri = nrSoiuri;
		}
	}

	static int getNrTotalSpecii()
	{
		return Pomi::nrTotalSpecii;
	}

	static void setNrTotalSpecii(int nrTotalSpecii)
	{
		if (nrTotalSpecii > 0)
		{
			Pomi::nrTotalSpecii = nrTotalSpecii;
		}
	}

	void afisarePomi()
	{
		cout << "Pomul " << nume << " are, in medie, inaltimea de " << inaltime << " metri.";
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
		cout << "In lume exista in total peste " << nrTotalSpecii << " de soiuri de pomi." << endl << endl;
	}

	friend void ordonareSoiuri(Pomi& p);
};
int Pomi::nrTotalSpecii = 60000;

void ordonareSoiuri(Pomi& p)
{
	for (int i = 0; i < p.nrSoiuri - 1; i++)
		for (int j = 0; j < p.nrSoiuri; j++)
			if (p.soiuri[i] > p.soiuri[j])
			{
				string aux = p.soiuri[i];
				p.soiuri[i] = p.soiuri[j];
				p.soiuri[j] = aux;
			}
}


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

	Cereale c4 = c3;
	cout << "In medie, o temperatura buna de incoltire este cu 15 grade mai mica decat temperatura optima pentru coacere. Stiind care este temperatura optima pentru coacere, temperatura de incoltire este: "
		<< temperaturaIncoltire(c4) << " grade Celsius.";

	char* cereala;
	cereala = new char[strlen("Orz") + 1];
	strcpy_s(cereala, strlen("Orz") + 1, "Orz");
	c1.setNume(cereala);
	cout << c1.getNume() << endl;
	cout << c1.getSoi() << endl;

	c2.setDurataPerioadaVegetatie(90);
	cout << c2.getDurataPerioadaVegetatie() << endl;

	c3.setConsumUman(1);
	cout << c3.getConsumUman() << endl;

	c4.setTemperatura(30);
	cout << c4.getTemperatura() << endl;

	cout << c4.getCantitateMaximaPesticide() << endl;
	c4.setCantitateMaximaPesticide(50);

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

	Legume l4 = l3;

	Legume l5;
	char* leguma5;
	leguma5 = new char[strlen("Sparanghel") + 1];
	strcpy_s(leguma5, strlen("Sparanghel") + 1, "Sparanghel");
	l5.setNume(leguma5);
	cout << l5.getNume() << endl;

	l2.setCategoriePlantaDurataVegetatie("Perena");
	cout << l2.getCategoriePlantaDurataVegetatie() << endl;

	l3.setRezistentaSeceta(1);
	cout << l3.getRezistentaSeceta() << endl;

	cout << l3.getPHSol() << endl;

	l4.setDistantaIntrePlante(40);
	cout << l4.getDistantaIntrePlante() << endl;

	l5.setNrTotalSpecii(10500);
	cout << l5.getNrTotalSpecii() << endl;

	cout << endl << endl;

	Pomi p1;
	p1.afisarePomi();

	Pomi p2(2.3, 1);
	p2.afisarePomi();

	int nrSoiuri = 3;
	cout << "Introduceti numarul de soiuri: ";
	cin >> nrSoiuri;
	string* soiuri = new string[nrSoiuri];
	for (int i = 0; i < nrSoiuri; i++)
	{
		cout << "Soiul " << i + 1 << ": ";
		cin >> soiuri[i];
	}
	/*soiuri[0] = "Williams";
	soiuri[1] = "Kieffer";
	soiuri[2] = "Santa Maria";*/
	Pomi p3("Par", 1.9, 1, nrSoiuri, soiuri);
	p3.afisarePomi();
	ordonareSoiuri(p3);
	p3.afisarePomi();

	Pomi p4 = p2;

	p1.setNume("Cires");
	cout << p1.getNume() << endl;

	p2.setInaltime(1.7);
	cout << p2.getInaltime() << endl;

	cout << p3.getAutopolenizator() << endl;

	p4.setNrSoiuri(4);
	cout << p4.getNrSoiuri() << endl;

	Pomi p5;
	int nrSoiuri5 = 2;
	string* pomi5 = new string[nrSoiuri]{ "Japonez", "Nanking" };
	p5.setSoiuri(nrSoiuri5, pomi5);
	p5.setNrTotalSpecii(60100);
	cout << p5.getNrTotalSpecii() << endl;

}

