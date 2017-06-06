
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
	/*bool kontrolaInfo(string kontrola);*/
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
	/*void testik();*/
	void vyberVolby();
	void vlozVstup();
	void vypisData();
	void ulozDoSuboru(string nazovSuboru);
};
