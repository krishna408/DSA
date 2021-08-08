class Solution {
public:
    string minWindow(string s, string t) {
        map<int,int> mp1,mp2;
        
        for(char c:t)
            mp2[c]++;
        int rmcnt=t.size();
        int mcnt=0,i=0,j=0;
        string ans="";
        
        while(true){
            bool f1=0,f2=0;
            //aquire 
            while(i<s.length()&&rmcnt>mcnt){
                mp1[s[i]]++;
                if(mp1[s[i]]<=mp2[s[i]])
                    mcnt++;
                f1=1;
                i++;
            }
            //get ans
        
            while(j<i&&rmcnt==mcnt){
                string temp=s.substr(j,i-j);
                if(ans==""||ans.size()>temp.size())
                    ans=temp;
                mp1[s[j]]--;
                if(mp1[s[j]]<mp2[s[j]])
                    mcnt--;
                j++;
                f2=1;
            }
            
            if(f1==0&&f2==0)
                break;
        }
        
        return ans;
    }
};
