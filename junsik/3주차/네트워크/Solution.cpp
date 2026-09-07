#include <string>
#include <vector>

using namespace std;

void DFS(int cur, vector<bool> &visited, vector<vector<int>> computers){
    visited[cur] = true;
        
        for(int i = 0; i < computers.size(); i++){
            if(computers[cur][i] == 1 && !visited[i]){
                DFS(i,visited,computers);
            }
        }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited (n, false);
    
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            DFS(i,visited,computers);
            answer++;
        }
    }
    return answer;
}