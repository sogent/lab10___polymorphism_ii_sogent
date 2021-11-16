// Sarah Ogent
// 11/15/2021
// 

#include <string>
#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;


Employee::Employee(){
    employeeID=000;
    name="";
    balance=0.00;
    payRate=10.00;
    employed=true;
}
// Constructor
Employee::Employee(int id, string myName) {
    employeeID=id;
    name=myName;
    balance=0.00;
    payRate=10.00;
    employed=true;
}

// Getter to return the employee ID
int Employee::getEmployeeID(){
    return employeeID;
}

// Getter to return the current pay rate
double Employee::getPayRate(){
    return payRate;
}

// Getter to return the current amount of pay earned
double Employee::getBalance(){
    return balance;
}

// Getter to get Employee's name
string Employee::getName(){
    return name;
}


// Function to give the raise. It takes in a percent in whole numbers
// (ex: 5 for 5%)
void Employee::giveRaise(int rate){
    double raiseAmt;
    raiseAmt=static_cast<double>(rate)/100;
    raiseAmt=raiseAmt*payRate;


    payRate=payRate+raiseAmt;



}

// Pays the employee
void Employee::pay(){
    Employee employee;
    if(employee.isEmployed()){
        balance=balance+payRate;
    }else{
        balance=balance+0;
    }

}

// Fires the Employee
void Employee::fire(){
    employeeID=000;
    payRate=0.00;
    employed=false;

}

// Returns if the Employee is currently employed
bool Employee::isEmployed(){
    return employed;


}

