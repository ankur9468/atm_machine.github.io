#include <iostream>
#include <conio.h>
#include<fstream>
#include<iomanip>
#include <windows.h>
#include <cctype>
using namespace std;
class account
{
    int acno;
    char name[50];
    int deposit;
    char type;
public:

    void create_account();
    void show_account();
    void modify();
    void deposit_amt(int);
    void withdraw(int);
    void report();
    int retacno();
    int retdeposit();
    int rettype();
};
void account::create_account()
{
    cout<<"\nEnter the Account number :";
    cin>>acno;
    cout<<"\nEnter the Account Holder Name :";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nEnter the type of Account(c/s):";
    cin>>type;
    type=toupper(type);
    cout<<"\nEnter the initial amount(>=500 for saving and >=1000 for current :";
    cin>>deposit;
    cout<<"\n\n\nCreating account";
    for(int i=0; i<=4; i++)
    {
        cout<<".";
        Sleep(500);
    }
    cout<<endl;
}
void account::show_account()
{
    cout<<"\nAccount no. : "<<acno;
    cout<<"\nAccount Holder Name : "<<name;
    cout<<"\nType of Account : "<<type;
    cout<<"\nBalance Amount : "<<deposit;
}
void account::modify()
{
    cout<<"\n\t\tPrevious Account Detail"<<endl;
    cout<<"\nAccount no. : "<<acno;
    cout<<"\nAccount Holder Name : "<<name;
    cout<<"\nType of Account : "<<type;
    cout<<"\nBalance Amount : "<<deposit;
    cout<<"\n\n\t\tEnter new Detail"<<endl;
    cout<<"\nAccount no. : "<<acno;
    cout<<"\nEnter the Modify Account Holder Name :";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nEnter the Modify type of Account(c/s):";
    cin>>type;
    type=toupper(type);
    cout<<"\nEnter the Modify Balance Amount :";
    cin>>deposit;
    cout<<"\n\n\nModifying account";
    for(int i=0; i<=4; i++)
    {
        cout<<".";
        Sleep(500);
    }
    cout<<endl;
}
void account::deposit_amt(int amt)
{
    deposit+=amt;

}
void account::withdraw(int amt)
{
    deposit-=amt;

}
void account::report()
{
    cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;

}
int account::retacno()
{
    return acno;
}
int account::retdeposit()
{
    return deposit;
}
int account::rettype()
{
    return type;
}
//**************************************************************************************************************************************
//                                                        Function Declaration
//**************************************************************************************************************************************
void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int,int);
void intro();
void secured_acc();


int main()
{

start:
    system("cls");
    int op;
    cout<<"\n\n\t\t\t\tBank Management System";
    cout<<"\n\n\t\t1.Login";
    cout<<"\n\t\t2.exit";
    cout<<"\n\n\t\tYour choice :";
    cin>>op;
    if(op==2)
    {
        exit(0);
    }
    if(op==1)
    {
        system("cls");
        cout<<"\n\n\t\t\t\tBank Management System\n\n";
        string user,passw,check_u,check_p;
        cout<<"\n\t\tEnter the username :";
        cin>>user;
        cout<<"\n\t\tEnter the password :";
        cin>>passw;
        ifstream thefile("security.txt");
        while(thefile>>check_u>>check_p)
        {
            if(check_u==user && check_p==passw)
            {
                goto pin;
            }
        }
        system("cls");
        cout<<"\n\nYou have Entered Invalid Detail Please Retry!!";
        getch();
        goto start;

    }
    char ch;
    while(1)
    {
pin:
        system("cls");
        cout<<"\n\n\t\t\tMain Menu\n\n";
        cout<<"                ***************************************************";
        cout<<"\n\t\t1. New Account";
        cout<<"\n\t\t2. Deposit Amount";
        cout<<"\n\t\t3. Withdraw Amount";
        cout<<"\n\t\t4. Balance inquiry";
        cout<<"\n\t\t5. All Account Holder List";
        cout<<"\n\t\t6. Close An Account";
        cout<<"\n\t\t7. Modify Account";
        cout<<"\n\t\t8. Logout";
        cout<<"\n\t\t9. Exit";
        cout<<"\n\t\tYour choice : ";
        cin>>ch;
        system("cls");
        switch(ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            int num;
            cout<<"\n\n\tEnter the Account No. ";
            cin>>num;
            deposit_withdraw(num,1);
            break;
        case '3':
            int num1;
            cout<<"\n\n\tEnter the Account No. ";
            cin>>num1;
            deposit_withdraw(num1,2);
            break;
        case '4':
            int num2;
            cout<<"\n\n\tEnter the Account No. ";
            cin>>num2;
            display_sp(num2);
            break;
        case '5':
            display_all();
            break;
        case '6':
            int num3;
            cout<<"\n\n\tEnter the Account No. ";
            cin>>num3;
            delete_account(num3);
            break;
        case '7':
            int num4;
            cout<<"\n\n\tEnter the Account No. ";
            cin>>num4;
            modify_account(num4);
            break;
        case '8':
            cout<<"\n\n\tThanks For using Atm machine";
            goto start;
        case '9':
            cout<<"\n\n\tThanks For using Atm machine";
            exit(0);
        default:
            cout<<"\t\tYou have Enter wrong choice please retry"<<endl;
            getch();
            goto pin;

        }
        getch();

    }
    return 0;
}

