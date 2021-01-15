#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Carte.h"

class Jucator
{
private:
	std::vector<Carte> mana;
	std::vector<Carte> colectat;
	int tabla;
	int punctaj;
public:
	std::vector<Carte> getMana()  const;
	std::vector<Carte> getColectat()  const;
	int getTabla() const;
	int getPunctaj() const;
	int getNumarColectat() const;
	void setPunctaj(int puncte);
	void afisMana();
	void primesteCarte(Carte c);
	void adaugaTabla();
	void anuleazaTabla();
	void actualizareMana(std::vector<Carte> m);
	void colecteaza(Carte c);
	

};

