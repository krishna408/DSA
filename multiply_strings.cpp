class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> res;
        
        if(num1=="0"||num2=="0")
            return "0";
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int add0=0;
        for(char c1:num1){
            string temp="";
            int carry=0;
            for(int i=0;i<add0;i++)
                temp.push_back('0');
            
              for(char c2:num2){
               int mul=((c1-'0')*(c2-'0')+carry);
               carry=mul/10;
               temp.push_back((mul%10+'0'));                   
              }
            
            if(carry>0)
                temp.push_back((carry+'0'));
            
            res.push_back(temp);    
            add0++;
          }
        
        int sz=res.size(),cr=0;
        string ans="";
        for(int i=0;i<res[sz-1].size();i++){
            int k=0;
            for(int j=res.size()-1;j>=0;j--){
                k+=i<res[j].size()?(res[j][i]-'0'):0;       
            }
            
            int p=k+cr;
            cr=p/10;
            
            ans.push_back((p%10+'0'));
                
        }
        if(cr>0)
            ans.push_back((cr+'0'));
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
