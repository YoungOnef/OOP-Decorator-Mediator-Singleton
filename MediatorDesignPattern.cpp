#include <iostream>
#include<windows.h>
using namespace std;

// creating classes prototpyes 
class House;
class ReadyEstate;
class AgencyMediator;
class Event;

//creating a interface class
class Interface
{
public:
	void registerAgent(ReadyEstate agent);
	void registerHouse(House house);
	bool isHouseOk();
	virtual void setReadyStatus(bool status) = 0;
};

// Event is a Interface that will be used in the ReadyEstate and ReadyEstate
//There is one event HouseSendOut
class Event
{
public:
	virtual void HouseSendOut() = 0;
};

// Agency Mediator is a mediator class which will be used for implemeting interface
//The mediator is regisrintg the house
//meethod for registerHouse and setReadyStatus is defined 
class AgencyMediator : public Interface
{
private:
	House* house = nullptr;
	ReadyEstate* agent = nullptr;
public:
	bool HouseSendOut = false;
	void registerAgent(ReadyEstate* agent)
	{
		this->agent = agent;
	}
	void registerHouse(House* house)
	{
		this->house = house;
	}
	bool isHouseOK()
	{
		return HouseSendOut;
	}
	void setReadyStatus(bool status)
	{
		HouseSendOut = status;
	}
};
//Class House has implemenation of Event Interface
//Its gets ready to send the house out
//House send out
// House class receives stuts updates from Mediator Class
//HouseSendOut is a event which will be triggring method in the Mediator Class
//Once the house has  HouseSendOut, getReady status will be set throught Mediator Class
class House : public Event
{
private:
	AgencyMediator* agencyMediator = nullptr;
public:
	House(AgencyMediator* agencyMediator)
	{
		this->agencyMediator = agencyMediator;
	}
	void HouseSendOut() override
	{
		if (agencyMediator->isHouseOK())
		{
			cout << "House is Online and sold" << endl;
			agencyMediator->setReadyStatus(true);
		}
		else
		{
			cout << "Waiting for permission for house to be online" << endl;
			Sleep(3000);
		}
	}
	void getReady()
	{
		cout << "The house is getting online " << endl;
		Sleep(3000);
		HouseSendOut();
	}
};

//Class ReadyEstate is responsbile for ReadyEstate  of the house thorught Mediator class
//ReadyEsate is set to False
//ReadyEsate implets the event of the houseSendout
//When house send out permsison was accepted tbe ReadyEsate will beccome a True in the Mediator Class
class ReadyEstate :public Event
{
private:
	AgencyMediator* agencyMediator = nullptr;
public:
	ReadyEstate(AgencyMediator* agencyMediator)
	{
		this->agencyMediator = agencyMediator;
		agencyMediator->setReadyStatus(false);
	}
	void HouseSendOut() override
	{
		cout << "House is sended to be ready" << endl;
		Sleep(3000);
		agencyMediator->setReadyStatus(true);
	}
};
// Client Code
void ClientCode()
{
	//setting up choices 
	int choice = 1;
	int option = 0;

	// Creating a while loop until user exits the program
	while (true)
	{
		//displaying mennu
		cout << endl << "Welcome to Menu" << endl;
		cout << "1. Buy the house" << endl;
		cout << "0. EXIT" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		// if user chosen 1
		if (choice == 1)
		{
			//cheking if the user bought the house
			if (option == !1) {
				// setting the Classes up with correct informataton and triggering the correct functions of the class
				cout << "Buying a house " << endl;
				AgencyMediator* agencyMediator = new AgencyMediator();
				House* HouseBrigend = new House(agencyMediator);
				ReadyEstate* agent = new ReadyEstate(agencyMediator);
				agencyMediator->registerHouse(HouseBrigend);
				agencyMediator->registerAgent(agent);
				HouseBrigend->getReady();
				agent->HouseSendOut();
				HouseBrigend->HouseSendOut();
				option += 1;
			}
			else // else already bougth the house
			{
				cout << "You already bought your house" << endl;
			}
		}
		else if (choice == 0)
		{
			exit(0); // exit the program
		}
		else // if user enters a wrong option
		{
			cout << "Please Select correct option" << endl;
		}
	}
}

int main()
{
	ClientCode();
	return 0;
}