package brackets;

import java.util.Scanner;
import java.util.Stack;

/**
 *
 * @author Андрей
 */
public class Brackets {

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        Scanner in = new Scanner(System.in);
        char[] l = in.next().toCharArray();
        boolean yes = true;
        for (int i = 0; i < l.length; i++) {
            if (l[i] == '(') {
                s.add(1);
            } else if (l[i] == ')') {
                if (!s.isEmpty()) {
                    s.pop();
                } else {
                    yes = false;
                }
            }
        }
        if(!s.isEmpty() || !yes)
            System.out.println("NO");
        else
            System.out.println("YES");
    }

}
