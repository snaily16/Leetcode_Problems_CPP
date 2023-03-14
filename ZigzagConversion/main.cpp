#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        string convert(string s, int numRows);
};

int main(){
    string s;
    int rows;
    int testcases;
    cin>>testcases;
    Solution sol;
    while(testcases--){
        cin>>rows;
        cin>>s;
        cout<<s<<" --> "<<sol.convert(s, rows)<<endl;
    }
}

string Solution::convert(string s, int numRows){
    string answer="";
    int jump = 2*numRows - 2;
    int slen = s.size();
    if(jump==0)
        return s;
    int j;
    for(int i=0; i<numRows; i++){
        int sj = 2 * (numRows - i) -2;
        j=i;
        while(j < slen){
            answer = answer + s[j];
            if(i!=0 && sj!=0 && (j+sj)<slen)
                answer = answer + s[j+sj];
            j = j + jump;
        }
    }
    return answer;
}
