//Jason Lahoda, 3/19/23, CIS2107
//Lab 6 2D Race
//This program simulates a race between a tortoise and a hare using functions to process pointers.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FINISH 70

void moveTortoise(int *tortoisePosition) {
    int i = rand() % 10 + 1;
    if (i >= 1 && i <= 5) {
        *tortoisePosition += 3;
    }
    else if (i >= 6 && i <= 7) {
        *tortoisePosition -= 6;
        if (*tortoisePosition < 1) {
            *tortoisePosition = 1;
        }
    }
    else {
        *tortoisePosition += 1;
    }
}

void moveHare(int *harePosition) {
    int i = rand() % 10 + 1; 
    /*if (i >= 1 && i <= 2) {
    }*/
    if (i >= 3 && i <= 4) {
        *harePosition += 9;
    }
    else if (i == 5) {
        *harePosition -= 12;
        if (*harePosition < 1) {
            *harePosition = 1;
        }
    }
    else if (i >= 6 && i <= 8) {
        *harePosition += 1;
    }
    else {
        *harePosition -= 2;
        if (*harePosition < 1) {
            *harePosition = 1;
        }
    }
}

int main() {
    srand(time(NULL));
    int tortoisePosition = 1;
    int harePosition = 1;
    printf("ON YOUR MARK, GET SET\n");
    printf("BANG               !!!!\n");
    printf("AND THEY'RE OFF    !!!!\n");
    while (tortoisePosition < 70 && harePosition < 70) {
        moveTortoise(&tortoisePosition);
        moveHare(&harePosition);
        for (int i = 1; i <= 70; i++) {
            if (i == tortoisePosition && i == harePosition) {
                printf("OUCH!!!");
            } else if (i == tortoisePosition) {
                printf("T");
            } else if (i == harePosition) {
                printf("H");
            } else {
                printf(" ");
            }
            if (tortoisePosition >= 70 || harePosition >= 70) {
                break;
            }
        }
        if (tortoisePosition < 70 && harePosition < 70) {
            printf("\n");
        }
        sleep(1);
    }
    if (tortoisePosition >= 70 && harePosition >= 70) {
        printf("It's a tie.");
    } else if (tortoisePosition >= 70) {
        printf("TORTOISE WINS!!! YAY!!!");
    } else {
        printf("Hare wins. Yuch.");
    }
    return 0;
}