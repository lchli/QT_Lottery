#ifndef HEWEI_H
#define HEWEI_H
#include "condition.h"

class hewei:public condition
{
public:
    hewei(list<string>& zs,string& input);
    void filter();
    condition* reverse();
};

#endif // HEWEI_H
