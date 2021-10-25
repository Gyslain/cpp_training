#include <iostream>
#include <string>
#include <memory> // pour les smarts pointeurs
#include <algorithm>

// conteneur de la lib standard
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
    //-------------------
    // tableaux statique

    // declaration d'un tableau de 4 elements
    string array1[2];   // declaration et allocation automatique sur le stack
    array1[0] = "hey!"; // on accede aux elements par leur indice
    array1[1] = "hello!";

    string array2[] = {"cat", "dog", "cow"}; // declaration et initialisation en meme temps

    // on peut forcer la taille a la declaration.
    // comme l'allocation est statique, on ne peut pas modifier la taille de ces tableaux a l'execution.
    // la taille est definit a la compilation
    string array3[4] = {"cat", "dog", "cow"}; // tableau de 4 elements
    array3[5] = "bat";

    //-------------------
    // Adresse memoire

    // l'adresse d'un objet est obtenu avec l'operateur &
    string food = "pizza";
    cout << "L'adresse de food est : " << &food << ", la variable contient " << food << endl;
    cout << endl;

    //-------------------
    // Pointeurs

    // un pointeur est une variable qui stocke l'adresse mémoire en tant que valeur :
    string *ptr_food = nullptr; // on declare un pointeur sur un string et on l'initialise a nullptr.
    ptr_food = &food;           // la variable ptr_food stocke l'adresse de food
    // on dereference un pointeur avec l'operateur *
    cout << "Le pointeur ptr_food contient l'adresse " << ptr_food << ". La valeur a cette adresse est : " << *ptr_food << endl;
    // on peut modifier la valeur de food via le pointeur ptr_food :
    *ptr_food = "hamburger";
    cout << "Le pointeur ptr_food contient l'adresse " << ptr_food << ". La valeur a cette adresse est : " << *ptr_food << endl;
    cout << endl;

    // Les tableaux statiques sont des pointeurs :
    cout << "Le tableau array2 est un pointeur, il contient une adresse vers un string : " << array2 << endl;
    cout << "Sa valeur dereferencee est : " << *array2 << endl; // on lit la premiere valeur, ce qui est equivalent a array2[0]

    // on peut parcourir un tableau en faisant de l'arithmetique de pointeur :
    for (int i = 0; i < 3; ++i)
        cout << "Adresse de l'element " << i << " : " << array2 + i << ", valeur : " << *(array2 + i) << endl;
    // le pointeur est decale du nombre d'octet de chaque element

    // Attention au depassements de memoire : *(array2 + 4), pas de controle pour les tableaux statiques

    cout << endl;

    // Pour simplifier la manipulation des pointeurs, on peut utiliser de references.
    // Ce sont des alias. Ils sont equivalents a des pointeurs constant auto-dereferences.
    // Les references sont declarees avec l'operateur &.
    // Elles sont obligatoirement initialisees a la declaration.
    string &ref_food = food; // Apres l'initialisation de la reference, utiliser ref_food ou food est equivalent
    cout << "ref_food = " << ref_food << endl;
    cout << "food = " << food << endl; // food contient la meme valeur que ref_food
    ref_food = "hot-dog";              // on modifie la reference
    cout << "food = " << food << endl; // food est egalement modifie
    cout << endl;

    //-------------------
    // Allocation dynamique

    // operateur new et delte
    int *var = nullptr; // declaration d'un pointeur d'entier
    // a ce stade *var est indetermine
    var = new int; // allocation d'un entier
    *var = 5;      // initialisation de l'entier
    delete var;    // liberation de la memoire
    var = nullptr; // on fait pointer le pointeur vers nullptr

    int *array_var = new int[2]; // allocation d'un tableau de 2 entiers
    array_var[0] = 1;            // initialisation du premier element avec []
    *(array_var + 1) = 2;        // ou en faisant de l'arithmetique de pointeur
    delete[] array_var;          // liberation du tableau avec delete[]

    //-------------------
    // Smart pointeurs, plus besoin de se soucier du delete
    // pour ne pas oublier de de-allouer la memoire, on peut utiliser les smart-pointeurs

    shared_ptr<string> smart_ptr(new string);
    // on peut le manipuler comme un pointeur classique
    *smart_ptr = "I'm smart";
    cout << "From smart_ptr : " << *smart_ptr << endl;
    // l'adresse du pointeur peut etre partagee par d'autre shared_ptr:
    shared_ptr<string> smart_ptr2 = smart_ptr;
    // le shared_ptr contient un compteur de references.
    // la memoire est liberee automatiquement lorsque le compteur de references est a 0.

    unique_ptr<string> uniquePtr(new string("hello"));
    cout << "From uniquePtr : " << *uniquePtr << endl;
    // les pointeurs uniquePtr ne peut etre reference que par une seule variable
    // unique_ptr<string> uniquePtr2 = uniquePtr; // Interdit!!
    // On ne peut pas copier son adresse. Mais on peut deplacer le pointeur :
    unique_ptr<string> uniquePtr2(std::move(uniquePtr)); // uniquePtr ne contient plus rien
    cout << "*uniquePtr2 = " << *uniquePtr2 << endl;
    // *uniquePtr; // on ne peut plus dereferencer uniquePtr, il est dans un etat indetermine
    // l'unique_ptr est plus performant que le shared_ptr, il ne contient pas de compteur de references.
    // le compilateur libere automatiquement la memoire en sortie du scope.

    //-------------------

    // conteneur de la stl, la memoire est geree automatiquement
    // on utilise les vectors pour faire des tableaux dynamique
    vector<int> data(3, 1); // construction d'un vecteur de 3 entiers initialises a 1
    data[0] = 0;            // modification du premier element
    data.push_back(4);      // on peut pousser de nouvelles donnees dedans, l'allocation memoire est dynamique

    // on definit une lambda pour afficher les elements du vector
    // le vector est passe par reference (&), on ne le copie pas.
    auto print = [](const auto &array)
    {
        // on boucle sur les elements du vector
        for (const auto &v : array)
            cout << v << " ";
        cout << endl;
    };

    cout << "data : ";
    print(data);

    cout << "map : \n";
    std::map<int, string> dict; // associe une cle de type int a un objet de type string
    dict[2] = "some data";
    cout << "dict[2]=" << dict[2] << endl;
    dict[-1] = "other data";
    for (auto k : dict) // boucle sur la map
        cout << "key: " << k.first << ", value: " << k.second << endl;
    cout << endl;

    // Decouvrir les conteneurs de la stl :
    // https://en.cppreference.com/w/cpp/container

    //-------------------
    // Les itérateurs

    // Les itérateurs sont utilisés pour pointer sur les adresses mémoire des conteneurs STL
    // Ils sont safe et performant suivant le conteneur de la stl
    vector<int> data2 = {3, 2, 5, 4, 1};             // Autre maniere d'initialiser un objet, avec l'initializer list. Les elements sont passes directement au constructeur.
    vector<int>::iterator ptr_begin = data2.begin(); // initialisation d'un iterator
    auto it = ptr_begin + 3;                         // deplacement de l'iterateur, il pointe sur 4 maintenant
    cout << "it pointe sur " << *it << endl;

    // Les iterateurs sont utiles pour les algorithme de la stl.
    // Copie d'elements
    copy(data2.begin(), data2.end(), data.begin());
    cout << "data : ";
    print(data);
    // Trie de vector
    sort(data2.begin(), data2.end());
    cout << "data2 apres sort : ";
    print(data2);
    // Recherche d'elements
    it = find(data2.begin(), data2.end(), 2);
    if (it != data2.end())
        std::cout << "Element present : " << *it << '\n';
    else
        std::cout << "Element non present\n";

    // Decouvrir les algorithmes de la stl :
    // https://en.cppreference.com/w/cpp/algorithm

    //-------------------

    return 0;
}