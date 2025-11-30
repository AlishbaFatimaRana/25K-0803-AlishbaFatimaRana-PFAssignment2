///25K-0803
//TCS encoding and decoding algorithm
#include <stdio.h>
#include <string.h>

void encode(char text[50]) {
    int len = 0;
    int i = 0;

    while (text[i] != '\0') {
        len++;
        i++;
    }

    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
        len--;
    }

    char reversetext[50];
    i = 0;

    while (len != 0) {
        reversetext[i] = text[len - 1];
        i++;
        len--;
    }
    reversetext[i] = '\0';

    i = 0;
    while (reversetext[i] != '\0') {
        int temp = reversetext[i];
        temp = temp ^ (1 << 1);
        temp = temp ^ (1 << 4);
        reversetext[i] = temp;
        i++;
    }

    printf("Encoded text: %s\n", reversetext);
}

void decode(char text[50]) {
    int len = 0;
    int i = 0;

    while (text[i] != '\0') {
        len++;
        i++;
    }

    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
        len--;
    }

    i = 0;
    while (text[i] != '\0') {
        int temp = text[i];
        temp = temp ^ (1 << 1);
        temp = temp ^ (1 << 4);
        text[i] = temp;
        i++;
    }

    char decoded[50];
    i = 0;

    while (len != 0) {
        decoded[i] = text[len - 1];
        i++;
        len--;
    }
    decoded[i] = '\0';

    printf("Decoded text: %s\n", decoded);
}

int main() {
    char text[50];
    int option;
    int exit = 0;

    do {
        printf("\nMENU\n"
               "1. Encode your text\n"
               "2. Decode your text\n"
               "3. Exit\n"
               "Choose: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
        case 1:
            printf("Enter text: ");
            fgets(text, 50, stdin);
            encode(text);
            break;
        case 2:
            printf("Enter encoded text: ");
            fgets(text, 50, stdin);
            decode(text);
            break;
        case 3:
            exit = 1;
            break;
        default:
            printf("Invalid option.\n");
            break;
        }
    } while (exit == 0);

    return 0;
}