#include "VectorCalculator.h"
#include <iostream>;

double VectorCalculator::CalculateMagnitude(std::vector<int> inputVector)
{
    double vectorMagnitude;

    inputVector.size() == 2
        ? vectorMagnitude = sqrt(pow(inputVector[0], 2) + pow(inputVector[1], 2))
        : vectorMagnitude = sqrt(pow(inputVector[0], 2) + pow(inputVector[1], 2) + pow(inputVector[2], 2));

    return vectorMagnitude;
}

int VectorCalculator::CalculateDotProduct(std::vector<int> inputVector1, std::vector<int> inputVector2)
{
    int dotProduct = 0;
    for (int i = 0; i < (inputVector1.size() == 3 ? 3 : 2); i++)
    {
        dotProduct += inputVector1[i] * inputVector2[i];
    }

    return dotProduct;
}

double VectorCalculator::CalculateAngleBetween(std::vector<int> inputVector1, std::vector<int> inputVector2)
{
    int dotProduct = CalculateDotProduct(inputVector1, inputVector2);
    double magVec1 = CalculateMagnitude(inputVector1);
    double magVec2 = CalculateMagnitude(inputVector2);
    double val = ((dotProduct) / (magVec1 * magVec2));
    return acos(val);
}

std::vector<int> VectorCalculator::CalculateCrossProduct(int x1, int y1, int z1, int x2, int y2, int z2)
{
    int iHat = ((y1 * z2) - (z1 * y2));
    int jHat = ((z1 * x2) - (x1 * z2));
    int kHat = ((x1 * y2) - (y1 * x2));

    return std::vector<int> {iHat, jHat, kHat};
}
