<!-- map -->
Pour parsing :
- ,0,0,0, a gerer en modifiant split ?

<!-- Pour GRAPHIQUE : -->

- 4 textures pour les murs (Rapport a la lumiere)
-

<!-- Pour vecteurs et position du joueur : -->

dir_x et dir_y: vecteur direction du joueur (vers la ou il regarde)
si le joueur regarde vers N dir_x = 0 dir_y = -1
si le joueur regarde vers S dir_x = 0 dir_y = +1
si le joueur regarde vers E dir_x = +1 dir_y = 0
si le joueur regarde vers W dir_x = -1 dir_y = 0

plane_x et plane_y : champs de vision du joueur, perpendiculaire a dir, represente le plan de la camera
vecteur perpendiculaire a (x, y) est (-y, x) (formule mathematique: voir produit scalaire qui doit etre = 0) quon doit multiplier par FOV (environ 0.66 car un champs de vision reliste cest 66°) donc;
si le joueur regarde vers N (plane_x = 1 plane_y = 0) * 0.66 = (plane_x = 0.66 plane_y = 0)
si le joueur regarde vers S (plane_x = -1 plane_y = 0) * 0.66 = (plane_x = -0.66 plane_y = 0)
si le joueur regarde vers E (plane_x = 0 plane_y = 1) * 0.66 = (plane_x = 0 plane_y = 0.66)
si le joueur regarde vers W (plane_x = 0 plane_y = -1) * 0.66 = (plane_x = 0 plane_y = -0.66)
finalement :
plane_x = -dir_y * 0.66;
plane_y = dir_x * 0.66;

pour initialiser la position du joueur avec son vecteur dir et plane, il faut pouvoir recuperer  N S E W + position du joueur
Pour ca au niveau du parsing il faut recuperer la position du joueur avec ses coordonnees + l orientation donc stocker N S E ou W donc une variable -> voir file init_player

<!-- Pour GRAPHIQUE : -->

- Ctrl + D = Selectionner prochaine occurance.
- Ctrl + Shift + K = Supprimer la ligne courante.
- Ctrl + X = Couper la ligne.
- Ctrl + L = Selectionner entièrement la ligne.
- Alt + flèches directionnelle(⬆️, ⬇️) = Déplacer la ligne.
- Ctrl + Shift + flèches directionnelle(➡️, ⬅️) = Selectionner mot par mot.
- Ctrl + Shift + P = Utiliser Snippet pour améliorer l'insertion d'un groupe de mot plus rapidement.
- F1 + extension insert numbers, permet d'iterer des chiffres sur les lignes selectionnées.
