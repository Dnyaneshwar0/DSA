package stackApp1;

import java.util.Stack;

public class Main implements Runnable
{
    public void run()
    {
        System.out.println("Running");
    }
    public static void main(String args[]) throws InterruptedException
    {
        Stack<Integer> stc=new Stack<Integer>(); 
        for(int i=24;i>=0;i--)
            stc.push(i);
        liveDiagram lv=new liveDiagram();
        (new Thread(new popRan(stc,lv))).start();
    }
}
