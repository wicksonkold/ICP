#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int haveData;
int logData;
int logEnabled = 1;
//Main Sections


struct data {
    int Record;
    char ItemName[50];
    int ItemNumber;
    char Category[10];
    int Quantity;
    double Weight;
    char Recipient[50];
    char FinalDestination[20];
    char Status[20];
} Data;

int main() {
    int userinput, firstswitch;

    void fileIsEmpty(void);
    void addNewItem(void);
    void displayItem(void);
    void searchItem(void);
    void modify(void);
    void test(void);
    void dataDelete(void);
    //void saveLog(void);
    void exportfile(void);

    fileIsEmpty(); //Check whether file is empty,if it is, change file to w+ mode, else, a+ mode.

    MainGUI:
    //system("cls");

    printf("1. Add New Item<s> :\n");
    printf("2. Display Item Record<s> :\n");
    printf("3. Search Item Information :\n");
    printf("4. Modify Item Record<s> :\n");
    printf("5. Delete Item Record<s> :\n");
    printf("6. Disable / Enable Logging:\n");
    printf("7. Export / BackUp File: \n");
    printf("0. Quit The Program : \n");
    printf("\nWhat Is Your Option <0-8> ?\n");

    type:
    scanf("%d", &userinput);
    fflush(stdin);


    switch (userinput) {

        case 1:
            printf("you have selected 1. \n[Add New Item<s>]\n\n");
            addNewItem();
            system("cls");
            goto MainGUI;

        case 2:
            printf("you have selected 2. \n[Display Item Record<s>] \n\n");
            displayItem();
            system("cls");
            goto MainGUI;
        case 3:
            printf("you have selected 3. \n[Search Item Information] \n\n");
            searchItem();
            system("cls");
            goto MainGUI;

        case 4:
            printf("you have selected 4. \n[Modify Item Record<s>] \n\n");
            modify();
            system("cls");
            goto MainGUI;

        case 5:
            printf("you have selected 5. \n[Delete Item Record<s>] \n\n");
            dataDelete();
            system("cls");
            goto MainGUI;
        case 6:
            logEnabled = !logEnabled;
            printf("Logging %s\n", (logEnabled ? "Enabled" : "Disabled"));
            goto MainGUI;
        case 7:
        	exportfile();
        	printf("you have selected 6. \n[Export File & BackUp File]");
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

int checkRecord(int record) {
    FILE *file = fopen("Stock.txt", "r+");
    char keyword[50];
    char string[100];
    snprintf(keyword, 50, "Record Number: %d\n", record);
    while (fgets(string, 99, file) != NULL) {
        if (strcmp(string, keyword) == 0) return 1;
    }
    fclose(file);
    return 0;
}

void addNewItem() {
    void writeIn(struct data);
    struct data enterData();
    addNEW:
    fflush(stdin);
    struct data Data;
    Data = enterData();
    writeIn(Data);
    char typeAgain;
    error:
    printf("\nDo you want to add another item record (y/n): ");
    scanf("%c", &typeAgain);
    fflush(stdin);
    switch (typeAgain) {
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

struct data enterData() {
    struct data data1;
    enter:
    printf("1) RecordNumber\nEnter : ");
    scanf("%d", &data1.Record);
    fflush(stdin);

    if (checkRecord(data1.Record)) {
        printf("Duplicated record number, please retype.\n");
        goto enter;
    }

    printf("2) ItemName\nEnter : ");
    gets(data1.ItemName);
    fflush(stdin);

    printf("3) ItemNumber\nEnter : ");
    scanf("%d", &data1.ItemNumber);
    fflush(stdin);

    printf("4) Category\nEnter : ");
    gets(data1.Category);
    fflush(stdin);

    printf("5) Quantity\nEnter : ");
    scanf("%d", &data1.Quantity);
    fflush(stdin);

    printf("6) Weight\nEnter : ");
    scanf("%lf", &data1.Weight);
    fflush(stdin);

    printf("7) Recipient\nEnter : ");
    gets(data1.Recipient);
    fflush(stdin);

    printf("8) Final Destination\nEnter : ");
    gets(data1.FinalDestination);
    fflush(stdin);

    printf("9) Delivery status \nEnter : ");
    gets(data1.Status);
    fflush(stdin);

    return data1;
}

void displayItem() {
    void showRecords(void);
    showRecords();
    printf("\nPress ENTER to go back....");
    getchar();
    fflush(stdin);

}

// search item
void searchItem() {
    void searchKeyWord(char *, char *);
    void searchName(char *, char *);
    void searchFromReNum(int);

    FILE *file = fopen("Stock.txt", "r+");

    char input;
    int input2;
    int search_Record_Num;
    //search MAIN
    firstInput:
    printf("Do you remember what is your Record number? Please enter (Y/N) ");
    scanf(" %c", &input);
    fflush(stdin);

    switch (input) {
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
    printf("Please enter your Record number : ");
    scanf("%d", &search_Record_Num);
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
    scanf("%d", &input2);
    fflush(stdin);

    int x = 0;
    char cSearch[100];
    char string[99];

    switch (input2) {
        case 1:
            printf("You have selected Record Number\n\n");
            strcpy(cSearch, "Record Number");
            goto searchX;

        case 2:
            printf("You have selected Item Name\n\n");
            strcpy(cSearch, "Item Name");
            goto searchX;

        case 3:
            printf("You have selected Item Number\n\n");
            strcpy(cSearch, "Item Number");
            goto searchX;

        case 4:
            printf("You have selected Category\n\n");
            strcpy(cSearch, "Category");
            goto searchX;

        case 5:
            printf("You have selected Quantity\n\n");
            strcpy(cSearch, "Quantity");
            goto searchX;

        case 6:
            printf("You have selected Weight\n\n");
            strcpy(cSearch, "Weight");
            goto searchX;

        case 7:
            printf("You have selected Recipient\n\n");
            strcpy(cSearch, "Recipient");
            goto searchX;

        case 8:
            printf("You have selected Final Destination\n\n");
            strcpy(cSearch, "Final Destination");
            goto searchX;

        case 9:
            printf("You have selected Delivery Status\n\n");
            strcpy(cSearch, "Status");
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
    searchFromReNum(search_Record_Num);
    goto End;


    searchX:

    while (fgets(string, 99, file) != NULL) {
        if (strstr(string, cSearch)) {
            printf("%s", string);
            x++;
        }
    }
    if (x == 0) {
        printf("Nothing found");
        goto End;
    }
    char ans;
    ask:
    printf("Do you want to open strict mode ? (Y/N/?)\n");
    scanf("%c", &ans);
    fflush(stdin);

    switch (ans) {
        case 'Y':
        case 'y':
        case 'N':
        case 'n':
        case '?':
            break;
        default:
            printf("Invalid input.\n");
            goto ask;
    }

    if (ans == '?') {
        printf("\nWhat is Strict mode ?\n");
        printf("   Strict mode is to search a record by a full completed name.\n");
        printf("   Instead of keyword, if there are no fully matched name in those records, it won't show anything.\n");
        printf("   If you use keyword, then any records which containing that word will also show at the result list.\n\n");
        goto ask;
    }

    printf("\nWhich do you want? please type that %s of %s\n", (ans == 'Y' || ans == 'y' ? "name" : "keyword"),
           cSearch);
    gets(string);
    fflush(stdin);

    if (ans == 'N' || ans == 'n') {
        searchKeyWord(cSearch, string);
    } else {
        searchName(cSearch, string);
    }

    End:

    fclose(file);

    printf("\nPress ENTER to go back....");
    getchar();
    fflush(stdin);
}

//modify

void modify() {
    void showRecords();
    void writeLog(char *);

    char input;


    firstInput:
    printf("Do you remember the Record Number?\nPlease Enter : Y / N \n");
    scanf("%c", &input);
    fflush(stdin);

    switch (input) {
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

    yesInput:

    fflush(stdin);

    int recN, x = 0;
    char recSearch[100];
    char str1[99];

    FILE *file = fopen("Stock.txt", "r");
    FILE *tem = fopen("Temp.txt", "w");  /// create a intermediate file for temporary storage

    strcpy(recSearch, "Record Number");
    while (fgets(str1, 99, file) != NULL) {
        if (strstr(str1, recSearch)) {
            printf("%s", str1);
            x++;
        }
    }
    if (x == 0) {
        printf("Nothing found");
        return;
    }

    printf("______________________________________________________\n");
    printf("\nEnter Record Number to modify: ");
    scanf("%d", &recN);
    fflush(stdin);


    char ch[100];
    char string[100];

    fseek(file, 0, SEEK_SET);
    sprintf(ch, "Record Number: %d\n", recN);
    while (fgets(string, 100, file) != NULL) {

        if (strcmp(string, ch) == 0) {
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fseek(file, 0, SEEK_CUR);
            continue;
        }

        fprintf(tem, "%s", string);

    }

    fclose(file);
    fclose(tem);

    int ret = remove("Stock.txt");
    rename("Temp.txt", "Stock.txt");

    struct data data1;
    enter:

    data1.Record = recN;

    printf("2) ItemName\nEnter : ");
    gets(data1.ItemName);
    fflush(stdin);

    printf("3) ItemNumber\nEnter : ");
    scanf("%d", &data1.ItemNumber);
    fflush(stdin);

    printf("4) Category\nEnter : ");
    gets(data1.Category);
    fflush(stdin);

    printf("5) Quantity\nEnter : ");
    scanf("%d", &data1.Quantity);
    fflush(stdin);

    printf("6) Weight\nEnter : ");
    scanf("%lf", &data1.Weight);
    fflush(stdin);

    printf("7) Recipient\nEnter : ");
    gets(data1.Recipient);
    fflush(stdin);

    printf("8) Final Destination\nEnter : ");
    gets(data1.FinalDestination);
    fflush(stdin);

    printf("9) Delivery status \nEnter : ");
    gets(data1.Status);
    fflush(stdin);


    //Start write in  the file
    file = fopen("Stock.txt", "a+");
    fprintf(file, "Record Number: %d\n", data1.Record);
    fprintf(file, "Item Name: %s\n", data1.ItemName);
    fprintf(file, "Item Number: %d\n", data1.ItemNumber);
    fprintf(file, "Category: %s\n", data1.Category);
    fprintf(file, "Quantity: %d\n", data1.Quantity);
    fprintf(file, "Weight: %.1f kg\n", data1.Weight);
    fprintf(file, "Recipient: %s\n", data1.Recipient);
    fprintf(file, "Final Destination: %s\n", data1.FinalDestination);
    fprintf(file, "Status: %s\n\n", data1.Status);
    printf("\nItem successfully modified");

    fclose(file);

    char log[100];
    sprintf(log, "Modified a Record with Record Number: %d.", data1.Record);
    writeLog(log);

    char zinput;

    again:
    printf("\nModify another record(y/n)");
    scanf(" %c", &zinput);
    fflush(stdin);
    switch (zinput) {
        case 'y':
        case 'Y':
            goto noInput;
        case 'n':
        case 'N':
            break;
        default:
            printf("not an valid input, returned.");
            goto again;
    }

    printf("\nPress ENTER to go back....");
    getchar();
    fflush(stdin);

}

// DELETE
void dataDelete() {
    void showRecords(void);
    struct data structFromRecord(int);
    void writeLog(char *);

    int recN, x = 0;
    char recSearch[100];
    char str1[99];
    long int recsize;
    FILE *file = fopen("Stock.txt", "r");
    FILE *tem = fopen("Temp.txt", "w");  /// create a intermediate file for temporary storage
    //rewind(file); /// move record to starting of file
    del:
    printf("Please enter the record number you want to delete\n");




    /// size of each record i.e. size of structure variable




    strcpy(recSearch, "Record Number");
    while (fgets(str1, 99, file) != NULL) {
        if (strstr(str1, recSearch)) {
            printf("%s", str1);
            x++;
        }
    }
    if (x == 0) {
        printf("Nothing found");
        return;
    }

    printf("______________________________________________________\n");
    printf("\nEnter Record Number to delete: ");
    scanf("%d", &recN);
    fflush(stdin);


    char ch[100];
    char string[100];

    fseek(file, 0, SEEK_SET);
    sprintf(ch, "Record Number: %d\n", recN);
    while (fgets(string, 100, file) != NULL) {

        if (strcmp(string, ch) == 0) {
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fgets(string, 100, file);
            fseek(file, 0, SEEK_CUR);
            continue;
        }

        fprintf(tem, "%s", string);

    }

    fclose(file);
    fclose(tem);
    int ret = remove("Stock.txt");
    char input;
    //printf("result of remove is %d\n",ret);


    if (ret == 0) {
        printf("Record deleted successfully\n");
        char log[100];
        sprintf(log, "Deleted a Record with Record Number: %d.", recN);
        writeLog(log);
    } else {
        printf("Error: unable to delete the Record\n");
    }
    //rename("Stock.txt","trash.txt"); // rename the temp file to original file name
    rename("Temp.txt", "Stock.txt");


    again:
    printf("Delete another record(y/n)");
    scanf(" %c", &input);
    fflush(stdin);
    switch (input) {
        case 'y':
        case 'Y':
            system("cls");
            goto del;
        case 'n':
        case 'N':
            break;
        default:
            printf("not an input, returned.");
            goto again;
    }
}

//Hui Shiu Lun Wickson Extra Function 
void exportfile(){
	void showRecords(void);
	struct data structFromRecord(int);
	
	int recN, x;
    char recSearch[100];
    char str1[99];
    char input;
	char c;
	//File Replace, Rearange, Rename, Copy Data to new .txt (wickson)
	
	//show the record number and ask for sort by record number
	FILE *file, *temp, *expo, *back;
	
		file = fopen("Stock.txt","r+");
		temp = fopen("Temp.txt","r+");
		expo = fopen("Export.txt","r+");
		back = fopen("StockBackUp.txt","r+");
		
	showRecords();
		
	firstinput:
		printf("______________________________________________________\n");	
    	printf("Do you want to output the data?\n ( y / n )\n");
	   	scanf("%c", &input);
	   	switch(input){
				case 'y':
				case 'Y':
					goto replaceagain;
				case 'n':
				case 'N':
					printf("QUIT Export FUNCTUION...");
					goto end;
				
	            default:
	                printf("not an input, returned.");
	                goto firstinput;
			}	
			
	
	replaceagain:
		
		printf("\nDo you want to duplicate the file for back up? (StockBackUp.txt)\nif the StockBackUp.txt is exist file will be rewrite.\n( y / n (skip) / Q(exit))\n");
	    scanf(" %c", &input);
	        fflush(stdin);
			switch(input){
				case 'y':
				case 'Y':
						goto replacefile;			
				case 'n':
				case 'N':
					goto exportagain;
				case 'q':
				case 'Q':
					printf("QUIT EXPORT FUNCTUION...\n");
					goto end;
	            default:
	                printf("not an input, returned.\n");
	                goto replaceagain;
			}	
			
	replacefile:
			   
		    strcpy(recSearch, "Record Number");
		    while (fgets(str1, 99, file) != NULL) {
		        if (strstr(str1, recSearch)) {
		            printf("%s",str1);
		            x++;
		        }
		    }
		    if (x == 0) {
		        printf("Nothing found");
		        return;
		    }
		    recN = 00000;
		
		    char ch[100];
		    char string[100];
		
		    fseek(file, 0, SEEK_SET);

		    while (fgets(string, 100, file) != NULL) {
		
		        if (strcmp(string, ch) == 0) {
		            fgets(string, 100, file);
		            fgets(string, 100, file);
		            fgets(string, 100, file);
		            fgets(string, 100, file);
		            fgets(string, 100, file);
		            fgets(string, 100, file);
		            fgets(string, 100, file);
		            fgets(string, 100, file);
		            fgets(string, 100, file);
		            fseek(file, 0, SEEK_CUR);
		            continue;
		        }
		
		        fprintf(temp, "%s", string);
		
		    }
		fclose(expo);
		fclose(temp);
		fclose(file);
	    fclose(back);
	    
		int ret3 = rename("Temp.txt","StockBackUp.txt");
			
	    if(ret3 == 0) {
	       printf("Duplicate file successfully...\n");
	    } else {
	       printf("Error: unable to duplicate the file\n");
	    }
		
		file = fopen("Stock.txt","r+");
		temp = fopen("Temp.txt","r+");
		expo = fopen("Export.txt","r+");
	    back = fopen("StockBackUp.txt","r+");
		
	//do you want to export as a finished list? // clear the org file , replace a blank doc
	exportagain:
		
		printf("\nDo you want to export as a finished list (Export.txt) ?\nThis will clear the org Stock file.\n( y / n (export as userinput name)/ Q(exit))\n");
	    scanf("%c", &input);
	        fflush(stdin);
			switch(input){
				case 'y':
				case 'Y':
					goto exportfile;
				case 'n':
				case 'N':
					goto renameagain;
				case 'q':
				case 'Q':
					printf("QUIT EXPORT FUNCTUION...\n");
					goto end;
	            default:
	                printf("not an input, returned.\n");
	                goto exportagain;
			}
			
	exportfile:
   	
	   	fclose(expo);
		fclose(temp);
		fclose(file);
		fclose(back);
			
			remove("Export.txt");
		int ret2 = rename("Stock.txt","Export.txt");
			
	    if(ret2 == 0) {
	       printf("Export file successfully... \n");
	    } else {
	       printf("Error: unable to Export the file\n");
	    }
	    
	    file = fopen("Stock.txt","r+");
	    fclose(file);
	    
	    printf("Export file finish....\n");
		goto end;
	//do you want to rename it ? 
	renameagain:
		
		printf("\nDo you want to rename the sorted data ?\n( y / n (back to previous step) / Q(exit) )\n");
	    scanf(" %c", &input);
	        fflush(stdin);
			switch(input){
				case 'y':
				case 'Y':
					goto retypename;
				case 'n':
				case 'N':
					goto exportfile;
				case 'q':
				case 'Q':
					printf("QUIT EXPORT FUNCTUION...\n");
					goto end;
	            default:
	                printf("not an input, returned.\n");
	                goto renameagain;
			}
		
    //copy data to new txt, export for user named
   
   retypename:
   	
	   	fclose(expo);
		fclose(temp);
		fclose(file);
		fclose(back);
		
   		char retypename[20];
   		
		printf("\nEnter the NEW NAME for the output file\n(REMEMBER .txt at the end) : ");
		gets(retypename);
		
		int ret1 = rename("Stock.txt",retypename);
			
	    if(ret1 == 0) {
	       printf("\nRename file successfully... New name : %s\nOrg file is empty\n",retypename);
	    } else {
	       printf("Error: unable to rename the file\n");
	    }
	    
	    printf("Userinput Name finish....\n");
		goto end;
		
	
	end:

		printf("\nPress ENTER to go back....\n");
    	getchar();
   		fflush(stdin);
	
	
	
	
	
}



//Functional Sections

void replace(char from[]) {
    int i = 0;
    while (from[i] != '\0') {
        if (from[i] == '_') {
            from[i] = ' ';
        }
        i++;
    }
}

char *getTime() {
    char time[100];
    return _strtime(time);
}

char *getDate() {
    char date[100];
    _strdate(date);
    for (int i = 0; i < strlen(date); ++i) {
        if (date[i] == '/') date[i] = '-';
    }
    return strcpy(date, date);
}

void writeLog(char *content) { /// Logging function by eric lam

    if (logEnabled == 0) return;

    char date[100];
    strcpy(date, getDate());

    char save[100];
    sprintf(save, "./log/%s.log", date);

    FILE *log = fopen(save, (logData ? "a+" : "w+"));

    if (log == NULL) {
        printf("log is null");
        freopen(save, "w+", log);
    }

    char time[100] = "[";
    strcat(time, strcat(getTime(), "] "));

    fprintf(log, "%s\n", strcat(time, content));
    logData = 1;
    fflush(log);
    fclose(log);
}

/*void saveLog(){
    char date[100];
    strcpy(date,getDate());
    for (int i = 0; i < strlen(date); ++i) {
        if (date[i] == '/') date[i] = '-';
    }
    char save[100];
    int dup = 1;
    sprintf(save,"%s-%d.log",date,dup);
    while (access( save , F_OK) == 0){
        ++dup;
        sprintf(save,"%s-%d.log",date,dup);
    }
    rename("latest.log",save);

}*/

void fileIsEmpty() {

    if (access("log", F_OK) != 0) mkdir("log");

    char date[100];
    strcpy(date, getDate());

    char save[100];
    sprintf(save, "./log/%s.log", date);

    FILE *file = fopen("Stock.txt", "r");
    FILE *log = fopen(save, "r");
    char string[30];
    if (file != NULL) {
        fgets(string, 30, file);
        if (strstr(string, "Record Number")) {
            haveData = 1;
        }
        fclose(file);
    }
    if (log != NULL) {
        fgets(string, 30, log);
        if (strstr(string, "[")) {
            logData = 1;
        }
        fclose(log);
    }


}
/*
void closef(){
	
	FILE *file = fopen(*"stock.txt","r+");
	flose(file);
	remove(file);
	
	int ret = remove("Stock.txt");

    if(ret == 0) {
       printf("File deleted successfully\n");
    } else {
       printf("Error: unable to delete the file\n");
    }
     //rename("Stock.txt","trash.txt"); // rename the temp file to original file name
    rename("Temp.txt","NStock.txt");
	
	
	
}
*/
//File I/O Sections

void writeIn(struct data structdata) {
    FILE *fp = NULL;

    //replace the string within '_' to ' '
    replace(structdata.ItemName);
    replace(structdata.Category);
    replace(structdata.Status);
    replace(structdata.Recipient);
    replace(structdata.FinalDestination);

    //Start write in  the file
    fp = fopen("Stock.txt", (haveData ? "a+" : "w+"));
    fprintf(fp, "Record Number: %d\n", structdata.Record);
    fprintf(fp, "Item Name: %s\n", structdata.ItemName);
    fprintf(fp, "Item Number: %d\n", structdata.ItemNumber);
    fprintf(fp, "Category: %s\n", structdata.Category);
    fprintf(fp, "Quantity: %d\n", structdata.Quantity);
    fprintf(fp, "Weight: %.1f kg\n", structdata.Weight);
    fprintf(fp, "Recipient: %s\n", structdata.Recipient);
    fprintf(fp, "Final Destination: %s\n", structdata.FinalDestination);
    fprintf(fp, "Status: %s\n\n", structdata.Status);
    printf("\nItem added.");
    haveData = 1;
    char log[100];
    sprintf(log, "Added a Record with Record Number: %d.", structdata.Record);
    writeLog(log);
    fclose(fp);
}

void showRecords() {
    FILE *file = fopen("Stock.txt", "r");
    if (!haveData || !file) {
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

void searchKeyWord(char name[], char keyword[]) {
    void searchFromReNum(int);
    char search[88];
    int record[99][2];
    int keywordLine[100];
    char match[99];
    sprintf(match, "%s: %s", name, keyword);
    FILE *file = fopen("Stock.txt", "r+");
    int line = 0, rdnum = 0, i = 0, r = 0;
    while (fgets(search, 88, file) != NULL) {
        if (strstr(search, "Record Number")) {
            sscanf(search, "Record Number: %d", &rdnum);
            record[i][0] = line;
            record[i][1] = rdnum;
            i++;
        }

        if (strstr(search, match)) {
            keywordLine[r] = line;
            r++;
        }

        line++;

    }
    if (i > 0) {
        i += 1;
        record[i][0] = line;
        record[i][1] = rdnum;
    }


    if (r == 0) {
        printf("Nothing found\n");
        return;
    }

    //printf("r is now %d\n",r);

    int first = -1;
    int recordNumber[100];
    int w = 0, j, k, z = 0;
    for (j = 0; j < i; j++) {
        if (first == -1) {
            first = record[j][0];
            continue;
        }

        int next = record[j][0];
        if (next == 0) next += first + 2;
        int key = 0;
        while (key < r) {
            //printf("first: %d, next: %d\n",first,next);
            //printf("keyline: %d\n",keywordLine[key]);
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

    //printf("w is now %d\n",w);
    if (w > 0) printf("\nFound it ! We are listing the items...\n\n");

    for (k = 0; k < w; k++) {
        searchFromReNum(recordNumber[k]);
    }

}

void searchFromReNum(int recordNumber) {
    FILE *file = fopen("Stock.txt", "r+");
    char keyword[50];
    char string[100];
    snprintf(keyword, 50, "Record Number: %d", recordNumber);
    while (fgets(string, 99, file) != NULL) {
        if (strstr(string, keyword)) goto Result;
    }

    printf("Nothing found.");
    return;

    Result:

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

    fclose(file);

}

void searchName(char type[], char keyword[]) {
    char search[88];
    int record[99][2];
    int keywordLine[100];
    char name[99];
    sprintf(name, "%s: %s\n", type, keyword);
    FILE *file = fopen("Stock.txt", "r+");
    int line = 0, rdnum = 0, i = 0, r = 0;
    while (fgets(search, 88, file) != NULL) {
        if (strstr(search, "Record Number")) {
            sscanf(search, "Record Number: %d", &rdnum);
            record[i][0] = line;
            record[i][1] = rdnum;
            i++;
        }

        if (strcmp(search, name) == 0) {
            //printf("%s vs %s",search,name);
            keywordLine[r] = line;
            r++;
        }

        line++;
    }

    if (i > 0) {
        i += 1;
        record[i][0] = line;
        record[i][1] = rdnum;
    }

    //printf("r is now %d\n",r);

    if (r == 0) {
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
        if (next == 0) next += first + 2;
        int key = 0;
        while (key < r) {
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
    //printf("w is now %d\n",w);
    if (w > 0) printf("\nFound it ! We are listing the items...\n\n");

    for (k = 0; k < w; k++) {
        searchFromReNum(recordNumber[k]);
    }

}


struct data structFromRecord(int recordNumber) {
    struct data data;
    FILE *file = fopen("Stock.txt", "r+");
    char keyword[50];
    char string[100];
    snprintf(keyword, 50, "Record Number: %d", recordNumber);
    while (fgets(string, 99, file) != NULL) {
        if (strstr(string, keyword)) goto Result;
    }

    printf("Nothing found.");
    return data;

    Result:

    sscanf(string, "Record Number: %d", &data.Record);

    fgets(string, 100, file);
    sscanf(string, "Item Name: %s", data.ItemName);

    fgets(string, 100, file);
    sscanf(string, "Item Number: %d", &data.ItemNumber);

    fgets(string, 100, file);
    sscanf(string, "Category: %s", data.Category);

    fgets(string, 100, file);
    sscanf(string, "Quantity: %d", &data.Quantity);

    fgets(string, 100, file);
    sscanf(string, "Weight: %lf kg", &data.Weight);

    fgets(string, 100, file);
    sscanf(string, "Recipient: %s", data.Recipient);

    fgets(string, 100, file);
    sscanf(string, "Final Destination: %s", data.FinalDestination);

    fgets(string, 100, file);
    sscanf(string, "Status: %s", data.Status);

    return data;

}
