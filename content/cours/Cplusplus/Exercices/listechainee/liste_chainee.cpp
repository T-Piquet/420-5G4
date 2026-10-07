#include <iostream>
#include <stdexcept>
using namespace std;

// =====================================================================
// Étape 1 : Classe Noeud
// =====================================================================
class Noeud {
public:
    int valeur;
    Noeud* suivant;

    // Constructeur pour faciliter la création
    Noeud(int val) : valeur(val), suivant(nullptr) {}

    // Destructeur (optionnel, mais bonne pratique)
    ~Noeud() {}
};

// =====================================================================
// Étape 2 : Affichage et ajout en début de liste
// =====================================================================
void afficherListe(Noeud* tete) {
    if (tete == nullptr) {
        cout << "(liste vide)" << endl;
        return;
    }

    Noeud* courant = tete;
    while (courant != nullptr) {
        cout << courant->valeur;
        if (courant->suivant != nullptr) {
            cout << " -> ";
        }
        courant = courant->suivant;
    }
    cout << " -> NULL" << endl;
}

void ajouterDebut(Noeud*& tete, int valeur) {
    Noeud* nouveauNoeud = new Noeud(valeur);
    nouveauNoeud->suivant = tete;
    tete = nouveauNoeud;
}

// =====================================================================
// Étape 3 : Ajout en fin de liste
// =====================================================================
void ajouterFin(Noeud*& tete, int valeur) {
    Noeud* nouveauNoeud = new Noeud(valeur);

    // Cas liste vide
    if (tete == nullptr) {
        tete = nouveauNoeud;
        return;
    }

    // Parcourir jusqu'au dernier nœud
    Noeud* courant = tete;
    while (courant->suivant != nullptr) {
        courant = courant->suivant;
    }

    // Ajouter le nouveau nœud à la fin
    courant->suivant = nouveauNoeud;
}

// =====================================================================
// Étape 4 : Recherche
// =====================================================================
int obtenirPosition(Noeud* tete, int valeur) {
    Noeud* courant = tete;
    int position = 0;

    while (courant != nullptr) {
        if (courant->valeur == valeur) {
            return position;
        }
        courant = courant->suivant;
        position++;
    }

    return -1; // Non trouvé
}

// =====================================================================
// Étape 5 : Suppression
// =====================================================================
bool supprimerElement(Noeud*& tete, int valeur) {
    // Liste vide
    if (tete == nullptr) {
        return false;
    }

    // Suppression en tête
    if (tete->valeur == valeur) {
        Noeud* aSupprimer = tete;
        tete = tete->suivant;
        delete aSupprimer;
        return true;
    }

    // Suppression ailleurs dans la liste
    Noeud* courant = tete;
    while (courant->suivant != nullptr) {
        if (courant->suivant->valeur == valeur) {
            Noeud* aSupprimer = courant->suivant;
            courant->suivant = aSupprimer->suivant;
            delete aSupprimer;
            return true;
        }
        courant = courant->suivant;
    }

    return false; // Élément non trouvé
}

// =====================================================================
// Étape 6 : Fonctions utilitaires
// =====================================================================
int compterElements(Noeud* tete) {
    int compteur = 0;
    Noeud* courant = tete;

    while (courant != nullptr) {
        compteur++;
        courant = courant->suivant;
    }

    return compteur;
}

void viderListe(Noeud*& tete) {
    while (tete != nullptr) {
        Noeud* aSupprimer = tete;
        tete = tete->suivant;
        delete aSupprimer;
    }
}

void inverserListe(Noeud*& tete) {
    if (tete == nullptr || tete->suivant == nullptr) {
        return; // Liste vide ou un seul élément
    }

    Noeud* precedent = nullptr;
    Noeud* courant = tete;
    Noeud* suivant = nullptr;

    while (courant != nullptr) {
        suivant = courant->suivant;
        courant->suivant = precedent;
        precedent = courant;
        courant = suivant;
    }

    tete = precedent;
}

// =====================================================================
// Étape 7 : Classe listeChainee
// =====================================================================
class listeChainee {
private:
    Noeud* tete; // Pointeur vers la tête de la liste

public:
    // Constructeur
    listeChainee();
    // Destructeur : libère toute la mémoire
    ~listeChainee();

    void ajouterDebut(int valeur);
    void ajouterFin(int valeur);
    int obtenirPosition(int valeur) const;
    bool supprimerElement(int valeur);
    void afficher() const;
    int compterElements() const;
    void inverser();
    void vider();

    // Bonus : accès aux éléments par l'opérateur []
    int& operator[](int index);
};

listeChainee::listeChainee() : tete(nullptr) {}

listeChainee::~listeChainee() {
    vider();
}

