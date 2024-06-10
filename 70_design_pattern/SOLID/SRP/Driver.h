#pragma once
#include <iostream>

class Driver
{
private:
    /* data */
    std::string lastName;
    std::string firstName;
public:
    Driver(/* args */);
    Driver(std::string _firstName, std::string _lastName) : lastName(_lastName), firstName(_firstName) {}
    ~Driver();
};

Driver::Driver(/* args */)
{
}

Driver::~Driver()
{
}
