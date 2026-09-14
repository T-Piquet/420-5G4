+++
title = "Allocation mémoire"
weight = 90
+++

Voici un exercice qui met en évidence un problème très classique : la **fuite de mémoire** (*memory leak*) et l'accès à de la **mémoire suspendue / pendante** (*dangling pointer*).

---

**Objectif :** Identifier pourquoi un code compile et semble fonctionner au premier abord, mais provoque un comportement indéterminé (*undefined behavior*) et consomme de la mémoire non libérée.

#### Le scénario

On souhaite écrire une fonction qui génère un tableau d'entiers dynamiquement, le remplit avec des nombres pairs, puis le retourne au `main` pour affichage. Puis l'inverse et le re-affiche.

Voici le code rédigé par un développeur débutant :

```cpp
#include <iostream>

// Fonction censée créer un tableau de N nombres pairs
int* genererPairs(int taille) {
    int* tab = new int[taille];
    for (int i = 0; i < taille; ++i) {
        tab[i] = i * 2;
    }
    return tab;
}

// Fonction qui tente d'inverser un tableau
void inverserEtNettoyer(int* ptr, int taille) {
    int* temp = new int[taille];
    for (int i = 0; i < taille; ++i) {
        temp[i] = ptr[taille - 1 - i];
    }
    
    // Le développeur libère ptr ici en pensant bien faire...
    delete[] ptr;
    
    // Et réassigne le pointeur local
    ptr = temp; 
}

int main() {
    int taille = 5;
    
    // 1. Génération du tableau
    int* mesChiffres = genererPairs(taille);

    // affichage
    std::cout << "Tableau : ";
    for (int i = 0; i < taille; ++i) {
        std::cout << mesChiffres[i] << " "; 
    }
    std::cout << std::endl;

    // 2. Tentative d'inversion
    inverserEtNettoyer(mesChiffres, taille);
    
    // 3. Affichage du tableau inversé
    std::cout << "Tableau inversé : ";
    for (int i = 0; i < taille; ++i) {
        std::cout << mesChiffres[i] << " "; 
    }
    std::cout << std::endl;

    return 0;
}

```

---

#### Vos tâches :

1. **Analyse sans exécuter :**
* Que vaut le pointeur `mesChiffres` dans la fonction `main` **après** l'appel à `inverserEtNettoyer` ?
* Pourquoi la ligne `ptr = temp;` à la fin de `inverserEtNettoyer` n'a-t-elle aucun effet sur `mesChiffres` dans le `main` ?


2. **Identification des bogues :**
* Où se situe l'accès mémoire invalide (*dangling pointer*) ?
* Combien de fuites de mémoire (*memory leaks*) contient ce programme et à quelles lignes sont alloués les blocs perdus ?


3. **Correction :**
* Réécrivez la fonction `inverserEtNettoyer` (ou adaptez sa signature) et la fonction `main` pour que :
* Le tableau soit correctement inversé et affiché.
* Toute la mémoire allouée avec `new[]` soit libérée avec `delete[]` avant la fin du `main`.

---

{{% expand title="**Explications détaillées et correction**" %}} 

### Analyse des problèmes mémoire

Le code initial accumule deux erreurs classiques lors de la manipulation manuelle du tas (*heap*) :

#### Le pointeur pendant (*Dangling Pointer*)

Dans la fonction `inverserEtNettoyer`, l'argument `ptr` est passé **par valeur**.

```cpp
void inverserEtNettoyer(int* ptr, int taille)

```

* Lors de l'appel `inverserEtNettoyer(mesChiffres, taille)`, la variable `ptr` est une **copie locale** de l'adresse contenue dans `mesChiffres`.
* La ligne `delete[] ptr;` libère le bloc mémoire alloué dans `genererPairs`. L'adresse contenue dans `mesChiffres` pointe désormais vers une zone mémoire **qui n'appartient plus au programme**.
* La réassignation `ptr = temp;` modifie uniquement la copie locale `ptr`. Dès la sortie de la fonction, la variable `ptr` disparaît.
* De retour dans le `main`, `mesChiffres` contient toujours l'ancienne adresse libérée. La boucle d'affichage tente de lire de la mémoire libérée : c'est un **comportement indéterminé** (*Undefined Behavior* / *Use-After-Free*).

