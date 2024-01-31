#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> indices(vector<int>& v) {
/* Time Complexity: O(N) Since we move from right to left, and the inner while loop stack only visit each temperature of the v vector only once in all the iterations, so it's O(N) time complexity */
        
        int n = v.size();
        vector<int>ans(n); //returning the distances of NGE
        int i=n-1;
        
        stack<pair<int,int>>st; //no need of pair if we need to find the element only 
        ans[i]=0;
        st.push({v[i],n-1});
        
        i-=1;
        
        while(i>=0){
                       
            while(!st.empty() && st.top().first<=v[i]){
                st.pop();
            }
            
            if(st.empty()){
                st.push({v[i],i});
                ans[i]=0;
            }
            else if(st.top().first>v[i]){
                 ans[i]=abs(st.top().second-i);
                 st.push({v[i],i});               
            }
            
            i-=1;
        }
        
        return ans;
    }

}