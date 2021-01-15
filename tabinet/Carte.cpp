#include "Carte.h"



std::string Carte::getValoare() const
{
	return valoare;
}

int Carte::getValoareNumerica(int caz) 
{
	if (caz == 1)
	{
		if (getValoare() == "A")
			return 1;
	}
	else if (caz == 2)
	{
		if (getValoare() == "A")
			return 11;
	}
	if (getValoare() == "2")
		return 2;
	if (getValoare() == "3")
		return 3;
	if (getValoare() == "4")
		return 4;
	if (getValoare() == "5")
		return 5;
	if (getValoare() == "6")
		return 6;
	if (getValoare() == "7")
		return 7;
	if (getValoare() == "8")
		return 8;
	if (getValoare() == "9")
		return 9;
	if (getValoare() == "10")
		return 10;
	if (getValoare() == "J")
		return 12;
	if (getValoare() == "Q")
		return 13;
	if (getValoare() == "K")
		return 14;
}

std::string Carte::getSimbol() const
{
	return simbol;
}

void Carte::setValoare(std::string val)
{
	valoare = val;
}

void Carte::setSimbol(std::string sim)
{
	simbol = sim;
}

void Carte::afisCarte()
{
	std::cout << valoare << "-" << simbol << " ";
}

bool Carte::vacuta()
{
	std::regex a("(diamond)");
	std::regex b("(club)");
	if ((regex_match(simbol, a) && valoare=="10") || ((regex_match(simbol, b) && valoare=="2")))
		return true;
	else return false;
}

void Carte::initializare()
{
	simbol = "";
	valoare = "";
}