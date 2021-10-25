#pragma once

// Pour l'exemple, il n'y a pas de fichier personne.cpp.
// Les declarations et les definition sont toutes dans le meme fichier personne.hpp.
// On parle de code inline, les definitions seront recompilees a chaque fois que
// ce fichier header est inclus dans une unite de compilation cpp.

#include <iostream>
#include <string>

class Personne
{
public:
    Personne(std::string nom_) : nom(nom_) {} // le constructeur
    std::string getNom() const { return nom; }

private:
    std::string nom;
};

// Etudiant est la classe fille ou dérivée de Personne.
// Etudiant est une Personne, Etudiant hérite ou descend de Personne.
class Etudiant : public Personne // heritage public
{
public:
    // Etudiant doit appeler le constructeur parent Personne(std::string nom)
    Etudiant(std::string nom_, int ine_) : Personne(nom_), ine(ine_) {} // le constructeur Personne est appele en premier
    int getINE() const { return ine; }
    std::string getNom() const { return "Etudiant " + Personne::getNom(); } // surchage de la methode getNom de Personne
    // std::string getNom() const { return nom; } // interdit car nom est un attribut prive de Personne

private:
    int ine;
};

// On peut continuer les heritages
class EtudiantDiscipline : public Etudiant
{
public:
    EtudiantDiscipline(std::string nom_, int ine_, std::string discipline_) : Etudiant(nom_, ine_), discipline(discipline_) {}
    std::string getNom() const { return Etudiant::getNom() + " " + discipline; }

private:
    std::string discipline;
};

// Attention a l'heritage
// Preferer la composition, surtout si on utilise le polymorphisme
// On cree une nouvelle classe discipline :
class Discipline
{
public:
    Discipline() = default; // on utilise le constructeur par defaut avec son implementation par defaut
    Discipline(std::string discipline_) : discipline(discipline_) {}
    std::string getDiscipline() const { return discipline; }

private:
    std::string discipline;
};

class Etudiant_comp : public Personne
{
public:
    Etudiant_comp(std::string nom_, int ine_) : Personne(nom_), ine(ine_) {}

    Etudiant_comp(std::string nom_, int ine_, std::string discipline_)
        : Personne(nom_), ine(ine_), discipline(discipline_)
    {
    }

    int getINE() const { return ine; }
    std::string getNom() const { return "Etudiant " + discipline.getDiscipline() + " " + Personne::getNom(); }

private:
    int ine;
    Discipline discipline; // Notre deuxieme version d'Etudiant embarque un objet Discipline
};