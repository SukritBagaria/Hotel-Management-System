#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Room.h"
#include "hotelManager.h"

using namespace std;

void hotelManager::manageRooms(){
    Room room;
    int menu,roomnumber;
    hotelManager hm;
    
        cout << "\n***********";
        cout<<"\n### Manage Rooms ###";
        cout<<"\n1.Add Room\n2.Modify Room\n3.Back to main menu: ";
        cout << "\n***********";
        cout << "\n\nEnter Option: ";
        cin >> menu;
        if(menu == 1){
            cout << "\nEnter Room Number:";
            cin >> roomnumber;
            
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
                    cout << "\nRoom already present";
                    cout << "\nPress any key to continue";
                    cin.ignore();
                    cin.get();
                    manageRooms();
                }
            if(count == 0){
                room.addRoom(roomnumber);
            }
        }
        if(menu==2){
            cout << "\nEnter Room Number:";
            cin >> roomnumber;
            room.searchRoom(roomnumber);
        }
        if(menu==3){
            hm.mainMenu();
        }
        else if(menu!=2 && menu!=3 && menu!=1 ){
            cout << "*********";
            cout << "\nInvalid input!";
            cout << "*********";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            manageRooms();
        }
}

void hotelManager::checkIn(){
    int roomnumber, again;
    cout << "Enter Room Number: ";
    cin >> roomnumber;
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
    if (count == 0){
        cout << "Room not found\n";
        cout << "\nPress any key to continue:";
                cin.ignore();
                cin.get();
                mainMenu();
    }
        
    else{
        if(row[4] == "1"){
            cout << "\nRoom is already booked.";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            cout << "\nPress 1 to go back to main menu\nPress 2 to enter another room no.";
            cin >> again;
            if(again==1){
                mainMenu();
            }
            if(again==2){
                checkIn();
            }
            if(again!=1 || again!=2){
                cout << "\nInvalid input!";
                cout << "\nPress any key to continue:";
                cin.ignore();
                cin.get();
                mainMenu();
            }
        }
        if(row[4]=="0"){
            cout<<"\nEnter Customer Name (First Name): ";
            cin>>cust.firstname;
            cout<<"\nEnter Customer Name (Last Name): ";
            cin>>cust.lastname;
            cout<<"\nEnter Address (only city): ";
            cin>>cust.address;
            cout<<"\nEnter Phone Number(10 digits): ";
            cin >> cust.phone;
            cout<<"\nEnter Advance Payment: ";
            cin>>cust.advance_payment;
            
            fstream mfout;
            mfout.open("Customers.csv", ios::out | ios::app);
              
            mfout << roomnumber << ","
             << cust.firstname << ","
            << cust.lastname << ","
            << cust.address << ","
            << cust.phone << ","
            << cust.advance_payment
            << "\n";

            mfout.close();
            fin.close();
            
            fstream fin, fout;
            fin.open("HotelRooms.csv", ios::in);
            fout.open("HotelRoomsnew.csv", ios::out | ios::app);
            
            while (!fin.eof()) {
            row.clear();
            getline(fin, line);
            stringstream s(line);
            int new_status = 1;
            while (getline(s, word, ',')) {
                 row.push_back(word);
            }
            int room2;
            room2 = stoi(row[0]);
            unsigned long int row_size = row.size();
            if (room2 == roomnumber) {
                stringstream convert;
                convert << new_status;
                row[4] = convert.str();
  
                if (!fin.eof()) {
                    for (int i = 0; i < row_size - 1; i++) {
                        fout << row[i] << ",";
                    }
                fout << row[row_size - 1] << "\n";
                }
            }
            else {
                if (!fin.eof()) {
                    for (int i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ",";
                    }
                fout << row[row_size - 1] << "\n";
                }
        }
            if (fin.eof())
                break;
        }
    fin.close();
    fout.close();
  
    
    remove("HotelRooms.csv");
    rename("HotelRoomsnew.csv", "HotelRooms.csv");
            
            cout << "\nCustomer checked-in successfully.";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            mainMenu();
        }
    }
}

