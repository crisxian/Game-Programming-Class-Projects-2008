// 
//

#include "stdafx.h"

void AI (int, int, int, int*, int*);
int BinaryConvert (int, int, int);


void main(void)
{
	int first, stack1, stack2, stack3, total, PChoice, PStack, playerturn = 0, aiturn = 0,
		ai_stack = 0, ai_value = 0;

	stack1  = 13;
 	stack2  = 12;
	stack3  =  5;
	first  =  0;
	total  = stack1 + stack2 + stack3;
	printf("Welcome to a game of nim sum. Got the guts to beat me?\n");
	printf("This is a game with 3 stacks. Stack 1 = %d Stack 2 = %d Stack 3 = %d\n", stack1, stack2, stack3);

	
	
	printf ("Do you want to go first or second? \n Type 1 for first and 2 for second\n");
		scanf ("%d",&first);

		while (first > 2)
		{
			printf ("How do you expect to win if you cannot even follow directions?\n");
			printf ("Do you want to go first or second? \n Type 1 for first and 2 for second\n");
				scanf ("%d",&first);
		}
			
	
	while (total>=1)
	{
		if(first = 1)
	
			printf("What stack would you like to subtract from?\n");
				scanf("%d", &PStack);
			printf("How many would you like to take away from this stack?\n");
				scanf("%d", &PChoice);
			
				if (PStack = 1)
				{
					stack1 = stack1 - PChoice;
					playerturn++;
				}
				
				if (PStack = 2)
				{
					stack2 = stack2 - PChoice;
					playerturn++;
				}
			
				else
				{
					stack3 = stack3 - PChoice;
					playerturn++;
				}
			
					printf("Stack 1 = %d Stack 2 = %d Stack 3 = %d\n", stack1, stack2, stack3);
				

		if (BinaryConvert (stack1, stack2, stack3) >= 0)
		{
			while (stack1 > 1 && stack2 > 1 && stack3 > 1)
			{
			if (stack1 = 1 && stack2 > 1 && stack3 > 1)
			{				
				stack2 = stack2 - 1;
				aiturn++;
			}
				if (stack2 = 1 && stack1 > 1 && stack3 > 1)
			{
				stack1 = stack1 - 1;
				aiturn++;
			}
		
			if (stack3 = 1 && stack1 > 1 && stack2 > 1)
			{
				stack1 = stack1 - 1;
				aiturn++;
			}
			
			}
		}
		if (ai_stack = stack1)
		{
			stack1 = ai_value;
			printf("Stack 1 = %d Stack 2 = %d Stack 3 = %d\n", stack1, stack2, stack3);
			aiturn++;
		}

		if (ai_value = stack2)
		{
			stack2 = ai_value;
			printf("Stack 1 = %d Stack 2 = %d Stack 3 = %d\n", stack1, stack2, stack3);
			aiturn++;
		}

		if (ai_value = stack3)
		{
			stack3 = ai_value;
			printf("Stack 1 = %d Stack 2 = %d Stack 3 = %d\n", stack1, stack2, stack3);
			aiturn++;
		}
	


	}
}




int BinaryConvert (int stack1, int stack2, int stack3)
{
	if (((stack1^stack2)^stack3) > 0)
		return 0;
	else
		return 1;
}

void AI (int stack1, int stack2, int stack3, int *ai_stack, int *ai_value)
{

	int difference;

	if (stack1 < stack3 && stack2 < stack3)
	{
		if((stack1 + stack2) < stack3)
		{
			stack3    = stack1 + stack2;
			*ai_stack = 3;
			*ai_value = stack3;
		}
		
		else
		{
			difference = (stack1 + stack2) - stack3;

			if (stack1 > stack2)
			{
				stack2    = stack2 - difference;
				*ai_stack = 2;
				*ai_value = stack3;
			}

			if (stack1 < stack2)
			{
				stack1    = stack1 - difference;
				*ai_stack = 1;
				*ai_value = stack1;
			}

			if (stack1 == stack2)
			{
				stack1    =  stack1 - difference;
				*ai_stack = 1;
				*ai_value = stack1;
			}
		}
	}

	if (stack2 > stack1 && stack2 > stack3)
	{
		if((stack1 + stack3) < stack2)
		{
			stack2    = stack1 + stack3;
			*ai_stack = 2;
			*ai_value = stack2;
		}

		else
		{
			difference = (stack1 + stack3) - stack2;
			
			if (stack1 > stack3)
			{
				stack1    = stack1 - difference;
				*ai_stack = 1;
				*ai_value = stack1;
			}

			if (stack1 < stack3)
			{
				stack3    = stack3 - difference;
				*ai_stack = 3;
				*ai_value = stack3;
			}

			if (stack1 == stack3)
			{
				stack1    = stack1 - difference;
				*ai_stack = 1;
				*ai_value = stack1;
			}
		}
	}

	if (stack3 < stack1 && stack2 < stack1)
	{
		if((stack2 + stack3) < stack1)
		{
			stack1    = stack2 + stack3;
			*ai_stack = 1;
			*ai_value = stack1;
		}
		else
		{
			difference = (stack2 + stack3) - stack1;

			if(stack2 > stack3)
			{
				stack2    = stack2 - difference;
				*ai_stack = 2;
				*ai_value = stack2;
			}

			if (stack2 < stack3)
			{
				stack3    = stack3 - difference;
				*ai_stack = 3;
				*ai_value = stack3;
			}

			if (stack2 == stack3)
			{
				stack2    = stack2 - difference;
				*ai_stack = 2;
				*ai_value = stack2;
			}
				
		}
	
	
	}
	
}


