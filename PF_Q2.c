//25K-0803
//Supermarket inventory management system
#include <stdio.h>
#include <string.h>

void displayinventory(int product[4], int quantity[4], int prices[4]) {
    printf("\nINVENTORY\n");
    for (int i = 0; i < 4; i++) {
        printf("Product: 00%d  ", product[i]);
        printf("Quantity: %d  ", quantity[i]);
        printf("Price: %d\n", prices[i]);
    }
}

int main() {
    int products[4] = {1, 2, 3, 4};
    int quantity[4] = {50, 10, 20, 8};
    int fullshelf[4] = {50, 10, 20, 8};
    int prices[4] = {100, 200, 300, 150};
    int option = 0;
    int cnic = 0, voucher = 0;
    float bill = 0.0;
    char name[50];

    while (option != 6) {
        printf("\nMAIN MENU\n");
        printf("Press 1 to Enter Customer Information\n"
               "Press 2 to Display Inventory\n"
               "Press 3 to Add Item to Cart\n"
               "Press 4 to Display Bill\n"
               "Press 5 to Show Invoice\n"
               "Press 6 to Exit\n"
               "Choose: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter your name: ");
            getchar(); // clear buffer
            fgets(name, 50, stdin);
            printf("Enter your CNIC number: ");
            scanf("%d", &cnic);
            break;

        case 2:
            displayinventory(products, quantity, prices);
            break;

        case 3: {
            int code, pquantity;
            displayinventory(products, quantity, prices);
            printf("\nEnter product code (1-4): ");
            scanf("%d", &code);
            if (code < 1 || code > 4) {
                printf("Invalid product code!\n");
                break;
            }
            printf("Enter quantity: ");
            scanf("%d", &pquantity);

            if (pquantity <= quantity[code - 1] && pquantity > 0) {
                bill += pquantity * prices[code - 1];
                quantity[code - 1] -= pquantity;
                printf("Added %d of product 00%d to cart.\n", pquantity, code);
            } else {
                printf("Out of stock or invalid quantity!\n");
            }
            break;
        }

        case 4:
            if (cnic == 0) {
                printf("Enter Customer Details First.\n");
                break;
            } else if (bill == 0) {
                printf("Your Cart is Empty.\n");
                break;
            } else {
                printf("Total Bill = %.2f\n", bill);
                printf("We are offering a promocode of Eid2025.\n");
                printf("Enter 1 if you have voucher, 0 if not: ");
                scanf("%d", &voucher);
                if (voucher == 1) {
                    printf("Discount Applied (25%% off)\n");
                }
            }
            break;

        case 5:
            if (bill == 0) {
                printf("No bill available.\n");
            } else {
                printf("\nBILL INVOICE\n");
                printf("Customer Name: %s", name);
                printf("Customer CNIC: %d\n", cnic);
                printf("Product\tBought\tPrice\n");
                for (int i = 0; i < 4; i++) {
                    int bought = fullshelf[i] - quantity[i];
                    if (bought > 0) {
                        printf("00%d\t%d\t%d\n", i + 1, bought, bought * prices[i]);
                    }
                }
                if (voucher == 1) {
                    printf("Total Bill after discount: %.2f\n", bill * 0.75);
                } else {
                    printf("Total Bill: %.2f\n", bill);
                }
            }
            break;

        case 6:
            printf("Exiting system...\n");
            break;

        default:
            printf("Invalid Option.\n");
            break;
        }
    }
    return 0;
}
