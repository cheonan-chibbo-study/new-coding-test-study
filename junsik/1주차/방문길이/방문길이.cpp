#include <string>
#include <set>

using namespace std;

int solution(string dirs) {
    int count = 0;
    int x = 0;
    int y = 0;
    
    set<string> visited;
    
    for(char dir : dirs){
        int nx = x;
        int ny = y;
        
        switch(dir){
            case 'U':
                ny++;
                break;
            case 'D':
                ny--;
                break;
            case 'L':
                nx--;
                break;
            case 'R':
                nx++;
                break;
        }
        
        if(ny > 5 || ny < -5 || nx > 5 || nx < -5){
            continue;
        }
        
        string path1 = to_string(x) + "," + to_string(y) + " " + 
            to_string(nx) + "," + to_string(ny);
        string path2 = to_string(nx) + "," + to_string(ny) + " " +
            to_string(x) + "," + to_string(y);
        
        if(visited.find(path1) == visited.end()){
            count++;
            visited.insert(path1);
            visited.insert(path2);
        }
        
        x = nx;
        y = ny;
    }
    return count;
}