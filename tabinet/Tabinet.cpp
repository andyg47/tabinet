#include "Tabinet.h"
#include <sstream>
#include <cstring>
#include <algorithm>
#include <ctime> 

Tabinet::Tabinet(int nr)
{
	numarJucatori = nr;
    for (int index = 0; index < nr; index++)
    {
        Jucator j;
        jucatori.push_back(j);
    }
        
    setPachet();
}

void Tabinet::setPachet()
{
    for (int index = 0; index < 52; index++)
    {
        Carte c;
        pachet.push_back(c);
    }
    std::string str;
    std::string val;
    for (int index = 0; index <13; index++)
    {
        
        pachet[index].setSimbol("heart");

        if (index == 0)
            pachet[index].setValoare("A");
        else if (index == 9)
            pachet[index].setValoare("10");
        else if (index == 10)
            pachet[index].setValoare("J");
        else if (index == 11)
            pachet[index].setValoare("Q");
        else if (index == 12)
            pachet[index].setValoare("K");
        else {
            str = std::to_string(index+1);
            pachet[index].setValoare(str);
        }
    }

    for (int index = 0; index <13; index++)
    {

        pachet[index + 13].setSimbol("spade");
        if (index == 0)
            pachet[index + 13].setValoare("A");
        else if (index == 9)
            pachet[index + 13].setValoare("10");
        else if (index == 10)
            pachet[index + 13].setValoare("J");
        else if (index == 11)
            pachet[index + 13].setValoare("Q");
        else if (index == 12)
            pachet[index + 13].setValoare("K");
        else
        {
            str = std::to_string(index+1);
            pachet[index+13].setValoare(str);
        }
    }
    
    for (int index = 0; index <13; index++)
    {

        pachet[index + 26].setSimbol("club");
        if (index == 0)
            pachet[index+26].setValoare("A");
        else if (index == 9)
            pachet[index + 26].setValoare("10");
        else if (index == 10)
            pachet[index + 26].setValoare("J");
        else if (index == 11)
            pachet[index + 26].setValoare("Q");
        else if (index == 12)
            pachet[index + 26].setValoare("K");
        else
        {
            str = std::to_string(index+1);
            pachet[index + 26].setValoare(str);
        }
    }
    
    for (int index = 0; index <13; index++)
    {

        pachet[index+39].setSimbol("diamond");
        if (index == 0)
            pachet[index+39].setValoare("A");
        else if (index == 9)
            pachet[index + 39].setValoare("10");
        else if (index == 10)
            pachet[index +39].setValoare("J");
        else if (index == 11)
            pachet[index + 39].setValoare("Q");
        else if (index == 12)
            pachet[index + 39].setValoare("K");
        else
        {
            str = std::to_string(index+1);
            pachet[index + 39].setValoare(str);
        }
    }
}

void Tabinet::amesteca()
{
    
        for (int index = 0; index < pachet.size(); index++)
        {
            int swap = rand() % pachet.size();
            Carte temp = pachet[index];
            pachet[index] = pachet[swap];
            pachet[swap] = temp;
        }

        
}

int random(int i)
{ return std::rand() % i; 
}


void Tabinet::primaMana(Jucator& j)
{
    int optiune = 0;
    std::cout << "<<<<<<<<<<<<<<<<<<<< PLAYER 0 >>>>>>>>>>>>>>>>>>>>" << std::endl;
    std::cout << "You received these cards:" << std::endl;
    for (int index = 0; index < 4; index++)
    {
        pachet[index].afisCarte();
    }
    std::cout << std::endl << "Do you wish to keep them?" << std::endl;
    std::cout << "1 - Yes \t 2 - No" << std::endl;
    std::cin >> optiune;
    while (optiune != 1 && optiune != 2)
    {
        std::cout << "Wrong input, type 1 or 2." << std::endl;
        std::cin >> optiune;
    }
    if (optiune == 1)
    {
        for (int index = 0; index < 6; index++)
        {
            Carte c = Tabinet::pachet[0];
            j.primesteCarte(c);
            pachet.erase(pachet.begin());
        }
    }
    else {
        for (int index = 0; index < 4; index++)
        {
            Carte c = Tabinet::pachet[0];
            masa.push_back(c);
            pachet.erase(pachet.begin());
        }

        for (int index = 0; index < 6; index++)
        {
            Carte c = Tabinet::pachet[0];
            j.primesteCarte(c);
            pachet.erase(pachet.begin());
        }
    }
}

void Tabinet::primesteCarti(Jucator& j)
{
    for (int index = 0; index < 6; index++)
    {
        Carte c = Tabinet::pachet[0];
        j.primesteCarte(c);
        pachet.erase(pachet.begin());
        
    }
}


