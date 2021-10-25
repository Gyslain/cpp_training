#include "voiture.hpp"

#include <iostream>

using namespace std;

// implementation de la methode, pas de virtual dans le cpp.
void Voiture::klakson() const
{
    cout << "La voiture fait : tut tut!\n";
}
