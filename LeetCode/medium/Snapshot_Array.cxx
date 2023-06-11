class SnapshotArray {
    vector<vector<pair<int, int>>> arr;
    vector<int> vals;
    int id = 0;
    set<int> to_update;
public:
    SnapshotArray(int length) {
        arr.resize(length, vector<pair<int, int>>(1, {0, 0}));
        vals.resize(length, 0);

    }
    
    void set(int index, int val) {
        // std::cout << "set" << endl;
        if (arr[index].size() > 0 && arr[index].back().first == id)
            arr[index].back().second = val;
        else
            arr[index].push_back({id, val});
    }

    
    int snap() {
        // std::cout << "snap" << endl;
        
        ++id;
        return id-1;
    }
    
    int get(int index, int snap_id) {
        // std::cout << "get" << endl;
        // for (auto x : arr[index]) {
        //     std::cout << x.first << " " << x.second << " --- " << "\n";
        // }
        // std::cout << "snpadi " << snap_id << endl;

        auto ret = upper_bound(arr[index].begin(), arr[index].end(), snap_id, [](int a, pair<int, int>& b) {
            return a < b.first;
        });
        --ret;
        return (*ret).second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
