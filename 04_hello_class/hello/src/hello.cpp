#include "hello.hpp" // on inclut notre fichier d'entete header
// les "" sont utilises les inclure les fichiers headers locaux.

#include <iostream> // alors que les <> sont utilises pour les headers systemes.

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
    cout << "Appel du constructeur par defaut.\n";
}

// constructeur avec parametres
Hello::Hello(std::string word_) : word(word_), id(global_counter)
{
    increment_global_counter();
    print_object_id();
    cout << "Appel du constructeur avec parametres.\n";
}

// constructeur par copie
Hello::Hello(const Hello &hello) : word(hello.word), id(global_counter)
{
    increment_global_counter();
    print_object_id();
    cout << "Appel du constructeur par copie.";
    cout << " Copie de ";
    hello.print_object_id();
    cout << endl;
}

// constructeur par deplacement
Hello::Hello(Hello &&hello) : word(std::move(hello.word)), // utilisation de std::move pour deplacer
                              id(global_counter)
{
    increment_global_counter();
    print_object_id();
    cout << "Appel du constructeur par deplacement.";
    cout << " Move de ";
    hello.print_object_id();
    cout << endl;
}

// destructeur (unique)
Hello::~Hello()
{
    print_object_id();
    cout << "Appel du destruceur.\n";
}

void Hello::speak() const
{
    print_object_id();
    cout << word << endl;
}

int Hello::get_id() const
{
    return id;
}

void Hello::print_object_id() const
{
    // this est le pointeur de l'objet courant. C'est l'adresse memoire de l'objet.
    cout << "Object " << id << " (" << this << ") ";
}

int Hello::increment_global_counter()
{
    return ++global_counter;
}
