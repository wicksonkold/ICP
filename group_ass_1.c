#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


int haveData = 0;

//Main Sections

int main()
{
	int userinput, firstswitch;

    void fileIsEmpty(void);
    void addNewItem(void);
    void displayItem(void);
    //fileIsEmpty();

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
            displayItem();
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

    /*
     * Examples
     *
     * 1002 Japanese_Garden_Pear_Gift_Box 300522 Food 2 4.2 Cheung_Siu_Ming Yuen_Long Arrival
     *
     * 1001 ORange_Laptop_Computer_DX5 235524 Electronics 1 1.8 Chan_Tai_Man Mong_Kok Delivery
     *
     * 1003 Koppo_Badminton_Racket_GPX-15 77524 Fashion 3 0.6 Lee_Siu_Yu Fortress_Hill Warehouse
     *
     */

//Sub Sections

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
    char typeAgain;
    error:
    printf("\nDo you want to add another item record (y/n): ");
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

}

void displayItem(){
    FILE *file = fopen("Stock.txt", "r");
    getc(file);
}

//Functional Sections

void replace(char from[]){
    int i = 0;
    while (from[i] != '\0') {
        if (from[i] == '_') {
            from[i] = ' ';
        }
        i++;
    }
}

void fileIsEmpty(){
    int data;
    FILE *file = fopen("Stock.txt", "r");
    fscanf(file,"%d",&data);
    if (!isblank(data)) haveData = 1;
    fclose(file);
}

//File I/O Sections

void writeIn(struct data structdata){
    FILE *fp = NULL;

    //replace the string within '_' to ' '
    replace(structdata.ItemName);
    replace(structdata.Category);
    replace(structdata.Status);
    replace(structdata.Recipient);
    replace(structdata.FinalDestination);

    //Start write in  the file
    fp = fopen("Stock.txt", "a+"); //(haveData ? "a+" : "w+")
    fprintf(fp,"%d\n",structdata.Record);
    fprintf(fp,"%s\n",structdata.ItemName);
    fprintf(fp,"%d\n",structdata.ItemNumber);
    fprintf(fp,"%s\n",structdata.Category);
    fprintf(fp,"%d\n",structdata.Quantity);
    fprintf(fp,"%.1f kg\n",structdata.Weight);
    fprintf(fp,"%s\n",structdata.Recipient);
    fprintf(fp,"%s\n",structdata.FinalDestination);
    fprintf(fp,"%s\n\n",structdata.Status);
    printf("\nItem added.");
    haveData = 1;
    fclose(fp);
}

void readFile(int recordNumber){
    FILE *file = fopen("Stock.txt", "r");
    fgetc(file);
}
