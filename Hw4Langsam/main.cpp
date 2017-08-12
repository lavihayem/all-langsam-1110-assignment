/*
  Name:program4
  Copyright:
  Author: Shafieollah Lavihayem
  Date: 7/19/2017 18:51
  Description: Calculates net and gross pay and over time for ten people

*/
#include <cstdlib>
#include <iostream>


using namespace std;
#include <fstream>
int highest(int temp1, int temp2,int temp3,int temp4,int temp5);
int lowest(int temp1, int temp2,int temp3,int temp4,int temp5);
float mean(int,int);
string similar(int temp1, int temp2,int temp3,int temp4,int temp5);

//ofstream outfile;

int main()
{
    // ifstream infile;                      //create the file infile for input
    int temp1,temp2,temp3,temp4,temp5,highestValue,lowestValue;
    float avgMean;
    string acknowledge;
    ifstream infile;
    infile.open("data3.txt");  //open the file

    if ( !infile.is_open() )              //checks to see if file was opened
    {
        // The file could not be opened
        cout << endl << "ERROR: Unable to open file" << endl;
        system ("PAUSE");
        exit(1);
    }

    //*********************************************************************************8
    ofstream outfile;
    outfile.open("resultdata.txt");

    outfile.setf(ios::fixed,ios::floatfield);          // setup output format for
    outfile.precision(1);
   // infile>>temp1>>temp2>>temp3>>temp4>>temp5;
    cout<<"Monday"<<"      "<<"Tuesday"<<"      "<<"Wednesday"<<"       "<<"Thursday"<<"          "<<"Friday"<<"    " ;
        cout<<" highestValue"<<"       lowestValue     "<<"   avg  Mean       "<<endl;
        outfile<<"Monday"<<"      "<<"Tuesday"<<"      "<<"Wednesday"<<"       "<<"Thursday"<<"          "<<"Friday"<<"    " ;
        outfile<<" highestValue"<<"       lowestValue     "<<"   avg  Mean       "<<endl<<endl;
    while( infile>>temp1>>temp2>>temp3>>temp4>>temp5 )
    {

        highestValue = highest(temp1,temp2,temp3,temp4,temp5);
        lowestValue = lowest(temp1,temp2,temp3,temp4,temp5);
        avgMean=mean(highestValue,lowestValue);
        acknowledge=similar(temp1,temp2,temp3,temp4,temp5);

        /*  highestMean=0;
          if(temp1>highestMean)
              highestMean=temp1;
          if(temp2>highestMean)
              highestMean=temp2;
          if(temp3>highestMean)
              highestMean=temp3;
          if(temp4>highestMean)
              highestMean=temp4;
          if(temp5>highestMean)
              highestMean=temp5;
          cout<<"\n\n\highestMean :        "<<highestMean;
          */
        //***************************************************************

        // cout<<"highestMean :        "<<highestMean;


        // outfile<<temp1<<"      "<<temp2<<"      "<<temp3<<"      "<<temp4<<"       "<<temp5;
        // outfile.width(5);
        /* outfile.width(5);
         outfile<<temp2;
         outfile.width(5);
          outfile<<temp3;
         outfile.width(5);
          outfile<<temp4;
         outfile.width(5);
          outfile<<temp5;
         outfile.width(5);
        //   outfile<<temp1<<temp2<<temp3<<temp4<<temp5;
        //  outfile.width(5);
        //  outfile<<temp1<<temp2<<temp3<<temp4<<temp5;
        */


        // outfile<<"Monday"<<"      "<<"   Tuesday"<<"      "<<"Wednesday"<<"       "<<"Thursday"<<"          "<<"Friday"<<endl;
        cout<<temp1<<"          "<<temp2<<"           "<<temp3<<"             "<<temp4<<"                  "<<temp5;
        cout<<"              "<<highestValue<<"               "<<lowestValue<<"                  "<<avgMean<<endl<<endl;
       outfile<<temp1<<"            "<<temp2<<"          "<<temp3<<"            "<<temp4<<"                  "<<temp5;
        outfile<<"             "<<highestValue<<"              "<<lowestValue<<"                 "<<avgMean<<endl<<endl;
        cout<<"The temperature was  "<<acknowledge<<" the same any consecutive day ."<<endl<<endl;
       outfile<<"The temperature was  "<<acknowledge<<" the same any consecutive day ."<<endl<<endl;

        //infile>>temp1>>temp2>>temp3>>temp4>>temp5;
    }


    return 0;
}
int highest(int temp1, int temp2,int temp3,int temp4,int temp5)
{
    int   highestMean=0;
    if(temp1>highestMean)
        highestMean=temp1;
    if(temp2>highestMean)
        highestMean=temp2;
    if(temp3>highestMean)
        highestMean=temp3;
    if(temp4>highestMean)
        highestMean=temp4;
    if(temp5>highestMean)
        highestMean=temp5;
    //  cout<<"\n\n\ highest  Mean :           "<<highestMean;
    return highestMean;
}
//*************************************************************************
int lowest(int temp1, int temp2,int temp3,int temp4,int temp5)
{
    int lowestMean=1000;
    if(temp1<lowestMean)
        lowestMean=temp1;
    if(temp2<lowestMean)
        lowestMean=temp2;
    if(temp3<lowestMean)
        lowestMean=temp3;
    if(temp4<lowestMean)
        lowestMean=temp4;
    if(temp5<lowestMean)
        lowestMean=temp5;
    //   cout<<"\n\n\ lowest  Mean :            "<<lowestMean;
    return lowestMean;
}
float mean(int highestValue,int lowestvalue)
{
    float avgMean;
    avgMean=(highestValue+lowestvalue)*.5;

    // cout<<"\n\n\ average  Mean :        "<<avgMean;
    return avgMean;
}
string similar(int temp1, int temp2,int temp3,int temp4,int temp5)
{
    if(temp1==temp2)
        return "yes";
    else if(temp2==temp3)
        return "yes";
    else  if(temp3==temp4)
        return "yes";
    else if(temp4==temp5)
        return "yes";
    return "NO";
}
