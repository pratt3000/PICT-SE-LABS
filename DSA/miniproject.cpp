#include"iostream"
#include"stdlib.h"
using namespace std;
int ended = 0;
//node class structure
class Node{
	int num1;
	int num2;
	int cows1;
	int cows2;
	int bulls1;
	int bulls2;
	Node* next;
	Node* prev;
public:
	Node();
	Node(int num1, int num2);
	friend class CowsAndBulls;
};

//main class structure
class CowsAndBulls {
	Node* start, * end;
	int number1, number2;
public:
	CowsAndBulls();
	void rules();				//rules of the game
	void initialInput();		//one time input
	void input();				//input for each turn	
	void calculateCows();		//calculate cows and pass to calculate bulls
	void calculateBulls();		//calculate bulls and diaplay cows and bulls
	void Output();				//displaying for each turn 
	void finalOutput();			//display winning player
	void developerMode();		//developer options
};
//NODE FUNCTIONS 
/* intitialising all elements to NULL using constructor */
Node :: Node() {
	num1 = 0;
	num2 = 0;
	next = NULL;
	prev = NULL;
	cows1 = 0;
	cows2 = 0;
	bulls1 = 0;
	bulls2 = 0;
}

/* assigning new node data using parameterised constructor */
Node :: Node(int num1, int num2) {
	this->num1 = num1;
	this->num2 = num2;
	next = NULL;
	cows1 = 0;
	cows2 = 0;
	bulls1 = 0;
	bulls2 = 0;
	prev = NULL;
}

//COWSANDBULLS FUNCTIONS
/*initialising pointers to NULL using constructor*/
CowsAndBulls :: CowsAndBulls() {
	start = NULL;
	end = NULL;
}

/*stating the rules of the game*/
void CowsAndBulls::rules() {
	cout << "\n---------------------------------- WELCOME TO THE GAME OF COWS AND BULLS -----------------------------------"
		 << "\nRULES"
		 << "\n1. Each player chooses a 4 digit number (WITH NO REPEATED DIGITS)"
		 << "\n2. The aim of the game is to guess the other players number"
		 << "\n3. Each player gets one guess per round."
		 << "\n5. a. Cows  : Correct digits but position guessed is wrong"
		 << "\n   b. Bulls : Correct digits and correct positions guessed ";
}

/* taking initial input numbers from the 2 players*/
void CowsAndBulls::initialInput() {
	cout << "\n\nPLAYER 1: ENTER NUMBER :- ";
	cin >> number1;
	system("CLS");
	rules();
	cout << "\n\nPLAYER 1: ENTER NUMBER :- **** ";
	cout << "\nPLAYER 2: ENTER NUMBER :- ";
	cin >> number2;
	system("CLS");
	cout << "\nNOW LET THE GAMES BEGIN!";
}

/* creating a new node for every turn of both the players and storing it in a DLL*/
void CowsAndBulls::input() {
	//system("CLS");
	int num1, num2;												/*taking input from user*/
	cout << "\n-------------------------------------------------------------------------------------------";
	cout << "\nYOU NEED TO ENTER YOUR GUESSES:";
	cout << "\nChance  :  PLAYER1";
	cout << "\nEnter guess : ";
	cin >> num1;
	cout << "\nChance  :  PLAYER2";
	cout << "\nEnter guess : ";
	cin >> num2;
	Node* temp = new Node(num1, num2);							/* creating nodes*/
	if (start == NULL) {
		temp->next = NULL;
		temp->prev = NULL;
		start = temp;
		end = temp;
	}
	else {
		temp->prev = NULL;
		temp->next = start;
		start->prev = temp;
		start = temp;
	}
	calculateCows();
}

/* we calculate the number of cows in this function. the number of digits that are same.
we also count the bulls right now, but we will call the calculatebulls function in which 
the bulls will be subracted from our output of calculatecows function, thereby giving us
the required cows and bulls in the variables*/
void CowsAndBulls::calculateCows() {
	int count1, count2;
	int n1, n2;
	start->cows1 = 0;
	start->cows2 = 0;
	int copy1 = number1, copy2 = number2;
	n1 = start->num1;
	n2 = start->num2;
	for (int count1 = 0;count1 < 4;count1++) {						//COWS COUNTING FOR FIRST NUMBER
		for (int count2 = 0;count2 < 4;count2++) {
			if (n1 % 10 == copy2 % 10) {
				(start->cows1)++;
				break;
			}
			copy2 /= 10;
		}
		copy2 = number2;
		n1 /= 10;
	}
	
	for (int count1 = 0;count1 < 4;count1++) {						//COWS COUNTING FOR SECOND NUMBER
		for (int count2 = 0;count2 < 4;count2++) {
			if (n2 % 10 == copy1 % 10) {
				(start->cows2)++;
				break;
			}
			copy1 /= 10;
		}
		copy1 = number1;
		n2 /= 10;
	}
	calculateBulls();
}

/* In this function the number of bulls are counted. 
If bull is found the the corresponding cows count is also decremented */
void CowsAndBulls::calculateBulls() {
	start->bulls1 = 0;
	start->bulls2 = 0;
	int n1 = number1;
	int n2 = number2;
	int copy1 = start->num1;
	int copy2 = start->num2;
	for (int count = 0;count < 4;count++) {
		if (n2 % 10 == copy1 % 10) {
			(start->cows1)--;
			(start->bulls1)++;
		}
		if (n1 % 10 == copy2 % 10) {
			(start->cows2)--;
			(start->bulls2)++;
		}
		n1 /= 10;
		n2 /= 10;
		copy1 /= 10;
		copy2 /= 10;
	}
	if (start->bulls1 == 4 || start->bulls2 == 4) {
		ended = 1;
		Output();
		finalOutput();
	}
	else {
		Output();
	}
}

/*display after each turn*/
void CowsAndBulls::Output() {
	Node* temp = end;
	int i = 0;
	cout << "\n\n CHANCE       ----------- PLAYER 1 -------------        ------------ PLAYER 2 -------------- ";
	cout << "\n                  NUMBER      COWS     BULLS	             NUMBER    COWS    BULLS";
	while (temp != NULL) {
			cout << "\n   " << i << "\t\t  " <<temp->num1<< "  \t" << temp->cows1 << "\t  " << temp->bulls1 
				<< "\t\t     " << temp->num2<< "  \t" << temp->cows2 << "\t  " << temp->bulls2;
			temp = temp->prev;
			i++;
	}
	cout << "\n\n";
	system("PAUSE");
	system("CLS");
	if(!ended)
		input();
}

/*display the winner*/
void CowsAndBulls :: finalOutput() {
	int flag = 0;
	cout << "\nGAME OVER";
	if (start->bulls1 == 4) {
		cout << "\nWINNER IS: PLAYER1\n\n";
		flag++;
	}
	if (start->bulls2 == 4) {
		cout << "\n\nWINNER IS: PLAYER2\n\n";
		flag++;
	}
	if (flag == 2)
		cout << "\n\nITS A TIE!\n\n";
	system("PAUSE");
}
void CowsAndBulls::developerMode() {
	cout << "\nbackdoor initialise";
	cout << "\nnumber 1 :" << number1;
	cout << "\nnumber 2 : " << number2;
	system("PAUSE");
	system("CLS");
}
// counting cows : repeated digits error  

/* singleton class structure */
int main() {
	int i = 1;
	while(i){
		system("CLS");
		CowsAndBulls ob;
		ob.rules();
		ob.initialInput();
		ob.input();
		cout << "\n\n play another game(1/0)";
		cin >> i;
		if (i == 420) {
			ob.developerMode();
		}
	}
	return 0;
}