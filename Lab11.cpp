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

        //cout<<line<<endl;


        stringstream inSS;
        inSS.str(line);
        string employeeAction;

        inSS>>employeeAction;
        //cout<<employeeAction;
        //inSS.flush();

        if(employeeAction=="NEW"){

            cout<<"NEW"<<endl;
            int employeeID;
            string employeeFirstName;
            string employeeLastName;
            string nextInput;
            //extracting from string stream
            inSS>>nextInput;
            //inserting into output stream
            //cout<<nextInput<<endl;
            employeeID=stoi(nextInput);
            cout<<employeeID<<endl;
            inSS>>nextInput;
            employeeFirstName=nextInput;
            //cout<<employeeFirstName;
            inSS>>nextInput;
            employeeLastName=nextInput;
            //cout<<employeeLastName;
            //cout<<employeeFirstName<<" "<<employeeLastName<<", ";
            string employeeName=employeeFirstName+" "+employeeLastName;
            cout<<employeeName<<endl;

            Employee newEmployee(employeeID,employeeName);
            Employees1.push_back(newEmployee);



        }

        if(employeeAction=="RAISE"){

            cout<<"RAISE"<<endl;
            int employeeID;
            int employeeRaiseAmt;
            string nextInput;
            inSS>>nextInput;
            employeeID=stoi(nextInput);
            cout<<employeeID<<endl;
            inSS>>nextInput;
            employeeRaiseAmt=stoi(nextInput);
            cout<<employeeRaiseAmt<<endl;

            for(int i=0;i<Employees1.size();++i){
                if(Employees1.at(i).getEmployeeID()==employeeID){
                    Employees1.at(i).giveRaise(employeeRaiseAmt);
                }
            }

        }

        if(employeeAction=="PAY"){
            for(int i=0;i<Employees1.size();++i){
                Employees1.at(i).pay();
            }
        }

        if(employeeAction=="FIRE"){
            int employeeID;
            string nextInput;
            inSS>>nextInput;
            employeeID=stoi(nextInput);


            for(int i=0;i<Employees1.size();++i){
                if(Employees1.at(i).getEmployeeID()==employeeID){
                    Employees1.at(i).fire();
                }
            }

        }



    }
    fin.close();




    //Putting output to new file
    ofstream fout("output.txt");
    for(int i=0;i<Employees1.size();++i){
        if(Employees1.at(i).getEmployeeID()==0) {
            fout << "Not employed with the company" << endl;
            fout << "Not employed with the company"<<endl;
            fout << setprecision(2) << fixed << Employees1.at(i).getBalance()<<endl;
            fout << setprecision(2)<<fixed<<Employees1.at(i).getPayRate() << endl;
            fout << endl;
        }else{
            fout<<Employees1.at(i).getName()<<", ";
            fout << Employees1.at(i).getEmployeeID()<<endl;
            fout <<"$"<<setprecision(2)<<fixed<< Employees1.at(i).getPayRate()<<endl;
            fout << "$"<<setprecision(2) << fixed <<Employees1.at(i).getBalance()<<endl;
            fout<<endl;
        }


    }
    fout.close();







    return 0;
}