void Tabinet::afisMasa()
{
    std::cout << "-------------------- The Board --------------------" << std::endl;
    /*for (int index = 0; index < masa.size(); index++)
    {
        masa[index].afisCarte();
    }*/
    for (auto carte : masa)
    {
        carte.afisCarte();
    }
    std::cout << std::endl;
    for (int index = 0; index < masa.size(); index++)
    {
        std::cout << "    " << index << "\t ";
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
}

int Tabinet::suma(Carte c, std::vector<Carte> vec)
{
   
    int suma;
    int rezultat;

    if (vec.size() == 1)
    {
        if (c.getValoareNumerica(2) == vec[0].getValoareNumerica(2))
            return 1;
    }

    suma = 0;
    rezultat = 0;
    for (int index = 0; index < vec.size(); index++)                                    //caz 1 + caz 2
    {
        suma = suma + vec[index].getValoareNumerica(1);
    }
    rezultat = c.getValoareNumerica(2);
    if (suma == rezultat)
        return 1;


    suma = 0;
    rezultat = 0;
    for (int index = 0; index <vec.size(); index++)                                    //caz 2 + caz 2
    {
        suma = suma + vec[index].getValoareNumerica(2);
    }
    rezultat = c.getValoareNumerica(2);
    if (suma == rezultat)
        return 1;
    
    
    return 0;

}

void Tabinet::randJucator(Jucator& j, int indexj)
{
    if (j.getMana().empty())
        return;
    int optiune = 0;
    int numar = 0;
    int aux = 0;
    bool oktabla = false;
    int okrand = 0;
    std::vector<Carte> mana = j.getMana();
    Carte c;
    std::vector<Carte> deLuat;
    std::cout << "<<<<<<<<<<<<<<<<<<<< PLAYER " << indexj << ">>>>>>>>>>>>>>>>>>>>" << std::endl;
    afisMasa();
    j.afisMana();
    std::cout << "You have colected " << j.getNumarColectat() << " cards" << " and " << j.getTabla() << " tabla" << std::endl;
    
    std::cout << " 1 - Take one or more cards" << std::endl;
    std::cout << " 2 - Drop a card" << std::endl;
    std::cin >> optiune;
    while (optiune != 1 && optiune != 2)
    {
        std::cout << "Wrong input, type 1 or 2." << std::endl;
        std::cin >> optiune;
    }

    if (optiune == 1)
    {
        while (okrand == 0)
        {
            oktabla = false;
            int indexc = -1;
            c.initializare();
            deLuat.clear();
            std::cout << "Pick a card to collect cards from the board (index)" << std::endl;
            std::cin >> indexc;
           
                while (indexc > 5 || indexc < 0)
                {
                 std::cout << "Wrong index." << std::endl;
                 std::cin >> indexc;
                }
                c = mana[indexc];
                std::cout << "Type how many cards you want to collect, then, type their indexes one by one. For tabla type 0." << std::endl;
                std::cin >> numar;
        
            if (numar < 1 && numar > 8)
            {
                std::cout << "Wrong input." << std::endl;
                std::cin >> numar;
            }

            if (numar > 0)
            {
                if (numar == 1)
                {
                    std::cin >> aux;
                    deLuat.push_back(masa[aux]);
                }
                else {
                    for (int index = 0; index < numar; index++)
                    {
                        std::cin >> aux;
                        deLuat.push_back(masa[aux]);
                    }
                }
            }
            else {
                oktabla = true;
            }

            if (oktabla == true)
            {
                for (int index = 0; index < masa.size(); index++)
                {
                    deLuat.push_back(masa[index]);
                }
                okrand = suma(c, deLuat);
            }
            else {
                okrand = suma(c, deLuat);
            }

            if (okrand==1)
            {
                ultimul = indexj;
                if (oktabla)
                {
                    j.adaugaTabla();
                }
                j.colecteaza(mana[indexc]);
                mana.erase(mana.begin()+indexc);
                if (deLuat.size() == 1)
                {
                    for (int index2 = 0; index2 < masa.size(); index2++)
                        if (deLuat[0].getValoare() == masa[index2].getValoare() && deLuat[0].getSimbol() == masa[index2].getSimbol())
                        {
                            j.colecteaza(deLuat[0]);
                            masa.erase(masa.begin() + index2);
                            deLuat.erase(deLuat.begin());
                            break;
                        }
                }
                else {
                    bool okluat = true;
                    while (!deLuat.empty())
                    {
                        for (int index2 = 0; index2 < masa.size(); index2++)
                            if (okluat == true)
                            {
                                if (deLuat[0].getValoare() == masa[index2].getValoare() && deLuat[0].getSimbol() == masa[index2].getSimbol())
                                {
                                    j.colecteaza(deLuat[0]);
                                    masa.erase(masa.begin() + index2);
                                    deLuat.erase(deLuat.begin());
                                    if (deLuat.empty())
                                        okluat = false;
                                }
                            }
                    }
                }

            }
        }
        std::cout << "Succesfuly played your hand" << std::endl;
    }
    else {
        int indexc2 = -1;
        std::cout << "Choose the index of the card you want to drop: " << std::endl;
        std::cin >> indexc2;
        while (mana.size() < indexc2 || indexc2 < 0)
        {
            std::cout << "Wrong input. Type a valid index." << std::endl;
            std::cin >> indexc2;
        }
        masa.push_back(mana[indexc2]);
        mana.erase(mana.begin() + indexc2);

    }
    j.actualizareMana(mana);

}


bool Tabinet::maximCarti(Jucator j)
{
    for (int index = 0; index < jucatori.size(); index++)
        if (j.getNumarColectat() < jucatori[index].getNumarColectat())
            return false;

   return true;
}

void Tabinet::calculPunctaj(Jucator& j)
{
    int puncte = 0;
    std::vector<Carte> colectat;
    colectat = j.getColectat();
    for (int index = 0; index < colectat.size(); index++)
    {
        if (colectat[index].vacuta())
        {
            puncte = puncte + 2;
        }
        else {
            if (colectat[index].getValoareNumerica(1) == 10 || colectat[index].getValoareNumerica(1)==12 || colectat[index].getValoareNumerica(1)==13 || colectat[index].getValoareNumerica(1)==14 || colectat[index].getValoareNumerica(1) == 1)
                puncte++;
        }

        if (colectat[index].getSimbol() == "club" && colectat[index].vacuta()==false)
        {
            puncte++;
        }
    }

    puncte = puncte + j.getTabla();

    if (maximCarti(j) == true)
    {
        puncte = puncte + 3;
    }
    j.setPunctaj(puncte);

}


void Tabinet::run()
{
    auto ok = true;
    int indexCastigator = 0;
    std::srand(unsigned(std::time(0)));
    std::cout << "There will be " << jucatori.size() <<" players"<< std::endl;

    //amesteca();

    std::random_shuffle(pachet.begin(), pachet.end()-1);

    primaMana(jucatori[0]);
    for (int index = 1; index < jucatori.size(); index++)
    {
        primesteCarti(jucatori[index]);
    }
    if (masa.empty())
    {
        for (int index = 0; index < 4; index++)
        {
            Carte c = Tabinet::pachet[0];
            masa.push_back(c);
            pachet.erase(pachet.begin());
        }
    }
    while (!pachet.empty() )
    {

        ok = true;
        /*for (int index = 0; index < jucatori.size(); index++)
        {
            if (!jucatori[index].getMana().empty())
                ok = false;
        }*/
        for (auto juc : jucatori)
        {
            if (!juc.getMana().empty())
                ok = false;
        }

        if (ok == true)
        {
            if(pachet.size() / 6 >= numarJucatori)
                for (int index = 0; index < jucatori.size(); index++)
                {
                    primesteCarti(jucatori[index]);
                }
            else {
                while (pachet.size() > 0)
                {
                    for (int index = 0; index < jucatori.size(); index++)
                    {
                        jucatori[index].primesteCarte(pachet[0]);
                        pachet.erase(pachet.begin());
                    }
                }
            }
        }
        for (int index = 0; index < jucatori.size(); index++)
        {
            randJucator(jucatori[index], index);
        }
    }
    ok = true;
    for (int index = 0; index < jucatori.size(); index++)
    {
        if (jucatori[index].getMana().empty())
            ok = false;
    }

    while (ok == true)
    {
        
        for (int index = 0; index < jucatori.size(); index++)
        {
            randJucator(jucatori[index], index);
        }

        for (int index = 0; index < jucatori.size(); index++)
        {
            if (jucatori[index].getMana().empty())
                ok = false;
        }
    }
    

    if (!masa.empty())
    {
        for (int index = 0; index < masa.size(); index++)
            jucatori[ultimul].colecteaza(masa[index]);
    }

    for (int index = 0; index < jucatori.size(); index++)
    {
        calculPunctaj(jucatori[index]);
    }
    
    for (int index = 0; index < jucatori.size(); index++)
    {
        if (jucatori[indexCastigator].getPunctaj() < jucatori[index].getPunctaj())
            indexCastigator = index;
    }

    std::cout << std::endl;
    std::cout << "===========================================================" << std::endl;
    std::cout << "=========================GAME OVER=========================" << std::endl;
    std::cout << "===========================================================" << std::endl;
    std::cout << std::endl;
    for (int index = 0; index < jucatori.size(); index++)
    {
        std::cout << "PLAYER " << index <<" are "<< jucatori[index].getPunctaj() <<" points" << std::endl;
    }
    std::cout << "The winner is PLAYER " << indexCastigator << std::endl;
    std::cout << "CONGRATULATIONS! " << std::endl;
    std::cout << "===========================================================" << std::endl;

}