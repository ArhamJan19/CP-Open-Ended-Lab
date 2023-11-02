#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	string nameArray[10] = { "", "", "", "", "", "", "", "", "", "" };
	string registrationArray[10] = { "", "", "", "", "", "", "", "", "", "" };
	time_t borrowTime[10] = { 0 };
	string bookArray[10] = { "Fourth Wing", "Tom Lake", "Too Late", "A Court of Thorns and Roses", "Atomic Habits", "It Ends With Us", "Icebreaker", "It Starts With Us", "The Housemaid", "American Prometheus" };
	bool available[10] = { true, true, true, true, true, true, true, true, true, true };
	int menuChoice, bookChoice, check;
	check = 0;
	do {
		cout << endl << "MENU" << endl;
		cout << "1. Looking to Borrow a book" << endl;
		cout << "2. Looking to Return a borrowed book" << endl;
		cout << "3. Quit" << endl;
		cout << "Enter your choice : ";
		cin >> menuChoice;
		if (menuChoice == 1) {

			for (int i = 0; i < 10; i++)
			{
				cout << i + 1 << ". " << bookArray[i] << endl;
			}
			cout << endl;
			cout << "which book do you want to borrow ? : ";
			cin >> bookChoice;
			int Index = bookChoice - 1;
			if (bookChoice >= 1 && bookChoice <= 10)
			{
				if (available[Index] == true)
				{
					cout << "Before we can issue this book, we just need a few details " << endl;
					cout << "Enter your name : ";
					cin >> nameArray[Index];
					cout << "Enter your Registration Number (XX-XXXXXX-XXX) : ";
					cin >> registrationArray[Index];
					cout << endl << "Congratulations! You just borrowed " << "'" << bookArray[Index] << "'" << " You have 1 week to return this book" << endl;
					borrowTime[Index] = time(0);
				}
				else
				{
					cout << endl << "Oops! This Book has already been borrowed" << endl;
				}
			}
			else
			{
				cout << "Invalid book choice. " << endl;
			}
		}

		else if (menuChoice == 2) {
			string regCheck = "";
			cout << "Please enter your Registration Number: ";
			cin >> regCheck;
			int bookCheck = 0;

			for (int i = 0; i < 10; i++) {
				if (regCheck == registrationArray[i]) {
					string check = "";
					cout << "Do you want to return '" + bookArray[i] + "'? (" << endl;
					cin >> check;
					if (check == "Yes" || check == "yes") {
						time_t returnTime = time(0);
						time_t timeCheck = difftime(returnTime, borrowTime[i]);
						int days = timeCheck / 86400;
						if (days > 7) {
							int dayCheck = days - 7;
							cout << endl << "You have to pay a fine of $" << dayCheck << endl;
						}
						registrationArray[i] = "";
						cout << endl << "Congratulations! You have returned '" + bookArray[i] + "'." << endl;
					}
					bookCheck = 1;
				}
			}
			if (bookCheck == 0) {
				cout << "You have not borrowed any book." << endl;
			}
		}
		else if(menuChoice == 3){
			cout << endl << "Goodbye!" << endl;
			check == 1;
			break;
		}

	} while (check != 1);

	
	
	return 0;
}

