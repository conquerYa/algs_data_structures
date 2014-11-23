/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package regexptrain;

import java.util.Scanner;
import java.util.Stack;

/**
 *
 * @author Andrey
 */
public class RegExp {

    public static void main(String[] args) throws Exception {

        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        //System.out.println(countSmiles(str));        
        //System.out.println(divideIntoLexemes(str));]
        //System.out.println(countRevPolish(str));
        System.out.println(toRevPolish(str));
    }

    static int countSmiles(String str) {
        char[] chars = str.toCharArray();
        int auto = 0;
        int res = 0;
        for (char x : chars) {
            if (x == ':' || x == ';') {
                auto = 1;
            } else if (x == '-') {
                auto = auto;
            } else if (x == ')' || x == '(' || x == ']' || x == '[') {
                if (auto == 1) {
                    res++;
                }
                auto = 0;
            } else {
                auto = 0;
            }
        }
        return res;
    }

    private static String divideIntoLexemes(String str) {
        char[] chars = str.toCharArray();
        int auto = 0;
        String res = "";
        for (char x : chars) {
            if (Character.isDigit(x)) {
                res += x;
                auto = 1;
            } else if (x == ' ') {

            } else {
                if (auto == 1) {
                    res += "\n";
                }
                auto = 0;
                res += x + "\n";
            }
        }
        return res;
    }
    private static String countRevPolish(String str) {
        char[] chars = str.toCharArray(); 
        Stack<Integer> nums = new Stack<>();
        for (char x : chars) {
          if(Character.isDigit(x)){
              nums.push(Character.getNumericValue(x)); 
          }else if(x=='+'){
              int a = nums.pop();
              int b = nums.pop();
              nums.push(a+b);
          }else if(x=='-'){
              int a = nums.pop();
              int b = nums.pop();
              nums.push(b-a);
          }else if(x=='*'){
              int a = nums.pop();
              int b = nums.pop();
              nums.push(a*b);
          }
          else{          
          }
        }
        return nums.pop().toString();
    }

    private static String toRevPolish(String str) {
        char[] chars = str.toCharArray(); 
        Stack<Character> ops = new Stack<>();
        String res="";
        for (char x : chars) {
          if(Character.isDigit(x)){
              res+=x;
              if(!ops.isEmpty()){
                 if(ops.peek()!='('){
                    res+=ops.pop();
                 }
              }                  
          }else{         
              if(x==')'){
                  ops.pop();
                  res+=ops.pop();
              }
              ops.push(x);
          }
        }
        return res;
    }
}
