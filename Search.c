#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void searchItem(){
	
	FILE *file = fopen("Stock.txt","r");
	
	char input;	
	int search_Record_Num;
	//search MAIN
	firstInput:
	printf("Do you remember what is your Record number?\nYes or No?\nPlease enter (Y/N)\n");
	scanf("%c",&input);
	
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
    
	//first type search
	yesInput:
		printf("Please enter your Record number : ");
		scanf("%d",&search_Record_Num);
		goto searchRN;
	
	//second type search
	noInput:	
		printf("select what you want to want to search");
		printf("1) Record Number");
	    printf("2) ItemName");
	    printf("3) ItemNumber  ");
	   	printf("4) Category ");
	    printf("5) Quantity");
		printf("6) Weight");
	    printf("7) Recipient");
	    printf("8) Final Destination");
	    printf("9) Delivery Status");
	    printf("0) Previous Step");
	    scanf("%d",&input);
	    
	    int x;
	    char cSearch[100];
	
		switch(input){
			case 1:
				printf("You have selected Record Number");
				x = 1;
				char rn[] = {'Record Number'};
				cSearch = rn[];
				goto searchX;
				
			case 2:
				printf("You have selected Item Name");
				x = 2;
				char iname[100] = {'Item Name'};
				cSearch = iname[100]; 
				goto searchX;
				
			case 3:
				printf("You have selected Item Number");
				x = 3;
				char inum[] = {'Item Number'};
				cSearch = inum;
				goto searchX;
				
			case 4:
				printf("You have selected Category");
				x = 4;
				char cat[] = {'Category'};
				cSearch = cat;
				goto searchX;
				
			case 5:
				printf("You have selected Quantity");
				x = 5;
				char quan[] = {'Quantity'};
				cSearch = quan;
				goto searchX;
				
			case 6:
				printf("You have selected Weight");
				x = 6;
				char weight[] = {'Weight'};
				cSearch = weight;
				goto searchX;
				
			case 7:
				printf("You have selected Recipient");
				x = 7;
				char rec[] = {'Recipient'};
				cSearch = rec;
				goto searchX;
				
			case 8:
				printf("You have selected Final Destination");
				x = 8;
				char fd[] = {'Final Destination'};
				cSearch = fd;
				goto searchX;
				
			 case 9:
				printf("You have selected Delivery Status");
				x = 9;
				char ds[] = {'Status'};
				cSearch = ds;
				goto searchX;
				
			case 0:
				printf("You have selected Previous Step");
				goto firstInput;
			default:
				printf("INVALID INPUT... RETYPE...");
				goto noInput;
			
			
			
		}
	
	searchRN:
	
	goto END;
	
	searchX:
	
	goto END;
	
	END:
	fclose(file);
	printf("Search File Closed...");
	goto MainGUI;
	
	
}
