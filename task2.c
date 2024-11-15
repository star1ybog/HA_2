#include <stdio.h>
#include <stdint.h>

typedef union {
    float f;
    uint32_t bits;
} FloatUnion;

void display_float_info(float num) {
    FloatUnion u;
    u.f = num;

    //IEEE 754 components
    int sign = (u.bits >> 31) & 1;
    int exponent = ((u.bits >> 23) & 0xFF) - 127;  //exponent is stored with a bias of 127
    int mantissa_bits = u.bits & 0x7FFFFF;  //mantissa occupies the last 23 bits

    //calculate the mantissa as a floating-point value
    float mantissa = 1.0;
    for (int i = 0; i < 23; i++) {
        if ((mantissa_bits >> (22 - i)) & 1) {
            mantissa += 1.0 / (1 << (i + 1));
        }
    }

    //extracted information
    printf("Sign bit: %s\n", sign ? "-" : "+");
    printf("Mantissa value: %.6f\n", mantissa - 1.0);  // Subtract 1 to show only fraction part
    printf("Exponent value: %d\n", exponent);

    //reconstruct and display the original value
    float reconstructed_value = (sign ? -1 : 1) * mantissa * (1 << exponent);
    printf("Reconstructed value: (1.0 + %.6f) * 2**%d = %.6f\n", mantissa - 1.0, exponent, reconstructed_value);
}

int main() {
    float num;

    printf("Enter a floating-point number: ");
    scanf("%f", &num);

    display_float_info(num);

    return 0;
}
