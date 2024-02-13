#include<iostream> //CIN COUT
#include<conio.h> //input output for console
#include<cstring> //string related funtions
#include<windows.h> //sleep function

using namespace std; //.h to include iostream.h 

class employee{
    
        
        char name[30];
        int id;
        char designation[10];
        int age;
        int ctc;
        int experience;
        float sal;
        float grosssal;
        float hra;
        float da;
        float ta;
        float pf;
    

        
        void waitForEnter(void){ //use void bcoz we dont pass any parameters in this function
            cout<<"\n\n\n Press the enter key to go back \n\n";
            cin.get(); //TO INPUT ONLY 1 CHARACTER
            cin.get(); //use to accessing character array
        }

        
	
	
        void listEmployees(void){ 
            system("cls"); //clrscr()
            FILE *file; 
            file= fopen("data.txt", "r");
            cout<<"\n\t      List of Employees is as follows\n";
           
            cout<<"\n NAME        |     ID     |     DESIGNATION\n";
        
            while(fscanf(file, "%s %d %s %d %d %d %f %f ", name, &id, designation, &age, &ctc, &experience, &sal, &grosssal)!= EOF)
                cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            fclose(file);
            waitForEnter();
        }
	
        void showDetails(void){ 
            system("cls");
            FILE *file;
            int checkId;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
                if(checkId==id){
                  
                    cout<<"\nName: "<<name;
                   
                    cout<<"\nId: "<<id;
                   
                    cout<<"\nDesignation: "<<designation;
                 
                    cout<<"\nAge: "<<age;
                   
                    cout<<"\nCTC: "<<ctc;
                 
                    cout<<"\nExperience: "<<experience;
                  
                    cout<<"\nBasic Salary: "<<sal;
                  
                    cout<<"\nGross Salary: "<<grosssal;
                  
                }
            fclose(file);
            waitForEnter();
        }
	
        void editExisting(void){ 
            system("cls");
            int checkId;
            cout<<"\nEnter employee id: ";
            cin>>checkId;
            char newDesignation[10];
          
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;
            int newCtc;
          
            cout<<"\nEnter new CTC: ";
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF){
                if(checkId==id)
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f\n", name, id, newDesignation, age, newCtc, experience, sal, grosssal );
                else
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, grosssal );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }
	// add employee
        void addNewEmployee(void){ 
        
        	system("cls");
            FILE *file;
            int newid;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
            {
            	newid=id+1;
			}
            fclose(file);
            
         
            cout<<"\n Enter First Name of the Employee: ";
            cin>>name;
          
            cout<<"\n Enter Designation of the Employee: ";
            cin>>designation;
           
            cout<<"\n Enter Age of Employee: ";
            cin>>age;
           
            cout<<"\n Enter Employee CTC: ";
            cin>>ctc;
           
            cout<<"\n Enter Employee Experience: ";
            cin>>experience;
            cout<<"\n Enter Employee Basic Salary: ";
            cin>>sal;
           
			hra = sal * (.10); //houserent
        	da  = sal * (.15); //Dearness Allowance inflation
        	ta  = sal * (.20); //travelling
        	pf  = sal * (.25); //provisionalfund
            grosssal = sal + hra + da + ta + pf;
		        	
		        	
            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %d %s %d %d %d %f %f \n", name, newid, designation, age, ctc, experience, sal, grosssal );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();
            waitForEnter();
        }
	//remove
        void deleteEmployeeDetails(void){ 
            system("cls");
            int checkId;
          
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;
            
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
                    if(checkId!=id)
                        fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, grosssal );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
                waitForEnter();
            }
            else
                deleteEmployeeDetails();
        }
