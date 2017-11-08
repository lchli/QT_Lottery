#include "hewei.h"
#include <iostream>
#include "utils.h"
#include <sstream>
hewei::hewei(list<string>& zs,string& dm):condition(zs,dm){

}

void hewei::filter(){
    list<string>::iterator it=mSource.begin();
    while(it!=mSource.end()){
        string& item=*it;
        int hezhi=0;
        for(string::size_type j=0;j<item.size();j++){
            int num=item[j]-'0';
            hezhi+=num;
        }
        int hewei=hezhi%10;
        cout<<"item:"<<item<<",hewei:"<<hewei<<endl;

        char hewei_str;
        stringstream ss;
        ss<<hewei;
        ss>>hewei_str;

        if(mInput.find(hewei_str)==string::npos){
            cout<<"erase:"<<item<<endl;
            it=mSource.erase(it);

        }else{
            ++it;
        }
    }
}

condition* hewei::reverse(){

    string s=get_reverse_number(mInput);
    return new hewei(mSource,s);
}
