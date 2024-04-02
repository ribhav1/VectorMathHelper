#include "Menu.h"
#include "VectorCalculator.h";
#include <iostream>;
#include <string>;
#include <vector>;

std::vector<int> getOneVectorInput(std::vector<int> inputVector)
{
	//Get vector components
	std::string input;

	std::cout << "Enter a vector" << std::endl;
	std::cin.ignore();
	while (input.length() != 3 && input.length() != 5)
	{
		getline(std::cin, input);
		if (input.length() == 3 || input.length() == 5)
		{
			break;
		}
		std::cout << "Make sure to enter a valid input" << std::endl;
	}

	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			inputVector.push_back(input[i] - 48);
		}
	}

	return inputVector;
}

std::vector<std::vector<int>> getVectorInputs(std::vector<int> inputVector1, std::vector<int> inputVector2)
{
	//Get first vector components
	inputVector1 = getOneVectorInput(inputVector1);
	int inputLen = inputVector1.size() == 2 ? 3 : 5;

	//Get second vector components and make is in same dimension as first vector
	std::string input2;
	std::cout << "Enter the second vector" << std::endl;
	while (input2.length() != inputLen)
	{
		getline(std::cin, input2);
		if (input2.length() == inputLen)
		{
			break;
		}
		std::cout << "Make sure that the second vector is the same dimension as the first vector" << std::endl;
	}

	for (int i = 0; i < input2.length(); i++)
	{
		if (isdigit(input2[i]))
		{
			inputVector2.push_back(input2[i] - 48);
		}
	}

	return std::vector<std::vector<int>> {inputVector1, inputVector2};
}

int Menu::DrawMainScreen()
{
	int selection = 0;

	std::cout << "Welcome to the Vector Math Helper program" << std::endl;
	std::cout << "Please select what operation you would like to perform/calculate" << std::endl;

	std::cout << "(1) Vector Magnitude" << std:: endl;
	std::cout << "(2) Dot Product" << std::endl;
	std::cout << "(3) Angle Between 2 Vectors" << std::endl;
	std::cout << "(4) Cross Product" << std::endl;

	while (typeid(selection).name() != "int" && selection != 1 && selection != 2 && selection != 3 && selection != 4)
	{
		std::cin >> selection;
		if (selection == 1 || selection == 2 || selection == 3 || selection == 4)
		{
			break;
		}
		std::cout << "Make sure to enter a valid input" << std::endl;
	}


	return selection;
}

void Menu::DrawVecMagScreen()
{
	std::cout << "Vector Magnitude Calculator" << std::endl;
	std::cout << "Please enter a 2D or 3D vector" << std::endl;
	std::cout << "Enter in the form of its components seperated by spaces, i.e: 1 2, or 1 2 3" << std::endl;

	double result = VectorCalculator::CalculateMagnitude(getOneVectorInput(std::vector<int>()));

	std::cout << "The magnitude of the vector is " << result << std::endl;
}

void Menu::DrawDotProductScreen()
{
	std::cout << "Dot Product Calculator" << std::endl;
	std::cout << "Please enter 2D or 3D vectors" << std::endl;
	std::cout << "Please enter vectors of the same dimension" << std::endl;
	std::cout << "Enter in the form of its components seperated by spaces, i.e: 1 2, or 1 2 3" << std::endl;

	std::vector<std::vector<int>> inputVectors = getVectorInputs(std::vector<int>{}, std::vector<int>{});

	int result = VectorCalculator::CalculateDotProduct(inputVectors[0], inputVectors[1]);
	std::cout << result << std::endl;
}

void Menu::DrawAngleBetweenScreen()
{
	std::cout << "Angle Between 2 Vectors Calculator" << std::endl;
	std::cout << "Please enter 2D or 3D vectors" << std::endl;
	std::cout << "Please enter vectors of the same dimension" << std::endl;
	std::cout << "Enter in the form of its components seperated by spaces, i.e: 1 2, or 1 2 3" << std::endl;

	std::vector<std::vector<int>> inputVectors = getVectorInputs(std::vector<int>{}, std::vector<int>{});

	double theta = VectorCalculator::CalculateAngleBetween(inputVectors[0], inputVectors[1]);
	theta *= (180/ 3.14159265358979323846);
	std::cout << "The angle between the two vectors is " << theta << " degrees" << std::endl;
}

void Menu::DrawCrossProductScreen()
{
	int x1, y1, z1, x2, y2, z2;

	std::cout << "Cross Product Calculator" << std::endl;
	std::cout << "Enter vectors in the form of its components seperated by spaces, i.e: 1 2 3" << std::endl;

	std::cout << "Enter the first vector" << std::endl;
	std::cin >> x1 >> y1 >> z1;

	std::cout << "Enter the second vector" << std::endl;
	std::cin >> x2 >> y2 >> z2;

	std::vector<int> result = VectorCalculator::CalculateCrossProduct(x1, y1, z1, x2, y2, z2);
	std::cout << "The cross product is: " << result[0] << "i + " << result[1] << "j + " << result[2] << "k " << std::endl;
}