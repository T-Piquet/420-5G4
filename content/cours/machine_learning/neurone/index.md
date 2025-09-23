+++
title = "Les réseaux de neurones"
weight = 30
draft = true
+++


## Perceptron

En **1957**, **Frank Rosenblatt** propose un algorithme d'apprentissage supervisé nommé le **Perceptron**. Aujourd'hui appelé "neurone formel", cet algorithme permettait de classifier des données **linéairement séparables** (définition à venir).

Son attrait est sa conception basée sur les **sciences cognitives**.

---

## Biologie cognitive

Notre cerveau est composé de **86 à 100 milliards de neurones** dont le rôle est d'acheminer et de traiter des messages dans notre organisme.

### Types de neurones :

- Certains neurones ont un rôle dédié aux **perceptions des sensations et aux mouvements**
- D'autres sont responsables des **fonctions automatiques** de notre corps (digestion, respiration…)

### Le deuxième cerveau :

Il y a des **centaines de millions de neurones** dans le tube digestif, que l'on surnomme maintenant le **deuxième cerveau**. La santé mentale est donc directement reliée à ce qu'on mange.

### Structure biologique d'un neurone :

Biologiquement, un neurone est une **cellule**, composée :

- **D'un noyau**
- **De plusieurs points d'entrée** de l'information
- **D'un chemin de sortie** de l'information appelé **axone**, pouvant atteindre une longueur d'un mètre
- **Des terminaisons axonales** également appelées **synapses** connectées aux autres neurones

---

## Le neurone

### Communication neuronale

La communication entre neurones s'opère par l'échange de **messages sous forme de variation de tension électrique**. Un neurone peut recevoir plusieurs messages de la part d'autres neurones auxquels il est connecté.

### Processus d'activation

Lorsqu'un neurone reçoit plusieurs messages, il effectue la **somme des influx nerveux reçus** puis, si cette somme dépasse un **certain seuil**, il **s'active** et transmet à son tour un message via son axone aux neurones connectés à celui-ci.

Pour une action donnée, un ensemble de neurones s'active alors que d'autres restent inactifs, car un **chemin s'est créé** entre l'action et l'activation neuronale.

---

## Neurone et perceptron

Le perceptron va se caractériser par une **couche de neurones en entrée** et un **neurone en sortie**.

### Correspondance biologique ↔ artificielle

|Neurone biologique|Neurone artificiel|
|---|---|
|**Dendrites**|Entrées (input)|
|**Synapses**|Poids|
|**Axone**|Sortie (output)|
|**Activation**|Fonction d'activation|

---

## Données linéairement séparables

Le **perceptron simple couche** ou **neurone formel** n'est en mesure de classifier que des données **linéairement séparables**.

- Il faudra **plusieurs couches** pour traiter de données plus complexes
- Des données linéairement séparables sont celles pouvant être **séparées par une droite**

_Voir les exemples des diapositives suivantes :_

---

## Fonctions logiques ET et OU

### Fonction ET

|A|B|A ET B|
|---|---|---|
|0|0|FAUX|
|0|1|FAUX|
|1|0|FAUX|
|1|1|VRAI|

### Fonction OU

|A|B|A OU B|
|---|---|---|
|0|0|FAUX|
|0|1|VRAI|
|1|0|VRAI|
|1|1|VRAI|

**Statut :** ✅ **Linéairement séparables**

---

## Fonction logique XOR (OU exclusif)

### OU EXCLUSIF (XOR)

|A|B|A XOR B|
|---|---|---|
|0|0|FAUX|
|0|1|VRAI|
|1|0|VRAI|
|1|1|FAUX|

**Statut :** ❌ **Non-linéairement séparable**

---

## Fonction d'activation

L'activation d'un neurone est déclenchée en fonction d'un **seuil**.

### Processus en deux étapes :

1. **Préactivation :** Faire la somme des produits des poids qui arrivent au neurone
2. **Activation :** Une fonction d'activation va déterminer si le neurone s'active ou non

---

## Fonction de seuil binaire

Cette fonction retourne une valeur égale à **0 ou 1**.

### Exemple pratique :

