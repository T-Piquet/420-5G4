+++
title = "Apprentissage machine"
weight = 20
draft = true
+++

### Définition

L'apprentissage machine (machine learning) se fonde sur des approches mathématiques et statistiques pour donner aux ordinateurs la capacité d'« apprendre » à partir de données. On cherche à améliorer leurs performances à résoudre des tâches sans être explicitement programmés pour.

**Deux phases:**

1. **Apprentissage ou entraînement**: On fournit un ensemble de données à un algorithme. L'algorithme développe un modèle qui résout une tâche pratique, telle que traduire un discours, estimer une probabilité, reconnaître la présence d'un chat dans une photographie ou participer à la conduite d'un véhicule autonome. Généralement avant l'utilisation pratique du modèle.

2. **Utilisation**: Selon le modèle déterminé, de nouvelles données peuvent alors être soumises afin d'obtenir le résultat correspondant à la tâche souhaitée. En pratique, certains systèmes peuvent poursuivre leur apprentissage une fois en production.

## Apprentissage supervisé ou non-supervisé?

Réaliser un apprentissage supervisé consiste à fournir à la machine des données étiquetées (labellisées) et propices à l'apprentissage. C'est-à-dire que nous allons analyser et préparer les données et leur donner une signification. C'est à partir de cette signification que la machine va réaliser son apprentissage. L'objectif étant d'indiquer à la machine que pour une série de données et pour une observation précise, la valeur à prédire est un chat, un chien ou bien une autre valeur.

- **Prédire une valeur : régression**. Par exemple : prédire le pourcentage de réussite d'une équipe de football lors d'un match
- **Sinon, classification**. Par exemple : déterminer que la photo affichée est un chat ou un chien est une classification.

## Principaux algorithmes supervisés d'apprentissage machine

L'apprentissage se fait à partie d'algorithmes de statistique ou d'optimisation.

Il ne s'agit pas ici d'en donner une description mathématique rigoureuse, mais bien une intuition de leur fonctionnement pour comprendre comment une machine "apprend".

### La régression linéaire univariée (linear regression)

Cet algorithme cherche à établir, sous forme d'une droite, une relation entre deux variables Par exemple, prédire une note à un examen en fonction du nombre d'heures de révision.

Ainsi, connaissant le nombre d'heures de révisions, il nous est possible de prédire approximativement la note que l'on obtiendra au prochain examen.

Ici, on pourrait prédire qu'en étudiant 4 heures, on aurait environ 8/20.

### La régression linéaire multiple (Multiple Linear Regression-MLR)

La régression linéaire n'utilise qu'une variable pour en expliquer une autre. Souvent, la réalité est plus complexe.

Par exemple, prédire la note à un examen peut dépendre du niveau de stress, du nombre d'heures de sommeil la veille de l'examen, des obtenues aux TPs, etc.

### Régression polynomiale

Il est parfois difficile de représenter un comportement avec une droite. En utilisant un polynôme (fonction avec des exposants, la courbe prédictive épouse mieux la forme des données)

L'exemple des notes d'examen avec une fonction polynomiale:

### Fonction sigmoïde (en S)

Lorsqu'un tente de faire une classification, une droite ou une courbe ne sont pas nécessairement utiles. On cherche plutôt la probabilité qu'on objet appartienne à une catégorie ou à une autre. Par exemple, la probabilité qu'un objet dans une image soit un chat ou un chien.

### Arbre de décision

Représente un ensemble de choix sous la forme d'un arbre. Permet d'explorer plusieurs possibilités.

Peut être sous la forme de plusieurs tests exécutés.

#### Arbre de décision dans les jeux

On peut développer une branche pour chaque coup possible dans un jeu.

L'algorithme devient alors d'explorer tous les coups possibles et de déterminer s'il existe un chemin qui est toujours gagnant pour un joueur ou l'autre. Lorsqu'un tel chemin est déterminé, on dit que le jeu est résolu (pour une liste: https://fr.wikipedia.org/wiki/Jeu_r%C3%A9solu)

**Jeu résolu célèbre**: Tic-Tac-Toe. Un joueur peut forcer une partie, peu importe s'il commence ou joue deuxième.

Pour les jeux plus complexes, il est impossible d'explorer tous les coups possibles. Aux échecs par exemple, il prendrait au meilleur ordinateur des centaines de milliers d'années pour explorer tous les coups.

Les algorithmes vont utiliser une heuristique pour éliminer l'exploration de certains coups: par exemple déplacer son roi en deuxième, volontairement sacrifier une pièce, etc.

**Une heuristique** est un ensemble de critères qui guide la découverte.

#### Arbre du Tic-tac-toe
*Impossible de perdre!*

#### Aux échecs...

### Forêts aléatoires (Random Forest)

