#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
using namespace std;

class atm{
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:
    void setData(long int account_no_a,string name_a,int PIN_a, double balance_a,string mobile_no_a){
        account_no = account_no_a;  //assigning formal arguments to private member
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }
    long int getAccountNo(){
        return account_no;
    }
    string getName(){
        return name;
    }
    int getPIN(){
        return PIN;
    }
    double getBalance(){
        return balance;
    }
    string getMobileNo(){
        return mobile_no;
    }
    void setMobile(string mob_prev,string mob_new){
        if(mob_prev == mobile_no){
            mobile_no = mob_new;
            cout<<endl<<"Sucessfully updated mobile no.";
            getch();
        }
        else{
            cout<<endl<<"Incorrect!! old mobile no.";
            getch();
        }
    }
    void cashWithdraw(int amount_a){
        if(amount_a > 0 && amount_a < balance){
            balance -= amount_a;
            cout<<endl<<"Please collect your cash";
            cout<<endl<<"Avaiilable balance: "<<balance;
            getch();
            }
        else{
                cout<<endl<<"Invalid input or Insufficient balance";
                getch();
            }
        }
};

int main(){
    int choice =0, enterPIN;
    long int enterAccountNo;
    system("clear");
    atm user1;
    user1.setData(1234567,"Ram",1111,45000.90,"9123415328");
        
    do{
        system("clear");
        cout<<endl<<"______Welcome to ATM_____"<<endl;
        cout<<endl<<"Enter your account number: ";
        cin>>enterAccountNo;

        cout<<endl<<"Enter PIN: ";
        cin>> enterPIN;

        if((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN())){
            do{
                int amount = 0;
				string oldMobileNo, newMobileNo;

				system("clear");
				cout << endl << "**** Welcome to ATM *****" << endl;
				cout << endl << "Select Options ";
				cout << endl << "1. Check Balance";
				cout << endl << "2. Cash withdraw";
			    cout << endl << "3. Show User Details";
				cout << endl << "4. Update Mobile no.";
				cout << endl << "5. Exit" << endl;
				cin >> choice;

                    switch (choice)						
				    {
				    case 1:								
					   cout << endl << "Your Bank balance is :" << user1.getBalance(); 
					   getch();
					   break;


				    case 2:									
					   cout << endl << "Enter the amount :";		
					   cin >> amount;
					   user1.cashWithdraw(amount);			
					   break;


				    case 3:										
					   cout << endl << "*** User Details are :- ";
					   cout << endl << "-> Account no" << user1.getAccountNo();
					   cout << endl << "-> Name      " << user1.getName();
					   cout << endl << "-> Balance   " << user1.getBalance();
					   cout << endl << "-> Mobile No." << user1.getMobileNo();
					   getch();
					   break;


				    case 4:								   
					   cout << endl << "Enter Old Mobile No. ";
					   cin >> oldMobileNo;							

					   cout << endl << "Enter New Mobile No. ";
					   cin >> newMobileNo;							

					   user1.setMobile(oldMobileNo, newMobileNo);	
					   break;

				    case 5:
					   exit(0);						

				    default:							
					   cout << endl << "Enter Valid Data !!!";
				    } 
                }while(1);
		    }
            else{
			   cout << endl << "User Details are Invalid !!! ";
			   getch();
		    }
	    } while (1);						

	return 0;
}
	