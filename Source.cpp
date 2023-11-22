//Domeniul: agronomie
#include <iostream>

using namespace std;

class Cereala
{
private:
	const int id;
	char* nume;
	string soi;
	int durataPerioadaVegetatie;
	bool consumUman;
	float temperatura;
	static float cantitateMaximaPesticide;

public:
	Cereala() : id(1)
	{
		this->nume = new char[strlen("Grau") + 1];
		strcpy_s(this->nume, strlen("Grau") + 1, "Grau");
		this->soi = "dur";
		this->durataPerioadaVegetatie = 0;
		this->consumUman = 1;
		this->temperatura = 0;
	}

	Cereala(char* nume, string soi, bool consumUman) : id(1)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->soi = soi;
		this->durataPerioadaVegetatie = 0;
		this->consumUman = consumUman;
		this->temperatura = 0;
	}

	Cereala(int idNou, char* nume, string soi, int durataPerioadaVegetatie, bool consumUman, float temperatura) : id(idNou)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->soi = soi;
		this->durataPerioadaVegetatie = durataPerioadaVegetatie;
		this->consumUman = consumUman;
		this->temperatura = temperatura;
	}

	Cereala(const Cereala& c) : id(c.id)
	{
		this->nume = new char[strlen(c.nume) + 1];
		strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
		this->soi = c.soi;
		this->durataPerioadaVegetatie = c.durataPerioadaVegetatie;
		this->consumUman = c.consumUman;
		this->temperatura = c.temperatura;
	}

	~Cereala()
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
	}

	const int getId() const
	{
		return this->id;
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

	bool getConsumUman()
	{
		return this->consumUman;
	}

	void setConsumUman(bool consumUman)
	{
		if (consumUman == 0)
		{
			this->consumUman = 0;
		}
		else
		{
			this -> consumUman = 1;
		}
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

	friend float temperaturaIncoltire(Cereala c);
	friend istream& operator>>(istream& in, Cereala& c);
	friend ostream& operator<<(ostream& out, const Cereala& c);
};
float Cereala::cantitateMaximaPesticide = 60;

float temperaturaIncoltire(Cereala c)
{
	return c.temperatura - 15;
}

istream& operator>>(istream& in, Cereala& c)
{
	cout << "Numele cerealei este: ";
	if (c.nume != NULL)
	{
		delete[]c.nume;
	}
	char aux[100];
	in >> aux;
	c.nume = new char[strlen(aux) + 1];
	strcpy_s(c.nume, strlen(aux) + 1, aux);
	cout << "Soiul: ";
	in >> c.soi;
	cout << "Durata perioadei de vegetatie este de (zile): ";
	in >> c.durataPerioadaVegetatie;
	cout << "Cereala este destinata consumului uman? (0 - NU, 1 - DA) ";
	in >> c.consumUman;
	cout << "Care este temperatura optima de coacere pentru acest tip de cereale? (grade Celsius) ";
	in >> c.temperatura;
	return in;
}

ostream& operator<<(ostream& out, const Cereala& c)
{
	out << c.id << ". " << "Cereala " << c.nume << " " << c.soi << " are perioada de vegetatie de " << c.durataPerioadaVegetatie << " zile. ";
	if (c.consumUman)
	{
		out << "Aceasta este destinata consumului uman. ";
	}
	else
	{
		out << "Aceasta este de tip furajer. ";
	}
	out << "Temperatura optima de coacere pentru acest tip de cereale este in jur de " << c.temperatura << " grade Celsius. ";
	out << "Cantitatea maxima de pesticide admisa in Romania este, in medie, de " << c.cantitateMaximaPesticide << " kg/ha." << endl << endl;
	return out;
}


class Leguma
{
private:
	const int id;
	char* nume;
	string categoriePlantaDurataVegetatie;
	bool rezistentaSeceta;
	float pHSol;
	int distantaIntrePlante;
	static int nrTotalSpecii;

public:
	Leguma() : id(1)
	{
		this->nume = new char[strlen("Rosie") + 1];
		strcpy_s(this->nume, strlen("Rosie") + 1, "Rosie");
		this->categoriePlantaDurataVegetatie = "anuala";
		this->rezistentaSeceta = 0;
		this->pHSol = 7;
		this->distantaIntrePlante = 0;
	}

	Leguma(bool rezistentaSeceta) : id(1)
	{
		this->nume = new char[strlen("Rosie") + 1];
		strcpy_s(this->nume, strlen("Rosie") + 1, "Rosie");
		this->categoriePlantaDurataVegetatie = "anuala";
		this->rezistentaSeceta = rezistentaSeceta;
		this->pHSol = 7;
		this->distantaIntrePlante = 0;
	}

	Leguma(int idNou, char* nume, string categoriePlantaDurataVegetatie, bool rezistentaSeceta, float pHSol, int distantaIntrePlante) : id(idNou)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->categoriePlantaDurataVegetatie = categoriePlantaDurataVegetatie;
		this->rezistentaSeceta = rezistentaSeceta;
		this->pHSol = pHSol;
		this->distantaIntrePlante = distantaIntrePlante;
	}

	Leguma(const Leguma& l) : id(l.id)
	{
		this->nume = new char[strlen(l.nume) + 1];
		strcpy_s(this->nume, strlen(l.nume) + 1, l.nume);
		this->categoriePlantaDurataVegetatie = l.categoriePlantaDurataVegetatie;
		this->rezistentaSeceta = l.rezistentaSeceta;
		this->pHSol = l.pHSol;
		this->distantaIntrePlante = l.distantaIntrePlante;
	}

	~Leguma()
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
	}

	const int getId() const
	{
		return this->id;
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
		if (rezistentaSeceta == 0)
		{
			this->rezistentaSeceta = 0;
		}
		else
		{
			this->rezistentaSeceta = 1;
		}
	}

	float getPHSol()
	{
		return this->pHSol;
	}

	void setPHSol(float pHSol)
	{
		if (pHSol > 0 && pHSol < 15)
		{
			this->pHSol = pHSol;
		}
		else
		{
			this->pHSol = 7;
		}
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
			this->pHSol = l.pHSol;
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

	friend istream& operator>>(istream& in, Leguma& l)
	{
		cout << "Numele legumei este: ";
		if (l.nume != NULL)
		{
			delete[]l.nume;
		}
		char aux[100];
		in >> aux;
		l.nume = new char[strlen(aux) + 1];
		strcpy_s(l.nume, strlen(aux) + 1, aux);
		cout << "In functie de durata de vegetatie, aceasta este (anuala/bienala/perena): ";
		in >> l.categoriePlantaDurataVegetatie;
		cout << "Este rezistenta la seceta? (0 - nu, 1 - da) ";
		in >> l.rezistentaSeceta;
		cout << "PH-ul solului trebuie sa fie: ";
		in >> l.pHSol;
		cout << "Pentru ca planta sa se poata dezvolta, este nevoie de o distanta de: ";
		in >> l.distantaIntrePlante;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Leguma& l);

};
int Leguma::nrTotalSpecii = 10000;