void listeChainee::ajouterDebut(int valeur) {
    Noeud* nouveauNoeud = new Noeud(valeur);
    nouveauNoeud->suivant = tete;
    tete = nouveauNoeud;
}

void listeChainee::ajouterFin(int valeur) {
    Noeud* nouveauNoeud = new Noeud(valeur);

    if (tete == nullptr) {
        tete = nouveauNoeud;
        return;
    }

    Noeud* courant = tete;
    while (courant->suivant != nullptr) {
        courant = courant->suivant;
    }
    courant->suivant = nouveauNoeud;
}

int listeChainee::obtenirPosition(int valeur) const {
    Noeud* courant = tete;
    int position = 0;

    while (courant != nullptr) {
        if (courant->valeur == valeur) {
            return position;
        }
        courant = courant->suivant;
        position++;
    }

    return -1;
}

bool listeChainee::supprimerElement(int valeur) {
    if (tete == nullptr) {
        return false;
    }

    if (tete->valeur == valeur) {
        Noeud* aSupprimer = tete;
        tete = tete->suivant;
        delete aSupprimer;
        return true;
    }

    Noeud* courant = tete;
    while (courant->suivant != nullptr) {
        if (courant->suivant->valeur == valeur) {
            Noeud* aSupprimer = courant->suivant;
            courant->suivant = aSupprimer->suivant;
            delete aSupprimer;
            return true;
        }
        courant = courant->suivant;
    }

    return false;
}

void listeChainee::afficher() const {
    if (tete == nullptr) {
        cout << "(liste vide)" << endl;
        return;
    }

    Noeud* courant = tete;
    while (courant != nullptr) {
        cout << courant->valeur;
        if (courant->suivant != nullptr) {
            cout << " -> ";
        }
        courant = courant->suivant;
    }
    cout << " -> NULL" << endl;
}

int listeChainee::compterElements() const {
    int compteur = 0;
    Noeud* courant = tete;

    while (courant != nullptr) {
        compteur++;
        courant = courant->suivant;
    }

    return compteur;
}

void listeChainee::inverser() {
    if (tete == nullptr || tete->suivant == nullptr) {
        return;
    }

    Noeud* precedent = nullptr;
    Noeud* courant = tete;
    Noeud* suivant = nullptr;

    while (courant != nullptr) {
        suivant = courant->suivant;
        courant->suivant = precedent;
        precedent = courant;
        courant = suivant;
    }

    tete = precedent;
}

void listeChainee::vider() {
    while (tete != nullptr) {
        Noeud* aSupprimer = tete;
        tete = tete->suivant;
        delete aSupprimer;
    }
}

// Bonus : opérateur [] (retourne une référence pour permettre la modification)
int& listeChainee::operator[](int index) {
    if (index < 0) {
        throw out_of_range("Index negatif");
    }

    Noeud* courant = tete;
    int i = 0;
    while (courant != nullptr) {
        if (i == index) {
            return courant->valeur;
        }
        courant = courant->suivant;
        i++;
    }

    throw out_of_range("Index hors limites");
}

