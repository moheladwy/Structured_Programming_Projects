#include <iostream>
#include <string>
#include <valarray>
using namespace std;

string first_number = "", _operator_ = "", second_number = "";

string get_input(); // Done.
string make_lowerCase(string message); // Done.
bool check_spaces_in_input(string equation); // Done.
void split_input(string equation); // Done.
bool check_numbers(string number); // Done.
bool check_operator(string _operator_); // Done.
bool check_backslach(string number); // Done.
double mini_split(string nuber); // Done.
void program(); // Done.

void as_fraction(double number, int cycles = 10, double precision = 5e-4) {
	int sign = number >= 0 ? 1 : -1;
	number = number * sign; //abs(number);
	double new_number, whole_part;
	double decimal_part = number - (int)number;
	int counter = 0;

	valarray<double> vec_1{ double((int)number), 1 }, vec_2{ 1,0 }, temporary;

	while (decimal_part > precision && counter < cycles) {
		new_number = 1 / decimal_part;
		whole_part = (int)new_number;

		temporary = vec_1;
		vec_1 = whole_part * vec_1 + vec_2;
		vec_2 = temporary;

		decimal_part = new_number - whole_part;
		counter += 1;
	}
	if (vec_1[1] != 1)
	{
		cout << sign * vec_1[0] << '/' << vec_1[1] << endl;
	}
	else
	{
		cout << sign * vec_1[0] << endl;
	}
}

int main()
{
	program();
	return 0;
}

string get_input() 
{
	string equation;
	equation = "";
	while (equation.empty())
	{
		cout << "Please enter a rational number operations (or exit): ";
		getline(cin, equation);
	}
	return equation;
}

string make_lowerCase(string message)
{
	string lowerCase_message = "";
	for (int i = 0; i < message.length(); i++)
	{
		lowerCase_message += tolower(message[i]);
	}
	return lowerCase_message;
}

bool check_spaces_in_input(string equation)
{
	int counter = 0;
	for (auto letter : equation)
	{
		if (letter == ' ')
		{
			counter += 1;
		}
	}
	if (counter == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void split_input(string equation)
{
	int i = 0;

	for (; i < equation.length(); i++)
	{
		if (equation[i] != ' ')
		{
			first_number += equation[i];
		}
		else
		{
			i++;
			break;
		}
	}
	for (; i < equation.length(); i++)
	{
		if (equation[i] != ' ')
		{
			_operator_ += equation[i];
		}
		else
		{
			i++;
			break;
		}
	}
	for ( i;i < equation.length(); i++)
	{

		if (equation[i] != ' ')
		{
			second_number += equation[i];
		}
		else
		{
			break;
		}
	}
}

bool check_numbers(string number)
{
	bool checker = true;
	if (number[0] == '-')
	{
		for (int i = 1; i < number.length(); i++)
		{
			if (!(isdigit(number[i])) && number[i] != '/')
			{
				checker = false;
				break;
			}
			else if (number[number.length() - 1] == '/')
			{
				checker = false;
				break;
			}
			else if ((number[i] == '/' && number[i + 1] == '0'))
			{
				checker = false;
				break;
			}
		}
	}
	else if (isdigit(number[0]))
	{
		for (int i = 0; i < number.length(); i++)
		{
			if (!(isdigit(number[i])) && number[i] != '/')
			{
				checker = false;
				break;
			}
			else if (number[number.length() - 1] == '/')
			{
				checker = false;
				break;
			}
			else if ((number[i] == '/' && number[i + 1] == '0'))
			{
				checker = false;
				break;
			}
		}
	}
	else
	{
		checker = false;
	}
	return checker;
}

bool check_operator(string _operator_)
{
	if (_operator_ == "+" || _operator_ == "-" || _operator_ == "*" || _operator_ == "/")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_backslach(string number)
{
	bool checker = false;
	for (auto letter : number)
	{
		if (letter == '/')
		{
			checker = true;
			break;
		}
	}
	return checker;
}

double mini_split(string number)
{
	double result;
	if (check_backslach(number))
	{
		string mini_first_number, mini_second_number;
		long double num1, num2;int i = 0;
		for (; i < number.length(); i++)
		{
			if (number[i] != '/')
			{
				mini_first_number += number[i];
			}
			else
			{
				i++;
				break;
			}
		}

		for (;i < number.length(); i++)
		{

			mini_second_number += number[i];
		}
		num1 = stold(mini_first_number);
		num2 = stold(mini_second_number);
		result = num1 / num2;
	}
	else
	{
		result = stold(number);
	}
	return result;

}

void program()
{
	cout << "Ahlan ya user ya habeby, Please Enter Your Calculation as Follows => " << "{Number 1 => (+ , - , / , *) => Number 2}." << "\n";
	cout << "There have to be Spaces between the First Number, the operation and the Second Number then Enter.\n" << "Numbers can be Rationals as (x/y) or Integers as (z).\n";
	string equation; 
	bool num1_stat, num2_stat, operation_stat;
	long double number1, number2, result;
	while (true)
	{
		while (true) {
			equation = get_input();
			equation = make_lowerCase(equation);
			if (equation == "exit") {
				break;
			}
			else if (check_spaces_in_input(equation)) {
				split_input(equation);
				num1_stat = check_numbers(first_number);
				num2_stat = check_numbers(second_number);
				operation_stat = check_operator(_operator_);
				if (num1_stat && num2_stat && operation_stat) {
					number1 = mini_split(first_number);
					number2 = mini_split(second_number);
					if (_operator_ == "/" && number2 == 0) {
						cout << "Can't didvide by 0, try again with different operator or different Denumenator.\n";
					}
					else {
						if (_operator_ == "+") {
							result = number1 + number2;
						}
						else if (_operator_ == "-") {
							result = number1 - number2;
						}
						else if (_operator_ == "*") {
							result = number1 * number2;
						}
						else {
							result = number1 / number2;
						}
						cout << "The result = "; as_fraction(result);
						first_number = ""; _operator_ = ""; second_number = "";
					}
				}
				else {
					first_number = ""; _operator_ = ""; second_number = "";
					cout << "Please Enter a Valid Input.\n";
				}
			}
			else {
				cout << "Enter the Equation that following (a/b operation c/d), the numbers and the operation must be seperated by space.\n";
			}
		}
		break;
	}
	cout << "Thank you for using rational number calculator.\n";
}