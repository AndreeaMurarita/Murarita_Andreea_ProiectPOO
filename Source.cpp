//Domeniul: agronomie
#include <iostream>

using namespace std;

class Cereala
{
private:
	char* nume;
	string soi;
	int durataPerioadaVegetatie;
	const bool consumUman;
	float temperatura;
	static float cantitateMaximaPesticide;

public:
	Cereala() : consumUman(1)
	{
		this->nume = new char[strlen("Grau") + 1];
		strcpy_s(this->nume, strlen("Grau") + 1, "Grau");
		this->soi = "dur";
		this->durataPerioadaVegetatie = 0;
		this->temperatura = 0;
	}

	Cereala(char* nume, string soi, bool consumUmanNou) : consumUman(consumUmanNou)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->soi = soi;
		this->durataPerioadaVegetatie = 0;
		this->temperatura = 0;
	}

	Cereala(char* nume, string soi, int durataPerioadaVegetatie, bool consumUman, float temperatura) : consumUman(1)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->soi = soi;
		this->durataPerioadaVegetatie = durataPerioadaVegetatie;
		this->temperatura = temperatura;
	}

	Cereala(const Cereala& c) : consumUman(c.consumUman)
	{
		this->nume = new char[strlen(c.nume) + 1];
		strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
		this->soi = c.soi;
		this->durataPerioadaVegetatie = c.durataPerioadaVegetatie;
		this->temperatura = c.temperatura;
	}

	~Cereala()
	{
		delete[]this->nume;
	}


	char* getNume()
	{
		return this->nume;
	}

	void setNume(char* nume)
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		if (strlen(nume) + 1 > 1)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	string getSoi()
	{
		return this->soi;
	}

	void setSoi(string soi)
	{
		if (strlen(nume) + 1 > 1)
		{
			this->soi = soi;
		}
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

	const bool getConsumUman()
	{
		return this->consumUman;
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
		return Cereala::cantitateMaximaPesticide;
	}

	static void setCantitateMaximaPesticide(float cantitate)
	{
		if (cantitate > 0)
		{
			Cereala::cantitateMaximaPesticide = cantitate;
		}
	}

	Cereala operator=(const Cereala& c)
	{
		if (this != &c)
		{
			if (this->nume != NULL)
			{
				delete[]nume;
			}
			this->nume = new char[strlen(c.nume) + 1];
			strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
			this->soi = c.soi;
			this->durataPerioadaVegetatie = c.durataPerioadaVegetatie;
			this->temperatura = c.temperatura;
		}
		return *this;
	}

	Cereala operator+=(const Cereala& c)
	{
		char* aux = new char[strlen(this->nume) + strlen(c.nume) + 1];
		strcpy_s(aux, strlen(this->nume) + 1, this->nume);
		strcpy_s(aux + strlen(this->nume), strlen(c.nume) + 1, c.nume);
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		this->nume = aux;
		this->durataPerioadaVegetatie += c.durataPerioadaVegetatie;
		this->temperatura += c.temperatura;
		return *this;
	}

	explicit operator int()
	{
		return durataPerioadaVegetatie;
	}

	operator float()
	{
		return temperatura;
	}

	void afisareCereala()
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

	friend float temperaturaIncoltire(Cereala c);
	friend ostream& operator<<(ostream& out, const Cereala& c);
};
float Cereala::cantitateMaximaPesticide = 60;

ostream& operator<<(ostream& out, const Cereala& c)
{
	out << "Cereala " << c.nume << " " << c.soi << " are perioada de vegetatie de " << c.durataPerioadaVegetatie << " zile. ";
	if (c.consumUman)
	{
		out << "Aceasta este destinata consumului uman. ";
	}
	else
	{
		out << "Aceasta este de tip furajer. ";
	}
	out << "Temperatura optima de coacere pentru acest tip de cereale este in jur de " << c.temperatura << " grade Celsius. ";
	out << "Cantitatea maxima de pesticide admisa in Romania este, in medie,  de " << c.cantitateMaximaPesticide << " kg/ha." << endl << endl;
	return out;
}

