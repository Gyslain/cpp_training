// header files
#include <iostream> // insertion de iostream pour l'utilisationde cout, cin et endl
#include <string>   // pour les chaines de characteres
#include <cmath>    // pour faire des maths

// pour ecrire et lire des fichiers
#include <iostream>
#include <fstream>

// utilisation de l'espace de nom de lib standard
// le compilateur cherchera des symboles dans l'espace de nom global, note ::
// et dans l'espace std, note std::
using namespace std;
// Ex. : apres l'instruction using namespace std, on a : string, ::string, std::string representent tous le meme symbole

// pour l'exemple, nous definissons un espace de nom functions :
namespace functions
{
    // exemple de definition de fonctions
    int sum_function(int a, int b)
    {
        cout << "somme entre deux entiers\n";
        return a + b;
    }
    // l'implementation d'une meme fonction depend de ses parametres
    // On pourra generer automatiquement ces fonctions grace aux templates
    float sum_function(float a, float b) // surcharge de sum_function
    {
        cout << "somme entre deux floats\n";
        return a + b;
    }
}

int main(int argc, char **argv) // fonction main.
{
    // Les variables doivent etre declarees.
    // Elles sont declarees une seul fois. Leur type ne plus changer.

    int myNum = 5;                               // Integer (4 bytes)
    float myFloatNum = 5.99;                     // Floating point number (4 bytes)
    double myDoubleNum = 3.14159265358979323846; // Floating point number (8 bytes)
    char myLetter = 'D';                         // Character (1 byte)
    bool myBoolean = true;                       // Boolean (true or false) (1 byte)

    // sizeof renvoit le nombre de bytes d'un objet ou d'un type
    cout << "myNum = " << myNum << " of size : " << sizeof(myNum) << " bytes." << endl;
    cout << "myFloatNum = " << myFloatNum << " of size : " << sizeof(myFloatNum) << " bytes." << endl;
    cout << "myDoubleNum = " << myDoubleNum << " of size : " << sizeof(myDoubleNum) << " bytes." << endl;
    cout << "myLetter = " << myLetter << " of size : " << sizeof(myLetter) << " bytes." << endl;
    cout << "myBoolean = " << myBoolean << " of size : " << sizeof(myBoolean) << " bytes." << endl;
    cout << endl;

    // declaration en une seule ligne
    int x = 5, y = 6;
    const int z = 7; // declaration d'une constante
    cout << x + y + z << endl;

    // TODO
    // operateur de cast,conversion d'un type a un autre

    // chaine de charactere
    std::string myText = "Hello";
    cout << myText << endl
         << endl; // instruction sur plusieurs lignes

    //-------------------

    // pour faire des maths, utiliser le fichier header cmath
    cout << "doing maths...\n";
    cout << "sqrt(64) = " << sqrt(64) << endl;
    cout << "round(2.6) = " << round(2.6) << endl;
    cout << "log(2) = " << log(2) << endl;
    cout << endl;

    //-------------------

    // entrer des donnees utilisateur avec std::cin
    int sum;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    sum = x + y;
    cout << "Sum is: " << sum << endl;

    //-------------------

    // conditions
    if (x < y)
        cout << "x < y" << endl;

    else if (x > y)
        cout << "x > y" << endl;
    else
        cout << "x == y" << endl;

    // switch case
    switch (x)
    {
    case 1:
        cout << "case x == 1" << endl;
        break;
    case 2:
        cout << "case x == 2" << endl;
        break;
        // ...
    default:
        cout << "default case" << endl;
        break;
    }
    cout << endl;

    //-------------------

    // loops
    cout << "while loop :\n";
    int i = 0;
    while (i < 3)
    {
        cout << i << "\n";
        i++; // operateur ++ pour incrementer
    }
    cout << endl;

    cout << "for loop :\n";
    for (int i = 0; i < 5; i++)
    {
        if (i == 1 || i == 2) // || est l'operateur ou
        {
            cout << "i=" << i << " appel a continue, on boucle.\n";
            continue;
        }

        if (i == 4)
        {
            cout << "i=" << i << " appel a break, on arrete la boucle ici, on ne boucle pas jusqu'a la fin.\n";
            break;
        }

        cout << "i=" << i << " des instructions...\n";
    }
    cout << endl;

    //-------------------

    // fonctions et namespace
    cout << "Appel de sum_function : \n";
    cout << functions::sum_function(x, y) << endl; // nous appelons la fonction avec l'operateur de resolution de portee ::
    // pour eviter d'ecrire functions::, on peut utiliser l'espace de nom en entier :
    using namespace functions;
    // On peut maintenant appeler la fonction directement
    cout << sum_function(static_cast<float>(x), static_cast<float>(y)) << endl; // l'implementation depend ici des parametres

    // lambda function, fonction anonyme
    // x est declare en tant que parametre de fonction et y et capture par copie [=]
    auto lambda = [=](auto x)
    {
        return sqrt(x) + y;
    };
    cout << lambda(x) << endl; // on appelle la variable comme une fonction
    cout << endl;

    //-------------------

    // exceptions
    cout << "Exceptions :\n";
    // lamda qui peut renvoyer une exception :

    // float my_sqrt(float x)
    // {
    //     if (x < 0)
    //         throw std::invalid_argument("x cannot be negative.");
    //     return sqrt(x);
    // };

    // another comment 2


    auto my_sqrt = [](float x)
    {
        if (x < 0)
            throw std::invalid_argument("x cannot be negative.");
        return sqrt(x);
    };

    try // on essaie de passer une valeur negative :
    {
        cout << my_sqrt(-1) << endl; // erreur
    }
    catch (const std::exception &e) // on attrape l'exception et on la traite :
    {
        std::cerr << e.what() << '\n'; // std::cerr renvoit sur la sortie 2, la sortie d'erreur
    }

    //-------------------

    // fichiers
    // ofstream	pour creer et ecrire des fichiers
    // ifstream	opur lire des fichiers

    // Ecriture de fichier :
    ofstream MyFile("fichier.txt");          // comme pour cout, on cree un flux qui sera redirige vers un fichier
    MyFile << "Manipulation de fichiers.\n"; // on ecrit
    MyFile << "Et voici une deuxieme ligne.\n";
    MyFile.close(); // et on ferme le flux

    // Lecture de fichier :
    ifstream MyReadFile("fichier.txt"); // On declare le flux de lecture du fichier
    while (getline(MyReadFile, myText)) // On boucle sur les lignes du fichier avec while et getline. On stocke la ligne dans myText
        cout << myText << endl;         // on pousse les donnees sur le flux
    MyReadFile.close();                 // on ferme le flux

    return 0;
}