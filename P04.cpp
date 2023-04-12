//P04 - Marc Holley
#include <iostream> //cin and cout
using namespace std;

#include <stdlib.h> //system ()

/*This program will calculate the monthly pay of employees by using the hourly rate of pay and hours worked each week.*/

int main()
{
	//declaring and initializing constants
	const double RATE1 = 1.0, RATE2 = 1.5, RATE3 = 2.0;

	//declaring variables
	int empCount, loopCount;

	int w1Hrs, w2Hrs, w3Hrs, w4Hrs, empQty, reportQty = 0;

	double rate, averageGross;

	double w1Pay1, w1Pay2, w1Pay3, w1Total;
	double w2Pay1, w2Pay2, w2Pay3, w2Total;
	double w3Pay1, w3Pay2, w3Pay3, w3Total;
	double w4Pay1, w4Pay2, w4Pay3, w4Total;

	double empTotal1, empTotal2, empTotal3, empTotal;

	//accumulators initialized to zero
	double reportTotal1 = 0, reportTotal2 = 0,
		   reportTotal3 = 0, reportTotal = 0;

	bool hrsError;

	char prompt;

	//sets decimal formatting
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "P04 - Marc Holley				\n\n";

	//getting employee count
	//do-while is processed until a valid empCount is entered (0 or greater)
	do
	{
		cout << "Enter the number of employees to process. \n";
		cout << "Enter 0 (zero) to exit: ";

		cin >> empCount;

		if (empCount < 0)
			cout << "Error: the number of employees to "
				 << "process must be 0 or greater. Try again.\n\n";
		}while (empCount < 0);

		//loopCounter initialized to 1
		loopCount = 1;

		//processes employees
		//while loop is controlled by the number of employees to process
		//if zero was entered, then we just skip the loop
		while (loopCount <= empCount)
		{
			//displays which employee we are currently processing
			cout << "\nP04 - Marc Holley\t\tEmployee: "
				 << loopCount << endl << endl;

			//do-while loop with if conditional statement gets a valid rate or returns an error message and ask again
			do
			{
				cout << "Enter the pay rate ($5.25 - $30.00): ";
				cin >> rate;

				if (rate < 5.25 || rate > 30.00)
					cout << "Error: The rate must be between $5.25 and $30.00. \n\n";
			} while (rate < 5.25 || rate > 30.00);

			/*do-while loop that gets the quantities for each of the four weeks and validates them using if conditional statements with logical operators
			or returns an error message and ask again*/
			do
			{

				hrsError = false;

				cout << "Enter four hours worked separated by a space (0 - 60): ";
				cin >> w1Hrs >> w2Hrs >> w3Hrs >> w4Hrs;


				if ((w1Hrs == 0) && (w2Hrs == 0) && (w3Hrs == 0) && (w4Hrs == 0))
				{
					cout << "Error: All four hours cannot be zero. \n\n";
					hrsError = true;
				}
				if ((w1Hrs < 0) || (w2Hrs < 0) || (w3Hrs < 0) || (w4Hrs < 0))
				{
					cout << "Error: Negative values are not valid. \n\n";
					hrsError = true;
				}
				if ((w1Hrs > 60) || (w2Hrs > 60) || (w3Hrs > 60) || (w4Hrs > 60))
				{
					cout << "Error: Values may not exceed 60. \n\n";
					hrsError = true;
				}
			} while (hrsError);

			//Process the hourly rate of pay for 4 weeks using conditional if else nested if else statements

			//Week 1
			if (w1Hrs < 41)
			{
				w1Pay1 = w1Hrs * rate;
				w1Pay2 = 0;
				w1Pay3 = 0;
			}
			else
			{
				if (w1Hrs < 51)
				{
					w1Pay1 = 40 * rate;
					w1Pay2 = (w1Hrs - 40) * rate * RATE2;
					w1Pay3 = 0;
				}
				else
				{
					w1Pay1 = 40 * rate;
					w1Pay2 = 10 * rate * RATE2;
					w1Pay3 = (w1Hrs - 50) * rate * RATE3;
				}
			}

			//Week 2
			if (w2Hrs < 41)
			{
				w2Pay1 = w2Hrs * rate;
				w2Pay2 = 0;
				w2Pay3 = 0;
			}
			else
			{
				if (w2Hrs < 51)
				{
					w2Pay1 = 40 * rate;
					w2Pay2 = (w2Hrs - 40) * rate * RATE2;
					w2Pay3 = 0;
				}
				else
				{
					w2Pay1 = 40 * rate;
					w2Pay2 = 10 * rate * RATE2;
					w2Pay3 = (w2Hrs - 50) * rate * RATE3;
				}
			}

			//Week 3
			if (w3Hrs < 41)
			{
				w3Pay1 = w3Hrs * rate;
				w3Pay2 = 0;
				w3Pay3 = 0;
			}
			else
			{
				if (w3Hrs < 51)
				{
					w3Pay1 = 40 * rate;
					w3Pay2 = (w3Hrs - 40) * rate * RATE2;
					w3Pay3 = 0;
				}
				else
				{
					w3Pay1 = 40 * rate;
					w3Pay2 = 10 * rate * RATE2;
					w3Pay3 = (w3Hrs - 50) * rate * RATE3;
				}
			}

			//Week 4
			if (w4Hrs < 41)
			{
				w4Pay1 = w4Hrs * rate;
				w4Pay2 = 0;
				w4Pay3 = 0;
			}
			else
			{
				if (w4Hrs < 51)
				{
					w4Pay1 = 40 * rate;
					w4Pay2 = (w4Hrs - 40) * rate * RATE2;
					w4Pay3 = 0;
				}
				else
				{
					w4Pay1 = 40 * rate;
					w4Pay2 = 10 * rate * RATE2;
					w4Pay3 = (w4Hrs - 50) * rate * RATE3;
				}
			}

			//sum the weekly totals (going across the columns)
			w1Total = w1Pay1 + w1Pay2 + w1Pay3;
			w2Total = w2Pay1 + w2Pay2 + w2Pay3;
			w3Total = w3Pay1 + w3Pay2 + w3Pay3;
			w4Total = w4Pay1 + w4Pay2 + w4Pay3;

			//sum the employee totals (going down the columns)
			empTotal1 = w1Pay1 + w2Pay1 + w3Pay1 + w4Pay1;
			empTotal2 = w1Pay2 + w2Pay2 + w3Pay2 + w4Pay2;
			empTotal3 = w1Pay3 + w2Pay3 + w3Pay3 + w4Pay3;
			empTotal = w1Total + w2Total + w3Total + w4Total;

			empQty = w1Hrs + w2Hrs + w3Hrs + w4Hrs;

			//accumulates the report totals
			reportTotal1 += empTotal1;
			reportTotal2 += empTotal2;
			reportTotal3 += empTotal3;
			reportTotal += empTotal;

			reportQty += empQty;



			//displays headings
			cout << endl
				<< "Week \tRate \tHours \t1.0 \t1.5 \t2.0 \tTotal \n\n"
				//display details
				<< "W1 \t" << rate << "\t" << w1Hrs << "\t" << w1Pay1 << "\t"
				<< w1Pay2 << "\t" << w1Pay3 << "\t" << w1Total << endl

				<< "W2 \t" << rate << "\t" << w2Hrs << "\t" << w2Pay1 << "\t"
				<< w2Pay2 << "\t" << w2Pay3 << "\t" << w2Total << endl

				<< "W3 \t" << rate << "\t" << w3Hrs << "\t" << w3Pay1 << "\t"
				<< w3Pay2 << "\t" << w3Pay3 << "\t" << w3Total << endl

				<< "W4 \t" << rate << "\t" << w4Hrs << "\t" << w4Pay1 << "\t"
				<< w4Pay2 << "\t" << w4Pay3 << "\t" << w4Total << endl
				<< endl

				//display employee totals
				<< "Employee Totals\t" << empQty
				<< "\t" << empTotal1
				<< "\t" << empTotal2
				<< "\t" << empTotal3
				<< "\t" << empTotal
				<< endl << endl

				<< "Press Enter to process the next employee or Report Totals: ";
			cin.ignore();
			prompt = cin.get();

			system("cls"); //clear screen for next salesperson

			//increments the count controlling the loop
			loopCount++;
		}

		//calculating the average using if else conditional statements
		if (empCount > 0)
		{
			averageGross = reportTotal / empCount;
		}
		else
		{
			averageGross = 0;
		}
		//displays report totals
		cout << "\nReport Totals \t" << reportQty
			<< "\t" << reportTotal1
			<< "\t" << reportTotal2
			<< "\t" << reportTotal3
			<< "\t" << reportTotal
			<< endl << endl
			//display empCount and average
			<< "Number of employees:   \t" << empCount
			<< "\tAverage Gross:\t" << averageGross << endl << endl;

}
