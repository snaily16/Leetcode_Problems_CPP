// Leetcode Problem 3
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


#include<iostream>
#include<string>
#include<map>
using namespace std;

int lengthOfLongestSubstring(string s);
int main(){
   
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        string s;
        getline(cin, s);
        cout<<s<<" "<<lengthOfLongestSubstring(s)<<endl;
    }
}

int max(int a, int b){
    if(a>=b) return a;
    return b;
}

int lengthOfLongestSubstring(string s){
    map<char, int> set;
    int i, repeat, maxL=0, tempL=0, pos=0;
    char key;
    for(i=0; i<s.length(); i++){
        key = s[i];
        if (set.find(key) == set.end()){
            tempL++;
            set[key]=i;
        }
        else{
            maxL = max(maxL, tempL);
            repeat = set[key];
            for(int j=pos; j<repeat; j++)
                set.erase(s[j]);
            set[key]=i;
            pos = repeat+1;
            tempL = i-repeat;
        }
    }
    maxL = max(maxL, tempL);
    return maxL;
}
