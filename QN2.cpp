/* DEsign a class Employee with id, name and salary as data members. Implement functions to input
employee data and display employees who have salary greater than a user-specific amount.*/
#include <iostream>
using namespace std;
class Employee
{
    int id, salary;
    string name;

public:
    void setdata()
    {
        cout << "Enter employee data: " << endl;
        cout << "id: ";
        cin >> id;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "salary: ";
        cin >> salary;
    }
    int getsalary(){return salary;}
    string getname (){return name;}
};
int main()
{
    int count, i, salary ;
    Employee Redmi[1999];
    cout << "Enter the number of the employee: ";
    cin >> count;
    cout<<"Enter the specified salary:";
    cin>>salary;
    for (i = 0; i < count; i++)
    {
        Redmi[i].setdata();
    }
    for ( i = 0; i < count; i++)
    {
        if(Redmi[i].getsalary()>salary){
            cout<<"The employee with salary greater than "
         <<salary<<" are: "<<endl;
           cout<<Redmi[i].getname();
        }
    }
    
    return 0;
}