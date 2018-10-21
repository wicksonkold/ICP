#include <stdio.h>
#include <math.h>

int main()
{
	int userinput, firstswitch;

    void addNewItem();
	
	printf("1. Add New Item<s> :\n");
	printf("2. Display Item Record<s> :\n");
	printf("3. Search Item Information :\n");
	printf("4. Modify Item Record<s> :\n");
	printf("5. Delete Item Record<s> :\n");
	printf("0. Quit The Program : \n");
	printf("\nWhat Is Your Option <1-5> ?\n");

    type:
	scanf("%d", &userinput);

	switch (userinput) {

        case 1:
            printf("you have selected 1. Add New Item<s> :\n");
            addNewItem();
            break;

        case 2:
            printf("you have selected 2. Display Item Record<s> :\n");
            break;
        case 3:
            printf("you have selected 3. Search Item Information :\n");
            break;

        case 4:
            printf("you have selected 4. Modify Item Record<s> :\n");
            break;

        case 5:
            printf("you have selected 5. Delete Item Record<s> :\n");
            break;

        case 0:
            printf("you have selected 0. Quit The Program");
            break;

        default:
            printf("you have selected a invalid number <%d> PLEASE RETYPE \n", userinput);
            goto type;
    }
	
	
	
	
	return 0;
 }

struct data{
    int Record;
    char ItemName[50];
    int ItemNumber;
    char Category[10];
    int Quantity;
    double Weight;
    char Recipient[50];
    char Status[20];
};

void addNewItem(){
    struct data Data;
    fflush(stdin);
    printf("Please enter 1) Record number, 2) Item name, 3) Itemnumber, 4) Category, 5) Quantity, 6) Weight 7) Recipient, 8) Final Destination, and 9) Delivery status :\n");
    scanf("%d  %s  %d  %s  %d  %lf  %s  %s",&Data.Record, Data.ItemName, &Data.ItemNumber, Data.Category, &Data.Quantity, &Data.Weight, Data.Recipient, Data.Status);
    printf(" you have typed %d %s %d %s %d %f %s %s",Data.Record, Data.ItemName, Data.ItemNumber, Data.Category, Data.Quantity, Data.Weight, Data.Recipient, Data.Status);

}
