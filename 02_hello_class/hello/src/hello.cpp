#include "hello.hpp"

#include <iostream>

using namespace std;

// initialisation de la variable statique global_counter
// comme la variable appartient a la classe et non a l'objet son initialisation se situe a l'exterieur des constructeurs.
int Hello::global_counter = 0;

int Hello::get_global_counter() { return global_counter; }

// Appel au constructeur par defaut et initialisation des parametres
Hello::Hello() : word("Hello world!"), id(global_counter) // id est constant, il doit obligatoirement erte initialise dans l'initializer list
{
    increment_global_counter();
    print_object_id();
    cout << " : Appel du constructeur par defaut.\n";
}

Hello::Hello(std::string word_) : word(word_), id(global_counter)
{
    increment_global_counter();
    print_object_id();
    cout << " : Appel du constructeur avec parametres.\n";
}

Hello::Hello(const Hello &hello) : word(hello.word), id(global_counter)
{
    increment_global_counter();
    print_object_id();
    cout << " : Appel du constructeur par copie.";
    cout << " Copie de l'objet " << hello.id << endl;
}

Hello::~Hello()
{
    print_object_id();
    cout << " : Appel du destruceur.\n";
}

void Hello::speak() const
{
    print_object_id();
    cout << " : " << word << endl;
}

int Hello::get_id() const
{
    return id;
}

void Hello::print_object_id() const
{
    cout << "Object " << id;
}

int Hello::increment_global_counter()
{
    return ++global_counter;
}
