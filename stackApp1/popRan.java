package stackApp1;

import java.util.Stack;
import java.util.EmptyStackException;

public class popRan implements Runnable
{
    Stack<Integer> stc;
    liveDiagram lv;
    popRan(Stack<Integer> stc, liveDiagram lv)
    {
        this.stc=stc;
        this.lv=lv;
    }
    public void run()
    {
        while(true)
        {
            try
            {
                int a=stc.pop();
                lv.setEngaged(a);
                System.out.println("Popped : "+a);
                (new Thread(new pushBack(stc, lv, a))).start();
            }
            catch(EmptyStackException e)
            {
                System.out.println("Stack empty, Nothing to pop.");
            }
            try 
            {
                Thread.sleep((int)(Math.random()*2000));
            } 
            catch (InterruptedException e) 
            {
                e.printStackTrace();
            }
        }
    }
}