ostream& operator<<(ostream& out, const Leguma& l)
{
	out << l.id << ". " << "Leguma " << l.nume << " este o leguma " << l.categoriePlantaDurataVegetatie << ". " << (l.rezistentaSeceta
		? "Aceasta este rezistenta la seceta. " : "Aceasta nu este rezistenta la seceta. ");
	out << "PH-ul solului in care este cultivata planta trebuie sa fie " << l.pHSol;
	out << ". Pentru ca planta sa se poata dezvolta, este nevoie de o distanta de " << l.distantaIntrePlante << " cm, intre plante. ";
	out << "In lume se estimeaza a fi undeva pe la " << l.nrTotalSpecii << " de soiuri de plante." << endl << endl;
	return out;
}

class Pom
{
private:
	const int id;
	string nume;
	float inaltimeMedie;
	bool autopolenizator;
	int nrSoiuri;
	string* soiuri;
	static int nrTotalSpecii;

public:
	Pom() : id(1)
	{
		this->nume = "Mar";
		this->inaltimeMedie = 0;
		this->autopolenizator = 0;
		this->nrSoiuri = 0;
		this->soiuri = NULL;
	}

	Pom(float inaltimeMedie, bool autopolenizator) : id(1)
	{
		this->nume = "Mar";
		this->inaltimeMedie = inaltimeMedie;
		this->autopolenizator = 0;
		this->nrSoiuri = 0;
		this->soiuri = NULL;
	}

