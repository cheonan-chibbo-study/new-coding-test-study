#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int idx_A = 0;
    int idx_B = 0;
    
    sort(A.begin(),A.end(),less<int>());
    sort(B.begin(),B.end(),less<int>());
    
    for(int i = 0; i<B.size(); i++){
        if(B[idx_B] > A[idx_A]){
            answer++;
            idx_A++;
            idx_B++;
        }
        else{
            idx_B++;
        }
    }
    
    return answer;
}