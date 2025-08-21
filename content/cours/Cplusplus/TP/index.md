+++
title = "TP C++"
weight = 110
draft = true

[params]
  menuPre = '<i class="fa-solid fa-flask"></i> '
+++

![alt text](alexandrie.png?width=20vw)
## Énoncé

Vous prenez la suite d'un autre stagiaire dans le département informatique d'une bibliothèque.

Il s'agit de reprendre un logiciel de gestion des usagers et des livres. C'est un code ancien qui a besoin d'un peu de maintenance et de nouvelles fonctionnalités.

Il y a un binaire fonctionnel utilisé par les agents de la bibliothèque, mais le code est incomplet sur le repos.

**Voici les fonctionnalités principales du binaire** :
- Ajouter/supprimer des livres de la bibliothèque
- Rechercher des livres par titre ou auteur
- Emprunter/retourner des livres
- Afficher les livres disponibles
- Sauvegarder l'état de la bibliothèque dans un fichier et recharger au démarrage

> Le travail se fait seul.

## Évaluation

Ce travail compte pour **20%** de votre session et sera corrigé selon la grille suivante :

|Critère|Pourcentage|
|---|---|
| Completion du code manquant | **10%** |
| Ajout nouvelle fonctionalité | **5%** |
| Veille technologique | **5%** |
|**Total**| **20%** |


## Spécifications détaillées

- Utilisez le dev container par défaut C++ de vscode. Comme vu [ici](../introduction/#un-premier-programme).
- Ce projet utilise cmake, pensez à créer un répertoire `build`. Comme vu [ici](../fonctions/#cmake)
- Le code est disponible sur git

<i class="fa-brands fa-github"></i>
Repos Github classroom du projet

### Combler les trous dans le code

Il y a une erreur de faite avant le premier commit, et une partie du code a été perdu, le fichier `book.cpp` est incomplet. Servez-vous du fichier d'entête pour le compléter.

TODO: retirer une autre fonction avec de la STL dedans
TODO: faire le tri des features features a 10%

### Ajout d'une nouvelle fonctionnalités
#### Interface et Expérience Utilisateur

- Tri des résultats par titre, auteur, date d'ajout
- Filtres avancés (par genre, année de publication, disponibilité)
- Confirmation avant suppression de livres/utilisateurs
- numérotation automatique des ID

#### Gestion des Données

- Validation robuste des entrées (ISBN format, emails, etc.)
- Détection des doublons plus intelligente (même titre + auteur)
- Import/Export CSV pour faciliter la gestion en lot
- Logs d'activité (qui a emprunté quoi et quand)


### Veille technologique

Donnez ces explications dans le README.md à la racine du dépôt. Un paragraphe par questions est suffisant.

#### C++
Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours.

#### Options de développement possible
Proposez une solution plus adaptée pour la gestion de bibliothèque et faisant appel éventuellement à une technologie autre que le C++, et expliquez comment vous interfaceriez ca avec le C++. Pensez au futur de cette bibliothèque à Alexandrie qui pourrait éventuellement imagecontenir des millions de livres.