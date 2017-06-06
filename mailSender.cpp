#include <iostream>
#include <algorithm>
#include <list>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int DUMMY_INT = -1;
const bool DUMMY_BOOL = false;
const string DUMMY_STRING = "";


class NAZOVPC {
	string name;
public:
	string spravnyTvar(string name);
	void vlozNazovPocitaca(string name);
	bool kontrola(string name);
	const string &getMenoPC() const { return name; };
};

class MACADRRESSA {
	string adresa;
public:
	void vlozMacAdressu(string adresa);
	bool kontrolaMac(string adrr);
	const string &getAdress() const { return adresa; };
	string spravnyTvar(string vstup);
};

class INFORMACIE {
	string informacia;
public:
	void vlozInformacie(string info);
	const string &geInfo() const { return informacia; };
	string upravInfo(string info);
};

class POCITAC {
	string meno;
	string macAdressa;
	string Informacia;
public:
	void setName(const string &name) { this->meno = name; };
	void setMac(const string &mac) { this->macAdressa = mac; };
	void setInfo(const string &info) { this->Informacia = info; };
	const string &getNamePC() const { return meno; };
	const string &getMacAdress() const { return macAdressa; };
	const string &getInformacia() const { return Informacia; };
};

class VYPIS {
	string nazovSuboru;
public:
	void vypisDoSuboru(string nazovSuboru);
	string vypisNaKonzolu();
};

class PONUKA {
	string vstup;
public:
	void testik();
	void vyberVolby();
	void vlozVstup();
	void vypisData();
	void ulozDoSuboru(string nazovSuboru);
};

vector<POCITAC> d;

// CLASS NAZOV PC METODY A FUNKCIE
bool NAZOVPC::kontrola(string name) {
	if (name.size() < 20) {
		if ((name[0] != 's') && (name[0] != 'S')) {
			return false;
		}
		if ((name[1] != 'k') && (name[1] != 'K')) {
			return false;
		}
		return true;
	}
	else {
		return false;
	}
}
string NAZOVPC::spravnyTvar(string name) {
	string pom;
	string res;
	int poc = 0;
	for (int i = 0; i < name.size(); i++) {
		if (name[i] != ' ') {
			char buff = name[i];
			if (buff > 64 && buff < 91) {
				pom += buff;
			}
			if (buff > 96 && buff < 123) {
				pom += buff - 32;
			}
			if (buff > 47 && buff < 58) {
				if (poc == 0) {
					poc += 1;
					pom += ' ';
				}
				poc += 1;
				if (poc == 5) {
					poc = 1;
					pom += ' ';
				}
				pom += buff;
			}

		}
	}
	res = pom;
	return res;
}
void NAZOVPC::vlozNazovPocitaca(string name) {
	if (kontrola(name) == true) {
		this->name = spravnyTvar(name);
	}
}

// CLASS MACADRRESSA METODY A FUNKCIE

string MACADRRESSA::spravnyTvar(string vstup) {
	string res;
	for (unsigned int i = 0; i < vstup.size(); i++) {
		char buff = vstup[i];
		if (buff > 47 && buff < 58) {
			res += buff;
		}
		if (buff > 64 && buff < 71) {
			buff = buff + 32;
			res += buff;
		}
	}
	return res; 
}

bool MACADRRESSA::kontrolaMac(string adrr) {
	int pom = 0;
	for (unsigned int i = 0; i < adrr.size(); i++) {
		if (adrr[i] == ' ') {
			pom += 1;
		}
	}
	if (pom > 0) {
		return false;
	}
	if (adrr.size() == 0) {
		return false;
	}		
	return true;
}
void MACADRRESSA::vlozMacAdressu(string adresa) {
	if (kontrolaMac(adresa) == true) {
		this->adresa = spravnyTvar(adresa);
	}
	else {
		cout << "zle zadana mac adresa!!!" << endl;
	}
}

// CLASS INFORMACIE METODY A FUNKCIE

