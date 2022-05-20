#ifndef LIB_H
#define LIB_H


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define CARD_COUNT         5
#define FLUSH_CHECK        5
#define ROYAL_FLUSH_CHECK  50
#define QUADS_CHECK        4
#define FULL_HOUSE_CHECK_1 3
#define FULL_HOUSE_CHECK_2 2


enum eValue { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace, VALUE_COUNT };

enum eSuit { Hearts, Diamonds, Clubs, Spades, SUIT_COUNT };


typedef struct {
    enum eValue value;
    enum eSuit  suit;
} card_t;

typedef struct {
    card_t card[CARD_COUNT];
} hand_t;


void display_Info(hand_t *hand);

void get_Random_Hand(hand_t *hand);

bool is_Flush(hand_t *hand);

bool is_Royal_Flush(hand_t *hand);

bool is_Quads(hand_t *hand);

size_t get_Diff_Index(hand_t *hand);

bool is_Full_House(hand_t *hand);


/// TEST FUNCTION

void get_Flush(hand_t *hand);

void get_Royal_Flush(hand_t *hand);

void get_Quads(hand_t *hand);

void get_Full_House(hand_t *hand);


#endif