- **Somme pondérée :** 0,8
- **Seuil défini :** 0,5
- **Résultat :** Comme 0,8 > 0,5, la fonction renvoie **1** (le neurone s'active)
- Si la valeur était < 0,5, la fonction d'activation renverrait **0**

### Calcul détaillé :

|Valeur en entrée|Poids lié à l'entrée|Valeur de l'entrée × valeur du poids|
|---|---|---|
|2|0,2|0,4|
|1|0,1|0,1|
|3|0,1|0,3|
||**Total :**|**0,8**|

---

## Fonction sigmoïde

La prédiction que nous obtenons est rarement égale à 0 ou 1, mais plutôt à des **valeurs numériques comprises entre 0 et 1** (0,50, 0,99…) exprimant un **pourcentage de probabilité**.

La **fonction Sigmoïde** a des **changements de valeurs entre 0 et 1 plus progressifs**.

---

## La fonction ReLU (Rectified Linear Unit)

L'apprentissage d'un neurone consiste en la **mise à jour des poids sur plusieurs itérations**.

La **fonction ReLU**, sans rentrer dans les détails, **facilite cette mise à jour** en palliant certains problèmes des autres fonctions.

---

## La fonction softMax

La **fonction softMax** permet de faire un **classement entre plus de deux classes**.

### Exemple :

|Classe|Probabilité|
|---|---|
|Animal|0,01|
|Fruit|**0,95**|
|Véhicule|0,04|

---

## La rétropropagation de l'erreur

La particularité des réseaux de neurones est qu'ils **apprennent de leurs erreurs**.

### Phase de propagation

L'étape consistant à réaliser la **somme pondérée des entrées** et à utiliser une **fonction d'activation** pour obtenir une valeur de prédiction est appelée la **phase de propagation**. Car nous partons des points d'entrées du neurone artificiel vers son point de sortie pour réaliser ces calculs.

### Calcul de l'erreur

Une fois la prédiction réalisée, nous allons **comparer la prédiction réalisée** par le neurone artificiel avec la **prédiction attendue** en faisant la différence entre la valeur attendue et la valeur prédite. En faisant cela, nous venons de calculer l'**erreur de prédiction**.

### Rétropropagation

Une fois cette erreur obtenue, nous allons à présent **parcourir le neurone en sens inverse** (de la sortie vers les entrées) afin de prendre en compte l'erreur commise lors de la prédiction dans l'apprentissage en **ajustant les valeurs des différents poids**. Cette phase est appelée la **rétropropagation de l'erreur**.

---

## Les fonctions de perte (Loss function)

Une **fonction de perte**, ou **Loss function**, est une fonction qui évalue l'**écart entre les prédictions réalisées** par le réseau de neurones et les **valeurs réelles** des observations utilisées pendant l'apprentissage.

### Principe d'optimisation :

- Plus le résultat de cette fonction est **minimisé**, plus le réseau de neurones est **performant**
- Sa minimisation se fait en **ajustant les différents poids** du réseau de neurones
- L'objectif est de **réduire au minimum l'écart** entre la valeur prédite et la valeur réelle pour une observation donnée

---

## Le biais, un neurone particulier

Le **biais** permet de **forcer l'activation d'un neurone**, si les entrées seules ne le permettent pas.

---

## Exemple pratique : Prédire l'admission

L'admission dans une université dépend de la **réussite ou non de certains examens d'entrée**. Le tableau ci-dessous regroupe différents cas d'admissions et de refus en fonction de la réussite ou non aux examens en mathématiques et informatique.

Le neurone tentera de **prédire si oui ou non un étudiant est accepté** selon ses résultats d'examen.

**L'exemple est simple :** c'est au bout du compte la **fonction ET**

### Données d'entraînement :

|Réussite à l'examen de mathématiques|Réussite à l'examen d'informatique|Admis|
|---|---|---|
|OUI|NON|NON|
|OUI|OUI|**OUI**|
|NON|OUI|NON|
|NON|NON|NON|

---

## Initialisation du perceptron

Nous allons initialiser notre perceptron avec :

- **Une couche de deux neurones en entrée** correspondant chacun à la réussite aux examens
- **Un neurone de sortie** qui permettra de classifier l'étudiant en tant qu'admis ou refusé dans l'université
- **En complément :** un autre neurone appelé **biais (seuil)** qui a pour but de contrôler la prédisposition du neurone à s'activer ou non et qui prendra toujours la **valeur 1**

### Notation des poids :

- **W11, W21 et Wb**
- **W** ayant pour signification **Weight (Poids)** suivi du numéro du neurone et du numéro de la couche
- **W11** se lit : poids du premier neurone de la première couche
- **W21** : poids du deuxième neurone de la première couche
- **Wb** signifiant : poids (Weight) du biais (bias en anglais)

---

## L'apprentissage : 1- Initialisation des poids

La première étape consiste à **initialiser les poids**. Cette initialisation se fait de façon **aléatoire dans un intervalle compris entre -1 et 1** sauf pour le biais qui prendra la **valeur 0**.

_Des fonctions existent pour "mieux" choisir les poids, mais nous les laisserons aux experts ;)_

