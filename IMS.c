#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
struct credentials
{
	char username[40];
	char password[40];
} cred;
struct product
{
	int id;
	char name[100];
	float price;
	int quantity;
	char description[200];
	char category[100];
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int second;

} pro;
void gotoxy(int, int);
void display();
void loginSystem();
void createAccount();
void menu();
void addProduct();
void removeProduct();
void displayProduct();
void searchProduct();
void modifyProduct();
void loadingBar();

int main()
{
	system("pause");
	system("cls");
	system("color 0B");

	display();
	
	return 0;
}
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void display()
{
	int c;
	gotoxy(36, 2);
	printf("+----------------------------------------------------------------+\n");
	gotoxy(37, 3);
	printf("|            Welcome To Inventory Management System            |\n");
	gotoxy(36, 4);
	printf("+----------------------------------------------------------------+\n");
	gotoxy(46, 6);
	printf("+-----------------------------+\n");
	gotoxy(47, 7);
	printf("|     1.Login Account ");
	gotoxy(75, 7);
	printf("|");
	gotoxy(46, 8);
	printf("+-----------------------------+\n");

	gotoxy(46, 9);
	printf("+-----------------------------+\n");
	gotoxy(47, 10);
	printf("|     2.Create Account ");
	gotoxy(75, 10);
	printf("|");
	gotoxy(46, 11);
	printf("+-----------------------------+\n");

	gotoxy(46, 12);
	printf("+-----------------------------+\n");
	gotoxy(47, 13);
	printf("|     3.Exit ");
	gotoxy(75, 13);
	printf("|");
	gotoxy(46, 14);
	printf("+-----------------------------+\n");

	gotoxy(90, 9);
	printf("+-----------------------------+\n");
	gotoxy(91, 10);
	printf("| Enter Your Choice :  ");
	gotoxy(119, 10);
	printf("|");
	gotoxy(90, 11);
	printf("+-----------------------------+\n");
	fflush(stdin);
	gotoxy(113, 10);
	scanf("%d", &c);

	switch (c)
	{
	case (1):
		system("cls");
		loginSystem();
		break;

	case (2):
		system("cls");
		createAccount();
		break;

	case (3):
		system("cls");
		exit(1);
	}
}
void loginSystem()
{
	FILE *fp;

	fp = fopen("credentials.txt", "rb");

	char username[40];
	char password[40];

	gotoxy(36, 2);
	printf("+----------------------------------------------------------------+\n");
	gotoxy(37, 3);
	printf("|            Welcome To Inventory Management System            |\n");
	gotoxy(36, 4);
	printf("+----------------------------------------------------------------+\n");

	gotoxy(46, 6);
	printf("+--------------------------------------------+\n");
	gotoxy(47, 7);
	printf("|  Enter Username : ");
	gotoxy(90, 7);
	printf("|");
	gotoxy(46, 8);
	printf("+--------------------------------------------+\n");

	gotoxy(46, 9);
	printf("+--------------------------------------------+\n");
	gotoxy(47, 10);
	printf("|  Enter Password : ");
	gotoxy(90, 10);
	printf("|");
	gotoxy(46, 11);
	printf("+--------------------------------------------+\n");
	fflush(stdin);
	gotoxy(68, 7);
	gets(username);
	fflush(stdin);
	gotoxy(68, 10);
	gets(password);

	while(fread(&cred, sizeof(cred), 1, fp)){
	if (strcmp(cred.username, username) == 0 && strcmp(cred.password, password) == 0)
	{
		system("cls");
		loadingBar();
		system("cls");
		system("color 0B");
		menu();
	}
	}
	if(strcmp(cred.username, username) != 0 || strcmp(cred.password, password) != 0)
	{
		MessageBox(NULL, "Invalid Credentials!", "Confirmation", MB_OK);
		system("cls");
		loginSystem();
	}
	

	fclose(fp);
}
void createAccount()
{

	FILE *fp;

	fp = fopen("credentials.txt", "ab+");

	gotoxy(46, 6);
	printf("+--------------------------------------------+\n");
	gotoxy(47, 7);
	printf("|  Enter Username : ");
	gotoxy(90, 7);
	printf("|");
	gotoxy(46, 8);
	printf("+--------------------------------------------+\n");

	gotoxy(46, 9);
	printf("+--------------------------------------------+\n");
	gotoxy(47, 10);
	printf("|  Enter Password : ");
	gotoxy(90, 10);
	printf("|");
	gotoxy(46, 11);
	printf("+--------------------------------------------+\n");
	fflush(stdin);
	gotoxy(68, 7);
	gets(cred.username);
	fflush(stdin);
	gotoxy(68, 10);
	gets(cred.password);
	gotoxy(68, 13);

	fwrite(&cred, sizeof(cred), 1, fp);

	fclose(fp);
    
	system("cls");
	gotoxy(68, 13);
	MessageBox(NULL, "Account Created Successfully!", "Welcome", MB_OK);
	system("cls");
	loginSystem();
}
void menu()
{
	int c;
	gotoxy(36, 2);
	printf("+-------------------------------------------+\n");
	gotoxy(38, 3);
	printf("| Welcome To Inventory Management System |\n");
	gotoxy(36, 4);
	printf("+-------------------------------------------+\n");
	gotoxy(42, 7);
	printf("|  1. Add Product             |\n");
	gotoxy(42, 8);
	printf("|  2. Remove Product          |\n");
	gotoxy(42, 9);
	printf("|  3. Display Product         |\n");
	gotoxy(42, 10);
	printf("|  4. Modify Product Details  |\n");
	gotoxy(42, 11);
	printf("|  5. Search Product          |\n");
	gotoxy(42, 12);
	printf("|  6. Log Out                 |\n");
	gotoxy(42, 13);
	printf("|  7. Exit                    |\n");
	gotoxy(36, 15);
	printf("+-------------------------------------------+\n");
	gotoxy(45, 17);
	printf("Enter Menu Number : ");
	scanf("%d", &c);

	switch (c)
	{
	case (1):
		system("cls");
		addProduct();
		break;
	case (2):
		system("cls");
		removeProduct();
		break;
	case (3):
		system("cls");
		displayProduct();
		break;
	case (4):
		system("cls");
		modifyProduct();
		break;
	case (5):
		system("cls");
		searchProduct();
		break;
	case (6):
		system("cls");
		loadingBar();
		system("cls");
		system("color 0B");
		display();
		break;
	case(7):
	    system("cls");
		exit(1);
	default:
		gotoxy(45, 18);
		printf("Invalid Input");
	}
}
void addProduct()
{

	FILE *fp;

	fp = fopen("Product.txt", "ab+");

	int c = 1;
	time_t current_time = time(NULL); // Get current time in seconds
	struct tm *local_time = localtime(&current_time);

	int hours = local_time->tm_hour;
	int minutes = local_time->tm_min;
	int seconds = local_time->tm_sec;
	int day = local_time->tm_mday;
	int month = local_time->tm_mon + 1;
	int year = local_time->tm_year + 1900;

	while (c == 1)
	{
		system("cls");
		gotoxy(35, 2);
		printf("Product Name : ");
		scanf("%s", pro.name);
		srand(time(0));
		pro.id = rand() % (int)pow(10, 5);
		gotoxy(35, 4);
		printf("Product Price : ");
		fflush(stdin);
		scanf("%f", &pro.price);
		gotoxy(35, 6);
		printf("Product Quantity : ");
		fflush(stdin);
		scanf("%d", &pro.quantity);
		gotoxy(35, 8);
		printf("Product Category : ");
		fflush(stdin);
		gets(pro.category);
		gotoxy(35, 10);
		printf("Product Description : ");
		fflush(stdin);
		gets(pro.description);
		pro.day = day;
		pro.month = month;
		pro.year = year;
		pro.hour = hours;
		pro.minute = minutes;
		pro.second = seconds;
		fwrite(&pro, sizeof(pro), 1, fp);
		gotoxy(90, 4);
		printf("Do You Want To Add More Products?");
		gotoxy(90, 5);
		printf("1.Yes");
		gotoxy(90, 6);
		printf("2.No");
		gotoxy(90, 7);
		printf("Enter Your Choice : ");
		scanf("%d", &c);
	}
	fclose(fp);
	system("cls");
	menu();
}
void removeProduct()
{

	FILE *fp, *temp;

	fp = fopen("Product.txt", "rb");
	temp = fopen("temp.txt", "ab+");

	int c, id;
	int flag = 0;
	char name[100];
	char choice;

	int answer;

	gotoxy(42, 7);
	printf("What Do You Want To Search By?");
	gotoxy(42, 8);
	printf("1.ID");
	gotoxy(42, 9);
	printf("2.Name");
	gotoxy(42, 11);
	printf("Enter Your Choice : ");
	scanf("%d", &c);
	
	system("cls");
	switch (c)
	{
	case (1):
		gotoxy(42, 6);
		printf("Enter Product ID : ");
		fflush(stdin);
		scanf("%d", &id);
		while (fread(&pro, sizeof(pro), 1, fp) == 1)
		{
			if (id == pro.id)
			{
				flag = 1;
				fclose(fp);
			}
		}
		if (flag == 0)
		{
			printf("\n\nRecord Not Found against %d", id);
			system("pause");
			system("cls");
			menu();
		}
		fp = fopen("Product.txt", "rb");
		while (flag == 1)
		{
			system("cls");
			fflush(stdin);
			answer = MessageBox(NULL, "Are you sure you want to remove? [Y/N]", "Confirmation", MB_YESNO);
			if (answer == IDYES)
			{
				system("cls");
				loadingBar();
				system("cls");
				system("color 0B");
				gotoxy(60, 5);
				printf("Removed Successfully!");
				printf("\n\n");
				while (fread(&pro, sizeof(pro), 1, fp) == 1)
				{
					if (id == pro.id)
					{
						printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");
						printf("|       ID      |        Name         |        Price       |      Quantity      |          Category          |          Description           |         Time / Date         |\n");
						printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");

						printf("| %9d     |       %-10s    |      %-14f|       %-13d|             %-15s|               %-17s|     %d:%d:%d / %d-%d-%d    |\n", pro.id, pro.name, pro.price, pro.quantity, pro.category, pro.description, pro.hour, pro.minute, pro.second, pro.day, pro.month, pro.year);
						printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");
					}
					else if (id != pro.id)
					{
						fwrite(&pro, sizeof(pro), 1, temp);
					}
				}

				fclose(fp);
				fclose(temp);

				remove("Product.txt");
				rename("temp.txt", "Product.txt");
			}
			else if (answer == IDNO)
			{
				system("cls");
				menu();
			}
			gotoxy(10, 16);
			printf("1.Main Menu : ");
			gotoxy(10, 17);
			printf("2.Exit : ");
			gotoxy(10, 18);
			fflush(stdin);
			scanf("%d", &c);
			if (c == 1)
			{
				system("cls");
				menu();
			}
			else
			{
				system("cls");
				exit(1);
			}

			break;
		}
	case (2):
		gotoxy(42, 6);
		printf("Enter Product Name : ");
		fflush(stdin);
		gets(name);
		while (fread(&pro, sizeof(pro), 1, fp) == 1)
		{
			if (strcmp(name, pro.name) == 0)
			{
				flag = 1;
				fclose(fp);
			}
		}
		if (flag == 0)
		{
			printf("\n\nRecord Not Found against %s", name);
			system("pause");
			system("cls");
			menu();
		}
		fp = fopen("Product.txt", "rb");
		while (flag == 1)
		{
			system("cls");
			gotoxy(70, 7);
			answer = MessageBox(NULL, "Are you sure you want to remove? [Y/N]", "Confirmation", MB_YESNO);
			if (answer == IDYES)
			{
				system("cls");
				loadingBar();
				system("cls");
				system("color 0B");
				printf("Removed Successfully!");
				printf("\n\n");
				while (fread(&pro, sizeof(pro), 1, fp) == 1)
				{
					if (strcmp(name, pro.name) == 0)
					{
						printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");
						printf("|       ID      |        Name         |        Price       |      Quantity      |          Category          |          Description           |         Time / Date         |\n");
						printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");

						printf("| %9d     |       %-10s    |      %-14f|       %-13d|             %-15s|               %-17s|     %d:%d:%d / %d-%d-%d    |\n", pro.id, pro.name, pro.price, pro.quantity, pro.category, pro.description, pro.hour, pro.minute, pro.second, pro.day, pro.month, pro.year);
						printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");
					}
					else if (strcmp(name, pro.name) != 0)
					{
						fwrite(&pro, sizeof(pro), 1, temp);
					}
				}

				fclose(fp);
				fclose(temp);
				remove("Product.txt");
				rename("temp.txt", "Product.txt");
			}
			else if (answer == IDNO)
			{
				system("cls");
				menu();
			}
			gotoxy(10, 16);
			printf("1.Main Menu : ");
			gotoxy(10, 17);
			printf("2.Exit : ");
			gotoxy(10, 18);
			fflush(stdin);
			scanf("%d", &c);
			if (c == 1)
			{
				system("cls");
				menu();
			}
			else
			{
				system("cls");
				exit(1);
			}
			break;
		}
	}
}

