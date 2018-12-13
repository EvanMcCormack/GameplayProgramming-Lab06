#include <iostream>
#include "MyMatrix3.h"
#include "MyVector3.h"

#define PI           3.14159265358979323846

/// <summary>
/// main enrtry point
/// </summary>
/// <returns>zero</returns>
int main()
{
	//Vectors used
	MyVector3 vector0{ 0, 0, 0 };
	MyVector3 vector1{ 1.0 , 2.0 , 3.0 };
	MyVector3 vector2{ 2.0 , 3.0 , 4.0 };
	MyVector3 vector3{ 3.0 , 4.0 , 5.0 };
	MyVector3 vector4{ 1.0, 1.0, 1.0 };
	MyVector3 vector5{ 5.0, 6.0, 0.0 };
	MyVector3 vector6{ 2.0, 1.0, 1.0 };
	MyVector3 scaledVector{};
	//Matrices used
	MyMatrix3 matrixOne{ 1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0 };
	MyMatrix3 matrixTwo;
	MyMatrix3 matrixThree{ 2, 1, 1,
		1, 2, 1,
		1, 1, 2 };
	MyMatrix3 matrixFour{ vector1, vector2, vector3 };
	MyMatrix3 matrixFive{ 1, 2, 3,
		4, 5, 6,
		7, 8, 9 };
	MyMatrix3 matrixSix{ 1, 1, 1,
		1, 1, 1,
		1, 1, 1 };
	//Doubles used
	const double scalar{ 3.5 };
	double det;
	double angle{ PI / 2 };
	//Ints used
	int row{ 2 };
	int col{ 1 };
	//Bools used
	bool equals{ false };
	bool notEquals{ false };

	std::cout << "Null Matrix" << std::endl;
	std::cout << matrixTwo.toString() << std::endl;
	std::cout << "[ 0.0, 0.0, 0.0," << "\n" << " 0.0, 0.0, 0.0" << "\n" << " 0.0, 0.0, 0.0 ]" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << "Matrix constructor" << std::endl;
	std::cout << matrixOne.toString() << std::endl;
	std::cout << "[ 1.0, 0.0, 0.0 " << "\n" << " 0.0, 1.0, 0.0 " << "\n" << " 0.0, 0.0, 1.0 ]" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << "Matrix Constructor (Using vectors)" << std::endl;
	std::cout << matrixFour.toString() << std::endl;
	std::cout << "[ 1, 2, 3 " << "\n" << " 2, 3, 4 " << "\n" << " 3, 4, 5 ]" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << "Equals Checker" << std::endl;
	if (matrixOne == matrixThree)
	{
		equals = true;
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}
	std::cout << "False" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << "NotEquals Checker" << std::endl;
	if (matrixOne != matrixThree)
	{
		notEquals = true;
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}
	std::cout << "True" << std::endl;
	std::cout << "-------------------------" << std::endl;

	matrixTwo = matrixOne + matrixThree;
	std::cout << "Matrix Addition" << std::endl;
	std::cout << matrixTwo.toString() << std::endl;
	std::cout << "[ 3, 1, 1," << "\n" << " 1, 3, 1," << "\n" << " 1, 1, 3 ]" << std::endl;
	std::cout << "-------------------------" << std::endl;

	matrixTwo = matrixThree - matrixOne;
	std::cout << "Matrix Subtraction" << std::endl;
	std::cout << matrixTwo.toString() << std::endl;
	std::cout << "[ 1, 1, 1," << "\n" << " 1, 1, 1," << "\n" << " 1, 1, 1 ]" << std::endl;
	std::cout << "-------------------------" << std::endl;

	matrixTwo = matrixThree * matrixOne;
	std::cout << "Matrix Multiplication" << std::endl;
	std::cout << matrixTwo.toString() << std::endl;
	std::cout << "[ 2, 1, 1, " << "\n" << " 1, 2, 1," << "\n" << " 1, 1, 2 ]" << std::endl;
	std::cout << "-------------------------" << std::endl;

	vector0 = matrixThree * vector1;
	std::cout << "Matrix-Vector Multiplication" << std::endl;
	std::cout << vector0.toString() << std::endl;
	std::cout << "[ 7, 8, 9 ]" << std::endl;
	std::cout << "-------------------------" << std::endl;

	matrixTwo = matrixThree * scalar;
	std::cout << "Matrix-Scalar Multiplication" << std::endl;
	std::cout << matrixTwo.toString() << std::endl;
	std::cout << "[ 7, 3.5, 3.5," << "\n" << " 3.5, 7, 3.5" << "\n" << " 3.5, 3.5, 7 ]" << std::endl;
	std::cout << "-------------------------" << std::endl;

	matrixTwo = matrixFive.transpose();
	std::cout << "Transpose of a Matrix" << std::endl;
	std::cout << matrixTwo.toString() << std::endl;
	std::cout << "[ 1, 4, 7, \n 2, 5, 8, \n 3, 6, 9 ]" << std::endl;
	std::cout << "-------------------------" << std::endl;

	det = matrixThree.determinant();
	std::cout << "Determinant" << std::endl;
	std::cout << det << std::endl;
	std::cout << "4" << std::endl;
	std::cout << "--------------------------" << std::endl;

	matrixTwo = matrixThree.inverse();
	std::cout << "Invertion of a Matrix" << std::endl;
	std::cout << matrixTwo.toString() << std::endl;
	std::cout << "[ 0.75, -0.25, -0.25, \n -0.25, 0.75, -0.25, \n -0.25, -0.25, 0.75 ]" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	vector0 = matrixThree.row(row);
	std::cout << "Row Display" << std::endl;
	std::cout << vector0.toString() << std::endl;
	std::cout << "[ 1, 1, 2 ]" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	vector0 = matrixThree.row(col);
	std::cout << "Column Display" << std::endl;
	std::cout << vector0.toString() << std::endl;
	std::cout << "[ 1, 2, 1 ]" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	matrixTwo = matrixSix.rotationZ(angle);
	vector0 = matrixTwo * vector4;
	std::cout << "Z Rotation" << std::endl;
	std::cout << vector0.toString() << std::endl;
	std::cout << "[ -1, 1, 1 ]" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	matrixTwo = matrixSix.rotationY(angle);
	vector0 = matrixTwo * vector4;
	std::cout << "Y Rotation" << std::endl;
	std::cout << vector0.toString() << std::endl;
	std::cout << "[ 1, 1, -1 ]" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	matrixTwo = matrixSix.rotationX(angle);
	vector0 = matrixTwo * vector4;
	std::cout << "X Rotation" << std::endl;
	std::cout << vector0.toString() << std::endl;
	std::cout << "[ 1, -1, 1 ]" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	matrixTwo = matrixOne.translation(vector5);
	vector0 = matrixTwo * vector6;
	std::cout << "Translation" << std::endl;
	std::cout << vector0.toString() << std::endl;
	std::cout << "[ 7.0, 7.0, 1.0 ]" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	scaledVector = matrixFive.scale(scalar) * vector6;
	std::cout << "Scaling" << std::endl;
	std::cout << scaledVector.toString() << std::endl;
	std::cout << "[ 7.0, 3.5, 3.5 ]" << std::endl;
	std::cout << "-----------------------------" << std::endl;

	system("Pause");
	return 0;
}