#pragma once

#include <iostream>
#include <string>

// Classe de base qui va nous servir d'interface
class Vehicule
{
public:
    // la methode klakson est declare virtuelle, elle pourra etre overrider par ses classes filles.
    virtual void klakson() const // le mot cle virtual n'est present que dans le fichier header.
    {
        // Dans notre cas, on implemente la fonction
        std::cout << "Le vehicule fait du bruit.\n";
    }
    // Si on ne donne pas d'implementation de la classe mere,
    // il faut declarer la methode comme etant virtuelle pure :
    // virtual void klakson() const = 0;
    // Dans ce cas, les classes derivees devront obligatoirement implementer la methode.
};
