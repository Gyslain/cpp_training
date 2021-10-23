#include <iostream>

// insertion du header contenant la declaration de notre classe Hello
#include "hello/src/hello.hpp"

using namespace std;

int main(int argc, char **argv)
{
    // constructor par defaut
    Hello hello1;
    // appel de la methode speak
    hello1.speak();
    // Acces et modification de l'attribut public word
    hello1.word = "Hey!";
    hello1.speak();
    cout << endl;

    Hello hello2("Hello, what's up?");
    hello2.speak();
    cout << endl;

    // constructor par copie, declaration avec auto
    auto hello3 = Hello(hello1);
    hello3.speak();
    cout << endl;

    cout << "Nombre d'instances Hello : " << Hello::get_global_counter() << endl;
    cout << endl;

    return 0;
}
