#include <iostream>
#include <string>

#include "personne.hpp"
#include "vehicule.hpp"
#include "voiture.hpp"

using namespace std;

int main(int argc, char **argv)
{
    //---------------
    // Heritage

    Personne personne("David");
    Etudiant etudiant("Paul", 12345);

    cout << personne.getNom() << endl;                                    // légal : personne est une Personne
    cout << etudiant.getNom() << ", ine : " << etudiant.getINE() << endl; // légal : etudiant est une Personne (par héritage)
    cout << etudiant.Personne::getNom() << endl;                          // utilisation de l'operateur de resolution de portee :: pour choisir la methode publique
    // personne.getINE(); // illégal : une Personne n’est pas forcement un Etudiant

    personne = etudiant; // copie OK
    // etudiant = personne; // interdit
    cout << personne.getNom() << endl;

    Personne *ptr_personne = &etudiant; // pointer sur Etudiant c'est pointer avant tout sur Personne

    cout << Etudiant_comp("Marie", 54321, "science").getNom() << endl;
    cout << endl;

    //---------------
    // Polymorphisme

    Vehicule vehicule;
    vehicule.klakson();
    Voiture voiture;
    voiture.klakson();
    cout << "Le type de voiture est : " << typeid(voiture).name() << endl;
    cout << endl;

    // on declare une lambda et on fait passer un vehicule en argument par copie.
    auto arg_par_copie = [](Vehicule vehicule_)
    {
        vehicule_.klakson();
        cout << "Le type de vehicule_ est : " << typeid(vehicule_).name() << endl;
    };
    cout << "Appel de arg_par_copie : \n";
    arg_par_copie(vehicule);
    arg_par_copie(voiture);
    cout << endl;
    // arg_par_copie ne voit que des vehicules

    // on definit la meme lambda avec un seul changement :
    // vehicule est passe par reference (&) au lieu d'etre passe par copie.
    auto arg_par_ref = [](Vehicule &vehicule_)
    {
        // l'implementation est la meme que arg_par_copie
        vehicule_.klakson();
        cout << "Le type de vehicule_ est : " << typeid(vehicule_).name() << endl;
    };
    cout << "Appel de arg_par_ref : \n";
    arg_par_ref(vehicule);
    arg_par_ref(voiture);
    // dans arg_par_ref on manipule des Vehicule (montee en abstraction)
    // mais a l'execution, l'implementation des methodes tient compte du type 

    return 0;
}