#### Les fuites de mémoire (*Memory Leaks*)

Le programme perd la trace de deux blocs mémoire alloués dynamiquement :

1. **Bloc `temp` dans `inverserEtNettoyer` :** Le tableau créé avec `new int[taille]` est assigné à la variable locale `ptr`. Lorsque la fonction se termine, cette adresse est perdue car elle n'a pas été renvoyée ni passée par pointeur/référence. Ce bloc de mémoire reste réservé jusqu'à la fin du processus.
2. **Absence de `delete[]` final dans le `main` :** Même si l'inversion avait fonctionné, aucun `delete[] mesChiffres;` n'est exécuté avant le `return 0;`.

---

### Schéma du comportement mémoire (Code défectueux)

```
[ main() ]                           [ Tas (Heap) ]
mesChiffres (0x1000) -------------> [ 0, 2, 4, 6, 8 ]  (Alloué par genererPairs)
                                          ^
[ inverserEtNettoyer() ]                  |
ptr (copie de 0x1000) --------------------+
  -> delete[] ptr  ----------------> [ MÉMOIRE LIBÉRÉE ]

temp (0x2000) --------------------> [ 8, 6, 4, 2, 0 ]  (Alloué dans la fonction)
ptr = temp  (ptr vaut 0x2000)

-- Fin de inverserEtNettoyer() : ptr et temp disparaissent --

[ main() ]
mesChiffres (0x1000) -------------> [ MÉMOIRE LIBÉRÉE ] (Lecture invalide !)
                                    [ 8, 6, 4, 2, 0 ]   (Bloc 0x2000 perdu en mémoire !)

```

---

### Code corrigé

Pour corriger ce code sans utiliser de classes ni de référence C++ (`&`), il faut transmettre un **pointeur de pointeur** (`int**`) à la fonction pour modifier directement l'adresse stockée dans `mesChiffres`.

```cpp
#include <iostream>

// Génération dynamique du tableau
int* genererPairs(int taille) {
    int* tab = new int[taille];
    for (int i = 0; i < taille; ++i) {
        tab[i] = i * 2;
    }
    return tab;
}

// Inversion et remplacement sécurisé du tableau
// pPtr est l'adresse du pointeur mesChiffres (&mesChiffres)
void inverserEtNettoyer(int** pPtr, int taille) {
    // 1. Allocation du nouveau tableau inversé
    int* temp = new int[taille];
    for (int i = 0; i < taille; ++i) {
        temp[i] = (*pPtr)[taille - 1 - i];
    }
    
    // 2. Libération de l'ancien tableau pointé par *pPtr
    delete[] *pPtr;
    
    // 3. Mise à jour de l'adresse contenue dans le pointeur d'origine
    *pPtr = temp;
}

int main() {
    int taille = 5;
    
    // 1. Allocation initiale
    int* mesChiffres = genererPairs(taille);
    
    // 2. Passage de l'adresse de mesChiffres (int**)
    inverserEtNettoyer(&mesChiffres, taille);
    
    // 3. Affichage (accède bien au nouveau tableau inversé)
    std::cout << "Tableau inversé : ";
    for (int i = 0; i < taille; ++i) {
        std::cout << mesChiffres[i] << " ";
    }
    std::cout << std::endl;

    // 4. Libération finale pour éviter tout memory leak
    delete[] mesChiffres;
    mesChiffres = nullptr;

    return 0;
}

```

---

### Résumé des bonnes pratiques avec `new` / `delete`

* **Un `new[]` implique toujours un `delete[]**` correspondant sur le même pointeur.
* **Toute modification de l'adresse pointée** par un pointeur passé à une fonction nécessite un pointeur de pointeur (`type**`) en C pur (ou une référence de pointeur `type*&` en C++).
* Après un `delete`, il est recommandé de réinitialiser le pointeur à `nullptr` pour éviter une réutilisation accidentelle.

{{% /expand %}} 