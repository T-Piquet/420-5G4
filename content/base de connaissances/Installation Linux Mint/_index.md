---
title: Installation de Linux Mint
weight: 1
---

## Procedure d'installation de Linux Mint

1. Sélectionner `Start Linux Mint`

![alt text](image.png)

2. Cliquer `Install Linux Mint`
![alt text](image-1.png)

3. Choisir la langue et cliquer sur `Continuer`
![alt text](image-2.png)

4. Choisir `French (Canada)` à gauche puis à droite. Cliquer sur `Continuer`
![alt text](image-3.png)

5. Cliquer sur `Installer les codecs multimédias` puis sur `Continuer`
![alt text](image-4.png)

6. Cliquer sur `Effacer le disque et installer Linux Mint`
![alt text](image-5.png)

7. Cliquer sur `Continuer`
![alt text](image-6.png)

8. Cliquer sur `Continuer`
![alt text](image-7.png)

9. Remplir les informations puis cliquer sur `Continuer`. Retenez bien votre mot de passe !
![alt text](image-8.png)

10. Cliquer sur `Redémarrer maintenant`
![alt text](image-9.png)

11. Retirer la clé USB puis faire `Entrée`
![alt text](image-10.png)

12. **L’environnement est installé, il faut le mettre à jour.** 

## Mise à jour de l'environement

### Première méthode :

Ouvrir le terminal.
![alt text](image-11.png)

Ecrire les commandes suivantes :
1. sudo apt update
1. Si proposer : `O/n`, faire `Entrée`
1. Sudo apt upgrade
1. Si proposer : `O/n`, faire `Entrée`

### Seconde méthode :
En utilisant l'outil intégré de Mint en bas a droite de votre écran :

![alt text](image-12.png)

1. Cliquez dessus :
![alt text](image-13.png)

2. Avant de faire la mise à jour, il faut mettre l'outil à jour :

(il n'est pas nécéssaire de changer vers un mirroir local)
![alt text](image-14.png)

3. Entrez votre mot de passe :
![alt text](image-15.png)

4. Installez les mise à jour :
![alt text](image-16.png)

5 .Entrez votre mot de passe une nouvelle fois.

Et maintenant votre systeme est à jour prêt pour la suite.

![alt text](image-17.png)

**Installation terminée !**

> [!tip] Mise à jour
> Pensez à faire les mises à jour régulièrement, vous serez prévenus d'une mise à jour lorsque le `manager` (en bas à droite) a une pastille orange.

## Installation de Virtual Box

Pour la suite de ce cours et pour d'autres cours de votre session, vous aller avoir besoin d'utiliser un logiciel de virtulisation de machine.

```bash
$ sudo apt install -y virtualbox
```

Entrez votre mot de passe quand il est demandé.

{{% expand title="**alternative graphique :**" %}} 
![alt text](image-18.png)

![alt text](image-19.png)

![alt text](image-20.png)

![alt text](image-21.png)

**Tapez votre mot de passe.**
{{% /expand %}}

## Installation d'outils de développement

Nous allons ensuite installer quelques outils qui vous seront nécessaire pour la suite de votre session : 
- VScode
- VScodium (comme VScode, mais sans les outils d'espionnage de Microsoft, ni forcage de copilot.)
- git

Pour cela téléchargez le script suivant:
[install.sh](install.sh?download)

Ouvrez un terminal, et tapez les commandes suivante :

```bash
$ cd Download (ou cd Téléchargements si votre installation est en francais)
$ sudo bash install.sh
```