// Battleship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <random>
#include <list>
using namespace std;



class Boat
{
public:
	
	string name;
	int locationX;
	int locationY;
	bool sunk = false;

	void setLocation()
	{
		//this seeds the random number
		std::random_device rd;
		std::srand(rd());

		//places boat at random location
		locationX = 1 + rand() % 8;
		locationY = 1 + rand() % 8;
	}

	void introduce()
	{
		std::cout << "\n" + name + " is located at " + (to_string(locationX)) + "/" + (to_string(locationY));

	}
};

int main()
{
	std::cout << "BATTLESHIP";

	//Creating boats
	Boat destroyer;
	destroyer.setLocation();
	destroyer.name = "Destroyer";

	Boat battleship;
	battleship.setLocation();
	battleship.name = "Battleship";

	Boat carrier;
	carrier.setLocation();
	carrier.name = "Carrier";

	Boat cruiser;
	cruiser.setLocation();
	cruiser.name = "Cruiser";

	Boat submarine;
	submarine.setLocation();
	submarine.name = "Submarine";

	Boat navy[5]{ destroyer, battleship, carrier, submarine, cruiser};



	for (Boat boat : navy)
	{
		boat.introduce();
	}

	//Setting up canon
	int hitLoactionX = 1;
	int hitLoactionY = 1;
	int nextLoactionX = 1;
	int nextLoactionY = 1;
	bool nearMiss = false;

	while (destroyer.sunk == false || battleship.sunk == false || carrier.sunk == false || submarine.sunk == false || cruiser.sunk == false)
	{
		if (nearMiss == false)
		{
			hitLoactionX = 1 + rand() % 8;
			hitLoactionY = 1 + rand() % 8;

		}
		else
		{
			hitLoactionX = nextLoactionX;
			hitLoactionY = nextLoactionY;
		}

		std::cout << "\nFired At " + to_string(hitLoactionX) + "/" + to_string(hitLoactionY);

		for (Boat boat : navy)
		{
			/*if (boat.sunk == true)
			{
				//this will never register as true, even if the boat is sunk, for reasons I do not understand, forcing me to rely on the spaghetti code below
			}*/
			if (boat.name == "Destroyer" && destroyer.sunk == true || boat.name == "Battleship" && battleship.sunk == true || boat.name == "Cruiser" && cruiser.sunk == true || boat.name == "Submarine" && submarine.sunk == true || boat.name == "Carrier" && carrier.sunk == true)
			{
				
			}
			else
			{
				if (hitLoactionX == boat.locationX && hitLoactionY == boat.locationY)
				{
					std::cout << ", Hit " + boat.name;
					if (boat.name == "Destroyer") //yay more spaghetti code for the same reason
					{
						destroyer.sunk = true;
						nearMiss = false;

					}
					if (boat.name == "Battleship")
					{
						battleship.sunk = true;
						nearMiss = false;
					}
					if (boat.name == "Cruiser")
					{
						cruiser.sunk = true;
						nearMiss = false;
					}
					if (boat.name == "Carrier")
					{
						carrier.sunk = true;
						nearMiss = false;
					}
					if (boat.name == "Submarine")
					{
						submarine.sunk = true;
						nearMiss = false;
					}

				}
				else if (hitLoactionX == boat.locationX || hitLoactionY == boat.locationY)
				{
					std::cout << ", Near Miss " + boat.name;
					nextLoactionX = boat.locationX;
					nextLoactionY = boat.locationY;

					nearMiss == true;
				}

				else
				{
					std::cout << ", Miss " + boat.name;
					nearMiss = false;
				}
			}
		}
							
		
	}

	std::cout << "\nAll Ships Have Sunk";

	////actual game
	//while (destroyer.sunk == false || battleship.sunk == false)
	//{
	//	if (nearMiss == false)
	//	{
	//		hitLoactionX = 1 + rand() % 3;
	//		hitLoactionY = 1 + rand() % 3;
	//	}
	//	else
	//	{

	//	}
	//	
	//	std::cout << "\nFired At " + to_string(hitLoactionX) + "/" + to_string(hitLoactionY);

	//	//check if hit destroyer
	//	if (destroyer.sunk == false)
	//	{
	//		if (hitLoactionX == destroyer.locationX && hitLoactionY == destroyer.locationY)
	//		{
	//			std::cout << ", Hit " + destroyer.name;
	//			destroyer.sunk = true;
	//			nearMiss == false;
	//		}
	//		else if ((hitLoactionX - destroyer.locationX) == 1)
	//		{
	//			std::cout << ", Near Miss " + destroyer.name;
	//			nearMiss == true;
	//			hitLoactionX = hitLoactionX - 1;
	//		}
	//		else if ((destroyer.locationX - hitLoactionX) == 1)
	//		{
	//			std::cout << ", Near Miss " + destroyer.name;
	//			nearMiss == true;
	//			hitLoactionX = hitLoactionX + 1;
	//		}
	//		else if ((hitLoactionY - destroyer.locationY) == 1)
	//		{
	//			std::cout << ", Near Miss " + destroyer.name;
	//			nearMiss == true;
	//			hitLoactionX = hitLoactionX - 1;
	//		}
	//		else if ((destroyer.locationY - hitLoactionY) == 1)
	//		{
	//			std::cout << ", Near Miss " + destroyer.name;
	//			nearMiss == true;
	//			hitLoactionY = hitLoactionY + 1;
	//		}
	//		else
	//		{
	//			std::cout << ", Miss " + destroyer.name;
	//			nearMiss == false;
	//		}
	//	}
	//	
	//	//check if hit battlship
	//	if (battleship.sunk == false)
	//	{
	//		if (hitLoactionX == battleship.locationX && hitLoactionY == battleship.locationY)
	//		{
	//			std::cout << ", Hit " + battleship.name;
	//			battleship.sunk = true;
	//			nearMiss == false;
	//		}
	//		else if ((hitLoactionX - battleship.locationX) == 1)
	//		{
	//			std::cout << ", Near Miss " + battleship.name;
	//			nearMiss == true;
	//			hitLoactionX = hitLoactionX - 1;
	//		}
	//		else if ((battleship.locationX - hitLoactionX) == 1)
	//		{
	//			std::cout << ", Near Miss " + battleship.name;
	//			nearMiss == true;
	//			hitLoactionX = hitLoactionX + 1;
	//		}
	//		else if ((hitLoactionY - battleship.locationY) == 1)
	//		{
	//			std::cout << ", Near Miss " + battleship.name;
	//			nearMiss == true;
	//			hitLoactionX = hitLoactionX - 1;
	//		}
	//		else if ((battleship.locationY - hitLoactionY) == 1)
	//		{
	//			std::cout << ", Near Miss " + battleship.name;
	//			nearMiss == true;
	//			hitLoactionY = hitLoactionY + 1;
	//		}
	//		else
	//		{
	//			std::cout << ", Miss " + battleship.name;
	//			nearMiss == false;
	//		}
	//	}



	//	
	//}
	//	

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu