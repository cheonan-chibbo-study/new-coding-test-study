#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// BFS로 두 섬이 이미 연결되어 있는지 확인하는 함수
bool isConnected(int start, int end, int n, const vector<vector<int>>& graph) {
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if(cur == end) return true; // 이미 도달 가능하므로 연결되어 있음
        
        for(int next : graph[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int bridge_count = 0;
    
    // 1. 비용 기준 오름차순 정렬
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    
    // 2. 인접 리스트(그래프 지도) 생성
    vector<vector<int>> graph(n);
    
    // 3. 다리를 하나씩 검사하며 그리디 탐색
    for(int i = 0; i < costs.size(); i++) {
        int u = costs[i][0];
        int v = costs[i][1];
        int cost = costs[i][2];
        
        // 두 섬이 이미 연결되어 있다면 사이클이 생기므로 패스
        if(isConnected(u, v, n, graph)) continue;
        
        // 연결 안 되어 있다면 다리 건설
        graph[u].push_back(v);
        graph[v].push_back(u);
        answer += cost;
        bridge_count++;
        
        // 모든 섬이 연결되면 종료 (다리 개수 = 섬 개수 - 1)
        if(bridge_count == n - 1) break;
    }
    
    return answer;
}