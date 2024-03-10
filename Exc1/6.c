#include <stdio.h>
#include <stdlib.h>

//Constants 
#define MAX_ROUNDS 5
#define PAPER 0
#define ROCK 1
#define SCISSORS 2

//Function declarations for the program
void playRound(int playerMove, int computerMove, int* playerScore, int* computerScore, int* moves, int round);
void printScores(int playerScore, int computerScore, int* moves, int round);

int main() {
    //Variables for the game
    int playerScore = 0, computerScore = 0, round = 0;
    int moves[MAX_ROUNDS];

    //Game loop
    printf("Welcome to the Rock-Paper-Scissors game!\n");
    //The game will run for a maximum of 5 rounds
    while (round < MAX_ROUNDS) {
        printf("\nRound %d\n", round + 1);
        printf("Enter your move (0 - Paper, 1 - Rock, 2 - Scissors): ");

        int playerMove;
        scanf("%d", &playerMove);
        //Check if the move is valid
        if (playerMove < 0 || playerMove > 2) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        int computerMove = rand() % 3;

        playRound(playerMove, computerMove, &playerScore, &computerScore, moves, round);
        round++;
    }
    //End screen
    printf("\nGame over!\n");
    printScores(playerScore, computerScore, moves, round);
    printf("Press any key to exit...");

    return 0;
}

//Play a round of the game
void playRound(int playerMove, int computerMove, int* playerScore, int* computerScore, int* moves, int round) {
    moves[round] = playerMove;

    //Check the winner of the round
    if (playerMove == computerMove) {
        printf("It's a tie!\n");
    } else if ((playerMove - computerMove + 3) % 3 == 1) {
        printf("You win this round!\n");
        (*playerScore)++;
    } else {
        printf("Computer wins this round!\n");
        (*computerScore)++;
    }
}
//Print the scores and moves
void printScores(int playerScore, int computerScore, int* moves, int round) {
    printf("\nScores:\nPlayer: %d\nComputer: %d\n\nYour Moves:\n", playerScore, computerScore);

    for (int i = 0; i < round; i++) {
        printf("Round %d: ", i + 1);
        switch (moves[i]) {
            case PAPER: printf("Paper\n"); break;
            case ROCK: printf("Rock\n"); break;
            case SCISSORS: printf("Scissors\n"); break;
        }
    }
}