	Pom(int idNou, string nume, float inaltimeMedie, bool autopolenizator, int nrSoiuri, string* soiuri) : id(idNou)
	{
		this->nume = nume;
		this->inaltimeMedie = inaltimeMedie;
		this->autopolenizator = autopolenizator;
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

	Pom(const Pom& p) : id(p.id)
	{
		this->nume = p.nume;
		this->inaltimeMedie = p.inaltimeMedie;
		this->autopolenizator = p.autopolenizator;
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
		{
			delete[]this->soiuri;
		}
	}

	const int getId() const
	{
		return this->id;
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

	bool getAutopolenizator()
	{
		return this->autopolenizator;
	}

	void setAutopolenizator(bool autopolenizator)
	{
		if (autopolenizator == 0)
		{
			this->autopolenizator = 0;
		}
		else
		{
			this->autopolenizator = 1;
		}
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
	
	Pom operator+(string s)
	{
		Pom copie = *this;
		copie.nrSoiuri = this->nrSoiuri + 1;
		string* sirCopie = new string[copie.nrSoiuri];
		int i;
		for (i = 0; i < this->nrSoiuri; i++)
		{
			sirCopie[i] = this->soiuri[i];
		}
		sirCopie[i] = s;
		if (copie.soiuri != NULL)
		{
			delete[]copie.soiuri;
		}
		copie.soiuri = sirCopie;
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

	friend Pom operator+(int, const Pom& p);
	friend Pom operator+(string, const Pom& p);
	friend void ordonareSoiuri(Pom& p);
	friend istream& operator>>(istream& in, Pom& p);
	friend ostream& operator<<(ostream& out, const Pom& p);
};
int Pom::nrTotalSpecii = 60000;

Pom operator+(int a, const Pom& p)
{
	Pom copie = p;
	copie.inaltimeMedie = a + p.inaltimeMedie;
	return copie;
}

Pom operator+(string s, const Pom& p)
{
	Pom copie = p;
	copie.nrSoiuri = p.nrSoiuri + 1;
	string* sirCopie = new string[copie.nrSoiuri];
	int i;
	for (i = 0; i < p.nrSoiuri; i++)
	{
		sirCopie[i+1] = p.soiuri[i];
	}
	sirCopie[0] = s;
	if (copie.soiuri != NULL)
	{
		delete[]copie.soiuri;
	}
	copie.soiuri = sirCopie;
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

istream& operator>>(istream& in, Pom& p)
{
	cout << "Numele pomului este: ";
	in >> p.nume;
	cout << "Care este inaltimea medie? (cm) ";
	in >> p.inaltimeMedie;
	cout << "In aceasta specie exista vreun soi autopolenizator? (0 - NU, 1 - DA) ";
	in >> p.autopolenizator;
	cout << "Introduceti numarul de soiuri pe care vreti sa le cititi: ";
	in >> p.nrSoiuri;
	if (p.soiuri != NULL)
	{
		delete[]p.soiuri;
	}
	p.soiuri = new string[p.nrSoiuri];
	for (int i = 0; i < p.nrSoiuri; i++)
	{
		cout << "Soi" << (i + 1) << ": ";
		in >> p.soiuri[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const Pom& p)
{
	out << p.id << ". " << "Pomul " << p.nume << " are, in medie, inaltimea de " << p.inaltimeMedie << " metri.";
	if (p.autopolenizator)
	{
		out << " In aceasta specie putem intalni soiuri autopolenizatoare. ";
	}
	else
	{
		out << " In aceasta specie nu putem intalni soiuri autopolenizatoare. ";
	}

	if (p.nrSoiuri != 0)
	{
		out << p.nrSoiuri << " dintre cele mai intalnite soiuri ale acestei specii sunt: " << endl;
		int i;
		for (i = 0; i < p.nrSoiuri - 1; i++)
		{
			out << p.soiuri[i] << ", ";
		}
		out << p.soiuri[i] << "." << endl;
	}
	else
	{
		out << "Nu a fost introdus numarul de soiuri";
	}
	out << "In lume exista in total peste " << p.nrTotalSpecii << " de soiuri de pomi." << endl << endl;
	return out;
}

class Gradina
{
private:
	const int idGradina;
	string numeProprietar;
	float latimeGradina;
	float lungimeGradina;
	int nrLegumeGradina;
	Leguma* legume;
	static int nrTotalGradini;
	
public:
	Gradina() :idGradina(1)
	{
		this->numeProprietar = "Fara Proprietar";
		this->latimeGradina = 0;
		this->lungimeGradina = 0;
		this->nrLegumeGradina = 0;
		this->legume = NULL;
	}

	Gradina(int idGradinaNou, string numeProprietar, float latimeGradina, float lungimeGradina, int nrLegumeGradina, Leguma* legume) :idGradina(idGradinaNou)
	{
		if (numeProprietar.length() > 1)
		{
			this->numeProprietar = numeProprietar;
		}
		else
		{
			this->numeProprietar ="Fara proprietar";
		}
		if (latimeGradina > 0)
		{
			this->latimeGradina = latimeGradina;
		}
		else
		{
			this->latimeGradina = 0;
		}
		if (lungimeGradina > 0)
		{
			this->lungimeGradina = lungimeGradina;
		}
		else
		{
			this->lungimeGradina = 0;
		}
		if (nrLegumeGradina > 0)
		{
			this->nrLegumeGradina = nrLegumeGradina;
			this->legume = new Leguma[this->nrLegumeGradina];
			for (int i = 0; i < this->nrLegumeGradina; i++)
			{
				this->legume[i] = legume[i];
			}
		}
		else
		{
			this->nrLegumeGradina = 0;
			this->legume = NULL;
		}
	}

	Gradina(const Gradina& g) :idGradina(g.idGradina)
	{
		this->numeProprietar = g.numeProprietar;
		this->latimeGradina = g.latimeGradina;
		this->lungimeGradina = g.lungimeGradina;
		this->nrLegumeGradina = g.nrLegumeGradina;
		this->legume = new Leguma[this->nrLegumeGradina];
		for (int i = 0; i < this->nrLegumeGradina; i++)
		{
			this->legume[i] = g.legume[i];
		}
	}

	~Gradina()
	{
		if (this->legume != NULL)
		{
			delete[]this->legume;
		}
	}

	const int getIdGradina() const
	{
		return this->idGradina;
	}

	string getNumeProprietar() const
	{
		return this->numeProprietar;
	}

	void setNumeProprietar(string numeProprietar)
	{
		if (numeProprietar.length() > 1)
		{
			this->numeProprietar = numeProprietar;
		}
	}

	float getLatimeGradina() const
	{
		return this->latimeGradina;
	}

	void setLatimeGradina(float latimeGradina)
	{
		if (latimeGradina > 0)
		{
			this->latimeGradina = latimeGradina;
		}
	}

	float getLungimeGradina() const
	{
		return this->lungimeGradina;
	}

	void setLungimeGradina(float lungimeGradina)
	{
		if (lungimeGradina > 0)
		{
			this->lungimeGradina = lungimeGradina;
		}
	}

	int getNrLegumeGradina() const
	{
		return this->nrLegumeGradina;
	}

	Leguma* getLegume() const
	{
		return this->legume;
	}

	void setLegumeGradina(int nrLegumeGradina, Leguma* legume)
	{
		if (nrLegumeGradina > 0)
		{
			this->nrLegumeGradina = nrLegumeGradina;
			if (this->legume != NULL)
			{
				delete[]this->legume;
			}
			this->legume = new Leguma[this->nrLegumeGradina];
			for (int i = 0; i < nrLegumeGradina; i++)
			{
				this->legume[i] = legume[i];
			}
		}
	}

	static int getNrTotalGradini()
	{
		return Gradina::nrTotalGradini;
	}

	static void setNrTotalGradini(int nrTotalGradini)
	{
		if (nrTotalGradini > 0)
		{
			Gradina::nrTotalGradini = nrTotalGradini;
		}
	}

	Gradina& operator=(const Gradina& g)
	{
		if (this != &g)
		{
			this->numeProprietar = g.numeProprietar;
			this->latimeGradina = g.latimeGradina;
			this->lungimeGradina = g.lungimeGradina;
			this->nrLegumeGradina = g.nrLegumeGradina;
			if (this->legume != NULL)
			{
				delete[]this->legume;
			}

			if (this->nrLegumeGradina != 0)
			{
				this->legume = new Leguma[this->nrLegumeGradina];
				for (int i = 0; i < this->nrLegumeGradina; i++)
				{
					this->legume[i] = g.legume[i];
				}
			}
			else
			{
				this->legume = NULL;
			}
		}
	}
	
	friend istream& operator>>(istream& in, Gradina& g)
	{
		cout << "Numele proprietarului este: ";
		in >> g.numeProprietar;
		cout << "Latimea gradinii este: ";
		in >> g.latimeGradina;
		cout << "Lungimea gradinii este: ";
		in >> g.lungimeGradina;
		cout << "Numarul de tipuri de legume din gradina este: ";
		in >> g.nrLegumeGradina;
		if (g.legume != NULL)
		{
			delete[]g.legume;
		}
		if (g.nrLegumeGradina != 0)
		{
			Leguma* legume = new Leguma[g.nrLegumeGradina];
			for (int i = 0; i < g.nrLegumeGradina; i++)
			{
				cout << "Leguma " << i + 1 << ": ";
				cin >> g.legume[i];
			}
		}
		else
		{
			g.legume = NULL;
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, Gradina& g)
	{
		out << g.idGradina << ". Gradina apartine lui " << g.numeProprietar << ". Gradina are latimea de " << g.latimeGradina << " m si lungimea de "
			<< g.lungimeGradina << " m. ";
		if (g.nrLegumeGradina != 0)
		{
			out << "In gradina sunt " << g.nrLegumeGradina << " tipuri de legume. Acestea sunt: " << endl;
			for (int i = 0; i < g.nrLegumeGradina; i++)
			{
				out << g.legume[i];
			}
		}
		else
		{
			out << "In gradina sunt nu sunt legume. ";
		}
		out << "In total, in judetul Ilfov sunt " << Gradina::nrTotalGradini << " gradini.";
		out << endl << endl;
		return out;
	}
};
int Gradina::nrTotalGradini = 1000;

void main()
{
	// Constructor fara parametri
	Cereala c1;
	cout << c1;

	// Constructori cu parametri
	char* nume2;
	nume2 = new char[strlen("Porumb") + 1];
	strcpy_s(nume2, strlen("Porumb") + 1, "Porumb");
	Cereala c2(nume2, "dulce", 1);
	cout << c2;
	if (nume2 != NULL)
	{
		delete[]nume2;
	}
	
	char* nume3;
	nume3 = new char[strlen("Secara") + 1];
	strcpy_s(nume3, strlen("Secara") + 1, "Secara");
	Cereala c3(2, nume3, "comuna", 100, 1, 25);
	cout << c3;
	if (nume3 != NULL)
	{
		delete[]nume3;
	}

	// Constructor de copiere
	Cereala c4 = c3;
	cout << c4;

	// Apel functie globala de modificare a temperaturii
	cout << "In medie, o temperatura buna de incoltire este cu 15 grade mai mica decat temperatura optima pentru coacere. Stiind care este temperatura optima pentru coacere, temperatura de incoltire este: "
		<< temperaturaIncoltire(c4) << " grade Celsius." << endl << endl;

	// Apel set-eri
	char* cereala;
	cereala = new char[strlen("Orz") + 1];
	strcpy_s(cereala, strlen("Orz") + 1, "Orz");
	c2.setNume(cereala);
	c2.setSoi("Smarald");
	c2.setDurataPerioadaVegetatie(90);
	c2.setConsumUman(1);
	c2.setTemperatura(30);
	c2.setCantitateMaximaPesticide(50);

	// Apel get-eri
	cout << c2.getId() << ". " << "Cereala " << c2.getNume() << " " << c2.getSoi() << " are perioada de vegetatie de " << c2.getDurataPerioadaVegetatie() << " zile. ";
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

	// Operator =
	c4 = c2;
	cout << c4;

	// Operator +=
	c3 += c2;
	cout << c3;

	// Operator cast
	int durataPerioadaVegetatie = (int)c2;
	cout << "Durata perioadei de vegetatie pentru " << c2.getNume() << " este de: " << durataPerioadaVegetatie << " zile." << endl;
	float temperatura = c2;
	cout << "Temperatura optima pentru " << c2.getNume() << " este de: " << temperatura << " grade Celsius." << endl;

	cout << endl << endl;

	// Constructor fara parametri
	Leguma l1;
	cout << l1;

	// Constructori cu parametri
	Leguma l2(1);
	cout << l2;

	char* leguma;
	leguma = new char[strlen("Ceapa") + 1];
	strcpy_s(leguma, strlen("Ceapa") + 1, "Ceapa");
	Leguma l3(2, leguma, "bienala", 1, 6.5, 30);
	cout << l3;

	// Constructor de copiere
	Leguma l4 = l3;
	cout << l4;

	// Apel set-eri
	Leguma l5;
	char* leguma5;
	leguma5 = new char[strlen("Sparanghel") + 1];
	strcpy_s(leguma5, strlen("Sparanghel") + 1, "Sparanghel");
	l5.setNume(leguma5);
	l5.setCategoriePlantaDurataVegetatie("perena");
	l5.setRezistentaSeceta(1);
	l5.setPHSol(7.6);
	l5.setDistantaIntrePlante(40);
	l5.setNrTotalSpecii(10500);

	// Apel get-eri
	cout << l5.getId() << ". " << "Leguma " << l5.getNume() << " este o leguma " << l5.getCategoriePlantaDurataVegetatie() << ". " << (l5.getRezistentaSeceta()
		? "Aceasta este rezistenta la seceta. " : "Aceasta nu este rezistenta la seceta. ");
	cout << "PH-ul solului in care este cultivata planta trebuie sa fie " << l5.getPHSol();
	cout << ". Pentru ca planta sa se poata dezvolta, este nevoie de o distanta de " << l5.getDistantaIntrePlante() << " cm, intre plante. ";
	cout << "In lume se estimeaza a fi undeva pe la " << l5.getNrTotalSpecii() << " de soiuri de plante." << endl << endl;

	// Operator =
	Leguma l6;
	cin >> l6;
	l1 = l6;
	cout << l6;

	// Operator ++ - forma postfixata
	Leguma l7;
	l7 = l6++;
	cout << l7;

	// Operator ++ - forma prefixata
	l7 = ++l6;
	cout << l7;

	// Operator <
	if (l3 < l5)
	{
		cout << "Distanta dintre plante este mai mare in cazul plantei " << l5.getNume() << ".";
	}
	else
		cout << "Distanta dintre plante este mai mare in cazul plantei " << l3.getNume() << ".";

	cout << endl << endl;


	// Constructor fara parametri
	Pom p1;
	cout << p1;

	// Constructori cu parametri
	Pom p2(2.3, 1);
	cout << p2;

	int nrSoiuri;
	cout << "Introduceti numarul de soiuri: ";
	cin >> nrSoiuri;
	string* soiuri = new string[nrSoiuri];
	for (int i = 0; i < nrSoiuri; i++)
	{
		cout << "Soiul " << i + 1 << ": ";
		cin >> soiuri[i];
	}

	Pom p3(2, "Par", 1.9, 1, nrSoiuri, soiuri);
	cout << p3;

	// Apel functie globala de ordonare alfabetica a soiurilor
	ordonareSoiuri(p3);
	cout << "Obiectul p3, cu soiurile afisate in ordine alfabetica, arata astfel: " << endl;
	cout << p3;

	// Apel set-eri
	Pom p4;
	p4.setNume("Cires");
	p4.setInaltimeMedie(1.7);
	p4.setAutopolenizator(1);
	int nrSoiuri4 = 3;
	string* pomi4 = new string[nrSoiuri4];
	pomi4[0] = "Japonez";
	pomi4[1] = "Nanking";
	pomi4[2] = "Spectral";
	p4.setSoiuri(nrSoiuri4, pomi4);
	p4.setNrTotalSpecii(60100);

	// Apel get-eri
	cout << p4.getId() << ". " << "Pomul " << p4.getNume() << " are, in medie, inaltimea de " << p4.getInaltimeMedie() << " metri.";
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
		cout << "Nu a fost introdus numarul de soiuri";
	}
	cout << "In lume exista in total peste " << p4.getNrTotalSpecii() << " de soiuri de pomi." << endl << endl;

	// Operator =
	p2 = p4;
	cout << p2;

	// Operator + cu 2 obiecte
	cout << p1;
	p1 = p2 + p3;
	cout << p1;

	// Operator + cu o variabila de tip int
	cout << p2.getInaltimeMedie() << endl << p3.getInaltimeMedie() << endl;
	p2 = p3 + 4;
	cout << p2;
	
	// Operator + cu o variabila de tip string
	// metoda
	cout << p2;
	p2 = p3 + "soiNou1";
	cout << p2;

	// functie globala
	p2 = "soiNou2" + p2;
	cout << p2;

	// Operator ==
	if (p2 == p4)
	{
		cout << "Cei doi pomi sunt echivalenti." << endl << endl;
	}
	else
	{
		cout << "Cei doi pomi nu sunt echivalenti." << endl << endl;
	}
	
	// Operator []
	cout << p4[2];

	cout << endl << endl;


	// Vectorul cu obiecte de tipul Cereala
	int n1;
	cout << "Introduceti numarul de cereale: ";
	cin >> n1;
	Cereala* cVector = new Cereala[n1];
	for (int i = 0; i < n1; i++)
	{
		cout << "Cereala " << (i + 1) << endl;
		cin >> cVector[i];
	}
	cout << endl;
	for (int i = 0; i < n1; i++)
	{
		cout << "Cereala " << (i + 1) << ":" << endl;
		cout << cVector[i];
	}
	cout << endl;
	if (cVector != NULL)
	{
		delete[]cVector;
	}

	// Vectorul cu obiecte de tipul Leguma
	int n2;
	cout << "Introduceti numarul de legume: ";
	cin >> n2;
	Leguma* lVector = new Leguma[n2];
	for (int i = 0; i < n2; i++)
	{
		cout << "Leguma " << (i + 1) << endl;
		cin >> lVector[i];
	}
	cout << endl;
	for (int i = 0; i < n2; i++)
	{
		cout << "Leguma " << (i + 1) << ":" << endl;
		cout << lVector[i];
	}
	cout << endl;
	if (lVector != NULL)
	{
		delete[]lVector;
	}

	// Vectorul cu obiecte de tipul Pom
	int n3;
	cout << "Introduceti numarul de pomi: ";
	cin >> n3;
	Pom* pVector = new Pom[n3];
	for (int i = 0; i < n3; i++)
	{
		cout << "Pomul " << (i + 1) << endl;
		cin >> pVector[i];
	}
	cout << endl;
	for (int i = 0; i < n3; i++)
	{
		cout << "Pomul " << (i + 1) << ":" << endl;
		cout << pVector[i];
	}
	cout << endl;
	if (pVector != NULL)
	{
		delete[]pVector;
	}

	//Matrice cu obiecte de tipul clasei Cereala
	int linii, coloane;
	cout << "Introduceti numarul de linii: ";
	cin >> linii;
	cout << "Introduceti numarul de coloane: ";
	cin >> coloane;
	Cereala** cMatrice = new Cereala * [linii];
	for (int i = 0; i < linii; i++)
	{
		cMatrice[i] = new Cereala[coloane];
	}
	for (int i = 0; i < linii; i++)
	{
		for (int j = 0; j < coloane; j++)
		{
			cout << "Cereala" << i+1 << j+1 << " este: ";
			cin >> cMatrice[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < linii; i++)
	{
		for (int j = 0; j < coloane; j++)
		{
			cout << "Obiectul " << (i + 1) << (j + 1) << ":" << endl;
			cout << cMatrice[i][j];
		}
	}
	for (int i = 0; i < linii; i++)
	{
		if (cMatrice[i] != NULL)
		{
			delete[]cMatrice[i];
		}
	}
	if (cMatrice != NULL)
	{
		delete[]cMatrice;
	}

	// Constructor fara parametri
	Gradina g1;
	cout << g1;

	// Constructor cu parametri
	char* gNumeLeguma1 = new char[strlen("Ardei") + 1];;
	strcpy_s(gNumeLeguma1, strlen("Ardei") + 1, "Ardei");
	Leguma gLeguma1(100, gNumeLeguma1, "anuala", 0, 6.5, 20);
	//legume[0] = gLeguma1;
	char* gNumeLeguma2 = new char[strlen("Vanata") + 1];
	strcpy_s(gNumeLeguma2, strlen("Vanata") + 1, "Vanata");
	Leguma gLeguma2(101, gNumeLeguma2, "anuala", 1, 6.9, 35);
	//legume[1] = gLeguma2;
	Leguma* legume2 = new Leguma[2]{ gLeguma1, gLeguma2 };
	Gradina g2(2, "Ion Popescu", 5, 7, 2, legume2);
	cout << g2;
	if (gNumeLeguma1 != NULL)
	{
		delete[]gNumeLeguma1;
	}
	if (gNumeLeguma2 != NULL)
	{
		delete[]gNumeLeguma2;
	}
	if (legume2 != NULL)
	{
		delete[]legume2;
	}
	
	// Apel set-eri
	Gradina g3;
	g3.setNumeProprietar("Ionescu Marinela");
	g3.setLatimeGradina(25);
	g3.setLungimeGradina(35);
	int nrLegumeGradina = 1;
	Leguma* legume3 = new Leguma[nrLegumeGradina];
	for (int i = 0; i < nrLegumeGradina; i++)
	{
		cin >> legume3[i];
	}
	g3.setLegumeGradina(nrLegumeGradina, legume3);
	g3.setNrTotalGradini(1107);
	cout << endl;

	// Apel get-eri
	cout << g3.getIdGradina() << ". Gradina apartine lui " << g3.getNumeProprietar() << ". Gradina are latimea de " << g3.getLatimeGradina() << " m si lungimea de "
		<< g3.getLungimeGradina() << " m. ";
	if (g3.getNrLegumeGradina() != 0)
	{
		cout << "In gradina sunt " << g3.getNrLegumeGradina() << " tipuri de legume. Acestea sunt: " << endl;
		for (int i = 0; i < g3.getNrLegumeGradina(); i++)
		{
			cout << g3.getLegume()[i];
		}
	}
	else
	{
		cout << "In gradina sunt nu sunt legume. ";
	}
	cout << "In total, in judetul Ilfov sunt " << Gradina::getNrTotalGradini() << " gradini.";
	cout << endl;

	Gradina g4;
	cin >> g4;
	cout << g4;

	/*g2 = g4;
	cout << g2;*/
}