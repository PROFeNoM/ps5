# Dépôt pour les projets S5 (PR103)

- Lien vers le sujet du projet :

	<https://www.labri.fr/perso/renault/working/teaching/projets/2020-21-S5-Tilings.php>

- Lien vers le projet sur la forge :

	<https://thor.enseirb-matmeca.fr/ruby/projects/projetss5>

- Lien vers la documentation sur l'utilisation de git :

	<https://thor.enseirb-matmeca.fr/ruby/docs/repository/git>
	
# HISTORY
## [5 nov. 2020][Guillaume FORNES]

### Travail effectué
- (Equipe) Compréhension du fonctionnement de *Git* et Thor
- (Equipe) Compréhension du fonctionnement/utilité des fichiers *header* ".h"
- (Equipe) Début de rédaction des fichiers tile.c, color.c et rédaction d'un premier main.c
- (Equipe) Documentation sur les *makefiles*, et création d'une première version du makefile du projet 

### Tâches, Objectif et planning
- création de *test* par la machine (sur les différentes parties, tuiles, deck,...)

- reflexion sur la répartition des *tiles* pour chaque joueurs et implémentation des structures *files*
	- répartition
	- définition de la structure file et fonctionnement
	
- reflexion sur la représentation algorithmique de la *board*
  	- définition des cases (coordonnées ? matrice ?)
	- initialisation (qui pose la première et ou)
	- limites et autre

## [6 nov. 2020][Paul DEBRAIX]

### Travail effectué
- (Paul) Travail sur l'implémentation de *player.c*, début d'un fichier *test_player.c*
- (Alexandre) Début des tests pour *tile.c* dans un fichier *test_tile.c*
- (Guillaume) Avancement sur comment représenter la *board* notamment comment représenter une case vide

### Tâches, Objectifs
- Header plus général regroupant toutes les structures nécessaires
	- Array of struct pour les couleurs
- Création achiev0 et lien latest
- Définition d'un tuile *vide* et modifications en conséquences
- Définir globalement C le nbr de couleurs
- Comment determiner ou non la possibilité de placer une tuile (liste_authorized_places)

# A long terme / Boîte à idée
- mieux comprendre les *malloc* et comment les éviter