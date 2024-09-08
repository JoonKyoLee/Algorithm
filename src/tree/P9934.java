/**
 * silver1
 * 완전 이진 트리(9934)
 * 1. 첫째 줄에는 레벨이 주어짐
 * 2. 둘째 줄에는 방문한 빌딩의 번호가 순서대로 주어짐
 * 3. 레벨 수에 맞게 정답을 출력
 */

package tree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class P9934 {
    static int level;
    static int[] numbers;
    static ArrayList<Integer>[] buildings;

    /**
     * 중위 순회 방식을 사용(Left -> Root -> Right)
     * 현재 구간에서 가운데에 위치한 빌딩을 현재 레벨에 저장
     * 구간을 나누어 앞 구간을 먼저 확인해서 다음 레벨에 저장하고 뒤의 구간을 확인
     */
    static void makeTree(int start, int end, int currentLevel) {
        int mid = (start + end) / 2;
        buildings[currentLevel].add(numbers[mid]);
        if (currentLevel == level) return;
        makeTree(start, mid - 1, currentLevel + 1);
        makeTree(mid + 1, end, currentLevel + 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        level = Integer.parseInt(br.readLine());
        int size = (int) (Math.pow(2, level) - 1);
        numbers = new int[size + 1];
        buildings = new ArrayList[level + 1];

        for (int i = 0; i <= level; i++) {
            buildings[i] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= size; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        makeTree(1, size, 1);

        for (int i = 1; i <= level; i++) {
            for (int j = 0; j < buildings[i].size(); j++) {
                System.out.print(buildings[i].get(j) + " ");
            }
            System.out.println();
        }
    }
}
