#include <stdio.h>
#include <math.h>

int main()

{
	int userinput, firstswitch;
	
	printf("1. Add New Item<s> :\n");
	printf("2. Display Item Record<s> :\n");
	printf("3. Search Item Information :\n");
	printf("4. Modify Item Record<s> :\n");
	printf("5. Delete Item Record<s> :\n");
	printf("0. Quit The Program : \n");
	printf("\nWhat Is Your Option <1-5> s\n");
	
	scanf("%d", &userinput);
	
	do{
			
			switch (userinput){
				
				case 1:
					printf("you have selected 1. Add New Item<s> :\n");
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
			
		}
			
	} while (userinput < 0 && userinput > 5);
	
	
	
	
	return 0;
 } 
