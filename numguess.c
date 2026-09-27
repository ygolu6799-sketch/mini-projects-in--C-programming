#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){
    int random, guess ;
    int no_of_guess = 0;
    srand(time(NULL));

    printf(" welcome to the world of guessing numbers\n");
    
    random = rand() % 100 +1;
    
    do {
        printf(" \n please enter your guess between ( 1 to 100):");
        scanf("%d",&guess);
        no_of_guess++;

        if ( guess < random ){
            printf("guess a larger number \n");

        } else if (guess > random){
            printf("guess a small number \n");

        } else {
            printf("congrats !!! you have suceessfully guessed the number in %d attempts",no_of_guess);
        }



        } while (guess != random);


        printf("\n bye bye , thanks for playing");
        printf("\n developed by golu");
        return 0;

    

}