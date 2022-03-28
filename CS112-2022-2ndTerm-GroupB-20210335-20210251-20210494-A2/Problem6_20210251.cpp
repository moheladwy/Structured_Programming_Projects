#include <iostream>
using namespace std;
int main()
{
	float salaryPerHour = 16.78;
	float hoursWorked;
	float extraHours;
	int dependents;
	float overTimePay;
	float totalSalary;
	float grossPay;
	float socialSecurityTax;
	float federalIncomeTax;
	float stateIncomeTax;
	float healthInsurance = 0;
	float unionDues = 10;
	cout << "input the number of hours you worked: ";
	cin >> hoursWorked;
	cout << "input the number of dependents: ";
	cin >> dependents;
	if (dependents >= 3) {
		healthInsurance = 35;
	}
	if (hoursWorked > 40) {
		extraHours = (hoursWorked - 40);
		overTimePay = extraHours * (salaryPerHour * 1.5);
		hoursWorked -= extraHours;
	}
	else {
		overTimePay = 0;
	}
	
	grossPay = ((salaryPerHour * hoursWorked)+overTimePay);
	socialSecurityTax = 0.06 * grossPay;
	federalIncomeTax = 0.14 * grossPay;
	stateIncomeTax = 0.05 * grossPay;
	totalSalary = grossPay - (socialSecurityTax + federalIncomeTax + stateIncomeTax + unionDues + healthInsurance);
	cout << "your gross pay = " << grossPay << "\n" << "amount withdheld for social security tax = " << socialSecurityTax << "\n"
		<< "amount withdheld for federal income tax = " << federalIncomeTax << "\n" << "amount withdheld for state income tax = " << stateIncomeTax
		<< "\n" << "amount withdheld for union dues = " << unionDues << "\n" << "amount withdheld for health insurance = " << healthInsurance
		<< "\n" << "your take-home pay = " << totalSalary;

		
	


}

