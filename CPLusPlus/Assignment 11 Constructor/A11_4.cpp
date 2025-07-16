#include<iostream>
#include<string.h>
using namespace std;

/*
A11.4 Define a class Room for a hotel management project with room number,
room type, is_AC, price as instance variables. Initialise instance variables
using constructor.
(Completed)
*/
class Room
{
    private:
        int roomNumber;
        char roomType[50];
        bool is_AC;
        float price;
    public:
        Room(int roomNum, const char rType[], bool isAC, float pricing)
        {
            roomNumber = roomNum;
            strcpy(roomType, rType);
            is_AC = isAC;
            price = pricing;
        }
        void showRoomDetails()
        {
            cout<<"Room Number: "<<roomNumber<<", Room Type: "<<roomType<<", is_AC: "<<is_AC<<", price: "<<price<<endl;
        }
};



int main()
{
    Room r1(1, "1BHK", false, 5000), r2(2, "2BHK", true, 15000.5);
    r1.showRoomDetails();
    r2.showRoomDetails();
    return 0;
}