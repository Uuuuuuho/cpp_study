#pragma once
#include "IView.h"

class Presenter
{
    IView* view = nullptr;
public:
    Presenter() = default;
    Presenter(IView* newView) : view(newView) {}
    ~Presenter() { delete view; }
    void callInterface() {
        view->display();
    }
};