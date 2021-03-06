#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
   
// T := [T][T]... | num 
   
int solve(string const &s, int &i){
    vector<int> v;
    if(isdigit(s[i])){
        int num = 0;
        while(isdigit(s[i])){
            num = num*10 + s[i]-'0';
            i++;
        }
        return (num + 1) / 2;
    }
    while(s[i] == '['){
        i++; // [
        v.push_back(solve(s,i));
        i++; // ]
    }
   
    sort(all(v));
    int n = v.size(), sum = 0;
    rep(k,(n+1)/2){
        sum += v[k];
    }
    return sum;
}
   
int main(void){
    int T;
    cin >> T;
    rep(_, T){
        string s;
        cin >> s;
        int index = 0;
        cout << solve(s, index) << endl;
    }
    return 0;
}