float temperaturaIncoltire(Cereala c)
{
	return c.temperatura - 15;
}


class Leguma
{
private:
	char* nume;
	string categoriePlantaDurataVegetatie;
	bool rezistentaSeceta;
	const float pHSol;
	int distantaIntrePlante;
	static int nrTotalSpecii;

public:
	Leguma() : pHSol(7)
	{
		this->nume = new char[strlen("Rosie") + 1];
		strcpy_s(this->nume, strlen("Rosie") + 1, "Rosie");
		this->categoriePlantaDurataVegetatie = "anuala";
		this->rezistentaSeceta = 0;
		this->distantaIntrePlante = 0;
	}

	Leguma(bool rezistentaSeceta) : pHSol(7)
	{
		this->nume = new char[strlen("Rosie") + 1];
		strcpy_s(this->nume, strlen("Rosie") + 1, "Rosie");
		this->categoriePlantaDurataVegetatie = "anuala";
		this->rezistentaSeceta = rezistentaSeceta;
		this->distantaIntrePlante = 0;
	}

	Leguma(char* nume, string categoriePlantaDurataVegetatie, bool rezistentaSeceta, float pHSolNou, int distantaIntrePlante) : pHSol(pHSolNou)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->categoriePlantaDurataVegetatie = categoriePlantaDurataVegetatie;
		this->rezistentaSeceta = rezistentaSeceta;
		this->distantaIntrePlante = distantaIntrePlante;
	}

	Leguma(const Leguma& l) : pHSol(l.pHSol)
	{
		this->nume = new char[strlen(l.nume) + 1];
		strcpy_s(this->nume, strlen(l.nume) + 1, l.nume);
		this->categoriePlantaDurataVegetatie = l.categoriePlantaDurataVegetatie;
		this->rezistentaSeceta = l.rezistentaSeceta;
		this->distantaIntrePlante = l.distantaIntrePlante;
	}

	~Leguma()
	{
		delete[]this->nume;
	}

	char* getNume()
	{
		return this->nume;
	}

	void setNume(char* nume)
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
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
		return Leguma::nrTotalSpecii;
	}

	static void setNrTotalSpecii(int nrTotalSpecii)
	{
		if (nrTotalSpecii > 0)
		{
			Leguma::nrTotalSpecii = nrTotalSpecii;
		}
	}

	Leguma operator=(const Leguma& l)
	{
		if (this != &l)
		{
			if (this->nume != NULL)
			{
				delete[]nume;
			}
			this->nume = new char[strlen(l.nume) + 1];
			strcpy_s(this->nume, strlen(l.nume) + 1, l.nume);
			this->categoriePlantaDurataVegetatie = l.categoriePlantaDurataVegetatie;
			this->rezistentaSeceta = l.rezistentaSeceta;
			this->distantaIntrePlante = l.distantaIntrePlante;
		}
		return *this;
	}

	bool operator<(const Leguma& l) const
	{
		return this->distantaIntrePlante < l.distantaIntrePlante;
	}

	Leguma operator++()
	{
		this->distantaIntrePlante += 5;
		return *this;
	}

	Leguma operator++(int)
	{
		Leguma copie = *this;
		this->distantaIntrePlante += 5;
		return copie;
	}

	void afisareLeguma()
	{
		cout << "Leguma " << nume << " este o leguma " << categoriePlantaDurataVegetatie << ". " << (rezistentaSeceta
			? "Aceasta este rezistenta la seceta. " : "Aceasta nu este rezistenta la seceta. ");
		cout << "PH-ul solului in care este cultivata planta trebuie sa fie " << pHSol;
		cout << ". Pentru ca planta sa se poata dezvolta, este nevoie de o distanta de " << distantaIntrePlante << " cm, intre plante. ";
		cout << "In lume se estimeaza a fi undeva pe la " << nrTotalSpecii << " de soiuri de plante." << endl << endl;
	}

	friend istream& operator>>(istream& in, Leguma& l)
	{
		cout << "Numele legumei este: ";
		in >> l.nume;
		cout << "In functie de durata de vegetatie, aceasta este (anuala/bienala/perena): ";
		in >> l.categoriePlantaDurataVegetatie;
		cout << "Este rezistenta la seceta? (0 - nu, 1 - da) ";
		in >> l.rezistentaSeceta;
		cout << "Pentru ca planta sa se poata dezvolta, este nevoie de o distanta de: ";
		in >> l.distantaIntrePlante;
		return in;
	}
};
int Leguma::nrTotalSpecii = 10000;

