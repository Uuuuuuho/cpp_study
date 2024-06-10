#pragma once
class Vehicle
{
private:
    /* data */
protected:
    int power;
    int vehicleID;
public:
    Vehicle(/* args */) = default;
    Vehicle(int _power, int _id) : power(_power), vehicleID(_id) {}
    virtual ~Vehicle() = default;
    virtual int getID() = 0;
};

