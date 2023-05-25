#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


  typedef struct{
	char name[50];
	int bus_num;
	int num_of_seats;
}pd;





void reservation(void);
void viewdetails(void);
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);



int main()

{

	printf("\t\t|           BUS TICKET RERSERVATION SYSTEM           |\n");

    printf("\t\t------------------------------------------------------\n");
    printf("\t\t---------------press Enter key  --------------\n");
    printf("\t\t------------------------------------------------------\n");
	getch();

	int menu_choice,choice_return;
	start:

	printf("\n=================================\n");
	printf("    BUS RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>.Reserve A Ticket\n2>.View All Available Bus\n3>. Exit");
	printf("\n-------------------------------------");
	printf("\n\n->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			printf("\n\nPress Backspace key to go to Main Menu..");
			getch();
			break;
		case 3:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

void viewdetails(void)
{
    printf("\nBUS.No\BUS Name\t\t\tDestinations\t\tfare\t\tTime\n");
	printf("\n960711\tBus A\t sangli to solapur\t\t\tRs.200\t\t9am");
	printf("\n960712\tBus B\t solapur to pune \t\t\tRs.500\t\t12pm");
	printf("\n960713\tBus C\t satara to  pune\t\t\t\Rs.100\t\t8am");
	printf("\n960714\tBus D\t kohlapur to solapur\t\t\tRs.350\t\t11am");
	printf("\n960715\tBus E\t kohlapur to mumbai\t\t\tRs.500\t\t7am");

}


void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);

	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Bus<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter bus number:> ");
	start1:
	scanf("%d",&passdetails.bus_num);
	if(passdetails.bus_num>= 960711&& passdetails.bus_num<=960715)
	{
		charges=charge(passdetails.bus_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
	}
	else
	{
		printf("\nInvalid bus Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
		printf("==================");
		printf("\n Reservation successful\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float charge(int bus_num,int num_of_seats)
{
		if (bus_num==960711)
	{
		return(200.0*num_of_seats);
	}
	if (bus_num==960712)
	{
		return(500.0*num_of_seats);
	}
	if (bus_num==960713)
	{
		return(100.0*num_of_seats);
	}
	if (bus_num==960714)
	{
		return(350.0*num_of_seats);
	}
	if (bus_num==960715)
	{
		return(500.0*num_of_seats);
	}
}

void printticket(char name[],int num_of_seats,int bus_num,float charges)
{

	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nBus Number:\t\t%d",bus_num);
	specificbus(bus_num);
	printf("\nCharges:\t\t%.2f",charges);
}

void specificbus(int bus_num)
{

	if (bus_num==960711)
	{
		printf("\nBus:\t\t\tBUS A");
		printf("\nDestination:\t\t sangli to solapur");
		printf("\nDeparture:\t\t9am ");
	}
	if (bus_num==960712)
	{
		printf("\nBus:\t\t\tBUS B");
		printf("\nDestination:\t\t solapur to pune");
		printf("\nDeparture:\t\t12pm");
	}
	if (bus_num==960713)
	{
		printf("\nBus:\t\t\tBUS C");
		printf("\nDestination:\t\t satara to pune ");
		printf("\nDeparture:\t\t8am");
	}
	if (bus_num==960714)
	{
		printf("\nBus:\t\t\tBUS D");
		printf("\nDestination:\t\t kohlapur  to  solapur");
		printf("\nDeparture:\t\t11am ");
	}
	if (bus_num==960715)
	{
		printf("\nBus:\t\t\tBUS C");
		printf("\nDestination:\t\t kohlapur to  mumbai");
		printf("\nDeparture:\t\t7am");
	}

}
