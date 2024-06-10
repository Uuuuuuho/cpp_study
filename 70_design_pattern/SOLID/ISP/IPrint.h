#pragma once

class IPrint
{
private:
    /* data */
public:
    IPrint(/* args */);
    virtual ~IPrint();
    virtual void print_ticket() = 0;
};
