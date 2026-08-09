// Last updated: 8/9/2026, 12:34:40 PM
class TimeMap {
public:
    TimeMap() {
        
    }
    
    unordered_map<string, vector<pair<int, string>>> mp;

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) {
            return "";
        }

        const vector<pair<int, string>> &curr = mp[key];

        int st = 0;
        int end = curr.size()-1;
        string ans = "";

        while(st <= end) {
            int mid = st + (end-st)/2;

            if(curr[mid].first == timestamp) {
                ans = curr[mid].second;
                break;
            }

            if(curr[mid].first > timestamp) {
                end = mid - 1;
            } else {
                ans = curr[mid].second;
                st = mid + 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */