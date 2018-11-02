#include<iostream>
#include<map>
#include<iterator>
#include<sstream>
using namespace std;

int strtoint(string str){
    int val=0;
    for(int i=0;i<str.length();i++){
        switch(str[i]){
            case '1':val=(val*10)+1;
            break;
            case '2':val=(val*10)+2;
            break;
            case '3':val=(val*10)+3;
            break;
            case '4':val=(val*10)+4;
            break;
            case '5':val=(val*10)+5;
            break;
            case '6':val=(val*10)+6;
            break;
            case '7':val=(val*10)+7;
            break;
            case '8':val=(val*10)+8;
            break;
            case '9':val=(val*10)+9;
            break;
            default:val=(val*10)+0;
    }
    }
    return val;
}

string obfuscate(string input, int charOffset, map<string, string> wordMap){
    map<string,string>::iterator itr;
    for(itr=wordMap.begin();itr!=wordMap.end();itr++){
        if(itr->first==input){
            return itr->second;
        }
    }
    int i=0,count=0;
    while(i!=input.length()&&input[i]>47&&input[i]<58){
            i++;
            count++;
    }
    if(count==input.length()){
        int val=strtoint(input)*charOffset;
        stringstream s;
        s<<val;
        return s.str();
    }
    for(int i=0;i<input.length();i++)
            input[i]=input[i]+charOffset;
    return input;
}


int main(){
    map<string, string> map1;
    string input;
    map1.insert(pair<string,string>("psgsoftwaresolutions","intern"));
    map1.insert(pair<string,string>("psg","tech"));
    map1.insert(pair<string,string>("psgcas","arts"));
    cin>>input;
    input=obfuscate(input,2,map1);
    cout<<input;
}

