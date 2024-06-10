#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car(int _power, int _id){
        power = _power;
        vehicleID = _id
    }
    ~Car() = default;
    int getId() override;
};