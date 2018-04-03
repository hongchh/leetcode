/*
 * 测试会有1.0.0.1等情况
   还会有比较1.0和1这种
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        deque<int> ver1, ver2;
        ver1.push_back(0);
        ver2.push_back(0);
        for (int i = 0, j = 0; i < version1.size(); ++i) {
        	if (version1[i] == '.') {
        		++j;
        		ver1.push_back(0);
        		continue;
        	}
        	ver1[j] = ver1[j]*10 + (version1[i]-'0');
        }
        while (ver1.size() > 1 && ver1[ver1.size()-1] == 0) {
        	ver1.pop_back();
        }
        for (int i = 0, j = 0; i < version2.size(); ++i) {
        	if (version2[i] == '.') {
        		++j;
        		ver2.push_back(0);
        		continue;
        	}
        	ver2[j] = ver2[j]*10 + (version2[i]-'0');
        }
        while (ver2.size() > 1 && ver2[ver2.size()-1] == 0) {
        	ver2.pop_back();
        }
        for (int i = 0; i < ver1.size() && i < ver2.size(); ++i) {
        	if (ver1[i] < ver2[i]) return -1;
        	if (ver1[i] > ver2[i]) return 1;
        }
        if (ver1.size() == ver2.size()) return 0;
        return ver1.size() < ver2.size() ? -1 : 1;
    }
};
