#include <time.h>
#include <iostream>
using namespace std;

class rat {
	
	private:
	int hunger;
	int happiness;
	int age = 0;
	string name;
	
	public:
	
	
	void setName() {
		cout << "Please enter a name for your pet Rat:\n";
		getline(cin, name);
	}
	void rollDice() {
		hunger = rand() % 5 + 1;
		happiness = rand() % 5 + 1;
	}
	void feed() {
		cout << name << " enjoys the food. (+1 Hunger)\n";
		hunger++;
		age++;
	}
	void play() {
		cout << name << " runs around. (+1 Happiness)\n";
		happiness++;
		age++;
	}
	void decrease() {
		switch (rand() % 2 + 1) {
			case 1:
			cout << "Rat sad (-1 Happiness)\n";
			happiness--;
			break;
			case 2:
			cout << "Rat hungry (-1 Hunger)\n";
			hunger--;
		}
	}
	bool displayAttributes() {
		cout << "-" << name << "-\n";
		cout << "  __QQ\n (_)_\">\n";
		cout << "-- " << name << "'s stats" << " --\n";
		cout << "Hunger: " << hunger << "\nHappiness: " << happiness << "\nAge: " << age << endl;
		if (hunger == 0 || happiness == 0 || age == 5) return false;
		else return true;
	}	
	void dead() {
		if (age == 5) cout << name << " died of old age, but enjoyed a fulfulling life.";
		else cout << name << " died :(";
	}
};
	


int main() {
	srand(time(0));
	bool alive;
	rat myRat;
	myRat.setName();
	myRat.rollDice();
	myRat.displayAttributes();
	
	do {
		int choice;
		cout << "Main Menu:\n1. Feed\n2. Play\n";
		cin >> choice;
		switch (choice) {
			case 1:
			myRat.feed();
			break;
			case 2:
			myRat.play();
		}
		myRat.decrease();
		alive = myRat.displayAttributes();
	} while (alive == true);		
	myRat.dead();
	return 0;
}