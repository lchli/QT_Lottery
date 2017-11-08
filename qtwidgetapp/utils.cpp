#include "utils.h"
#include <sstream>

string get_reverse_number(string& numbers){
    string ret;
    for(int i=0;i<10;i++){
        char strI;
        stringstream ss;
        ss<<i;
        ss>>strI;

        if(numbers.find(strI)==string::npos){
            ret+=strI;
        }
    }

    return ret;
}
