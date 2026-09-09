#include <iostream>
#include <vector>
#include <utility> // Pour std::swap

// Fonction qui effectue le tri par sélection
void triParSelection(std::vector<int>& tableau) {
    size_t taille = tableau.size();

    // On parcourt le tableau jusqu'à l'avant-dernier élément
    for (size_t i = 0; i < taille - 1; ++i) {
        // On suppose que l'élément actuel est le plus petit
        size_t indexMinimum = i;

        // Recherche du véritable minimum dans le reste du tableau non trié
        for (size_t j = i + 1; j < taille; ++j) {
            if (tableau[j] < tableau[indexMinimum]) {
                indexMinimum = j; // Mise à jour de l'indice du minimum
            }
        }

        // Échange de l'élément actuel avec le minimum trouvé
        if (indexMinimum != i) {
            std::swap(tableau[i], tableau[indexMinimum]);
        }
    }
}

// Fonction d'affichage du tableau
void afficherTableau(const std::vector<int>& tableau) {
    for (int valeur : tableau) {
        std::cout << valeur << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> donnees = {64, 25, 12, 22, 11};

    std::cout << "Tableau initial : ";
    afficherTableau(donnees);

    triParSelection(donnees);

    std::cout << "Tableau trie   : ";
    afficherTableau(donnees);

    return 0;
}