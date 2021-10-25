#pragma once

#include "vehicule.hpp" // on inclut notre interface

// classe derivee
class Voiture : public Vehicule // Voiture herite de Vehicule
{
public:
    virtual void klakson() const override;
    // le mot cle override est facultatif.
    // C'est un garde fou pour s'assurer et confirmer que le compilateur va bien overrider la methode parente.
};