Consiste à apprendre en parallèle sur plusieurs arbres de décisions construits aléatoirement (au hasard) et entraînés sur des sous-ensembles contenant des données différentes. Chaque arbre propose alors une prédiction et la prédiction finale consiste à réaliser la moyenne de toutes les prédictions.

### Agrégation de modèle

L'union fait la force! Comme pour la forêt aléatoire, on peut combiner plusieurs modèles pour prendre une décision.

- **Le bagging**: Consiste à découper les données d'apprentissage en échantillons et d'utiliser pour chaque échantillon un algorithme différent.
- **Le boosting**: Comme le bagging, mais les algorithmes sont notés selon leur prédiction. Plus l'algorithme prédit une bonne valeur, plus il obtient une bonne note.

### Machine à vecteur de support - Support Vector Machine (SVM)

Peut faire à la fois de la régression et de la classification. Détermine une frontière afin de séparer les observations en groupes distincts tout en maximisant la marge de séparation.

#### Machine à vecteur de support

Consiste donc à projeter les données dans un espace vectoriel de plus grande dimension à l'aide d'un élément appelé noyau, permettant alors une création de frontière.

### KNN (K-Nearest Neighbours)

Algorithme de classification visant à déterminer pour le groupe d'appartenance d'une observation à partir du groupe d'appartenance de ses K plus proches voisins. K étant le nombre de voisins à considérer.

### Naive Bayes

Naive Bayes se base sur le Théorème de Bayes fondé sur les probabilités conditionnelles: la probabilité qu'un évènement se produise en fonction d'un évènement qui s'est déjà produit.

Par exemple, dans un jeu de cartes, la probabilité de piger une reine est de 4/52.

Par contre, si on sait d'avance que la carte est un personnage, la question devient: Probabilité que la carte soit une reine SACHANT que c'est un personnage. Puisqu'il n'y a que roi, valet ou reine, la probabilité est de 1/3.

**Algorithme utilisé pour la classification de spam:**
- Au lieu de se demander: Quelle est la probabilité que ce courriel soit du spam?
- On se demande plutôt: Quelle est la probabilité que ce courriel soit du spam, SACHANT qu'il y a déjà 1000 courriels identifiés comme spam qui ont déjà été reçus de cette adresse?

## Principaux algorithmes non-supervisés

Lors de la phase d'apprentissage, les données ne sont pas étiquetées. Cela veut dire que la machine doit apprendre sans savoir à quel groupe (i.e. Chien ou chat) appartient une donnée).

L'algorithme doit déterminer des groupes d'appartenance (cluster) elle-même.

### K-Moyennes (K-Means)

On indique à l'algorithme le nombre de clusters à trouve et celui-ci détermine des centroïdes (un par cluster) autour desquels il est possible de regrouper les données. Ces regroupements s'effectuant en calculant la distance de chaque observation par rapport à un point central de regroupement appelé centroïde et permettant ainsi de classer les observations en plusieurs groupes de façon automatique.

Ici, on a demandé 2 clusters.

### Mean-Shift

Basé sur une notion de "fenêtre coulissante" parcourant le jeu d'observations à la recherche de zones ayant une densité d'observations concentrée autour du centre de la fenêtre. Voici son fonctionnement dans un jeu d'observations.

L'algorithme analyse ensuite les observations contenues dans son rayon d'analyse et déplace la fenêtre vers des régions de densité plus élevée. Ce déplacement se réalise en positionnant le point central de la fenêtre vers la moyenne des points qu'elle contient.

Ce processus est répété jusqu'à ce que le nombre d'observations (la densité) contenues dans la fenêtre d'analyse soit fixe, définissant ainsi un cluster.

La principale différence avec l'algorithme du K-Mean vu précédemment est que nous n'avons pas besoin d'indiquer à la machine combien de clusters elle doit trouver. Ces groupes étant créés de façon automatique par la notion de densité.

### DBSCAN (Density Based Spatial Clustering of Application with Noise)

## Résumé

| Algorithme | Apprentissage supervisé - regression | Apprentissage supervisé - catégorisation | Apprentissage non supervisé |
|------------|-------------------------------------|------------------------------------------|----------------------------|
| Regression linéaire univariée | X | | |
| Régression linéaire multiple | X | | |
| Régression polynomiale | X | | |
| Régression logistique | | X | |
| Arbres de décision | X | X | |
| Forêt aléatoire | X | X | |
| Machine à vecteurs de support | | X | |
| KNN | | X | |
| Naive Bayes | | X | |
| K-moyennes | | | X |
| Mean-shift | | | X |
| DBSCAN | | | X |

**Notes importantes:**
- Ce n'est qu'une petite partie des algorithmes qui existent.
- Un bon scientifique des données développe une intuition des algorithmes qui sont le plus adaptés à son problème.
- La machine "apprend", mais il lui faut un bon professeur. Comme vous ;)

## Bibliographie

- Vannieuwenhuyze, Aurélien. Intelligence artificielle vulgarisée, ENI, 2019. 434 p.
- Wikipédia