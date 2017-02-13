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
	/*bool kontrolaInfo(string kontrola);*/
	const string &geInfo() const { return informacia; };
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
	void vypisNaKonzolu();
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
		if ((name[2] != ' ') && (name[2] != 'T')) {
			return false;
		}
		return true;
	}
	else {
		return false;
	}
}

void NAZOVPC::vlozNazovPocitaca(string name) {
	if (kontrola(name) == true) {
		this->name = name;
	}
	else {
		cout << "Zle zadany vstup." << endl;
		getchar();
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
	if (adrr.size() == 0) {
		return false;
	}
	if (0 < adrr.size() < 13) {
		return true;
	}
	else {

	}
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
void INFORMACIE::vlozInformacie(string info) {
	this->informacia = info;
}

// CLASS VYPIS METODY A FUNKCIE

void VYPIS::vypisDoSuboru(string nazovSuboru) {
	ofstream vystup;
	vystup.open(nazovSuboru);
	vystup << "++===============================================================++" << endl;
	vystup << (char)124 << (char)124 << "RUNNING OS INSTALL:                                            " << (char)124 << (char)124 << endl;
	vystup << (char)124 << (char)124 << "==================++====================++=====================" << (char)124 << (char)124 << endl;
	vystup << (char)124 << (char)124 << "      PC NAME     " << (char)124 << (char)124 << "     MAC ADRESSA    " << (char)124 << (char)124 << "      STATUS INFO    " << (char)124 << (char)124 << endl;
	vystup << (char)124 << (char)124 << "------------------" << (char)124 << (char)124 << "--------------------" << (char)124 << (char)124 << "---------------------" << (char)124 << (char)124 << endl;
	for (unsigned int i = 0; i < d.size(); i++) {
		if (d.at(i).getInformacia().size() == 15) {
			vystup << (char)124 << (char)124 << "    " << d.at(i).getNamePC() << "    " << (char)124 << (char)124 << "    " << d.at(i).getMacAdress() << "    " << (char)124 << (char)124 << "   " << d.at(i).getInformacia() << "   " << (char)124 << (char)124 << endl;
		}
		else {
			vystup << (char)124 << (char)124 << "    " << d.at(i).getNamePC() << "    " << (char)124 << (char)124 << "    " << d.at(i).getMacAdress() << "    " << (char)124 << (char)124 << "   " << d.at(i).getInformacia() << "            " << (char)124 << (char)124 << endl;
		}
		vystup << (char)124 << (char)124 << "------------------" << (char)124 << (char)124 << "--------------------" << (char)124 << (char)124 << "---------------------" << (char)124 << (char)124 << endl;
	}
	vystup << "++==================++====================++=====================++" << endl;
	system("cls");
	PONUKA v;
	v.vyberVolby();
}

void VYPIS::vypisNaKonzolu() {
	cout << "++===============================================================++" << endl;
	cout << (char)124 << (char)124 << "RUNNING OS INSTALL:                                            " << (char)124 << (char)124 << endl;
	cout << (char)124 << (char)124 << "==================++====================++=====================" << (char)124 << (char)124 << endl;
	cout << (char)124 << (char)124 << "      PC NAME     " << (char)124 << (char)124 << "     MAC ADRESSA    " << (char)124 << (char)124 << "      STATUS INFO    " << (char)124 << (char)124 << endl;
	cout << (char)124 << (char)124 << "------------------" << (char)124 << (char)124 << "--------------------" << (char)124 << (char)124 << "---------------------" << (char)124 << (char)124 << endl;
	for (unsigned int i = 0; i < d.size(); i++) {
		if (d.at(i).getInformacia().size() == 15) {
			cout << (char)124 << (char)124 << "    " << d.at(i).getNamePC() << "    " << (char)124 << (char)124 << "    " << d.at(i).getMacAdress() << "    " << (char)124 << (char)124 << "   " << d.at(i).getInformacia() << "   " << (char)124 << (char)124 << endl;
		}
		else {
			cout << (char)124 << (char)124 << "    " << d.at(i).getNamePC() << "    " << (char)124 << (char)124 << "    " << d.at(i).getMacAdress() << "    " << (char)124 << (char)124 << "   " << d.at(i).getInformacia() << "            " << (char)124 << (char)124 << endl;
		}

		cout << (char)124 << (char)124 << "------------------" << (char)124 << (char)124 << "--------------------" << (char)124 << (char)124 << "---------------------" << (char)124 << (char)124 << endl;
	}
	cout << "++==================++====================++=====================++" << endl;
	cout << "PRESS SOMETHING" << endl;
	getchar();
	system("cls");
	PONUKA v;
	v.vyberVolby();
}

//PONUKA
void PONUKA::testik() {
	system("cls");
	/*cout << "This is the entry: " << vstup << " This is his size: " << vstup.size() << endl;
	cout << "Press ENTER to CONTINUE" << endl;
	getchar();*/
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
	res.vypisNaKonzolu();
	getchar();
}

void PONUKA::ulozDoSuboru(string nazovSuboru) {
	VYPIS res;
	res.vypisDoSuboru(nazovSuboru);
}

void PONUKA::vyberVolby() {
	string vstup;
	cout << "+********************* PONUKA *****************+" << endl;
	cout << "|==============================================|" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|               PRIDAJ PC >>>  1  <<<          |" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|         PRINT ON SCREEN >>>  2  <<<          |" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|        SAVE INTO A FILE >>>  3  <<<          |" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "|               RUN TESTS >>>  4  <<<          |" << endl;
	cout << "|----------------------------------------------|" << endl;
	cout << "+==============================================+" << endl;
	cout << "Zadaj volbu:" << endl;
	getline(cin, vstup);
	testik();
	if (vstup.size() == 1) {
		if ('1' == vstup[0]) {
			vlozVstup();
		}
		if ('2' == vstup[0]) {
			vypisData();
		}
		if ('3' == vstup[0]) {
			system("cls");
			cout << "Enter file name: " << endl;
			getline(cin, vstup);
			vstup += ".txt";
			ulozDoSuboru(vstup);
			testik();
		}
		if (vstup[0] == '4') {
			/*testyNazovPC();
			testyMacAdresa();
			testyInformacie();*/
			cout << "Ta co ši še ošaľel" << endl;
		}
	}
}