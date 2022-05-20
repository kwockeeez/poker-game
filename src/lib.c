#include "./lib.h"


void display_Info(hand_t *hand) {
    for (size_t i = 0; i < CARD_COUNT; i++) {
        printf("\n[%zd]\n", i + 1);
        printf("->\tValue is %u\n", hand->card[i].value);
        printf("->\tSuit  is %u\n", hand->card[i].suit);
    }
}

void get_Random_Hand(hand_t *hand) {
    for (size_t i = 0; i < CARD_COUNT; i++) {
        hand->card[i].value = (unsigned int)random() % VALUE_COUNT;
        hand->card[i].suit  = (unsigned int)random() % SUIT_COUNT;
    }
}

bool is_Flush(hand_t *hand) {
    unsigned int check = 1;
    for (size_t i = 0; i < CARD_COUNT - 1; i++) {
        if (hand->card[i].suit == hand->card[i + 1].suit && check < FLUSH_CHECK) {
            check++;
        }
    }
    if (check == FLUSH_CHECK) return true;
    return false;
}

bool is_Royal_Flush(hand_t *hand) {
    unsigned int value_count = 0;
    if (is_Flush(hand)) {
        for (size_t i = 0; i < CARD_COUNT; i++) {
            value_count += hand->card[i].value;
        }
    }
    if (value_count == ROYAL_FLUSH_CHECK) return true;
    return false;
}

bool is_Quads(hand_t *hand) {
    unsigned int value = hand->card[0].value;
    unsigned int chech = 0;
    for (size_t i = 0; i < CARD_COUNT; i++) {
        if (hand->card[i].value == value && chech < QUADS_CHECK) {
            chech++;
        }
    }
    if (chech == QUADS_CHECK) return true;
    return false;
}

size_t get_Diff_Index(hand_t *hand) {
    size_t i = 1;
    while (hand->card[0].value == hand->card[i].value) {
        i++;
    }
    return i;
}

bool is_Full_House(hand_t *hand) {
    unsigned int value_1 = hand->card[0].value;
    unsigned int value_2 = hand->card[get_Diff_Index(hand)].value;
    unsigned int check_1 = 0, chech_2 = 0;
    for (size_t i = 0; i < CARD_COUNT; i++) {
        if (hand->card[i].value == value_1 && check_1 < FULL_HOUSE_CHECK_1) {
            check_1++;
        }
        else if ( hand->card[i].value == value_2 && chech_2 < FULL_HOUSE_CHECK_2) {
            chech_2++;
        }
    }
    if (check_1 == FULL_HOUSE_CHECK_1 && chech_2 == FULL_HOUSE_CHECK_2) return true;
    return false;
}


/// TEST FUNCTION

void get_Flush(hand_t *hand) {
    for (size_t i = 0; i < CARD_COUNT; i++) {
        hand->card[i].value = (unsigned int)random() % VALUE_COUNT;
        hand->card[i].suit  = Diamonds;
    }
}

void get_Royal_Flush(hand_t *hand) {
    for (size_t i = 0; i < CARD_COUNT; i++) {
        hand->card[i].value = VALUE_COUNT - 1 - i;
        hand->card[i].suit  = Diamonds;
    }
}

void get_Quads(hand_t *hand) {
    for (size_t i = 0; i < CARD_COUNT; i++) {
        if (i < QUADS_CHECK) {
            hand->card[i].value = King;
        }
        else hand->card[i].value = (unsigned int)random() % VALUE_COUNT;
        hand->card[i].suit = (unsigned int)random() % SUIT_COUNT;
    }
}

void get_Full_House(hand_t *hand) {
    for (size_t i = 0; i < CARD_COUNT; i++) {
        if (i < FULL_HOUSE_CHECK_1) {
            hand->card[i].value = Jack;
        }
        else hand->card[i].value = Queen;
        hand->card[i].suit = (unsigned int)random() % SUIT_COUNT;
    }
}