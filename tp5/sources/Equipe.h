#ifndef Equipe_H
#define Equipe_H

#include <string>

using namespace std;

// Cette classe represente une Equipe
class Equipe {
public:
	// Constructeurs
    Equipe () {}
    Equipe(string, string);
    
    
    // Getters
    string getNomEquipe();
    string getPaysEquipe();
    
    void associerEquipe(string, string);
   
private:
	// Informations sur l'équipe
    string teamName;
    string teamPays;
    
};
#endif 