string INFORMACIE::upravInfo(string info) {
	string res = "";
	string p = "";
	int pocetMedzier = 0;
	int riadok = 0;
	int pomocna;
	int pomocna2;
	int a = info.size();
	for (unsigned int i = 0; i < info.size(); i++) {
		if (info[i] == ' ') {
			pocetMedzier += 1;
		}
		p += info[i];
		if (pocetMedzier == 3) {
			if (riadok != 0) {
				res += "||                  ||                    ||";
			}
			if (p.size() < 21) {
				pomocna = (21 - p.size()) / 2 + 1;
				pomocna2 = 21 - p.size() - p.size() % 2 - pomocna - 1;
				if (pomocna > 0) {
					for (unsigned int j = 0; j < pomocna; j++) {
						p = ' ' + p;
					}
				}
				if (pomocna2 > 0) {
					for (unsigned int j = 0; j < pomocna2; j++) {
						p += '  ';
					}
				}
			}
			res += p;
			res += "||\n";
			res += "||------------------||--------------------||---------------------||\n";
			p = "";
			pocetMedzier = 0;
			riadok++;
		}
	}
	if (pocetMedzier != 3) {
		if (riadok != 0) {
			res += "||                  ||                    ||";
		}
		pomocna = (21 - p.size()) / 2;
		pomocna2 = 21 - p.size() - p.size() % 2 - pomocna;
		if (pomocna > 0) {
			for (unsigned int j = 0; j < pomocna; j++) {
				p = ' ' + p;
			}
		}
		if (pomocna2 > 0) {
			for (unsigned int j = 0; j < pomocna2; j++) {
				p += ' ';
			}
		}
		res += p;
		res += "||\n";
		res += "||------------------||--------------------||---------------------||\n";
		p = "";
	}

	return res;
}

void INFORMACIE::vlozInformacie(string info) {
	this->informacia = upravInfo(info);
}

// CLASS VYPIS METODY A FUNKCIE
string VYPIS::vypisNaKonzolu() {
	char pom[100000];
	int pocetMedzier = 0;
	string res;
	res += "++===============================================================++\n";
	res += "||RUNNING OS INSTALL:                                            ||\n";
	res += "++==================++====================++=====================++\n";
	res += "||      PC NAME     ||     MAC ADRESSA    ||      STATUS INFO    ||\n";
	res += "++------------------++--------------------++---------------------++\n";
	for (unsigned int i = 0; i < d.size(); i++) {
		sprintf(pom, "||    %s    ||    %s    || %s", d.at(i).getNamePC().c_str(), d.at(i).getMacAdress().c_str(), d.at(i).getInformacia().c_str());
		res += string(pom);
	}
	res += "++===============================================================++\n";
	return res;
}
void VYPIS::vypisDoSuboru(string nazovSuboru) {
	ofstream vystup;
	vystup.open(nazovSuboru);
	vystup << vypisNaKonzolu() << endl;
	vystup.close();
	PONUKA v;
	v.testik();
	v.vyberVolby();
}


//PONUKA
void PONUKA::testik(){
	system("cls");
}

void PONUKA::vlozVstup() {
	string vstup;
	NAZOVPC n;
	MACADRRESSA m;
	INFORMACIE i;
	POCITAC p;

	cout << "Zadaj Meno PC: " << endl;
	getline(cin, vstup);
	n.vlozNazovPocitaca(vstup);
	p.setName(n.getMenoPC());
	testik();
	
	cout << "Zadaj Mac Adressu: " << endl;
	getline(cin, vstup);
	m.vlozMacAdressu(vstup);
	p.setMac(m.getAdress());
	testik();

	cout << "Zadaj Info: " << endl;
	getline(cin, vstup);
	i.vlozInformacie(vstup);
	p.setInfo(i.geInfo());
	d.push_back(p);
	testik();
	vyberVolby();
}

void PONUKA::vypisData() {
	VYPIS res;
	cout << res.vypisNaKonzolu() << endl;
	getchar();
	testik();
	vyberVolby();
}

void PONUKA::ulozDoSuboru(string nazovSuboru) {
	VYPIS res;
	res.vypisDoSuboru(nazovSuboru);
}

void PONUKA::vyberVolby() {
	string vstup;
	cout << "+********************** MENU ******************+" << endl;
	cout << "|==============================================|" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|                  ADD PC >>>  1  <<<          |" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|         PRINT ON SCREEN >>>  2  <<<          |" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|        SAVE INTO A FILE >>>  3  <<<          |" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "+==============================================+" << endl;
	cout << "Please insert your option >>> ";
	getline(cin, vstup);
	testik();
	if (vstup.size() == 1) {
		if ('1' == vstup[0]) {
			vlozVstup();
			testik();
			getchar();
			testik();
		}
		if ('2' == vstup[0]) {
			vypisData();
			testik();
			getchar();
			testik();
		}
		if ('3' == vstup[0]) {
			system("cls");
			cout << "Enter file name: " << endl;
			getline(cin, vstup);
			vstup += ".txt";
			ulozDoSuboru(vstup);
			testik();
			getchar();
			testik();
		}
	}
}

void main(){
	PONUKA m;
	m.vyberVolby();
}
