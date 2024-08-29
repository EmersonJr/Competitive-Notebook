// LCS com recuperação da string que dá a maior substring comum entre S e T

void recover(int i, int j){ 
     if (i>=s_size || j>=t_size) return ; 
     if (s[i]==t[j]){ans.push_back(s[i]);recover(i+1, j+1);} 
     else if(lcs_size[i+1][j]>lcs_size[i][j+1]) return recover(i+1, j); 
     else return recover(i, j+1); 
  
 } 
  
 int main(){ 
     cin >> s >> t; 
     s_size = s.size(); 
     t_size = t.size(); 
  
  
     for(int i=s_size-1; i>=0; i--){ 
         for(int j =t_size-1;j>=0; j--){ 
             if(s[i]==t[j]) lcs_size[i][j] = 1+lcs_size[i+1][j+1]; 
             else lcs_size[i][j] = max(lcs_size[i+1][j], lcs_size[i][j+1]); 
         } 
     } 
  
     
     recover(0,0); 
  
     cout << ans << endl; 
  
 }
