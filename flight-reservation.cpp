#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <limits>
#include <iomanip>

using namespace std;

void loading();       // 574 to 606*
void welcome();       // 437 to 525*
void processing();    // 787 to 818
void exit();          // 526 to 573
void login_manual();  // 743 to 787
void login();         // 607 to 664
void registration();  // 665 to 684
void forgot();        // 685 to 742
int menu();           // 819 to 861
void user_manual();   // 862 to 889
void about();         // 890 to 905
void schedule();      // 127 to 358
void edit_schedule(); // 359 to 436
void reserve_seat();  // 1091 to 1335
void cancel_ticket(); // 1336 to 1409
void receipt();       // 1410 to 1456
void admin_panel();   // 1457 to 1580
void reserved_seat();
void schedule_show(); // 906 to 1090
void Records();       // 1581 to 1599
void about();         // 890 to 905

bool check_login_status = false;
const int a = 5;
const int b = 5;
const int n = a + b;

const int users = 10;
int count = 0;
int reserve_seats = 0;
string from;

bool schedule_set = false;

struct passenger
{

    string name, address, passport, cnic, phone_no, seat_type, flight_no, date_of_flight, destination;
    int payment, discounts, debit;
};

struct plan
{

    string date, from, to, timing, airline;
    int total_seats, price;
};

