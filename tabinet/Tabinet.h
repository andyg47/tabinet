#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Carte.h"
#include "Jucator.h"

class Tabinet
{
private:
		int numarJucatori;
		std::vector<Carte> pachet;
		std::vector<Carte> masa;
		std::vector<Jucator> jucatori;
		int ultimul;
public:
	Tabinet(int nr);
	void run();
	void setPachet();
	void amesteca();
	void primaMana(Jucator& j);
	void primesteCarti(Jucator& j);
	void afisMasa();
	void randJucator(Jucator& j, int index);
	int suma(Carte c, std::vector<Carte> m);
	void calculPunctaj(Jucator& j);
	bool maximCarti(Jucator j);
	
	

};

