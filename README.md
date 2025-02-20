# 🎮 So\_long

## 📌 Description

**So\_long** est un projet de l'école 42 visant à développer un petit jeu en **2D** utilisant la minilibX. Le but est de naviguer dans un labyrinthe tout en collectant des objets avant d'atteindre la sortie. Ce projet est un exercice d'optimisation, de gestion des entrées utilisateur et de manipulation de textures.

✅ Bibliothèque graphique : **minilibX**

## 🎯 Objectif du Jeu

- L'objectif est de guider le personnage à travers une carte tout en récoltant tous les objets avant d'atteindre la sortie.
- L'utilisateur peut se déplacer dans **quatre directions** : haut, bas, gauche et droite.
- Un compteur d'affichage indique le nombre de mouvements effectués.

## 🕹️ Commandes

| 🏷️ Touche | 📜 Action                  |
| ---------- | -------------------------- |
| `W` / `↑`  | 🔼 Déplacer vers le haut   |
| `S` / `↓`  | 🔽 Déplacer vers le bas    |
| `A` / `←`  | ◀️ Déplacer vers la gauche |
| `D` / `→`  | ▶️ Déplacer vers la droite |
| `ESC`      | ❌ Quitter le jeu           |

## 📜 Format de la Carte

La carte est définie par un fichier `.ber`, contenant des caractères symbolisant les différents éléments du jeu :

| 🏷️ Caractère | 📜 Signification               |
| ------------- | ------------------------------ |
| `1`           | 🧱 Mur                         |
| `0`           | 🏞️ Espace vide                |
| `P`           | 🎮 Position initiale du joueur |
| `C`           | 💎 Collectible                 |
| `E`           | 🚪 Sortie                      |
| `X`           | 👾 Ennemi (optionnel)          |

Exemple de carte :

```
11111
1P0C1
1C0E1
11111
```

## ⚙️ Installation et Compilation

### 📦 Prérequis

- Un environnement **Linux**
- La bibliothèque **minilibX**
- `make`

### 🏗️ Compilation

```sh
make
```

Cela génère l'exécutable `so_long`.

## 🚀 Utilisation

### 🎯 Exécuter le programme

```sh
./so_long maps/map.ber
```

📌 Exemple d'exécution :

```sh
./so_long maps/level1.ber
```

Cela charge la carte `level1.ber` et lance le jeu.

## 🏆 Fonctionnalités et Optimisation

| 📌 Fonctionnalité          | ✅ Implémentation                  |
| -------------------------- | --------------------------------- |
| **Lecture de la carte**    | 📜 Gestion des fichiers `.ber`    |
| **Affichage graphique**    | 🎨 Utilisation de minilibX        |
| **Déplacements du joueur** | 🏃 Gestion des entrées clavier    |
| **Compteur de mouvements** | 🔢 Affichage des déplacements     |
| **Gestion des erreurs**    | ⚠️ Vérification des cartes        |
| **Optimisation mémoire**   | 💾 Gestion propre des allocations |

## 📚 Ressources Utiles

- 📄 [Sujet officiel du projet](https://cdn.intra.42.fr/pdf/pdf/135148/fr.subject.pdf)
- 📘 [Introduction à la minilibX](https://harm-smits.github.io/42docs/libs/minilibx)

## ✍️ Auteur

Projet réalisé dans le cadre de l'école 42 par **Achille BOSC**.

---

📢 *Cet article a été rédigé par une intelligence artificielle. Le code lui, n'a d'aucune sorte été généré ou modifié par l'IA. 100% du code lié a ce Repertoire GitHub a été fais par les autheurs mentionnés*

🔗 [ChatGPT](https://chat.openai.com/)

