#include <stdio.h>
#include <stdlib.h>


int main(){
	int min,max,random;
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
	goto Guess;
	Finish:
		printf("\nCorrect!!!! \n");
		printf("You guessed %d times and got success.",times);
}
