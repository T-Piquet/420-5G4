+++
title = "Analyse d'image"
weight = 130
draft = true
+++

Dans ce laboratoire, vous allez entraîner un modèle à la classification d'images. La partie théorique est assez dense, essayez d'en dégager une idée générale par rapport à ce que nous avons vu dans le cours.

Pas besoin de faire la partie où on entraîne le modèle avec plus d'image, ni d'enregistrer le modèle. Le modèle final se trouve sur Moodle.

Pour me montrer que vous avez bien fait ce laboratoire, vous prenez une dizaine de captures d'écran de votre progression. Ensuite, vous testez votre modèle avec 3 images trouvées sur Internet et vous prenez une capture de la prédiction du modèle.

Ce laboratoire compte pour 5% de votre session.

Le texte et l'exemple proviennent du livre :
Vannieuwenhuyze, Aurélien. Intelligence artificielle vulgarisée, ENI, 2019. 434 p.

## Différence entre détection et classification d'images

Il est important de faire la distinction entre une détection et une classification d'images. Savoir détecter un cercle, un triangle, une forme, voire un visage, ne relève pas forcément du domaine de l'intelligence artificielle (bien que certains algorithmes en soient capables). En effet, ces tâches sont confiées à des algorithmes de traitement d'images que nous aurons l'occasion de manipuler dans le chapitre suivant.

Cependant, être en mesure de reconnaître une voiture d'un vélo, de réaliser de la reconnaissance faciale relève de l'intelligence artificielle où des algorithmes d'apprentissage ont été entraînés pour reconnaître (classifier) les éléments.

Néanmoins, la détection de formes dans une image peut aider l'algorithme de classification, en ce sens où l'on peut facilement extraire un visage d'une photo ou d'une vidéo et le proposer à un algorithme de classification capable alors de réaliser de la reconnaissance faciale.

## Des réseaux de neurones convolutifs pour classifier des images

Pour classifier des images, nous allons utiliser un réseau de neurones un peu particulier : le réseau de neurones convolutifs ou encore appelé CNN (Convulational Neural Network ou encore ConvNet).

Cet algorithme d'apprentissage peut être assimilé à un millefeuille composé de plusieurs couches. Les dernières couches (hautes du millefeuille) sont constituées de réseaux de neurones tels que nous les avons découverts dans les chapitres précédents, dont les données en entrée sont issues des couches précédentes appelées couches de convolutions dont nous allons à présent découvrir le principe.

### 1. De nombreuses données d'apprentissage nécessaires

Pour que le réseau de neurones puisse réaliser une bonne classification d'images, il faut bien entendu lui donner une base d'apprentissage. Mais lorsqu'il s'agit d'images, leur nombre peut vite devenir impressionnant.

En effet, en tant qu'humain, notre cerveau est capable de réaliser la classification entre un chat et un chien, qu'il soit noir, blanc, de face, de profil, de dos, en plein jour, dans la pénombre… c'est-à-dire dans différents environnements et positions possibles ! Ce qui vous laisse imaginer le nombre d'images nécessaires.

Si vous souhaitez vous lancer dans un projet personnel de classification d'images, cela vous permet également d'apprécier le travail de photographie à réaliser.

Heureusement pour nous, des jeux d'observations sont disponibles sur Internet pour nous entraîner.

Pour pouvoir réaliser son apprentissage, la machine va devoir manipuler l'image. Nous entrons donc dans le domaine du traitement d'image qui comme vous le savez sans doute est gourmand en ressources matérielles. Par conséquent, réaliser la classification d'images nécessite un temps important pour la création du jeu d'apprentissage et un investissement dans le matériel pour réaliser l'apprentissage.

### 2. Un outil pour illustrer nos propos

Les réseaux de neurones convolutifs sont composés de plusieurs couches de traitements que l'on peut facilement schématiser. Grâce à Adam W Harley, nous pouvons aller plus loin en visualiser l'intérieur du réseau de neurones convolutifs à l'aide d'un outil interactif disponible à cette adresse : (https://adamharley.com/nn_vis/cnn/3d.html).

**Un outil de visualisation pour comprendre les réseaux de neurones convolutifs**

Le principe de cet outil est assez simple. En haut de la partie de gauche, nous allons dessiner un chiffre de 0 à 9 et charge à la machine de classifier ce dessin en tant que chiffre. Dans la partie de droite, nous pourrons visualiser toutes les étapes successives réalisées par la machine pour y parvenir. Chaque étape devant être considérée comme étant une couche de l'algorithme de classification.

Sur certaines résolutions d'écran, la partie de gauche n'est pas entièrement visible. Dans ce cas, il suffit de dézoomer grâce à l'option de zoom des navigateurs web.

### 3. L'image d'entrée

Les réseaux de neurones à convolution servent à classifier les images. Tout part donc d'une image source. Pour la créer, dessinons un chiffre entre 0 et 9 en haut de la partie de gauche et observons ce qui se passe dans la partie de droite.

La première chose que l'on observe est que notre image d'entrée (input layer) se trouve tout en bas de l'écran et se voit divisée en petits carrés. Ces carrés étant bien entendu les pixels de l'image.

Si l'on remonte petit à petit, on voit également que d'autres images sont apparues jusqu'à obtenir la prédiction du chiffre dessiné (1 pour notre cas).

### 4. Les caractéristiques

Voyons à présent la notion de caractéristique. Imaginons que nous cherchions à réaliser une classification d'une image comportant un lapin. L'objectif étant que lorsque nous présentons une image de lapin à notre machine, celle-ci nous indique qu'il s'agit d'un lapin ou non.

L'une des solutions nous venant intuitivement à l'esprit pour résoudre ce problème est de comparer pixel par pixel deux images, une image d'apprentissage et une image à classifier. Si les deux images correspondent, on peut alors affirmer qu'il s'agit d'un lapin.

Sauf que cela comporte un inconvénient, car il faut que l'image à classifier soit strictement identique à l'image de référence, ce qui est tout à fait impossible dans les cas réels d'application.

La solution pour résoudre ce souci va consister à capturer des caractéristiques dans l'image source (des morceaux d'images) et à les rechercher dans l'image à classifier. C'est ce que l'on appelle le principe de convolution que nous allons à présent découvrir.

