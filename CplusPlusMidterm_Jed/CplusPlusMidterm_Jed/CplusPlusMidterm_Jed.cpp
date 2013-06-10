// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const double TAX = 1.06;

// Creating a Class for the Events
class Event{
public:
	string name;
	string type;
	string attendees[10]; // This is bad... I need to learn std::vector... Setting a max for now
	string waitingList[2];
	int capacity;
	double ticketprice;
	Event();
	Event(string name, string type, int capacity, double ticketprice);
};

// Default Constructor
Event::Event(){};

// Main Constructor
Event::Event(string e_name, string e_type, int e_capacity, double e_ticketprice){
	name = e_name;
	type = e_type;
	capacity = e_capacity;
	ticketprice = e_ticketprice;
};

// Creating a Class for the customer
// Played around a bit with encapsulated variables / functions
class Customer{
private:
	string name;
public:
	double total;
	Customer();

	void setName(string c_name){
		name = c_name;
	}
	string getName();
};

Customer::Customer() {};
string Customer::getName(){
	return name;
};

// Prototyping the Functions
void welcome_msg();
void list_events(Event events[], Customer cus);
void ticket_prompt(Event events[], int selection, Customer cus);
void buy_tickets(Event events[], int selection, int tickets, Customer cus);
void complete_order(Event events[], Customer cus);
void cancel_order(Event events[], Customer cus);
void print_ticketHolders(Event events[]);

void main()
{
	// Creating an array of Events, and populating.
	Event events[4];
	events[0] = Event("Solar Bears Hockey Game", "Sports", 10, 25);
	events[1] = Event("Tina Turner Concert", "Concert", 5, 50);
	events[2] = Event("Cats", "Play", 2, 30);
	events[3] = Event("Star Trek Convention", "Convention", 3, 10);

	Customer currentCustomer;
	// currentCustomer.setName("Jed");

	welcome_msg();
	list_events(events, currentCustomer);

	print_ticketHolders(events);
	system("pause");
}

// Says Hello
void welcome_msg(){
	cout << "Welcome to the Amway Arena!" << endl;
};

// The main function, that will ask what the Customer would like to do
// Pointers to the current customer and the events being passed in
void list_events(Event events[], Customer cus){
	// Check to see if we are sold out
	int i;
	int freeTickets = 0;
	for(i = 0; i < sizeof(events); i++){
		freeTickets += events[i].capacity;
	}

	if(freeTickets == 0){
		cout << "There are no more tickets Left! Sorry!" << endl;
	}else{
		cout << "Which of the following events are you interested in?" << endl << endl;
		// Loop through and ask about the events
		for(i = 0; i < sizeof(events); i++){
			cout << i + 1 << ": " << events[i].name << endl;
		}
		cout << endl;
		cout << "5: Complete Order" << endl;
		cout << "6: Cancel a Ticket" << endl;
		cout << "7: Exit Program" << endl;

		// Will break if this is not an int
		// TODO: Fix that!
		int choice;
		cin >> choice;
		while(choice < 1 || choice > 7){
			cout << "That's an invalid choice. Please choose from the above Menu.";
			cin >> choice;
		}

		if(choice < 5){
			// GoTo ticket prompt if 1-4
			ticket_prompt(events, choice - 1, cus);
		}else if(choice == 5){
			// GoTo complete order if 5
			complete_order(events, cus);
		}else if(choice == 6){
			// GoTo cancel order if 6
			cancel_order(events, cus);
		}else if(choice == 7){
			// Show Ticketholders / Exit Program
			// This will happen on exit by default
		}
	}
}

