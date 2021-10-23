#pragma once

#include <string>

class Hello // nom de la classe
{
public: // acces public
    // constructeurs (ne renvoient pas d'objets)
    Hello();                 // defaut
    Hello(std::string word); // parametres
    Hello(const Hello &);    // par copie

    // un seul destructeur doit etre present
    ~Hello();

    // methods
    void speak() const; // la methode ne modifie pas l'objet

    // accesseur public aux donnees privees
    int get_id() const;

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
