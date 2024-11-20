#include <stdio.h>
#include <stdlib.h>
void displayTables(int tables[], int totalTables) 
{
    printf("\nTable Status:\n");
    for (int i = 0; i < totalTables; i++) 
	{
        if (tables[i] == 0)
            printf("Table %d: Available\n", i + 1);
        else
            printf("Table %d: Reserved\n", i + 1);
    }
}
void reserveTable(int tables[], int totalTables, int tableNumber) 
{
    if (tableNumber < 1 || tableNumber > totalTables) 
	{
        printf("Invalid table number. Please enter a number between 1 and %d.\n", totalTables);
    } 
	else if (tables[tableNumber - 1] == 1) 
	{
        printf("Table %d is already reserved.\n", tableNumber);
    } 
	else 
	{
        tables[tableNumber - 1] = 1;
        printf("Table %d has been successfully reserved.\n", tableNumber);
    }
}
int main() {
    int totalTables;
    printf("Enter the number of tables available: ");
    scanf("%d", &totalTables);
    int *tables = (int *)malloc(totalTables * sizeof(int));
    for (int i = 0; i < totalTables; i++) 
	{
        tables[i] = 0;
    }
    int choice, tableNumber;
    while (1) 
	{
        printf("\nTable Reservation System\n");
        printf("1. Display Table Status\n");
        printf("2. Reserve a Table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
           case 1:
                displayTables(tables, totalTables);
                break;
            case 2:
                printf("Enter the table number to reserve (1-%d): ", totalTables);
                scanf("%d", &tableNumber);
                reserveTable(tables, totalTables, tableNumber);
                break;
            case 3:
                printf("Thank you for using the Table Reservation System.\n");
                free(tables);
                return 0;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }
    return 0;
}
