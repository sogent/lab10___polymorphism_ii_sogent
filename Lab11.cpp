#include <iostream>
#include "Employee.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    vector<Employee> Employees;
    vector<string> fileData;
    Employee employee1(123, "Adora");
    Employee employee2(456, "Ollie");
    //employee1.fire();
    Employees.push_back(employee1);
    Employees.push_back(employee2);



    for(int i=0;i<Employees.size();++i) {
        if (Employees.at(i).isEmployed()) {
            cout << Employees.at(i).getName()<<" is employed" << endl;
        } else {
            cout << Employees.at(i).getName()<<" is not employed" << endl;
        }
    }

    Employees.at(0).giveRaise(5);
    Employees.at(0).giveRaise(5);
    /*

    for(int i=0;i<Employees.size();++i) {
        cout << Employees.at(i).getName()<<", ";
        cout << Employees.at(i).getEmployeeID()<< endl;
        cout << Employees.at(i).getPayRate()<< endl;

    }
     */


    ifstream fin("/Users/sogent/CLionProjects/lab10---polymorphism-ii-sogent/input.txt");
    string line;
    vector<Employee> Employees1;


    while(getline(fin, line)) {
        string firstChar;
        firstChar=line.substr(0, 1);
        fileData.clear();

        stringstream inSS(line);
        while(getline(inSS, line, ' ')){
            fileData.push_back(line);
        }


        if(firstChar=="N"){

            int employeeID;
            string firstName;
            string lastName;
            string employeeName;
            employeeID=stoi(fileData[1]);
            firstName=fileData[2];
            lastName=fileData[3];

            employeeName=employeeName.append(firstName);
            employeeName=employeeName.append(" ");
            employeeName=employeeName.append(lastName);
            //employeeName=employeeName.append(",");
            //employeeName=firstName+" "+lastName+", ";


            //cout<<employeeID<<endl;
            //cout<<employeeName<<endl;
            Employee newEmployee(employeeID,employeeName);
            Employees1.push_back(newEmployee);


        }else if(firstChar=="R"){

            int employeeID;
            int employeeRaiseAmt;

            employeeID=stoi(fileData[1]);
            employeeRaiseAmt=stoi(fileData[2]);
            //cout<<employeeID<<endl;
            //cout<<employeeRaiseAmt<<endl;

            for(int i=0;i<Employees1.size();++i){
                if(Employees1.at(i).getEmployeeID()==employeeID){
                    Employees1.at(i).giveRaise(employeeRaiseAmt);
                }
            }


        }else if(firstChar=="P"){
            for(int i=0;i<Employees1.size();++i){
                Employees1.at(i).pay();
            }


        }else if(firstChar=="F"){
            int employeeID;
            employeeID=stoi(fileData[1]);
            for(int i=0;i<Employees1.size();++i){
                if(Employees1.at(i).getEmployeeID()==employeeID){
                    Employees1.at(i).fire();
                }
            }

        }


    }
    fin.close();




    //Putting output to new file
    ofstream fout("output.csv");
    for(int i=0;i<Employees1.size();++i){
        if(Employees1.at(i).getEmployeeID()==0) {
            fout << "Not employed with the company" << endl;
            fout << "Not employed with the company"<<endl;
            fout << setprecision(2) << fixed << Employees1.at(i).getBalance()<<endl;
            fout << Employees1.at(i).getPayRate() << endl;
            fout << endl;
        }else{
            fout<<Employees1.at(i).getName()<<", ";
            fout << Employees1.at(i).getEmployeeID()<<endl;
            fout <<"$"<< Employees1.at(i).getPayRate()<<endl;
            fout << "$"<<setprecision(2) << fixed <<Employees1.at(i).getBalance()<<endl;
            fout<<endl;
        }


    }
    fout.close();







    return 0;
}
