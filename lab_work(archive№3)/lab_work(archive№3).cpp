#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <functional>


using namespace std;


int main()
{

	setlocale(LC_ALL, "Rus");
	srand(time(NULL));


	ofstream WRITE; // writing and reading objects
	ifstream READ;
	char symb; // buffer

	function <void()> write_into;
	write_into = [&]()
	{

		int size; // quantity of the words to write

		cout << "Enter the quantity of words you want to write: " << endl;
		cin >> size;


		cout << "Enter your data: " << endl;

		for (int i = 0; i < size; i++)
		{

			string msg;

			SetConsoleCP(1251); // possibility to write russian letters

			cin >> msg;
			WRITE << msg << " ";

			SetConsoleCP(866); // returning default console settings

		}
	};



	/* Writing data to the A and B files */

	cout << "Let's write something into the А file!" << endl;
	WRITE.open("A.txt", ofstream::app);

		if (!WRITE.is_open())
		{
			cout << "Cannot open the file!" << endl;
		}
		else
		{
			write_into();
		}

	WRITE.close();


	cout << "Let's write something into the B file!" << endl;
	WRITE.open("B.txt", ofstream::app);

		if (!WRITE.is_open())
		{
			cout << "Cannot open the file!" << endl;
		}
		else
		{
			write_into();
		}

	WRITE.close();



	/* Writing all digits from A file to the C file */
	
	READ.open("A.txt");

		if (!READ.is_open())
		{
			cout << "Cannot open the file!" << endl;
		}
			

		WRITE.open("C.txt");

			if (!WRITE.is_open())
			{
				cout << "Cannot open the file!" << endl;
			}

			while (!READ.eof())
			{

				READ.get(symb);

				if (isdigit(symb))
				{
					WRITE << symb;
					WRITE << " ";
				}
				else { continue; }
			
			}

		WRITE.close();


	READ.close();


	/* Complete A file with lowercase letters from B file */
	
	READ.open("B.txt");

		if (!READ.is_open())
		{
			cout << "Cannot open the file!" << endl;
		}


		WRITE.open("A.txt", ofstream::app);

			if (!WRITE.is_open())
			{
				cout << "Cannot open the file!" << endl;
			}

			while (!READ.eof())
			{

				READ.get(symb);

				if (islower(symb))
				{
					WRITE << symb;
					WRITE << " ";
				}
				else { continue; }
				
			}

		WRITE.close();


	READ.close();
	
	return 0;
}