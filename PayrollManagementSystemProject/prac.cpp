#include<iostream> //CIN COUT
#include<conio.h> //input output for console

#include<cstring> //string related funtions

#include<windows.h> //sleep 

using namespace std;
int main(){
int checkId,no_of_leave=2;
int choices,grosssal=8000;
			float perdaysal,newgrosssal;
            cout<<"\n\nEnter the month in number: ";
            switch (choices) {
                    case 1: 
                    case 3: 
                    case 5: case 7: case 8: case 10: case 12:
                    perdaysal = grosssal / 31.0;
                    newgrosssal = grosssal-perdaysal* no_of_leave;
                    break;
                    case 4: case 6: case 9: case 11: 
                    perdaysal = grosssal / 30.0 ;
                    newgrosssal = grosssal-perdaysal* no_of_leave;
                    break;
                    case 2: 
                    perdaysal = grosssal / 28.0 ;
                    newgrosssal = grosssal-perdaysal* no_of_leave;
                    break;
                    default:
                        cout<<"\n Sorry..!! I don't understand that..!! \n";
                        break;
                    }
                    cout<<perdaysal;
                    cout<<newgrosssal;

}


 // if (month==3)
                    //{
                    // perdaysal = grosssal / 31 ;
                    // newgrosssal = grosssal-perdaysal* no_of_leave;
                    // }

                    // if (month==5)
                    // {
                    // perdaysal = grosssal / 31 ;
                    // newgrosssal = grosssal-perdaysal* no_of_leave;
                    // }

                    // if (month==7)
                    // {
                    // perdaysal = grosssal / 31 ;
                    // newgrosssal = grosssal-perdaysal* no_of_leave;
                    // }

                    // if (month==8)
                    // {
                    // perdaysal = grosssal / 31 ;
                    // newgrosssal = grosssal-perdaysal* no_of_leave;
                    // }

                    // if (month==10)
                    // {
                    // perdaysal = grosssal / 31 ;
                    // newgrosssal = grosssal-perdaysal* no_of_leave;
                    // }

                    // if (month==12)
                    // {
                    // perdaysal = grosssal / 31 ;
                    // newgrosssal = grosssal-perdaysal* no_of_leave;
                    // }