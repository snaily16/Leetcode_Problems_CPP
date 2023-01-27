// Leetcode Problem 5
// https://leetcode.com/problems/longest-palindromic-substring

#include<iostream>
#include<string>

using namespace std;

string longestPalandromicString(string s);

int main(){
    int testcases;
    cin>>testcases;

    while(testcases--){
        string s;
        getline(cin, s);
        cout<<s<<" --> "<<longestPalandromicString(s)<<endl;
    }
}
string longestPalandromicString(string A){
    int maxLength = 1;
    int right, left, palandromic_length, start = 0;
    int n = A.length();
    
    for(int i=0; i<n; i++){
        right = i;

        while(right < n && A[right] == A[i])
            right++;
        left = i-1;
        while(left >= 0 && right < n && A[right] == A[left]){
            left--;
            right++;
        }

        palandromic_length = right - left - 1;
        if(palandromic_length > maxLength){
            maxLength = palandromic_length;
            start = left + 1;
        }
    }
    //cout<<start<<" "<<maxLength<<" ";
    return A.substr(start, maxLength);
}

