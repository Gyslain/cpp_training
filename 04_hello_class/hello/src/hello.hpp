// on utilise la directive #pragma once pour que le compilateur
// insere une seule fois ce fichier entete dans chaque unite de compilation .cpp ou il est inclut.
// Les variables et les objets ne sont declares qu'une seule fois par unite de compilation.
#pragma once

#include <string>

class Hello // nom de la classe
{
public: // acces public
    // constructeurs (pas de retour)
    Hello();              // defaut
    Hello(std::string);   // parametres
    Hello(const Hello &); // par copie
    Hello(Hello &&);      // par deplacement

    // un seul destructeur doit etre present
    ~Hello();

    // methods
    void speak() const; // la methode const ne modifie pas l'objet

    // accesseur public aux donnees privees
    int get_id() const; // acces en lecture (methode const)

    static int get_global_counter();

    std::string word; // un attribut public

private: // acces prive, seule la classe Hello a acces, cela permet d'encapsuler les donnees
    // variable statique, elle appartient a la classe et non a l'objet
    static int global_counter;

    // variable const, elle ne peut pas etre modifiee apres sont initialisation
    const int id;

    void print_object_id() const;
    int increment_global_counter();
};
