#include <iostream>
#include <string>
using namespace std;


//creating a base class
class Car {
protected:
	// creating a variable in which will be used used thouggh inhertiance 
	string m_description;

public:
	Car(); // Creting constactur 
	virtual string getDescription();    // virtual function which will be used later with description 
	virtual double cost() = 0; // setting a virtual veriavle to 0 which will be used later 

};
// adding unknow to the Descrption 
Car::Car() {
	m_description = "unknown";
}
// returning the Description
string Car::getDescription() {
	return m_description;
}
// Createing a class of Amaze which has  inheritance of the car
class Amaze : public Car {
public:
	Amaze();
	double cost();
};
// adding name Amaze to the m_description
Amaze::Amaze()
{
	m_description = "Amaze";
}
// returning cost of the Amaze
double Amaze::cost() {
	return 100;
}
// Createing a class of Amaze which has  inheritance of the car
class Awe : public Car {
public:
	Awe();
	double cost();
};
// adding name Amaze to the m_description
Awe::Awe() {
	m_description = "Awe";
}
// returning cost of the Amaze
double Awe::cost() {
	return 100;
}

// Creating a AddsOnDecorator which will be used add more thing to the car and has inhertance of the car
class AddsOnDecorator : public Car {
public:
	virtual string getDescription() = 0;
	virtual double cost() = 0;
};


// creating a decorator class sub classes extened the classes
// creating a class of RadioSystemDecorator which has inheritance of AddsOnDecorator
class RadioSystemDecorator : public AddsOnDecorator {
	//creating a pointer to m_Car
	Car* m_Car;

public:
	RadioSystemDecorator(Car* car);
	double cost();
	string getDescription();

};
RadioSystemDecorator::RadioSystemDecorator(Car* car) :
	m_Car(car) {
}
//adding to the price
double RadioSystemDecorator::cost() {
	return m_Car->cost() + 50;
}
//adding to the getDescription radio sstem
string RadioSystemDecorator::getDescription() {
	return m_Car->getDescription() + " + Radio system";
}
// creating a decorator class sub classes extened the classes
// creating a class of BoseMP3systemDecorator which has inheritance of AddsOnDecorator
class BoseMP3systemDecorator : public AddsOnDecorator {
	Car* m_Car;

public:
	BoseMP3systemDecorator(Car* car);
	double cost();
	string getDescription();

};
//returning car
BoseMP3systemDecorator::BoseMP3systemDecorator(Car* car) :
	m_Car(car) {
}
// returning and adding the cost
double BoseMP3systemDecorator::cost() {
	return m_Car->cost() + 50;
}
// adding description 
string BoseMP3systemDecorator::getDescription() {
	return m_Car->getDescription() + " + Bose MP3 system";
}
// creating a decorator class sub classes extened the classes
// creating a class of LeatherseatsDecorator which has inheritance of AddsOnDecorator
class LeatherseatsDecorator : public AddsOnDecorator {
	Car* m_Car;

public:
	LeatherseatsDecorator(Car* car);
	double cost();
	string getDescription();

};
//returning car
LeatherseatsDecorator::LeatherseatsDecorator(Car* car) :
	m_Car(car) {
}
//adding the cost 
double LeatherseatsDecorator::cost() {
	return m_Car->cost() + 50;
}
// adding description 
string LeatherseatsDecorator::getDescription() {
	return m_Car->getDescription() + " + Leather seats";
}
// creating a decorator class sub classes extened the classes
// creating a class of LeatherseatsDecorator which has inheritance of AddsOnDecorator
class WheelilluminationDecorator : public AddsOnDecorator {
	Car* m_Car;

public:
	WheelilluminationDecorator(Car* car);
	double cost();
	string getDescription();

};
//returning car
WheelilluminationDecorator::WheelilluminationDecorator(Car* car) :
	m_Car(car) {
}
// adding cost
double WheelilluminationDecorator::cost() {
	return m_Car->cost() + 50;
}
// adding descrition
string WheelilluminationDecorator::getDescription() {
	return m_Car->getDescription() + " + Wheel illumination";
}


int main() {

	// displaing menu
	cout << "Enter your Choice of the car type" << endl;
	cout << "1. Awe - car (6 Seats)" << endl;
	cout << "2. Amaze - car (4 seats)" << endl;
	cout << "3. Exit" << endl;
	cout << "Your Option: ";
	//defning and saving the choice
	int choice;
	cin >> choice;
	cout << endl;
	//inislasing the class
	Car* car;


	//switch statment
	switch (choice)
	{
	case 1:
		//displaying menu
		cout << "You have selected 'Awe' " << endl;
		cout << "Options of the car that are available for you" << endl;
		cout << "1 - Awe without any addons - $100" << endl;
		cout << "2 - Awe + RadioSystem - $150" << endl;
		cout << "3 - Awe + RadioSystem + BoseMP3system - $200" << endl;
		cout << "4 - Awe + RadioSystem + BoseMP3system + Leather seats - $250" << endl;
		cout << "5 - Awe + RadioSystem + BoseMP3system + Leather seats + Wheel illumination - $300" << endl;
		cout << "6 - Exit" << endl;
		cout << "Your Option: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			//if user chosen option 1
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// only Awe, no addsOn. 
			car = new Awe();
			cout << "Description of the car: " << car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 2:
			//if user chosen option 2
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// Awe + RadioSystem
			car = new Awe();
			car = new RadioSystemDecorator(car);
			cout << "Description of the car: " << car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 3:
			//if user chosen option 3
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// Awe + RadioSystem + BoseMP3system
			car = new Awe();
			car = new RadioSystemDecorator(car);
			car = new BoseMP3systemDecorator(car);
			cout << "Description of the car: " << car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 4:
			//if user chosen option 4
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// Awe + RadioSystem + BoseMP3system + Leather seats
			car = new Awe();                            
			car = new RadioSystemDecorator(car);
			car = new BoseMP3systemDecorator(car);
			car = new LeatherseatsDecorator(car);
			cout << "Description of the car: " << car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 5:
			//if user chosen option 5
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// Awe + RadioSystem + BoseMP3system + Leather seats + Wheel illumination
			car = new Awe();
			car = new RadioSystemDecorator(car);
			car = new BoseMP3systemDecorator(car);
			car = new LeatherseatsDecorator(car);
			car = new WheelilluminationDecorator(car);
			cout << "Description of the car: " <<car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 6:
			exit(0); // exits the program
			break;
		default:
			cout << "Invalid choice.\n"; // option that user enters is invalid
			cout << "Try Again.\n"; //
			break;
		}
		break;
	case 2:
		//displaing a menu
		cout << "You have selected 'Awe' " << endl;
		cout << "Options of the car that are available for you" << endl;
		cout << "1 - Amaze without any addons - $100" << endl;
		cout << "2 - Amaze + RadioSystem - $150" << endl;
		cout << "3 - Amaze + RadioSystem + BoseMP3system - $200" << endl;
		cout << "4 - Amaze + RadioSystem + BoseMP3system + Leather seats - $250" << endl;
		cout << "5 - Amaze + RadioSystem + BoseMP3system + Leather seats + Wheel illumination - $300" << endl;
		cout << "6 - Exit" << endl;
		cout << "Your Option: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			//if user chosen option 1
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// only Amaze, no addsOn. 
			car = new Amaze();
			cout << "Description of the car: " << car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 2:
			//if user chosen option 2
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// Amaze + RadioSystem
			car = new Amaze();
			car = new RadioSystemDecorator(car);
			cout << "Description of the car: " << car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 3:
			//if user chosen option 3
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// Amaze + RadioSystem + BoseMP3system
			car = new Amaze();
			car = new RadioSystemDecorator(car);
			car = new BoseMP3systemDecorator(car);
			cout << "Description of the car: " << car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 4:
			//if user chosen option 4
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// Amaze + RadioSystem + BoseMP3system + Leather seats
			car = new Amaze();
			car = new RadioSystemDecorator(car);
			car = new BoseMP3systemDecorator(car);
			car = new LeatherseatsDecorator(car);
			cout << "Description of the car: " << car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 5:
			//if user chosen option 5
			cout << endl << "---------------------------" << endl;
			//calling apporpaite classes and functions that user has chosen
			// Amaze + RadioSystem + BoseMP3system + Leather seats + Wheel illumination
			car = new Amaze();
			car = new RadioSystemDecorator(car);
			car = new BoseMP3systemDecorator(car);
			car = new LeatherseatsDecorator(car);
			car = new WheelilluminationDecorator(car);
			cout << "Description of the car: " << car->getDescription() << endl;
			cout << "Price : $" << car->cost() << endl;
			delete car;
			break;
		case 6:
			exit(0); // esits the program
			break;
		default:
			cout << "Invalid choice.\n"; // invalid option
			cout << "Try Again.\n"; //
			break;
		}
		break;
	case 3:
		exit(0);
	default:
		cout << "Invalid choice.\n"; // invalid option
		cout << "Try Again.\n"; // invalid option
		break;
	}


	return 0;
}