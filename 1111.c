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
    void searchItem(void);
    void modify(void);
    void test(void);
    void enter(void);
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
	system("cls");
	
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
            searchItem();
            goto MainGUI;

        case 4:
            printf("you have selected 4. \n[Modify Item Record<s>] \n\n");
            modify();
			goto MainGUI;

        case 5:
            printf("you have selected 5. \n[Delete Item Record<s>] \n\n");
            goto MainGUI;

        case 0:
            printf("you have selected 0. \n[Quit The Program]\n");
            break;
		case 10:
			printf("test\n");
			test();
			goto MainGUI;
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

void test(){
	struct data structFromRecord(int);
	int recordnum;
	printf("type a record num\n");
	scanf("%d",&recordnum);
	struct data Data = structFromRecord(recordnum);
	printf("%d\n",Data.Record);
	printf("%s\n",Data.ItemName);
	printf("%d\n",Data.ItemNumber);
	printf("%s\n",Data.Category);
	printf("%d\n",Data.Quantity);
	printf("%.1f\n",Data.Weight);
	printf("%s\n",Data.Recipient);
	printf("%s\n",Data.FinalDestination);
	printf("%s\n",Data.Status);
	
}

void addNewItem(){
    void writeIn(struct data);
    void enter();
    addNEW:
    fflush(stdin);
    //struct data Data;
    enter();

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

	system("cls");
}

void enterData(){
	
	printf("1) RecordNumber\nEnter : ");
    scanf("%d",&Data.Record);
    fflush(stdin);

    printf("2) ItemName\nEnter : ");
    gets(Data.ItemName);
    fflush(stdin);

    printf("3) ItemNumber\nEnter : ");
    scanf("%d", &Data.ItemNumber);
    fflush(stdin);

    printf("4) Category\nEnter : ");
    gets(Data.Category);
    fflush(stdin);

    printf("5) Quantity\nEnter : ");
    scanf("%d",&Data.Quantity);
    fflush(stdin);

    printf("6) Weight\nEnter : ");
    scanf("%lf",&Data.Weight);
    fflush(stdin);

    printf("7) Recipient\nEnter : ");
    gets(Data.Recipient);
    fflush(stdin);

    printf("8) Final Destination\nEnter : ");
    gets(Data.FinalDestination);
    fflush(stdin);

    printf("9) Delivery status \nEnter : ");
    gets(Data.Status);
    fflush(stdin);
}

void displayItem(){
    void showRecords(void);
    showRecords();
    printf("\nPress ENTER to go back....\t");
    getchar();
    fflush(stdin);
    //system("cls");
}

