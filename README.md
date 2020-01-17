# manga-downloader
Télécharge des chapitres en ligne de commande depuis manga-panda.com

Prérequis: 
- Docker installé et utilisable sur le système
- (optionnel) un compilateur c ( Au cas où le programme déja compilé ne fonctionne pas sur l'appareil, il faudra recompiler manuellement: gcc download-manga.c -o download-manga)

Comment utiliser?
- Ouvrir la ligne de commande. 
- build l'image docker à partir du dockerfile (il faut se placer dans le dossier contenant le dockerfile et respecter cette syntaxe: docker build . -t download-container)
- taper la commande de téléchargement tout en respectant la syntaxe suivante:

1- ./Download-Manga nomManga numeroChapitre (pour un seul chapitre)

2- ./Download-Manga nomManga numeroChapitreDebut - numeroChapitreFin (pour les chapitres de 1 à 5 par exemple) 

3- ./Download-Manga nomManga numeroChapitre , numeroChapitre , ... (pour plusieurs chapitre séparés. Exemple: chap 1, chap 4, chap 6, etc)

ps: il faut mettre un espace entre chaque paramètre. ex: chap1 , chap3.
    il faut séparer les noms des mangas constitués de plusieurs mots par des tirets. ex: one-piece, nanatsu-no-taizai
    il faut respecter l'écriture du nom du manga, au cas échéant le logiciel ne pourra pas le trouver. ex: on-piece (est incorrect)

Au cas où le programme refuse l'accès, il suffit juste de donner les droits à l'utilisateur sur les fichiers download-manga.o et downloader (chmod u+x downloader et chmod u+x download-manga sur linux ou mac) Sur windows il faudra le faire dans les paramètres du fichier download-manga.exe)
