
#include <iostream>
using namespace std;

int main()
{
	int day;
	char type;
	int hour;
	int night;
	int weekend;
	int charge;
	string date;

	cout <<
		" General Checkup: $80\n" <<
		" If weekend(Saturday or Sunday), +$20 surcharge\n" <<
		" Emergency : $250\n" <<
		" If at night(hour >= 20 or hour < 6), +$50 surcharge\n" <<
		" Specialist : $150\n" <<
		" If no referral, +$40 extra fee\n";

	cout << endl << "Enter 1 for general check up, Enter 2 for emergency, Enter 3 for specialist:";
	cin >> type;

	cout << endl << "enter the day of the week as a number 1-7:";
	cin >> day;
	if (day == 6 || day == 7)
	{
		weekend = 20;
	}
	else
	{
		weekend = 0;
	}
	cout << endl << "enter the time of day as a number 1-24 for exanple 9:00am would be 9:";
	cin >> hour;
	if (hour >= 20 || hour < 6)
	{
		night = 50;
	}
	else
	{
		night = 0;
	}

	switch (type)
	{
	case '1':
	{
		charge = 80;

		if (hour > 17)
		{
			switch (day+1)
			{
			case 8:
				date = "Monday";
				break;
			case 2:
				date = "Tuesday";
				break;
			case 3:
				date = "Wednesday";
				break;
			case 4:
				date = "Thursday";
				break;
			case 5:
				date = "Friday";
				break;
			case 6:
				date = "Saturday";
				break;
			case 7:
				date = "Sunday";
				break;
			default:
				cout << endl << "Invalid day number\n";
			}
			cout << endl << "you're next appointment is at 9:00 on " << date << endl;
		}
		else
		{
			cout << endl << "the doctor can see you now";
		}
		cout << "your bill will be:$" << charge + night + weekend << endl;
		break;
	}
	case '2':
	{
		charge = 250;
		cout << "Immediate - Proceed to ER bay\n";

		cout << "your bill will be:$" << charge + night + weekend << endl;
		break;
	}
	case '3':
	{
		char ref;
		int refc;
		charge = 150;
		

		cout << "do you have a referal, enter y for yes and n for no:";
		cin >> ref;

		if (ref == 'Y' || ref == 'y')
		{
			refc = 0;
		}
		else
		{
			refc = 40;
		}

		if (hour >= 10 && hour <= 16 && day < 6)
		{
			cout << endl << "the doctor can see you now";

			cout << "your bill will be:$" << charge + night + weekend + refc << endl;
		}
		else
		{
			cout << endl << "you're next appointment is at 10:00 on Monday\n";

			cout << "your bill will be:$" << charge + night + refc << endl;
		}
		
		break;
	}
	default:
	{
		cout << "Invalid imput.\n";
	}
	return 0;
	}
}