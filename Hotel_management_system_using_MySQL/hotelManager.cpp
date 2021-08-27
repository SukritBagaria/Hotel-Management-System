#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Room.h"
#include "hotelManager.h"
#include "sql.h"

using namespace std;

//done
void hotelManager::manageRooms(){
    Room room;
    int menu, roomnumber;
    hotelManager hm;
    sql sql;

        cout << "\n***********";
        cout<<"\n### Manage Rooms ###";
        cout<<"\n1.Add Room\n2.Modify Room\n3.Back to main menu: ";
        cout << "\n***********";
        cout << "\n\nEnter Option: ";
        cin >> menu;
        if(menu == 1){
            cout << "\nEnter Room Number:";
            cin >> roomnumber;

            stringstream s1;
            s1 << "SELECT * FROM Rooms WHERE RoomNumber = '"<< roomnumber <<"'";
            bool qstate = sql.query_check(s1, sql);
            if(qstate) {
                sql.res= mysql_store_result(sql.conn);
                sql.row = mysql_fetch_row(sql.res);
                if(sql.row){
                    cout << "\nRoom Already Present!\n";
                    mainMenu();
                }
                else room.addRoom(roomnumber);
            }
            else cout << "\nQuery Execution Failed!";
        }
        else if(menu==2){
            cout << "\nEnter Room Number:";
            cin >> roomnumber;
            room.searchRoom(roomnumber);
        }
        else if(menu==3){
            hm.mainMenu();
        }
        else {
            cout << "*********";
            cout << "\nInvalid input!";
            cout << "*********";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            hm.manageRooms();
        }
}

//done
void hotelManager::checkIn(){
    sql sql;
    int roomnumber, again;
    cout << "Enter Room Number: ";
    cin >> roomnumber;
    stringstream s1, s2, s3;
    s1 << "SELECT Status FROM Rooms WHERE RoomNumber = '"<< roomnumber <<"'";
    bool qstate = sql.query_check(s1, sql);
    if(qstate) {
        sql.res= mysql_store_result(sql.conn);
        sql.row = mysql_fetch_row(sql.res);
        if(sql.row) {
            int status = atoi(sql.row[0]);
            if(status != 0) {
                cout << "\nRoom is already booked.";
                cout << "\nPress any key to continue:";
                cin.ignore();
                cin.get();
                cout << "\nPress 1 to go back to main menu\nPress 2 to enter another room no.";
                cin >> again;
                if(again==1)mainMenu();
                if(again==2)checkIn();
                else cout << "\nInvalid input!";
            }
            else {
                cout<<"\nEnter Customer Name (First Name): ";
                cin>>cust.firstname;
                cout<<"\nEnter Customer Name (Last Name): ";
                cin>>cust.lastname;
                cout<<"\nEnter Address (only city): ";
                cin>>cust.address;
                cout<<"\nEnter Phone Number(10 digits): ";
                cin >> cust.phone;

                s2 << "INSERT INTO Guests(RoomNumber, FirstName, LastName, Address, PhoneNumber) VALUES('"<< roomnumber <<"','"<< cust.firstname <<"','"<< cust.lastname <<"','"<< cust.address <<"','"<< cust.phone <<"')";
                bool q2state = sql.query_check(s2, sql);
                if(q2state) {
                    status = 1;
                    s3 << "UPDATE Rooms SET Status = '"<< status <<"' WHERE RoomNumber = '"<< roomnumber <<"'";
                    bool q3state = sql.query_check(s3, sql);
                    if(q3state) {
                            cout << "\nCustomer CheckedIn Successfully!";
                    }
                    else cout << "\nRoomStatus not modified!";
                }
                else cout << "\nCheckIn UnSuccessful!";
            }
        }
        else cout << "\nRoom Not Found\n";
    }
    else {
        cout << "Query Execution Failed\n";
    }
    cout << "\nPress any key to continue:";
    cin.ignore();
    cin.get();
    mainMenu();
}

//done
void hotelManager::checkOut(int roomnumber){
    sql sql;
    int bill;
    int num_of_days;
    stringstream s1, s2, s3, s4;
    s1 << "SELECT Status, RentPerDay FROM Rooms WHERE RoomNumber = '"<< roomnumber <<"'";
    bool qstate = sql.query_check(s1, sql);
    if(qstate){
        sql.res= mysql_store_result(sql.conn);
        sql.row = mysql_fetch_row(sql.res);
        if(sql.row) {
            int status = atoi(sql.row[0]);
            int rent = atoi(sql.row[1]);
            if(status == 0) {
                cout << "\nRoom is empty.";
            }
            else {
                cout<<"\nEnter number of days room was booked for: ";
                cin>>num_of_days;
                bill = num_of_days*rent;

                s2 << "INSERT INTO Customers SELECT guest.*, '"<<num_of_days<<"', '"<<bill<<"' FROM Guests guest WHERE RoomNumber = '"<< roomnumber <<"'";

                bool q2state = sql.query_check(s2, sql);
                if(q2state){
                    s3 << "DELETE FROM Guests WHERE RoomNumber = '"<< roomnumber <<"'";
                    bool q3state = sql.query_check(s3, sql);
                    if(q3state) {
                        status = 0;
                        s4 << "UPDATE Rooms SET Status = '"<< status <<"' WHERE RoomNumber = '"<< roomnumber <<"'";
                        bool q4state = sql.query_check(s4, sql);
                        if(q4state) cout << "\nCheckOut Successful!";
                        else cout << "\nRoom Status Not Modified!";
                    }
                    else cout << "\n CheckOut Unsuccessful!";
                }
                else cout << "\nCustomers Data not Modified!"<<endl;
            }
        }
        else cout << "\nRoom not found";
    }
    else cout << "\nQuery Execution Failed";

    cout << "\nPress any key to continue:";
    cin.ignore();
    cin.get();
    mainMenu();
}

