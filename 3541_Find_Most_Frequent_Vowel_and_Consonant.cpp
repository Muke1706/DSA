#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool isVowel(char ch) {
        string vowels = "aeiou";
        for(char k : vowels) {
            if(ch == k) return true;
        }
        return false;
    }

    int maxFreqSum(string s) {
        int n = s.size();
        string v = "";
        string c = "";
        for(int i = 0 ; i < n ; i++){
            if(isVowel(s[i]) == true) v += s[i];
            else c += s[i];
        }
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;
        for(int i = 0 ; i < v.size() ; i++){
            mpp1[v[i]]++;
        }
        for(int i = 0 ; i < c.size() ; i++){
            mpp2[c[i]]++;
        }
        int f = 0 , g = 0;
        for(auto &p : mpp1){   // iterate over map
            f = max(f, p.second);
        }
        for(auto &p : mpp2){
            g = max(g, p.second);
        }
        return (g+f);
    }
};