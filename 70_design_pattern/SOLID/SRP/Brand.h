#pragma once
#include <iostream>

class Brand
{
    friend class Model;
    std::string brandName;
public:
    Brand(std::string name) : brandName(name) {}
    ~Brand();
};