//Add overtime
        void addOvertime(void)
        {  
        	
        	system("cls");
            FILE *file;
            int checkId,over;
			float newgrosssal;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            cout<<"\n\nEnter the overtime (number of hours) : ";
            cin>>over;
            
            file= fopen("data.txt", "r");

            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
                if(checkId==id){
		        	newgrosssal = grosssal + over*100;
                }
            fclose(file);
            
            cout<<"\n\nOvertime amount "<<over*100<<" added to the Gross Salary\n\n";

            FILE *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF){
                if(checkId==id)
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, newgrosssal );
                else
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, grosssal );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }
//Leave section


      void addleave(void){
        system("cls");
            FILE *file;
            int checkId,no_of_leave,month;
            int choices;
			float perdaysal,newgrosssal;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            cout<<"\n\nEnter no. of leaves : ";
            cin>>no_of_leave;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
                if(checkId==id){
                    cout<<"\n\nEnter month in Number : ";
                    cin>>month;

                if (month==1)
                    {
                        perdaysal = grosssal / 31 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month == 3)
                    {
                        
                        perdaysal = grosssal / 31 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month==5)
                    {
                        perdaysal = grosssal / 31 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month==7)
                    
                    {
                        perdaysal = grosssal / 31 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    
                    }
                    else if (month==8)

                    {
                        perdaysal = grosssal / 31 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month==10)
                    
                    {
                        perdaysal = grosssal / 31 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month==12)
                    
                    {
                        perdaysal = grosssal / 31 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month==4)
                    {
                        perdaysal = grosssal / 30 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month==6)
                    {
                        perdaysal = grosssal / 30 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month==9)
                    {
                        perdaysal = grosssal / 30 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month==11)
                    {
                        perdaysal = grosssal / 30 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

                    else if (month==2)
                    {
                        perdaysal = grosssal / 28 ;
                        newgrosssal = grosssal-perdaysal* no_of_leave;
                    }

		        	//perdaysal = grosssal / 30 ;
                    //newgrosssal = grosssal-perdaysal* no_of_leave;
                }
            
            fclose(file);
            
           cout<<"\n\nNo. of leaves "<< perdaysal <<" deducted from the Gross Salary\n\n";

            FILE *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF){
                if(checkId==id)
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, newgrosssal );
                else
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, grosssal );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
      }
    

        void generatePay(void){  //to generate pay slip
			system("cls");
            FILE *file;
            int checkId;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
                if(checkId==id){
                	
		            cout<<"\n\tPAYSLIP\n";
		          
		            cout<<"\nBasic salary\t:\t"<<sal;
		            cout<<"\nhra\t\t:\t"<<sal*(.10);
		            cout<<"\nda\t\t:\t"<<sal*(.15);
		            cout<<"\nta\t\t:\t"<<sal*(.20);
		            cout<<"\npf\t\t:\t"<<sal*(.25);
		            cout<<"\nGross Salary\t:\t"<<grosssal;
                }
            fclose(file);
            waitForEnter();
        }


    public:
        // Function to serve as end point
        void options(void){ //menu
        int login(); //login declaration
                login();//login screen
            while(true){
                system("cls");
                
                cout<<"\n\t\t\t>>>>>>>>>  EMPLOYEE PAYROLL MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\n";
          
                cout<<"\n\t\t\tENTER   1:   To View List of Employees";
              
                cout<<"\n\t\t\tENTER   2:   To View Employee Details";
                
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Employee Details";
               
                cout<<"\n\t\t\tENTER   4:   To Add New Employee Details";
               
                cout<<"\n\t\t\tENTER   5:   To Remove an Employee Details";

                cout<<"\n\t\t\tENTER   6:   To Add Overtime";
                
                cout<<"\n\t\t\tENTER   7:   To Generate PaySlip";

                cout<<"\n\t\t\tENTER   8:   To Add leave";
                
				cout<<"\n\t\t\tENTER   0:   To Exit     ";
                
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                // Taking the action input
               int choice;
               cin>>choice;
                //Calling relevant function as per choice
                switch (choice) {
                    case 0:
                    	system("CLS");
                        cout<<"\n\nEMPLOYEE MANAGEMENT SYSTEM \n\n Thank You ('.') \n\n ";
                        Sleep(10);
                        return;
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    case 6:
                        addOvertime();
                       break;
                    case 7:
                        generatePay();
                        break;
                    case 8:
                        addleave();
                        break;
                    default:
                        cout<<"\n Sorry..!! I don't understand that..!! \n";
                        break;
                }

            }
        }

};

int main(){
    // Call the options function
    employee e; //E object Dynamic
    e.options();
    return 0;
}

int login(){ //login procedure
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tEMPLOYEE PAYROLL MANAGEMENT SYSTEM";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);//pushes the element in the vector from the back
      cout << '*';
      ch = _getch();//screen hold
   }   
   if(pass == "password"){
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++) // Change 'a<?' to how many * you want
	{
		Sleep(200); //2000milliseconds means 2 second
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\tAccess Granted..!! \n\n\n";
      
      system("PAUSE");
      system("CLS");
   }
   else
   {
      cout << "\nAccess Aborted...!!\n";
      login(); 
   }
}

