#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	int min,max,random;
	Start:
	printf("Please type a min and max number of guessing: \n");
	TypeMinMax:
	scanf("%d%d",&min,&max);
	fflush(stdin);
	if ( (min - max) >= 0){
		printf("Invaild range! please retype.\n");
		goto TypeMinMax;
	}
	if ( (max - min) < 2){
		printf("you range is too small, we need at least 2 number of range, please retype.\n");
		goto TypeMinMax;
	}
	int maxguess;
	printf("Please type max guess times that you think you can success:  ");
	scanf("%d",&maxguess);
	fflush(stdin);
	srand(time(NULL));
	random = ( rand() % (max-min+1) ) +min;
	printf("\nDone.");
	int guess;
	int times;
	Guess:
	printf("\nPlease type a number to guess...\n");
	scanf("%d",&guess);
	fflush(stdin);
	if( guess == random){
		times++;
		goto Finish;
	}
	if (guess > random){
		times++;
		max = guess;
	}
	if (guess < random){
		times++;
		min = guess;
	}
	printf("\nWrong number! The range is %d - %d",min,max);
	if (times != maxguess){
		goto Guess;
	} else {
		goto Failed;
	}
	Finish:
		printf("\nCorrect!!!! \n");
		printf("You guessed %d times and got success.",times);
		goto PlayAgain;
	Failed:
		printf("\n\nOh No! You failed the guess!");
		printf("\nYou have already used %d times to guess and nothing correct :(", times);
		printf("\nThe correct answer is %d",random);
		goto PlayAgain;
	char input;
	PlayAgain:	
		printf("\nDo you want to play again ? (Y/N) ");
		scanf("%c",&input);
		switch(input){
			case 'Y':
			case 'y':
				goto Start;
			case 'N':
			case 'n':
				return 0;
			default:
				printf("Worng input ! \n");
				goto PlayAgain;		
		}	
}