// This will ask the user how many tickets they would like to purchase.
// Takes in a pointer to the Event array and Customer, and an int for the menu selection.
//
// There are several checks in here to see if the user has asked for tickets to a sold out event.
// If so, they will be asked to put on teh waiting list.
void ticket_prompt(Event events[], int selection, Customer cus){
	cout << "You have chosen the Event: \n\t" << events[selection].name << endl << endl;
	cout << "Tickets are $" << events[selection].ticketprice << " a peice." << endl;
	if(events[selection].capacity > 0){
		cout << "There are " << events[selection].capacity << " tickets left. Would you like to purchase tickets? (y/n)  ";
	}else{
		cout << "There aren't any available tickets at this time." << endl
			<< "Would you like to be placed on the Waiting List? (y/n)  ";
	}

	char choice;
	cin >> choice;
	int i_choice;
	switch(choice){
	case 'y':
		if(events[selection].capacity > 0){
			cout << "Excellent. You may purchase up to 2 tickets. How many would you like?  ";
			cin >> i_choice;
		}else{
			// Only letting them reserve one...
			i_choice = 1;
		}
		
		while(i_choice < 1 || i_choice > 2){
			cout << "That's an invalid choice. Would you like 1 or 2 tickets?  ";
			cin >> i_choice;
		}

		buy_tickets(events, selection, i_choice, cus);
		break;
	default:
		cout << "Invalid Choice. Returning to the Main Menu...";
		list_events(events, cus);
	}
}

// This will go through with assigning a ticket slot to the User
// Takes in pointers to the Event Array and customer, and ints for the event menu selection and tickets ordered
void buy_tickets(Event events[], int selection, int tickets, Customer cus){
	string name;
	cout << "Please enter your name: ";
	cin.ignore();
	getline(cin, name);
	if(cus.getName().compare(name) == 0){
		// Same customer. Do nothing.
	}else{
		// Different Customer. Reset Class.
		cus = Customer();
		cus.setName(name);
		cus.total = 0;
	}

	// Let's make sure this user isn't trying to buy more than 2 tickets
	bool canbuy = true;
	int i, j;
	int ticketCount = 0;
	for(i = 0; i < (sizeof(events[selection].attendees)) / sizeof(string); i++){
		if(events[selection].attendees[i].compare(name) == 0){
			ticketCount++;
			if(ticketCount >= 2){
				canbuy = false;
				cout << cus.getName() << ", you have already purchased tickets for this event." << endl
					<< "Would you like to purchase tickets for another event? (y/n)" << endl;
		
				char choice;
				cin >> choice;
				switch(choice){
				case 'y':
					list_events(events, cus);
					break;
				default:
					cout << "Have a nice day! Goodbye." << endl;
					break;
				}
			}
		}
	}

	// Catch them if they have bought 1, and only allow for one more ticket to be bought.
	if(ticketCount == 1 && tickets == 2){
		cout << "You have already purchased one ticket, so you can only buy one more." << endl
			<< "Sorry for any inconvenience." << endl;
		tickets = 1;
	}


	// Normal buying procedure. Tickets are available.
	if(canbuy && events[selection].capacity > 0){
		cout << "Thanks " << name << ". Your total with tax for " << tickets 
			<< " ticket(s) is: $" << events[selection].ticketprice * tickets * TAX;
		if((int)((events[selection].ticketprice * tickets * TAX) * 100) % 100 == 0){
			cout << ".00";
		}else{
			cout << "0";
		} 
		cout << endl << endl;

		cout << "How would you like to proceed?" << endl
			<< "1: Confirm Tickets and buy tickets to another event" << endl
			<< "2: Confirm Tickets and complete order" << endl
			<< "3: Cancel these Tickets" << endl;

		int choice;
		cin >> choice;

		// The nitty-gritty stuff.
		// Setting all the of the variables in the pointed arrays.
		switch(choice){
		case 1:
			events[selection].capacity -= tickets;
			cus.total += (events[selection].ticketprice * tickets * TAX);
			for(i = 0; i < tickets; i++){
				for(j = 0; j < (sizeof(events[selection].attendees)) / sizeof(string); j++){
					if(events[selection].attendees[j].size() == 0){
						events[selection].attendees[j] = cus.getName();
						break;
					}
				}
			}
			list_events(events, cus);
			break;
		case 2:
			events[selection].capacity -= tickets;
			cus.total += (events[selection].ticketprice * tickets * TAX);
			for(i = 0; i < tickets; i++){
				for(j = 0; j < (sizeof(events[selection].attendees)) / sizeof(string); j++){
					if(events[selection].attendees[j].size() == 0){
						events[selection].attendees[j] = cus.getName();
						break;
					}
				}
			}
			complete_order(events, cus);
			break;
		case 3:
			cout << "This order has been cancelled. Returning to Main Menu." << endl;
			list_events(events, cus);
			break;
		default:
			cout << "This order has been cancelled. Returning to Main Menu." << endl;
			list_events(events, cus);
			break;
		}
	// This executes if a user has chosen to be added to the waiting list.
	}else if(canbuy && events[selection].capacity < 1){
		cout << "Thanks " << name << ". You have been added to the waiting list." << endl << endl;

		cout << "Now returning to Main Menu... " << endl << endl;

		for(i = 0; i < tickets; i++){
			for(j = 0; j < (sizeof(events[selection].waitingList)) / sizeof(string); j++){
				if(events[selection].waitingList[j].size() == 0){
					events[selection].waitingList[j] = cus.getName();
				}
			}
		}
		
		list_events(events, cus);
	}
}

