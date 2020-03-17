#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


static int score;

/**
 * cree un entier entre 1 et 10
 */


int rdm(){
    return rand() % 10 + 1;
}

/**
 *  sortie du programme
 */



 void sortie(){
    printf("\nSCORE : %d\n", score);
    exit(0);
}



/**
 * Fonction main
 */


int main(){

    /* initialisation du score à 0 */
    score = 0;

    /* initialisation de la gestion des signaux */

    struct sigaction action;
    action.sa_handler = sortie;
    action.sa_flags = 0;
    sigemptyset (&action.sa_mask);
    sigaction(SIGALRM, &action, NULL);
    sigaction(SIGQUIT, &action, NULL);
    sigaction(SIGINT, &action, NULL);

    /
    srand(time(NULL));


    int n, k, res;

    /* boucle */
    while (1){

        /*programmation de l'alarme */

        alarm(5);

        n = rdm();
        k = rdm();

        /* saisie du resultat */

        printf("%d * %d\n", n, k);
        printf("> ");
        scanf("%d", &res);

        /* condition pour tester le resultat */
        if (res == n * k){
            score++;
        }
    }

    return 0;
}
