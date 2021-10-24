#include <iostream> // header file, insertion de iostream pour l'utilisationde cout et endl

using namespace std; // utilisation de l'espace de nom de lib standard

int main(int argc, char **argv) // declaration et definition de la fonction main.
{
    // cout est flux vers la sortie standard.
    // l'operateur << redirige un flux. Ici on redirige le flux des donnees vers la sortie standard.
    cout << "Hello world" << endl; // endl est equivalent a "\n"
    return 0;                      // retour de fonction
}