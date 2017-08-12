#include <cstdlib>
#include <fstream>
#include <cctype>
#include <iostream>
#include<string>
using namespace std;
void bubble(string MaleLastname[],string MaleFirstname[],string MaleAddress[], int n);
int match(string MaleLastname[],string MaleAddress[],string FemaleLastname,string FemaleAddress, int m);
ifstream infilew;
ifstream infile;



const int SIZE=25;

int main()
{
    string MaleFirstname[SIZE],MaleLastname[SIZE],MaleAddress[SIZE];
    string FemaleFirstname[SIZE],FemaleLastname[SIZE],FemaleAddress[SIZE];
    int countFemale=0,countMale=0,research, number=0,numberofNoMatch=0;

    infile.open("men.txt");    //open the file
    if ( !infile.is_open() )            //check to see if file was opened
    {
        // The file could not be opened
        cout << endl << "ERROR: Unable to open file" << endl;
        system ("PAUSE");
        exit(1);
    }

    //cout<<"Male"<<endl;
    while(!infile.eof() )
    {
        infile>>MaleFirstname[countMale]>>MaleLastname[countMale];
        getline(infile,MaleAddress[countMale]);
          countMale++;

    }//end of while loop
     cout<<"***************LIST OF MEN SORTED******************"<<endl<<endl<<endl;

    bubble( MaleLastname, MaleFirstname, MaleAddress,countMale);


    infilew.open("women.txt");    //open the file
    if ( !infilew.is_open() )            //check to see if file //was opened
    {
        // The file could not be opened
        cout << endl << "ERROR: Unable to open file" << endl;
        system ("PAUSE");
        exit(1);

    }
    cout<<endl<<endl<<"LIST OF Female(NOT SORTED)"<<endl;
    while(!infilew.eof() )
    {
        infilew>>FemaleFirstname[countFemale]>>FemaleLastname[countFemale];
        getline(infilew,FemaleAddress[countFemale]);
        cout<<FemaleLastname[countFemale]<<"    "<<FemaleFirstname[countFemale]
            <<"       "<<  FemaleAddress[countFemale]<< endl;
        countFemale++;
    }
    cout<<"*****NAME OF PEOPLE THAT MATCH*****"<<endl;

    for (int i=0; i< countFemale; i++)
    {
        research=match(MaleLastname,MaleAddress,FemaleLastname[i], FemaleAddress[i],                 countMale);

        if(research==-1)
            numberofNoMatch++;
        else
        {
            number++;
            cout<<FemaleLastname[i]<<", "<<FemaleFirstname[i]<<"   Mutch With   "
                <<MaleLastname[research]<<" ,"<<   MaleFirstname[research]<<endl<<endl
                <<endl;
        }

    }
    cout<<"The number of match was:   "<<number<<endl;
    cout<<"The number of no match was:   "<<numberofNoMatch<<endl;
     cout<<"************FEMALE   SORTED    LIST **********************"<<endl;

    bubble(FemaleLastname,FemaleFirstname,FemaleAddress,countFemale);
    // cout<<FemaleFirstname<<FemaleLastname<<FemaleAddress<<countFemale;
    // countFemale--;
    // }

    cout<<"**************************************"<<endl;

    infile.close();
    infilew.close();
    return 0;


}

void bubble(string MaleLastname[],string MaleFirstname[],string MaleAddress[],int n)
{

    string hold;
    int  j, pass;
    bool switched = true;

    for (pass = 0; pass < n-1 && switched == true; pass++)
    {
        //     outer loop controls the number of passes
        switched = false;   	              // initially no interchanges
        // have been made on this pass
        for (j = 0; j < n-pass-1; j++)
            //    inner loop governs each individual pass
            if ( MaleLastname[j] > MaleLastname[j+1])
            {
                //           elements out of order
                //        an interchange is necessary
                switched = true;
                hold = MaleLastname[j];
                MaleLastname[j] = MaleLastname[j+1];
                MaleLastname[j+1] = hold;

                hold=MaleFirstname[j];
                MaleFirstname[j]=MaleFirstname[j+1];
                MaleFirstname[j+1]=hold;

                hold=MaleAddress[j];
                MaleAddress[j]=MaleAddress[j+1];
                MaleAddress[j+1]=hold;


            }  // end of if
    }


    for ( j = 0; j < n; j++)
       cout<<MaleLastname[j]<<"    "<<MaleFirstname[j]<<"       "<<  MaleAddress[j]<< endl;

    }// end of function



int match(string MaleLastname[],string MaleAddress[],string FemaleLastname,string FemaleAddress, int countMale)
{

    for(int i=0; i<countMale; i++)
    {

        if((MaleAddress[i]==FemaleAddress)  &&  (MaleLastname[i]==FemaleLastname))
            return i;
    }

    return -1;
}

/*int linearSearch(int data[], int length, int val) {
03

04
   for (int i = 0; i <= length; i++) {
05
       if (val == data[countMale]) {
06
          return i;
07
       }//end if
08
   }//end for
09
   return -1;   //Value was not in the list
10
}//end linearSearch Function
*/

