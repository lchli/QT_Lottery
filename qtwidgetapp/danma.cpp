#include "danma.h"
#include <iostream>
#include "shama.h"

danma::danma(list<string>& zs,string& dm):condition(zs,dm){

}

void danma::filter(){
     cout<<"danma mInput:"<<mInput<<endl;

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
            cout<<"danma erase:"<<*it<<endl;
            it=mSource.erase(it);

        }else{
            ++it;
        }
    }
}

condition* danma::reverse(){

    return new shama(mSource,mInput);
}
