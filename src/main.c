#include "./lib.h"


int main() {
    srand((unsigned int)time(0));

    hand_t *hand = malloc(sizeof *hand);

    // RANDOM FUNCTION
    get_Random_Hand(hand);

    // TEST FUNCTIONS
    // get_Flush(hand);
    // get_Royal_Flush(hand);
    // get_Quads(hand);
    // get_Full_House(hand);

    display_Info(hand);

    if (is_Royal_Flush(hand)) {
        printf("\n[Result]\n->\tIt's a Royal Flush!\n");
    }
    else if (is_Full_House(hand)) {
        printf("\n[Result]\n->\tIt's a Full House!\n");
    }
    else if (is_Quads(hand)) {
        printf("\n[Result]\n->\tIt's a Quads!\n");
    }
    else if (is_Flush(hand)) {
        printf("\n[Result]\n->\tIt's a Flash!\n");
    }
    else {
        printf("\n[Result]\n->\tLoses!\n");
    }

    free(hand);
    return 0;
}