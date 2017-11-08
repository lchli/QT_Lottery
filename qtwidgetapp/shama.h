#ifndef SHAMA_H
#define SHAMA_H
#include "condition.h"

class shama:public condition
{
public:
    shama(list<string>& zs,string& input);
    void filter();
    condition* reverse();
};

#endif // SHAMA_H
