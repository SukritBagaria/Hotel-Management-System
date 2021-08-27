#ifndef  ROOM_H
#define ROOM_H

#include "Customer.h"

using namespace std;

class Room
{
    public:
    int rno;
    char roomtype;
    char comfort;
    char capacity;
    int status;
    int rent_per_day;
    
    Customer cust;
    void addRoom(int);
    void searchRoom(int);
    void modifyRoom(int);
    void displayRoom(int);
};

#endif // ROOM_H
