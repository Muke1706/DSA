#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }

    string consonantPattern(string w) {
        string res = "";
        for (char c : w) {
            if (isVowel(c)) res.push_back('*');
            else res.push_back(tolower(c));
        }
        return res;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());

        unordered_map<string,string> caseInsensitive;
        unordered_map<string,string> consonantInsensitive;

        for (string w : wordlist) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = w;

            string pattern = consonantPattern(lower);
            if (!consonantInsensitive.count(pattern))
                consonantInsensitive[pattern] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
                continue;
            }

            string pattern = consonantPattern(lower);
            if (consonantInsensitive.count(pattern)) {
                ans.push_back(consonantInsensitive[pattern]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};