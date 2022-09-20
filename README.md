# Compilation

Créer un répertoire builds/Debug et configurer le projet :
`cmake -S . -B builds/Debug`

Compiler le projet
`cmake --build builds/Debug --target exememoryfails`

Executer le projet
`builds/Debug/exememoryfails data/nimp.txt`

# Contenu fonctionnel

Le programme lit un fichier texte composé de mots. Pour chaque mot qui commence par une voyelle, on a ajoute un chou dont le diamètre est de dix fois le nombre de lettres du mot. Pour chaque mot qui commence par une consonne, on a ajoute une patate dont le calibre est le nombre de lettres du mot. Pour chaque légume ajouté, on veut stocker sa variété qui est la première lettre du mot qui a déclenché son ajout, et on veut tracer sa provenance qui correspond à ce même mot. Une fois le ficher lu, des statistiques sur la collection de légumes sont calculées par type de légumes comme la cardinalité, le minimum, la moyenne, et le maximum de leurs caractérisques. Finalement, on veut pouvoir afficher le graphe d'affinités des lettres des provenances en affichant pour chaque lettre la liste des lettres qui la précédent au sein des provenances.