/**
 * silver2
 * DFS와 BFS(1260)
 * 1. 첫째 줄에 정점의 개수, 간선의 개수, 탐색을 시작할 정점이 주어짐
 * 2. 둘째 줄부터는 간선이 연결하는 두 정점이 주어짐
 * 3. DFS BFS 순서대로 탐색 후 출력
 * dfs의 경우에는 재귀를 활용해서 구현, bfs는 queue를 활용해서 구현
 */

package graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class P1260 {
    static int N, M, V;
    static List<List<Integer>> graph;
    static boolean[] isVisitedForBFS;
    static boolean[] isVisitedForDFS;
    static Queue<Integer> queue;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());

        isVisitedForBFS = new boolean[N + 1];
        isVisitedForDFS = new boolean[N + 1];
        graph = new ArrayList<>();
        queue = new LinkedList<>();

        for (int i = 0; i < N + 1; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken());
            int second = Integer.parseInt(st.nextToken());
            graph.get(first).add(second);
            graph.get(second).add(first);
        }

        for (List<Integer> adj : graph) {
            Collections.sort(adj);
        }

        dfs(V);
        sb.append("\n");

        bfs(V);

        System.out.println(sb.toString());
    }

    static void dfs(int start) {
        isVisitedForDFS[start] = true;
        sb.append(start).append(" ");

        for (int v : graph.get(start)) {
            if (!isVisitedForDFS[v]) {
                dfs(v);
            }
        }
    }

    static void bfs(int start) {
        queue.add(start);
        isVisitedForBFS[start] = true;
        sb.append(start).append(" ");

        while (!queue.isEmpty()) {
            int current = queue.poll();

            for (int v : graph.get(current)) {
                if (!isVisitedForBFS[v]) {
                    isVisitedForBFS[v] = true;
                    queue.add(v);
                    sb.append(v).append(" ");
                }
            }
        }
    }
}
