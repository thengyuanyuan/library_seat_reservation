#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;

const double PublicSeat=0;
const double SingleSeat=5;
const double GroupSeat=8;
const double Room=15;

int main()
{
    int typeOfSeat;
    string seatname;
    int quantity;
    double price;
    string response;
    int startTime, endTime;
    double duration;
    int d,m,y;
    string name;
    string phonenumber;
    string studentid;
    string schoolname;
    double payable;
    double paid, paid2, change;
    int payment_method;
    int pin;
    int choose1,choose2;
    time_t now = time(0); //get current date and time

    tm *ltm = localtime(&now);

//menu/first page
MENU:
{
    cout<<"==========================================="<<endl;
    cout<<"            Welcome to Pi Library"<<endl;
    cout<<"==========================================="<<endl<<endl;
    cout<<"  Working Hour: 0900-2100"<<endl<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"  Type of seat             Price per hour"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"   Public seat                   Free"<<endl;
    cout<<"   Single seat                 RM 5.00"<<endl;
    cout<<"    Group seat                 RM 8.00"<<endl;
    cout<<"      Room                     RM15.00"<<endl;
    cout<<"-------------------------------------------"<<endl<<endl;
    cout<<"******** 20% discount for student ********"<<endl<<endl;
    system("pause");
    system("cls");
    choose1=0,choose2=0;
}
//choose seats
SEAT:
{
    cout<<"Enter '-1' to quit reservation"<<endl<<endl;
    cout<<"==========================================="<<endl;
    cout<<"                CHOOSE SEAT"<<endl;
    cout<<"==========================================="<<endl<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"  Type of seat             Price per hour"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"  1. Public seat                Free"<<endl;
    cout<<"  2. Single seat              RM 5.00"<<endl;
    cout<<"  3. Group seat               RM 8.00"<<endl;
    cout<<"  4. Room                     RM15.00"<<endl;
    cout<<"-------------------------------------------"<<endl<<endl;

    do{
        cout<<"Enter number to choose your seat."<<endl;
        cin>>typeOfSeat;
        if(typeOfSeat==-1)
        {
            system("cls");
            cout<<"You have quit from the reservation"<<endl;
            cout<<"Thank You"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }
        else if(typeOfSeat!=1&&typeOfSeat!=2&&typeOfSeat!=3&&typeOfSeat!=4)
        {
            cout<<"*Please choose a valid number (1, 2, 3 or 4)"<<endl;
        }
    }while(typeOfSeat!=1&&typeOfSeat!=2&&typeOfSeat!=3&&typeOfSeat!=4&&typeOfSeat!=-1);

    do{
    cout<<endl<<"How many seats would you like?"<<endl;
    cin>>quantity;

    if(quantity==-1)
    {
        system("cls");
        cout<<"You have quit from the reservation"<<endl;
        cout<<"Thank You"<<endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        system("cls");
        goto MENU;
    }
    if (quantity<=0)
    {
        cout<<"*Please choose a valid value"<<endl;
    }

    }while(quantity<=0);

//choose date
CHOOSE_DATE:

    cout<<endl<<"Choose date ( DD / MM / YYYY )"<<endl;
    cin >> d; // read the day
        if(d==-1)
        {
            system("cls");
            cout<<"You have quit from the reservation"<<endl;
            cout<<"Thank You"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }

        if(cin.get()!='/')
        {
            cout<<"*Please follow the format ( DD / MM / YYYY )"<<endl;
            goto CHOOSE_DATE;
        }

    cin >> m; // read the month
        if(cin.get()!='/')
        {
            cout<<"*Please follow the format ( DD / MM / YYYY )"<<endl;
            goto CHOOSE_DATE;
        }

    cin >> y; // read the year

    //invalid for passed date (extra);
        if((y==1900+ltm->tm_year)&&(m==1+ltm->tm_mon)&&(d<ltm->tm_mday))
        {
            cout<<"*Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }

        if((y==1900+ltm->tm_year)&&(m<1+ltm->tm_mon))
        {
            cout<<"*Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }
        if(y<1900+ltm->tm_year)
        {
            cout<<"*Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }

    //invalid for invalid date (extra)
        if(d<1)//day
        {
            cout<<"*Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }

        else if((m>12)||(m<1))//month 1-12
        {
            cout<<"*Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }
        else if ((y%4==0)&&(m==2)&&(d>29)) //February leap year
        {
            cout<<"*Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }
        else if ((y%4!=0)&&(m==2)&&(d>28)) //February common year
        {
            cout<<"*Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }
        else if ((m==1)&&(m==3)&&(m==5)&&(m==7)&&(m==8)&&(m==10)&&(m==12)&&(d>31)) //a solar month of 31 days
        {
            cout<<"*Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }
        else if ((m==4)&&(m==6)&&(m==9)&&(m==11)&&(d>30)) //a lunar month of 30 days
        {
            cout<<"*Please choose a valid date"<<endl;
            goto CHOOSE_DATE;
        }

//choose time
CHOOSE_TIME:
    do{
        cout<<endl<<"Select time start (24h): (HHMM)"<<endl;
        cin>>startTime;
        if(startTime==-1)
        {
            system("cls");
            cout<<"You have quit from the reservation"<<endl;
            cout<<"Thank You"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }
        else if((startTime<900) || (startTime>2000))
        {
            cout<<"*Please choose the time within our working hour(0900-2100)"<<endl<<endl;
        }
        else if ((startTime%100)>59) //max 59 minutes (extra)
        {
            cout<<"*Please choose a valid time"<<endl;
        }
    }while((startTime<900) || (startTime>2000)||(startTime%100>59));

    //invalid for passed time (extra)
    if((y==1900+ltm->tm_year)&&(m==1+ltm->tm_mon)&&(d==ltm->tm_mday)&&(startTime/100<ltm->tm_hour))//invalid for passed hour
        {
            cout<<"*Please choose a valid time"<<endl;
            goto CHOOSE_TIME;
        }
    else if((y==1900+ltm->tm_year)&&(m==1+ltm->tm_mon)&&(d==ltm->tm_mday)&&(startTime/100==ltm->tm_hour)&&(startTime%100<=ltm->tm_min))//invalid for passed minutes
        {
            cout<<"*Please choose a valid time"<<endl;
            goto CHOOSE_TIME;
        }

    do{
        cout<<endl<<"Select time end (24h): (HHMM)"<<endl;

cin>>endTime;

        if(endTime==-1)
        {
            system("cls");
            cout<<"You have quit from the reservation"<<endl;
            cout<<"Thank You"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }
        if(endTime<=startTime)
        {
            cout<<"*Please choose the time after your starting time"<<endl<<endl;
        }
        else if(endTime>2100)
        {
            cout<<"*Please choose the time within our working hour(0900-2100)"<<endl<<endl;
        }
        else if(endTime%100>59) //max 59 minutes (extra)
        {
            cout<<"*Please choose a valid time"<<endl;
        }
        else if((endTime-startTime)%100!=0)
        {
            cout<<"*The time slot available is measured in hour"<<endl;
        }
    }while((endTime<=startTime)||(endTime>2100)||((endTime%100)>59)||(endTime-startTime)%100!=0);

    duration=((endTime-startTime)/100);

}
    cout<<endl;
    system("pause");
    system("CLS");

//calculation for price
CALCULATE_PRICE:
{
    cout<<"Enter '-1' to quit reservation"<<endl<<endl;
    cout<<"==========================================="<<endl;
    cout<<"              Booking Details"<<endl;
    cout<<"==========================================="<<endl<<endl;

    if(typeOfSeat==1)
    {
        price=PublicSeat*quantity*duration;
        seatname="Public Seat";
    }
    else if(typeOfSeat==2)
    {
        price=SingleSeat*quantity*duration;
        seatname="Single Seat";
    }
    else if(typeOfSeat==3)
    {
        price=GroupSeat*quantity*duration;
        seatname="Group Seat";
    }
    else
    {
        price=Room*quantity*duration;
        seatname="Room";
    }

    cout<<fixed;
    cout<<" Type Of Seat : "<<seatname<<endl;
    cout<<" Quantity     : "<<quantity<<endl;
    if(startTime<=900)
        cout<<" Time         : 0"<<noshowpoint<<setprecision(0)<<startTime<<" - "<<endTime<<endl;
    else
        cout<<" Time         : "<<noshowpoint<<setprecision(0)<<startTime<<" - "<<endTime<<endl;

    if(duration>1)
        cout<<" Duration     : "<<duration<<" hours"<<endl;
    else
        cout<<" Duration     : "<<duration<<" hour"<<endl;

    cout<<" Date         : "<<d<<"/"<<m<<"/"<<y<<endl;
    cout<<" Price        : RM "<<setprecision(2)<<price<<endl<<endl;
}
    cout<<"Options"<<endl;
    cout<<"1. Make change on current page"<<endl;
    cout<<"2. Proceed to next page"<<endl;
    if(choose2==1)
    {
        cout<<"3. Proceed to PAYMENT"<<endl;
    }
    do{
    cout<<endl<<"Enter the number: ";
    cin>>choose1;

    if(choose1==-1)
    {
        system("cls");
        cout<<"You have quit from the reservation"<<endl;
        cout<<"Thank You"<<endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        system("cls");
        goto MENU;
    }
    else if(choose2==1&&choose1==3)
    {
        this_thread::sleep_for(chrono::milliseconds(5000));
        goto PAYMENT;
    }
    else if (choose2==1&&choose1==2)
    {
        system("cls");
        goto PERSONAL_INFORMATION_OUTPUT;
    }
    else if (choose1==1)
    {
        system("cls");
        goto SEAT;
    }
    else if (choose2==0&&choose1==2)
    {
        cout<<endl;
        system("cls");
    }
    if((choose2==0&&choose1!=1&&choose1!=2&&choose1!=-1)||(choose2==1&&choose1!=1&&choose1!=2&&choose1!=3&&choose1!=-1))
    {
        cout<<"*Please choose a valid option"<<endl;
    }
    }while ((choose2==0&&choose1!=1&&choose1!=2&&choose1!=-1)||(choose2==1&&choose1!=1&&choose1!=2&&choose1!=3&&choose1!=-1));

//personal information
PERSONAL_INFORMATION:
{
    cout<<"Enter '-1' to quit reservation"<<endl<<endl;
    cout<<"==========================================="<<endl;
    cout<<"            Personal Information"<<endl;
    cout<<"==========================================="<<endl;

    cout<<"Enter your name:"<<endl;
    cin.ignore();
    getline(cin,name);
    if(name=="-1")
        {
            system("cls");
            cout<<"You have quit from the reservation"<<endl;
            cout<<"Thank You"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }

    cout<<endl<<"Enter your phone number: "<<endl;
    cin>>phonenumber;
    if(phonenumber=="-1")
        {
            system("cls");
            cout<<"You have quit from the reservation"<<endl;
            cout<<"Thank You"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }

ask_student:
    cout<<endl<<"Are you a student? (y/n)"<<endl;
    cin.ignore();
    cin>>response;
    if(response=="-1")
        {
            system("cls");
            cout<<"You have quit from the reservation"<<endl;
            cout<<"Thank You"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }
    else if (response=="y"||response=="Y")
    {
        cout<<endl<<"Enter the name of your school: "<<endl;
        cin.ignore();
        getline(cin,schoolname);
        if(schoolname=="-1")
        {
            system("cls");
            cout<<"You have quit from the reservation"<<endl;
            cout<<"Thank You"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }

        cout<<endl<<"Enter your student ID: "<<endl;
        cin>>studentid;
        if(studentid=="-1")
        {
            system("cls");
            cout<<"You have quit from the reservation"<<endl;
            cout<<"Thank You"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }
        payable=price*0.8;
    }
    else if (response=="n"||response=="N")
    {
        payable=price;
    }
    else
    {
        cout<<"*Please enter a valid input"<<endl;
        goto ask_student;
    }
    cout<<endl;

}
    system("pause");
    system("CLS");

//output for personal information
PERSONAL_INFORMATION_OUTPUT:
{
    cout<<"Enter '-1' to quit reservation"<<endl<<endl;
    cout<<"=========================================="<<endl;
    cout<<"            Personal Information"<<endl;
    cout<<"=========================================="<<endl<<endl;
    cout<<" Name               : "<<name<<endl;
    cout<<" Phone number       : "<<phonenumber<<endl;
    if(response=="Y"||response=="y")
    {
    cout<<" School             : "<<schoolname<<endl;
    cout<<" Student ID         : "<<studentid<<endl;
    }
    cout<<endl;
}
    cout<<"Options"<<endl;
    cout<<"1. View previous page"<<endl;
    cout<<"2. Make change on current page"<<endl;
    cout<<"3. Proceed to PAYMENT"<<endl;
    do{
    cout<<endl<<"Enter the number: ";
    cin>>choose2;

    if(choose2==-1)
    {
        system("cls");
        cout<<"You have quit from the reservation"<<endl;
        cout<<"Thank You"<<endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        system("cls");
        goto PERSONAL_INFORMATION;
    }
    else if (choose2==1)
    {
        system("cls");
        goto CALCULATE_PRICE;
    }
    else if (choose2==2)
    {
        system("cls");
        goto PERSONAL_INFORMATION;
    }
    else if (choose2==3)
    {
        system("cls");
        goto PAYMENT;
    }
    else
    {
        cout<<"*Please choose a valid option"<<endl;
    }
    }while (choose2!=1&&choose2!=2&&choose2!=3&&choose2!=-1);
    system("pause");
    system("cls");

//payment
PAYMENT:
{
    cout<<"Enter '-1' to quit reservation"<<endl<<endl;
    cout<<"==========================================="<<endl;
    cout<<"                  Payment"<<endl;
    cout<<"==========================================="<<endl<<endl;

    cout<<" Price           : RM "<<showpoint<<setprecision(2)<<price<<endl;
    if(response=="y"||response=="Y")
        cout<<"  * Student Price   -20% *"<<endl;

    cout<<"-------------------------------------------"<<endl;
    cout<<" Total Payable   : RM "<<payable<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<endl;

    do{
        cout<<"Choose a payment method"<<endl;
        cout<<"1. Cash"<<endl;
        cout<<"2. VisaCard / MasterCard"<<endl;
        cin>>payment_method;
        cout<<endl;

        if (payment_method==-1)
        {
            system("cls");
            cout<<"Reservation has been canceled"<<endl;
            this_thread::sleep_for(chrono::milliseconds(5000));
            system("cls");
            goto MENU;
        }
        else if(payment_method==1)
        {
            cout<<"You have chosen Cash."<<endl<<endl;
            cout<<"Enter the amount you have paid "<<endl<<"RM ";
            cin>>paid;
            while(paid<payable)
            {
                cout<<"You still have RM "<<payable-paid<<" more to Pay"<<endl;
                cout<<"Enter the amount you have paid again"<<endl;
                cin>>paid2;
                paid=paid+paid2;
            }
            change=paid-payable;
            cout<<"Your payment is successful."<<endl;
            if(change>0)
            {
            cout<<"Your change is RM "<<change<<endl;
            }
        }
        else if (payment_method==2)
        {
            cout<<"You have chosen VisaCard / MasterCard"<<endl<<endl;
            cout<<"Please insert your MasterCard or VisaCard..."<<endl<<endl;

            system("pause");

            cout<<endl<<"Enter your pin number"<<endl;
            cin>>pin;
            paid=payable;
        }
        else
        {
            cout<<"*Please choose a valid option"<<endl;
        }
    }while(payment_method!=1&&payment_method!=2&&payment_method!=-1);
}
    cout<<endl<<"Your payment has successful"<<endl<<endl;
    system("pause");
    system("CLS");

//receipt booking confirmation
RECEIPT:
{
    cout<<"==========================================="<<endl;
    cout<<"            Booking Confirmation"<<endl;
    cout<<"==========================================="<<endl<<endl;

    cout<<" Type Of Seat         : "<<seatname;

    cout<<" x"<<quantity<<endl;

    if(startTime<=900)
        cout<<" Time               : 0"<<noshowpoint<<setprecision(0)<<startTime<<" - "<<endTime<<endl;
    else
        cout<<" Time               : "<<noshowpoint<<setprecision(0)<<startTime<<" - "<<endTime<<endl;

    if(duration>1)
        cout<<" Duration           : "<<duration<<" hours"<<endl;
    else
        cout<<" Duration           : "<<duration<<" hour"<<endl;

    cout<<" Date               : "<<d<<"/"<<m<<"/"<<y<<endl;;
    cout<<"-------------------------------------------"<<endl;
    cout<<" Price              : RM "<<showpoint<<setprecision(2)<<price<<endl;

    if(response=="y"||response=="Y")
        cout<<" * Student Price   -20% *"<<endl;

    cout<<"-------------------------------------------"<<endl;

    cout<<" Total payable      : RM "<<payable<<endl<<endl;
    cout<<" Paid amount        : RM "<<paid<<endl;
    cout<<" Change amount      : RM "<<change<<endl<<endl<<endl;

    cout<<" Name               : "<<name<<endl;
    cout<<" Phone No           : "<<phonenumber<<endl;
    if (response=="y"||response=="Y")
    {
    cout<<" School             : "<<schoolname<<endl;
    cout<<" Student ID         : "<<studentid<<endl<<endl<<endl;
    }

    cout<<"   Thank you for choosing Pi Library"<<endl;
    cout<<"         Please come again..."<<endl<<endl;
}
//get current date and time
DATE_TIME:
{
    if(ltm->tm_mday>=10)
        cout<<ltm->tm_mday<<"/";
    else
        cout<<"0"<<ltm->tm_mday<<"/";
    if( 1 + ltm->tm_mon>=10)
        cout<<1+ltm->tm_mon<<"/";
    else
        cout<<"0"<<1+ltm->tm_mon<<"/";
    cout<<1900 + ltm->tm_year;

    cout << setw(25);

    if(ltm->tm_hour>=10)
        cout << ltm->tm_hour << ":";
    else
        cout << "0"<<ltm->tm_hour << ":";

    if(ltm->tm_min>=10)
        cout << ltm->tm_min << ":";
    else
        cout <<"0"<< ltm->tm_min << ":";

    if(ltm->tm_sec>=10)
        cout << ltm->tm_sec << endl;
    else
        cout <<"0"<< ltm->tm_sec << endl;
}
    return 0;
}
