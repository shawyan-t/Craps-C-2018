#include "functions.h"


void print_game_rules(void)
{
	printf("The rules of craps are as follows: A player rolls two dice. Each die has six faces.\n"
		"These faces contain 1, 2, 3, 4, 5, and 6 spots.After the dice have come to rest,\n"
		"the sum of the spots on the two upward faces is calculated.If the sum is 7 or 11 on the first throw,\n"
		"the player wins.If the sum is 2, 3, or 12 on the first throw (called 'craps'),\n"
		"the player loses(i.e.the 'house' wins).If the sum is 4, 5, 6, 8, 9, or 10 on the first throw,\n"
		"then the sum becomes the player's point. To win, you must continue rolling the dice until you 'make your point.'\n" 
		"The player loses by rolling a 7 before making the point.\n");
}

int print_menu(void)
{
	int option = 0;
	printf("1. Display Game Rules\n");
	printf("2. Play Game\n");
	printf("3. Exit game\n");
	scanf("%d", &option);

	if (option == 1)
	{
		print_game_rules();
		print_menu();
	}
	else if (option == 2) 
	{
		return 2;
	}
	else if (option == 3)
	{
		exit(0); //Exit game
	}
	else
	{
		printf("Invalid Input, try again");
		print_menu();
	}
}

/*
Description: Prints a menu with options for the player, returns an option value, determining which action should be taken
Preconditions: None
Postcondtions: The option is not 3
*/


double get_bank_balance(void)
{
	double balance = 0.0;
	printf("How much cash you got? : ");
	scanf("%lf", &balance);
	return balance;
}

/*
Description: Prompts the user for a starting bank balance, then returns that to the main() function
Preconditions: None
Postcondtions: None
*/

double get_wager_amount(void)
{
	double wager = 0.0;
	printf("How much cash you wanna bet?: ");
	scanf("%lf", &wager);
	return wager;
	
}

/*
Description: Prompts the user for a wager, then returns that value to the main() function
Preconditions: None
Postcondtions: None
*/

int check_wager_amount(double wager, double balance)
{
	if (wager <= balance)
	{
		return 1;
	}
	else
	{
		printf("Invalid wager");
		return 0;
	}
}

/*
Description: Takes in two double values from main, wager and balance. The function then checks to make sure that the wager 
			is equal to or less than the balance. If the wager is more than the balance, the function will return 0 and the main function will loop
			until a valid input is made. Otherwise, 1 is returned on successful input.
				
Preconditions: There are two double values to be taken in.
Postcondtions: None
*/

int roll_die(void)
{
	int die_value = 0;
	die_value = rand() % 6 + 1;
	return die_value;
}

/*
Description: Creates a random number between 1-6 and returnst that number to a variable in main
Preconditions: None
Postcondtions: None
*/

int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = die1_value + die2_value;
	return sum;
}

/*
Description: Calculates the sum of two die from the main() function
Preconditions: There are two valid int values
Postcondtions: None
*/

int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1; //Player Wins
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0; //Player Loses
	}
	else
	{
		return -1; //Becomes player's "point"
	}
}

/*
Description: Determines if the first roll is a win loss or a point based on the sum of the dice, which this function takes as a parameter
Preconditions: There is a valid int value being input
Postcondtions: None
*/

int is_point_loss_or_neither(int sum_dice, int point_value)
{
	if (sum_dice == point_value)
	{
		return 1; //Player makes point
	}
	else if (sum_dice == 7)
	{
		return 0; //Player loses
	}
	else
	{
		return -1; //Player keeps point
	}
}

/*
Description: Determines if any roll after the first roll is a win loss or a point based on the sum of the dice, which this function takes as a parameter
Preconditions: There are two valid int values being input
Postcondtions: None
*/

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1)
	{
		bank_balance = bank_balance + wager_amount;
		return bank_balance;
	}
	else if (add_or_subtract == 0)
	{
		bank_balance = bank_balance - wager_amount;
		return bank_balance;
	}
	else
		return bank_balance;
}

/*
Description: Adds or subtracts from the players bank balance. Takes in the the bank balance, wager amount, and a 0 or 1, which determines if the player
					loses money or gains money
Preconditions: There are two valid doubles and an int being given to the function
Postcondtions:
*/

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	if (number_rolls >= 5)
	{
		printf("Thats a lot of rolls, don't lose your point!\n");
	}
	else
	{
		; //Do nothing
	}
	//-------------------------------------------------------------------------------------------------------------//
	if (win_loss_neither == 1)
	{
		printf("You won!\n");
	}
	else if (win_loss_neither == 0)
	{
		printf("You Lost!\n");
	}
	else
	{
		;
	}
	//-------------------------------------------------------------------------------------------------------------//

	if ((initial_bank_balance + current_bank_balance <= (initial_bank_balance / 2)))
	{
		printf("It's never too late for a comeback!\n");
	}
/*
Description: Prints miscellaneous messages based on the number of rolls you've made, if you won or lost, your starting and your current bank balance
Preconditions: The values being taken by the function are called inside main
Postcondtions: None
*/
}

