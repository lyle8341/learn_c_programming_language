#include <stdio.h>


struct Bit {
    unsigned char bit0: 1;
    unsigned char bit1: 1;
    unsigned char bit2: 1;
    unsigned char bit3: 1;
    unsigned char bit4: 1;
    unsigned char bit5: 1;
    unsigned char bit6: 1;
    unsigned char bit7: 1;
};
int main() {

    unsigned num = 0x12345678;
    printf("%lu\n", sizeof(num));
    struct Bit *p = (struct Bit *) &num;
    for (int i = 0; i < sizeof(num); ++i) {
        struct Bit *pBit = p + i;
        printf("%d%d%d%d%d%d%d%d ", pBit->bit0, pBit->bit1, pBit->bit2, pBit->bit3, pBit->bit4, pBit->bit5, pBit->bit6, pBit->bit7);
    }
    return 0;
}