void write_account()
{
    account ac;
    ofstream outfile;
    outfile.open("accounts.txt",ios::binary|ios::app);
    ac.create_account();
    outfile.write(reinterpret_cast<char *>(&ac),sizeof(account));
    outfile.close();
}
void display_sp(int n)
{
    account ac;
    bool flag=false;
    ifstream infile;
    infile.open("accounts.txt",ios::binary);
    if(!infile)
    {
        cout<<"file cannot be open !! press any key...";
        return ;
    }
    cout<<"\nBalance Details\n";
    while(infile.read(reinterpret_cast<char *>(&ac),sizeof(account)))
    {
        if(ac.retacno()==n)
        {
            ac.show_account();
            flag=true;
        }
    }
    infile.close();
    if(flag==false)
    {
        cout<<"\n\nAccount doesn't exist";
    }


}
void modify_account(int n)
{
    account ac;
    bool flag=false;
    fstream infile;
    infile.open("accounts.txt",ios::binary |ios::in|ios::out);
    if(!infile)
    {
        cout<<"file cannot be open !! press any key...";
        return ;
    }
    while(!infile.eof()&& flag ==false)
    {
        infile.read(reinterpret_cast<char*>(&ac),sizeof(account));
        if(ac.retacno()==n)
        {
            //ac.show_account();
            //cout<<"\n\nEnter the new account detail"<<endl;
            ac.modify();
            int pos=(-1)*static_cast<int>(sizeof(account));
            infile.seekp(pos,ios::cur);
            infile.write(reinterpret_cast<char*>(&ac),sizeof(account));
            cout<<"\n\nRecord Updated Succesfully";
            flag=true;
        }

    }
    infile.close();
    if(flag==false)
    {
        cout<<"\n\nRecord not found";
    }
}
void delete_account(int n)
{
    account ac;
    ifstream infile;
    ofstream outfile;
    infile.open("accounts.txt",ios::binary);
    if(!infile)
    {
        cout<<"file cannot be open !! press any key...";
        return ;
    }
    outfile.open("Temp.txt",ios::binary);
    infile.seekg(0,ios::beg);
    while(infile.read(reinterpret_cast<char*>(&ac),sizeof(account)))
    {

        if(ac.retacno()!=n)
        {
            outfile.write(reinterpret_cast<char*>(&ac),sizeof(account));
        }

    }
    infile.close();
    outfile.close();
    remove("accounts.txt");
    rename("Temp.txt","accounts.txt");
    cout<<"\n\nRecord deleted";
}
void display_all()
{
    account ac;
    bool flag=false;
    ifstream infile;
    infile.open("accounts.txt",ios::binary);
    if(!infile)
    {
        cout<<"file cannot be open !! press any key...";
        return ;
    }
    cout<<"\n\n\t\tAccount Holder Lists\n\n";
    cout<<"--------------------------------------------------------------\n";
    cout<<"A/c no.       Name          Type     Balance\n";
    cout<<"--------------------------------------------------------------\n";
    while(infile.read(reinterpret_cast<char*>(&ac),sizeof(account)))
    {

        ac.report();

    }
    infile.close();
}
void deposit_withdraw(int n,int option)
{
    account ac;
    int amt;
    bool flag=false;
    fstream infile;
    infile.open("accounts.txt",ios::binary|ios::in|ios::out);
    if(!infile)
    {
        cout<<"file cannot be open !! press any key...";
        return ;
    }
    while(!infile.eof()&& flag ==false)
    {
        infile.read(reinterpret_cast<char*>(&ac),sizeof(account));
        if(ac.retacno()==n)
        {
            ac.show_account();
            if(option ==1)
            {
                cout<<"\n\n\t To deposit Amount";
                cout<<"\n\nEnter amount to be deposit :";
                cin>>amt;
                ac.deposit_amt(amt);
            }
            if(option ==2)
            {
                cout<<"\n\n\t To withdraw Amount";
                cout<<"\n\nEnter amount to be withdraw :";
                cin>>amt;
                int bal=ac.retdeposit()-amt;
                if((bal <500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
                {
                    cout<<"Insufficience Balane";
                }
                else
                {
                    ac.withdraw(amt);
                }
            }
            int pos=(-1)*static_cast<int>(sizeof(account));
            infile.seekp(pos,ios::cur);
            infile.write(reinterpret_cast<char*> (&ac),sizeof(account));
            cout<<"\n\nRecord Updated Succesfully";
            flag=true;
        }

    }
    infile.close();
    if(flag==false)
    {
        cout<<"\n\nRecord not found";
    }

}