### 5. La convolution

Comme nous venons de le voir, nous allons utiliser des caractéristiques d'une image pour essayer de les retrouver dans une autre image à classifier. Si l'image à classifier comporte un grand nombre de caractéristiques communes avec l'image source de classification, il y a de fortes probabilités que les images soient fortement similaires. La phase d'apprentissage va consister à extraire ces caractéristiques pour ensuite alimenter un réseau de neurones afin qu'il apprenne à faire le lien entre les caractéristiques de l'image source couplées à une labellisation (nom de l'objet à reconnaître). À l'issue de son apprentissage, le réseau de neurones sera en mesure de dire "J'ai appris que si je suis majoritairement en présence de ces caractéristiques alors, l'image que l'on me présente est un lapin".

Pour éclaircir ce concept, considérons une image ayant une dimension de 5 pixels sur 5 pixels et une caractéristique de 3 pixels sur 3 pixels. Cette caractéristique est également appelée filtre ou kernel. Les pixels noirs de l'image porteront la valeur 1, les blancs 0 et les gris -1.

La convolution va consister à appliquer le filtre sur l'ensemble de l'image afin d'en déduire une nouvelle image. Les quatre figures suivantes expliquent le procédé :

- On place le filtre en haut et à gauche de l'image.
- Pour chaque valeur de pixel de l'image se situant dans le filtre, on la multiplie par la valeur du pixel du filtre.
- On réalise la somme de ces produits.
- On se décale d'un pixel et on recommence le produit et la somme. Ce déplacement porte le nom de Stride et dans notre cas, a la valeur 1.

Ce processus étant à réaliser jusqu'à ce que l'ensemble de l'image soit filtré, donnant ainsi naissance à une nouvelle image plus petite que l'image d'origine et ayant de nouvelles valeurs. Ces valeurs ayant pour but de faire ressortir certaines caractéristiques de l'image.

Nous verrons lors de la mise en pratique que dans la phase de convolution nous allons spécifier une méthode d'activation. Dans la plupart des cas, nous choisirons la méthode ReLU, permettant de supprimer les valeurs négatives de l'image de convolution en les remplaçant par la valeur 0. Sans cette activation, les résultats d'apprentissage ne seraient pas ceux attendus.

On note qu'à la convolution n°8, la somme est plus importante que celle des autres convolutions. Cela est dû au fait que le filtre appliqué correspond parfaitement à la partie de l'image qui est en train d'être analysée, il y a donc un point de concordance.

Revenons à présent à notre outil de reconnaissance de chiffres. On peut observer qu'au-dessus de l'image d'entrée, il y a 6 autres images. Ces images sont issues de la convolution de 6 filtres. À droite, on trouve l'image issue du filtre n°1 et à gauche celle du filtre n°6. Les filtres appliqués sont d'une taille de 5 pixels * 5 pixels et sont bien entendu différents.

Si vous passez la souris sur un pixel de l'image issue de la convolution, vous pourrez voir à partir de quelle partie de l'image source celui-ci a été conçu.

**Principe de convolutions**

Comme nous venons de le voir, le nombre de filtres utilisés correspond aux caractéristiques à apprendre. Nous aurions donc tendance à dire que plus de filtres différents sont utilisés dans la phase d'apprentissage, plus cette phase d'apprentissage sera efficace ; cependant, cela peut entraîner un surapprentissage de l'algorithme et avoir l'effet inverse de celui escompté.

Malheureusement, il n'existe pas de méthode miracle permettant de déterminer la quantité de filtres à utiliser ainsi que leur dimension, il faut bien souvent définir ces valeurs de façon empirique.

Si on applique ce traitement de convolution sur notre image de lapin, on peut se rendre compte que le nombre de calculs peut vite devenir important si la taille de l'image est grande et si l'on multiplie le nombre de filtres. Ce calcul demandant alors beaucoup de ressources au niveau de processeur et de la carte graphique. Nous verrons que dans notre cas pratique, nous allons configurer des couches de convolutions à 128 filtres ayant une taille de 3 pixels par 3 pixels ! C'est pourquoi dans la plupart des cas, de petites images sont utilisées (28x28 pixels ou 32x32 pixels). Notons que certains fabricants de cartes graphiques (NviDia) se sont spécialisés dans la réalisation de matériel dédié au Deep Learning avec des produits dépassant les 2000 € pour les cartes les plus performantes.

Petit aparté technique : en termes de traitement d'image, il est préférable de travailler avec des images en niveau de gris. En effet, une image en couleur contient 3 couches de couleurs (rouge, vert et bleu), alors qu'une image en niveau de gris n'en contient qu'une. Cela améliore les temps de traitement, car au lieu de traiter 3 couches, nous ne devons en traiter qu'une seule.

### 6. Pooling

Maintenant que nous disposons d'une image filtrée, nous allons lui appliquer un nouveau traitement appelé **Pooling** permettant d'extraire les caractéristiques importantes issues de la convolution.

Ce traitement consiste à déplacer une fenêtre dans l'image issue de la convolution. Dans le cadre d'un MaxPooling, on recherche la valeur maximale contenue à l'intérieur de cette fenêtre, dans le cadre d'un Average Pooling, on calcule la moyenne des valeurs contenues dans la fenêtre et enfin dans le cadre d'un Pooling Stochastique, on retient une valeur en fonction d'estimations probabilistiques.

Reprenons l'image issue de notre convolution et appliquons-lui une fenêtre de pooling de 2 pixels sur 2 pixels avec un stride (déplacement) de 1 tout comme nous l'avons fait dans l'étape de convolution.

Comme nous pouvons le constater, à l'issue d'une convolution et d'un pooling, notre image source faisant 5x5 pixels se trouve réduite en une image de 2x2 tout en conservant les caractéristiques de l'image issue de la convolution.

Cette réduction de taille est notamment bénéfique aux différents calculs à venir.

Si l'on observe la couche de pooling dans l'outil de classification des chiffres dessinés manuellement, on constate que chaque couche de convolution donne lieu à un pooling. Le pooling utilisé pour chaque filtre est un MaxPooling d'une dimension de 2x2 avec un stride (déplacement) de deux.

### 7. Plusieurs couches de convolutions

Comme nous pouvons le constater dans l'outil de prédiction des chiffres dessinés manuellement, la couche de pooling vue précédemment est elle-même connectée à une couche de convolution, qui est aussi connectée à une couche de pooling.

Ce qui nous donne les couches de convolution suivantes :
- Une première couche de convolution composée de 6 filtres de dimension 5x5 avec un stride de 1
- Une couche de pooling de taille 2x2
- Une seconde couche de convolution composée de 16 filtres de dimension 5x5 avec un stride de 1
- Une couche de pooling de taille 2x2

L'objectif étant de réduire l'image tout en conservant les informations importantes.

Les paramètres des différentes couches utilisées dans l'outil de visualisation sont disponibles dans le document PDF "An Interactive Node-Link Visualization of Convolutional Neural Networks" rédigé par Adam W. Harley et téléchargeable à cette adresse : http://scs.ryerson.ca/~aharley/vis/harley_vis_isvc15.pdf

### 8. Mise à plat (Flatten)

À l'issue des différentes opérations de convolutions et de pooling, nous allons préparer les données pour qu'elles soient intégrables dans un réseau de neurones.

Cette étape de préparation consiste à "mettre à plat" les différentes images issues des opérations de pooling sous forme d'une seule colonne (ou ligne dans l'outil). Nous créons alors un vecteur.

