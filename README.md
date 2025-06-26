Pour parsing :




- ne prend que une map en arguments. rien d'autre

<!--  information : -->
- verif chaque ligne avant la carte. 
- Verifier qu'il y ai 6 element.
- ils commencent par NO, SO, WE, EA, F ou C.
- un seul de chaque.
- verifier que les textures existent.
- verifier les couleurs sont comprises entre 0 et 255.
- ignorer les whites space ou les espaces.
- il y a un seul path et non plus plusieurs.
- parser l'extension .cub
<!-- map -->
- elle doit toujours etre a la fin du fichier.
- uniquement 0, 1, N, S, E, W.
- la map doit etre fermé (floodfill ?)
- Naziha a cook :
On remplace tous les caracteres whitespace par un X. si un X est entouré par un 0, faux.

Pour GRAPHIQUE :

- 4 textures pour les murs (Rapport a la lumiere)
-