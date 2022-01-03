#include<stdio.h>
#include<windows.h>
#include<time.h>

int price[7] = { 250 , 300 , 20 , 120 , 150 , 160 , 50 };
int mealTaxPrices[7];
int adultNumber,childNumber;
int usrScore = 0,compScore = 0;
void checkOptions(int usr,int comp){
	// 1 = scissor 2= paper 3=rock
	if(usr == comp){
		printf(" --------------------\n");
		printf("|    Its a tie       |\n");
		printf(" --------------------\n");
	}
	else if(usr == 1){
		if(comp == 2){
			printf(" --------------------\n");
			printf("|      You Won :)    |\n");
			printf("| You : Scissor      |\n");
			printf("| Computer : Paper   |\n");
			printf(" --------------------\n");
			usrScore++;

		}
		else {
			printf(" --------------------\n");
			printf("|     You Lose :(    |\n");
			printf("| You : Scissor      |\n");
			printf("| Computer : Rock    |\n");
			printf(" --------------------\n");

			compScore++;
		}
	}
	else if(usr == 2){
		if(comp == 1){
			printf(" --------------------\n");
			printf("|      You Lose :(   |\n");
			printf("| You : Paper        |\n");
			printf("| Computer : Scissor |\n");
			printf(" --------------------\n");
		    compScore++;
		}
		else {
			printf(" --------------------\n");
			printf("|     You Won :)     |\n");
			printf("| You : Paper        |\n");
			printf("| Computer : Rock    |\n");
			printf(" --------------------\n");

			usrScore++;
		}
	}
	else if(usr == 3){
		if(comp == 1){
			printf(" --------------------\n");
			printf("|      You Won :)    |\n");
			printf("| You : Rock        |\n");
			printf("| Computer : Scissor |\n");
			printf(" --------------------\n");
			usrScore++;
		}
		else {
			printf(" --------------------\n");
			printf("|     You Lose :(    |\n");
			printf("| You : Rock         |\n");
			printf("| Computer : Paper    |\n");
			printf(" --------------------\n");

			compScore++;
		}
	}
	else if(usr == 4){
		printf(" --------------------\n");
		if(usrScore > compScore)
		printf("|      You Won :)    |\n");
		else if (usrScore < compScore)
		printf("|     You Lose :(    |\n");
		else
		printf("|      Its a tie     |\n");
		printf("|     Final Score    |\n");
		printf("| You : %d            |\n",usrScore);
		printf("| Computer: %d        |\n",compScore);
		printf(" --------------------\n");
		printf("\a");
	}
	else {
		Beep(750,500);
		printf("\n Invalid Option");
	}

}
void mainrockpaperscissors() {
int userChoice,compChoice;
srand(time(0));
printf("\t\t\t\t==========*Welcome to Rock, Paper & Scissor Game*==========");
while(userChoice != 4){
printf("\nPlease select the option: ");
printf("\n1.Scissor");
printf("\n2.Paper");
printf("\n3.Rock");
printf("\n4.Quit\n");
scanf("%d",&userChoice);

compChoice = (rand() % 3) + 1;   // If random numbers are generated with rand() without first calling srand(), 
				//your program will create the same sequence of numbers each time it runs.
checkOptions(userChoice,compChoice);
printf("THANKYOU FOR PLAYING :)");
}
}
void mainbankingsystem()
 { int pin=1234,option,enteredPin,count=0,amount=1; float balance=5000; 
 int continueTransaction=1;
  time_t now; time(&now); 
 printf("\n"); printf("\t\t\t\t\t %s",ctime(&now)); 
 printf("\n\t\t\t=======================Welcome to ATM=======================");

while(pin != enteredPin){
    printf("\nPlease enter your pin : ");
    scanf("%d",&enteredPin);
    if(enteredPin !=pin){
        Beep(610,320);
        printf("Invalid pin!!!");
    }
    count++;
    if(count==3 && enteredPin!=pin){
        return 0;
    }
}
while(continueTransaction !=0){
printf("\n\t\t\t====================*Available Transactions================");
printf("\n\n\t\t1.Withdrawal");
printf("\n\t\t2.Deposit");
printf("\n\t\t3.Check Balance");
printf("\n\n\tPlease select an option : ");
scanf("%d",&option);
switch(option){
    case 1:
    while(amount % 500 !=0){
        printf("\n\t\tEnter the amount :");
        scanf("%d",&amount);
        if(amount % 500 !=0)
        printf("\n\tThe amount must be multiples of 500");
    }
    if(balance < amount){
        printf("\n\t Sorry insufficient balance");
        amount=1;
        break;
    }
    else{
        balance -=amount;
        printf("\n\t\tYou have withdrawn Rs.%d  your new balance is Rs.%f",amount,balance);
        amount=1;
        break;
    }
    case 2:
    printf("\n\t\t Please enter the amount : ");
    scanf("%d",&amount);
    balance+=amount;
    printf("\n\t\t You have deposited Rs.%d  your new balance is Rs.%f",amount,balance);
    amount=1;
    break;
    
    case 3:
    printf("\n\t\t Your balance is Rs.%f",balance);
    break;
    
    default:
    Beep(610,320);
    printf("\n\t\t Invalid option!!");
}
printf("\n\n\t\t Do you wish to perform another Transaction? press 1[yes],0[no]");
scanf("%d",&continueTransaction);
}
printf("\n\t\t        Thank you for banking\n");

}
void printMeals()
{

    printf("\20*******************  WELCOME TO SRM RESTURANT **************************\20\n");
    printf(" \t\t\t Below is the menue:\20\n");
    printf(" \t\t\t MEALS\t\t\tPRICE:\n");
    printf(" \t\t\t \22*******************************\22\n");
    printf(" \t\t\t 1- Veg Biryani\t\t250/-\n");
    printf(" \t\t\t 2- Special Meal\t300/-\n");
    printf(" \t\t\t 3- Roti\t\t20/-\n");
    printf(" \t\t\t 4- Dal\t\t\t120/-\n");
    printf(" \t\t\t 5- Paneer Tikka\t150/-\n");
    printf(" \t\t\t 6- Veg mix\t\t160/-\n");
    printf(" \t\t\t 7- Icecream\t\t50/-\n");



    printf("\n");
}
void orderMeals()
{
	int totalPriceForAdult, totalPriceForChildren;
	int allPayment,discount;
    printf("                      \t\t**** ORDER MENUE****\n");

	totalPriceForAdult =  orderForAdult();
    totalPriceForChildren = orderForChildren();
	allPayment = totalPriceForAdult + totalPriceForChildren ;

    printf("\n \t\t     \22**************************************\22    \n");
    printf(" \t\t   ******************  final BILL   ************      \n");
    printf(" \t\t\tadult/child\tcount\t\ttotal price\n");
    printf(" \t\t\tadults\t\t%d\t\t%d\n",adultNumber,totalPriceForAdult);
    printf(" \t\t\tchildren\t%d\t\t%d\n",childNumber,totalPriceForChildren);
    printf(" \t\t\tTotal bill\t\t\t%d\n",allPayment );



    if(allPayment < 100)
	discount=((allPayment * 0.5)/100);
    else if(allPayment>= 100 && allPayment<200)
    discount=((allPayment * 1)/100);
    else if(allPayment>= 200 && allPayment<300)
    discount=((allPayment * 1.5)/100);
    else if(allPayment>= 300 && allPayment<400)
    discount=((allPayment * 2.0)/100);
	else
	discount= ((allPayment * 5.0)/100);

    printf(" \t\t\tTotal bill after discount\t%d\n",allPayment-discount);

}
int orderForAdult()
{
    int menuOption,i,amount;
    char response = 'y';
    double totalPerPerson = 0.0,totalAllPerson = 0.0;
    double tax = 5.0;
    if(adultNumber <=0)
	printf("\n ");
	else
    printf("*\tadults:\n");
    for(i=0;i<adultNumber;i++)
    {
        printf("adult %d please enter your orders\n",i+1);
        while(response == 'y' || response == 'Y')
        {
            printf("please enter your option:");
            scanf("%d",&menuOption);
			if(menuOption<1 || menuOption>7)
			{
				printf("sorry we don`t have this order \nagain! ");
				continue;
			}
            printf("please enter your amount of order:");
            scanf("%d",&amount);
			totalPerPerson = totalPerPerson + (amount * price[menuOption - 1] );
			printf("\nWould you like to enter more orders(y/n):");
            scanf("\n%c",&response);



        }
        printf("\n");
        totalAllPerson += totalAllPerson +  totalPerPerson;
        totalPerPerson = 0.0;
        response = 'y';
    }

    return totalAllPerson + ((totalAllPerson * tax) / 100);
}

