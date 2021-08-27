#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "hotelManager.h"
#include "Room.h"
#include "Customer.h"

using namespace std;

void Room::addRoom(int roomnumber){
    Room room;
    room.rno=roomnumber;
    cout << "\n***********";
    cout << "\n(Deluxe Suite->D)\n(Non-Deluxe Suite->N)\n(Presidntial Suite->P)\n";
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
   
    room.status=0;
    cout << "\nEnter the rent per day:";
    cin >> room.rent_per_day;
    
    fstream fout;
    fout.open("HotelRooms.csv", ios::out | ios::app);

    fout << room.rno << ","
        << room.roomtype << ","
        << room.comfort << ","
        << room.capacity << ","
        << room.status << ","
        << room.rent_per_day
        << "\n";

    fout.close();
    cout << "\n Room added successfully!";
    displayRoom(roomnumber);
    hotelManager hm;
    hm.manageRooms();
}
 
 
void Room::displayRoom(int roomnumber){
    hotelManager hm;
    cout << "\n***********";
  
                fstream fin;
              fin.open("HotelRooms.csv", ios::in);
              int room2 = 0, count = 0;
              vector<string> row;
              string line, word, temp;
            
             while (!fin.eof()) {
                  row.clear();
                  getline(fin, line);
                  stringstream s(line);
                  //cout << s;
                  //cout << line;
                  while (s.good()) {
                      getline(s,word,',');
                      row.push_back(word);
                      //cout << row[0] << " ";
                  }
                  //cout << row.size();
                 if(row.size()>1){
                  room2 = stoi(row[0]);
                  if (room2 == roomnumber) {
                      count = 1;
                      break;
                  }
                 }
              }
      
            if (room2 == roomnumber) {
      
                count = 1;
                cout << "Details of Roomnumber " << row[0] << " : \n";
                cout << "Roomtype: " << row[1] << "\n";
                cout << "Room comfort: " << row[2] << "\n";
                cout << "Room capacity: " << row[3] << "\n";
                cout << "Room status: " << row[4] << "\n";
                cout << "Rent per day: " << row[5] << "\n";
            }
            fin.close();
            if(count ==0){
                cout << "\nNo record found";
                cout << "Press any key to go back to manage rooms";
                cin.ignore();
                cin.get();
                hm.manageRooms();
            }
}
 
void Room::modifyRoom(int roomnumber){
    int opt, index, room2;
    hotelManager hm;
    string newc;
        fstream fin, fout;
  
        fin.open("HotelRooms.csv", ios::in);
  
        fout.open("HotelRoomsnew.csv", ios::out);
        
        string line, word;
            vector<string> row;
        
        cout << "\n***********";
        cout << "\nWhat would you want to modify?";
        cout << "\nRoom Type - Press 1\nRoom Comfort - Press 2\nRoom capacity - Press 3\nRent per day - Press 4\nFinish - Press 5\n";
        cout << "*********";
        cin >> opt;
        
    if (opt == 1){
            index = 1;
            cout << "\n***********";
            cout << "\n(Deluxe Suite->D)\n(Non-Deluxe Suite->N)\n(Presidntial Suite->P)\n";
            cout << "*********";
            cout << "\nEnter the code for new room type:";
            cin >> newc;
    }
        else if (opt == 2){
            index = 2;
            cout << "\n***********";
            cout << "\n(AC->A)\n(Non-AC->N)";
            cout << "*********";
            cout << "\nEnter the code for new room comfort:";
            cin >> newc;
        }
        else if (opt == 3){
            index = 3;
            cout << "\n***********";
            cout << "\n(Single->S)\n(Double->D)";
            cout << "*********";
            cout << "\nEnter the code for new  room capacity:";
            cin >> newc;
        }
        else if(opt == 4){
            index = 5;
            cout << "\nEnter new rent per day: ";
            cin >> newc;
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
  
        room2 = 0;
        int count = 0;
    
     while (!fin.eof()) {
          row.clear();
          getline(fin, line);
          stringstream s(line);
          //cout << s;
          //cout << line;
          while (s.good()) {
              getline(s,word,',');
              row.push_back(word);
              //cout << row[0] << " ";
          }
          //cout << row.size();
         if(row.size()>1){
          room2 = stoi(row[0]);
          if (room2 == roomnumber) {
              count = 1;
              row[index] = newc;
              for(int i=0; i<5; i++){
                  fout << row[i] << ",";
              }
              fout << row[5];
              fout << "\n";
          } else{
              for(int i=0; i<5; i++){
                  fout << row[i] << ",";
                  //mfout << row[row_size-1] << "\n";
              }
              fout << row[5];
              fout << "\n";
          }
             
         }
      }
  
    fin.close();
    fout.close();
  
    remove("HotelRooms.csv");
    rename("HotelRoomsnew.csv", "HotelRooms.csv");
    
    cout << "\nData modified successfully.";
    cout << "\nPress any key to continue: ";
    cin.ignore();
    cin.get();
    hm.mainMenu();
}
 
void Room::searchRoom(int roomnumber){
   fstream fin;
    hotelManager hm;
      fin.open("HotelRooms.csv", ios::in);
      int room2 = 0, count = 0;
      vector<string> row;
      string line, word, temp;
    
     while (!fin.eof()) {
          row.clear();
          getline(fin, line);
          stringstream s(line);
          //cout << s;
          //cout << line;
          while (s.good()) {
              getline(s,word,',');
              row.push_back(word);
              //cout << row[0] << " ";
          }
          //cout << row.size();
         if(row.size()>1){
          room2 = stoi(row[0]);
          if (room2 == roomnumber) {
              count = 1;
              break;
          }
         }
      }
  
        if (room2 == roomnumber) {
            displayRoom(roomnumber);
            modifyRoom(roomnumber);
        }
        else{
            cout << "\nRoom not found.";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            hm.manageRooms();
        }
    fin.close();
}
