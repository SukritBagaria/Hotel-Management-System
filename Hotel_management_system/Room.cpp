#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "hotelManager.h"
#include "Room.h"
#include "Customer.h"
#include "sql.h"

using namespace std;

//done
void Room::addRoom(int roomnumber){
    sql sql;
    Room room;
    cout << "\n***********";
    cout << "\n(Deluxe Suite->D)\n(Non-Deluxe Suite->N)\n(Presidential Suite->P)\n";
    cout << "*********";
    cout << "\nEnter the code for room type:";
    cin >> room.roomtype;

    cout << "\n***********";
    cout << "\n(AC->A)\n(Non-AC->N)";
    cout << "\n***********";
    cout << "\nEnter the code for room comfort:";
    cin >> room.comfort;

    cout << "\n***********";
    cout << "\n(Single->S)\n(Double->D)";
    cout << "\n***********";
    cout << "\nEnter the code for room capacity:";
    cin >> room.capacity;

    cout << "\nEnter the rent per day:";
    cin >> room.rent_per_day;

    int status = 0;

    stringstream ss;
    ss << "INSERT INTO Rooms(RoomNumber, Type, Comfort, Capacity, Status, RentPerDay) VALUES('"<< roomnumber <<"','"<< room.roomtype <<"','"<< room.comfort <<"','"<< room.capacity <<"','"<< status <<"','"<< room.rent_per_day <<"')";
    if(sql.query_check(ss, sql)){
        cout << "\nRoom Added Successfully!";
        cout << "\nPress any key to display room:";
        cin.ignore();
        cin.get();
        displayRoom(roomnumber);
    }
    else{
        cout << "\nQuery Execution Failed!";
    }
    cout << "\nPress any key to continue:";
    cin.get();
    hotelManager hm;
    hm.manageRooms();
}

//done
void Room::displayRoom(int roomnumber){
    sql sql;
    hotelManager hm;
    cout << "\n***********\n";

            stringstream ss;
            ss << "SELECT * FROM Rooms WHERE RoomNumber = '"<< roomnumber <<"'";
            bool qstate = sql.query_check(ss, sql);
            if(qstate) {
                sql.res= mysql_store_result(sql.conn);
                sql.row = mysql_fetch_row(sql.res);
                if(sql.row) {
                    cout << "Details of Roomnumber " << sql.row[0] << " : \n";
                    cout << "Room type: " << sql.row[1] << "\n";
                    cout << "Room comfort: " << sql.row[2] << "\n";
                    cout << "Room capacity: " << sql.row[3] << "\n";
                    cout << "Room status: " << sql.row[4] << "\n";
                    cout << "Rent per day: " << sql.row[5] << "\n";
                }
                else cout << "\nNo record found!!";
            }
            else{
                cout << "\nQuery Execution Failed";
                cout << "Press any key to go back to manage rooms";
                cin.ignore();
                cin.get();
                hm.manageRooms();
            }
}

//done
void Room::modifyRoom(int roomnumber){
    int opt, index;
    sql sql;
    hotelManager hm;
    string newc;
    stringstream ss;
        cout << "\n***********";
        cout << "\nWhat would you want to modify?";
        cout << "\nRoom Type - Press 1\nRoom Comfort - Press 2\nRoom capacity - Press 3\nRent per day - Press 4\nFinish - Press 5\n";
        cout << "*********\n";
        cin >> opt;

    if (opt == 1){
            index = 1;
            cout << "\n***********";
            cout << "\n(Deluxe Suite->D)\n(Non-Deluxe Suite->N)\n(Presidential Suite->P)\n";
            cout << "*********";
            cout << "\nEnter the code for new room type:";
            cin >> newc;
            ss << "UPDATE Rooms SET Type = '"<< newc <<"' WHERE RoomNumber = '"<< roomnumber <<"'";
    }
        else if (opt == 2){
            index = 2;
            cout << "\n***********";
            cout << "\n(AC->A)\n(Non-AC->N)";
            cout << "*********";
            cout << "\nEnter the code for new room comfort:";
            cin >> newc;
            ss << "UPDATE Rooms SET Comfort = '"<< newc <<"' WHERE RoomNumber = '"<< roomnumber <<"'";
        }
        else if (opt == 3){
            index = 3;
            cout << "\n***********";
            cout << "\n(Single->S)\n(Double->D)";
            cout << "*********";
            cout << "\nEnter the code for new  room capacity:";
            cin >> newc;
            ss << "UPDATE Rooms SET Capacity = '"<< newc <<"' WHERE RoomNumber = '"<< roomnumber <<"'";
        }
        else if(opt == 4){
            index = 5;
            cout << "\nEnter new rent per day: ";
            cin >> newc;
            ss << "UPDATE Rooms SET RentPerDay = '"<< newc <<"' WHERE RoomNumber = '"<< roomnumber <<"'";
        }
        else if(opt == 5){
            hm.manageRooms();
        }
        else{
               cout << "\nInvalid Input";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            modifyRoom(roomnumber);
        }

        if(sql.query_check(ss, sql)) {
            cout << "Successfully Modified";
        }
        else{
            cout << "\nFailed to Modify";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            hm.manageRooms();
        }

    cout << "\nPress any key to continue: ";
    cin.ignore();
    cin.get();
    hm.mainMenu();
}

//done
void Room::searchRoom(int roomnumber){
    sql sql;
    hotelManager hm;

        stringstream ss;
        ss << "SELECT * FROM Rooms WHERE RoomNumber = '"<< roomnumber <<"'";
        bool qstate = sql.query_check(ss, sql);
        if(qstate) {
            sql.res= mysql_store_result(sql.conn);
            sql.row = mysql_fetch_row(sql.res);
            if(sql.row) {
                displayRoom(roomnumber);
                modifyRoom(roomnumber);
            }
            else cout << "\nNo record found!!";
        }
        else{
            cout << "\nQuery Execution Failed!";
        }
        cout << "\nPress any key to continue:";
        cin.ignore();
        cin.get();
        hm.manageRooms();
}


