#pragma once   
#include "Vehicle.h"

class Airplane : public Vehicle
{
private:
    /* data */
public:
    Airplane(/* args */);
    ~Airplane();
    int getID() override;
    int getHeight();
};

Airplane::Airplane(/* args */)
{
}

Airplane::~Airplane()
{
}
