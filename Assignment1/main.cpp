/*
  Name: paycheck
  Copyright:
  Author: Shafieollah Lavihayem
  Date: 7/19/2017 18:51
  Description: Calculates net and gross pay and over time for ten people

*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ofstream outfile;
  outfile.open("output.txt");

    cout.setf(ios::fixed,ios::floatfield);          // setup output format for
    cout.precision(2);
    outfile.setf(ios::fixed,ios::floatfield);          // setup output format for
    outfile.precision(2);

    float tax,netPay,GrossPay,OverTime,StraightTimePay,OverTimePay;
    int normalWorkingHour,hoursWorked;
    float RateOfPay,NetPay,NumberOfOverTime;

    cout<<"Enter Hour Worked and Normal Working Hour and Rate of Pay "<<endl;

    cin>> hoursWorked>>normalWorkingHour>>RateOfPay;
    while(hoursWorked>0)
    {

        StraightTimePay=normalWorkingHour*RateOfPay;
        OverTime=hoursWorked-normalWorkingHour;
        if(OverTime<0)
            OverTime=0;
        OverTimePay=1.5 * OverTime * RateOfPay;
        GrossPay=StraightTimePay+OverTimePay;
        tax=.20*GrossPay;
        NetPay=GrossPay-tax;
        cout<<"Rate of pay:          "<<RateOfPay<<endl;
        cout<<"Total hours worked:   "<<hoursWorked<<endl;
        cout<<"Straight time:        "<<normalWorkingHour<<endl;
        cout<<"Over Time:            "<<OverTime<<endl;
        cout<<"Gross Pay:            "<<GrossPay<<endl;
        cout<<"Tax:                  "<<tax<<endl;
        cout<<"Net Pay:              "<<NetPay<<endl;
        //cout<<"Enter Hour Worked and Normal Working Hour and Rate of Pay "<<endl;
        outfile<<"Rate of pay:          "<<RateOfPay<<endl;
        outfile<<"Total hours worked:   "<<hoursWorked<<endl;
        outfile<<"Straight time:        "<<normalWorkingHour<<endl;
        outfile<<"Over Time:            "<<OverTime<<endl;
        outfile<<"Gross Pay:            "<<GrossPay<<endl;
        outfile<<"Tax:                  "<<tax<<endl;
        outfile<<"Net Pay:              "<<NetPay<<endl;
        cout<<"Enter Hour Worked and Normal Working Hour and Rate of Pay "<<endl;

        cin>> hoursWorked>>normalWorkingHour>>RateOfPay;
    }//end of while loop
        outfile.close();

    return 0;
}
/*}Enter Hour Worked and Normal Working Hour and Rate of Pay
 12 50 100
Rate of pay:          100.00
Total hours worked:   12
Straight time:        50
Over Time:            0.00
Gross Pay:            5000.00
Tax:                  1000.00
Net Pay:              4000.00
Enter Hour Worked and Normal Working Hour and Rate of Pay
12 45 78
Rate of pay:          78.00
Total hours worked:   12
Straight time:        45
Over Time:            0.00
Gross Pay:            3510.00
Tax:                  702.00
Net Pay:              2808.00
Enter Hour Worked and Normal Working Hour and Rate of Pay
12 87 56
Rate of pay:          56.00
Total hours worked:   12
Straight time:        87
Over Time:            0.00
Gross Pay:            4872.00
Tax:                  974.40
Net Pay:              3897.60
Enter Hour Worked and Normal Working Hour and Rate of Pay
55 20 10
Rate of pay:          10.00
Total hours worked:   55
Straight time:        20
Over Time:            35.00
Gross Pay:            725.00
Tax:                  145.00
Net Pay:              580.00
Enter Hour Worked and Normal Working Hour and Rate of Pa*/
