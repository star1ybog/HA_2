#include <stdio.h>
#include <stdlib.h>

void print_binary(int value) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int value, key, encrypted, decrypted;
    int verbose = 0;

    //verbose mode if "-v" argument is provided
    if (argc > 1 && (strcmp(argv[1], "-v") == 0)) {
        verbose = 1;
    }

    // Input original value
    printf("Enter a value: ");
    scanf("%d", &value);

    // Input key (number of bits for XOR)
    printf("Enter a key (number of bits for XOR): ");
    scanf("%d", &key);

    // Encrypt
    encrypted = value ^ key;

    // Decrypt
    decrypted = encrypted ^ key;

    //results
    printf("Original value (Decimal): %d\n", value);
    if (verbose) {
        printf("Binary: ");
        print_binary(value);
    }

    printf("Encrypted value (Decimal): %d\n", encrypted);
    if (verbose) {
        printf("Binary: ");
        print_binary(encrypted);
    }

    printf("Decrypted value (Original): %d\n", decrypted);
    if (verbose) {
        printf("Binary: ");
        print_binary(decrypted);
    }

    return 0;
}
