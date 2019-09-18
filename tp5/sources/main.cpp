#include <iostream>
#include "Joueur.h"

using namespace std;

/*
 * fonction principale
 */
int main(int argc, char** argv) {
    
    Joueur* joueur = new Joueur(); // Création d'un joueur
    //string DBFile = "DB.txt"; // Fichier qui contient une base des joueurs
    int choix; // Opération séléctionnée par l'utilisateur
    do {
        std::cout << std::endl << "--------------------------------------" << std::endl;
        std::cout << "0 - Quitter le programme " << std::endl;
        std::cout << "1 - Créer un joueur " << std::endl;
        std::cout << "2 - Trouver un joueur " << std::endl;
        std::cout << "3 - Afficher un joueur " << std::endl;
        std::cout << "4 - Enregistrer le joueur " << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::cin >> choix;
        switch (choix) {
            case 1:
            {
                string nom;
                string prenom;
                int age;
                string nomEquipe;
                string paysEquipe;
                std::cout << "Saisir le nom du joueur : " ;
                std::cin >> nom;
                std::cout << "Saisir le prenom du joueur : " ;
                std::cin >> prenom;
                std::cout << "Saisir l'age du joueur : " ;
                std::cin >> age;
                std::cout << "Saisir le nom de l'équipe : " ;
                std::cin >> nomEquipe;
                std::cout << "Saisir le pay de l'équipe : " ;
                std::cin >> paysEquipe;
                delete joueur;
                joueur = new Joueur (nom, prenom, age, nomEquipe, paysEquipe);       
                break;
            }
            case 2:
            {
                string nom,prenom;
				std::cout << "Saisir le nom du joueur : " ;
                std::cin >> nom;
                std::cout << "Saisir le prenom du joueur : " ;
                std::cin >> prenom;
                string DBFile = "DB.txt";//restructuration
                Joueur* tmp = joueur->trouverJoueur(DBFile, nom,prenom);
                if (tmp != NULL) {// Si l'joueur est trouvé
                    joueur = tmp;
		    std::cout << "Joueur trouvé !" << std::endl;	
                } else {
                    std::cout << "Aucun joueur n'est trouvé!" << std::endl;
                }
                break;
            }
            case 3:
            {
                if (joueur != NULL) {
                    joueur->afficher();
                } else {
                    std::cout << "Aucun joueur n'est séléctionné" << std::endl;
                }
                break;
            }
            case 4:
            {
                if (joueur != NULL){ 
					string DBFile = "DB.txt";//restructuration
                    joueur->saveJoueur(DBFile);
                    std::cout << "Joueur enregistré !" << std::endl;
                }
            }
        }        
    } while (choix!= 0); // Tant que l'utilisateur ne décide pas de quitter le programmme
    return 0;
}

