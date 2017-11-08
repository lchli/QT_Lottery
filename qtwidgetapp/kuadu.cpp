#include "kuadu.h"
#include <iostream>
#include "utils.h"
#include <sstream>
kuadu::kuadu(list<string>& zs,string& dm):condition(zs,dm){

}

void kuadu::filter(){
    list<string>::iterator it=mSource.begin();
    while(it!=mSource.end()){
        string& item=*it;

        int min=item[0]-'0';
        int max=item[0]-'0';

        for(string::size_type j=0;j<item.size();j++){
            int num=item[j]-'0';
            if(num>max){
                max=num;
            }else if(num<min){
                min=num;
            }
        }

        int kuadu=max-min;

        cout<<"item:"<<item<<",kuadu:"<<kuadu<<endl;

        char kuadu_str;
        stringstream ss;
        ss<<kuadu;
        ss>>kuadu_str;

        if(mInput.find(kuadu_str)==string::npos){
            cout<<"erase:"<<item<<endl;
            it=mSource.erase(it);

        }else{
            ++it;
        }
    }
}

condition* kuadu::reverse(){

    string s=get_reverse_number(mInput);
    return new kuadu(mSource,s);
}