// search item
void searchItem(){
    void searchKeyWord(char*);
    void searchFromReNum(int);

    FILE *file = fopen("Stock.txt","r+");

    char input;
    int input2;
    int search_Record_Num;
    //search MAIN
    firstInput:
    printf("Do you remember what is your Record number? Please enterData (Y/N) ");
    scanf(" %c",&input);
    fflush(stdin);

    switch (input){
        case 'y':
        case 'Y':
            goto yesInput;
        case 'n':
        case 'N':
            goto noInput;
        default:
            printf("INVALID INPUT.... RETYPE...\n");
            goto firstInput;
    }

    //first type search, search by Record number
    yesInput:
    printf("Please enterData your Record number : ");
    scanf("%d",&search_Record_Num);
    fflush(stdin);
    goto searchRN;

    //second type search, search by key category
    noInput:
    printf("select what you want to want to search\n");
    printf("1) Record Number\n");
    printf("2) ItemName\n");
    printf("3) ItemNumber  \n");
    printf("4) Category \n");
    printf("5) Quantity\n");
    printf("6) Weight\n");
    printf("7) Recipient\n");
    printf("8) Final Destination\n");
    printf("9) Delivery Status\n");
    printf("0) Previous Step\n");
    scanf("%d",&input2);
    fflush(stdin);

    int x = 0;
    char cSearch[100];
    char string[99];

    switch(input2){
        case 1:
            printf("You have selected Record Number\n\n");
            strcpy(cSearch,"Record Number");
            goto searchX;

        case 2:
            printf("You have selected Item Name\n\n");
            strcpy(cSearch,"Item Name");
            goto searchX;

        case 3:
            printf("You have selected Item Number\n\n");
            strcpy(cSearch,"Item Number");
            goto searchX;

        case 4:
            printf("You have selected Category\n\n");
            strcpy(cSearch,"Category");
            goto searchX;

        case 5:
            printf("You have selected Quantity\n\n");
            strcpy(cSearch,"Quantity");
            goto searchX;

        case 6:
            printf("You have selected Weight\n\n");
            strcpy(cSearch,"Weight");
            goto searchX;

        case 7:
            printf("You have selected Recipient\n\n");
            strcpy(cSearch,"Recipient");
            goto searchX;

        case 8:
            printf("You have selected Final Destination\n\n");
            strcpy(cSearch,"Final Destination");
            goto searchX;

        case 9:
            printf("You have selected Delivery Status\n\n");
            strcpy(cSearch,"Status");
            goto searchX;

        case 0:
            printf("You have selected Previous Step\n\n");
            goto firstInput;
        default:
            printf("INVALID INPUT... RETYPE...\n");
            goto noInput;



    }

    //third type search, search by input keyword

    searchRN:
    //search_Record_Number
    //strcat(keyword,(char *)search_Record_Num);
    //fseek(file, 0, SEEK_SET);
    searchFromReNum(search_Record_Num);
    goto End;





    searchX:

    while (fgets(string,99,file) != NULL){
        if (strstr(string,cSearch)){
            printf("%s",string);
            x++;
        }
    }
    if (x == 0) {
        printf("Nothing found");
        goto End;
    }
    printf("\nWhich do you want? please type that name of %s\n",cSearch);
    gets( string );
    //scanf("%s",string);
    fflush(stdin);
    searchKeyWord(string);

    End:

    fclose(file);

    printf("\nPress ENTER to go back....\t");
    getchar();
    fflush(stdin);
    system("cls");
}

//modify

void modify(){
	void displayItem();
	void searchFromReNum();
	void showRecords();
	void modify2();
	
	char input;
	int  input2;
	int search_Record_Num;
	
	FILE *file = fopen("Stock.txt","r+");
	
	firstInput:
		printf("Do you remember the Record Number?\nPlease Enter : Y / N \n");
			scanf("%c",&input);
				fflush(stdin);
	
	    switch (input){
	        case 'y':
	        case 'Y':
	            goto yesInput;
	        case 'n':
	        case 'N':
	            goto noInput;
	        default:
	            printf("INVALID INPUT.... RETYPE...\n");
	            goto firstInput;
	    }
	    
	noInput:
		showRecords();
			goto yesInput;

	yesInput:
    	printf("Please enterData your Record number : ");
    		scanf("%d",&search_Record_Num);
    			fflush(stdin);
						searchFromReNum(search_Record_Num);
	    
	   
	
}
/* 
void modify2(){
	void replace();
	void writeIn();
	FILE *fp = fopen("Stock.txt","a+");
	FILE *nf = fopen("TemStock.txt","a+");
	 
	c = fgetc(fp); 
	    while (c != EOF){ 
	        fputc(c, nf); 
	        c = fgetc(fp); 
	    } 
	
	printf("hiiiiii here is modify 2 , i want to get data and change it hereeeee\n\n\n\n\n\n");
	
	//get enter function
	enterData();
    
    fclose(fp);
    fclose(nf);
    
    //delete & replace
       int ret;
	   char oldname[] = "TemStock.txt";
	   char newname[] = "Stock.txt";
	   
	   ret = rename(oldname, newname);
		
	   if(ret == 0) {
	      printf("File renamed successfully");
	   } else {
	      printf("Error: unable to rename the file");
	   }
        
    // REMAKE A FILE I/O and SEARCH FOR THE NEW FILE AND RENAME 
    // REPLACE THE OLD 
    // 
    
}
*/

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
    FILE *file = fopen("Stock.txt", "r+");
    char string[30];
    if (file == NULL) return;
    if (strcmp(fgets(string,30,file),"\n") != 0) {
        haveData = 1;
    }
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

