#include<stdio.h>
#include<windows.h>
#include<time.h>

int price[7] = { 250 , 300 , 20 , 120 , 150 , 160 , 50 };
int mealTaxPrices[7];
int adultNumber,childNumber;

struct library {
    char book_name[20];
    char author[20];
    int pages;
    float price;
};


void mainlibrary()
{

    struct library lib[100];

    char ar_nm[30], bk_nm[30];

    int i, input, count;

    i = input = count = 0;

    while (input != 5) {

        printf("\n\n*************"
               "WELCOME TO E-LIBRARY "
               "*************\n");
        printf("\n\n1. Add book infor"
               "mation\n2. Display "
               "book information\n");
        printf("3. List all books of "
               "given author\n");
        printf(
            "4. List the count of book"
            "s in the library\n");
        printf("5. Exit");

        printf("\n\nEnter one of "
               "the above: ");
        scanf("%d", &input);

        switch (input) {

        case 1:

            printf("Enter Book Name = ");
            scanf("%s", lib[i].book_name);

            printf("Enter Author Name = ");
            scanf("%s", lib[i].author);

            printf("Enter Pages = ");
            scanf("%d", &lib[i].pages);

            printf("Enter Price = ");
            scanf("%f", &lib[i].price);
            count++;

            break;


        case 2:
            printf("You have entered"
                   " the following "
                   "information\n");
            for (i = 0; i < count; i++) {

                printf("book name = %s",
                       lib[i].book_name);

                printf("\t author name = %s",
                       lib[i].author);

                printf("\t  pages = %d",
                       lib[i].pages);

                printf("\t  price = %f",
                       lib[i].price);
            }
            break;


        case 3:
            printf("Enter Author Name : ");
            scanf("%s", ar_nm);
            for (i = 0; i < count; i++) {

                if (strcmp(ar_nm,
                           lib[i].author)== 0)
                   {
					        printf("book name = %s",
                       lib[i].book_name);

                printf("\t author name = %s",
                       lib[i].author);

                printf("\t  pages = %d",
                       lib[i].pages);

                printf("\t  price = %f",
                       lib[i].price);
            }

            }
            break;


        case 4:
            printf("\n No of books in "
                   "library : %d",
                   count);
            break;
        case 5:
          printf("\nTHANKYOU FOR USING E-LIBRARY:)");
        }
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
		printf("PRESS 1 FOR LIBRARY MANAGEMENT SYSTEM\nPRESS 2 FOR ATM BANKING\nPRESS 3 FOR RESTURANT BILLING\n");
		scanf("%d",&abc);
		if(abc==1)
		{
			mainlibrary();

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
