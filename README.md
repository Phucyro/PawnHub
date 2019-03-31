# Pawn Hub
> Jeu d'Échecs en Réseau Local

Ce projet a pour but de développer un jeu d'échecs en réseau.
Le client existe sous deux formes; une GUI Qt et une GUI ncurses.

## Installation

Utilisez la fonction clone de git:
'git clone https://gitlab.com/INFOF209-1819/groupe2.git'

La version courante sera dans la branche master.

## Compilation

La compilation requiert g++ par défaut.

Le Makefile du dossier principal permet de compiler le serveur et le client utilisant ncurses.
Compiler les deux ensemble, ainsi que supprimer les fichiers intermédiaires, peut être effectué à l'aide de la commande:
'make'
Compiler les deux ensembles, supprimer les fichiers intermédiaires, et exécuter le serveur prend la commande suivante:
'make run'
Supprimer les dossiers intermédiaires peut être effectué à l'aide de la commande:
'make clean'
Supprimer les dossiers intermédiaires ainsi que les fichiers exécutables suite à la compilation est effectué avec la commande:
'make deepclean'

### Compiler le serveur

Utilisez le Makefile se trouvant dans le dossier principal:
'make server'

### Compiler le client - ncurses

Utilisez le même Makefile que pour le serveur, se trouvant dans le dossier principal:
'make client'

### Compiler le client - Qt

Le fichier exécutable de cette version du client est généré par un Makefile généré automatiquement par QMake.

Depuis le dossier Qt_UI/MainMenu, pour construire le fichier exécutable, effectuez:
'qmake; make'

## Exécution

### Exécuter le serveur

Le serveur s'exécute depuis le dossier principal avec la commande:
'./server'

### Exécuter le client - ncurses

Le client s'exécute depuis le dossier principal avec la commande:
'./client'

### Exécuter le client - Qt

Le client s'exécute depuis le dossier Qt_UI/MainMenu avec la commande:
'./MainMenu'

## Utilisation

### Serveur

Le serveur affiche le nom d'hote de sa machine, et ensuite diverses informations d'exécution.
Le programme ne prend pas d'options à l'exécution.

### Client

Le client requiert d'abord le nom d'hote de la machine du serveur, afin de se connecter.
Il demande ensuite à l'utilisateur de se connecter ou de s'inscrire.
Une fois connecté, un utilisateur peut effectuer plusieurs choix, dont celui de lancer une partie.

#### GUI ncurses

Ce programme ne prend comme entrées que les touches du clavier.
En jeu, l'utilisateur demande le déplacement de ses pièces en indiquant la position de départ et la position de fin de mouvement d'une pièce, toutes deux sous la forme de [notation algebrique](https://fr.wikipedia.org/wiki/Notation_alg%C3%A9brique).
Par exemple, "a2a4" déplacerait la pièce présente à la case a2 sur la case a4.

#### GUI Qt

Ce programme prend comme entrées la souris et le clavier.
En jeu, l'utilisateur demande le déplacement de ses pièces en sélectionnant la case de départ et la case de fin de mouvement d'une pièce.

## Dépendences

- ncurses (v 6.1)
- Qt (v 5.9)
