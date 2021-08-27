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

int main(){
    hotelManager hm;
    fstream fout;
    fout.open("HotelRooms.csv", ios::out | ios::app);
    fout.close();
    hm.mainMenu();
    return 0;
}