// =====================================================================
// Démonstration des étapes 1 à 6
// =====================================================================
void demonstrationEtapes() {
    cout << "=== DÉMONSTRATION DES ÉTAPES ===" << endl;

    // Étape 1 : Création manuelle de 3 nœuds
    cout << "\n--- Étape 1 : Création manuelle ---" << endl;
    Noeud* noeud1 = new Noeud(10);
    Noeud* noeud2 = new Noeud(20);
    Noeud* noeud3 = new Noeud(30);

    noeud1->suivant = noeud2;
    noeud2->suivant = noeud3;

    cout << "Liste: ";
    afficherListe(noeud1);

    viderListe(noeud1);

    // Étape 2 : Ajout au début
    cout << "\n--- Étape 2 : Ajout au début ---" << endl;
    Noeud* liste = nullptr;

    ajouterDebut(liste, 30);
    cout << "Liste après ajout de 30: ";
    afficherListe(liste);

    ajouterDebut(liste, 20);
    cout << "Liste après ajout de 20: ";
    afficherListe(liste);

    ajouterDebut(liste, 10);
    cout << "Liste après ajout de 10: ";
    afficherListe(liste);
    viderListe(liste);

    // Étape 3 : Ajout à la fin
    cout << "\n--- Étape 3 : Ajout à la fin ---" << endl;
    liste = nullptr;
    ajouterFin(liste, 10);
    ajouterFin(liste, 20);
    cout << "Liste initiale: ";
    afficherListe(liste);

    ajouterFin(liste, 30);
    cout << "Après ajout de 30: ";
    afficherListe(liste);

    ajouterFin(liste, 40);
    cout << "Après ajout de 40: ";
    afficherListe(liste);

    ajouterFin(liste, 50);
    cout << "Après ajout de 50: ";
    afficherListe(liste);

    // Étape 4 : Recherche
    cout << "\n--- Étape 4 : Recherche ---" << endl;
    int valeursRecherche[] = {30, 60, 10};
    for (int val : valeursRecherche) {
        int position = obtenirPosition(liste, val);
        cout << "Recherche de " << val << ": ";
        if (position != -1) {
            cout << "Trouvé à la position " << position << endl;
        } else {
            cout << "Non trouvé (position -1)" << endl;
        }
    }

    // Étape 5 : Suppression
    cout << "\n--- Étape 5 : Suppression ---" << endl;
    cout << "Liste initiale: ";
    afficherListe(liste);

    bool succes = supprimerElement(liste, 30);
    cout << "Suppression de 30: ";
    afficherListe(liste);
    cout << (succes ? "(Réussi)" : "(Échec)") << endl;

    succes = supprimerElement(liste, 10);
    cout << "Suppression de 10: ";
    afficherListe(liste);
    cout << (succes ? "(Réussi)" : "(Échec)") << endl;

    succes = supprimerElement(liste, 60);
    cout << "Suppression de 60: ";
    afficherListe(liste);
    cout << (succes ? "(Réussi)" : "(Échec - élément non trouvé)") << endl;

    viderListe(liste);

    // Étape 6 : Fonctions utilitaires
    cout << "\n--- Étape 6 : Fonctions utilitaires ---" << endl;
    liste = nullptr;
    ajouterFin(liste, 10);
    ajouterFin(liste, 20);
    ajouterFin(liste, 30);
    ajouterFin(liste, 40);

    cout << "Liste: ";
    afficherListe(liste);
    cout << "Nombre d'éléments: " << compterElements(liste) << endl;

    inverserListe(liste);
    cout << "Liste inversée: ";
    afficherListe(liste);

    viderListe(liste);
    cout << "Liste vidée: ";
    afficherListe(liste);
}

// =====================================================================
// Étape 8 : Menu interactif
// =====================================================================
void afficherMenu() {
    cout << "\n=== GESTIONNAIRE DE LISTE CHAÎNÉE ===" << endl;
    cout << "1. Ajouter au début" << endl;
    cout << "2. Ajouter à la fin" << endl;
    cout << "3. Rechercher élément" << endl;
    cout << "4. Supprimer élément" << endl;
    cout << "5. Afficher liste" << endl;
    cout << "6. Compter éléments" << endl;
    cout << "7. Inverser liste" << endl;
    cout << "8. Vider liste" << endl;
    cout << "9. Quitter" << endl;
    cout << "Votre choix : ";
}

int main() {
    // Démonstration des étapes 1 à 6
    demonstrationEtapes();

    // Menu interactif (étapes 7 et 8)
    listeChainee liste;
    int choix;

    do {
        afficherMenu();
        cin >> choix;

        switch (choix) {
            case 1: {
                int valeur;
                cout << "Valeur à ajouter au début : ";
                cin >> valeur;
                liste.ajouterDebut(valeur);
                cout << "Élément ajouté avec succès." << endl;
                break;
            }

            case 2: {
                int valeur;
                cout << "Valeur à ajouter à la fin : ";
                cin >> valeur;
                liste.ajouterFin(valeur);
                cout << "Élément ajouté avec succès." << endl;
                break;
            }

            case 3: {
                int valeur;
                cout << "Valeur à rechercher : ";
                cin >> valeur;
                int position = liste.obtenirPosition(valeur);
                if (position != -1) {
                    cout << "Élément trouvé à la position " << position << endl;
                } else {
                    cout << "Élément non trouvé." << endl;
                }
                break;
            }

            case 4: {
                int valeur;
                cout << "Valeur à supprimer : ";
                cin >> valeur;
                bool succes = liste.supprimerElement(valeur);
                if (succes) {
                    cout << "Élément supprimé avec succès." << endl;
                } else {
                    cout << "Élément non trouvé." << endl;
                }
                break;
            }

            case 5: {
                cout << "Liste actuelle: ";
                liste.afficher();
                break;
            }

            case 6: {
                cout << "Nombre d'éléments: " << liste.compterElements() << endl;
                break;
            }

            case 7: {
                liste.inverser();
                cout << "Liste inversée avec succès." << endl;
                break;
            }

            case 8: {
                liste.vider();
                cout << "Liste vidée avec succès." << endl;
                break;
            }

            case 9: {
                cout << "Au revoir!" << endl;
                break;
            }

            default: {
                cout << "Choix invalide. Veuillez réessayer." << endl;
                break;
            }
        }

    } while (choix != 9);

    return 0;
}