// Called to complete the order.
// Takes in pointers to the Event array and customer
void complete_order(Event events[], Customer cus){
	cout << "Your total is: $" << cus.total;
	if((int)((cus.total) * 100) % 100 == 0){
		cout << ".00" << endl;
	}else{
		cout << "0" << endl;
	} 
	cout << "1: Pay Now" << endl
		<< "2: Return to Main Menu" << endl;

	int choice;
	cin >> choice;
	
	switch(choice){
	case 1:
		cout << "Thank you for your patronage. Have a great day!" << endl << endl;
		cus = Customer();
		list_events(events, cus);
		break;
	case 2:
		list_events(events, cus);
		break;
	default:
		list_events(events, cus);
		break;
	}
}

// Allows a user to cancel an order
// Takes in pointers to the Event array and customer
//
// This will AUTOMATICALLY look at the waiting list.
// If a user is there, they will take the cancellation's spot instantly.
void cancel_order(Event events[], Customer cus){
	cout << "Which of the following events are cancelling your order for?" << endl << endl;
	// Loop through and ask about the events
	int h, i, j;
	for(i = 0; i < sizeof(events); i++){
		cout << i + 1 << ": " << events[i].name << endl;
	}

	int selection;
	cin >> selection;
	while(selection < 1 || selection > 6){
		cout << "That's an invalid choice. Please choose from the above Menu.";
		cin >> selection;
	}
	selection -= 1;

	cout << "How many tickets are you cancelling? ";
	int tickets;
	cin >> tickets;

	// Ask for the User's Name
	string name;
	cout << "Please enter your name: ";
	cin.ignore();
	getline(cin, name);

	bool cancelled = false;
	// Main Logic. Find the user, clear them out.
	// Then check the waitingList for any users. If one is there, give them the spot.
	for(h = 0; h < tickets; h++){
		for(i = 0; i < (sizeof(events[selection].attendees)) / sizeof(string); i++){
			if(events[selection].attendees[i].compare(name) == 0){
				cout << name << ", your ticket for "
					<< events[selection].name << " has been cancelled." << endl;
				events[selection].attendees[i].clear();
				cancelled = true;
				for(j = 0; j < (sizeof(events[selection].waitingList)) / sizeof(string); j++){
					if(events[selection].waitingList[j].size() > 0){
						events[selection].attendees[i] = events[selection].waitingList[j];
						events[selection].waitingList[j].clear();
						i = (sizeof(events[selection].attendees)) / sizeof(string);
						break;
					}
				}
			}
		}
	}

	if(!cancelled){
		cout << "You did not seem to have a ticket to that event" << endl;
	}
	// Return to main Menu
	list_events(events, cus);
}

// Printing out all ticket holders at the end of the Program.
void print_ticketHolders(Event events[]){
	int i, j;
	for(i = 0; i < sizeof(events); i++){
		cout << "Event Name: " << events[i].name << endl;
		cout << "TicketHolders: " << endl;
		for(j = 0; j <(sizeof(events[i].attendees)) / sizeof(string); j++){
			if(events[i].attendees[j].size() > 0){
				cout << "\t" << events[i].attendees[j] << endl;
			}
		}
	}
}