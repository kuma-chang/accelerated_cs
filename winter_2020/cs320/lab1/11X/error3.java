import java.io.*;
class error3{
  public static void main (String argv[]) throws IOException {
    final int STACK_SIZE = 1024;
    final int[] stack = new int[STACK_SIZE];
    int sp = -1;
    stack[++sp] = 10;
    stack[++sp] = 1;
    stack[++sp] = 0;
    {int t = stack[sp-0]; stack[++sp] = t;}
    while (stack[sp--] != 0) {
      {int t = stack[sp-0]; stack[++sp] = t;}
      System.out.print(stack[sp--]); System.out.flush();
      stack[++sp] = 10;
      System.out.write((byte) stack[sp--]); System.out.flush();
      stack[++sp] = 1;
      stack[sp-1] = stack[sp-1] + stack[sp]; sp--;
      {int t = stack[sp-1]; stack[++sp] = t;}
      {int t = stack[sp-1]; stack[++sp] = t;}
      stack[++sp] = -1;
      stack[sp-1] = stack[sp-1] + stack[sp]; sp--;
      stack[sp] = - stack[sp];
      stack[sp-1] = stack[sp-1] + stack[sp]; sp--;
      }
    }
