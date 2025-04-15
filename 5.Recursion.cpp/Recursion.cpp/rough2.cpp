#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "amkabcka";
    string pattern = "abc";
    bool match = false;
    int idx = -1;
    for(int i = 0;i<str.length();i++){
        if(pattern[0] == str[i]){
            match = true;
            idx = i;
            for(int j = 1;j<pattern.length() and i<str.length();j++){
                if(pattern[j] != str[i+j]) {
                    match = false;
                    break;
                }
            }
        if(match) break;
        }
    }
    (match)? (cout<<"Pattern Found at index "<<idx) : (cout<<"Pattern not found!");
    return 0;
}