void displayProduct()
{

	int c;
	FILE *fp;
	int i;
	fp = fopen("Product.txt", "rb");
	if (fp == NULL)
	{
		gotoxy(30, 6);
		perror("Error opening file: ");
		for (i = 0; i < 7; i++)
		{
			Beep(500, 900);
		}
		system("cls");
		exit(1);
	}
	printf("\n\n\n\n");
	printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");
	printf("|       ID      |        Name         |        Price       |      Quantity      |          Category          |          Description           |         Time / Date         |\n");
	printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");

	while (fread(&pro, sizeof(pro), 1, fp) == 1)
	{
		printf("| %9d     |       %-10s    |      %-14f|       %-13d|             %-15s|               %-17s|     %d:%d:%d / %d-%d-%d    |\n", pro.id, pro.name, pro.price, pro.quantity, pro.category, pro.description, pro.hour, pro.minute, pro.second, pro.day, pro.month, pro.year);
		printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");
	}
	fclose(fp);
	gotoxy(10, 1);
	printf("1.Main Menu : ");
	gotoxy(10, 2);
	printf("2.Exit : ");
	fflush(stdin);
	gotoxy(10, 3);
	scanf("%d", &c);
	if (c == 1)
	{
		system("cls");
		menu();
	}
	else
	{
		system("cls");
		exit(1);
	}
}

