/****************************************************\
 =================== Bitboard =======================
\****************************************************/
#include <stdio.h>

// U64 is an unsigned long long, which is 64 bits. 
// This is how the bitboard will be stored as there are 64 squares on the board.
// A value of 1 at a particular index will represent a piece on that square.
#define U64 unsigned long long

// The enum will store the index of the square in the bitboard.
// The index will be used to set the bit in the bitboard.
// For example, if the square is a1, the index will be 56 
// because a1 is the 56th square in the enum list.

//   a8 b8 c8 d8 e8 f8 g8 h8 (0-7)
//   a7 b7 c7 d7 e7 f7 g7 h7 (8-15)
//   a6 b6 c6 d6 e6 f6 g6 h6 (16-23)
//   a5 b5 c5 d5 e5 f5 g5 h5 (24-31)
//   a4 b4 c4 d4 e4 f4 g4 h4 (32-39)
//   a3 b3 c3 d3 e3 f3 g3 h3 (40-47)
//   a2 b2 c2 d2 e2 f2 g2 h2 (48-55)
//   a1 b1 c1 d1 e1 f1 g1 h1 (56-63)

// The bitboard will be stored in the following way:
// a1 is 2^0, b1 is 2^1, ... h8 is 2^63
enum {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};

// set_bit will set the bit at the index of the square in the bitboard.
// Example: Given board
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// with square = a1
// You are effective doing the following operation:
// 0ULL | (1ULL << 56)
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 10000000
#define set_bit(bitboard, square) (bitboard |= (1ULL << square))

// get_bit will return the bit at the index of the square in the bitboard.
// Example: Given board
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// with square = a1
// You are effective doing the following operation:
// 0ULL & (1ULL << 56)
// which will do an and operation with the bitboard and the square
// returning 1 if the bit is set and 0 if the bit is not set.
#define get_bit(bitboard, square) (bitboard & (1ULL << square))

// clear_bit will clear the bit at the index of the square in the bitboard.
// Example: Given board
// Example: Given board
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// with square = a1
// You are effective doing the following operation:
// 0ULL & ~(1ULL << 56)
// wheree ~(1ULL << 56) 
#define clear_bit(bitboard, square) (bitboard &= ~(1ULL << square))


// One prespective is that the board is stored backwards compared 
// to standard binary representation.
// The least significant bit is on the top left corner
// and the most significant bit is on the bottom right corner.
void print_bitboard(U64 bitboard) {
    printf("\n     a b c d e f g h\n\n");
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            if (!file) {
                printf("  %d  ", 8 - rank);
            }

            printf("%d ", get_bit(bitboard, square) ? 1 : 0);
        }
        printf("\n");
    }
}


int main() {
    U64 bitboard = 0ULL;
    set_bit(bitboard, a1);
    int square = a1;
    printf("Square: %d\n", square);
    set_bit(bitboard, b1);
    set_bit(bitboard, c1);
    set_bit(bitboard, d1);
    set_bit(bitboard, e1);
    set_bit(bitboard, f1);
    set_bit(bitboard, g1);
    set_bit(bitboard, h1);
    print_bitboard(bitboard);
    clear_bit(bitboard, a1);
    print_bitboard(bitboard);
    return 0;
}