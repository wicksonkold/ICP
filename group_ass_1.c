#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int haveData;

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

int main()
{
    int userinput, firstswitch;

    void fileIsEmpty(void);
    void addNewItem(void);
    void displayItem(void);
    void searchItem(void);
    void modify(void);
    void test(void);
    void dataDelete(void);
    fileIsEmpty(); //Check whether file is empty,if it is, change file to w+ mode, else, a+ mode.

    MainGUI:
    system("cls");
    
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
            dataDelete();
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
    struct data enterData();
    addNEW:
    fflush(stdin);
    struct data Data;
    Data = enterData();
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

struct data enterData(){
	struct data data1;
	printf("1) RecordNumber\nEnter : ");
    scanf("%d",&data1.Record);
    fflush(stdin);

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
    scanf("%d",&data1.Quantity);
    fflush(stdin);

    printf("6) Weight\nEnter : ");
    scanf("%lf",&data1.Weight);
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

void displayItem(){
    void showRecords(void);
    showRecords();
    printf("\nPress ENTER to go back....");
    getchar();
    fflush(stdin);
    
}

// search item
void searchItem(){
    void searchKeyWord(char*, char*);
    void searchName(char *,char *);
    void searchFromReNum(int);

    FILE *file = fopen("Stock.txt","r+");

    char input;
    int input2;
    int search_Record_Num;
    //search MAIN
    firstInput:
    printf("Do you remember what is your Record number? Please enter (Y/N) ");
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
    printf("Please enter your Record number : ");
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
    char ans;
    ask:
    printf("Do you want to open strict mode ? (Y/N/?)\n");
    scanf("%c",&ans);
    fflush(stdin);

    switch (ans){
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

    if (ans == '?'){
        printf("\nWhat is Strict mode ?\n");
        printf("   Strict mode is to search a record by a full completed name.\n");
        printf("   Instead of keyword, if there are no fully matched name in those records, it won't show anything.\n");
        printf("   If you use keyword, then any records which containing that word will also show at the result list.\n\n");
        goto ask;
    }

    printf("\nWhich do you want? please type that %s of %s\n",(ans == 'Y' || ans == 'y' ? "name" : "keyword"),cSearch);
    gets( string );
    fflush(stdin);

    if (ans == 'N' || ans == 'n') {
        searchKeyWord(cSearch,string);
    } else {
        searchName(cSearch,string);
    }

    End:

    fclose(file);

    printf("\nPress ENTER to go back....");
    getchar();
    fflush(stdin);
}

//modify

void modify(){
	void showRecords();
	void modifyRecord(int);
	
	char input;
	int  input2;
	int search_Record_Num;


	
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

	yesInput:
    	printf("\nPlease enter your Record number : ");
    	scanf("%d",&search_Record_Num);
    	fflush(stdin);

    modifyRecord(search_Record_Num);

    printf("\nPress ENTER to go back....");
    getchar();
    fflush(stdin);

}

// DELETE
void dataDelete() {
    void showRecords(void);
    struct data structFromRecord(int);

    int recN, x;
    char recSearch[100];
    char str1[99];
	long int recsize;
	FILE *file , *tem;
    
	del:
    
		printf("Please enter the record number you want to delete\n");
		
		


	/// sizeo of each record i.e. size of structure variable 

    	
		file = fopen("Stock.txt","r");
		
		strcpy(recSearch,"Record Number");
		while (fgets(str1,99,file) != NULL){
        if (strstr(str1,recSearch)){
            printf("%s",str1);
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


    struct data dat;
    dat = structFromRecord(recN);
    recsize = sizeof(dat);

        tem = fopen("Temp.txt","w");  /// create a intermediate file for temporary storage
        rewind(file); /// move record to starting of file
        
    int a = dat.Record;
    char ch[100];
    char ch2[100];
    //itoa(a, ch, 10);
    //sprintf(ch2, "%d", recN);
    char string[100];
   
    /*while(fread(&dat, sizeof(recsize),1,file) == 1){  /// read all records from file
        if(strcmp(ch,ch2) != 0){  /// if the entered record match
            fwrite(&dat, sizeof(recsize),1,tem); /// move all records except the one that is to be deleted to temp file
        }
    }*/
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
    
    fclose(tem);
	fclose(file);
    int ret = remove("Stock.txt");  		
	char input;
	printf("result of remove is %d\n",ret);
	

    if(ret == 0) {
       printf("File deleted successfully\n");
    } else {
       printf("Error: unable to delete the file\n");
    }
     //rename("Stock.txt","trash.txt"); // rename the temp file to original file name
    rename("Temp.txt","Stock.txt");
	
	
   
   
	again:
	printf("Delete another record(y/n)");
    scanf(" %c", &input);
        fflush(stdin);
		switch(input){
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
    fgets(string,30,file);
    if (strstr(string,"Record Number")) {
        haveData = 1;
    }
    fclose(file);
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
    fprintf(fp,"Record Number: %d\n",structdata.Record);
    fprintf(fp,"Item Name: %s\n",structdata.ItemName);
    fprintf(fp,"Item Number: %d\n",structdata.ItemNumber);
    fprintf(fp,"Category: %s\n",structdata.Category);
    fprintf(fp,"Quantity: %d\n",structdata.Quantity);
    fprintf(fp,"Weight: %.1f kg\n",structdata.Weight);
    fprintf(fp,"Recipient: %s\n",structdata.Recipient);
    fprintf(fp,"Final Destination: %s\n",structdata.FinalDestination);
    fprintf(fp,"Status: %s\n\n",structdata.Status);
    printf("\nItem added.");
    haveData = 1;
    fclose(fp);
}

void showRecords(){
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

void searchKeyWord(char name[],char keyword[]) {
    void searchFromReNum(int);
    char search[88];
    int record[99][2];
    int keywordLine[100];
    char match[99];
    sprintf(match,"%s: %s",name,keyword);
    FILE *file = fopen("Stock.txt", "r+");
    int line = 0, rdnum = 0, i = 0, r = 0;
    while (fgets(search, 88, file) != NULL) {
        if (strstr(search,"Record Number")) {
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
        i+=1;
        record[i][0] = line;
        record[i][1] = rdnum;
    }


    if (r == 0){
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
		while (key < r){
		    //printf("first: %d, next: %d\n",first,next);
		    //printf("keyline: %d\n",keywordLine[key]);
        	if (keywordLine[key] >= first && keywordLine[key] < next){
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

void searchFromReNum(int recordNumber){
    FILE *file = fopen("Stock.txt","r+");
    char keyword[50];
    char string[100];
    snprintf(keyword,50,"Record Number: %d",recordNumber);
    while(fgets(string,99,file) != NULL){
        if (strstr(string,keyword)) goto Result;
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
    sprintf(name,"%s: %s\n",type,keyword);
    FILE *file = fopen("Stock.txt", "r+");
    int line = 0, rdnum = 0, i = 0, r = 0;
    while (fgets(search, 88, file) != NULL) {
        if (strstr(search,"Record Number")) {
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
        i+=1;
        record[i][0] = line;
        record[i][1] = rdnum;
    }

    //printf("r is now %d\n",r);

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
        if (next == 0 ) next += first + 2;
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
    //printf("w is now %d\n",w);
    if (w > 0) printf("\nFound it ! We are listing the items...\n\n");

    for (k = 0; k < w; k++) {
        searchFromReNum(recordNumber[k]);
    }

}


struct data structFromRecord(int recordNumber){
	struct data data;
    FILE *file = fopen("Stock.txt","r+");
    char keyword[50];
    char string[100];
    snprintf(keyword,50,"Record Number: %d",recordNumber);
    while(fgets(string,99,file) != NULL){
        if (strstr(string,keyword)) goto Result;
    }

    printf("Nothing found.");
    return data;

    Result:
    	
	sscanf(string,"Record Number: %d",&data.Record);

    fgets(string, 100, file);
    sscanf(string,"Item Name: %s",data.ItemName);
    
    fgets(string, 100, file);
    sscanf(string,"Item Number: %d",&data.ItemNumber);

    fgets(string, 100, file);
    sscanf(string,"Category: %s",data.Category);

    fgets(string, 100, file);
    sscanf(string,"Quantity: %d",&data.Quantity);

    fgets(string, 100, file);
    sscanf(string,"Weight: %lf kg",&data.Weight);

    fgets(string, 100, file);
    sscanf(string,"Recipient: %s",data.Recipient);

    fgets(string, 100, file);
    sscanf(string,"Final Destination: %s",data.FinalDestination);

    fgets(string, 100, file);
    sscanf(string,"Status: %s",data.Status);
    
    return data;

}

void modifyRecord(int recordNum) {
    FILE *file = fopen("Stock.txt", "rt+");
    char string[99];
    int record;
    while (fgets(string, 99, file) != NULL) {
        sscanf(string, "Record Number: %d\n", &record);
        if (record == recordNum) {
            goto result;
        }
    }

    printf("Nothing Found\n\n");
    fclose(file);
    return;

    result:

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

    char edit[100];
    int input2;
    printf("\n\nwhich you want to edit ?\n");
    printf("2) ItemName\n");
    printf("3) ItemNumber  \n");
    printf("4) Category \n");
    printf("5) Quantity\n");
    printf("6) Weight\n");
    printf("7) Recipient\n");
    printf("8) Final Destination\n");
    printf("9) Delivery Status\n");
    scanf("%d", &input2);
    fflush(stdin);


    switch (input2) {
        case 2:
            printf("You have selected Item Name\n\n");
            strcpy(edit, "Item Name");
            break;

        case 3:
            printf("You have selected Item Number\n\n");
            strcpy(edit, "Item Number");
            break;

        case 4:
            printf("You have selected Category\n\n");
            strcpy(edit, "Category");
            break;

        case 5:
            printf("You have selected Quantity\n\n");
            strcpy(edit, "Quantity");
            break;

        case 6:
            printf("You have selected Weight\n\n");
            strcpy(edit, "Weight");
            break;

        case 7:
            printf("You have selected Recipient\n\n");
            strcpy(edit, "Recipient");
            break;

        case 8:
            printf("You have selected Final Destination\n\n");
            strcpy(edit, "Final Destination");
            break;

        case 9:
            printf("You have selected Delivery Status\n\n");
            strcpy(edit, "Status");
            break;
        default:
            printf("INVALID INPUT... RETYPE...\n");
            goto result;
    }
    char editTo[50];
    printf("\nEdit to: ");
    gets(editTo);
    fflush(stdin);

    //freopen("Stock.txt","r+",file);
    fseek(file, 0, SEEK_SET);
    while (fgets(string, 99, file) != NULL) {
        sscanf(string, "Record Number: %d\n", &record);
        if (record == recordNum) {
            long loc = 0;
            while (strcmp(string, "") != 0) {
                fgets(string, 99, file);
                //printf("string is now %s\n",string);
                if (strstr(string, edit)) {
                    //printf("\nfound edit target %s in %s\n",edit,string);
                    //fwrite(input, strlen(input), sizeof(ftell(file)),file);
                    char input[99];
                    sprintf(input, "%s: %s", edit, editTo);
                    fseek(file, loc, SEEK_SET);
                    fprintf(file, "\0");
                    fputs(input, file);
                    printf("Successfully edited %s to '%s'\n\n", edit, editTo);
                    break;
                }
                loc = ftell(file);

            }
            break;
        }
    }

    fflush(file);
    fclose(file);
}
