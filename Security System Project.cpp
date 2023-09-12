#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void intro();

int main()
{
	int a = 0;
	int i = 0;
	string text;
	string old;
	string password1;
	string password2;
	string pass;
	string name;
	string password0;
	string age;
	string user;
	string word;
	string word1;
	string credentials[2];
	string cp[2];

	intro();

	do
	{
		cout << endl << endl;
		cout << "Please enter your choice: ";
		cin >> a;

		switch (a)
		{
		case 1:
		{
			// Registration Process
			cout << "|--------------------|" << endl;
			cout << "|    Registration    |" << endl;
			cout << "|____________________|" << endl << endl;
			cout << "Please enter your username: ";
			cin >> name;
			cout << "Please enter your password: ";
			cin >> password0;
			cout << "Please enter your age: ";
			cin >> age;

			ofstream of1;
			of1.open("file.txt");
			if (of1.is_open())
			{
				// Writing credentials to file
				of1 << name << "\n";
				of1 << password0;
				cout << "Registration successful" << endl;
			}
			break;
		}
		case 2:
		{
			// Login process
			i = 0;

			cout << "|--------------------|" << endl;
			cout << "|        Login       |" << endl;
			cout << "|____________________|" << endl << endl;

			ifstream of2;
			of2.open("file.txt");
			cout << "Please enter your username: ";
			cin >> user;
			cout << "Please enter your password: ";
			cin >> pass;

			if (of2.is_open())
			{
				while (!of2.eof()) // Go until end of file is reached
				{
					while (getline(of2, text)) // Reads file line-by-line
					{
						istringstream iss(text);
						iss >> word;
						credentials[i] = word;
						i++;
					}

					if (user == credentials[0] && pass  == credentials[1]) // If username and password match those in the array
					{
						cout << "Login successful" << endl << endl;

						cout << "Details:" << endl;

						cout << "Username: " + name << endl;
						cout << "Password: " + pass << endl;
						cout << "Age: " + age << endl;
					}

					else // If credentials are wrong
					{
						cout << endl << endl << "Incorrect username or password" << endl;
						cout << "Press 2 to try again" << endl;
						cout << "Press 3 to change password" << endl;

						break;
					}
				}
			}
			break;
		}

		case 3:
		{
			i = 0;

			cout << "|--------------------|" << endl;
			cout << "|   Change Password  |" << endl;
			cout << "|____________________|" << endl << endl;

			ifstream of0;
			of0.open("file.txt");

			cout << "Please enter your old password: ";
			cin >> old;
			
			if (of0.is_open())
			{
				while (of0.eof())
				{
					while (getline(of0, text))
					{
						istringstream iss(text);
						iss >> word1;
						cp[i] = word1;
						i++;
					}

					if (old == cp[1])
					{
						of0.close();

						ofstream of1;
						if (of1.is_open())
						{
							cout << "Enter your new password: ";
							cin >> password1;
							cout << "Enter your new password again: ";
							cin >> password2;

							if (password1 == password2)
							{
								of1 << cp[0] << "\n";
								of1 << password1;
								cout << "Password changed successfully" << endl;
							}

							else
							{
								of1 << cp[0] << "\n";
								of1 << old;
								cout << "Passwords do not match, password was not changed";
							}
						}
					}
					else
					{
						cout << "Please enter a valid password" << endl;
						break;
					}
				}
			}
			break;
		}

		case 4:
		{
			break;
		}

		default:
			cout << "Please enter a valid choice";
			break;
		}
	} while (a != 4);

	return 0;
}

void intro()
{
	cout << "   Security System" << endl;

	cout << "|--------------------|" << endl;
	cout << "|1. Register         |" << endl;
	cout << "|2. Login            |" << endl;
	cout << "|3. Change Password  |" << endl;
	cout << "|4. Exit Program     |" << endl;
	cout << "|____________________|" << endl;
}