#ifndef RANGEMENT_H
#define RANGEMENT_H

#include <vector>
#include <string>

#include "contenant.h"
#include "carton.h"
#include "espaceLibre.h"

class Rangement{
  public :
  // Attributs :
    int _qContenant;
    std::vector<Carton*> _cartRang;
    std::vector<Contenant*> _contRang;
    std::vector<EspaceLibre*> _espLib;
  
  // Méthodes génériques :
    // Constructeur
	Rangement(void) : _qContenant(0) {}
    // Destructeur
	~Rangement(void) {}

    // Accesseurs :
		int getContActuel(void){return _qContenant;}

		// Accesseur de carton
		Carton* getCartonByRang(int i){return _cartRang[i];}	//Sélectionner un carton par son rang
		int getCartonByName(std::string name);					//Sélectionner un carton par son nom
		int getCartonByDim(int dim);							// Sélectionner un carton par une de ses dimensions
	
		// Accesseurs de contenant
		Contenant* getContenantByRang(int i){return _contRang[i];}
		int getContenantByName(std::name name);
		int getContenantByDim(int dim);

		// Accesseur d'espace libre
		EspaceLibre* getELByRang(int i){return _espLib[i];}
		int getELByName(std::string name);
		int getELByDim(int dim);

		// Fonction outil
		

	// Mutateurs
		void setContActuel(int i){_qContenant=i;} // Préciser le contenant dans lequel on travaille

		void addCarton(Carton* carton); // Ajout de carton par recopie
		void addCarton(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, const bool fragile, const float masse); // Permet de créer le carton dans la fonction
		
		void addContenant(Contenant* contenant); // Ajout de contenant par recopie
		void addContenant(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, float masseMax); // Permet de créer le contenant dans la fonction
		
		void addEL(EspaceLibre* espLibre); // Ajout d'espace libre par recopie
		void addEL(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name); // Permet de créer l'espace libre dans la fonction
	
  // Méthodes spécialisées :
    // Récupération des cartons à ranger
	void recupererCartons(std::string fichier); // A adapter car dépend de l'interface
	
    // Tri des cartons fonction de leurs dimensions
	void triDesCartons(void);
  
    // Vérification de la possibilité de placement des cartons
	bool validationAttributionCoordonnees(void); // Fonction de test globale
	bool verifMasseLegale(Carton * carton);
	bool verifContactContainer(Carton * carton);
	bool verifContactCarton(Carton * carton, int x, int y, int z);
		
    // Trouver le carton le plus adapté
	int trouverCarton(EspaceLibre* espaceLibre); //Renveira l'indice du carton le plus adapté
	bool attributionPossible(Carton * carton, EspaceLibre *);
	
    // Attribution des coordonnées de la position du carton
	void attributionCoordonnees(void);
	
    // Ranger les cartons
	void rangerLesCartons(void);
};

#endif

/* Remarques

1  Nono 
	Réaliser un pattern de classement des cartons dans le vecteur une fois rangés pour faciliter 
	la modélisation graphique (Nono)
   
*/
