#pragma once

class IEmail
{
private:
    /* data */
public:
    IEmail(/* args */) = default;
    virtual ~IEmail() = default;
    virtual void sendTicketByEmail() = 0;
};