class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> strMap;
        for (int i = 0; i < strs.size(); ++i) {
        	string temp = strs[i];
        	sort(temp.begin(), temp.end());
        	strMap[temp].push_back(strs[i]);
        }
        vector<vector<string>> group;
        map<string, vector<string>>::iterator it = strMap.begin();
        for (; it != strMap.end(); ++it) {
        	sort((it->second).begin(), (it->second).end());
        	group.push_back(it->second);
        }
        return group;
    }
};