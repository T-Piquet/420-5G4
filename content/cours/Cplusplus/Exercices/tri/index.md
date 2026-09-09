+++
title = "Algorithme de tri"
weight = 110
draft = true
+++


## Principe du tri par sélection

On divise le tableau en deux parties : une partie triée (à gauche) et une partie non triée (à droite). À chaque étape :
1. On cherche le plus petit élément dans la partie non triée.
2. On l'échange avec le premier élément de la partie non triée.
3. On avance la frontière entre la zone triée et non triée d'une position.


### Animation interactive

{{< tri_selection >}}

## complexité de l'algorithme

- **Complexité temporelle** : 
$O(n^2)$ dans tous les cas (meilleur, moyen, pire), car la recherche du minimum nécessite toujours de parcourir le reste du tableau.
- **Complexité spatiale** : 
$O(1)$ — c'est un tri sur place (in-place), il n'exige pas de mémoire supplémentaire significative.