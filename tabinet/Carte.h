#pragma once

#include <iostream>
#include <string>
#include <regex>

class Carte
{
private:
	std::string valoare;
	std::string simbol;
public:
	std::string getValoare() const;
	int getValoareNumerica(int caz);
	std::string getSimbol() const;
	void setValoare(std::string val);
	void setSimbol(std::string sim);
	void afisCarte();
	bool vacuta();
	void initializare();
};

