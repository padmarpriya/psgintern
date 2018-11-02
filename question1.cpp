#include<iostream>
#include<map>
#include<iterator>
#include<sstream>
using namespace std;


// strtoint function is used to convert the string to int and the return the converted int value
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

    /*checking whether the given string is present in the wordMap or not
    if present return the value of that matched key in the wordMap*/
    for(itr=wordMap.begin();itr!=wordMap.end();itr++){
        if(itr->first==input){
            return itr->second;
        }
    }
    int i=0,count=0;

    // if string not present in the wordMap then checking whether the given string contains numerical character or not
    while(i!=input.length()&&input[i]>47&&input[i]<58){
            i++;
            count++;
    }
    /* if string contains the numerical character then multiply the string and charOffset
    by converting the string into integer then converting the multiplied value into string and returning the string */
    if(count==input.length()){
        int val=strtoint(input)*charOffset;
        stringstream s;
        s<<val;
        return s.str();
    }

    /* if the above two cases fails then converting the string by adding the charOffset to every char ascii in the string
    and returning the string */
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

