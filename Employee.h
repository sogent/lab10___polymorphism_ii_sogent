#pragma once
// Your name
// Today's date
// 

#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
private:
	int employeeID;
	string name;
	double balance;
	double payRate;
	bool employed = true;
public:
	// Constructor
	Employee(int id, string myName);

	// Getter to return the employee ID
	int getEmployeeID();

	// Getter to return the current pay rate
	double getPayRate();

	// Getter to return the current amount of pay earned
	double getBalance();

	// Getter to get Employee's name
	string getName();

	// Function to give the raise. It takes in a percent in whole numbers 
	// (ex: 5 for 5%)
	void giveRaise(int rate);

	// Pays the employee
	void pay();

	// Fires the Employee
	void fire();

	// Returns if the Employee is currently employed
	bool isEmployed();

};

#endif