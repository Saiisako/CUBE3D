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

<!-- Objectif : envoyer des rayons par colonne sur tout le champs de vision FOV : -->

FOV s'etend de x = 0(premiere colonne) a x = largeur de la camera - 1 (ex: si la largeur de la camera(fenetre) fait 800 on commence a x = 0 jusqua x = 799)
cameraX = 2 * x / (double)screenWidth - 1; cette formule permet de repartir les rayons sur tout le FOV en normalisant la largeur de l ecran de x = -1 a x = +1 avec x = 0 la position du joueur. pq normalise la largeur ? pour qu elle soit independante de la resolution, sinon on devrait faire nos calculs a partir de la resolution et avoir un resultat deforme si la resolution est modifiee, on n a pas besoin de cameraY car on envoie les rayons sur chaque colonne donc juste besoin du x
ca va nous permettre d obtenir les coordonnees de chaque rayon envoyes ()

pour obtenir la coordonnee de la direction du rayon raydir = (vecteur direction du joueur) + (vecteur plane * cameraX)
(vecteur plane * cameraX) cette partie permet d obtenir la portion du vecteur plane correspondant a la position ou arrive le rayon en question
donc si on veut raydirx ca sera : raydirx = dir_x + (plane_x * cameraX)
donc si on veut raydiry ca sera : raydiry = dir_y + (plane_y * cameraX)

<!-- Pour GRAPHIQUE : -->

- Ctrl + D = Selectionner prochaine occurance.
- Ctrl + Shift + K = Supprimer la ligne courante.
- Ctrl + X = Couper la ligne.
- Ctrl + L = Selectionner entièrement la ligne.
- Alt + flèches directionnelle(⬆️, ⬇️) = Déplacer la ligne.
- Ctrl + Shift + flèches directionnelle(➡️, ⬅️) = Selectionner mot par mot.
- Ctrl + Shift + P = Utiliser Snippet pour améliorer l'insertion d'un groupe de mot plus rapidement.
- F1 + extension insert numbers, permet d'iterer des chiffres sur les lignes selectionnées.








bonus collision : a mettre dans <move>
{
if (cube->map_cpy->grid[(int)new_y][(int)new_x] == '1') // ADDED
	return ;
}

bonus mouse : a mettre dans <render>
{
	int x;
	int y;
	mlx_mouse_get_pos(cube->mlx, cube->win, &x, &y);
	if (x < WIN_WIDTH / 3)
		rotate(cube, ROTATE_L);
	else if (x > 2 * WIN_WIDTH / 3)
		rotate(cube, ROTATE_R);
}

