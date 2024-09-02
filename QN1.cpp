/* ccreate a class person with name and date of birth as data members.Ask the user
 to enter a date of birth and print all persons name with a matched date of birth. */
 #include<iostream>
 #include<iomanip>
 using namespace std;
 class Person
 {
    string name;
   int year, month, day;
    public:
     
    void setdata(){
        cout<<"Enter the name of the person: "<<endl;
       cin.ignore();
       getline(cin,name);
        cout<<"Enter the date of brith of "<< name<<" :"<<endl;
        cout<<"Year: "<<endl;
        cin>>year;
          cout<<"month: "<<endl;
        cin>>month;
          cout<<"day: "<<endl;
        cin>>day;
    }
int getyear(){return year;}
int getmonth(){return month;}
int getday(){return day;}
string getname(){return name;}
 };
 int main()
 {
    int count,i,j;
    Person matchingdob[1000];
    cout<<"Enter the number of the person: "<<endl;
   cin>>count;
   for ( i = 0; i < count; i++)
   {
    matchingdob[i].setdata();
   }
   cout<<"The list of people name with matching date of birth are: "<<endl;
   for(i = 0; i < count - 1; i++){
    for(j = 1 ; j< count; j ++){
        if (matchingdob[i].getyear() == matchingdob[j].getyear() || matchingdob[i].getmonth() == matchingdob[j].getmonth()||matchingdob[i].getday() == matchingdob[j].getday())
        {
            cout<<matchingdob[i].getname();
              cout<<matchingdob[j].getname();
        }
    }
   }
 return 0;
 }