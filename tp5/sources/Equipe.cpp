#include "Equipe.h"

#include <fstream>
#include <iostream>
#include <stdlib.h>

// Constructeur
/*Equipe::Equipe(){
	this->teamName = "";
	this->teamPays = "";
}*/

Equipe::Equipe(string teamName,string teamPays) {
    // Equipe information
    this->teamName = teamName;
    this->teamPays = teamPays;
}
// Associer équipe au joueur
void Equipe::associerEquipe (string teamName, string teamPays) {
    this->teamName = teamName;
    this->teamPays = teamPays;
}

// Getters
string Equipe::getNomEquipe() {
    return this->teamName;
}

string Equipe::getPaysEquipe() {
    return this->teamPays;
}
