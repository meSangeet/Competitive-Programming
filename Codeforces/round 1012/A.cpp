class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        //looks like simple BFS idk
        //but the constraints are large so definitely not brute force DFS.
        //smaller queries will definitely be a subset of larger queries
        vector<pair<int,int>> que;
        for(int i = 0; i<queries.size(); i++){
            que.push_back({queries[i], i});
        }
        sort(que.begin(), que.end());

        int count = 0;
        vector<int> tempAns;

        //let's sort the visited cells in ascending order
        int mx = grid.size();
        int my = grid[0].size();
        vector<vector<bool>> vis(mx, vector<bool> (my, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        for(auto q : que){
            int no = que.first();
            while(!pq.empty() and pq.top[0] < no){
                count++;
                auto to = pq.top();
                pq.pop();
                int x = to[1];
                int y = to[2];
                
            }
        }
    }
};