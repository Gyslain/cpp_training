#include <iostream>
#include <vector>

// insertion du header contenant la declaration de notre classe Hello
#include "hello/src/hello.hpp"

using namespace std;

int main(int argc, char **argv)
{
    // constructor par defaut
    Hello hello0;
    // appel de la methode speak
    hello0.speak();
    // Acces et modification de l'attribut public word
    hello0.word = "Hey!";
    hello0.speak();
    cout << endl;

    Hello hello1("Hello, what's up?");
    hello1.speak();
    cout << endl;

    // constructor par copie avec declaration auto
    auto hello2 = Hello(hello0);
    hello2.speak();
    cout << endl;

    // creation d'un vector avec 2 objets Hello construit par defaut :
    vector<Hello> hello_vect(2); // O3, O4
    // hello_vect.reserve(5); // on peut reserver le nombre d'objets en avance pour eviter des copies
    hello_vect.push_back(hello1);            // copy O1 -> O5, O3 -> O6, O4 -> O7
    hello_vect.push_back(Hello("move"));     // O8, move O8 -> O9
    hello_vect.push_back(std::move(hello2)); // move O2 -> 10, ...
    // hello2 a deplace ses attributs :
    hello2.speak(); // rien a dire
    cout << endl;

    // on parcour les elements du vector par reference constante
    for (const auto &hello : hello_vect)
    {
        hello.speak();
    }
    cout << endl;

    cout << "Nombre d'instances Hello : " << Hello::get_global_counter() << endl;
    cout << endl;

    return 0;
}
