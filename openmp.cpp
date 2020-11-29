#include <iostream>
#include <vector>
#include <string>
#include <omp.h>

using namespace std;

bool isCorrect(double prop, double sum, int totalSum) {
	return prop * totalSum == sum;
}

int main()
{
	vector<double> childrenProp;
	vector<double> childrenSum;

	bool check = true;
	string str;
	string str1;
	double prop = 0;
	double totalSum = 0;
	double totalProportion = 0;
	int sum = 0;

	do {
		for (int i = 0; i < 1; i++) {
			cout << "Enter sum (positive,  integer number)" << endl;
			cin >> str;

			try {
				totalSum = stoi(str);
			}
			catch (const std::exception&) {
				i--;
			}
		}
	} while (totalSum <= 0);

	for (int i = 0; i < 8; i++) {
		do {
			cout << "Enter the proportion of the " << i + 1 << "th son (not negative, from 0 to 1)" << endl;

			cin >> str;

			cout << "Enter the sum of the " << i + 1 << "th son (not negative)" << endl;

			cin >> str1;

			try {
				prop = stod(str);
				sum = stod(str1);
			}
			catch (const std::exception&) {
				i--;
			}
		} while (prop < 0 || prop > 1 || sum < 0);

		childrenProp.push_back(prop);
		childrenSum.push_back(sum);
		sum = 0;
		prop = 0;
	}

	#pragma omp parallel for 
	for (int i = 0; i < 8; i++)
	{
		totalProportion += childrenProp[i];
	}

	if (totalProportion != 1) {
		cout << "Incorrect calculations" << endl;
		return 0;
	}

	int j = 0;

	#pragma omp parallel
	{
		while (check && j < 8)
		{
			#pragma omp critical
			{
				check = isCorrect(childrenProp[j], childrenSum[j], totalSum);

				if (!check) {
					cout << "Incorrect calculations" << endl;
					return 0;
				}

				j++;
			}
		}
	}

	cout << "OK" << endl;
	return 0;
}