plan flights_dos[n];
plan flights_int[n];
passenger p[100];
int extra = 15000;
const int seat = 10;
int main()
{

    int exit_status = 0;
    welcome();
    system("cls");
    login_manual();
    processing();

    while (true)
    {
        int choice = menu();

        switch (choice)
        {

        case 1:
            loading();
            schedule();
            break;
        case 2:
            loading();
            reserved_seat();
            processing();
            break;
        case 3:
            loading();
            cancel_ticket();
            processing();
            break;

        case 4:
            loading();
            receipt();
            processing();
            break;
        case 5:
            loading();
            user_manual();
            break;
        case 6:
            loading();
            admin_panel();
            processing();
            break;
        case 7:
            loading();
            about();
            break;
        case 8:

            exit_status = 1;
            exit();
            break;
        default:
            cout << "\t\t\t\tError: Invalid Option!" << endl;
            break;
        }

        if (exit_status == 1)
        {
            break;
        }
    }

    return 0;
}
void schedule()
{
    system("cls");

    cout << "\t\t\t\t\t\t\t\t";

    if (!schedule_set)
    {
        int tra;
        while (true)
        {
            cout << "\t\t\t\t\t\tDo  You Want To Travel Domestic or Internationl?\n\t\t\t\t\t\t If Domestic press 1 If International  Press 2\n";
            cout << "\n\n\n\t\t\t\t\t\1. You Want To Travel Domestic \n\t\t\t\t\t2.You Want To Travel International  \n";

            cin >> tra;
            if (cin.fail() || (tra != 2 && tra != 1))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input! Please enter either 1 or 2." << endl;
            }
            else
            {
                break;
            }
        }

        if (tra == 1)
        {

            flights_dos[0].date = "08-07-2024";
            flights_dos[0].from = "LAHORE";
            flights_dos[0].to = "Karachi";
            flights_dos[0].timing = "9:30 AM";
            flights_dos[0].airline = "AIR SIAL";
            flights_dos[0].price = 20000;
            flights_dos[0].total_seats = 34;

            flights_dos[1].date = "12-07-2024";
            flights_dos[1].from = "Islamabad";
            flights_dos[1].to = "Sakardu";
            flights_dos[1].timing = "11:00 AM";
            flights_dos[1].airline = "PIA";
            flights_dos[1].price = 50000;
            flights_dos[1].total_seats = 100;

            flights_dos[2].date = "13-07-2024";
            flights_dos[2].from = "LAHORE";
            flights_dos[2].to = "Islamabad";
            flights_dos[2].timing = "09:30 AM";
            flights_dos[2].airline = "Sarene Airways";
            flights_dos[2].price = 18700;
            flights_dos[2].total_seats = 75;

            flights_dos[3].date = "13-07-2024";
            flights_dos[3].from = "Karachi";
            flights_dos[3].to = "Peshawer";
            flights_dos[3].timing = "01:30 PM";
            flights_dos[3].airline = "Air Blue";
            flights_dos[3].price = 23500;
            flights_dos[3].total_seats = 60;

            flights_dos[4].date = "14-07-2024";
            flights_dos[4].from = "LAHORE";
            flights_dos[4].to = "Quetta";
            flights_dos[4].timing = "05:30 PM";
            flights_dos[4].airline = "PIA";
            flights_dos[4].price = 17500;
            flights_dos[4].total_seats = 35;

            cout << "\t\t\t\t Today is:  " << __DATE__ << "  ";
            cout << "Current Time is: " << __TIME__ << endl
                 << endl;

            cout << "\t\t\t\t\t\tToday Available Domestic flights are\n";
            cout << "\t\t\t\t " << setw(10) << "Flight"
                 << setw(15) << "Date"
                 << setw(15) << "From"
                 << setw(15) << "To"
                 << setw(15) << "Timing"
                 << setw(15) << "Airline"
                 << setw(20) << "Remaining Seats"
                 << setw(10) << "Price" << endl;
            cout << "\t\t\t\t----------------------------------------------------------------------------------------" << endl;

            for (int i = 0; i < a; i++)
            {
                cout << "\t\t\t\t " << setw(10) << i + 1
                     << setw(15) << flights_dos[i].date
                     << setw(15) << flights_dos[i].from
                     << setw(15) << flights_dos[i].to
                     << setw(15) << flights_dos[i].timing
                     << setw(15) << flights_dos[i].airline
                     << setw(20) << flights_dos[i].total_seats - reserve_seats
                     << setw(10) << flights_dos[i].price << endl;
            }

            cout << endl
                 << endl;
            cout << "\t\t\t\t    |+|______________________________________________________________________________________|+| \n";
            cout << "\t\t\t\t    |+|**************************************************************************************|+| \n";
            cout << "                                        __________________________________________________________________________________   " << endl;

            system("pause");
            cout << endl;
            int res;
            while (true)
            {
                cout << "\t\t\t\t\t\tDo You Want To Reserve A seat?\n If Yes press 1 If No Press 2\n";
                cout << "\n\t\t\t\t\t\t1.You Want To Reserve A Seat \n\t\t\t\t\t\t2.You Don't Want To Reserve A Seat   \n";

                cin >> res;
                if (cin.fail() || (res != 2 && res != 1))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid Input! Please enter either 1 or 2." << endl;
                }
                else
                {
                    break;
                }
            }

            if (res == 1)
            {
                system("cls");
                reserved_seat();
            }
            else
            {
                system("cls");
            }
        }
        else if (tra == 2)
        {

            flights_int[0].date = "12-07-2024";
            flights_int[0].from = "Lahore";
            flights_int[0].to = "Istanbul";
            flights_int[0].timing = "5:30 AM";
            flights_int[0].airline = "Turkish Airways";
            flights_int[0].price = 105000;
            flights_int[0].total_seats = 60;

            flights_int[1].date = "12-07-2024";
            flights_int[1].from = "Islamabad";
            flights_int[1].to = "Toronto";
            flights_int[1].timing = "11:00 AM";
            flights_int[1].airline = "PIA";
            flights_int[1].price = 175000;
            flights_int[1].total_seats = 100;

            flights_int[2].date = "13-07-2024";
            flights_int[2].from = "Lahore";
            flights_int[2].to = "Jeddah";
            flights_int[2].timing = "09:30 AM";
            flights_int[2].airline = "Sarene Airways";
            flights_int[2].price = 87000;
            flights_int[2].total_seats = 75;

            flights_int[3].date = "14-07-2024";
            flights_int[3].from = "Karachi";
            flights_int[3].to = "Bali";
            flights_int[3].timing = "01:30 PM";
            flights_int[3].airline = "Qatar Airways";
            flights_int[3].price = 135000;
            flights_int[3].total_seats = 60;

            flights_int[4].date = "14-07-2024";
            flights_int[4].from = "LAHORE";
            flights_int[4].to = "Dubai";
            flights_int[4].timing = "05:30 PM";
            flights_int[4].airline = "Fly Jinaah";
            flights_int[4].price = 100000;
            flights_int[4].total_seats = 95;

            cout << "\t\t\t\t Today is:  " << __DATE__ << "  ";
            cout << "Current Time is: " << __TIME__ << endl
                 << endl;

            cout << "\t\t\t\t\t\tToday Available International flights are\n";
            cout << "\t\t\t\t " << setw(10) << "Flight"
                 << setw(15) << "Date"
                 << setw(15) << "From"
                 << setw(15) << "To"
                 << setw(15) << "Timing"
                 << setw(15) << "Airline"
                 << setw(20) << "Remaining Seats"
                 << setw(10) << "Price" << endl;
            cout << "\t\t\t\t----------------------------------------------------------------------------------------" << endl;

            for (int i = 0; i < b; i++)
            {
                cout << "\t\t\t\t " << setw(10) << i + 1
                     << setw(15) << flights_int[i].date
                     << setw(15) << flights_int[i].from
                     << setw(15) << flights_int[i].to
                     << setw(15) << flights_int[i].timing
                     << setw(15) << flights_int[i].airline
                     << setw(20) << flights_int[i].total_seats - reserve_seats
                     << setw(10) << flights_int[i].price << endl;
            }

            cout << endl
                 << endl;
            cout << "\t\t\t\t    |+|______________________________________________________________________________________|+| \n";
            cout << "\t\t\t\t    |+|**************************************************************************************|+| \n";
            cout << "                                        __________________________________________________________________________________   " << endl;

            system("pause");
            cout << endl;
            int rest;
            while (true)
            {
                cout << "\t\t\t\t\t\tDo You Want To Reserve A seat?\n If Yes press 1 If No Press 2\n";
                cout << "\n\t\t\t\t\t\t1.You Want To Reserve A Seat \n\t\t\t\t\t\t2.You Don't Want To Reserve A Seat   \n";

                cin >> rest;
                if (cin.fail() || (rest != 2 && rest != 1))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid Input! Please enter either 1 or 2." << endl;
                }
                else
                {
                    break;
                }
            }

            if (rest == 1)
            {
                system("cls");
                reserved_seat();
            }
            else
            {
                system("puase");
            }
        }
    }
}
void edit_flights()
{
    int edit_dos;
    while (true)
    {
        cout << "\t\t\t\t\t\tYou Want To Edit Flights Scheudule ?\n";
        cout << "\n\n\n\t\t\t\t\t\1.Press 1 If Edit Domestic Flight Schedule \n\t\t\t\t\t2.Press 2 If Edit International Flight Schedule Press  \n";

        cin >> edit_dos;
        if (cin.fail() || (edit_dos != 2 && edit_dos != 1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter either 1 or 2." << endl;
        }
        else
        {
            break;
        }
    }

    if (edit_dos == 1)
    {
        for (int i = 0; i < a; i++)
        {
            cin.ignore();
            cout << "PLZ Enter THE  Date (date/month/year): ";
            getline(cin, flights_dos[i].date);

            cout << "PLZ Enter THE  Airline (PIA#xyz): ";
            getline(cin, flights_dos[i].airline);

            cout << "PLZ Enter THE  Departure City: ";
            getline(cin, flights_dos[i].from);

            cout << "PLZ Enter THE Destination City (Dubai, UK): ";
            getline(cin, flights_dos[i].to);

            cout << "PLZ Enter THE Timing OF YOUR Flight  (hour:minutes 03:45 am/pm): ";
            getline(cin, flights_dos[i].timing);

            cout << "PLZ Enter THE  Number of Seats of this Flight: ";
            cin >> flights_dos[i].total_seats;

            cout << "PLZ Enter THE  Ticket Price of this Flight: ";
            cin >> flights_dos[i].price;

            cout << "\n\n THANKS FOR ENTERING THE SCHEDULE";
        }
        schedule_set = true;
    }
    else
    {
        for (int i = 0; i < b; i++)
        {
            cin.ignore();
            cout << "PLZ Enter THE  Date (date/month/year): ";
            getline(cin, flights_int[i].date);

            cout << "PLZ Enter THE  Airline (PIA#xyz): ";
            getline(cin, flights_int[i].airline);

            cout << "PLZ Enter THE  Departure City: ";
            getline(cin, flights_int[i].from);

            cout << "PLZ Enter THE Destination City (Dubai, UK): ";
            getline(cin, flights_int[i].to);

            cout << "PLZ Enter THE Timing OF YOUR Flight  (hour:minutes 03:45 am/pm): ";
            getline(cin, flights_int[i].timing);

            cout << "PLZ Enter THE  Number of Seats of this Flight: ";
            cin >> flights_int[i].total_seats;

            cout << "PLZ Enter THE  Ticket Price of this Flight: ";
            cin >> flights_int[i].price;

            cout << "\n\n THANKS FOR ENTERING THE SCHEDULE";
        }
        schedule_set = true;
    }
}
void welcome()
{
    system("cls");
    system("color 3f");
    cin.ignore();
    cout << "\n\n\n\n\n\n\n\n"
         << setw(120) << "*************************************************************************************************\n"
         << setw(120) << "^^|+|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                       WELCOME  TO                                     |+|^^\n"
         << setw(120) << "^^|+|                                          (-_-)                                        |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|+|^^\n"
         << setw(120) << "\t\t      *************************************************************************************************\n\n\n\n\t\t\t\t\t";

    Sleep(1000);

    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n"
         << setw(120) << "*************************************************************************************************\n"
         << setw(120) << "^^|+|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                       WELCOME  TO                                     |+|^^\n"
         << setw(120) << "^^|+|                                          (-_-)                                        |+|^^\n"
         << setw(120) << "^^|+|                                 AIRLINE Ticketing SYSTEM                              |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|+|^^\n"
         << setw(120) << "\t\t      *************************************************************************************************\n\n\n\n\t\t\t\t\t";

    Sleep(1000);

    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n"
         << setw(120) << "*************************************************************************************************\n"
         << setw(120) << "^^|+|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                       WELCOME  TO                                     |+|^^\n"
         << setw(120) << "^^|+|                                          (-_-)                                        |+|^^\n"
         << setw(120) << "^^|+|                                 AIRLINE Ticketing SYSTEM                              |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|                                      Developed By:                                    |+|^^\n"
         << setw(120) << "^^|+|        umar ahad uddin ahmed usmani             and             muhammad qasim        |+|^^\n"
         << setw(120) << "^^|+|            sap 60199                                               sap 59857          |+|^^\n"
         << setw(120) << "^^|+|                                                                                       |+|^^\n"
         << setw(120) << "^^|+|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|+|^^\n"
         << setw(120) << "\t\t      *************************************************************************************************  \n\n\n\n\t\t\t\t\t";

    system("pause");
    system("cls");
}
void login_manual()
{
    int c;
    cout << "\n\n\n\n\t\t\t\t\t\t *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n";
    cout << "\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~welcome to online air ticketing system~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    cout << "\t\t\t\t\t\t____________________________******______login page_______******_____________________________\n\n";
    cout << "\t\t\t\t\t\t\t\t  |*~*| PRESS 1 to LOGIN                       |*~*|\n";
    cout << "\t\t\t\t\t\t\t\t  |*~*| PRESS 2 to REGISTER                    |*~*|\n";
    cout << "\t\t\t\t\t\t\t\t  |*~*|PRESS 3 to IF YOU FORGOT THE PASSWORD   |*~*|\n";

    cout << "\n\t\t\t\t\t\t Please enter your choice :";
    cin >> c;
    cout << endl;

    cin.clear();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\t\t\t Invalid input. Please enter a numeric choice between 1 and 3: ";

    cout << endl;

    switch (c)
    {
    case 1:
        loading();
        login();
        break;
    case 2:
        loading();
        registration();
        processing();
        break;
    case 3:
        loading();
        forgot();
        processing();
        break;

    default:
        system("cls");
        system("color 3f");
        cout << "\n\n\n\t\t\t\t\t\t Please select from the options given above \n"
             << endl;
        system("pause");
        login_manual();
        break;
    }
}
void loading()
{
    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ****************************~~Loading~~**************************\n"
         << endl;
    cout << "\t\t\t\t\t\t Loading |||||||                                                 | 15% ....";
    Sleep(500);
    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ****************************~~Loading~~**************************\n"
         << endl;
    cout << "\t\t\t\t\t\t Loading |||||||||||||||||||                                     | 47% ....";
    Sleep(630);
    system("color 3f");
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ****************************~~Loading~~**************************\n"
         << endl;
    cout << "\t\t\t\t\t\t Loading |||||||||||||||||||||||||||||||||                       | 65% ....";
    Sleep(570);
    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ****************************~~Loading~~**************************\n"
         << endl;
    cout << "\t\t\t\t\t\t Loading ||||||||||||||||||||||||||||||||||||||||||||||||        | 84% ....";
    Sleep(630);
    system("color 3f");
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ****************************~~Loading~~**************************\n"
         << endl;
    cout << "\t\t\t\t\t\t Loading ||||||||||||||||||||||||||||||||||||||||||||||||||||||    | 97% ....";
    Sleep(470);
    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ****************************~~Loading~~**************************\n"
         << endl;
    cout << "\t\t\t\t\t\t Loading |||||||||||||||||||||||||||||||||||||||||||||||||||||||| | 100% ....";
}
void login()
{
    int reg;
    int count = 0;
    string userID, password, id, pass, useremail, email;
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\t Please enter the username and password : " << endl;
    cout << "\t\t\t\t\t\t USERNAME : ";
    cin >> userID;
    cout << "\t\t\t\t\t\t EMAIL : ";
    cin >> useremail;
    cout << "\t\t\t\t\t\t PASSWORD : ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> email >> pass)
    {
        if (id == userID && pass == password && email == useremail)
        {
            count = 1;
            system("cls");
        }
    }

    input.close();
    if (count == 1)
    {
        cout << "\n\n\n\t\t\t\t\t\tMr/Mrs" << userID << "Your LOGIN is successful \n\t\t\t\t\t\t Thanks for logging in! \n";
        cout << "\t\t\t\t\t\tDo You Want to Proceude further ?\n";
        system("pause");
    }
    else
    {
        cout << " \n\t\t\t\t\t\t LOGIN ERROR \n Please check your registration \n ";
        system("pause");
        system("cls");
        while (true)
        {
            cout << "\n\t\t\t\t\t\t Do You Want To Register Yourself?\n\t\t\t\t\t\tIf Yes press 1 If No Press 2\n";
            cout << "\n\n\n\t\t\t\t\t\t 1. You Want To Register \n\t\t\t\t\t\t2.You Don't To Register \n";

            cin >> reg;
            if (cin.fail() || (reg != 2 && reg != 1))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input! Please enter either 1 or 2." << endl;
            }
            else
            {
                break;
            }
        }

        if (reg == 1)
        {
            system("cls");
            registration();
        }
        else
        {
            system("cls");
            login_manual();
        }
    }
}
void registration()
{
    string ruserID, rpassword, rid, rpass, ruseremail, remail;
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\twelcome to registration" << endl;
    cout << "\t\t\t\t\t\t Plz Enter the username : ";
    cin >> ruserID;
    cout << "\t\t\t\t\t\t Plz Enter the email : ";
    cin >> ruseremail;
    cout << "\t\t\t\t\t\t Plz Enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserID << ' ' << ruseremail << ' ' << rpassword << endl;
    cout << "\n\t\t\t\t\t\t Registration is successful! \n";

    system("pause");
    system("cls");
    login_manual();
}
void forgot()
{
    int option;
    system("cls");
    cout << "\n\n\n\n\n\t\t\t\t\t\t\t You forgot the password? No worries \n";
    cout << "\t\t\t\t\t\t Press 1 to search your ID by username or email " << endl;
    cout << "\t\t\t\t\t\t Press 2 to go back to the main menu" << endl;
    cout << "\t\t\t\t\t\t Enter your choice : ";

    while (!(cin >> option) || option < 1 || option > 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t\t Invalid input. Please enter a numeric choice between 1 and 2: ";
    }
    cout << endl;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserID, sid, spass, semail;
        cout << "\n\t\t\t\t\t\t Enter the username or email which you remembered : ";
        cin >> suserID;
        processing();

        ifstream f2("records.txt");
        while (f2 >> sid >> semail >> spass)
        {
            if (sid == suserID || semail == suserID)
            {
                count = 1;
                break;
            }
        }

        f2.close();
        if (count == 1)
        {
            cout << "\n\n\t\t\t Your account is found! \n";
            cout << "\n\n\t\t\t Your password is : " << spass;
            Sleep(3000);
            system("cls");
            login_manual();
        }
        else
        {
            cout << "\n\n\t\t\t Sorry! Your account is not found! \n";
            Sleep(3000);
            system("cls");
            login_manual();
        }
        break;
    }
    case 2:
    {
        system("cls");
        login_manual();
        break;
    }
    default:
        cout << "\n\n\n\t\t\t\t\t\t Wrong choice! Please try again " << endl;
        forgot();
        break;
    }
}
void exit()
{
    system("color 3f");
    cout << endl
         << endl;
    system("cls");

    Sleep(60);
    system("color 3f");
    cout << "\n\t\t\t\t\t--------------------------------------------\n";
    cout << "\t\t\t\t\t|              !!!!!!!!!!!                 |\n";
    cout << "\t\t\t\t\t|             (  o      o )                |\n";
    cout << "\t\t\t\t\t|              (    ||   )                 |\n";
    cout << "\t\t\t\t\t|             ( ________  )                |\n";
    cout << "\t\t\t\t\t|               ##########                 |\n";
    cout << "\t\t\t\t\t|                                          |\n";
    cout << "\t\t\t\t\t|   Thank you for selecting our service    |\n";
    cout << "\t\t\t\t\t|                                          |\n";
    cout << "\t\t\t\t\t|                                          |\n";
    cout << "\t\t\t\t\t|                                          |\n";
    cout << "\t\t\t\t\t|                                          |\n";
    cout << "\t\t\t\t\t--------------------------------------------";
    Sleep(1000);
    system("cls");
    system("color 3f");
    Sleep(999);

    cout << "\n\t\t\t\t\t--------------------------------------------\n";
    cout << "\t\t\t\t\t|              !!!!!!!!!!!                 |\n";
    cout << "\t\t\t\t\t|             (  o      o )                |\n";
    cout << "\t\t\t\t\t|              (    ||   )                 |\n";
    cout << "\t\t\t\t\t|              ( ________ )                |\n";
    cout << "\t\t\t\t\t|               ##########                 |\n";
    cout << "\t\t\t\t\t|                                          |\n";
    cout << "\t\t\t\t\t|   Thank you for selecting our service    |\n";
    cout << "\t\t\t\t\t|             _____________                |\n";
    cout << "\t\t\t\t\t|            |   o    o    |               |\n";
    cout << "\t\t\t\t\t|            |     i       |               |\n";
    cout << "\t\t\t\t\t|            |   |----|    |               |\n";
    cout << "\t\t\t\t\t--------------------------------------------\n";
    cout << "\t\t\t\t\t";
    system("pause");
}
void processing()
{

    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    Please Wait ...\n"
         << endl;
    cout << "\t\t\t\t\t\t Under Proceesing <<<|||||||                                        |>>> 17% ....";
    Sleep(500);
    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    Please Wait for ...\n"
         << endl;
    cout << "\t\t\t\t\t\t Under Proceesing <<<|||||||||||||||||||                            |>>> 47% ....";
    Sleep(630);
    system("color 3f");
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    Please Wait ...\n"
         << endl;
    cout << "\t\t\t\t\t\t Under Proceesing <<<|||||||||||||||||||||||||||||||||              |>>> 61% ....";
    Sleep(570);
    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    Please Wait \n"
         << endl;
    cout << "\t\t\t\t\t\t Under Proceesing <<<|||||||||||||||||||||||||||||||||||||||||||||||| |>>> 95% ....";
    Sleep(470);
    system("cls");
    system("color 3f");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    Please Wait...\n"
         << endl;
    cout << "\t\t\t\t\t\tUnder Proceesing <<<|||||||||||||||||||||||||||||||||||||||||||||||||||||||||>>> 100% ....\n";
    Sleep(580);
    cout << endl
         << "\t\t\t\t\t\t\t";
    system("cls");
}
int menu()
{

    int choice;
    system("cls");
    system("color 3f");
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "\n\n\n\n";
    cout << setw(120) << "*******************************************************************\n";
    cout << setw(120) << "***********************~~~~~~MAIN MENU~~~~*************************\n";
    cout << setw(120) << "****                                                           ****\n";
    cout << setw(120) << "****                   <1>~ Flight Schedule                    ****\n";
    cout << setw(120) << "****                                                           ****\n";
    cout << setw(120) << "****                   <2>~ Seat Reservation                   ****\n";
    cout << setw(120) << "****                                                           ****\n";
    cout << setw(120) << "****                   <3>~ Cancel your Ticket                 ****\n";
    cout << setw(120) << "****                                                           ****\n";
    cout << setw(120) << "****                   <4>~ Generate Receipt                   ****\n";
    cout << setw(120) << "****                                                           ****\n";
    cout << setw(120) << "****                   <5>~ User Manual of system              ****\n";
    cout << setw(120) << "****                                                           ****\n";
    cout << setw(120) << "****                   <6>~ Admin Panel                        ****\n";
    cout << setw(120) << "****                                                           ****\n";
    cout << setw(120) << "****                   <7>~ About                              ****\n";
    cout << setw(120) << "****                                                           ****\n";
    cout << setw(120) << "****                   <8>~ Exit                               ****\n";
    cout << setw(120) << "****                                                           ****\n";
    cout << setw(120) << "*******************************************************************\n";
    cout << setw(120) << "*******************************************************************\n";
    cout << setw(120) << "__________________------------------------------_________________________\n";
    cout << "\t\t\t\t\t\tPlz Enter Your Choice  :";
    cin >> choice;
    cin.clear();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\t\t\t Invalid input. Please enter a numeric choice between 1 and 8: ";
    // Sleep(10000);

    cout << endl;
    return choice;
}
void user_manual()
{
    system("cls");
    system("color 3f");
    cout << endl
         << endl
         << endl;
    cout << "\n\n\n\n\n\t\t\t\t\t\t*******************~~User Manual~~************************" << endl
         << endl;
    cout << "\t\t\t\t\t\t                Be careful before using our system! \n\n";
    cout << "\t\t\t\t\t\t1. First of all you have to register into system . \n\n";
    cout << "\t\t\t\t\t\t * In case, if you have account go to login option, if you want to reset your password,\n\t\t\t\t\t\t you have to go to forgot option. \n\n";
    cout << "\t\t\t\t\t\t2. If you have account then you have to login first. \n\n";
    cout << "\t\t\t\t\t\t3. After login you can now see the main menu .\n\t\t\t\t\t\t You can see flight schedule using filght schedule option \n\n";
    cout << "\t\t\t\t\t\t4. After selecting the flight schedule you have to reserve your seat using seat reservation option. \n\n";
    cout << "\t\t\t\t\t\t5. After reserving your seat you have to pay for your seat. \n\n";
    cout << "\t\t\t\t\t\t6. After paying for your seat you can to print your receipt. \n\n";
    cout << "\t\t\t\t\t\t7. After printing your receipt you have to exit the program. \n\n";
    cout << "\t\t\t\t\t\t8. In case of emergency, If you want to cancel your reserved ticket then \n\t\t\t\t\t\t You have to select the Cancel ticket option from the menu. \n\n";
    cout << "\t\t\t\t\t\t9. If you want to know about the discounts then you have to select the discount option. \n\n";
    cout << "\t\t\t\t\t\t10. If you want to know about the system then you have to select the about option. \n\n";
    cout << "\t\t\t\t\t\t11. If you want to know about the user manual of the system then you have to select the user manual option. \n\n";
    cout << "\t\t\t\t\t\t12. If you want to exit the program then you have to select the exit option. \n\n";
    cout << "\t\t\t\t\t\t13. If you want to reset your password then you have to select the forgot password option from user panel menu. \n\n";
    cout << "\t\t\t\t\t\t14. If you want to go to the admin panel then you have to select the admin panel option from the main menu.\n \t\t\t\t\t\t Enter your id and password and login to admin panel \n\n";
    cout << "\t\t\t\t\t\t15. The Default id and password for admin panel is:   @dmin -- 1@3. \n";
    cout << "\t\t\t\t\t\t All Rights are Reserved. \n\n";
    cout << "\t\t\t\t\t\t Copyright @ umar ahad uddin ahmed usmani & muhammad qasim +923334739757 & +923206589259 \n\n";
    cout << "\t\t\t\t\t\t Thank You for using our system! \n";
    system("pause");
}
void about()
{
    system("cls");
    system("color 3f");
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "\n\n\n\n\n\t\t\t\t\t\t*******************~~About~~************************" << endl;

    cout << "\t\t\t\t\t\tThis is an Airline Ticketing System. \n";
    cout << "\t\t\t\t\t\tThis system is developed by Umar Ahad Uddin Ahmed Usmani & Muhammad Qasim .\n";
    cout << "\t\t\t\t\t\tThis system is developed for the PBL Project of first semester. \n";
    cout << "\t\t\t\t\t\t\t\t\t\t\n";
    cout << "\t\t\t\t\t\tAll Rights are Reserved. \n";
    cout << "\t\t\t\t\t\t You can contact with us at umarahadusmani@gmail.com & mq9140681@gmail.com or +923334739757 & +923206589259 \n";
    cout << "\t\t\t\t\t\t Thanks for using our service \n";
    system("pause");
}
void schedule_show()
{
    system("cls");

    if (!schedule_set)
    {
        int tra;
        while (true)
        {
            cout << "\n\n\n\t\t\t\t\t\tDo  You Want To Travel Domestic or Internationl?\n\t\t\t\t\t\t If Domestic press 1 If International  Press 2\n";
            cout << "\n\n\n\t\t\t\t\t\1. You Want To Travel Domestic \n\t\t\t\t\t2.You Want To Travel International  \n"
                 << endl;
            cout << "Plz Enter Your Choice ";
            cin >> tra;
            if (cin.fail() || (tra != 2 && tra != 1))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input! Please enter either 1 or 2." << endl;
            }
            else
            {
                break;
            }
        }

        if (tra == 1)
        {

            flights_dos[0].date = "08-07-2024";
            flights_dos[0].from = "LAHORE";
            flights_dos[0].to = "Karachi";
            flights_dos[0].timing = "9:30 AM";
            flights_dos[0].airline = "AIR SIAL";
            flights_dos[0].price = 20000;
            flights_dos[0].total_seats = 34;

            flights_dos[1].date = "12-07-2024";
            flights_dos[1].from = "Islamabad";
            flights_dos[1].to = "Sakardu";
            flights_dos[1].timing = "11:00 AM";
            flights_dos[1].airline = "PIA";
            flights_dos[1].price = 50000;
            flights_dos[1].total_seats = 100;

            flights_dos[2].date = "13-07-2024";
            flights_dos[2].from = "LAHORE";
            flights_dos[2].to = "Islamabad";
            flights_dos[2].timing = "09:30 AM";
            flights_dos[2].airline = "Sarene Airways";
            flights_dos[2].price = 18700;
            flights_dos[2].total_seats = 75;

            flights_dos[3].date = "13-07-2024";
            flights_dos[3].from = "Karachi";
            flights_dos[3].to = "Peshawer";
            flights_dos[3].timing = "01:30 PM";
            flights_dos[3].airline = "Air Blue";
            flights_dos[3].price = 23500;
            flights_dos[3].total_seats = 60;

            flights_dos[4].date = "14-07-2024";
            flights_dos[4].from = "LAHORE";
            flights_dos[4].to = "Quetta";
            flights_dos[4].timing = "05:30 PM";
            flights_dos[4].airline = "PIA";
            flights_dos[4].price = 17500;
            flights_dos[4].total_seats = 35;
        }

        cout << "\t\t\t\t Today is:  " << __DATE__ << "  ";
        cout << "Current Time is: " << __TIME__ << endl
             << endl;

        cout << "\t\t\t\t\t\tToday Available Domestic flights are\n";
        cout << "\t\t\t\t " << setw(10) << "Flight"
             << setw(15) << "Date"
             << setw(15) << "From"
             << setw(15) << "To"
             << setw(15) << "Timing"
             << setw(15) << "Airline"
             << setw(20) << "Remaining Seats"
             << setw(10) << "Price" << endl;
        cout << "\t\t\t\t----------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < a; i++)
        {
            cout << "\t\t\t\t " << setw(10) << i + 1
                 << setw(15) << flights_dos[i].date
                 << setw(15) << flights_dos[i].from
                 << setw(15) << flights_dos[i].to
                 << setw(15) << flights_dos[i].timing
                 << setw(15) << flights_dos[i].airline
                 << setw(20) << flights_dos[i].total_seats - reserve_seats
                 << setw(10) << flights_dos[i].price << endl;
        }

        cout << endl
             << endl;
        cout << "\t\t\t\t    |+|______________________________________________________________________________________|+| \n";
        cout << "\t\t\t\t    |+|**************************************************************************************|+| \n";
        cout << "                                        __________________________________________________________________________________   " << endl;

        system("pause");
        cout << endl;
    }
    else
    {

        flights_int[0].date = "12-07-2024";
        flights_int[0].from = "Lahore";
        flights_int[0].to = "Istanbul";
        flights_int[0].timing = "5:30 AM";
        flights_int[0].airline = "Turkish Airways";
        flights_int[0].price = 105000;
        flights_int[0].total_seats = 60;

        flights_int[1].date = "12-07-2024";
        flights_int[1].from = "Islamabad";
        flights_int[1].to = "Toronto";
        flights_int[1].timing = "11:00 AM";
        flights_int[1].airline = "PIA";
        flights_int[1].price = 175000;
        flights_int[1].total_seats = 100;

        flights_int[2].date = "13-07-2024";
        flights_int[2].from = "Lahore";
        flights_int[2].to = "Jeddah";
        flights_int[2].timing = "09:30 AM";
        flights_int[2].airline = "Sarene Airways";
        flights_int[2].price = 87000;
        flights_int[2].total_seats = 75;

        flights_int[3].date = "14-07-2024";
        flights_int[3].from = "Karachi";
        flights_int[3].to = "Bali";
        flights_int[3].timing = "01:30 PM";
        flights_int[3].airline = "Qatar Airways";
        flights_int[3].price = 135000;
        flights_int[3].total_seats = 60;

        flights_int[4].date = "14-07-2024";
        flights_int[4].from = "LAHORE";
        flights_int[4].to = "Dubai";
        flights_int[4].timing = "05:30 PM";
        flights_int[4].airline = "Flu Jinaah";
        flights_int[4].price = 100000;
        flights_int[4].total_seats = 95;

        cout << "\t\t\t\t Today is:  " << __DATE__ << "  ";
        cout << "Current Time is: " << __TIME__ << endl
             << endl;

        cout << "\t\t\t\t\t\tToday Available International flights are\n";
        cout << "\t\t\t\t " << setw(10) << "Flight"
             << setw(15) << "Date"
             << setw(15) << "From"
             << setw(15) << "To"
             << setw(15) << "Timing"
             << setw(15) << "Airline"
             << setw(20) << "Remaining Seats"
             << setw(10) << "Price" << endl;
        cout << "\t\t\t\t----------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < b; i++)
        {
            cout << "\t\t\t\t " << setw(10) << i + 1
                 << setw(15) << flights_int[i].date
                 << setw(15) << flights_int[i].from
                 << setw(15) << flights_int[i].to
                 << setw(15) << flights_int[i].timing
                 << setw(15) << flights_int[i].airline
                 << setw(20) << flights_int[i].total_seats - reserve_seats
                 << setw(10) << flights_int[i].price << endl;
        }

        cout << endl
             << endl;
        cout << "\t\t\t\t    |+|______________________________________________________________________________________|+| \n";
        cout << "\t\t\t\t    |+|**************************************************************************************|+| \n";
        cout << "                        __________________________________________________________________________________   " << endl;

        system("pause");
        cout << endl;
    }
}