void hotelManager::checkOut(int roomnumber){
    double bill;
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
    fin.close();
    if (count == 0){
        cout << "Room not found\n";
        cout << "\nPress any key to continue:";
        cin.ignore();
        cin.get();
        mainMenu();
    }
    else{
        if(row[4] == "0"){
            cout << "\nNo customer present in roomnumber" << roomnumber;
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            mainMenu();
        }
        else{
            int days;
            cout << "\nEnter no. of days:";
            cin >> days;
            bill=days*stoi(row[5]);
            cout<<"\nTotal Amount : "<<bill<<" /-";
            fstream mfin,mfout;
            mfin.open("Customers.csv", ios::in);
            mfout.open("Customersnew.csv", ios::out);
            int room2a;
            string line, word;
            vector <string> row;
            while(!mfin.eof()){
                row.clear();
                getline(mfin, line);
                stringstream s(line);
                while(s.good()){
                    getline(s,word,',');
                    row.push_back(word);
                }
                unsigned long int row_size = 6;
                if(row.size() > 1){
                room2a = stoi(row[0]);
                if(room2a!=roomnumber){
                    for(int i=0; i<row_size-1; i++){
                        mfout << row[i] << ",";
                        //mfout << row[row_size-1] << "\n";
                    }
                    mfout << row[row_size-1];
                    mfout << "\n";
                }
                else{
                    cout<<"\nAdvance Paid: "<<row[5]<<" /-";
                    cout<<"\n*** Total Payable: "<<bill-stoi(row[5])<<"/- ";
                    cout << "\nPlease wait...";
                }
                if(mfin.eof()){
                    break;
                }
            }
            }
            mfin.close();
            mfout.close();
            remove("Customers.csv");
            rename("Customersnew.csv", "Customers.csv");
            
            
            fstream fin,fout;
            fin.open("HotelRooms.csv", ios::in);
            fout.open("HotelRoomsnew.csv", ios::out | ios::app);
            
            while (!fin.eof()) {
            row.clear();
            getline(fin, line);
            stringstream s(line);
            while (getline(s, word, ',')) {
                row.push_back(word);
            }
             int room2;
            room2 = stoi(row[0]);
            unsigned long int row_size = row.size();
  
            if (room2 == roomnumber) {
            count = 1;
            stringstream convert;
            int newstatus =0;
            convert << newstatus;
            row[4] = convert.str();
  
            if (!fin.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1];
                fout << "\n";
            }
        }
        if (fin.eof())
            break;
        }
        fin.close();
        fout.close();
        remove("HotelRooms.csv");
        rename("HotelRoomsnew.csv","HotelRooms.csv");
        
            cout << "\nChecked out successfully.";
            cout << "\nPress any key to continue:";
            cin.ignore();
            cin.get();
            mainMenu();
        }
    }
}


void hotelManager::getAvailableRooms(){
    
    fstream fin;
    fin.open("HotelRooms.csv", ios::in);
    int roomstatus = 0, status2, count = 0;
    vector<string> row;
    string line, word, temp;
  
    while (!fin.eof()) {
  
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (s.good()) {
            getline(s, word, ',');
            row.push_back(word);
        }
        if(row.size()>1){
        status2 = stoi(row[4]);
        if (status2 == roomstatus) {
            count = 1;
            cout << "\nRoom no. :" << row[0];
            cout << "\nRoom type : " << row[1];
            cout << "\nRoom comfort:" << row[2];
            cout << "\nRoom rent:" << row[5];
        }
    }
    }
    if (count == 0)
        cout << "\nAll rooms are reserved.";
    cout << "\nPress any key to continue:";
    cin.ignore();
    cin.get();
    mainMenu();
}

void hotelManager::searchCustomer(){
    string fname;
    string lname;
    cout << "\nEnter first name of the customer:";
    cin >> fname;
    cout << "\nEnter last name of the customer:";
    cin >> lname;
    
    fstream fin;
    fin.open("Customers.csv", ios::in);
  
    string fname2, lname2;
    int count = 0;
    
    vector<string> row;
    string line, word, temp;
  
    while (!fin.eof()) {
  
        row.clear();
        //cout << line << " ";
        getline(fin, line);
        stringstream s(line);

        while (s.good()) {
            getline(s,word,',');
            row.push_back(word);
        }
        if(row.size()>1){
        fname2 = row[1];
            //cout << fname2 << " ";
        lname2 = row[2];
        }
  
        if (fname2 == fname && lname2 == lname) {
            count = 2;
            cout << "Details of" << row[1] << " " << row[2] << "\n";
            cout << "Stayed in room no.: " << row[0] << "\n";
            cout << "Address: " << row[3] << "\n";
            cout << "Phone Nmber: " << row[4] << "\n";
            cout << "Advance Payment: " << row[5] << "\n";
            break;
        }
    }
    if (count == 0)
        cout << "Customer not found.\n";
        
    cout << "\nPress any key to continue: ";
    cin.ignore();
    cin.get();
    mainMenu();
}

void hotelManager::mainMenu(){
    hotelManager hm;
    cout << "Welcome to Monkey's Island\n" << endl;
    int menu,roomnumber;
    cout << "*********";
    cout << "\n1.Manage Rooms"<< endl << "2.Check-In Room" << endl << "3.Check-out Room" << endl << "4.Search Customer" << endl << "5.Available Rooms" << endl << "6.Exit";
    cout << "*********";
    cout << "\nEnter the corresponding no. to go the menu:";
    cin >> menu;
    switch(menu){
        case 1:
           manageRooms();
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
