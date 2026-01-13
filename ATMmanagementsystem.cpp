#include<iostream>
#include<cstring>
#include<ctime> 
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<sstream>
using namespace std;

ofstream complainwrite("complain.txt");
ifstream complainread("complain.txt");
int malecount = 0;
int femalecount = 0;
int index = -1;
int currentuserindex = 0;
int userid[100] = {};
char password[100][20];
int agedivision[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
long double balance[100] = {0, 0, 0, 0, 0};
long double transactionextrema[1000] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int TransactionNum[100] = { 0, 0, 0, 0, 0 };
char transactiondate[150][20];
long double transactionamount[150] = {};
long double transactionbalance[150] = {};

long double numericvalidator(int check);
void swap(long double & x, long double & y);
int SearchInt(int arr[], int size, int key);
void readcomplain();
void information();
int highandlowtrans();
int requestbalance();
int depositmoney();
int withdrawmoney();
void adminbalances();
void admintransactions();
int adminconsole();
void managerconsole();
void costumerconsole();
int usertransactions();
int operationsmenu();
int createaccount();
int login();
int mainmenu();

int main()           //calls main menu and then starts the program
{
	int x = 1;
	while (x) 
	{
		x = mainmenu();
	}
	system("pause");
	return 0;
}
long double numericvalidator(int check) {      //to check that numeric input is passed
	long double number; 
	int x = 1;
	cin.clear();
	cin.ignore(250, '\n');         //clears previous variable
	cin >> number;
	bool condition = 0;
	if (check == 1) {
		while (x) {
			if (!cin || (signed long int)number % 10 != 0 || (signed long int)number != number || number < 0) {
				cin.clear();
				cin.ignore(250, '\n');
				cout << "\t" << "Invalid Input! Enter again: ";
				cin >> number;
			}
			else {
				return number;
			}
		}
	}
	else if (check == 2) {
		while (x) {
			if (!cin || (signed long int)number != number || number < 0) {
				cin.clear();
				cin.ignore(250, '\n');
				cout << "\t" << "Invalid Input!Enter again : ";
				cin >> number;
			}
			else {
				return number;
			}
		}
	}
	else {
		if (!cin || number < 0) {
			cin.clear();
			cin.ignore(250, '\n');
			cout << "\t" << "Invalid Input! Enter again: ";
			cin >> number;
		}
		else {
			return number;
		}
	}
}

void swap(long double & x, long double & y)      
{
	long double temp;
	temp = x;
	x = y;
	y = temp;
}

int SearchInt(int arr[], int size, int key) 
{
	bool found = false;
	int i = 0;
	while (i < size) {
		if (arr[i] == key) {
			found = true;
			break;
		}
		i++;
	}
	if (found == true) {
		return i;
	}
	else {
		return -1;
	}
}
void readcomplain()                   //complains in file
{
	string com;                         //reads file on its own
	ostringstream ss;  
	ss << complainread.rdbuf();       //read buffer
	com = ss.str();                   //convert to string and then store

	cout << "complain of user are:" << endl << endl;
	cout << com << endl;
}
void information()          //getting information,age,gender of user
{
	char gender;
	bool infinity = true;
	while (infinity)
	{
		cout << "are you a male or a female? (M for male & F for Female)" << endl;
		gender = _getch();          //no need to press enter
		if (gender == 'M' || gender == 'm')
		{
			malecount++;
			cout << 'm' << endl;
			infinity = false;
		}
		else if (gender == 'F' || gender == 'f')
		{
			femalecount++;
			cout << 'f' << endl;
			infinity = false;
		}
		else
		{
			cout << "Invalid character" << endl;
			infinity = true;
		}
	}

	int age;
	cout << "Entre your age:";
	cin >> age;

	if (age >= 0 && age < 10)
	{
		agedivision[0]++;
	}
	else if (age >= 10 && age < 20)
	{
		agedivision[1]++;
	}
	else if (age >= 20 && age < 30)
	{
		agedivision[2]++;
	}
	else if (age >= 30 && age < 40)
	{
		agedivision[3]++;
	}
	else if (age >= 40 && age < 50)
	{
		agedivision[4]++;
	}
	else if (age >= 50 && age < 60)
	{
		agedivision[5]++;
	}
	else if (age >= 60 && age < 70)
	{
		agedivision[6]++;
	}
	else if (age >= 70 && age < 80)
	{
		agedivision[7]++;
	}
	else if (age >= 80 && age < 90)
	{
		agedivision[8]++;
	}
	else if (age >= 90 && age < 100)
	{
		agedivision[9]++;
	}
	else
	{
		cout << "you are over age" << endl;
	}
}

int highandlowtrans()    //gives the transactions of user
{          
	cout << "\t" << "Highest amount of Transaction: " << transactionextrema[index + 5] << endl;
	cout << "\t" << "Lowest amount of Transaction: " << transactionextrema[index] << endl;
	system("pause");
	return 0;
}
int requestbalance()        //calculte balance in account
{
 	long double currentbalance = balance[index];
	cout << "\t" << "\tYour balance is RS." << currentbalance << "." << endl;
	system("pause");
	return 0;
}
int depositmoney()       //deposit money in account
{
	long double depositamount;
	int transactionindex = ((index+1)*3);
	cout << "\t" << "Enter Amount of deposit: Rs.";
	depositamount = numericvalidator(0);
	balance[index] = balance[index] + depositamount;

	time_t now;      //getting system time
	time(&now);
	char dt[100];
strcpy(dt, ctime(&now));
	if (dt[strlen(dt) - 1] == '\n') dt[strlen(dt) - 1] = '\0';

	for (int i = 0; i < 24; i++)
	{
		transactiondate[transactionindex - 1][i] = transactiondate[transactionindex - 2][i];
	}
	for (int i = 0; i < 24; i++)
	{
		cout << ".";
		transactiondate[transactionindex - 2][i] = transactiondate[transactionindex - 3][i];
	}

	

	for (int i = 0; i < 24; i++)
	{
		transactiondate[transactionindex - 3][i] = dt[i];
	}

	transactionamount[transactionindex - 1] = transactionamount[transactionindex - 2];
	transactionamount[transactionindex - 2] = transactionamount[transactionindex - 3];
	transactionamount[transactionindex - 3] = depositamount;

	transactionbalance[transactionindex - 1] = transactionbalance[transactionindex - 2];
	transactionbalance[transactionindex - 2] = transactionbalance[transactionindex - 3];
	transactionbalance[transactionindex - 3] = balance[index];
	
	if (TransactionNum[index] == 0) {
		transactionextrema[index] = depositamount;
		transactionextrema[index + 5] = depositamount;
	}
	else if (depositamount < transactionextrema[index]) {
		transactionextrema[index] = depositamount;
	}
	else if (depositamount > transactionextrema[index+5]) {
		transactionextrema[index+5] = depositamount;
	}
	TransactionNum[index]++;
	cout << "\t" << "Deposit successful!" << endl;
	operationsmenu();
	system("pause");
	return 0;
}
int withdrawmoney()      //withdraw money from account having demoninations for tens
{
	int inputvalid = 1;
	int transactionindex = ((index + 1) * 3);
	long double withdrawalrequest;
	long double currentbalance;
	int currentdenomination;
	cout << "\tAmount of withdrawal: ";
	withdrawalrequest = numericvalidator(1);
	currentbalance = balance[index];
	while (withdrawalrequest > currentbalance) {
		cout << "\t" << "Insufficient amount!Please enter again; ";
		system("pause");
		system("cls");
		operationsmenu();
		withdrawalrequest = numericvalidator(1);
	}
	currentbalance = currentbalance - withdrawalrequest;
	balance[index] = currentbalance;
	if (TransactionNum[index] == 0) {
		transactionextrema[index] = withdrawalrequest;
		transactionextrema[index + 5] = withdrawalrequest;
	}
	else if (withdrawalrequest < transactionextrema[index]) {
		transactionextrema[index] = withdrawalrequest;
	}
	else if (withdrawalrequest > transactionextrema[index + 5]) {
		transactionextrema[index + 5] = withdrawalrequest;
	}

	time_t now;
	time(&now);
	char dt[100];
strcpy(dt, ctime(&now));
	if (dt[strlen(dt) - 1] == '\n') dt[strlen(dt) - 1] = '\0';

	for (int i = 0; i < 24; i++)
	{
		transactiondate[transactionindex - 1][i] = transactiondate[transactionindex - 2][i];
	}
	for (int i = 0; i < 24; i++)
	{
		cout << "_";
		transactiondate[transactionindex - 2][i] = transactiondate[transactionindex - 3][i];
	}

	

	for (int i = 0; i < 24; i++)
	{
		transactiondate[transactionindex - 3][i] = dt[i];
	}

	transactionamount[transactionindex - 1] =  transactionamount[transactionindex - 2];
	transactionamount[transactionindex - 2] = transactionamount[transactionindex - 3];
	transactionamount[transactionindex - 3] = withdrawalrequest*(-1);

	transactionbalance[transactionindex - 1] = transactionbalance[transactionindex - 2];
	transactionbalance[transactionindex - 2] = transactionbalance[transactionindex - 3];
	transactionbalance[transactionindex - 3] = balance[index];
	TransactionNum[index]++;
	cout << "\tCash Withdrawal for Rs. " << withdrawalrequest << " requested" << endl;
	if ((int)withdrawalrequest / 5000 != 0){
		currentdenomination = (int)withdrawalrequest / 5000;
		cout << "\tDenomination for 5000s are --> " << currentdenomination << endl;
		withdrawalrequest = withdrawalrequest - (long double)currentdenomination * 5000;
	}
	if ((int)withdrawalrequest / 1000 != 0){
		currentdenomination = (int)withdrawalrequest / 1000;
		cout << "\tDenomination for 1000s are--> " << currentdenomination << endl;
		withdrawalrequest = withdrawalrequest - (long double)currentdenomination * 1000;
	}
	if ((int)withdrawalrequest / 500 != 0){
		currentdenomination = (int)withdrawalrequest / 500;
		cout << "\tDenomination for 500s are --> " << currentdenomination << endl;
		withdrawalrequest = withdrawalrequest - (long double)currentdenomination * 500;
	}
	if ((int)withdrawalrequest / 100 != 0){
		currentdenomination = (int)withdrawalrequest / 100;
		cout << "\tDenomination for 100s are --> " << currentdenomination << endl;
		withdrawalrequest = withdrawalrequest - (long double)currentdenomination * 100;
	}
	if ((int)withdrawalrequest / 50 != 0){
		currentdenomination = (int)withdrawalrequest / 50;
		cout << "\tDenomination for 50s are --> " << currentdenomination << endl;
		withdrawalrequest = withdrawalrequest - (long double)currentdenomination * 50;
	}
	if ((int)withdrawalrequest / 20 != 0){
		currentdenomination = (int)withdrawalrequest / 20;
		cout << "\tDenomination for 20s are --> " << currentdenomination << endl;
		withdrawalrequest = withdrawalrequest - (long double)currentdenomination * 20;
	}
	if ((int)withdrawalrequest / 10 != 0){
		currentdenomination = (int)withdrawalrequest / 10;
		cout << "\tDenomination for 10s are --> " << currentdenomination << endl;
		withdrawalrequest = withdrawalrequest - (long double)currentdenomination * 10;
	}
	system("pause");
	return 0;
}
void adminbalances()          // balance in account of each user
{
	int tempids[5];
	long double tempbal[5];
	int i = 0, j=0;
	while (i < currentuserindex) {
		tempids[i] = userid[i];
		i++;
	}
	i = 0;
	while (i < currentuserindex) {
		tempbal[i] = balance[i];
		i++;
	}
	//sorting - Descending ORDER
	for (i = 0; i<currentuserindex; i++)
	{
		for (j = i + 1; j<currentuserindex; j++)
		{
			if (tempbal[i]<tempbal[j])
			{
				swap(tempbal[i], tempbal[j]);
				swap(tempids[i], tempids[j]);
				
			}
		}
	}

	for (i = 0; i<currentuserindex; i++)
	{
		cout << "\t" << tempids[i] << "\t" << tempbal[i] << endl;
	}
	system("pause");
}
void admintransactions()  //transactions by each user
{
	int i = 0;
	while (i < currentuserindex)
	{
		cout << "\t" << userid[i] << "\t";

		time_t now;
		time(&now);
		char dt[100];
	strcpy(dt, ctime(&now));
		if (dt[strlen(dt) - 1] == '\n') dt[strlen(dt) - 1] = '\0';
		cout << dt;

		cout << "\t" << TransactionNum[i] << endl;
		i++;
	}
	system("pause");
}
int adminconsole()       //menu in admin console
{
	char option;
	system("CLS");
	cout << "\t" << endl;
	cout << "\t" << "A--> All Accounts Balance Report" << endl;
	cout << "\t" << "T--> Total Transactions Report" << endl;
	cout << "\t" << "M--> Return to Mainmenu" << endl;
	cout << "\t" << "Your input: ";
	cin >> option;
	if (option == 'a') {
		adminbalances();
		return 1;
	}
	else if (option == 't') {
		admintransactions();
		return 1;
	}
	else if (option == 'm') {
		return 0;
	}
	else {
		cout << "\t" << "Please enter only one of the above mentioned options." << endl;
		system("pause");
		return 1;
	}
}
void managerconsole()          //tells which gender and agegroup is using more
{
	system("cls");
	if (malecount > femalecount)
	{
		cout << "Higest frequency is of MALE" << endl;
	}
	else if (malecount < femalecount)
	{
		cout << "Higest frequency is of FEMALE" << endl;
	}
	else
	{
		cout << "both MALE and FEMALE has 50-50 frequency" << endl;
	}

	int index;
	int highestagegroup = agedivision[0];
	for (int i = 0; i < 9; i++)
	{
		if (agedivision[i] < agedivision[i + 1])
		{
			highestagegroup = agedivision[i + 1];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (highestagegroup == agedivision[i])
		{
			index = i;
			break;
		}
	}

	cout << "Maximum members are of the agegroup " << index * 10 << " - " << (index + 1) * 10 << endl << endl;

	readcomplain();

	system("pause");
}
void costumerconsole()          //gets complains from user
{
	char c;
	bool lop = true;
	system("CLS");
	cout << "Do you have any complain? (Y or N)" << endl;
	while (lop)
	{
		c = _getch();
		if (c == 'y' || c == 'Y')
		{
			char com[100];
			cout << "Entre your complain and press entre:" << endl;
			cin >> ws;
			cin.getline(com,100);
			complainwrite << com;
			complainwrite << endl;
			lop = false;
		}
		else if (c == 'n' || c == 'N')
		{
			//do nothing
			lop = false;
		}
		else
		{
			cout << "Invalid character pressed" << endl;
			lop = true;
		}
	}
	cout << "Your complain has been registerd!" << endl;
	system("pause");
}
int usertransactions()   //shows transation of user
{
	int transactionindex = ( (index + 1) * 3 )-3;
	for (int i = 0; i < 3; i++){
		cout << "\tUser Account: \t" << userid[index] << "\n \tDate: \t";
		for (int j = 0; j < 24; j++)
		{
			cout << transactiondate[transactionindex + i][j];
		}
		cout << "\n \tType: \t";
		if (transactionamount[transactionindex + i] < 0) 
		{
			cout << "Withdrawal";
		}
		else if (transactionamount[transactionindex + i]==0) 
		{
			cout << "NONE!";
		}
		else 
		{
			cout << "Deposit";
		}
		cout << "\n \tAmount: \t" << transactionamount[transactionindex + i] << "\n \tRemaining Balance: \t" << transactionbalance[transactionindex + i] << endl;
		cout << "------------------------------------ \n";
	}
	system("pause");
	return 0;
}
int operationsmenu() //menu opens after login in account to make transactions
{
	char option;
	cout << endl;
	system("CLS");
	cout << "\t" << "D--> Deposit Money" << endl;
	cout << "\t" << "W--> Withdraw Money" << endl;
	cout << "\t" << "R--> Request Balance" << endl;
	cout << "\t" << "T--> Transaction History" << endl;
	cout << "\t" << "H--> Highest & Lowest Transaction" << endl;
	cout << "\t" << "M--> Return to Mainmenu" << endl;
	cout << "\t" << "Please select an option: ";
	cin >> option;
	if (option == 'w' || option == 'W') {
		withdrawmoney();
		return 1;
	}
	else if (option == 'd' || option == 'D') {
		depositmoney();
		return 1;
	}
	else if (option == 'r' || option == 'R') {
		requestbalance();
		return 1;
	}
	else if (option == 't' || option == 'T') {
		usertransactions();
		return 1;
	}
	else if (option == 'h' || option == 'H') {
		highandlowtrans();
		return 1;
	}
	else if (option == 'm' || option == 'M') {
		return 0;
	}
	else {
		cout << "\t" << "Please enter only one of the above mentioned options." << endl;
		system("pause");
		return 1;
	}
}
int createaccount() //creats accounts of users
{
	int username;
	int x;
	cout << "\t" << "Enter your username: ";
	while (true)
	{
		username = numericvalidator(2);
		x = SearchInt(userid, currentuserindex, username);
		if (x == -1) {
			userid[currentuserindex] = username;

			char pass[20] = "";
			char currentpassentry = 0;
			cout << "\t" << "Enter your passsword: ";
			int passsize = 0;
			while (true)
			{
				currentpassentry = _getch();
				if (currentpassentry == 13 && pass == "")
				{
					cout << "\t" << "Error! Password should contain atleast 1 character." << endl;
					cout << "\t" << "Please enter again: ";
				}
				else if (currentpassentry == 13)
				{
					passsize++;
					break;
				}
				else if (currentpassentry == 8)
				{
					passsize--;
					cout << "\b";
					cout << " ";
					cout << "\b";
				}
				else
				{
					pass[passsize] = currentpassentry;
					cout << "*";
					passsize++;
				}
			}
			pass[passsize] = '\0';
			for (int i = 0; i < 20; i++)
			{
				password[currentuserindex][i] = pass[i];
			}

			cout << "\n\tAccount Creation Successful!\n\t";
			currentuserindex++;
			system("pause");
			return 0;
		}
		else {
			cout << "\t" << "Error: Username already exist! Please enter again:";
		}
	}
	return 0;
}
int login()  //same password and username is required to login
{
	int username;
	int userlocate;
	system("cls");
	cout << "\t" << "Please Enter your username: ";
	username = numericvalidator(2);

	char pass[20] = "";
	char currentpassentry = 0;
	cout << "\t" << "Enter your passsword: ";
	int passsize = 0;
	while (true)
	{
		currentpassentry = _getch();
		if (currentpassentry == 13 && pass == "")
		{
			cout << "\t" << "Error! Password should contain atleast 1 character." << endl;
			cout << "\t" << "Please enter again: ";
		}
		else if (currentpassentry == 13)
		{
			passsize++;
			break;
		}
		else if (currentpassentry == 8)
		{
			passsize--;
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else
		{
			pass[passsize] = currentpassentry;
			cout << "*";
			passsize++;
		}
	}
	pass[passsize] = '\0';

	userlocate = SearchInt(userid, 10, username);
	if (userlocate != -1) 
	{
		bool check = false;
		int size = strlen(password[userlocate]);
		for (int i = 0; i < size; i++)
		{
			if (password[userlocate][i] == pass[i])
			{
				check = true;
			}
			else
			{
				check = false;
				break;
			}
		}
		if (check) 
		{
			cout << endl << "\t" << "Login successful!" << endl;
			system("pause");
			system("cls");
			index = userlocate;
			int x = 1;
			information();
			while (x) 
			{
				x = operationsmenu();
			}
		}
		else 
		{
			cout << endl << "\t" << "Sorry! Incorrect Password!" << endl;
			system("pause");
		}
	}
	else {
		cout << endl << "\t" << "Sorry! User not found!" << endl;
		system("pause");
	}
	return 0;
}
int mainmenu()  //first menu to show to select consoles
{
	char option;
	cout << endl;
	system("CLS");
	cout << "\t" << "Welcome to ATM Management System." << endl;
	cout << "\t" << "Please choose one of the following options:" << endl;
	cout << "\t" << "A--> Create an account" << endl;
	cout << "\t" << "B--> Login" << endl;
	cout << "\t" << "C--> Admin Console" << endl;
	cout << "\t" << "D--> Manager Console" << endl;
	cout << "\t" << "E--> Costumer Console" << endl;
	cout << "\t" << "F--> Quit" << endl;
	cout << "\t" << "Please select an option: ";
	cin >> option;
	if (option == 'a' || option == 'A') 
	{
		createaccount();
		return 1;
	}
	else if (option == 'b' || option == 'B') 
	{
		login();
		return 1;
	}
	else if (option == 'c' || option == 'C') 
	{
		int x = 1;
		while (x) {
			x = adminconsole();
		}
		return 1;
	}
	else if (option == 'd' || option == 'D')
	{
		managerconsole();
		return 1;
	}
	else if (option == 'e' || option == 'E')
	{
		costumerconsole();
		return 1;
	}
	else if (option == 'f' || option == 'F') {
		cout << "\t" << "Program Exiting!" << endl;
		return 0;
	}
	else 
	{
		cout << "\t" << "Please enter only one of the above mentioned options." << endl;
		system("pause");
		return 1;
	}
}