//done
void hotelManager::getAvailableRooms(){
    sql sql;
    int status = 0;
    stringstream s1;
    s1 << "SELECT RoomNumber FROM Rooms WHERE Status = '"<< status <<"'";
    bool qstate = sql.query_check(s1, sql);
    if(qstate) {
        sql.res= mysql_store_result(sql.conn);
        sql.row = mysql_fetch_row(sql.res);
        if(sql.row) {
            cout << "Room numbers of available rooms are: ";
            cout << sql.row[0] << ", ";

            while ((sql.row = mysql_fetch_row(sql.res)))
            cout << sql.row[0] << ", ";
        }
        else cout << "\nALL rooms are reserved.";
    }
    else cout << "\nQuery Not Executed";
    cout << "\nPress any key to continue:";
    cin.ignore();
    cin.get();
    mainMenu();
}

void hotelManager::searchCustomer(){

    sql sql;
    string fname;
    string lname;
    cout << "\nEnter first name of the customer:";
    cin >> fname;
    cout << "\nEnter last name of the customer:";
    cin >> lname;

    stringstream ss;
    ss << "SELECT * FROM Guests WHERE FirstName = '"<< fname << "' and LastName like '"<< lname << "'";
    bool qstate = sql.query_check(ss, sql);
    if(qstate) {
        sql.res= mysql_store_result(sql.conn);
        int flag = 0;
        cout << "\nCurrent Guest list:-\n";
        cout << "-----------------------\n";
        while ((sql.row = mysql_fetch_row(sql.res))) {
            cout << "Room Number: " << sql.row[0] << endl;
            cout << "Firstname: " << sql.row[1] << endl;
            cout << "Lastname: " << sql.row[2] << endl;
            cout << "Address: " << sql.row[3] << endl;
            cout << "Phone Number: " << sql.row[4] << endl;
            cout << "-----------------------\n";
            flag = 1;
        }
        if(flag == 0)
            cout << "No Such Customer" << endl;
        cout << "***********************\n";
    }
    else{
        cout << "Query not executed"<< endl;
    }
    
    stringstream s2;
    s2 << "SELECT * FROM Customers WHERE FirstName = '"<< fname << "' and LastName like '"<< lname << "'";
    bool q2state = sql.query_check(s2, sql);
    if(q2state) {
        sql.res= mysql_store_result(sql.conn);
        int flag = 0;
        cout << "Past Customers:-\n";
        cout << "-----------------------\n";
        while ((sql.row = mysql_fetch_row(sql.res))) {
            cout << "Room Number: " << sql.row[0] << endl;
            cout << "Firstname: " << sql.row[1] << endl;
            cout << "Lastname: " << sql.row[2] << endl;
            cout << "Address: " << sql.row[3] << endl;
            cout << "Phone Number: " << sql.row[4] << endl;
            cout << "Number of days of stay: " << sql.row[4] << endl;
            cout << "Total Bill: " << sql.row[4] << endl;
            cout << "-----------------------\n";
            flag = 1;
        }
        if(flag == 0)
            cout << "No Such Customer" << endl;
        cout << "***********************\n";
    }
    else{
        cout << "Query not executed"<< endl;
    }
    
    mainMenu();
}

void hotelManager::mainMenu(){
    hotelManager hm;
    cout << "Welcome to Monkey's Island\n" << endl;
    int menu;
    int roomnumber;
    cout << "*********";
    cout << "\n1.Manage Rooms"<< endl << "2.Check-In Room" << endl << "3.Check-out Room" << endl << "4.Search Customer" << endl << "5.Available Rooms" << endl << "6.Exit";
    cout << "*********";
    cout << "\nEnter the corresponding no. to go the menu:";
    cin >> menu;
    switch(menu){
        case 1:
           hm.manageRooms();
           break;
         case 2:
            hm.checkIn();
            break;
         case 3:
            cout << "\nEnter Room Number:";
            cin >> roomnumber;
            hm.checkOut(roomnumber);
            break;
        case 4:
                hm.searchCustomer();
            break;
        case 5:
                hm.getAvailableRooms();
            break;
        case 6:
            cout<<"\nTHANK YOU FOR USING THIS SOFTWARE";
            break;
        default:
            cout << "\nInvalid input.";
            cout << "\nEnter the correct option:";
    }
}

