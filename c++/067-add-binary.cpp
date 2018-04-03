/*
 * 利用好下标，不造成多余的内存开销
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int flag = 0;
        string& longer = a.size() > b.size() ? a : b;
        string& shorter = a.size() > b.size() ? b : a;
        int i = longer.size()-1, j = shorter.size()-1;
        while (i >= 0 && j >= 0) {
        	longer[i] = (longer[i]-'0')+(shorter[j]-'0');
        	if (i-1 < 0) {
        		flag = longer[i]/2;
        	} else {
        		longer[i-1] += longer[i]/2;
        	}
        	longer[i] = longer[i]%2+'0';
        	--i, --j;
        }
        while (i >= 0) {
        	if (i-1 < 0) {
        		flag = (longer[i]-'0')/2;
        	} else {
        		longer[i-1] += (longer[i]-'0')/2;
        	}
        	longer[i] = (longer[i]-'0')%2+'0';
        	--i;
        }
        return (flag ? "1"+longer : longer);
    }
};
