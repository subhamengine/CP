problem:- https://www.codechef.com/submit/INCREAST
solution:-
#include <bits/stdc++.h>
using namespace std;
void solve(){
     string s;
     cin>>s;
     string p = s;
     sort(p.begin(),p.end());
     if(s == p){
       cout<<s<<endl;
       return;
     }
     vector<int>fre(26,0);
     for(char ch:s){
       fre[ch-'a']++;
     }
     string preffix="",subs = "",suffix = s;
     int index = 0;
     string ans = s;
     while(index < 26){
       if(fre[index] == 0){
         index++;
         continue;
       }
       int i = 0;
       while(i < (int)suffix.size() and fre[index] > 0){
         if(suffix[i] - 'a' == index){
           preffix+=suffix[i];
         }
         else{
           subs+=suffix[i];
         }
         fre[suffix[i] - 'a']--;
         i++;
       }
       suffix = suffix.substr(i);
       ans = min(preffix+subs+suffix , ans);
     }
     cout<<ans<<endl;
}
int main() 
{
   int t;
   cin>>t;
   while(t--){
       solve();
   }
    return 0;
}