void searchKeyWord(char keyword[]) {
    void searchFromReNum(int);
    char search[88];
    int record[99][2];
    int keywordLine[100];
    FILE *file = fopen("Stock.txt", "r+");
    int line = 0, rdnum = 0, i = 0, r = 0;
    while (fgets(search, 88, file) != NULL) {
        if (strstr(search,"Record Number")) {
            sscanf(search, "Record Number \t\t\t%d", &rdnum);
            record[i][0] = line;
            record[i][1] = rdnum;
            i++;
        }
        if (strstr(search, keyword)) {
            keywordLine[r] = line;
            r++;
        }
        line++;
    }
    if (r == 0){
        printf("Nothing found\n");
        return;
    }
    
    
    int first = -1;
    int recordNumber[100];
    int w = 0, j, k, z = 0;
    for (j = 0; j < i; j++) {
        if (first == -1) {
            first = record[j][0];
            continue;
        }

        int next = record[j][0];
        
		int key = 0;
		while (key < r){
        	if (keywordLine[key] >= first && keywordLine[key] < next) {
            	recordNumber[w] = record[z][1];
            	w++;
            	break;
        	}
        	key++;
    	}
        
        

        first = next;
		z++;
    }
    
	if (w > 0) printf("\nFound it ! We are listing the items...\n\n");

    for (k = 0; k < w; k++) {
        searchFromReNum(recordNumber[k]);
    }

}

 void searchFromReNum(int recordNumber){
    FILE *file = fopen("Stock.txt","r+");
    char keyword[50];
    char string[100];
    snprintf(keyword,50,"Record Number \t\t\t%d",recordNumber);
    while(fgets(string,99,file) != NULL){
        if (strstr(string,keyword)) goto Result;
    }

    printf("Nothing found.");
    return;
	
    Result:
	
	system("cls");
	
    printf("%s", string);

    fgets(string, 100, file);
    printf("%s", string);

    fgets(string, 100, file);
    printf("%s", string);

    fgets(string, 100, file);
    printf("%s", string);

    fgets(string, 100, file);
    printf("%s", string);

    fgets(string, 100, file);
    printf("%s", string);

    fgets(string, 100, file);
    printf("%s", string);

    fgets(string, 100, file);
    printf("%s", string);

    fgets(string, 100, file);
    printf("%s\n", string);
    
	printf("_____________________________________________________________________________________\n\n");
	char input;
	firstInput:
		printf("do you want to modify this data?\nPlease Enter (Y/N)\n");
		scanf("%c",&input);
		switch (input){
		        case 'y':
		        case 'Y':
		            //modify2();
		        case 'n':
		        case 'N':
		            goto noInput;
		        default:
		            printf("INVALID INPUT.... RETYPE...\n");
		            goto firstInput;
	}
	noInput:
		printf(" ");

}


struct data structFromRecord(int recordNumber){
	struct data data;
    FILE *file = fopen("Stock.txt","r+");
    char keyword[50];
    char string[100];
    snprintf(keyword,50,"Record Number \t\t\t%d",recordNumber);
    while(fgets(string,99,file) != NULL){
        if (strstr(string,keyword)) goto Result;
    }

    printf("Nothing found.");
    return;

    Result:
    	
	sscanf(string,"Record Number \t\t\t%d",&data.Record);

    fgets(string, 100, file);
    sscanf(string,"Item Name \t\t\t%s",data.ItemName);
    
    fgets(string, 100, file);
    sscanf(string,"Item Number \t\t\t%d",&data.ItemNumber);

    fgets(string, 100, file);
    sscanf(string,"Category \t\t\t%s",data.Category);

    fgets(string, 100, file);
    sscanf(string,"Quantity \t\t\t%d",&data.Quantity);

    fgets(string, 100, file);
    sscanf(string,"Weight \t\t\t\t%lf kg",&data.Weight);

    fgets(string, 100, file);
    sscanf(string,"Recipient \t\t\t%s",data.Recipient);

    fgets(string, 100, file);
    sscanf(string,"Final Destination \t\t%s",data.FinalDestination);

    fgets(string, 100, file);
    sscanf(string,"Status \t\t\t\t%s",data.Status);
    
    return data;

}
