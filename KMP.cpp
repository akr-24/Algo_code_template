  #include<bits/stdc++.h>
  using namespace std;
  
  
    void make(string &pattern,vector<int>&lps){
        
        lps[0]=0;
        int np = pattern.size();
        
        int len = 0;//the length of the previous longest prefix suffix
        for(int i=1;i<np;i++){
            
            if(pattern[i]!=pattern[len]){
               while(len!=0 && pattern[len]!=pattern[i]){
                    len=lps[len-1];
                }
            }
            
            if(pattern[i]==pattern[len])
                len+=1;
            
            
            lps[i]=len;
                        
        }  
        
        
    }
    
    int kmp(string &text,string &pattern,vector<int>&lps){
        
        //int cnt = 0;       
        
        int nt = text.size(),np = pattern.size();
        
        int j=0;

        for(int i=0;i<nt;i++){
            if(text[i]!=pattern[j]){
                while(j!=0 && text[i]!=pattern[j]){
                    j=lps[j-1];
                }
            }
            if(text[i]==pattern[j])
                 j+=1;
            
            if(j==np){
                return (i-j+1);
              //cnt++;
              //j = lps[j-1];
            }
        }
        
        //return cnt;
        return -1;
        
    }
