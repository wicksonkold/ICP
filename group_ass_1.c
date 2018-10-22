#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int userinput, firstswitch;

    void addNewItem(void);
    MainGUI:

	printf("1. Add New Item<s> :\n");
	printf("2. Display Item Record<s> :\n");
	printf("3. Search Item Information :\n");
	printf("4. Modify Item Record<s> :\n");
	printf("5. Delete Item Record<s> :\n");
	printf("0. Quit The Program : \n");
	printf("\nWhat Is Your Option <1-5> ?\n");

    type:
	scanf("%d", &userinput);
    fflush(stdin);

	switch (userinput) {

        case 1:
            printf("you have selected 1. Add New Item<s> :\n");
            addNewItem();
            goto MainGUI;

        case 2:
            printf("you have selected 2. Display Item Record<s> :\n");
            goto MainGUI;
        case 3:
            printf("you have selected 3. Search Item Information :\n");
            goto MainGUI;

        case 4:
            printf("you have selected 4. Modify Item Record<s> :\n");
            goto MainGUI;

        case 5:
            printf("you have selected 5. Delete Item Record<s> :\n");
            goto MainGUI;

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
    char FinalDestination[20];
    char Status[20];
};

void addNewItem(){
    void writeIn(struct data);
    addNEW:
    fflush(stdin);
    struct data Data;
    printf("Please enter 1) RecordNumber, 2) ItemName, 3) ItemNumber, 4) Category, 5) Quantity, 6) Weight 7) Recipient, 8) Final Destination, and 9) Delivery status :\n");
    scanf("%d%s%d%s%d%lf%s%s%s",&Data.Record, Data.ItemName, &Data.ItemNumber, Data.Category, &Data.Quantity, &Data.Weight, Data.Recipient,Data.FinalDestination, Data.Status);
    fflush(stdin);
    //printf(" you have typed %d %s %d %s %d %.2f %s %s %s",Data.Record, Data.ItemName, Data.ItemNumber, Data.Category, Data.Quantity, Data.Weight, Data.Recipient, Data.FinalDestination, Data.Status);
    writeIn(Data);
    printf("Item added.");
    char typeAgain;
    error:
    printf("Do you want to add another item record (y/n): ");
    scanf("%c", &typeAgain);
    fflush(stdin);
    switch (typeAgain){
        case 'y':
        case 'Y':
            goto addNEW;
        case 'n':
        case 'N':
            break;
        default:
            printf("Unknown input.\n");
            goto error;
    }


    //1002 Japanese-Garden-Pear-Gift-Box 300522 Food 2 4.2 Cheung-Siu-Ming Yuen-Long Arrival

}

void replace(char from[]){
    int i = 0;
    while (from[i] != '\0') {
        if (from[i] == '-' || from[i] == '_') {
            from[i] = ' ';
        }
        i++;
    }
}

void writeIn(struct data structdata){
    FILE *fp = NULL;

    //replace the string within '_' or '-' to ' '
    replace(structdata.ItemName);
    replace(structdata.Category);
    replace(structdata.Status);
    replace(structdata.Recipient);
    replace(structdata.FinalDestination);

    //Start write in  the file
    fp = fopen("Stock.txt", "w+");
    fprintf(fp,"\n%d\n",structdata.Record);
    fprintf(fp,"%s\n",structdata.ItemName);
    fprintf(fp,"%d\n",structdata.ItemNumber);
    fprintf(fp,"%s\n",structdata.Category);
    fprintf(fp,"%d\n",structdata.Quantity);
    fprintf(fp,"%.1f kg\n",structdata.Weight);
    fprintf(fp,"%s\n",structdata.Recipient);
    fprintf(fp,"%s\n",structdata.FinalDestination);
    fprintf(fp,"%s\n",structdata.Status);
    printf("Saved Success");
    fclose(fp);
}
