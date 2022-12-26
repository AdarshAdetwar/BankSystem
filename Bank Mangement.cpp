#include<iostream>
using namespace std;
class account
/*I was trying to add a database through SQL in the project 
kept it simple and editable,
but now i'm Not able to Add it */
{
private:
    string name;
    int accno;
    string atype;
public:
    void  getAccountDetails()
    {
        cout<<"\nEnter Customer Name : ";
        cin>>name;
        cout<<"Enter Account Number  : ";
        cin>>accno;
        cout<<"Enter Account Type    : ";
        cin>>atype;
    }
    void displayDetails()
    {
        cout<<"\n\nCustomer Name : "<<name;
        cout<<"\nAccount Number  : "<<accno;
        cout<<"\nAccount Type    : "<<atype;
    }
};
class current_account : public account
{
private:
    float balance;
public:
    void c_display()
    {
        cout<<"\nBalance :"<<balance;
    }
    void c_deposit()
    {
        float deposit;
        cout<<"\nEnter amount to Deposit :  ";
        cin>>deposit;
        balance = balance + deposit;
    }
    void c_withdraw()
    {
        float withdraw;
        cout<<"\n\nBalance : "<<balance;
        cout<<"\nEnter amount to be withdraw :";
        cin>>withdraw;
        if(balance > 1000)
        {
            balance=balance-withdraw;
            cout<<"\nBalance Amount After Withdraw: "<<balance;
        }
        else
        {
            cout<<"\n Insufficient Balance";
        }
 
    }
 
 
};
 
class saving_account : public account
{
private:
    float sav_balance;
public:
    void s_display()
    {
        cout<<"\nBalance :  "<<sav_balance;
    }
    void s_deposit()
    {
        float deposit,interest;
        cout<<"\nEnter amount to Deposit :  ";
        cin>>deposit;
        sav_balance = sav_balance + deposit;
        interest=(sav_balance*2)/100;
        sav_balance=sav_balance+interest;
    }
    void s_withdraw()
    {
        float withdraw;
        cout<<"\nBalance :- "<<sav_balance;
        cout<<"\nEnter amount to be withdraw : ";
        cin>>withdraw;
        if(sav_balance > 500)
        {
            sav_balance=sav_balance-withdraw;
            cout<<"\nBalance Amount After Withdraw: "<<sav_balance;
        }
        else
        {
            cout<<"\n Insufficient Balance";
        }
    }
};
 
 
 
int main()
{
    current_account c1;
    saving_account s1;
    char type;
    
    cout<<"\t\t\t-----------------------------------------------\t\t\t\n";
    cout<<"\t\t\t------------Bank Management System-------------\t\t\t\n";
    cout<<"\t\t\t-----------------------------------------------\t\t\t\n";
    cout<<"\n\n\nFirst please enter the type of your Acc: Saving OR Current (c/s) \n";
    cin>>type;
    int choice;
    if(type=='s' || type=='S')
    {
        s1.getAccountDetails();
        while(1)
        {
            cout<<"\nChoose Your Choice\n";
            cout<<"1.Deposit\n";
            cout<<"2.Withdraw\n";
            cout<<"3.Display Balance\n";
            cout<<"4.Display with full Details\n";
            cout<<"5.Exit\n";
            cout<<"Enter Your choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1 :
                s1.s_deposit();
                break;
            case 2 :
                s1.s_withdraw();
                break;
            case 3 :
                s1.s_display();
                break;
            case 4 :
                s1.displayDetails();
                s1.s_display();
                break;
            case 5 :
                goto end;
            default:
                cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
    }
    else if(type=='c' || type=='C')
    {
        c1.getAccountDetails();
        while(1)
        {
            cout<<"\nChoose Your Choice\n";
            cout<<"1.Deposit\n";
            cout<<"2.Withdraw\n";
            cout<<"3.Display Balance\n";
            cout<<"4.Display with full Details\n";
            cout<<"5.Exit\n";
            cout<<"Enter Your choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1 :
                c1.c_deposit();
                break;
            case 2 :
                c1.c_withdraw();
                break;
            case 3 :
                c1.c_display();
                break;
            case 4 :
                c1.displayDetails();
                c1.c_display();
                break;
            case 5 :
                goto end;
            default:
                cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
    }
    else
    {
        cout<<"\nInvalid Account Selection";
    }
end:
    cout<<"\nThank You for Banking with us..";
    return 0;
}

