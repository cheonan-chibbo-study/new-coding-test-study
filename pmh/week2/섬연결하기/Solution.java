import java.util.*;

class Solution {
    public int solution(int n, int[][] costs) {

        // 인접 리스트
        List<int[]>[] graph = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        // 양방향으로 연결
        for (int[] cost : costs) {
            int a = cost[0];
            int b = cost[1];
            int price = cost[2];

            graph[a].add(new int[]{b, price});
            graph[b].add(new int[]{a, price});
        }

        // 방문 여부
        boolean[] visited = new boolean[n];

        // {연결할 섬, 비용}
        PriorityQueue<int[]> pq =
                new PriorityQueue<>((a, b) -> a[1] - b[1]);

        // 0번 섬에서 시작
        pq.offer(new int[]{0, 0});

        int answer = 0;
        int count = 0;

        while (!pq.isEmpty()) {

            int[] current = pq.poll();

            int node = current[0];
            int price = current[1];

            // 이미 연결된 섬이면 무시
            if (visited[node]) {
                continue;
            }

            // 섬 연결
            visited[node] = true;
            answer += price;
            count++;

            // 현재 섬에서 갈 수 있는 다리 추가
            for (int[] next : graph[node]) {

                int nextNode = next[0];
                int nextPrice = next[1];

                if (!visited[nextNode]) {
                    pq.offer(new int[]{nextNode, nextPrice});
                }
            }
        }

        return answer;
    }
}