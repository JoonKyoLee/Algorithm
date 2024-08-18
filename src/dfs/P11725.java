/***
 * silver2
 * 트리의 부모 찾기(11725)
 * 루트 없는 트리가 주어지며, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램 작성
 * 1. 첫째 줄에는 노드의 개수 N이 주어짐
 * 2. 둘째 줄부터 N - 1개의 줄에 트리 상에서 연결된 두 정점이 주어짐
 * 3. 출력할 때는 2번 노드의 부모 노드부터 출력함
 */

package dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class P11725 {
    static int N;
    static int[] parent;
    static boolean[] isVisited;
    static ArrayList<ArrayList<Integer>> list;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        parent = new int[N + 1];
        isVisited = new boolean[N + 1];
        list = new ArrayList<>();

        for (int i = 0; i <= N; i++) { // 리스트 초기화
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken());
            int second = Integer.parseInt(st.nextToken());

            // 연결된 노드의 번호를 저장
            list.get(first).add(second);
            list.get(second).add(first);
        }

        // 루트 노드가 1이기 때문에 1을 넣어 dfs 실행
        dfs(1);

        for (int i = 2; i < parent.length; i++) {
            System.out.println(parent[i]);
        }
    }

    static void dfs(int n) {
        isVisited[n] = true;

        // 현재 노드와 연결된 노드 확인
        for (int v : list.get(n)) {
            if (!isVisited[v]) {
                dfs(v);
                parent[v] = n;
            }
        }
    }
}
