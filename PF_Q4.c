//25K-0803
//Stack program
#include <stdio.h>

void push(int arr[10], int *top) {
    int num;
    if (*top == 9) {
        printf("Array is full. Stack Overflow!\n");
    } else {
        printf("Enter a number: \n");
        scanf("%d", &num);
        (*top)++;
        arr[*top] = num;
        printf("Pushed %d onto stack.\n", num);
    }
}

void pop(int arr[10], int *top) {
    if (*top == -1) {
        printf("Array is Empty.\n");
    } else {
        printf("Popped element: %d\n", arr[*top]);
        arr[*top] = 0;
        (*top)--;
    }
}

void peek(int arr[10], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top = %d\n", arr[top]);
    }
}

void display(int arr[10], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Current Stack:\n");
        for (int i = top; i >= 0; i--) {
            printf("Element %d: %d\n", i + 1, arr[i]);
        }
    }
}

int main() {
    int array[10] = {0};
    int top = -1, option = 0;

    while (option != 5) {
        printf("\nMAIN MENU:\n"
               "1.Enter 1 to push an element.\n"
               "2.Enter 2 to pop an element.\n"
               "3.Enter 3 to peek top element.\n"
               "4.Enter 4 to display entire stack.\n"
               "5.Enter 5 to Exit.\n"
                "Choose: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            push(array, &top);
            break;
        case 2:
            pop(array, &top);
            break;
        case 3:
            peek(array, top);
            break;
        case 4:
            display(array, top);
            break;
        case 5:
            break;
        default:
            printf("Invalid Option.\n");
            break;
        }
    }
}