int orderForChildren()
{
    int menuOption,i,amount;
    char response = 'y';
    double totalPerChild = 0.0,totalAllChildren = 0.0;
    double tax = 5.0,oneOrder;
    if(childNumber <=0)
	printf("\n");
	else
    printf("*\tChildren:\n");
    for(i=0;i<childNumber;i++)
    {
        printf("child %d please enter your orders\n",i+1);
        while(response == 'y' || response == 'Y')
        {
            printf("please enter your option:");
            scanf("%d",&menuOption);
			if(menuOption<1 || menuOption>7)
			{
				printf("sorry we don`t have this order \nagain! ");
                continue;
			}
            printf("please enter your amount of order:");
            scanf("%d",&amount);

            oneOrder = (price[menuOption - 1] * 60)/100 ;//this one order for a child with discount %60 of one order of adult
            totalPerChild = totalPerChild + (amount * oneOrder)  ;

			printf("Would you like to enter more orders(y/n):");
            scanf("\n%c",&response);


        }
        totalAllChildren += totalAllChildren +  totalPerChild;
        response = 'y';
        totalPerChild = 0.0;

        printf("\n");

    }

    return totalAllChildren + ((totalAllChildren * tax) / 100);
}







int main()
{
	int abc;
	char ch;
	printf("Hello! WELCOME TO OUR MINI PROJECT\n");
	do{
		printf("PRESS 1 TO PLAY ROCK-PAPER-SCISSORS\nPRESS 2 FOR ATM BANKING\nPRESS 3 FOR RESTURANT BILLING\n");
		scanf("%d",&abc);
		if(abc==1)
		{
			mainrockpaperscissors();
			
		}
		else if(abc==2)
		{
			mainbankingsystem();
			
		}
		else if(abc==3)
		{
		
    		char response = 'y';
			printMeals();
    		while(response == 'y'|| response == 'Y')
    		{
    			printf("please enter number of adults  :");
        		scanf("%d",&adultNumber);

        		printf("please enter number of children:");
        		scanf("%d",&childNumber);

				orderMeals();

        		printf("\nwould you like to continue(y/n):");
        		scanf("\n%c",&response);
    		}

 			printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
 			printf("\20**********************   PLEASE VISIT US NEXT TIME  **************************\20 \n");
 			
		}
		else
		{
			printf("\nInvalid option");
			Beep(750,500);
		}
		
		printf("\nWOULD YOU LIKE TO GO BACK TO MENU(y/n)?\n");
		scanf(" %c",&ch);
	}
	while(ch=='y');
	return 0;
}