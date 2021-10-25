#include <iostream>
#include <vector>

// les templates sont specifies avec l'entete suivante.
// on peut utiliser typename ou class
template <typename T> // T est le type en parametre
void func(T x)        // x est du type T
{
    std::cout << "x = " << x << " de type " << typeid(x).name() << std::endl;
}

// Example de classe template
// On implemente un stack
template <typename T>
class Stack
{
public:
    void push(T val) { data.push_back(val); }
    T pop() { return data.pop_back(); }
    // on peut separer la declaration de la definition
    // la definition doit obligatoirement etre inline
    // isEmpty est defini juste apres la classe
    bool isEmpty() const;

private:
    std::vector<T> data;
};

// definition de isEmpty
// comme on peut le voir la methode appartient a la classe Stack<T> et non Stack qui n'existe pas ici.
template <typename T>
bool Stack<T>::isEmpty() const
{
    return data.empty();
}

using namespace std;

int main(int argc, char **argv)
{
    // on appelle successivement la meme fonction func avec des variable de type differents :
    func(1);         // entier
    func(1.);        // double precision
    func<float>(1.); // on peut forcer l'appel pour un type donne, ici en simple precision
    func("un");      // chaine de charactere PKc = Pointer Konst char

    // un stack d'entiers
    Stack<int> stack_int;
    stack_int.push(1);

    // un stack de floats
    Stack<float> stack_float;
    stack_float.push(1.);

    return 0;
}