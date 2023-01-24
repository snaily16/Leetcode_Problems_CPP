// Leetcode problem 4
// Median of Two Sorted Array in O(log(m+n))
#include<iostream>
#include<vector>

using namespace std;

double findMedianSortedArray(vector<int>& A, vector<int>& B);
int main(){

    int testcases;
    cin>>testcases;
    while(testcases--){
        int l1, l2, i;
        vector<int> A, B;
        cin>>l1>>l2;
        
        int input;
        for(i=0; i<l1; i++){
            cin>>input;
            A.push_back(input);
        }

        for(i=0; i<l2; i++){
            cin>>input;
            B.push_back(input);
        }

        for(int n:A)   cout<<n<<" ";
        cout<<endl;
        for(int n:B) cout<<n<<" ";
        cout<<endl;
        cout<<"Median: "<<findMedianSortedArray(A,B)<<endl;
    }
}

double findMedianSortedArray(vector<int>& A, vector<int>& B){
    int l1, l2;
    l1 = A.size();
    l2 = B.size();
    bool odd = (l1+l2)%2;
    int i=0, j=0, pos=-1, curr_ele=0;
    int mid = (l1+l2-1)/2;
    while(i<l1 && j<l2){
        if(pos == mid){
            if(odd)
                return curr_ele;
            else{
                if(A[i]<=B[j]) return (A[i]+curr_ele)/2.0;
                return (B[j]+curr_ele)/2.0;
            }
        }
        if(A[i]<=B[j]){
            curr_ele = A[i];
            i++;
        }
        else{
            curr_ele=B[j];
            j++;
        }
        pos++;
    }
    if(pos==mid){
        if(odd) return curr_ele;
        else{
            if(j>=l2 || i<l1 && A[i]<=B[j]) return (A[i]+curr_ele)/2.0;
            return (B[j]+curr_ele)/2.0;
            }
        }
    pos++;

    if(j>=l2 && i<=l1){
        if(odd) return A[i+mid-pos];
        return (A[i+mid-pos]+A[i+mid-pos+1])/2.0;
    }
    if(i>=l1 && j<=l2){
        if(odd) return B[j+mid-pos];
        return (B[j+mid-pos]+B[j+mid-pos+1])/2.0;
    }
    return 0;
}
