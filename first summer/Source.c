#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



 main(void) {
	 FILE* fptr;

	 fptr = fopen("leaderboard.txt", "w");
	char name[30];
	printf("  Welcome to the\n");
	printf("  Guessing game\n");
	printf("Please say your name.\n");
	scanf("%s", name);
	printf("Hi %s!\n", name);

	int Choice;
	//printf("Would you like to be quizzed on Demerit Points, medium or hard difficulty?\n");
	printf("Press 1 to play!\n");
	printf("Press 2 to look at the leaderboard.\n");
	printf("Press 3 to exit.\n");
	scanf("%d", &Choice);
	if (Choice == 1) {
		Gameintro(name); // this should take the name for scorekeeping later on
	}
	else if (Choice == 2) {
		leaderboard();
	}
	else {
		exit(1);
	}

	
}


intro()
{
	char name[30];
	printf("  Welcome to the\n");
	printf("  Guessing game\n");
	printf("Please say your name.\n");
	scanf("%s", name);
	printf("Hi %s!\n", name);


	return 0;
}
Menu() {
	int Choice;
	//printf("Would you like to be quizzed on Demerit Points, medium or hard difficulty?\n");
	printf("Press 1 to play!\n");
	printf("Press 2 to look at the leaderboard.\n");
	printf("Press 3 to exit.\n");
	scanf("%d", &Choice);
	if (Choice == 1) {
		Gameintro();
	} else if (Choice == 2){
		bookscore();
	}
	else {
		exit(1);
	}
	
}
	Gameintro(char *takename){
		printf("Here we go!\n");
		printf("Here are the rules! You type in a number that is between 1 and 25.\n");
		printf("When you type in a number, the game will tell you if the correct number is\n");
		printf("Higher or lower. You have to keep guessing until you guess the correct number!\n");
		printf("Are you ready to play? Let's go!\n");
		gameplaygood( *takename);
		/*int userin1;
		scanf("%d", &userin1);
		if (userin1 == 1 )
			printf("up");*/
		}

	gameplaygood(char *takename) {
		int guess;
		int randomnumber;
		int countguess = 1;
		int guessnum = 4;
		srand(time(NULL));
		randomnumber = (rand() % 25) + 1;
		printf("give me a number between 1 and 25\n");


		do {
			scanf("%d", &guess);

			if (guess > randomnumber) {
				printf("lower\n");
				countguess++;
			}
			else if (guess < randomnumber) {
				printf("higher\n");
				countguess++;
			}

		} while (guess != randomnumber);

		printf("you got it right!\n");
		printf("It took you %d guesses!\n", countguess);
		
		//bookscore(*takename, countguess);
		bookscore(*takename, countguess);
	}
	bookscore(char *takename, int countguess) {

		
		int name = *takename;
		
		fprintf(fptr, "%s, %d", takename, countguess);
		fprintf(fptr, "\n");

		// Close the file
		fclose(fptr);
	}


	
	
	leaderboard()
	{
		printf("this is the leaderboard\n");
	}