void reserved_seat()
{
    system("cls");
    int discount = 0, gov_std, age;

    cout << "\n\n\n\n\t\t\t\t\t\t~*~*~*~*~*~*~*~*~*~*~*~*Registration for Your Seat Reservation*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
    cout << "\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~Be Careful before Providing Your Information~~~~~~~~~~~~~~~~~~~~\n"
         << endl;

    cin.ignore();
    cout << "\t\t\t\t\t\tPlease Enter your name: ";
    getline(cin, p[reserve_seats].name);
    cout << "\t\t\t\t\t\tPlease Enter your address: ";
    getline(cin, p[reserve_seats].address);
    cout << "\t\t\t\t\t\tPlease Enter your passport number: ";
    getline(cin, p[reserve_seats].passport);
    cout << "\t\t\t\t\t\tPlease Enter your CNIC number: ";
    getline(cin, p[reserve_seats].cnic);
    cout << "\t\t\t\t\t\tPlease Enter your phone number: ";
    getline(cin, p[reserve_seats].phone_no);

    cout << "\n\n\n";
    schedule_show();
    int redo;
    while (true)
    {
        cout << "\t\t\t\t\t\tDo You Want To Reserve A seat?\n If Domestic Flight Press 1 If International Flight Press 2\n";
        cout << "\n\t\t\t\t\t\t1.You Want To Reserve A Seat In Domestic Flight \n\t\t\t\t\t\t2.You  Want To Reserve A Seat In International Flight   \n";

        cin >> redo;
        if (cin.fail() || (redo != 2 && redo != 1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter either 1 or 2." << endl;
        }
        else
        {
            break;
        }
    }

    if (redo == 1)
    {
        int i, m;
        cout << "\n\t\t\t\t\t\tEnter your flight number that you want to reserve: ";
        cin >> i;
        m = i - 1;
        cout << "\t\t\t\t\t\tThe flight you want to reserve is:\n";
        cout << "\t\t\t\t\t\tTravel Date: " << flights_dos[m].date << endl;
        cout << "\t\t\t\t\t\tDeparture City: " << flights_dos[m].from << endl;
        cout << "\t\t\t\t\t\tDestination City: " << flights_dos[m].to << endl;
        cout << "\t\t\t\t\t\tFlight Time: " << flights_dos[m].timing << endl;
        cout << "\t\t\t\t\t\tAirline: " << flights_dos[m].airline << endl;
        cout << "\t\t\t\t\t\tRemaining Seats: " << flights_dos[m].total_seats - reserve_seats << endl;

        cin.ignore();
        while (true)
        {
            cout << "\t\t\t\t\t\tPlease Enter your seat type:\n";
            cout << "\t\t\t\t\t\t1. Business Class (Press 1)\n";
            cout << "\t\t\t\t\t\t2. Economy Class (Press 2)\n";
            cout << "\t\t\t\t\t\tEnter the seat type (1 or 2): ";
            getline(cin, p[reserve_seats].seat_type);
            int pay = flights_dos[m].price;
            if (p[reserve_seats].seat_type == "1")
            {
                cout << "you will be Charge extra Rs" << extra << endl;
                p[reserve_seats].payment = pay + extra;
                break;
            }
            else if (p[reserve_seats].seat_type == "2")
            {
                p[reserve_seats].payment = flights_dos[m].price;
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input! Please enter a valid seat type." << endl;
            }
        }
    }
    else
    {

        int j, k;
        cout << "\n\t\t\t\t\t\tEnter your flight number that you want to reserve: ";
        cin >> j;
        k = j - 1;
        cout << "\t\t\t\t\t\tThe flight you want to reserve is:\n";
        cout << "\t\t\t\t\t\tTravel Date: " << flights_int[k].date << endl;
        cout << "\t\t\t\t\t\tDeparture City: " << flights_int[k].from << endl;
        cout << "\t\t\t\t\t\tDestination City: " << flights_int[k].to << endl;
        cout << "\t\t\t\t\t\tFlight Time: " << flights_int[k].timing << endl;
        cout << "\t\t\t\t\t\tAirline: " << flights_int[k].airline << endl;
        cout << "\t\t\t\t\t\tRemaining Seats: " << flights_int[k].total_seats - reserve_seats << endl;

        cin.ignore();
        while (true)
        {
            cout << "\t\t\t\t\t\tPlease Enter your seat type:\n";
            cout << "\t\t\t\t\t\t1. Business Class (Press 1)\n";
            cout << "\t\t\t\t\t\t2. Economy Class (Press 2)\n";
            cout << "\t\t\t\t\t\tEnter the seat type (1 or 2): ";
            getline(cin, p[reserve_seats].seat_type);
            int pay = flights_int[k].price;
            if (p[reserve_seats].seat_type == "1")
            {
                cout << "you will be Charge extra Rs" << extra << endl;
                p[reserve_seats].payment = pay + extra;
                break;
            }
            else if (p[reserve_seats].seat_type == "2")
            {
                p[reserve_seats].payment = flights_int[k].price;
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Input! Please enter a valid seat type." << endl;
            }
        }
    }

    system("pause");
    while (true)
    {
        cout << "\n\t\t\t\t\t\tDo You Want any Dicount?\n If Yes press 1 If No Press 2\n";
        cout << "\n\t\t\t\t\t\t1. Yes I Need A Discount \n\t\t\t\t\t\t2.No I Don't Need Any Discount  \n";

        cin >> discount;
        if (cin.fail() || (discount != 2 && discount != 1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter either 1 or 2." << endl;
        }
        else
        {
            break;
        }
    }

    if (discount == 1)
    {
        system("cls");

        cout << "\n\t\t\t\t\t\tHow old are you? ";
        cin >> age;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter a valid age." << endl;
            cin >> age;
        }
        if (age >= 60)
        {
            cout << "\n\t\t\t\t\t\tYou have a 50% discount." << endl;
            p[reserve_seats].discounts = 50;
        }
        else if (age >= 40)
        {
            cout << "\n\t\t\t\t\t\tYou have a 15% discount." << endl;
            p[reserve_seats].discounts = 15;
        }
        else if (age <= 20)
        {
            cout << "You have a 30% discount." << endl;
            p[reserve_seats].discounts = 30;
        }
        else
        {
            cout << "You have a 0% discount." << endl;
            p[reserve_seats].discounts = 0;
        }
    }
    while (true)
    {
        cout << "\n\t\t\t\t\t\tDo You Are Government Employee or Student?\n If Yes press 1 If No Press 2\n";
        cout << "1. You Are Government Employee or Student\n2.You Are Not  Government Employee or Student \n";

        cin >> gov_std;
        if (cin.fail() || (gov_std != 2 && gov_std != 1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter either 1 or 2." << endl;
        }
        else
        {
            break;
        }
    }
    if (gov_std == 1)
    {
        cout << "Are you a government employee? (Press 1 For Yes or 2 For No): ";
        int govt_employee;
        cin >> govt_employee;
        if (govt_employee == 1)
        {
            cout << "You have an additional 5% Government Employee Discount." << endl;
            p[reserve_seats].discounts += 5;
        }
        else
        {
            cout << "You are not eligible for Government Employee  discount." << endl;
        }

        cout << "Are you a student? (Press 1 For Yes or 2 For No): ";
        int student;
        cin >> student;
        if (student == 1)
        {
            cout << "You have an additional  Student discount." << endl;
            p[reserve_seats].discounts += 15;
        }
        else
        {
            cout << "You are not eligible for Student discount." << endl;
        }
    }
    else
    {
        cout << "You have no discount." << endl;
    }

    cout << "\n\t\t\t\t\t\tYou have " << p[reserve_seats].discounts << "% discount." << endl;
    cout << "\t\t\t\t\t\tYour total payment is: " << p[reserve_seats].payment - (p[reserve_seats].payment * p[reserve_seats].discounts / 100) << endl;
    cout << "\t\t\t\t\t\tSeat is reserved! Congratulations!" << endl;
    cout << "\t\t\t\t\t\tYour seat number is: " << reserve_seats + 1 << endl;

    cout << "\n\n\t\t\t\t\t\tYou Have Too Pay The Payment Online\n";

    cout << "\t\t\t\t\t\tPlz Enter Your Credit Card Number :";
    cin >> p[reserve_seats].debit;
    cout << " \t\t\t\t\t\tThanks For Reserve A Seat \n";

    cin.ignore();

    cout << "\n\t\t\t\t\t\tDo you want to reserve more seats? :\n1. If Yes Press 1\n2.If No Press 2";
    int choice;
    cin >> choice;

    while (true)
    {
        if (choice != 1 && choice != 2)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter either 1 or 2" << endl;
            cin >> choice;
        }
        else
        {
            break;
        }
    }

    if (choice == 2)
    {
        return;
    }
    reserve_seats++;
}
void cancel_ticket()
{
    string cnic, name;

    system("cls");

    cout << "\n\n\n\n\t\t\t\t\t\t*******************~~Cancellation of Your Seat Reservation~~************************" << endl;
    cout << "\n\t\t\t\t\t\tDo you want to Cancel Your Seat? :\n1. If Yes Press 1\n2.If No Press 2";
    int choice;
    cin >> choice;

    while (true)
    {
        if (choice != 1 && choice != 2)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter either 1 or 2" << endl;
            cin >> choice;
        }
        else
        {
            break;
        }
    }

    if (choice == 1)
    {

        cout << "\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~|||||----)~Kindly Enter Your Information~(----|||||~~~~~~~~~~~~~~~~~~~~\n"
             << endl;

        cout << "Enter your CNIC (CNIC): ";
        getline(cin, cnic);
        cout << "Enter your name: ";
        getline(cin, name);

        bool ticketFound = false;

        for (int i = 0; i <= reserve_seats; i++)
        {
            if (cnic == p[i].cnic && name == p[i].name)
            {

                p[i].name = "";
                p[i].address = "";
                p[i].passport = "";
                p[i].cnic = "";
                p[i].phone_no = "";
                p[i].seat_type = "";
                p[i].flight_no = "";
                p[i].date_of_flight = "";
                p[i].destination = "";
                p[i].payment = 0;
                p[i].discounts = 0;

                reserve_seats--;

                for (int j = i; j <= reserve_seats; j++)
                {
                    p[j] = p[j + 1];
                }

                cout << "Your seat is canceled!" << endl;
                ticketFound = true;
                break;
            }
        }

        if (!ticketFound)
        {
            cout << "Record not found!" << endl;
        }
    }
    else
    {
        cout << "\n\t\t\t\t\t\tYou Do Not Want To Cancel The Ticket\n";
        system("pause");
    }
}
void receipt()
{
    string name, cnic;
    int index = -1;

    system("cls");

    cout << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t*******************~~Receipt Generation~~************************" << endl;
    cout << "\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~|||||----)~Kindly Enter Your Information~(----|||||~~~~~~~~~~~~~~~~~~~~\n"
         << endl;

    cout << "\t\t\t\t\t\tEnter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "\t\t\t\t\t\tEnter your CNIC: ";
    getline(cin, cnic);

    for (int i = 0; i <= reserve_seats; i++)
    {
        if (cnic == p[i].cnic && name == p[i].name)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "\t\t\t\t\t\tName: " << p[index].name << endl;
        cout << "\t\t\t\t\t\tAddress: " << p[index].address << endl;
        cout << "\t\t\t\t\t\tPassport number: " << p[index].passport << endl;
        cout << "\t\t\t\t\t\tCNIC number: " << p[index].cnic << endl;
        cout << "\t\t\t\t\t\tPhone number: " << p[index].phone_no << endl;
        cout << "\t\t\t\t\t\tSeat type: " << p[index].seat_type << endl;
        cout << "\t\t\t\t\t\tFlight number: " << p[index].flight_no << endl;
        cout << "\t\t\t\t\t\tDate of flight: " << p[index].date_of_flight << endl;
        cout << "\t\t\t\t\t\tDestination: " << p[index].destination << endl;
        cout << "\t\t\t\t\t\tTotal Price: " << p[index].payment << endl;
        cout << "\t\t\t\t\t\tDiscount: " << p[index].discounts << endl;
        cout << "\t\t\t\t\t\tFinal Payment: " << p[index].payment - (p[index].payment * p[index].discounts / 100) << endl;
        cout << "\t\t\t\t\t\tSeat Number: " << index + 1 << endl;
        system("pause");
    }
    else
    {
        cout << "Record not found!" << endl;
        system("pause");
    }
}
void admin_panel()
{
    bool admin_login = false;
    string id, pass;
    int attempts = 1, choice;
    int h;

    while (true)
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t|-|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|-|" << endl;
        cout << "\t\t\t\t\t\t|+|~~~~~~~~~~~~~{ Welcome To  Admin Panel }~~~~~~~~~~~~~|+|" << endl;
        cout << "\t\t\t\t\t\t|-|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|-|" << endl
             << endl
             << endl;

        cout << "Please enter the Admin ID and Password to login\n";
        cout << "\t\t\t\t\t\tEnter The Admin ID: ";
        getline(cin, id);
        cout << endl;

        cout << "\t\t\t\t\t\tEnter The Password: ";
        getline(cin, pass);
        cout << endl;

        if (id == "@dmin" && pass == "1@3")
        {
            cout << "\t\t\t\t\t\tYou Logged in Successfully!" << endl;
            system("pause");
            processing();
            admin_login = true;
            break;
        }
        else if (attempts % 5 == 0)
        {
            cout << "\n\t\t\t\t\t\tYou have exceeded the number of attempts!" << endl;
            system("pause");
        }
        else
        {
            cout << "\n\t\t\t\t\t\tInvalid ID or Password! " << endl;
            cout << "\t\t\t\t\t\tPlease Try Again!" << endl;
            system("pause");
            system("cls");
        }

        attempts++;
    }

    if (admin_login)
    {
        while (true)
        {
            system("cls");

            cout << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl
                 << endl;
            cout << "\n\n\n\n";
            cout << setw(120) << "*******************************************************************\n";
            cout << setw(120) << "***********************~~~~~~Admin Panel~~~~*************************\n";
            cout << setw(120) << "****                                                           ****\n";
            cout << setw(120) << "****                 <1>~ View Flight Schedule                 ****\n";
            cout << setw(120) << "****                                                           ****\n";
            cout << setw(120) << "****                 <2>~ Edit Flight Schedule                 ****\n";
            cout << setw(120) << "****                                                           ****\n";
            cout << setw(120) << "****                 <3>~ View All User Data                   ****\n";
            cout << setw(120) << "****                                                           ****\n";
            cout << setw(120) << "****                 <4>~ View All Passenger Data              ****\n";
            cout << setw(120) << "****                                                           ****\n";
            cout << setw(120) << "****                 <5>~ View All Reserved Seats              ****\n";
            cout << setw(120) << "****                                                           ****\n";
            cout << setw(120) << "****                 <6>~ Exit to Admin Panel                  ****\n";
            cout << setw(120) << "****                                                           ****\n";
            cout << setw(120) << "*******************************************************************\n";
            cout << setw(120) << "*******************************************************************\n";
            cout << setw(120) << "__________________------------------------------_________________________\n";
            cout << "\t\t\t\t\t\tEnter Your Choice: ";
            cin >> choice;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice)
            {
            case 1:
                processing();
                schedule_show();

                break;
            case 2:
                processing();
                edit_flights();
                break;
            case 3:
                processing();
                Records();
                break;
            case 4:
                cout << "\t\t\t\t\t\t All Passenger Data" << endl;
                for (h = 0; h < count; h++)
                {
                    cout << "\n\t\t\t\t\t\tPassenger Name: " << p[h].name << endl;
                    cout << "\t\t\t\t\t\tPassenger Address: " << p[h].address << endl;
                    cout << "\t\t\t\t\t\tPassenger Passport: " << p[h].passport << endl;
                    cout << "\t\t\t\t\t\tPassenger CNIC: " << p[h].cnic << endl;
                    cout << "\t\t\t\t\t\tPassenger Phone Number: " << p[h].phone_no << endl;
                    cout << "\t\t\t\t\t\tPassenger Seat Type: " << p[h].seat_type << endl;
                    cout << "\t\t\t\t\t\tPassenger Discount: " << p[h].discounts << endl;
                    cout << "\t\t\t\t\t\tPassenger Payment: " << p[h].payment << endl;
                    cout << "\t\t\t\t\t\tPassenger Credit Card Number: " << p[h].debit << endl;
                    cout << endl;
                    break;
                case 5:
                    cout << "\t\t\t\t\t\t All Reserved Seats Are " << endl;
                    cout << "Total Reserved Seats: " << reserve_seats << endl;
                    break;
                case 6:
                    cout << "\t\t\t\t\t\tExit From Admin Panel" << endl;
                    system("pause");
                    break;
                default:
                    cout << "\t\t\t\t\t\tInvalid Option!" << endl;
                    break;
                }

                if (choice == 6)
                {
                    break;
                }

                system("pause");
            }
        }
    }
}

void Records()
{

    ifstream input("records.txt");
    int count = 0;
    string id, email, pass;

    while (input >> id >> email >> pass)
    {
        count++;
        cout << "\t\t\t\t\t\tRecord " << count << ": " << endl;
        cout << "\t\t\t\t\t\tUsername: " << id << endl;
        cout << "\t\t\t\t\t\tEmail: " << email << endl;
        cout << "\t\t\t\t\t\tPassword: " << pass << endl
             << endl;
    }

    input.close();
    cout << "Total number of records: " << count << endl;
}
