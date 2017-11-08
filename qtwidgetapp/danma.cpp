#include "danma.h"
#include "utils.h"
#include <iostream>

danma::danma(list<string>& zs,string& dm):condition(zs,dm){

}

void danma::filter(){
    list<string>::iterator it=mSource.begin();
    while(it!=mSource.end()){
        bool valid=false;

        for(string::size_type i=0;i<mInput.size();i++){
            if(it->find(mInput[i])!=string::npos){
                valid=true;
                break;
            }
        }

        if(!valid){
            cout<<"erase:"<<*it<<endl;
            it=mSource.erase(it);

        }else{
            ++it;
        }
    }
}

condition* danma::reverse(){

    string reverse_number=get_reverse_number(mInput);
    return new danma(mSource,reverse_number);
}
