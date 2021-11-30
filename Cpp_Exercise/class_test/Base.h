#ifndef _BASE_H_
#define _BASE_H_

class Base
{
public:
    Base() = default;
    virtual ~Base() = default;
    virtual void Show() = 0;
};

#endif