void searchProduct()
{
	FILE *fp;
	fp = fopen("Product.txt", "rb");

	int c, id;
	char name[100];
	int flag = 0;

	gotoxy(42, 7);
	printf("What do you want to search by?");
	gotoxy(42, 8);
	printf("1.ID");
	gotoxy(42, 9);
	printf("2.Name");
	gotoxy(42, 11);
	printf("Enter Your Choice : ");
	scanf("%d", &c);
    
	system("cls");
	switch (c)
	{
	case (1):
		gotoxy(35, 2);
		printf("Enter Product ID : ");
		fflush(stdin);
		scanf("%d", &id);
		system("cls");
		break;

	case (2):
		gotoxy(35, 2);
		printf("Enter Product Name : ");
		fflush(stdin);
		gets(name);
		system("cls");
		break;
	}

	system("cls");
		while (fread(&pro, sizeof(pro), 1, fp) == 1 && flag == 0)
		{
			if (id == pro.id || (strcmp(name, pro.name) == 0))
			{
				printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");
				printf("|       ID      |        Name         |        Price       |      Quantity      |          Category          |          Description           |         Time / Date         |\n");
				printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");

				printf("| %9d     |       %-10s    |      %-14f|       %-13d|             %-15s|               %-17s|     %d:%d:%d / %d-%d-%d     |\n", pro.id, pro.name, pro.price, pro.quantity, pro.category, pro.description, pro.hour, pro.minute, pro.second, pro.day, pro.month, pro.year);
				printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");

				flag = 1;
			}
			else if (flag == 0)
			{
				gotoxy(70, 5);
				printf("Record NOT Found!");
				flag = 1;
			}
		}
		fclose(fp);
		gotoxy(10, 13);
		printf("1.Search Another Product : ");
		gotoxy(10, 14);
		printf("2.Main Menu : ");
		gotoxy(10, 15);
		fflush(stdin);
		scanf("%d", &c);
		if (c == 1)
		{
			system("cls");
			searchProduct();
		}
		else if (c == 2)
		{
			system("cls");
			menu();
		}

}
void modifyProduct()
{
	FILE *fp;
	int id, c, found = 0;
	char name[100];
	char newName[100], newDescription[200], newCategory[100];
	float newPrice;
	int newQuantity;

	fp = fopen("Product.txt", "rb+");

	gotoxy(42, 7);
	printf("What do you want to search by?");
	gotoxy(42, 8);
	printf("1.ID");
	gotoxy(42, 9);
	printf("2.Name");
	gotoxy(42, 11);
	printf("Enter Your Choice : ");
	scanf("%d", &c);
	system("cls");
	switch (c)
	{
	case (1):
		gotoxy(35, 2);
		printf("Enter Product ID : ");
		fflush(stdin);
		scanf("%d", &id);
		break;

	case (2):
		gotoxy(35, 2);
		printf("Enter Current Product Name : ");
		fflush(stdin);
		gets(name);
		break;
	}

	while (fread(&pro, sizeof(pro), 1, fp))
	{
		if (pro.id == id | (strcmp(name, pro.name) == 0))
		{

			found = 1;
			system("cls");
			printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");
			printf("|       ID      |        Name         |        Price       |      Quantity      |          Category          |          Description           |         Time / Date         |\n");
			printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");

			printf("| %9d     |       %-10s    |      %-14f|       %-13d|             %-15s|               %-17s|     %d:%d:%d / %d-%d-%d     |\n", pro.id, pro.name, pro.price, pro.quantity, pro.category, pro.description, pro.hour, pro.minute, pro.second, pro.day, pro.month, pro.year);
			printf("+---------------+---------------------+--------------------+--------------------+----------------------------+--------------------------------+-----------------------------+\n");

			gotoxy(35, 6);
			printf("Enter New Product Name : ");
			fflush(stdin);
			gets(newName);
			gotoxy(35, 8);
			printf("Enter New Product Price : ");
			fflush(stdin);
			scanf("%f", &newPrice);
			gotoxy(35, 10);
			printf("Enter New Product Quantity : ");
			fflush(stdin);
			scanf("%d", &newQuantity);
			gotoxy(35, 12);
			printf("Enter New Product Category : ");
			fflush(stdin);
			gets(newCategory);
			gotoxy(35, 14);
			printf("Enter New Product Description : ");
			fflush(stdin);
			gets(newDescription);

			strcpy(pro.name, newName);
			pro.price = newPrice;
			pro.quantity = newQuantity;
			strcpy(pro.description, newDescription);
			strcpy(pro.category, newCategory);

			fseek(fp, -sizeof(pro), SEEK_CUR);
			fwrite(&pro, sizeof(pro), 1, fp);
			break;
		}
	}

	if (found == 0)
	{
		system("cls");
		gotoxy(70, 5);
		printf("Product not found\n");
	}
	else
	{
		system("cls");
		gotoxy(70, 5);
		printf("Product updated successfully\n");
	}

	fclose(fp);
	gotoxy(10, 11);
	printf("1.Modify Another Product : ");
	gotoxy(10, 12);
	printf("2.Display All Products : ");
	gotoxy(10, 13);
	printf("3.Main Menu : ");
	gotoxy(10, 14);
	printf("4.Exit : ");
	gotoxy(10, 15);
	fflush(stdin);
	scanf("%d", &c);
	if (c == 1)
	{
		system("cls");
		modifyProduct();
	}
	else if (c == 2)
	{
		system("cls");
		displayProduct();
	}
	else if (c == 3)
	{
		system("cls");
		menu();
	}
	else if (c == 4)
	{
		system("cls");
		exit(1);
	}
}
void loadingBar()
{
	system("color 0A");

	char a = 177, b = 219;

	printf("\n\n\n\n");
	printf("\n\n\n\n\t\t\t\t\t");
	printf("Loading...\n\n");
	printf("\t\t\t\t\t");

	for (int i = 0; i < 26; i++)
		printf("%c", a);

	printf("\r");
	printf("\t\t\t\t\t");

	for (int i = 0; i < 26; i++)
	{
		printf("%c", b);

		Sleep(50);
	}
}
