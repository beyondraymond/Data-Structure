#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <windows.h>
#include <ctime>
#define size 10 //The size of the ticket container is set to 10 but this can be changed depending on the needed capacity

using namespace std;

enum ConsoleColors { // This enum declares the integer values for a specified color scheme.
    LightGreen = 10,
    LightCyan = 11,
    Red = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15,
    VioletYellow = 94,
    VioletWhite = 95,
    BlackWhite = 271
};

void setTextColor(ConsoleColors text);


class singleJourney{
	private:
		int container[size], front, rear, adminpin;
		int *a= NULL; // pointer a will be used to allocate for a dynamic array later on
	public:
		int start, end, n, controlnum; 
		singleJourney();
		void isWrongInput();
		bool isFull();	
		bool isEmpty();
		void enQueue();
		void generateTickets();
		int deQueue();
		void addJourney();
		void confirmJourney();
		int invalidStation(int station);
		int invalidStation(int start, int station);
		int Payment(int fare, int payment);
		int Payment(int fare, int payment, int change);
		void displayJourney(int fare);
		void printReceipt(int fare, int payment, int change);
	};

int main(){
	setTextColor(VioletYellow);
	cout<<" "<<endl;
	cout<<"\tGood day Commuter! Welcome to,"<<endl<<endl;Sleep(500); // Sleep() is a predefined c++ function that pauses a program in a specfied milliseconds
	setTextColor(VioletWhite);
	cout<<"\t#       ######  #######    #       ### #     # #######     #####  "<<endl;Sleep(500);
	cout<<"\t#       #     #    #       #        #  ##    # #          #     # "<<endl;Sleep(500);
	cout<<"\t#       #     #    #       #        #  # #   # #                # "<<endl;Sleep(500);
	cout<<"\t#       ######     #       #        #  #  #  # #####       #####  "<<endl;Sleep(500);
	cout<<"\t#       #   #      #       #        #  #   # # #          #       "<<endl;Sleep(500);
	cout<<"\t#       #    #     #       #        #  #    ## #          #       "<<endl;Sleep(500);
	cout<<"\t####### #     #    #       ####### ### #     # #######    ####### "<<endl<<endl;Sleep(1000);
	setTextColor(VioletYellow);
	cout<<setw(60)<<"\tBuy your ticket before going to the platform."<<endl;Sleep(3000);
	setTextColor(BlackWhite);
	
	singleJourney s; s.generateTickets();
	int payment, change, fare;
	string station[]={"Santolan","Katipunan","Anonas", "Cubao", "Betty Go", "Gilmore", "J.Ruiz", "V.Mapa", "Pureza", "Legarda", "Recto"}; 
	// Station array holds the list of station that is currently available in LRT line 2
	while(1){
			system("cls");
			setTextColor(LightMagenta);
			cout<<"====================================="<<endl<<endl;
			setTextColor(Yellow);
			cout<<setw(30)<<"LRT Line 2 - Purple Line"<<endl;
			cout<<setw(30)<<"Select From the Following Stations"<<endl<<endl;
			setTextColor(LightCyan);
			for(int i=0; i<11; i++){ // The list of stations in the array is displayed using for loop.
			cout<< i+1 <<" -> "<< station[i]<<"\t\t";
		    if(i%2){cout<<endl;}
		    }
			cout<<endl;
			setTextColor(LightMagenta);
			cout<<"====================================="<<endl<<endl;
			setTextColor(White);
			
			s.addJourney();
		switch(s.start)
        {
        case 0:
        	//Start == Santolan; 
        	if (s.end==1 || s.end==2 || s.end==3){
				fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==4 || s.end==5 || s.end==6){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==7 || s.end==8 || s.end==9 || s.end==10){
        		fare=25;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
            
        case 1:
            //Start == Katipunan; 
        	if (s.end==0 || s.end==2 || s.end==3 || s.end==4){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==5 || s.end==6 || s.end==7 || s.end==8){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==9 || s.end==10){
        		fare=25;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
            
        case 2:
            //Start == Anonas; 
        	if (s.end==0 || s.end==1 || s.end==3 || s.end==4 || s.end==5){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==6 || s.end==7 || s.end==8 || s.end==9){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==10){
        		fare=25;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
            
        case 3:
            //Start == Cubao; 
        	if (s.end==0 || s.end==1 || s.end==2 || s.end==4 || s.end==5 || s.end==6){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==7 || s.end==8 || s.end==9 || s.end==10){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
            
        case 4:
			//Start == Betty Go; 
        	if (s.end==7 || s.end==1 || s.end==2 || s.end==3 || s.end==5 || s.end==6){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==0 || s.end==8 || s.end==9 || s.end==10){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}         
            break;
            
        case 5:
        	//Start == Gilmmore; 
        	if (s.end==7 || s.end==8 || s.end==2 || s.end==3 || s.end==4 || s.end==6){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==0 || s.end==1 || s.end==9 || s.end==10){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
            
        case 6:
            //Start == J.Ruiz; 
        	if (s.end==7 || s.end==8 || s.end==9 || s.end==3 || s.end==4 || s.end==5){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==0 || s.end==1 || s.end==2 || s.end==10){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
            
        case 7:
            //Start == V.Mapa; 
        	if (s.end==4 || s.end==5 || s.end==6 || s.end==8 || s.end==9 || s.end==10){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==1 || s.end==2 || s.end==3){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==0){
        		fare=25;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
            
        case 8:
            //Start == Pureza; 
        	if (s.end==5 || s.end==6 || s.end==7 || s.end==9 || s.end==10){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==1 || s.end==2 || s.end==3 || s.end==4 ){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==0){
        		fare=25;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
            
        case 9:
        	//Start == Legarda; 
        	if (s.end==6 || s.end==7 || s.end==8 || s.end==10){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==2 || s.end==3 || s.end==4 || s.end==5){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==0 || s.end==1){
        		fare=25;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
		case 10:
			//Start == Recto; 
        	if (s.end==7 || s.end==8 || s.end==9){
        		fare=15;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==3 || s.end==4 || s.end==5 || s.end==6){
        		fare=20;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
			if (s.end==0 || s.end==1 || s.end==2){
        		fare=25;
        		s.displayJourney(fare);
				fare*=s.n;
        		cout<<"Please Enter Cash Amount: ";
        		cin>>payment;
        		payment=s.Payment(fare, payment);
        		change=s.Payment(fare, payment, change);
			}
            break;
            
        default:
            cout<<"Wrong choice"<<endl;
        }	
        
    system("cls");
        	
	setTextColor(LightCyan);
	cout<<"  "<<endl;
	cout<<" ######  ######  #######  #####  #######  #####   #####  ### #     #  #####                "<<endl;Sleep(500);
	cout<<" #     # #     # #     # #     # #       #     # #     #  #  ##    # #     #               "<<endl;Sleep(500);
	cout<<" #     # #     # #     # #       #       #       #        #  # #   # #                     "<<endl;Sleep(500);
	cout<<" ######  ######  #     # #       #####    #####   #####   #  #  #  # #  ####               "<<endl;Sleep(500);
	cout<<" #       #   #   #     # #       #             #       #  #  #   # # #     #     ###  ###  ### "<<endl;Sleep(500);
	cout<<" #       #    #  #     # #     # #       #     # #     #  #  #    ## #     #     ###  ###  ###"<<endl;Sleep(500);
	cout<<" #       #     # #######  #####  #######  #####   #####  ### #     #  #####      ###  ###  ### "<<endl<<endl;Sleep(1000);
	setTextColor(Yellow);
	cout<<" This may take a few seconds. Please claim your ticket/s on the bottom bin."<<endl;Sleep(2000);
	
	
		char choice;
		setTextColor(Yellow);
		cout<<" Do you want to have a printed receipt? Y/N: ";
		setTextColor(White);
		cin>>choice;
		
		//if(choice=='Y'||'y')
		while(!(choice=='N'|| choice=='n' || choice=='Y' || choice=='y')){
			setTextColor(Red);
			cout<<"Invalid Choice. Enter Again: ";
			setTextColor(White); cin>>choice;
		}
		if(choice=='N'|| choice=='n'){
		setTextColor(LightCyan);
		cout<<" -> No"<<endl;
		setTextColor(LightMagenta);
		cout<<"\t------------------------------------"<<endl<<endl;
		setTextColor(Yellow);
		cout<<"\tThank you for riding in LRT Line 2!"<<endl;
		cout<<"\tPlease Proceed to the Train Platform"<<endl<<endl;
		setTextColor(LightMagenta);
		cout<<"\t++++++++++++++++++++++++++++++++++++"<<endl<<endl;
		setTextColor(White);
		} else if(choice=='Y' || choice=='y'){
			setTextColor(LightCyan);
			cout<<" -> Yes"<<endl;
			setTextColor(White);
			cout<<" Printing your receipt."<<endl;Sleep(1000);
			s.printReceipt(fare, payment, change);		
		}
		system("pause");
	}

}

void setTextColor(ConsoleColors text){ // This function transforms the color of the console depending on the colors indicated in the enum
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (text)); // A predefined function under windows.h library that changes the color of outputs 
}

singleJourney::singleJourney(){ // The constructor provides the menu of the station and prompts the user to enter a startinng and end station
			front = -1;
			rear = -1;
			controlnum= 100869000; // Each ticket will have a specified control number which will start from 100869000 then increment each successful enqueueing
			adminpin=100869;
		}

void singleJourney::isWrongInput() // This function checks if the cin match the data type needed for the operation
	{if (cin.fail())  
	/* cin.fail() detects whether the value entered fits the value defined in the variable. 
	If cin.fail==true it means the instream is broken and the entered value is still in the buffer */
				{
					cin.clear(); // We repair the error on cin by calling cin.clear so that future inputs will work correctly
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // cin.ignore used to skip(discard/throw away) characters in the input stream
				}
			}
			
bool singleJourney::isFull(){ // This function checks if the ticket container is full and returns a boolean.
		if(front == 0 && rear == size-1){
			return true;
		}else return false;
}

bool singleJourney::isEmpty(){ // This function checks if the ticket container is empty and returns a boolean.
		if(front == -1) return true;
		else return false;
}

void singleJourney::enQueue(){ //This function enqueues a single ticket in the container
		if(isFull()){
			cout<<"Ticket container is full"<< endl;
		}else{
			
			if(front == -1) front = 0;
			rear++;
			container[rear] = ++controlnum; //controlnum is iterated so each ticket has a unique control number
			cout<<"Ticket No. "<< controlnum <<" is inserted in the ticket container"<<endl;	
		}
	}

void singleJourney::generateTickets(){ 
/* This function allows an admin to check the remaining tickets and 
stores a number of tickets in the ticket container by looping the enqueue() function*/
	if(isEmpty()){
		int input, picker, navigation;
		setTextColor(LightCyan);
		cout<<"Ticket Container is Empty. Inform an Authorized Personnel"<< endl;
		cout<<"Enter Admin Pin Code: ";
		cin>>input;
		while(adminpin!=input){
		isWrongInput();
		setTextColor(Red);
		cout<<"Wrong Pin. Please Try Again: ";
		setTextColor(White);
		cin>>input;
		}
		while(navigation!=2){
		system("cls");
		setTextColor(LightCyan);
		cout<<"Good Day Admin. What would you like to do?"<<endl;
		cout<<"[1] Check Remaining Tickets"<<endl;
		cout<<"[2] Add Tickets"<<endl<<endl;
		cout<<"Your Choice: ";
		setTextColor(White);
		cin>>picker;
		while(picker>2 || cin.fail()){
		isWrongInput();
		setTextColor(Red);
		cout<<"Wrong Choice. Please Try Again: ";
		setTextColor(White);
		cin>>picker;
		}
		switch(picker){
			case 1:
				int counter;
				setTextColor(LightCyan);
				if(front==-1 && rear == -1)
				cout<<"\nRemaining Tickets: 0"<<endl<<endl;
				else{
					for(int i=front; i<=rear; i++) counter=i+1;
					cout<<"\nRemaining Tickets: "<< counter<<endl<<endl;
					}
				setTextColor(Yellow);
				cout<<"What do you want to do next?\n";
				cout<<"\t[1] Return to Admin Menu\n";
				cout<<"\t[2] Exit"<<endl<<endl;
				cout<<"Your Choice: ";
				setTextColor(White);
				cin>>navigation;
				while(navigation>2 || cin.fail()){
				isWrongInput();
				setTextColor(Red);
				cout<<"Wrong Choice. Please Try Again: ";
				setTextColor(White);
				cin>>navigation;
				}
				break;
			case 2:
				setTextColor(LightCyan);
				cout<<"\nInserting Tickets in the Ticket Container..."<<endl;
				for(int i=0; i<size; i++)enQueue();
				setTextColor(Yellow);
				cout<<"\nWhat do you want to do next?\n";
				cout<<"\t[1] Return to Admin Menu\n";
				cout<<"\t[2] Exit"<<endl<<endl;
				cout<<"Your Choice: ";
				setTextColor(White);
				cin>>navigation;
				while(navigation>2 || cin.fail()){
				isWrongInput();
				setTextColor(Red);
				cout<<"Wrong Choice. Please Try Again: ";
				setTextColor(White);
				cin>>navigation;
				}
				break;
		}	
		}
		
	}
}
int singleJourney::deQueue(){ // This function dequeues a single number of ticket and return it to the calling function
		int element;
		if(isEmpty()){
			cout<<"Ticket container is empty."<<endl;
			return(-1);
		} else {
			element = container[front];
			if(front >= rear){
				front = -1;
				rear = -1;
			} else {
				front++;
			}
			cout << "Ticket No. "<<element<<" is released."<< endl;
			return(element);
		}
	}
	
void singleJourney::addJourney(){  // This function dequeues a number of tickets depending on the quantity that the user wants to buy
			cout<<"Enter Starting Station: ";
			cin>>start;
			start=invalidStation(start); // Checks whether the inputted stations are integer type then prompts an error message which allows the user to change the input.
			cout<<"Enter End Station: ";
			cin>>end;
			end=invalidStation(end);
			end=invalidStation(start, end); // Checks whether the start and end station is the same then prompts an error message which allows the user to change the input.
			start-=1; end-=1;
			confirmJourney();
		cout<<"Enter Number of Ticket/s: ";
		cin>>n;
		cout<<endl;
		while(n>size || (cin.fail())){
		isWrongInput();
		setTextColor(Red);	
		cout << "The ticket storage cannot accomodate your desired quantity." << endl;
		setTextColor(White);
		cout << "Enter Number of Tickets: ";
		cin >> n;
		}
		if(n<size+1){
		a = new int[n];  	// Allocate n integers and save pointer in a. "new" allows to assign memory during runtime using n variable as size
		for (int i=0; i<n; i++) {
		    generateTickets();
			a[i] = deQueue(); // Array in pointer a was then assigned a ticket number by the means of dequeueing each ticket in the ticket container
		}	
		system("pause");
		}
	}

void singleJourney::confirmJourney(){ // This function verifies if the stations entered by the user is correct before proceeding to the next transaction
		char choice;
		setTextColor(Yellow);
		cout<<"Do you want to proceed with the indicated stations? Y/N: ";
		setTextColor(White);
		cin>>choice;
		//if(choice=='Y'||'y')
		while(!(choice=='N'|| choice=='n' || choice=='Y' || choice=='y')){
			setTextColor(Red);
			cout<<"Invalid Choice. Enter Again: ";
			setTextColor(White); 
			cin>>choice;
		}
		if(choice=='N'|| choice=='n'){
			setTextColor(LightCyan);
			cout<<"-> No"<<endl;
			setTextColor(White);
			cout<<"Enter Starting Station: ";
			cin>>start;
			start=invalidStation(start);
			cout<<"Enter End Station: ";
			cin>>end;
			end=invalidStation(end);
			end=invalidStation(start, end);
			start-=1;
			end-=1;
			confirmJourney();
		} else if(choice=='Y' || choice=='y'){
			setTextColor(LightCyan);
			cout<<"-> Yes"<<endl;
			setTextColor(White);
		}
	}

int singleJourney::invalidStation(int station){ 
/* Checks whether the inputted stations are integer type and/or the station is present in LRT 2 
then prompts an error message which allows the user to change the input.*/
		if(!(cin.fail())) {
			if(station<=11 && station != 0){
			return station;
			}else if(station>11 || station==0){
			setTextColor(Red);	
			cout << "Station Doesn't Exist! Please try again." << endl;
			setTextColor(White);
			cout << "Enter Another Station: ";
			cin >> station;
			return invalidStation(station); //Recursive call is used to loop the function while condition is not met.
			}
		}
		else if(cin.fail()){
			isWrongInput();
			setTextColor(Red);	
			cout<<"Invalid Input. Please Enter Numerical Value: ";
			setTextColor(White);
			cin>>station;
			return invalidStation(station);
		}
	}
	
int singleJourney::invalidStation(int start, int station){
	// Overloaded Function of invalidStation() that checks if the starting station and end station is the same.
		if(start!=station && !(cin.fail()) && station<=11){
			return station;
		}else{
		isWrongInput();
		setTextColor(Red);	
		cout << "You've entered the same Start and End Station! Please try again." << endl;
		setTextColor(White);
		cout << "Enter Another Station: ";
		cin >> station;
		return invalidStation(start, station); //Recursive call is used to loop the function while condition is not met.
		}
	}

int singleJourney::Payment(int fare, int payment){ 
/* This function checks if the amount entered by user is sufficient enough to buy the ticket 
and if the value entered is an integer */ 
		if(payment>=fare){
			return payment;
		}else{
		isWrongInput();
		setTextColor(Red);
		cout<<"You have entered an insufficient balance or a wrong input."<<endl;
		setTextColor(White);
		cout<<"Please Enter A Sufficient Amount: ";
		cin>>payment;
		return Payment(fare, payment);	
		}
	}

int singleJourney::Payment(int fare, int payment, int change){ //The overloaded Payment() function compute for the change of the user
		if(payment>=fare){
			change = payment-fare;
			return change;
		}
	}

void singleJourney::displayJourney(int fare){
	//This function displays the Ticket data and prompts the user to enter payment
		string station[]={"Santolan","Katipunan","Anonas", "Cubao", "Betty Go", "Gilmore", "J.Ruiz", "V.Mapa", "Pureza", "Legarda", "Recto"};
		system("cls");
		setTextColor(LightMagenta);
		cout<<"=========================================="<<endl<<endl;
		setTextColor(White);
		cout<<setw(25)<<"Ticket Details"<<endl;
		setTextColor(Yellow);
		cout<<"Single Line Journey: "<< station [start]<<" to "<< station [end]<<endl;
		setTextColor(LightCyan);
		cout<<"Ticket Price: "<<fare<<endl;
		cout<<"Ticket Quantity: "<<n<<endl;
		cout<<"Total Payable: "<<fare*n<<endl<<endl;
		setTextColor(LightMagenta);
		cout<<"=========================================="<<endl<<endl;
		setTextColor(White);	
	}

void singleJourney::printReceipt(int fare, int payment, int change){ // This menu prints an invoice receipt for the customer
		time_t transaction= time(0);
		char* now= ctime(&transaction);
		string station[]={"Santolan","Katipunan","Anonas", "Cubao", "Betty Go", "Gilmore", "J.Ruiz", "V.Mapa", "Pureza", "Legarda", "Recto"};
		system("cls");
		setTextColor(LightMagenta);
		cout<<"\t++++++++++++++++++++++++++++++++++++"<<endl<<endl;
		setTextColor(Yellow);
		cout<<"\t       LRT 2 - Purple Line          "<<endl;
		cout<<"\t         Official Receipt           "<<endl;
		cout<<"\t      "<<now<<"      "<<endl;
		setTextColor(LightMagenta);
		cout<<"\t------------------------------------"<<endl<<endl;
		setTextColor(LightCyan);
		cout<<"\tItinerary: "<< station[start] <<" to "<< station[end] <<endl;
		cout<<"\tTicket Quantity: "<< n<<endl;
		for (int i=0; i<n; i++) {
		cout<< "\tTicket Control No.: " << a[i] <<endl;
		}
		cout<<endl<<"\tTotal: "<<fare<<endl;
		cout<<"\tCash Amount: "<<payment<<endl;
		cout<<"\tChange: "<<change<<endl<<endl;
		setTextColor(LightMagenta);
		cout<<"\t------------------------------------"<<endl<<endl;
		setTextColor(Yellow);
		cout<<"\tThank you for riding in LRT Line 2!"<<endl;
		cout<<"\tPlease Proceed to the Train Platform"<<endl<<endl;
		setTextColor(LightMagenta);
		cout<<"\t++++++++++++++++++++++++++++++++++++"<<endl<<endl;
		setTextColor(White);
		}
