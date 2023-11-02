#include<iostream>
using namespace std;
int main()
{
	char userChoice;
	cout << "Do you want to find prime numbers in a given range or check if a specific number is prime. (F/C) : ";
	cin >> userChoice;
	if (userChoice == 'f' || userChoice == 'F')
	{
		int lowerBound, upperBound;
		bool Flag = true;
		cout << " Please enter the Lower bound : ";
		cin >> lowerBound;
		cout << " please enter the upper bound : ";
		cin >> upperBound;
		for (lowerBound; lowerBound <= upperBound; lowerBound++)
		{
			if (lowerBound == 0 || lowerBound == 1)
			{
				Flag = false;
			}
			else
			{
				for (int i = 2; i < lowerBound / 2; i++)
				{
					if (lowerBound % i == 0)
					{
						Flag = false;
						break;
					}
				}
			}
			if (Flag == true)
			{
				cout << lowerBound << " ";
			}
		}
	}
	else if (userChoice == 'c' || userChoice == 'C')
	{
		int Number;			bool flag = true;
		cout << "enter the number you want to check : ";
		cin >> Number;
		if (Number == 0 || Number == 1)
		{
			flag = false;
		}
		else
		{
			for (int i = 2; i < Number / 2; i++)
			{
				if (Number % i == 0)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
		{
			cout << "Number is a Prime Number";
		}
		else
		{
			cout << "Numbrer is a Composite Number";
		}
	}
	else
	{
		cout << "incorrect option";
	}

}