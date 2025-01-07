void solve(string &pat, int m, vector<int> &LPS)
    {
        int i = 1;
        
        int length = 0;
        
        while(i < m)
        {
            if(pat[i] == pat[length])
            {
                length++;
                
                LPS[i] = length;
                
                i++;
            }
            
            else
            {
                if(length == 0)
                {
                    LPS[i] = 0;
                    
                    i++;
                }
                
                else
                {
                    length = LPS[length-1];
                }
            }
        }
    }
  
    vector<int> search(string& pat, string& txt) 
    {
        int m = pat.length();
        
        int n = txt.length();
        
        vector<int> ans;
        
        vector<int> LPS(m,0);
        
        solve(pat,m,LPS);
        
        int i = 0, j = 0;
        
        while(i < n)
        {
            if(j == m)
            {
                ans.push_back(i-m);
                
                j = LPS[j-1];
            }
            
            else if(txt[i] == pat[j])
            {
                i++;
                
                j++;
            }
            
            else
            {
                if(j-1 < 0)
                {
                    i++;
                }
                
                else
                {
                    j = LPS[j-1];
                }
            }
        }
        
        if(j == m)
        {
            ans.push_back(i-m);
        }
        
        return ans;
    }
