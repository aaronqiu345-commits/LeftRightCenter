#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

// CHANGE ME FOR NEW SEED
int seed = 0;

typedef enum faciem {LEFT, RIGHT, CENTER, PASS} faces;
faces die[] = {LEFT, RIGHT, CENTER, PASS, PASS, PASS};

const char *names[] = {"Happy", "Sleepy", "Sneezy", "Dopey", "Bashful", "Grumpy", "Doc", "Mirror Mirror", "Snow White", "Wicked Queen"};
int money[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
int pot = 0;

int turn = 0;
int players = sizeof(names) / sizeof(names[0]);


int left(int pos, int players) {
    return ((pos + players-1) % players);
}

int right(int pos, int players) {
    return ((pos + players+1) % players);
}

int main(void) {
    srand(seed);
    while (true) {
        int greaterThanZero = 0;
        const char *winner = "Placeholder";
        int winnings = 0;
        for (int i = 0; i < players; i++) {
            if (money[i] != 0) {
                greaterThanZero++;
                winner = names[i];
                winnings = money[i] + pot;
            }
        }
        if (greaterThanZero == 1) {
            printf("Game resolved, winner is %s with $%d\n", winner, winnings);
            break;
        }
        else {
            int rollCount = money[turn];
            if (rollCount > 3) {
                rollCount = 3;
                    }
            for (int i = 0; i < rollCount; i++) {
                if (money[turn] > 0) {
                    int rng = rand() % 6;
                    int choice = die[rng];
                    if (choice == LEFT) {
                        money[turn]--;
                        int playerLeft = left(turn, players);
                        money[playerLeft]++;
                        printf("%s gives $1 to %s\n", names[turn], names[playerLeft]);
                    }
                    else if (choice == RIGHT) {
                        money[turn]--;
                        int playerRight = right(turn, players);
                        money[playerRight]++;
                        printf("%s gives $1 to %s\n", names[turn], names[playerRight]);
                    }
                    else if (choice == CENTER) {
                        money[turn]--;
                        pot++;
                        printf("%s adds $1 to the pot\n", names[turn]);
                    }
                    else if (choice == PASS) {
                        printf("%s passes their turn\n", names[turn]);
                    }
                }
            }
            turn = left(turn, players);
        }
    }
    return 0;
}
