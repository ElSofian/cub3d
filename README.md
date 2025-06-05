# Cub3D – 42 Paris

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

## 📖 Description

Le projet **Cub3D** consiste à développer un petit moteur de rendu 3D en C, fondé sur la technique de raycasting (inspirée de Wolfenstein 3D). L’objectif est de créer un affichage en temps réel d’un labyrinthe en 3D à partir d’un fichier de configuration (`.cub`), en implémentant notamment :

- Le parsing d’un fichier de carte (`.cub`) décrivant l’environnement (murs, textures, plancher/plafond, positions de sprites, etc.)
- Le calcul des rayons pour déterminer la hauteur et l’emplacement des murs à l’écran
- Le rendu de textures sur les murs, avec prise en charge des différentes orientations (Nord, Sud, Est, Ouest)
- L’affichage du sol et du plafond en couleurs unies
- La gestion des sprites (placement, distance, tri depth, et affichage correct par-dessus les murs)
- La gestion des déplacements du joueur (avancer, reculer) et des rotations (gauche, droite) avec détection de collisions
- La gestion des événements clavier pour permettre une navigation fluide dans le monde 3D

Ce projet vise à valider les acquis en manipulation bit‐maps, en algorithmes de rendu 3D simplifiés, en gestion d’événements graphiques avec la bibliothèque MiniLibX, ainsi qu’en gestion de mémoire en C.

---

## 🛠️ Prérequis

- Un environnement UNIX
- Un compilateur C (gcc, cc...)
- Make

---

## 🚀 Installation & Compilation

1. **Cloner le dépôt**  
   ```bash
   git clone https://github.com/ElSofian/cub3d.git
   cd cub3d
   make
   ./cub3d assets/maps/test.cub (ou tout autre map)

## 🖋️ Crédits
Elaloui Sofian & Balthazar Borry
