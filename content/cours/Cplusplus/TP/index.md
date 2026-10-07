+++
title = "TP C++"
weight = 110

[params]
  menuPre = '<i class="fa-solid fa-flask"></i> '
+++

![alt text](alexandrie.png?width=20vw)
## Énoncé

Vous prenez la suite d'un autre stagiaire dans le département informatique d'une bibliothèque.

Il s'agit de reprendre un logiciel de gestion des usagers et des livres. C'est un code ancien qui a besoin d'un peu de maintenance et de nouvelles fonctionnalités.

Il y a un binaire fonctionnel utilisé par les agents de la bibliothèque, mais le code est incomplet sur le repos.
Binaire disponnible : [bibliotheque](bibliotheque)


**Voici les fonctionnalités principales du binaire** :
- Ajouter/supprimer des livres de la bibliothèque
- Rechercher des livres par titre ou auteur
- Emprunter/retourner des livres
- Afficher les livres disponibles
- Sauvegarder l'état de la bibliothèque dans un fichier et recharger au démarrage

### Exemple d'utilisation

```
Chargement des données de la bibliothèque...
Aucun fichier de livres existant trouvé. Démarrage avec une bibliothèque vide.
Aucun fichier d'utilisateurs existant trouvé. Démarrage sans utilisateurs enregistrés.

=== SYSTÈME DE GESTION DE BIBLIOTHÈQUE PERSONNELLE ===
1.  Ajouter un Livre
2.  Supprimer un Livre
3.  Rechercher des Livres par Titre
4.  Rechercher des Livres par Auteur
5.  Afficher Tous les Livres
6.  Afficher les Livres Disponibles
7.  Ajouter un Utilisateur
8.  Afficher Tous les Utilisateurs
9.  Emprunter un Livre
10. Retourner un Livre
11. Statistiques de la Bibliothèque
12. Sauvegarder les Données
13. Créer une Sauvegarde
0.  Quitter
======================================================
Entrez votre choix : 7
Entrez le nom de l'utilisateur : Thomas Piquet
Entrez l'ID de l'utilisateur : USR420
Utilisateur ajouté avec succès !

Appuyez sur Entrée pour continuer...
```

## Évaluation

Ce travail compte pour **20%** de votre session et sera corrigé selon la grille suivante :

|Critère|Pourcentage|
|---|---|
| Completion du code manquant | **25%** |
| Ajout de nouvelles fonctionalitées | **50%** |
| Veille technologique | **20%** |
| Qualité du repo git | **5%** |
|**Total**| **100%** |

> Le travail se fait seul.

## Spécifications détaillées

- Utilisez le dev container par défaut C++ de vscode. Comme vu [ici](../../base-de-connaissances/vscode/#dev-container-de-base). *Pensez à le versionner dans git.*
- Ce projet utilise cmake, pensez à créer un répertoire `build`. Comme vu [ici](../fonctions/#cmake). *Pensez à votre `.gitignore`.*
- Le code est disponible sur git, vous allez faire un `fork` du projet. Référez vous à la [page git](../../base-de-connaissances/git/#utilisation-des-forks) pour plus de détails.

<div style="text-align: center; font-size: 28px; font-weight: bold;">
  <a href="https://github.com/T-Piquet/420-5G4-TPcpp"><i class="fa-brands fa-github"></i> Dépot Github du projet</a> 
</div>

> [!warning] **Remise**
> **Soignez vos commit** en suivant les recommandations [**ici**](../../../base%20de%20connaissances/git/#bien-%C3%A9crire-un-message-de-commit). 
>
> Votre historique git est un indicateur de votre progression lors du TP, c'est une manière pour moi d'évaluer votre code. Trop peu de commit me feront soupsonner l'utilisation d'IA générative.
>
> Le **dernier commit + pull request** doit être fais avant :
> - **Groupe 1** : Remise le ~~9/10 23h59~~ 16/10 23h59
> - **Groupe 2** : Remise le ~~6/10 23h59~~ 19/10 23h59
> - **Groupe 3** : Remise le ~~7/10 23h59~~ 14/10 23h59
> 
> En cas de doute, vous pouvez me demander de vérifier si j'ai bien recu votre `pull-request`.

### Combler les trous dans le code

Il y a une erreur de faite avant le premier commit, et une partie du code a été perdu, le fichier `book.cpp` est manquant. Servez-vous du fichier d'entête pour le compléter.

> [!tip]
> Pour les fonctions relative à la sauvegarde de fichier, pensez a utiliser les fichiers d'exemple fournis `books.txt`.
>
> Vous devrez être capable de lire ce fichiers une fois `books.cpp`complété.

### Ajout de nouvelles fonctionnalités

Vous devez ajouter 3 nouvelles fonctionnalités tirée du backlog du projet : 
- 1 fonctionnalité au choix dans *Interface et Expérience Utilisateur*
- 1 fonctionnalité au choix dans *Gestion des Données*
- La fonctionnalité journal d'activités.
- Corriger le bug

#### Interface et Expérience Utilisateur

- numérotation automatique des ID utilisateurs. 
- Afficher le nom d'utilisateur plutôt que l'id dans l'affichage des livres.
- Détection des doublons plus intelligente (même titre, auteur, ISBN).

#### Gestion des Données

- Tri des résultats par titre, auteur pour l'affichage (utilisation de la fonction de tri de la STL).
- Import/Export CSV pour faciliter la gestion en lot (en plus du format actuel).

#### Journal d'activités
- Créez un fichier de journal de l'application. Ce fichier est conservé au fur et à mesure des sessions (créez le fichier s'il n'existe pas à la première exécution).

``` 
2026-10-23 10:23:57 - [EMPRUNT] Les Misérables|Victor Hugo|9782253096337|0|Marie Dubois
2026-10-23 01:35:23 - [AJOUT LIVRE] L'assomoir |Victor Hugo|9782253090275|1|
```

#### Corriger un bug
- Sauvegarde automatique à la sortie sans répertoire de données
 - Si on lance sans --data-dir, saveLibraryData essaie d’écrire dans "" et échoue silencieusement.
 - Proposition : ne pas sauvegarder si les chemins sont vides et afficher un message explicite.

### Veille technologique
Donnez ces explications dans le fichier `README.md` à la racine du dépôt. C'est le texte qui est afficher sur la page de votre repos sur Github.

> [!tip] Contenue du README.md
> Le fichier `README.md` est en markdown. Utilisez cette [Cheatsheet markdown](https://github.com/im-luka/markdown-cheatsheet) pour formater votre readme.
> - Votre nom et prénom.
> - Les fonctionnalités que vous avez choisi d'implémenter.
> - Les réponses aux questions, un paragraphe par questions est suffisant. (une phrase est insuffisant.)

#### Question 1 : C++
Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours. Montrez ici l'exemple sorti du code du projet.

#### Question 2 : Options de développement possible
Proposez une solution plus adaptée pour la gestion de bibliothèque et faisant appel éventuellement à une technologie autre que le C++, et expliquez comment vous interfaceriez ça avec le C++. Quelle solution technologique utiliseriez vous ? Pensez au futur de cette bibliothèque à Alexandrie qui pourrait éventuellement contenir des millions de livres.