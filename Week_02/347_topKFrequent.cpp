class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int,int> num_map;
        for(auto i : nums) num_map[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
        for (auto i :num_map) {
            if(qu.size()<k) {
                qu.push(make_pair(i.second,i.first));
            }
            else {
                if(i.second>qu.top().first) {
                    qu.pop();
                    qu.push(make_pair(i.second,i.first));
                }
            }
        }
        while(!qu.empty()) {
            ret.push_back(qu.top().second);
            qu.pop();
        }
        return ret;
    }
};
