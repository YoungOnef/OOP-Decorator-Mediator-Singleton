#include <iostream>
#include <string>
using namespace std;

// creating a Base class
class People
{
	//protected will be used for inheritance part and will not be accessiable by the public
protected:
	string Name;
	void setName(string name)
	{
		Name = name;
	}
public:
	// birtual keyword will allow for overriding
	virtual string getName()
	{
		return Name;
	}
};
//Singleton Derived Class
class King :public People
{
	// Create a fucntion pointer to instance
	//Constructor is private, no obejct will be able to be create by client
private:
	static King* vinstance;
	King()
	{
		//Private Constructor
	}
	~King()
	{
		cout << "Deleting the king instance..." << endl;
	}

public:
	//Creating a public function in which it iwll return the instace of this class
	// Delete keyword is used to delte the instalce of the class
	//Destcutor is called when instance is deleted 
	static King* Instance(string n);
	void DelInstance(King* vc)
	{
		delete vc;
		vinstance = 0;
		cout << "The king is removed" << endl;
	}

};
//Initialising the static variable which is called vinstace
//Defining a function instance that will create a single instance of the class
King* King::vinstance = 0;
King* King::Instance(string n)
{
	if (vinstance == 0)
	{
		vinstance = new King();
		vinstance->setName(n);
		return vinstance;
	}
	return vinstance;
}
//Creating a Derived class
class OtherCandidance : public People
{
public:
	OtherCandidance(string n)
	{
		this->setName(n);
	}
	//overriding 
	virtual string getName()
	{
		return this->Name + ", OtherCandidance in Other king doms";
	}
};
int main()
{
	//Iniliasing classes
	OtherCandidance L1("King3");
	OtherCandidance L2("King2");
	King* VC = King::Instance("King");

	//creating variables in which will be used in the Client 
	int choice = 1;
	bool vc = 0;
	string name;

	//while loop
	while (choice)
	{
		//displaying menu
		cout << endl << "MyOwnKingdom" << endl;
		cout << "1. Retrieve the People Details" << endl;
		cout << "2. Kill the king" << endl;
		cout << "3. Enter King name:" << endl;
		cout << "0. EXIT" << endl;
		cout << "Enter your choice: ";

		//selecting the choice
		cin >> choice;
		switch (choice)
		{
		case 1:
			//if statment if the vs is true
			if (vc)
			{
				cout << "The king post is vacant" << endl;
				cout << "The current people members are: " << endl;
				cout << L1.getName() << endl << L2.getName() << endl;
			}
			// if its not true
			else
			{
				cout << "The current king is: ";
				cout << VC->getName() << endl;
				cout << "The current Staff members are: " << endl;
				cout << L1.getName() << endl << L2.getName() << endl;
			}
			break;
		case 2:
			//deleting instalce of VC and setting VC to 1
			VC->DelInstance(VC);
			vc = 1;
			break;
		case 3:
			// Getting new kings name into the instance
			cout << "Please enter the name of the new king:";
			cin.ignore(10000, '\n');
			getline(cin, name);
			VC = King::Instance(name);
			vc = 0;
			break;
		default:
			//if other options dosen't work display this message
			cout << "Invalid choice.\n";
			break;
		}
	}
}