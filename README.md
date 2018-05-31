# Lem-in
Objectif : Implémentation d'algorithme de parcours de graphes.
Executez le programme "lem-in" avec une redirection ou bien directement sur l'entrée standard.
Exemples : "./lem-in < test"
Contenu du fichier "test" :
#nombre_de_fourmis
42
#salles
##start
salle_1 0 0
salle_2 1 1
salle_3 2 2
salle_4 3 3
salle_5 4 4
##end
salle_6 5 5
#liens_entres_les_salles
salle_1-salle_2
salle_1-salle_3
salle_2-salle_3
salle_2-salle_4
salle_4-salle_5
salle_5-salle_6
salle_3-salle_5


Le programme va chercher et afficher le chemin le plus court par lequel les fourmis vont passer.
Le nom des salles n'importe pas. Les coordonnées des salles doivent êtres des entiers.
La commande "start" indique que la prochaine ligne est la salle de départ.
La commande "end" indique que la prochaine ligne est la salle d'arrivée.
Les lignes débutant par un seul caractère '#' sont des commentaires.
il y a un saut de ligne entre chaque salles, commandes, commentaires ou liens.