### 9. L'apprentissage

Enfin, la dernière phase du réseau de neurones à convolution est l'apprentissage proprement dit à l'aide de couches de neurones totalement connectés ayant pour entrée la couche de mise à plat réalisée précédemment et pour sortie une prédiction.

Le fonctionnement de l'apprentissage est identique à celui que nous avons découvert dans le chapitre précédent : définition des poids, prédiction, rétropropagation…

En regardant les dernières couches de l'outil de prédiction, on peut voir le réseau de neurones permettant de prédire une probabilité par catégorie de chiffre (de 0 à 9).

Selon l'auteur de l'outil, le réseau de neurones est composé de 784 neurones en entrée, 300 neurones dans la première couche cachée, de 100 dans la seconde et 10 en sortie correspondant à chacun des différents chiffres.

### 10. Un schéma global qui résume tout

Pour résumer tout ce que nous venons de voir, nous pouvons nous appuyer sur un schéma très populaire représenté par la figure suivante (https://www.mathworks.com/videos/introduction-to-deep-learning-what-are-convolutional-neural-networks--1489512765771.html) où l'on retrouve toutes les étapes d'un réseau de neurones à convolution.

## Un cas pratique autour de la mode

### 1. Présentation de Kaggle

Kaggle (www.kaggle.com) est le site de référence en termes de propositions de défis liés au Machine Learning. Ce site regorge de cas d'études et de challenges proposés par de grands groupes tels que McDonalds, Netflix… Chacun d'entre nous peut tenter de résoudre ces différents défis en proposant ses propres modèles de prédiction. Ce site permet également d'apprendre énormément sur les techniques liées au Machine Learning, car chaque proposition de solution soumise par les participants aux différents défis est visible, commentée et peut ainsi être étudiée. Ce site est entièrement gratuit, alors pourquoi s'en priver ?

C'est à partir de ce site que nous allons réaliser notre cas pratique qui permettra d'illustrer les principes de codage d'un réseau de neurones à convolution.

### 2. Parlons un peu de Keras

Dans le chapitre précédent, nous avons utilisé la librairie TensorFlow. Il existe un module complémentaire à cette librairie appelé Keras se voulant avant tout facile d'utilisation. Cette facilité se trouve notamment dans la phase de création et de paramétrage des différents modèles d'apprentissage, sans oublier qu'il se prête très bien à l'utilisation de réseaux de neurones à convolution, car il possède nativement les fonctions pour y parvenir.

### 3. Classifier des robes, pulls et chaussures ?

L'un des cas d'étude les plus utilisés dans la mise en pratique des réseaux de neurones convolutifs est la classification de lettres manuscrites à l'aide de la collection d'observations MNIST (Mixed National Institute of Standards and Technology).

Cependant, en 2018, Zalando a publié sa propre collection d'images nommée Zalando-MNIST. Cette collection d'images ayant pour but de permettre à des algorithmes de s'entraîner en la classification d'objets de mode : pull, robe, sac… C'est cette collection que nous allons utiliser pour notre cas pratique.

Au-delà de l'aspect très concret du projet, la phase d'apprentissage de ce cas d'étude peut être exécutée par la plupart des ordinateurs. En effet, comme nous l'avons évoqué en début de chapitre, la classification d'images requiert des performances accrues en termes de mémoire, de puissance processeur et de performance de la carte graphique afin d'obtenir de bons résultats et rapidement.

Il est également possible d'utiliser le Cloud en louant des machines virtuelles situées sur des serveurs dédiés à l'intelligence artificielle, comme le propose Amazon. Ces machines peuvent alors être configurées en termes de puissance en fonction du projet à réaliser.

Nous vous invitons à présent à télécharger les données disponibles sur Moodle (fichiersLab3) puis à créer un nouveau projet Python dans lequel il sera nécessaire de créer un dossier datas et d'y déposer l'ensemble des données précédemment téléchargées.

### 4. De quelles données disposons-nous ?

Avant de nous lancer dans toute phase d'apprentissage, nous devons connaître les données dont nous disposons. Comme nous cherchons à classifier des images, nous devrions donc être en possession de quelques-unes pour réaliser l'apprentissage. Mais visiblement, nous ne disposons pas de fichier image tel que nous avons l'habitude d'en rencontrer. En effet, pas de fichier JPEG ni de PNG.

Cependant, si nous ouvrons le fichier `fashion-mnist_train.csv`, nous pouvons nous apercevoir que celui-ci contient des observations ayant pour features :
- Un label
- Des pixels numérotés de 1 à 784 ayant des valeurs différentes

Voyons à présent ce que nous dit la documentation de ce jeu d'observations disponible sur le site de Kaggle (https://www.kaggle.com/plarmuseau/zalando-image-classifier/data) :
- Le jeu d'observations comporte 60 000 images d'apprentissage et 10 000 images de test.
- Chaque image a une hauteur de 28 pixels et une largeur de 28 pixels, pour un total de 784 pixels.
- Chaque pixel est associé à une seule valeur de pixel, indiquant la luminosité de ce pixel. Cette valeur de pixel est un entier compris entre 0 et 255.
- Les ensembles de données d'entraînement et de tests comportent 785 colonnes.
- La première colonne est constituée des labels de classe et représente l'article vestimentaire. Le reste des colonnes contient les valeurs des pixels de l'image associée.

Toujours à partir de la documentation, nous pouvons déterminer les différents labels :
- 0 - T-shirt/haut
- 1 - Pantalon
- 2 - Pull
- 3 - Robe
- 4 - Manteau
- 5 - Sandales
- 6 - Chemise
- 7 - Baskets
- 8 - Sac
- 9 - Bottes de cheville

À partir de ces informations, nous pouvons donc affirmer que nos images tant attendues sont présentes dans ce fichier sous forme de valeurs par pixel.

Afin de nous en assurer, nous allons essayer d'afficher la première image.

```python
import pandas as pnd
import numpy as np

#Définition de la longueur et de la largeur de l'image
LONGUEUR_IMAGE = 28
LARGEUR_IMAGE = 28

#Chargement des images
observations_entrainement = pnd.read_csv('datas/fashion-mnist_train.csv')

#On exclut la première colonne (les labels) pour constituer un tableau de pixels
X = np.array(observations_entrainement.iloc[:, 1:])

from matplotlib import pyplot as plt
premiereImage = X[0]
premiereImage = premiereImage.reshape([LONGUEUR_IMAGE, LARGEUR_IMAGE])
plt.imshow(premiereImage)
plt.show()
```

Après avoir importé les modules Pandas et Numpy, nous avons spécifié les dimensions de l'image afin de les utiliser ultérieurement à divers endroits de notre code.

Nous avons ensuite chargé les images en mémoire dans une variable à l'aide du module Pandas et avons exclu la première colonne pour constituer un tableau ne contenant que les données des images (les pixels). La première image a ensuite été recherchée dans le tableau puis formatée (reshape) pour obtenir une taille de 28 px sur 28 px pour enfin être affichée à l'aide du module matplotlib.

### 5. Préparation des données d'apprentissage

Maintenant que nous avons une petite idée des données que nous allons utiliser, il nous faut les préparer pour que celles-ci soient exploitables par notre réseau de neurones.

La première étape va consister à créer nos jeux d'apprentissage et jeux de tests comme suit :

```python
import pandas as pnd
import numpy as np
from sklearn.model_selection import train_test_split
# (Installer le package scikit-learn)

#Définition de la longueur et de la largeur de l'image
LONGUEUR_IMAGE = 28
LARGEUR_IMAGE = 28

#Chargement des données d'entrainement
observations_entrainement = pnd.read_csv('datas/fashion-mnist_train.csv')

#On ne garde que les features "pixels"
X = np.array(observations_entrainement.iloc[:, 1:])

#On crée des catégories à l'aide du module Keras
import tensorflow as tf # (Choisir la version 2.11.0)
import keras
y = keras.utils.to_categorical(np.array(observations_entrainement.iloc[:, 0]))

#Répartition des données d'entrainement en données d'apprentissage et données de validation
#80% de donnée d'apprentissage et 20% de donnée de validation
X_apprentissage, X_validation, y_apprentissage, y_validation = train_test_split(X, y, test_size=0.2, random_state=13)
```

Par ces quelques lignes de code, nous venons donc de créer notre jeu d'apprentissage composé de données d'apprentissage et de données de validation. À noter l'utilisation du module Keras et de la fonction `to_categorical` qui permet de créer un tableau binaire des différentes catégories.

Dans notre exemple, nous disposons de 10 catégories soit un tableau de 10 valeurs possibles : `[0,0,0,0,0,0,0,0,0,0]`

La première image de notre jeu de données porte le numéro 2 dans sa feature label, nous allons donc mettre un 1 à la troisième position (la première correspondant à la catégorie portant le numéro 0) :
`[0,0,1,0,0,0,0,0,0,0]`

La seconde image a pour label le numéro 9 ce qui nous donne le tableau suivant :
`[0,0,0,0,0,0,0,0,0,1]`

Ce processus est ainsi réalisé pour chaque observation afin de constituer un tableau global :
`[[0,0,1,0,0,0,0,0,0,0], [0,0,0,0,0,0,0,0,0,1]…]`

L'étape suivante va consister à reformater toutes les données des images au format 28 * 28 et à transformer les valeurs de chaque pixel dans une plage de valeurs comprise entre 0 et 1. Cette transformation est une mise à l'échelle de ces valeurs des pixels (scaling) en divisant chaque valeur de pixel par 255 (valeur maximale d'un pixel).

```python
# On redimensionne les images au format 28*28 et on réalise un scaling sur les données des pixels
X_apprentissage = X_apprentissage.reshape(X_apprentissage.shape[0], LARGEUR_IMAGE, LONGUEUR_IMAGE, 1)
X_apprentissage = X_apprentissage.astype('float32')
X_apprentissage /= 255
```

On réalise ensuite les mêmes opérations sur les données de validation :

```python
X_validation = X_validation.reshape(X_validation.shape[0], LARGEUR_IMAGE, LONGUEUR_IMAGE, 1)
X_validation = X_validation.astype('float32')
X_validation /= 255
```

### 6. Préparation des données de tests

Les données de tests vont nous permettre de vérifier l'efficacité de notre modèle d'apprentissage. Ces données doivent donc être préparées de la même façon que les données d'apprentissage :

```python
#Preparation des données de tests
observations_test = pnd.read_csv('datas/fashion-mnist_test.csv')
X_test = np.array(observations_test.iloc[:, 1:])
y_test = tf.keras.utils.to_categorical(np.array(observations_test.iloc[:, 0]))
X_test = X_test.reshape(X_test.shape[0], LARGEUR_IMAGE, LONGUEUR_IMAGE, 1)
X_test = X_test.astype('float32')
X_test /= 255
```

### 7. Un réseau avec une seule couche de convolution

Nous allons effectuer un premier apprentissage avec un réseau de neurones ne comportant qu'une seule couche de convolution.

#### a. Configuration

La configuration de notre premier réseau de neurones à convolution va comporter les éléments suivants :
- Une couche de convolution de 32 filtres de taille 3x3 avec une fonction d'activation de type ReLU
- Un pooling composé d'un filtre de 2x2
- Une phase de flatten (mise en colonne des résultats du pooling)
- Un réseau de neurones complètement connecté de 128 neurones avec une fonction d'activation de type ReLU
- Un dernier réseau de neurones complètement connecté comportant 10 neurones et une fonction d'activation de type Softmax correspondant aux 10 catégories d'images à prédire

Voici à présent le code associé à cette configuration :

```python
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten
from keras.layers import Conv2D, MaxPooling2D

#On spécifie les dimensions de l'image d'entrée
dimentionImage = (LARGEUR_IMAGE, LONGUEUR_IMAGE, 1)

#On crée le réseau de neurones couche par couche
reseauNeurone1Convolution = Sequential()

#1- Ajout de la couche de convolution comportant
# 32 filtres de de taille 3x3 (Kernel) parcourant l'image
# Une fonction d'activation de type ReLU (Rectified Linear Activation)
# Une image d'entrée de 28px * 28 px
reseauNeurone1Convolution.add(Conv2D(32, kernel_size=(3, 3), activation='relu', input_shape=dimentionImage))

#2- Définition de la fonction de pooling avec une fenêtre de 2px sur 2 px
reseauNeurone1Convolution.add(MaxPooling2D(pool_size=(2, 2)))

#3- Ajout d'une fonction d'ignorance
reseauNeurone1Convolution.add(Dropout(0.2))

#5 - On transforme en une seule ligne
reseauNeurone1Convolution.add(Flatten())

#6 - Ajout d'un réseau de neurones composé de 128 neurones avec une fonction d'activation de type ReLU
reseauNeurone1Convolution.add(Dense(128, activation='relu'))

#7 - Ajout d'un réseau de neurones composé de 10 neurones avec une fonction d'activation de type softmax
reseauNeurone1Convolution.add(Dense(10, activation='softmax'))
```

La notion de Drop Out précisée dans le code consiste à ignorer certains neurones dans les phases d'apprentissage et de rétropropagation afin d'éviter le surapprentissage.

#### b. Compilation, apprentissage et test

Maintenant que notre réseau est configuré, nous pouvons le compiler et réaliser l'apprentissage :

```python
reseauNeurone1Convolution.compile(loss=keras.losses.categorical_crossentropy,
                                  optimizer=tf.keras.optimizers.Adam(),
                                  metrics=['accuracy'])
```

La compilation se fait en précisant les paramètres suivants :
- La fonction de minimisation de l'erreur
- L'optimiseur utilisant l'algorithme Adam (méthode de calcul de descente de gradient)
- Et la valeur mesurée, dans notre cas la précision

Avant d'exécuter notre code, nous allons paramétrer l'apprentissage comme suit :
- 10 passages complets du jeu de données à travers le réseau de neurones (epoch)
- 256 images traitées à la fois (batch_size)
- Un affichage des logs d'apprentissage dans la console (verbose=1)
- La validation du modèle est basée sur les images et labels de validation définis plus en amont de ce chapitre (80 % de données d'apprentissage et 20 % de données de validation)

```python
historique_apprentissage = reseauNeurone1Convolution.fit(X_apprentissage, y_apprentissage,
                                                         batch_size=256,
                                                         epochs=10,
                                                         verbose=1,
                                                         validation_data=(X_validation, y_validation))
```

En d'autres termes, sachant que notre jeu d'apprentissage comporte 60 000 images et que nous n'en avons retenu que 80 % pour la phase d'apprentissage, cette dernière se réalisera donc sur 48 000 images.

Comme il nous est impossible de passer en une seule fois les 48 000 images à travers le réseau de neurones, nous devons les envoyer par paquets à l'aide d'un batch. Selon notre paramétrage, le batch enverra 256 images à travers le réseau de neurones. Par conséquent, pour réaliser un passage complet de l'ensemble des images dans le réseau de neurones (epoch), il nous faudra donc 187 itérations (48 000 / 256). Mettons ce chiffre de côté, nous verrons qu'il nous sera utile un peu plus loin dans ce chapitre.

Nous ajoutons également l'évaluation du modèle d'apprentissage sur les données de tests afin de déterminer la précision d'apprentissage :

```python
evaluation = reseauNeurone1Convolution.evaluate(X_test, y_test, verbose=0)
print('Erreur:', evaluation[0])
print('Précision:', evaluation[1])
```

Et terminons par l'affichage d'un graphique où figureront les courbes de précision et d'erreur après chaque passage complet du jeu de données à travers le réseau de neurones (epoch).

```python
from matplotlib import pyplot as plt

#Données de précision (accuracy)
plt.plot(historique_apprentissage.history['accuracy'])
plt.plot(historique_apprentissage.history['val_accuracy'])
plt.title('Précision du modèle')
plt.ylabel('Précision')
plt.xlabel('Epoch')
plt.legend(['Apprentissage', 'Test'], loc='upper left')
plt.show()

# Plot training & validation loss values
plt.plot(historique_apprentissage.history['loss'])
plt.plot(historique_apprentissage.history['val_loss'])
plt.title('Erreur')
plt.ylabel('Erreur')
plt.xlabel('Epoch')
plt.legend(['Apprentissage', 'Test'], loc='upper left')
plt.show()
```

Nous pouvons à présent lancer l'apprentissage !

À noter que la phase d'apprentissage prend environ 5 minutes dans notre cas avec un PC équipé d'un processeur Intel Core i5 2,6G GHz avec 8 Go de mémoire et une carte graphique Intel HD Graphics 620 équipée de 64 Mo de RAM. Ce temps peut donc varier en fonction de votre matériel.

#### c. Conclusion sur l'apprentissage

Une fois l'apprentissage terminé et notre modèle d'apprentissage constitué, nous obtenons les chiffres suivants sur notre jeu de tests (ceux-ci pouvant varier).

```
Erreur : 0.23872388958334922
Précision: 0.9154
```

Signifiant que nous avons une précision de classification de 91,54 % avec un taux d'erreur de 23,87 %.

Ces informations sont reprises dans les deux graphiques qui suivent où l'on constate une augmentation de la précision dans la phase d'apprentissage jusqu'à atteindre 93 % ainsi qu'une diminution de l'erreur. Ces deux informations étant tout à fait logiques.

#### d. Augmentation du nombre de données

Il se peut que dans notre jeu de données de tests, il existe des images dont notre jeu d'entraînement ne dispose pas. Cela influe donc sur la précision de classification de notre modèle.

La solution consiste donc à augmenter le nombre d'images de notre jeu d'apprentissage. Pour cela, nul besoin de rechercher des photos sur le Net, nous allons utiliser une fonction `ImageDataGenerator` du module Keras prévue à cet effet.

```python
from keras.preprocessing.image import ImageDataGenerator
generateur_images = tf.keras.preprocessing.image.ImageDataGenerator(rotation_range=8,
                                                                   width_shift_range=0.08,
                                                                   shear_range=0.3,
                                                                   height_shift_range=0.08,
                                                                   zoom_range=0.08)
```

Le principe de cette fonction est le suivant :

À partir d'une image contenue dans le jeu d'apprentissage, la fonction va procéder à des actions de rotation, de zoom, de translation de façon aléatoire afin de créer de nouvelles images. Voici les paramètres de cette fonction :
- `rotation_range` est l'angle de rotation de l'image compris entre 0 et 180.
- `width_shift` et `height_shift` sont les plages de translation verticale ou horizontale de l'image.
- `shear_range` est le niveau de cisaillement de l'image.
- `zoom_range` est le niveau de zoom de l'image.

Nous allons à présent générer de nouvelles images et procéder à un nouvel apprentissage.

```python
nouvelles_images_apprentissage = generateur_images.flow(X_apprentissage, y_apprentissage, batch_size=256)
nouvelles_images_validation = generateur_images.flow(X_validation, y_validation, batch_size=256)

historique_apprentissage = reseauNeurone1Convolution.fit_generator(nouvelles_images_apprentissage,
                                                                   steps_per_epoch=48000//256,
                                                                   epochs=50,
                                                                   validation_data=nouvelles_images_validation,
                                                                   validation_steps=12000//256,
                                                                   use_multiprocessing=False, 
                                                                   verbose=1)

evaluation = reseauNeurone1Convolution.evaluate(X_test, y_test, verbose=0)
print('Erreur :', evaluation[0])
print('Précision:', evaluation[1])
```

Pour notre nouvel apprentissage, nous utilisons la fonction `fit_generator` du module Keras au lieu de la fonction `fit` utilisée dans le précédent apprentissage. Cela est dû au fait que pour chaque sous-tâche d'apprentissage (batch) les images que nous utilisons sont différentes, car générées de façon aléatoire avec notre générateur d'image.

La fonction `fit` n'est pas en mesure de gérer ce type de changement à la volée, contrairement à la fonction `fit_generator` prévue à cet effet.

On note également une augmentation du nombre de passages complets du jeu de données à travers le réseau de neurones passant de 10 à 50 car nous disposons d'un nombre d'images plus important.

La fonction `fit_generator` peut être vue comme une boucle d'apprentissage qui n'a pas de fin. Afin que cette boucle s'arrête, nous devons lui indiquer le nombre d'itérations à effectuer par epoch, c'est le rôle du paramètre `steps_per_epoch` prenant la valeur 187 comme nous l'avions calculé lors du premier apprentissage.

Ainsi lorsque le nombre d'itérations sera atteint pour une epoch, l'epoch suivante sera déclenchée jusqu'à atteindre le nombre total d'epoch spécifiées, soit 50 dans notre cas.

**PAS BESOIN DE L'EXÉCUTER**

Nous pouvons à présent exécuter notre nouvel apprentissage et constater dans un premier temps que celui-ci prend beaucoup plus de temps ! (Environ 40 minutes contre les 5 minutes lors du précédent apprentissage). Cela vient du fait qu'en complément de l'apprentissage, de nouvelles images sont générées à chaque batch, ce qui nécessite des ressources matérielles plus importantes et ralentit donc l'ensemble du processus.

Mais en dépit de ce temps d'apprentissage, on peut s'apercevoir une petite amélioration de l'apprentissage frôlant les 92 %.

```
Erreur : 0.2299670210123062
Précision: 0.9175
```

Et une diminution du taux d'erreur entre la phase d'apprentissage et la phase de test. On peut donc considérer que ce modèle est plus performant que le précédent.

**PAS BESOIN DE SAUVEGARDER LE MODÈLE**

#### e. Sauvegarde du modèle

Maintenant que nous avons un modèle un peu plus performant, nous pouvons le sauvegarder afin de l'utiliser par la suite.

Pour cela, il convient de créer un nouveau répertoire dans le projet que nous nommerons "modele" qui sera chargé de contenir la définition modèle au format JSON et les différents poids issus de l'apprentissage seront quant à eux sauvegardés dans un fichier ayant pour extension H5. Ces deux fichiers pouvant être utilisés par la suite dans une application annexe.

```python
#Sauvegarde du modèle
# Serialisation du modèle 
model_json = reseauNeurone1Convolution.to_json()
with open("modele/modele.json", "w") as json_file:
    json_file.write(model_json)

# Serialisation des poids
reseauNeurone1Convolution.save_weights("modele/modele.h5")
print("Modèle sauvegardé !")
```

**PAS BESOIN DE FAIRE LE POINT 8**

### 8. Un modèle plus performant

Nous allons à présent utiliser un modèle plus complexe, mais qui offre de meilleures performances. Ce modèle comporte quatre couches de convolution définies comme suit :

```python
reseauNeurones4Convolution = Sequential()

reseauNeurones4Convolution.add(Conv2D(32, kernel_size=(3, 3), activation='relu', input_shape=dimentionImage))
reseauNeurones4Convolution.add(BatchNormalization())
reseauNeurones4Convolution.add(Conv2D(32, kernel_size=(3, 3), activation='relu'))
reseauNeurones4Convolution.add(BatchNormalization())
reseauNeurones4Convolution.add(MaxPooling2D(pool_size=(2, 2)))
reseauNeurones4Convolution.add(Dropout(0.25))

reseauNeurones4Convolution.add(Conv2D(64, kernel_size=(3, 3), activation='relu'))
reseauNeurones4Convolution.add(BatchNormalization())
reseauNeurones4Convolution.add(Dropout(0.25))

reseauNeurones4Convolution.add(Conv2D(128, kernel_size=(3, 3), activation='relu'))
reseauNeurones4Convolution.add(BatchNormalization())
reseauNeurones4Convolution.add(MaxPooling2D(pool_size=(2, 2)))
reseauNeurones4Convolution.add(Dropout(0.25))

reseauNeurones4Convolution.add(Flatten())
reseauNeurones4Convolution.add(Dense(512, activation='relu'))
reseauNeurones4Convolution.add(BatchNormalization())
reseauNeurones4Convolution.add(Dropout(0.5))

reseauNeurones4Convolution.add(Dense(128, activation='relu'))
reseauNeurones4Convolution.add(BatchNormalization())
reseauNeurones4Convolution.add(Dropout(0.5))

reseauNeurones4Convolution.add(Dense(10, activation='softmax'))
```

On note l'utilisation de la fonction `BatchNormalisation()` qui permet de normaliser les données. Dans les phases de mises à jour des poids, il se peut que les données soient trop petites ou trop grandes par rapport aux autres. Grâce à cette fonction, les valeurs seront normalisées, c'est-à-dire que leur moyenne sera proche de 0 et leur écart type proche de 1. Cette phase a aussi pour conséquence d'améliorer les performances de traitement.

Voici les résultats obtenus :

```
Temps d'apprentissage = 53044.6571731
Erreur : 0.19346623014211656
Précision: 0.9302
```

Soit 93 % de bonne classification. Mais cela a un coût, car avec la configuration de notre PC que nous vous avons présenté dans ce chapitre, la phase d'apprentissage a mis environ 8H00 !!

## À FAIRE - Utilisation du modèle avec de nouvelles images

Nous allons à présent utiliser le dernier modèle avec de nouvelles images.

Fort heureusement pour vous, nous avons réalisé une sauvegarde du modèle précédemment généré vous évitant ainsi d'attendre le temps de sa création. Libre à vous de le télécharger et de le placer dans le répertoire modèle du projet.

Nous vous invitons à créer un nouveau fichier Python que l'on nommera `classification.py`.

La première étape va être de charger le modèle comme suit :

*(Aller chercher le modèle sur Moodle et le mettre dans votre projet sur pyCharm)*

```python
#----------------------------
# CHARGEMENT DU MODELE
#----------------------------

#Chargement de la description du modèle
fichier_json = open('modele/modele_4convolutions.json', 'r')
modele_json = fichier_json.read()
fichier_json.close()

#Chargement de la description des poids du modèle
from keras.models import model_from_json
modele = model_from_json(modele_json)

#Chargement des poids
modele.load_weights("modele/modele_4convolutions.h5")
```

On définit ensuite les différentes catégories de classifications :

```python
#Définition des catégories de classifications
classes = ["Un T-shirt/haut","Un pantalon","Un pull",
           "Une robe","Un manteau","Des sandales","Une chemise",
           "Des baskets", "Un sac","Des bottes de cheville"]
```

Ensuite, libre à vous de choisir des images de vêtements sur Internet et de les sauvegarder dans un répertoire dans votre projet que vous nommerez images.

L'image doit être transformée pour être utilisée dans notre modèle : Conversion en niveaux de gris, et redimensionnement. Pour cela, nous allons utiliser le module Pilow comme suit :

*(Attention à l'indentation du code ici)*

```python
#---------------------------------------------
# CHARGEMENT ET TRANSFORMATION D'UNE IMAGE
#---------------------------------------------
from PIL import Image, ImageFilter

#Chargement de l'image et conversion de celle-ci en nuances de gris (L = greyScale)
image = Image.open("images/IMG_2.jpg").convert('L')

#Dimension de l'image
longueur = float(image.size[0])
hauteur = float(image.size[1])

#Création d'une nouvelle image
nouvelleImage = Image.new('L', (28, 28), (255))

#Redimensionnement de l'image
#L'image est plus longue que haute, on la met à 20 pixels
if longueur > hauteur:
    #On calcule le ratio d'agrandissement entre la hauteur et la longueur
    ratioHauteur = int(round((20.0 / longueur * hauteur), 0))
    if (ratioHauteur == 0):
        nHauteur = 1
    #Redimensionnement
    img = image.resize((20, ratioHauteur), Image.LANCZOS).filter(ImageFilter.SHARPEN)
    #Position horizontale
    position_haut = int(round(((28 - ratioHauteur) / 2), 0))
    nouvelleImage.paste(img, (4, position_haut))
else:
    ratioHauteur = int(round((20.0 / hauteur * longueur), 0))
    if (ratioHauteur == 0):
        ratioHauteur = 1
    #Redimensionnement
    img = image.resize((ratioHauteur, 20), Image.LANCZOS).filter(ImageFilter.SHARPEN)
    #Calcul de la position verticale
    hauteur_gauche = int(round(((28 - ratioHauteur) / 2), 0))
    nouvelleImage.paste(img, (hauteur_gauche, 4))

#Récupération des pixels
pixels = list(nouvelleImage.getdata())

#Normalisation des pixels
tableau = [(255 - x) * 1.0 / 255.0 for x in pixels]
```

Enfin, nous allons soumettre l'image à notre modèle et afficher les résultats :

```python
import numpy as np

#Transformation du tableau en tableau numpy
img = np.array(tableau)

#On transforme le tableau linéaire en image 28x28
image_test = img.reshape(1, 28, 28, 1)

# Extraction des probabilités
probabilites = modele.predict(image_test)
prediction = np.argmax(probabilites, axis=1)

print()
print("Selon moi l'image est : " + classes[prediction[0]])
print()

i = 0
for classe in classes:
    print(classe + ": " + str((probabilites[0][i]*100)) + "%")
    i = i + 1
```

Voici les résultats obtenus pour l'image concernant le pull :

```
Selon moi l'image est : Un pull
Un T-shirt/haut: 3.5228632390499115%
Un pantalon: 0.09517147555015981%
Un pull: 74.61184859275818%
Une robe: 1.9539179280400276%
Un manteau: 13.278758525848389%
Des sandales: 0.007388717494904995%
Une chemise: 6.171694025397301%
Des baskets: 0.004739782161777839%
Un sac: 0.35167725291103125%
Des bottes de cheville: 0.0019266608433099464%
```