### Observation importante :

On constate dans notre cas que le **poids W21 est plus important** que les autres, cela signifie donc que la valeur contenue dans le neurone X2 a plus d'importance que les autres dans la prédiction.

**Attention :** Ce qui est peut-être faux, car cette valeur est uniquement **choisie au hasard**. Cela ne signifie pas non plus que c'est cette valeur qui sera à la fin de l'apprentissage considérée comme importante, car comme nous l'avons vu, le neurone va **apprendre de ses erreurs** et ce poids va s'ajuster au fur et à mesure de l'apprentissage.

---

## 2- Chargement des données : Première observation

On "fait passer" la **première observation** dans le neurone.

- **X1 = 1**
- **X2 = 0**

### Calcul des sommes pondérées (préactivation) :

_[Les calculs détaillés seraient normalement présentés ici avec les valeurs des poids initialisés]_

---

## 3- Utilisation d'une fonction d'activation

La fonction d'activation que nous allons utiliser est la **sigmoïde** ou encore appelée **courbe en S**.

La fonction est appliquée à la **somme de la préactivation**.

---

## 4- Calcul de l'erreur commise lors de l'apprentissage

- **Prédiction réalisée :** 0.45860596
- **Valeur attendue :** 0
- **Calcul de l'erreur :** Différence entre la valeur attendue et la prédiction réalisée

**Erreur = 0 - 0.45860596**  
**Erreur = -0.45860596**

---

## 5- Ajustement des poids

Le perceptron va **apprendre de ses erreurs** en ajustant les différents poids de chaque entrée jusqu'à atteindre une **convergence**.

### Calcul du gradient :

La rétropropagation s'effectue en calculant le **gradient** :

**Gradient = -1 × ERREUR × PREDICTION × (1-PREDICTION) × VALEUR_ENTREE**

Avec nos valeurs :

- **Erreur** = -0.45860596
- **Prédiction** = 0.45860596
- **Valeur d'entrée X1** = 1

**Gradient = -1 × (-0.45860596) × 0.45860596 × (1-0.45860596) × 1**  
**Gradient = 0,11386568**

### Utilisation du taux d'apprentissage :

Une fois le gradient déterminé, nous utilisons le **taux d'apprentissage** qui va nous permettre de progresser dans la descente. Nous avons choisi de façon arbitraire un **taux d'apprentissage de 0,1**.

_En pratique, des algorithmes ou l'expérience permettent de choisir ce taux._

**Valeur_ajustement_W11 = 0.11386568 × 0,1 = 0,01138657**

**Nouveau_W11 = W11 - Valeur_ajustement_W11**  
**Nouveau_W11 = -0.165955990594852 - 0,01138657 = -0.15456942**

### Ajustement de tous les poids :

Nous devons procéder de la même façon pour ajuster le **poids W21** et le **poids du biais**.

|Paramètre|X1|X2|BIAIS|
|---|---|---|---|
|**VALEUR**|1|0|1|
|**POIDS**|-0,16595599|0,44064899|0|
|**ERREUR**|-0,45860596|-0,45860596|-0,45860596|
|**PREDICTION**|0,45860596|0,45860596|0,45860596|
|**GRADIENT**|-0,11386568|0|-0,11386568|
|**TAUX APPRENTISSAGE**|0,1|0,1|0,1|
|**VALEUR_AJUSTEMENT**|-0,01138657|0|-0,01138657|
|**NOUVEAU POIDS**|-0,15456942|0,44064899|0,01138657|

---

## Ensuite?

Ceci constituait une **première itération** du processus d'apprentissage.

### Processus itératif :

- Il faut **recommencer tant et aussi longtemps** que l'erreur n'a pas été minimisée
- Si la sortie prévue est 0, on doit obtenir un nombre **le plus près possible de 0**

_Voir la suite dans **perceptron.py**_

---

## Bibliographie

**Vannieuwenhuyze, Aurélien.** _Intelligence artificielle vulgarisée_, ENI, 2019. 434 p.