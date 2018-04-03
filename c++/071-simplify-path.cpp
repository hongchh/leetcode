class Solution {
public:
    string simplifyPath(string path) {
        list<string> sp;
        path += '/';
        int len = path.size();
        for (int i = 0; i < len; ++i) {
            if (path[i] == '.' && i < len && path[i+1] == '/') {
                continue;
            }
            else if (path[i] == '.' && i < len && path[i+1] == '.' && path[i+2] == '/') {
                if (!sp.empty()) sp.pop_back();
                i += 2;
            }
            else if (path[i] != '/') {
                string name = "";
                while (i < len && path[i] != '/') {
                    name += path[i++];
                }
                sp.push_back(name);
            }
        }
        string simplifiedPath = "";
        for (list<string>::iterator it = sp.begin(); it != sp.end(); ++it) {
            simplifiedPath += '/';
            simplifiedPath += (*it);
        }
        return simplifiedPath.size() ? simplifiedPath : "/";
    }
};