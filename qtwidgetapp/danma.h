#ifndef CONDITION_DANMA_H
#define CONDITION_DANMA_H
#include "condition.h"
class danma:condition{

public:
    danma(list<string>& zs,string& dm);
    void filter();
    condition* reverse();
};

#endif // CONDITION_DANMA_H
