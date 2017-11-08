#ifndef KUADU_H
#define KUADU_H
#include "condition.h"

class kuadu:public condition
{
public:
    kuadu(list<string>& zs,string& input);
    void filter();
    condition* reverse();
};

#endif // KUADU_H
