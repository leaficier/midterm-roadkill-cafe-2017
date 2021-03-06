/*
Nick Leif - Midterm
*/

#include "stdafx.h"
#include <iostream>	
#include <fstream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	//variables for date and time
	string dayAttending;
	char amORpm, cMenu = NULL, first_dayAttending;
	int standardTimeAttending, militaryTimeAttending = 0;

	//varibles for status of cafe and store
	bool storeStatus, cafeStatus;

	//display banner and hours
	cout << endl;
	cout << "Welcome to Murphy's Roadkill Cafe!" << endl << endl;
	cout << "Cafe Hours: " << endl << "=================================" << endl;
	cout << "Sunday 5 AM - 11 PM" << endl << "Monday 5 AM - 11 PM" << endl << "Tuesday 5 AM - 11 PM" << endl << "Wednesday 5 AM - 11 PM" << endl << "Thursday 5 AM - 11 PM" << endl << "Friday 5 AM - 11 PM" << endl << "Saturday 5 AM - 11 PM" << endl << endl;
	cout << "Store Hours: " << endl << "=================================" << endl;
	cout << "Sunday 7 AM - 10 PM" << endl << "Monday 8 AM - 8 PM" << endl << "Tuesday 8 AM - 8 PM" << endl << "Wednesday 8 AM - 8 PM" << endl << "Thursday 8 AM - 8 PM" << endl << "Friday 8 AM - 8 PM" << endl << "Saturday 7 AM - 10 PM" << endl << endl;

	//time and date selection loop
	while (true)
	{
		//find day of week visiting and put into string: dayAttending. Make dayAttending string all lower case for easier manipulation
		//www.stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
		cout << "What day of the week will you be attending?" << endl;
		getline(cin, dayAttending);
		transform(dayAttending.begin(), dayAttending.end(), dayAttending.begin(), tolower);

		//find what time visiting and wether its AM or PM
		cout << "And what hour of the day (Hour, a = AM or p = PM)?" << endl;
		cin >> standardTimeAttending >> amORpm;

		//if statement for PM times
		if (amORpm == 'p')
		{
			//if time is 12 PM, military time is also 12
			if (standardTimeAttending == 12)
			{
				//assigns militaryTime variable and displays what day of week and time was chosen
				militaryTimeAttending = 12;
				cout << "You have selected: " << dayAttending << " at " << standardTimeAttending << "PM" << endl;
				break;
			}
			else
			{
				//assigns militaryTime variable and displays what day of week and time was chosen
				militaryTimeAttending = standardTimeAttending + 12;
				cout << "You have selected: " << dayAttending << " at " << standardTimeAttending << "PM." << endl;
				break;
			}
		}

		//if statement for AM times
		else if (amORpm == 'a')
		{
			//if time is 12 AM, military time is 24
			if (standardTimeAttending == 12)
			{
				//assigns militaryTime variable and displays what day of week and time was chosen
				militaryTimeAttending = 24;
				cout << "You have selected: " << dayAttending << " at " << standardTimeAttending << "AM" << endl;
				break;
			}
			else
			{
				//assigns militaryTime variable and displays what day of week and time was chosen
				militaryTimeAttending = standardTimeAttending;
				cout << "You have selected: " << dayAttending << " at " << standardTimeAttending << "AM" << endl;
				break;
			}
		}
	}
	system("PAUSE");
	system("CLS");

	//grab first character of string first_dayAttending for easier manipulation
	first_dayAttending = dayAttending[0];
	cout << endl;

	//variables for the cafe
	string cafeItem1B_name = "Rat Egg Omlette", cafeItem2B_name = "Rabbit Leg Pancakes", cafeItem3B_name = "Armadillo Coffee";
	string cafeItem1L_name = "Rattle Snake Quesadilla", cafeItem2L_name = "Turtle Soup", cafeItem3L_name = "Ratatouille";
	double const cafeItem1B_price = 8.50, cafeItem2B_price = 11.00, cafeItem3B_price = 3.50;
	double const cafeItem1L_price = 7.50, cafeItem2L_price = 6.75, cafeItem3L_price = 15.00;
	int cafeItem1L_stock = 10, cafeItem2L_stock = 10, cafeItem3L_stock = 10;
	int cafeItem1B_order = 0, cafeItem2B_order = 0, cafeItem3B_order = 0, cafeItem1L_order = 0, cafeItem2L_order = 0, cafeItem3L_order = 0;
	int satisfaction;
	char cafeChoice = NULL;
	double total = 0, tax = 0;

	//variables for the juke box
	int jukeQuaters = 1;
	int songLength = 0, playTime =0;
	string songString, songName;
	ifstream infile;
	ofstream outfile;

	//variables for the store
	double const storeItem_1_price = 19.99, storeItem_2_price = 37.99, storeItem_3_price = 50.00, storeTax = 0.0725;
	double  storeTotal = 0, restockTotal = 0;
	int storeItem_1_stock = 5, storeItem_2_stock = 5, storeItem_3_stock = 5;
	string storeItem_1_name = "Snowglobe[S]", storeItem_2_name = "Toy Roadkill[T]", storeItem_3_name = "Barrel of Mice[B]";
	char storeChoice = NULL;
	

	//control menu	
	while (true) {
		system("CLS");
		//check if cafe is open
		//for mon - sun
		if (((first_dayAttending == 'm') || (first_dayAttending == 't')) || ((first_dayAttending == 'w') || (first_dayAttending == 'f')) || (first_dayAttending == 's'))
		{
			//if time is between 5 and 23 say cafe is open
			if ((militaryTimeAttending >= 5) && (militaryTimeAttending <= 23))
			{
				cout << "Cafe[C] - OPEN" << endl;
				cafeStatus = true;
			}
			//if time is not between 5 and 23 say cafe is closed and set cafe status to false
			else if ((militaryTimeAttending <= 4) || (militaryTimeAttending == 24))
			{
				cout << "Cafe[C] - CLOSED" << endl;
				cafeStatus = false;
			}
		}

		//check if store is open
		//on weekdays mon - fri
		if (((first_dayAttending == 'm') || (first_dayAttending == 't')) || ((first_dayAttending == 'w') || (first_dayAttending == 'f')))
		{
			//if time is between 8 and 20 say store is open
			if ((militaryTimeAttending >= 8) && (militaryTimeAttending <= 20))
			{
				cout << "Store[S] - OPEN" << endl;
				storeStatus = true;
			}
			//if time is not between 8 and 20 say store is closed and set store status to false
			else if ((militaryTimeAttending <= 7) || (militaryTimeAttending >= 21))
			{
				cout << "Store[S] - CLOSED" << endl;
				storeStatus = false;
			}
		}

		//on weekends sat and sun
		else if (first_dayAttending == 's')
		{
			//if time is between 7 and 22 say store is open
			if ((militaryTimeAttending >= 7) && (militaryTimeAttending <= 22))
			{
				cout << "Store[S] - OPEN" << endl;
				storeStatus = true;
			}
			//if time is not between 7 and 22 say store is closed and set store status to false
			else if ((militaryTimeAttending <= 6) || (militaryTimeAttending >= 23))
			{
				cout << "Store[S] - CLOSED" << endl;
				storeStatus = false;
			}
		}

		//jukebox is open when cafe is open/true
		if (cafeStatus) cout << "Jukebox[J] - OPEN" << endl;
		else if (!(cafeStatus)) cout << "Jukebox[J] - CLOSED" << endl << endl;

		//get control menu selection
		cout << endl << "'X' to exit" << endl << endl;
		cout << endl << "What would you like to do?" << endl << "(Press a letter): " << endl;
		cin.ignore(100, '\n');
		cin >> cMenu;
		//close program if x is pressed
		if ((cMenu == 'x') || (cMenu == 'X')) break;

		//control menu switch
		switch (cMenu)
		{
		//CAFE option
		case 'C':
		case 'c':
		{
			system("CLS");

			while (true) 
			{
				if (cafeStatus) {
					cout << "++++++++++++++++++++++++++++++++" << endl << "BREAKFAST MENU           " << endl << "++++++++++++++++++++++++++++++++" << endl;
					cout << "[A] Rat Egg Omlette          " << setw(10) << setfill(' ') << setprecision(2) << showpoint << fixed << cafeItem1B_price << endl;
					cout << "[B] Rabbit Leg Pancakes      " << setw(10) << setfill(' ') << setprecision(2) << showpoint << fixed << cafeItem2B_price << endl;
					cout << "[C] Armadillo Coffee         " << setw(10) << setfill(' ') << setprecision(2) << showpoint << fixed << cafeItem3B_price << endl << endl;

					if ((militaryTimeAttending >= 11) && (militaryTimeAttending <= 20)) {
						cout << "++++++++++++++++++++++++++++++++" << endl << "LUNCH/DINNER MENU        " << endl << "++++++++++++++++++++++++++++++++" << endl;
						cout << "[D] Rattle Snake Quesadilla  " << setw(10) << setfill(' ') << setprecision(2) << showpoint << fixed << cafeItem1L_price << " - " << cafeItem1L_stock << " Remaining" << endl;
						cout << "[E] Turtle Soup              " << setw(10) << setfill(' ') << setprecision(2) << showpoint << fixed << cafeItem2L_price << " - " << cafeItem2L_stock << " Remaining" << endl;
						cout << "[F] Ratatouille              " << setw(10) << setfill(' ') << setprecision(2) << showpoint << fixed << cafeItem3B_price << " - " << cafeItem3L_stock << " Remaining" << endl << endl;
					}
					else if ((militaryTimeAttending < 11) || (militaryTimeAttending > 16)) {
						cout << "LUNCH/DINNER MENU        " << setw(10) << setfill(' ') << "NOT SERVED AT THIS TIME" << endl << endl;
					}
				}

				else if (!(cafeStatus)) {
					cout << "BREAKFAST MENU           " << setw(10) << setfill(' ') << "NOT SERVED AT THIS TIME" << endl << endl;
					cout << "LUNCH/DINNER MENU        " << setw(10) << setfill(' ') << "NOT SERVED AT THIS TIME" << endl << endl;
				}


				cout << "What would you like? (Press letter of corresponding item)" << endl << "'T' for bill" << endl << "'X' to return to control menu" << endl << endl;
				cin >> cafeChoice;

				if ((cafeChoice == 'x') || (cafeChoice == 'X')) break;

				switch (cafeChoice)
				{
				case 'A':
				case 'a':
				{
					total += cafeItem1B_price;
					cafeItem1B_order++;
					system("CLS");
					break;
				}
				case 'B':
				case 'b':
				{
					total += cafeItem2B_price;
					cafeItem2B_order++;
					system("CLS");
					break;
				}
				case 'C':
				case 'c':
				{
					total += cafeItem3B_price;
					cafeItem3B_order++;
					system("CLS");
					break;
				}
				case 'D':
				case 'd':
				{
					if (cafeItem1L_stock > 0) {
						total += cafeItem1L_price;
						cafeItem1L_order++;
						cafeItem1L_stock--;
						system("CLS");
						break;
					}
					else if (cafeItem1L_stock <= 0) {
						cout << "Sorry! That item is not available!" << endl;
						system("PAUSE");
						system("CLS");
						break;
					}
				}
				case 'E':
				case 'e':
				{
					if (cafeItem2L_stock > 0) {
						total += cafeItem1L_price;
						cafeItem2L_order++;
						cafeItem2L_stock--;
						system("CLS");
						break;
					}
					else if (cafeItem2L_stock <= 0) {
						cout << "Sorry! That item is not available!" << endl;
						system("PAUSE");
						system("CLS");
						break;
					}
				}
				case 'F':
				case 'f':
				{
					if (cafeItem3L_stock > 0) {
						total += cafeItem1L_price;
						cafeItem3L_order++;
						cafeItem3L_stock--;
						system("CLS");
						break;
					}
					else if (cafeItem3L_stock <= 0) {
						cout << "Sorry! That item is not available!" << endl;
						system("PAUSE");
						system("CLS");
						break;
					}
				}

				//get bill case
				case 'T':
				case 't':
				{
					system("CLS");
					if (cafeItem1B_order > 0) {
						cout << cafeItem1B_order << setw(4) << " x " << cafeItem1B_name << " = ";
						cout << setw(10) << setprecision(2) << showpoint << fixed << (cafeItem1B_price * cafeItem1B_price) << endl;
					}
					if (cafeItem2B_order > 0) {
						cout << cafeItem2B_order << setw(4) << " x " << cafeItem2B_name << " = ";
						cout << setw(10) << setprecision(2) << showpoint << fixed << (cafeItem2B_price * cafeItem2B_order) << endl;
					}
					if (cafeItem3B_order > 0) {
						cout << cafeItem3B_order << setw(4) << " x " << cafeItem3B_name << " = ";
						cout << setw(10) << setprecision(2) << showpoint << fixed << (cafeItem3B_price * cafeItem3B_order) << endl;
					}
					if (cafeItem1L_order > 0) {
						cout << cafeItem1L_order << setw(4) << " x " << cafeItem1L_name << " = ";
						cout << setw(10) << setprecision(2) << showpoint << fixed << (cafeItem1L_price * cafeItem1L_order) << endl;
					}
					if (cafeItem2L_order > 0) {
						cout << cafeItem2L_order << setw(4) << " x " << cafeItem2L_name << " = ";
						cout << setw(10) << setprecision(2) << showpoint << fixed << (cafeItem2L_price * cafeItem2L_order) << endl;
					}
					if (cafeItem3L_order > 0) {
						cout << cafeItem3L_order << setw(4) << " x " << cafeItem3L_name << " = ";
						cout << setw(10) << setprecision(2) << showpoint << fixed << (cafeItem3L_price * cafeItem3L_order) << endl;
					}
					cout << endl << endl << "Sub-total: " << "$" << setprecision(2) << showpoint << fixed << total << endl;
					tax = (total * 0.04125);
					cout << "Tax (4.125%): " << "$" << setprecision(2) << showpoint << fixed << tax << endl;
					cout << "Total: " << "$" << setprecision(2) << showpoint << fixed << (total + tax) << endl << endl;

					cout << "We hope you enjoyed your meal, how satisfied are you on a scale of 1 - 5 (1 = Very Unhappy, 5 = Very Happy): ";
					cin >> satisfaction;
					if (satisfaction == 3) {
						cout << "In that case, you should tip $" << ((total + tax) * 0.15) << endl;
					}
					if (satisfaction > 3) {
						cout << "In that case, you should tip $" << ((total + tax) * 0.10) << endl;

					}
					if (satisfaction < 3) {
						cout << "In that case, you should tip $" << ((total + tax) * 0.20) << endl;
					}
					system("PAUSE");
					system("CLS");
					cout << "Thanks for your money sucker, now get out!" << endl;
					system("PAUSE");
					system("CLS");
					break;
				}


				}
			}
			break;
		}

		//JUKE BOX option
		case 'J':
		case 'j':
		{
			while (cafeStatus)
			{
				system("CLS");
				//display welcome banner
				cout << "MURPH BOX v.01" << endl << endl;
				cout << "25 cents for 3 minutes of play time \nNumber of quaters: ";
				//get money input
				cin >> jukeQuaters;
				//open files
				infile.open("CafeSongs.txt");
				outfile.open("SongsPlayed.txt", std::ofstream::trunc);
				//if user enters 0 quaters, quit
				if (jukeQuaters == 0) break;
				//check if the file is open
				if (infile.is_open())
				{
					//find how much time user has and print it
					playTime = (jukeQuaters * 3);
					cout << endl << "You get " << playTime << " minutes of playtime\n\n";

					//for each line in the file, store it in a string
					while (getline(infile, songString))
					{
						//convert the string to a stream
						istringstream ss(songString);
						//assign first input(song name) to a variable and second input(song length) to a variable
						ss >> songName >> songLength;
						//if user still has time remaining, play next song
						if (playTime >= 0) 
						{
							//print name of song playing, decrese play time reamaining, output song name to output file
							cout << "NOW PLAYING: " << songName << endl << endl;
							playTime -= songLength;
							outfile << songName << endl;

						}
						//if no play time remains, exit loop
						else break;
					}
					system("PAUSE");

				}
				//if file isnt open or unable to open print this
				else cout << "Unable to open file" << endl;
				//close input file after loop is over
				infile.close();

			}
			//close output file after loop is over and display parting message
			outfile.close();
			cout << "Thank you for using MURPH BOX, have a good day!" << endl;
			system("PAUSE");
			break;
		}
		//STORE
		case 'S':
		case 's':
		{
			
			//loop for purchasing items
			while (true) {
				system("CLS");
				//welcoming banner
				cout << "Welcome to Murphy's gift shop" << endl << "We are currently: ";
				//check if store is open and if so display items with prices and description
				if (storeStatus) {
						cout << "OPEN";
						cout << endl << endl << "FOR SALE:" << endl;
						cout << storeItem_1_name << "      " << setprecision(2) << showpoint << fixed  << storeItem_1_price << " - Remaining: " << storeItem_1_stock << endl;
						cout << '\t' << "A slightly damaged Snowglobe. (Snow not included)" << endl << endl;

						cout << storeItem_2_name << "      " << setprecision(2) << showpoint << fixed << storeItem_2_price << " - Remaining: " << storeItem_2_stock << endl;
						cout << '\t' << "The catch of the day in toy form!" << endl << endl;

						cout << storeItem_3_name << "      " << setprecision(2) << showpoint << fixed << storeItem_3_price << " - Remaining: " << storeItem_3_stock << endl;
						cout << '\t' << "Like a barrel of monkeys but worse!" << endl << endl;
				}
				//if store is closed display closed sign
				else if (!(storeStatus)) cout << "CLOSED";
				//get user input for item wanted
				cout << "What would you like?" << endl << "'X' if done" << endl << "'C' to checkout " << endl << "Press letter of item: ";
				cin >> storeChoice;
				cout << endl;
				//if user inputs an x, exit program
				if ((storeChoice == 'x') || (storeChoice == 'X')) break;
				//switch statement for items, each case represents an item and will keep track of what is sold and how much remains, adds cost of item to total balance
				switch (storeChoice) {
				case 'S':
				case 's':
				{
					if (storeItem_1_stock > 0) {
						storeTotal += storeItem_1_price;
						storeItem_1_stock--;
						system("CLS");
						break;
					}
					else if (storeItem_1_stock <= 0) {
						cout << "Sorry that item is out of stock" << endl;
						system("PAUSE");
						system("CLS");
						break;
					}
				}
				case 'T':
				case 't':
				{
					if (storeItem_2_stock > 0) {
						storeTotal += storeItem_2_price;
						storeItem_2_stock--;
						system("CLS");
						break;
					}
					else if (storeItem_2_stock <= 0) {
						cout << "Sorry that item is out of stock" << endl;
						system("PAUSE");
						system("CLS");
						break;
					}
				}
				case 'B':
				case 'b':
				{
					if (storeItem_3_stock > 0) {
						storeTotal += storeItem_3_price;
						storeItem_3_stock--;
						system("CLS");
						break;
					}
					else if (storeItem_3_stock <= 0) {
						cout << "Sorry that item is out of stock" << endl;
						system("PAUSE");
						system("CLS");
						break;
					}
				}
				//checkout case
				case 'C':
				case 'c':
				{
					system("CLS");
					//display number of items bought, item name, and total cost of each item
					cout << endl << "CHECKOUT" << endl << endl;
					if (storeItem_1_stock < 5) {
						cout << (5 - storeItem_1_stock) << " x " << storeItem_1_name << setw(10) << setfill ('-') << setprecision(2) << showpoint << fixed << ((5 - storeItem_1_stock) * storeItem_1_price) << endl;
					}
					if (storeItem_2_stock < 5) {
						cout << (5 - storeItem_2_stock) << " x " << storeItem_2_name << setw(10) << setfill('-') << setprecision(2) << showpoint << fixed << ((5 - storeItem_2_stock) * storeItem_2_price) << endl;
					}
					if (storeItem_3_stock < 5) {
						cout << (5 - storeItem_3_stock) << " x " << storeItem_3_name << setw(10) << setfill('-') << setprecision(2) << showpoint << fixed << ((5 - storeItem_3_stock) * storeItem_3_price) << endl;
					}
					//display exit sign, subtotal, tax to be collected as well as tax rate, and subtotal
					cout << "Thank you for shopping at Murphy's Souviener Shop" << endl;
					cout << endl << "Subtotal: " << storeTotal;
					cout << endl << "Tax(7.25%): " << (storeTotal * storeTax);
					cout << endl << "Subtotal: " << ((storeTotal * storeTax) + storeTotal);

					//restock form
					cout << endl << endl;
					cout << "ORDER FORM" << endl;
					cout << "ITEM  -  # NEEDED  -  COST" << endl;
					//display name of item needed, amount needed, and cost to get those items
					if (storeItem_1_stock < 5) {
						cout << storeItem_1_name << " - " << (5 - storeItem_1_stock) << " - " << setprecision(2) << showpoint << fixed << ((5 - storeItem_1_stock) * storeItem_1_price) << endl;
						restockTotal += (((5 - storeItem_1_stock) * storeItem_1_price));
					}
					if (storeItem_2_stock < 5) {
						cout << storeItem_2_name << " - " << (5 - storeItem_2_stock) << " - " << setprecision(2) << showpoint << fixed << ((5 - storeItem_2_stock) * storeItem_2_price) << endl;
						restockTotal += (((5 - storeItem_2_stock) * storeItem_2_price));
					}
					if (storeItem_3_stock < 5) {
						cout << storeItem_3_name << " - " << (5 - storeItem_3_stock) << " - " << setprecision(2) << showpoint << fixed << ((5 - storeItem_3_stock) * storeItem_3_price) << endl;
						restockTotal += (((5 - storeItem_3_stock) * storeItem_3_price));
					}
					//display total cost of restock (msde + fuel + fees)
					cout << endl << setprecision(2) << showpoint << fixed << restockTotal << " + 50 (fuel) + 100 (delivery fee) =  $"<< setprecision(2)<< showpoint << fixed <<  (restockTotal + 150) << endl << endl; 

					system("PAUSE");
				}
				}
			}
			system("PAUSE");
			break;
		}

		}
	}


	system("PAUSE");
	return 0;
}
