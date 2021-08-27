#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include "Customer.h"

using namespace std;

class Room
{
    public:
    string roomtype;
    string comfort;
    string capacity;
    int status;
    int rent_per_day;

    Customer cust;
    void addRoom(int);
    void searchRoom(int);
    void modifyRoom(int);
    void displayRoom(int);
};

#endif // ROOM_H_INCLUDED

