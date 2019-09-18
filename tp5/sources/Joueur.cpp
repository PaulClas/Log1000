#include "Joueur.h"

#include <fstream>
#include <iostream>
#include <stdlib.h>

// Constructeur
/*
 * Joueur::Joueur(){//Modification par Paul
	nom = "";
	prenom = "";
	age = "";
	equipe = new Equipe();//Modification par Paul
}
*/
Joueur::Joueur (string nom,string prenom,int age,string teamName,string teamPays) {
    // Joueur information
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
    // Equipe information
    this->equipe = new Equipe(teamName, teamPays);//Modification par Paul
}

// Setters
void Joueur::setNom(string nom) {
    this->nom = nom;
}
void Joueur::setPrenom(string prenom) {
    this->prenom = prenom;
}
void Joueur::setAge(int age) {
    this->age = age;
}
// Associer équipe au joueur
void Joueur::associerEquipe (Equipe* equipe) {//Modification par Paul
    this->equipe = equipe;
}

// Getters
string Joueur::getNom() {
    return this->nom;
}
string Joueur::getPrenom() {
    return this->prenom;
}

int Joueur::getAge() {
    return this->age;
}
/***********************************************************************
 * Modification par Paul
 * ********************************************************************/
string Joueur::getNomEquipe(){
	return equipe->getNomEquipe();
}
/***********************************************************************
 * Modification par Paul
 * ********************************************************************/
string Joueur::getPaysEquipe(){
	return equipe->getPaysEquipe();
}

/*
string Joueur::getNomEquipe() {
    return this->teamName;
}

string Joueur::getPaysEquipe() {
    return this->teamPays;
}
*/

// Enregistrer l'Joueur dans un fichier
void Joueur::saveJoueur (string fileName) {
    ofstream outfile (fileName.c_str(), std::ofstream::binary | std::fstream::app);
    // write to outfile
    outfile<<this->nom <<","
		   <<this->prenom <<","
		   <<this->age <<","
		   <<(this->equipe)->getNomEquipe() << "," //Modifcation par Paul
		   <<(this->equipe)->getPaysEquipe() <<"\n"; //Modification par Paul
    outfile.close();
}


string extraireChaine(int & debutLecture, string ligne) {
	string retour;
	int i;
	for (i = debutLecture ; i < ligne.length() ; i++) {
            if (ligne[i] != ',') {
               retour += ligne[i];
            } else {
                 break;
            }
	}
	debutLecture = i;
	return retour;
}


// Trouver un Joueur avec son nom dans la base de données DB
Joueur* Joueur::trouverJoueur (string DB, string nom,string prenom) {
    
    ifstream fichier(DB.c_str(), ios::in); // Ouvrir le fichier "DB.txt"
    Joueur*tmp=NULL;
	
    if(fichier)
    {
        string line;
        // Lire les Joueurs, un Joueur par ligne dans la base de données (DB)
        while (getline(fichier, line)) {
            
            // Récupérer le nom de joueur
            int i = 0;
			string nomJoueurDB = extraireChaine(i,line);
			
            // Si le Joueur qu'on lit actuellement est celui qu'on cherche
            if (nomJoueurDB == nom) {
                
                // Récupérer le prenom du joueur
                string prenomJoueurDB = extraireChaine(++i, line);
               
                if (prenomJoueurDB == prenom) {
				 
					//  Récupérer le nom de l'age
					string ageJoueurDB = extraireChaine(++i, line);
					
					// Récupérer le nom de l'équipe
					string teamNameDB = extraireChaine(++i, line);
					
					// Récupérer le pays de l'équipe
					string teamPaysDB = extraireChaine(++i, line);
					
					// Créer un objet de type Joueur avec les informations récupérées
					Joueur *a = new Joueur(nomJoueurDB, prenomJoueurDB,atoi(ageJoueurDB.c_str()), teamNameDB, teamPaysDB);
					// Fermer la base de données
					fichier.close();
					// Retourner l'Joueur sélectionné
					return a;
				} // end if (prenomJoueurDB == prenom) 	
	    } //end if (nomJoueurDB == nom) 
         }// end while
        fichier.close();
    }// end  if(fichier)
    return NULL;
}

// Afficher l'Joueur
void Joueur::afficher() {
    std::cout << "Nom : " << this->nom << std::endl;
    std::cout << "Prenom : " << this->prenom << std::endl;
    std::cout << "Age : " << this->age << std::endl;
    std::cout << "Nom equipe : " << (this->equipe)->getNomEquipe() << std::endl;
    std::cout << "Pays equipe: " << (this->equipe)->getPaysEquipe() << std::endl;
}



