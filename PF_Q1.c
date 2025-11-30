//25K-0803
//Liberty books inventory management system
#include <stdio.h>
#include <string.h>

void addNewBook(int ISBNs[], char titles[][50], float prices[], int quantities[], int* in_stock); 
void processSales(int ISBNs[], int quantities[], int in_stock);
void lowStockReport(int ISBNs[], char titles[][50], float prices[], int quantities[], int* in_stock);

int main(){
    int ISBNs[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int in_stock = 0;
    int menu;

    do{
        printf("Welcome to the Liberty Books Inventory System. \nSelect an option to procced.\n");
        printf("1. Add New Book.\n");
        printf("2. Process a Sale.\n");
        printf("3. Generate Low-Stock Report.\n");
        printf("4. Exit the Program.\n");
        printf("Enter Option\n");
        scanf("%d", &menu);

        switch(menu){
            case 1:
             addNewBook(ISBNs, titles, prices, quantities, &in_stock);
             break;
            case 2:
             processSales(ISBNs, quantities, in_stock);
             break;
            case 3:
             lowStockReport(ISBNs, titles, prices, quantities, &in_stock);
             break;
            case 4:
             printf("Exiting Program.\n");
             break;
            default:
             printf("Invalid Option. Try again.\n");    
        }
    } while(menu != 4);

    return 0;
}

void addNewBook(int ISBNs[100], char titles[100][50], float prices[100], int quantities[], int *in_stock){
    if(in_stock >= 100){
        printf("Inventory Full.\n");
    }
    int newISBN;
    printf("Enter ISBN: ");
    scanf("%d", &newISBN);
    
    for(int i = 0; i < *in_stock; i++){
        if(ISBNs[i] == newISBN){
            printf("Error: A book with this ISBN already exists.\n");
            return;
        }
    }
    ISBNs[*in_stock] = newISBN;

    printf("Enter Book Title: ");
    fgets(titles[*in_stock], 50, stdin);
    titles[*in_stock][strcspn(titles[*in_stock], "\n")] = '\0'; 

    printf("Enter Price: ");
    scanf("%f", &prices[*in_stock]);
    printf("Enter Quantity: ");
    scanf("%d", &quantities[*in_stock]);

    (*in_stock)++;

    printf("Book added successfully!\n");

} 
void processSales(int ISBNs[], int quantities[], int in_stock){
    int findISBN, copiesSold;
     printf("Enter ISBN of the book sold: ");
    scanf("%d", &findISBN);

    for(int i = 0; i < in_stock; i++){
        if(ISBNs[i] == findISBN){
            printf("Enter number of copies sold: ");
            scanf("%d", &copiesSold);

            if(copiesSold > quantities[i]){
                printf("Error: Not enough stock available.\n");
            } 
            else{
                quantities[i] -= copiesSold;
                printf("Sale processed successfully. Remaining stock: %d\n", quantities[i]);
            }
            return;
        }
    }
    printf("Book with ISBN %d not found.\n", findISBN);
}
void lowStockReport(int ISBNs[], char titles[][50], float prices[], int quantities[], int* in_stock){
    int found = 0;

    for(int i = 0; i < in_stock; i++){
        if(quantities[i] < 5){
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   ISBNs[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No low-stock books found.\n");
}

