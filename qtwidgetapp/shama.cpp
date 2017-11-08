#include "shama.h"
#include <iostream>
#include "danma.h"

shama::shama(list<string>& zs,string& dm):condition(zs,dm){

}

void shama::filter(){
    list<string>::iterator it=mSource.begin();
    while(it!=mSource.end()){
        bool valid=true;

        for(string::size_type i=0;i<mInput.size();i++){
            if(it->find(mInput[i])!=string::npos){
                valid=false;
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

condition* shama::reverse(){

    return new danma(mSource,mInput);
}
