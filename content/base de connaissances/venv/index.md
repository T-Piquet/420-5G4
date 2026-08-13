+++
title = "Venv python"
weight = 60
+++

## Pourquoi utiliser un environnement virtuel (`venv`) ?

Par défaut, lorsque tu installes une bibliothèque avec `pip install <paquet>`, Python l'installe de manière **globale** sur ta machine.

En développement, cela pose rapidement deux problèmes majeurs :

1. **Conflit de versions :** Le projet A a besoin de `Django 3.2`, mais le projet B nécessite `Django 5.0`.
2. **Pollution du système :** Ton environnement Python global accumule des dizaines de paquets obsolètes ou incompatibles.

Un environnement virtuel (`venv`) est simplement **un dossier isolé** contenant une copie locale de l'exécutable Python et son propre répertoire de dépendances `pip`.

Vous pouvez voir ca comme un conteneur python uniquement, encore plus spécialisé, plus légé.

---

## Le flux de travail classique (Workflow)

1. **Créer l'environnement virtuel:** À exécuter à la racine de ton projet.
Dans ton terminal, place-toi dans le dossier de ton projet et lance :

```bash
python3 -m venv .venv

```

* **`python3 -m venv`** appelle le module intégré `venv`.
* **`.venv`** est le nom du répertoire créé. Le point au début permet de masquer le dossier sur les systèmes UNIX (Linux/macOS).


2. **Activer l'environnement:** Bascule le terminal vers le Python local.
Selon ton système d'exploitation :

```bash
source .venv/bin/activate

```


3. **Gérer les dépendances:** Installation et fichier requirements.txt.
Toutes les commandes `pip` s'appliquent désormais uniquement à cet environnement :

```bash
# Exemples d'installation
$ pip install requests matplotlib

# Exporter la liste exacte des paquets installés
$ pip freeze > requirements.txt

```

Sur une autre machine ou pour un collègue, il suffira de réinstaller le tout avec :

```bash
$ pip install -r requirements.txt

```


4. **Quitter l'environnement:**
Dès que tu as fini de travailler sur le projet :

```bash
$ deactivate

```


---

## Bonnes pratiques

* **Ne jamais versionner le dossier `.venv` sur Git :** Ce dossier est lourd et propre à ta machine. Ajoute systématiquement `.venv/` dans ton fichier `.gitignore`. Seul le fichier `requirements.txt` doit être poussé sur le dépôt.
* **Sélection de l'interpréteur dans l'IDE :** Dans ton éditeur de code (VS Code, VS Codium, PyCharm), pense à sélectionner l'interpréteur situé dans `.venv/bin/python` (ou `.venv\Scripts\python.exe`) pour que le linter et l'autocomplétion repèrent tes dépendances.
* **Outils modernes en entreprise :** En entreprise ou sur de gros projets, tu rencontreras des gestionnaires comme `uv`, `poetry` ou `pipenv` qui s'appuient aussi sur les environnements virtuels mais gèrent automatiquement le verrouillage des dépendances (`lockfiles`).