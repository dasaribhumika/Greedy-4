// https://leetcode.com/problems/shortest-way-to-form-string/description/

// Time Complexity: O(n*m) n is the length of the source and m is the length of the target
// Space Complexity: O(1)


class Solution {
    public:
        int shortestWay(string source, string target) {
            unordered_set<char> st;
            for(int i=0; i<source.size(); i++){
                st.insert(source[i]);
            }
            int cnt=1;
            int sp = 0; int tp = 0;
            while(tp < target.size()){
                if(st.find(target[tp]) == st.end()) return -1;
                if(source[sp] == target[tp]){
                    sp++;
                    tp++;
                    if(tp == target.size()) return cnt;
                }
                else sp++;
                
                if(sp == source.size()){
                    sp=0;
                    cnt++;
                }
            }
            return cnt;
        }
    };

// Binary Search 
// Time Complexity: O(m*log n) 
// Space Complexity: O(n)


class Solution {
    public:
        int shortestWay(string source, string target) {
            unordered_map<char, vector<int>> mp;
            for(int i=0; i<source.size(); i++){
                mp[source[i]].push_back(i);
            }
            int cnt=1;
            int sp = 0; int tp=0;
            while(tp<target.size()){
                if(mp.find(target[tp]) == mp.end()) return -1;
                vector<int> ans = mp[target[tp]];
                auto it = lower_bound(ans.begin(), ans.end(), sp);
                if(it == ans.end()){
                    sp = 0;
                    cnt++;
                }
                else{
                    sp = *it+1;
                    tp++;
                }
            }
            return cnt;
        }
    };