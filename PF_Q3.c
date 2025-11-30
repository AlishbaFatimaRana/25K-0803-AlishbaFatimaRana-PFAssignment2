//25K-0803
//IESCO power grid monitoring system
#include <stdio.h>


void Update(int arr[5][2], int row, int col);
void Query(int arr[5][2], int row, int col);
void Diagnostic(int arr[5][2]);

int main(){
    int grid[5][2] = {{5,3},{2,1},{0,4},{1,6},{6,7}};
    int option;
    int row, col;
    printf("What function do you want to perform\n"
            "Enter 1 to Update Sector Reference\n"
            "Enter 2 for Query Sector Reference\n"
            "Enter 3 to Run System Diagnostic\n"
        "Choose: ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        printf("\nEnter row number of Sector you want to make changes to: ");
        scanf("%d", &row);
        printf("\nEnter column number of sector you want to make changes to: ");
        scanf("%d",&col);
        Update(grid,row,col);
        break;
    case 2:
        printf("Enter row and column number of sector you want query status of\n"
        "row: ");
        scanf("%d",&row);
        printf("\ncolumn: ");
        scanf("%d",&col);
        Query(grid,row,col);
        break;
    case 3:
            Diagnostic(grid);
        break;

    default:
        break;
    }


}

void Update(int arr[5][2], int row, int col){
    int option, flag;
    printf("Which status do you want to modify?\n"
    "0 - Power Status\n"
    "1 - Overload Warning\n"
    "2 - Maintenance Required\n"
    "Choose: ");
    scanf("%d", &flag);
    printf("Which action do you want to perform: \n"
    "Enter 1 to Set Status\n"
    "Enter 2 to Clear Status\n"
    "Choose: ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        arr[row][col] |= (1 << flag);
        printf("\nStatus Set.");
        break;
    case 2:
        arr[row][col] &= ~(1 << flag);
        printf("\nStatus Cleared.");
        break;
    default:
        printf("\nError: Invalid Input.");
        break;
    }
}
void Query(int arr[5][2], int row, int col) {
    int value = arr[row][col];
    printf("\nSector (%d, %d) status:\n", row, col);

    int power = value & (1 << 0);
    if (power != 0) {
        printf("Power Status: ON\n");
    } else {
        printf("Power Status: OFF\n");
    }

    int overload = value & (1 << 1);
    if (overload != 0) {
        printf("Overload Warning: YES\n");
    } else {
        printf("Overload Warning: NO\n");
    }

    int maintenance = value & (1 << 2);
    if (maintenance != 0) {
        printf("Maintenance Required: YES\n");
    } else {
        printf("Maintenance Required: NO\n");
    }
}

void Diagnostic(int arr[5][2]) {
    int overloadcount = 0;
    int maintenancecount = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            int value = arr[i][j];

            int overload = value & (1 << 1);
            if (overload != 0) {
                overloadcount++;
            }

            int maintenance = value & (1 << 2);
            if (maintenance != 0) {
                maintenancecount++;
            }
        }
    }

    printf("\nSystem Diagnostic Report:\n");
    printf("Total Overloaded Sectors: %d\n", overloadcount);
    printf("Total Sectors Requiring Maintenance: %d\n", maintenancecount);
}