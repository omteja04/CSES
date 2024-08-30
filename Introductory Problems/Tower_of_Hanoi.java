import java.util.ArrayList;
import java.util.Scanner;

class Pair<U, V> {
    public final U first;
    public final V second;

    Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
}

public class Tower_of_Hanoi {

    static void towerOfHanoi(int n, int source, int helper, int destination, ArrayList<Pair<Integer, Integer>> arr) {
        if (n == 0) {
            return;
        }
        towerOfHanoi(n - 1, source, destination, helper, arr);
        arr.add(new Pair<>(source, destination));
        towerOfHanoi(n - 1, helper, source, destination, arr);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        ArrayList<Pair<Integer, Integer>> ans = new ArrayList<>();
        towerOfHanoi(n, 1, 2, 3, ans);

        sc.close();
        int size = ans.size();
        System.out.println(size);

        for (Pair<Integer, Integer> pair : ans) {
            System.out.println(pair.first + " " + pair.second);
        }

    }
}
