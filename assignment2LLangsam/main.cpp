/*
  Name: paycheck2
  Copyright:
  Author: Shafieollah Lavihayem
  Date: 7/19/2017 18:51
  Description: Calculates net and gross pay and over time for ten people

*/
#include <cstdlib>
#include <iostream>


using namespace std;
#include <fstream>

//int findMax(int );
//
float computeBasePay(int,float);
    float computeTax(int,float );
    //int findMin(int );

int main()
{

    string lastName,firstName,oldestFirstN,oldestLastN,youngestFirstN,youngestLastN;
    int age,oldest=1,youngest=200;
    float hourWork,rateOfPay,overTime,normalHourWorked=40,basePay,tax,netPay;
    //  cout << "Hello world!" << endl;
    ofstream outfile;
    outfile.open("outfile.txt");

    outfile.setf(ios::fixed,ios::floatfield);          // setup output format for
    outfile.precision(2);
    cout<<"\t\t\t           Miser Corporation Payroll  "<<endl<<endl<<endl;
    outfile<<" \n\n\n\t\t\t           Miser Corporation Payroll  "<<endl<<endl<<endl;
    //************************************************************************************************
    ifstream infile;                      //create the file infile for input
    infile.open("misercorp.txt");  //open the file

    if ( !infile.is_open() )              //checks to see if file was opened
    {
        // The file could not be opened
        cout << endl << "ERROR: Unable to open file" << endl;
        system ("PAUSE");
        exit(1);
    }
    /************************************************************************/
    while(!infile.eof())
    {
        infile>>lastName>>firstName>>hourWork>>rateOfPay>>age;
        outfile<<"Last name"<<"  first name   "<<"     hour work"<<"    rate of pay"<<"    age "<<"  Base Pay"<<"  Net Pay"<<endl;
        outfile<<lastName<<"        "<<firstName<<"            "<<hourWork<<"        "<<rateOfPay<<"     "<<"     "<<age;

        basePay=computeBasePay(hourWork,rateOfPay);
        tax= computeTax(age,basePay);
        outfile<<"   "<<basePay;
        netPay=basePay-tax;
        outfile<<"     "<<netPay;

        outfile<<endl;
        outfile<<endl;
        outfile<<endl;
        // }//end of while loop
        /*max=findMax(age);
        outfile<<"Max age"<<max<<endl;
        cout<<"Max age"<<max<<endl<<endl<<endl;
        min= findMin(age);
        outfile<<"Min age"<<min<<endl;
        cout<<"Min age"<<min<<endl<<endl<<endl;
        outfile<<"The Payroll Program is finished"<<endl;
        */

        if(age>oldest)
        {
            oldest=age;
            oldestFirstN=firstName;
            oldestLastN=lastName;
//}

        }

        if(age<youngest)
        {
            youngest=age;

            youngestFirstN=firstName;
            youngestLastN=lastName;
        }
    }//end of while loop
// cout<<"Oldest person first name :  "<<Oldest person first name<<"    Oldest person last name:      "<< Oldest person last name<<"      "<<oldest<<endl<<endl;
//   cout<<"youngest person first name :  "<<firstName<<"    youngest person last name:      "<<lastName<< "     "<<youngest<<endl;
    outfile<<"Oldest person first name :  "<<oldestFirstN<<"     Oldest person last name:       "<<oldestLastN<<oldest<<endl<<endl;
    outfile<<"youngest person first name :  "<<youngestFirstN<<"   youngest person last name:    "<<youngestLastN<< "  "<<youngest<<endl;


//}




    infile.close();
    return 0;
}

//************************************************************************************************
float computeBasePay(int hourWork,float rateOfPay)
{
    float overTime, straightTimePay,normalHourWork=40,overTimePay,grossPay,basePay;
    if(hourWork<=40 && hourWork>0)
        normalHourWork==hourWork;
    else
        normalHourWork=40;


    straightTimePay=normalHourWork*rateOfPay;
    overTime=hourWork-40;
    if(overTime<0)
        overTime=0;

    overTimePay=1.5*overTime*rateOfPay;
    // cout<<"overTimePay"<<overTimePay<<endl;
//outfile<<"overTimePay"<<overTimePay<<endl;
    basePay=straightTimePay+overTimePay;

    //  cout<<"BasePay  is :"<<basePay<<endl;
    return basePay;
}

//**********************************************************************************************

float computeTax(int age,float basePay)
{
    float tax;
    if(age>=55)
        tax=.50*basePay;
    else
        tax=.10*basePay;
    //  cout<<"tax"<<tax;
    return tax;

}
//********************************************************************************************************

/*int findMax(int age){
     int max=0;
  for(int i; i<=15; i++)
  {
     // max=age;
      if (age>max)
          max=age;
  }//end of for loop
  return max;

}
//**********************************************************************************************************
int findMin(int age){
  int min=150;
  for(int i; i<=15; i++)
  {
     // max=age;
      if (age<min)
          min=age;
  }//end of for loop
  return min;

y


*/

