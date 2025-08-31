#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WINNING_POSITION 100
char getMarker(int pos) {
    switch (pos) {
        case 99: case 70: case 52: case 25: case 95: return 'S';
        case 6: case 11: case 17: case 46: case 60: return 'L';
        default: return ' ';
    }
}
int checkSnake(int position) {
    switch (position) {
        case 99: return 54;
        case 70: return 55;
        case 52: return 42;
        case 25: return 2;
        case 95: return 72;
        default: return position;
    }
}
int checkLadder(int position) {
    switch (position) {
        case 6: return 25;
        case 11: return 40;
        case 17: return 69;
        case 46: return 90;
        case 60: return 85;
        default: return position;
    }
}
int rollDice() {
    return (rand() % 6) + 1;
}
void printBoard(int player, int computer) {
    int num = 100;
    printf("\n================== SNAKE AND LADDER BOARD ==================\n\n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < 10; j++) {
                int current = num;
                char mark = getMarker(current);
                if (current == player && current == computer)
                    printf(" PC ");
                else if (current == player)
                    printf(" P  ");
                else if (current == computer)
                    printf(" C  ");
                else if (mark != ' ')
                    printf(" %c%2d", mark, current);
                else
                    printf(" %3d", current);
                num--;
            }
        } else {
            for (int j = 0; j < 10; j++) {
                int current = num;
                char mark = getMarker(current);
                if (current == player && current == computer)
                    printf(" PC ");
                else if (current == player)
                    printf(" P  ");
                else if (current == computer)
                    printf(" C  ");
                else if (mark != ' ')
                    printf(" %c%2d", mark, current);
                else
                    printf(" %3d", current);
                num--;
            }
        }
        printf("\n\n");
    }
    printf("============================================================\n\n");
}
int main() {
    int player = 0, computer = 0;
    int dice;
    srand(time(NULL));

    printf("Welcome to Snake and Ladder (You vs Computer)\n");
    printf("First to reach 100 wins!\n");

    while (player < WINNING_POSITION && computer < WINNING_POSITION) {
        printBoard(player, computer);
        printf("Your turn! Press Enter to roll the dice...");
        getchar();
        dice = rollDice();
        printf("You rolled a %d\n", dice);
        player += dice;
        if (player == WINNING_POSITION) {
            printBoard(player, computer);
            printf("🎉 You win!\n");
            break;
        }
        printf("Computer's turn...\n");
        dice = rollDice();
        printf("Computer rolled a %d\n", dice);
        computer += dice;
        if (computer > WINNING_POSITION) computer -= dice;
        computer = checkLadder(computer);
        computer = checkSnake(computer);
        printf("Computer is now on square %d\n\n", computer);
        if (computer == WINNING_POSITION) {
            printBoard(player, computer);
            printf("💻 Computer wins! Better luck next time.\n");
            break;
        }
    }

    return 0;
}

