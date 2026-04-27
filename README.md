## Astéroïde

Un clone du jeu d'arcade classique **Asteroids**, développé en C++ avec SFML 2.6.1. Ce projet a été réalisé dans le cadre d'un apprentissage de la programmation orientée objet en C++, notamment la hiérarchisation de classes, l'héritage, et la gestion de ressources via des templates.

---

## Fonctionnalités

- Vaisseau jouable avec physique (poussée, friction, rotation)
- Astéroïdes qui se fragmentent en deux morceaux plus petits lorsqu'ils sont touchés
- Missiles avec son laser
- Explosions animées avec effet sonore
- Défilement toroïdal : les entités sortant d'un bord réapparaissent de l'autre côté
- Score en temps réel et sauvegarde du meilleur score (`meilleurScore.txt`)
- Écran d'accueil

---

## Contrôles

| Touche        | Action              |
|---------------|---------------------|
| Flèche haut   | Accélérer           |
| Flèche gauche | Tourner à gauche    |
| Flèche droite | Tourner à droite    |
| Espace        | Tirer un missile    |
| N'importe quelle touche | Démarrer une partie |

---

## Architecture du projet

Le projet repose sur une hiérarchie de classes centrée autour d'`ElementEspace`, la classe de base abstraite pour toutes les entités du jeu.

```
ElementEspace  (classe de base abstraite)
├── Vaisseau   (vaisseau du joueur)
├── Asteroide  (astéroïde)
├── Missile    (projectile)
└── Explosion  (effet visuel/sonore)
```

- **`Espace`** — Contient et gère toutes les entités. Gère les collisions (test circulaire O(n²)) et le nettoyage en fin de frame.
- **`Jeu`** — Gère l'état de la partie (score, meilleur score, démarrage/fin de jeu).
- **`Coordonnees`** — Coordonnées avec wrap-around automatique sur les bords de l'écran.
- **`GestionnaireRessources<T>`** — Cache de ressources SFML (textures, sons) pour éviter les chargements dupliqués.

---

## Dépendances

- [SFML 2.x](https://www.sfml-dev.org/) — à installer via Homebrew (macOS)
- CMake
- Compilateur C++17 ou supérieur

---

## Compilation

```bash
# Installer SFML (macOS)
brew install sfml@2

# Compiler
mkdir build && cd build
cmake ..
make
```

---

## Limitations notées

- Les astéroïdes ne sont pas générés de façon infinie : une fois tous détruits, la partie se termine.
- Les collisions utilisent un modèle circulaire simple (pas de détection pixel-perfect).
