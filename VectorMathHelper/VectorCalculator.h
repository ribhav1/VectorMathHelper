#pragma once
#include <vector>;

class VectorCalculator
{
public:
	static double CalculateMagnitude(std::vector<int> inputVector);
	static int CalculateDotProduct(std::vector<int> inputVector1, std::vector<int> inputVector2);
	static double CalculateAngleBetween(std::vector<int> inputVector1, std::vector<int> inputVector2);
	static std::vector<int> CalculateCrossProduct(int x1, int y1, int z1, int x2, int y2, int z2);
};

