#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int haveData;

//Main Sections

int main()
{
	int userinput, firstswitch;

    void fileIsEmpty(void);
    void addNewItem(void);
    void displayItem(void);
    fileIsEmpty(); //Check whether file is empty,if it is, change file to w+ mode, else, a+ mode.

    MainGUI:
	printf("1. Add New Item<s> :\n");
	printf("2. Display Item Record<s> :\n");
	printf("3. Search Item Information :\n");
	printf("4. Modify Item Record<s> :\n");
	printf("5. Delete Item Record<s> :\n");
	printf("0. Quit The Program : \n");
	printf("\nWhat Is Your Option <0-5> ?\n");

    type:
	scanf("%d", &userinput);
    fflush(stdin);

	switch (userinput) {

        case 1:
            printf("you have selected 1. \n[Add New Item<s>]\n\n");
            addNewItem();
            goto MainGUI;

        case 2:
            printf("you have selected 2. \n[Display Item Record<s>] \n\n");
            displayItem();
            goto MainGUI;
        case 3:
            printf("you have selected 3. \n[Search Item Information] \n\n");
            
		    goto MainGUI;

        case 4:
            printf("you have selected 4. \n[Modify Item Record<s>] \n\n");
            goto MainGUI;

        case 5:
            printf("you have selected 5. \n[Delete Item Record<s>] \n\n");
            goto MainGUI;

        case 0:
            printf("you have selected 0. \n[Quit The Program]\n");
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
}Data;

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
    //struct data Data;
    printf("1) RecordNumber\nEnter : ");
    scanf("%d",&Data.Record);
    fflush(stdin);
    	
    printf("2) ItemName\nEnter : ");
    scanf("%s", &Data.ItemName);
    fflush(stdin);
    
    printf("3) ItemNumber\nEnter : ");
    scanf("%d", &Data.ItemNumber);
    fflush(stdin);
    
    printf("4) Category\nEnter : ");
    scanf("%s", &Data.Category);
    fflush(stdin);
    
    printf("5) Quantity\nEnter : ");
    scanf("%d",&Data.Quantity);
    fflush(stdin);
    
    printf("6) Weight\nEnter : ");
    scanf("%lf",&Data.Weight);
    fflush(stdin);
    
    printf("7) Recipient\nEnter : ");
    scanf("%s",&Data.Recipient);
    fflush(stdin);
    
    printf("8) Final Destination\nEnter : ");
    scanf("%s",&Data.FinalDestination);
    fflush(stdin);
    
    printf("9) Delivery status \nEnter : ");
    scanf("%s",&Data.Status);
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
    void showRecords(void);
    showRecords();
    printf("\nPress ENTER to go back....\t");
    getchar();
    fflush(stdin);
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
    FILE *file = fopen("Stock.txt", "r");
    fscanf(file,"%d",&haveData);
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
    fp = fopen("Stock.txt", (haveData ? "a+" : "w+"));
    fprintf(fp,"Record Number \t\t\t%d\n",structdata.Record);
    fprintf(fp,"Item Name \t\t\t%s\n",structdata.ItemName);
    fprintf(fp,"Item Number \t\t\t%d\n",structdata.ItemNumber);
    fprintf(fp,"Category \t\t\t%s\n",structdata.Category);
    fprintf(fp,"Quantity \t\t\t%d\n",structdata.Quantity);
    fprintf(fp,"Weight \t\t\t\t%.1f kg\n",structdata.Weight);
    fprintf(fp,"Recipient \t\t\t%s\n",structdata.Recipient);
    fprintf(fp,"Final Destination \t\t%s\n",structdata.FinalDestination);
    fprintf(fp,"Status \t\t\t\t%s\n\n",structdata.Status);
    printf("\nItem added.");
    haveData = 1;
    fclose(fp);
}

void showRecords(){   // Still trying how
    FILE *file = fopen("Stock.txt", "r");
    if (!haveData || !file){
        printf("There's no data in txt.\n");
        return;
    }
    char String[50];
  
    while (fgets(String, 100, file) != NULL) {

        //fgets(String, 100, file);
        printf("%s", String);

        fgets(String, 100, file);
        printf("%s", String);

        fgets(String, 100, file);
        printf("%s", String);

        fgets(String, 100, file);
        printf("%s", String);

        fgets(String, 100, file);
        printf("%s", String);

        fgets(String, 100, file);
        printf("%s", String);

        fgets(String, 100, file);
        printf("%s", String);

        fgets(String, 100, file);
        printf("%s", String);

        fgets(String, 100, file);
        printf("%s\n", String);

        fgets(String, 100, file);
		
    }


    fclose(file);
}
