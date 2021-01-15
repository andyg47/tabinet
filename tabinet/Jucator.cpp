#include "Jucator.h"

std::vector<Carte> Jucator::getMana() const
{
	return mana;
}

std::vector<Carte> Jucator::getColectat() const
{
	return colectat;
}

void Jucator::afisMana()
{
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "Aveti in mana: " << std::endl;
	for (int index = 0; index < mana.size(); index++)
	{
		mana[index].afisCarte();
	}
	std::cout << std::endl;
	for (int index = 0; index < mana.size(); index++)
	{
		std::cout << "    " << index << "\t ";
	}

	std::cout << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
}

void Jucator::primesteCarte(Carte c)
{
	mana.push_back(c);
}

void Jucator::adaugaTabla()
{
	tabla++;
}

void Jucator::anuleazaTabla()
{
	tabla--;
}

void Jucator::actualizareMana(std::vector<Carte> m)
{
	mana = m;
}

void Jucator::colecteaza(Carte c)
{
	colectat.push_back(c);
}

int Jucator::getTabla() const
{
	return tabla;
}

void Jucator::setPunctaj(int puncte)
{
	punctaj = puncte;
}

int Jucator::getNumarColectat() const
{
	return colectat.size();
}

int Jucator::getPunctaj() const
{
	return punctaj;
}