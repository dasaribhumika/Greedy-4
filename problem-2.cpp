// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/

// Time Complexity: O(n) 
// Space Complexity: O(1)

class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            unordered_map<int,int> mp;
            int target = 1;
            for(int i=0; i<tops.size(); i++){
                mp[tops[i]]++;
                if(mp[tops[i]] >= tops.size()){
                    target = tops[i];
                    break;
                }
            }
            for(int i=0; i<bottoms.size(); i++){
                mp[bottoms[i]]++;
                if(mp[bottoms[i]] >= bottoms.size()){
                    target = bottoms[i];
                    break;
                }
            }
            int aRot=0;int bRot=0;
            for(int i=0; i<tops.size(); i++){
                int top = tops[i]; int bottom = bottoms[i];
                if(top != target && bottom != target) return -1;
                if(top != target) aRot++;
                if(bottom != target) bRot++;
            }
            return min(aRot, bRot);
        }
    };

// Processing pairs
// Time Complexity: O(n) 
// Space Complexity: O(1)

class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
           int a = tops[0];
           int res = check(tops,bottoms, a);
           if(res != -1) return res;
           int b = bottoms[0];
           return check(tops,bottoms, b);
        }
        int check(vector<int>& tops, vector<int>& bottoms, int target){
            int aRot=0;int bRot=0;
            for(int i=0; i<tops.size(); i++){
                int top = tops[i]; int bottom = bottoms[i];
                if(top != target && bottom != target) return -1;
                if(top != target) aRot++;
                if(bottom != target) bRot++;
            }
            return min(aRot, bRot);
        }
    };