#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int ans;


void withdraw(){
   system("cls");
 float amount;

   cout<<"\n ______Enter amount you want to withdraw______"<<endl;
cin>>amount;


if (amount<=0)
{
    cout<<"amount cant be null or none";
}

else if (amount > 0 )
    {
     cout <<"confirmed you have withdrawn successfully ksh. " <<amount;
}

}

void deposit(){
    system("cls");
float deposit = 0;
 cout <<"enter amount you wish to deposit. ";
 cin>> deposit;
if (deposit<=0)
{
 cout<<"deposit cant be null or none";
}

else{
 cout <<"confirmed you have deposited successfully ksh. " <<deposit;
}

}
void checkBalance(){

}

//registering the user to the db
    void registerAcc()
    {
        string userName;
        fstream userFile;
        userFile.open("database.txt",ios::app);
        if(userFile.is_open()){
        cout<<"\n Please enter your prefered username: ";
        cin>>userName;
        userFile<<endl;
        userFile<<userName;
        userFile.close();
    }
    }

void log_in(){
system("cls");
int nameNum ;
string userName;
string userCheck;
cout <<" ....Welcome to comrades bank ltd. .... \n";

cout<< "Enter your user name to login: ";
cin>>userName;

//checking for user name in the db
fstream verifyUser;
verifyUser.open("database.txt");
if(verifyUser.is_open()){

    while(verifyUser.good()){
        getline(verifyUser,userCheck);
            if(userCheck==userName){
            cout<<"\nAccount verified!";
            sleep(3);
            goto w;
        }

    }
        if(userCheck!=userName)
            {
        cout<<"\nSeems yuo are not registerd, please consider registering\n";
        goto g;
    }

}


cin >>nameNum;
    g:
        registerAcc();
    w:
        system("cls");
     cout<<"\nWelcome "<<userName;
     cout<<"\nWhat would you like to do today"<<endl;
     cout<<"\n1: withdraw"<<"\n2: Deposit"<<"\n3: check balance"<<endl;
     cin>>ans;
     switch(ans){
 case 1:
    withdraw();
    break;
 case 2:
    deposit();
    break;
 case 3:
    checkBalance();
    break;
     }
}



int main()
{
    log_in();
    return 0;
}
