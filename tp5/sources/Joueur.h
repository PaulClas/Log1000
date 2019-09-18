#ifndef Joueur_H
#define Joueur_H


#include <string>
#include "Equipe.h"

using namespace std;
        
// Cette classe represente un Joueur
class Joueur {
public:
    // Constructeurs
    Joueur () {}
    Joueur(string, string, int, string, string);
   
    // Setters
    void setNom(string nom);
    void setPrenom(string prenom);
    void setAge(int age);
    
    // Getters
    string getNom();
    string getPrenom();
    int getAge();
    string getNomEquipe();
    string getPaysEquipe();
   
    // Associer une equipe à un joeur 
    void associerEquipe(Equipe*);
    // Enregistrer le Joueur
    void saveJoueur(string);
    // Afficher le Joueur
    void afficher();
    // Chercher un Joueur dans une base de donnees par titre
    Joueur* trouverJoueur(string, string, string);
    
private:
    // Informations sur le joueur
    string nom;
    string prenom;
    int age;
    Equipe* equipe;
};

#endif 