class Pom
{
private:
	string nume;
	float inaltimeMedie;
	const bool autopolenizator;
	int nrSoiuri;
	string* soiuri;
	static int nrTotalSpecii;

public:
	Pom() : autopolenizator(0)
	{
		this->nume = "Mar";
		this->inaltimeMedie = 0;
		this->nrSoiuri = 0;
		this->soiuri = NULL;
	}

	Pom(float inaltimeMedie, bool autopolenizator) : autopolenizator(autopolenizator)
	{
		this->nume = "Mar";
		this->inaltimeMedie = inaltimeMedie;
		this->nrSoiuri = 0;
		this->soiuri = NULL;
	}

	Pom(string nume, float inaltimeMedie, bool autopolenizator, int nrSoiuri, string* soiuri) : autopolenizator(autopolenizator)
	{
		this->nume = nume;
		this->inaltimeMedie = inaltimeMedie;
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

	Pom(const Pom& p) : autopolenizator(p.autopolenizator)
	{
		this->nume = p.nume;
		this->inaltimeMedie = p.inaltimeMedie;
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

	~Pom()
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

	float getInaltimeMedie()
	{
		return this->inaltimeMedie;
	}

	void setInaltimeMedie(float inaltimeMedie)
	{
		if (inaltimeMedie > 0)
		{
			this->inaltimeMedie = inaltimeMedie;
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

	string* getSoiuri() const
	{
		return this->soiuri;
	}

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
		return Pom::nrTotalSpecii;
	}

	static void setNrTotalSpecii(int nrTotalSpecii)
	{
		if (nrTotalSpecii > 0)
		{
			Pom::nrTotalSpecii = nrTotalSpecii;
		}
	}

	Pom operator=(const Pom& p)
	{
		if (this != &p)
		{
			this->nume = p.nume;
			this->inaltimeMedie = p.inaltimeMedie;
			this->nrSoiuri = p.nrSoiuri;
			if (this->soiuri != NULL)
			{
				delete[]soiuri;
			}
			if (this->nrSoiuri != 0)
			{
				this->soiuri = new string[nrSoiuri];
				for (int i = 0; i < nrSoiuri; i++)
				{
					this->soiuri[i] = p.soiuri[i];
				}
			}
		}
		return *this;
	}

	Pom operator+(const Pom& p) const
	{
		Pom copie = *this;
		copie.inaltimeMedie = this->inaltimeMedie + p.inaltimeMedie;
		copie.nrSoiuri = this->nrSoiuri + p.nrSoiuri;
		if (copie.soiuri != NULL)
		{
			delete[]copie.soiuri;
		}
		if (copie.nrSoiuri > 0)
		{
			copie.soiuri = new string[copie.nrSoiuri];
			for (int i = 0; i < this->nrSoiuri; i++)
			{
				copie.soiuri[i] = soiuri[i];
			}
			for (int i = this->nrSoiuri; i < copie.nrSoiuri; i++)
			{
				copie.soiuri[i] = p.soiuri[i - nrSoiuri];
			}
		}
		else
		{
			copie.soiuri = NULL;
		}
		return copie;
	}

	Pom operator+(int a)
	{
		Pom copie = *this;
		copie.inaltimeMedie = this->inaltimeMedie + a;
		return copie;
	}

	bool operator==(const Pom& p)
	{
		if (this->nume == p.nume && this->inaltimeMedie == p.inaltimeMedie && this->nrSoiuri == p.nrSoiuri)
		{
			int ok = 1;
			for (int i = 0; i < this->nrSoiuri; i++)
			{
				if (this->soiuri[i] != p.soiuri[i])
				{
					ok = 0;
					break;
				}
			}
			return ok;
		}
	}

	string& operator[](int i)
	{
		if (i >= 0 && i < this->nrSoiuri)
		{
			return soiuri[i];
		}
	}

	void afisarePom()
	{
		cout << "Pomul " << nume << " are, in medie, inaltimea de " << inaltimeMedie << " metri.";
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

	friend Pom operator+(int, Pom);
	friend void ordonareSoiuri(Pom& p);
};
int Pom::nrTotalSpecii = 60000;

Pom operator+(int a, Pom p)
{
	Pom copie = p;
	copie.inaltimeMedie = a + p.inaltimeMedie;
	return copie;
}

void ordonareSoiuri(Pom& p)
{
	for (int i = 0; i < p.nrSoiuri - 1; i++)
		for (int j = i + 1; j < p.nrSoiuri; j++)
			if (p.soiuri[i] > p.soiuri[j])
			{
				string aux = p.soiuri[i];
				p.soiuri[i] = p.soiuri[j];
				p.soiuri[j] = aux;
			}
}


void main()
{
	Cereala c1;
	c1.afisareCereala();

	char* nume2;
	nume2 = new char[strlen("Porumb") + 1];
	strcpy_s(nume2, strlen("Porumb") + 1, "Porumb");
	Cereala c2(nume2, "dulce", 1);
	c2.afisareCereala();

	char* nume3;
	nume3 = new char[strlen("Secara") + 1];
	strcpy_s(nume3, strlen("Secara") + 1, "Secara");
	Cereala c3(nume3, "comuna", 100, 1, 25);
	c3.afisareCereala();

	Cereala c4 = c3;
	cout << "In medie, o temperatura buna de incoltire este cu 15 grade mai mica decat temperatura optima pentru coacere. Stiind care este temperatura optima pentru coacere, temperatura de incoltire este: "
		<< temperaturaIncoltire(c4) << " grade Celsius." << endl << endl;

	char* cereala;
	cereala = new char[strlen("Orz") + 1];
	strcpy_s(cereala, strlen("Orz") + 1, "Orz");
	c2.setNume(cereala);
	c2.setSoi("Smarald");
	c2.setDurataPerioadaVegetatie(90);
	c2.setTemperatura(30);
	c2.setCantitateMaximaPesticide(50);

	cout << "Cereala " << c2.getNume() << " " << c2.getSoi() << " are perioada de vegetatie de " << c2.getDurataPerioadaVegetatie() << " zile. ";
	if (c2.getConsumUman())
	{
		cout << "Aceasta este destinata consumului uman. ";
	}
	else
	{
		cout << "Aceasta este de tip furajer. ";
	}
	cout << "Temperatura optima de coacere pentru acest tip de cereale este in jur de " << c2.getTemperatura() << " grade Celsius. ";
	cout << "Cantitatea maxima de pesticide admisa in Romania este, in medie,  de " << c2.getCantitateMaximaPesticide() << " kg/ha." << endl << endl;

	c4 = c2;
	cout << c4;

	c3 += c2;
	cout << c3;

	int durataPerioadaVegetatie = (int)c2;
	cout << "Durata perioadei de vegetatie pentru " << c2.getNume() << " este de: " << durataPerioadaVegetatie << " zile." << endl;
	float temperatura = c2;
	cout << "Temperatura optima pentru " << c2.getNume() << " este de: " << temperatura << " grade Celsius." << endl;

	cout << endl << endl;

	Leguma l1;
	l1.afisareLeguma();

	Leguma l2(1);
	l2.afisareLeguma();

	char* leguma;
	leguma = new char[strlen("Ceapa") + 1];
	strcpy_s(leguma, strlen("Ceapa") + 1, "Ceapa");
	Leguma l3(leguma, "bienala", 1, 6.5, 30);
	l3.afisareLeguma();

	Leguma l4 = l3;
	l4.afisareLeguma();

	Leguma l5;
	char* leguma5;
	leguma5 = new char[strlen("Sparanghel") + 1];
	strcpy_s(leguma5, strlen("Sparanghel") + 1, "Sparanghel");
	l5.setNume(leguma5);
	l5.setCategoriePlantaDurataVegetatie("perena");
	l5.setRezistentaSeceta(1);
	l5.setDistantaIntrePlante(40);
	l5.setNrTotalSpecii(10500);

	cout << "Leguma " << l5.getNume() << " este o leguma " << l5.getCategoriePlantaDurataVegetatie() << ". " << (l5.getRezistentaSeceta()
		? "Aceasta este rezistenta la seceta. " : "Aceasta nu este rezistenta la seceta. ");
	cout << "PH-ul solului in care este cultivata planta trebuie sa fie " << l5.getPHSol();
	cout << ". Pentru ca planta sa se poata dezvolta, este nevoie de o distanta de " << l5.getDistantaIntrePlante() << " cm, intre plante. ";
	cout << "In lume se estimeaza a fi undeva pe la " << l5.getNrTotalSpecii() << " de soiuri de plante." << endl << endl;

	Leguma l6;
	cin >> l6;
	l1 = l6;
	l6.afisareLeguma();

	Leguma l7;
	l7 = l6++;
	l7.afisareLeguma();
	l7 = ++l6;
	l7.afisareLeguma();

	if (l3 < l5)
	{
		cout << "Distanta dintre plante este mai mare in cazul plantei " << l5.getNume() << ".";
	}
	else
		cout << "Distanta dintre plante este mai mare in cazul plantei " << l3.getNume() << ".";

	cout << endl << endl;

	Pom p1;
	p1.afisarePom();

	Pom p2(2.3, 1);
	p2.afisarePom();

	int nrSoiuri;
	cout << "Introduceti numarul de soiuri: ";
	cin >> nrSoiuri;
	string* soiuri = new string[nrSoiuri];
	for (int i = 0; i < nrSoiuri; i++)
	{
		cout << "Soiul " << i + 1 << ": ";
		cin >> soiuri[i];
	}

	Pom p3("Par", 1.9, 1, nrSoiuri, soiuri);
	p3.afisarePom();
	ordonareSoiuri(p3);
	cout << "Obiectul p3, cu soiurile afisate in ordine alfabetica, arata astfel: " << endl;
	p3.afisarePom();

	Pom p4;
	p4.setNume("Cires");
	p4.setInaltimeMedie(1.7);
	int nrSoiuri4 = 3;
	p4.setNrSoiuri(nrSoiuri4);
	string* pomi4 = new string[nrSoiuri4];
	pomi4[0] = "Japonez";
	pomi4[1] = "Nanking";
	pomi4[2] = "Spectral";
	p4.setSoiuri(nrSoiuri4, pomi4);
	p4.setNrTotalSpecii(60100);

	cout << "Pomul " << p4.getNume() << " are, in medie, inaltimea de " << p4.getInaltimeMedie() << " metri.";
	if (p4.getAutopolenizator())
	{
		cout << " In aceasta specie putem intalni soiuri autopolenizatoare. ";
	}
	else
	{
		cout << " In aceasta specie nu putem intalni soiuri autopolenizatoare. ";
	}

	if (p4.getNrSoiuri() != 0)
	{
		cout << p4.getNrSoiuri() << " dintre cele mai intalnite soiuri ale acestei specii sunt: ";
		int i;
		for (i = 0; i < p4.getNrSoiuri() - 1; i++)
		{
			cout << p4.getSoiuri()[i] << ", ";
		}
		cout << p4.getSoiuri()[i] << "." << endl;
	}
	else
	{
		cout << endl;
	}
	cout << "In lume exista in total peste " << p4.getNrTotalSpecii() << " de soiuri de pomi." << endl << endl;


	p2 = p4;
	p2.afisarePom();

	p1 = p2 + p3;
	p1.afisarePom();

	if (p2 == p4)
	{
		cout << "Cei doi pomi sunt echivalenti.";
	}
	else
	{
		cout << "Cei doi pomi nu sunt echivalenti.";
	}

	cout << endl << endl;
	cout << p4[2] << endl;

}