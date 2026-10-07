+++
title = "Algorithme de tri"
weight = 120
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

## Consignes
- Vous devez implémenter cet algorithme de tri en C++.
- Vous pouvez utiliser un tableau donné (hardcoded) dans le code. 
- Pensez à utiliser la STL pour le tableau et pour faire l'[échange](https://en.cppreference.com/cpp/algorithm/swap) des valeurs (exemple simplifié de [swap](https://www.geeksforgeeks.org/cpp/swap-in-cpp/)).
- Vous n'êtes pas obliger de créer une classe. Un seul fichier cpp suffit.

### Algorithme détail

Le **tri par sélection** parcourt le tableau de gauche à droite pour placer le plus petit élément à sa place définitive, une case à la fois.

1. **Zone triée vs Zone non triée :**
Le tableau est séparé en deux parts. Au départ, la zone triée est vide ($i = 0$).
2. **Conditions de départ d'une passe :**
* On pose $i$ comme le premier indice de la zone non triée.
* On suppose que cet élément est le plus petit : `min_idx = i`.


3. **Recherche :**
Un curseur $j$ parcourt le reste du tableau (de $i+1$ à la fin) :

{{< math >}}
$$\text{Si } A[j] < A[\text{min_idx}], \text{ alors } \text{min_idx} = j$$
{{< /math >}}

4. **Échange :**
Une fois le parcours terminé, on échange $A[i]$ et $A[\text{min_idx}]$. La zone triée s'agrandit de 1 case.
5. **Fin :**
On répète jusqu'à ce qu'il ne reste qu'un seul élément au bout du tableau.

<!-- ---
## Solution

[**tri.cpp**](tri.cpp)
 -->
