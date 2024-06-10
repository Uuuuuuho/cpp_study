#pragma once
#include "IView.h"
#include <iostream>

class View : public IView
{
public:
    View() = default;
    ~View() = default;
    void display() override { std::cout << "Hellow World" << std::endl; }
};