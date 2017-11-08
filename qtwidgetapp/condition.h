#ifndef FILTER_CONDITION_H
#define FILTER_CONDITION_H
#include <string>
#include <list>
using namespace std;

class condition{
protected:
    list<string>& mSource;
    string& mInput;

public:

    condition(list<string>& zs,string& dm);

   virtual void filter()=0;

    virtual condition* reverse()=0;
};


#endif // FILTER_CONDITION_H
