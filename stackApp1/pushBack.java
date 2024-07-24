package stackApp1;

import java.util.Stack;

public class pushBack implements Runnable
{
    Stack<Integer> stc;
    liveDiagram lv;
    int i;
    pushBack(Stack<Integer> stc, liveDiagram lv, int i)
    {
        this.stc=stc;
        this.lv=lv;
        this.i=i;
    }
    public void run()
    {
        try 
        {
            Thread.sleep((int)(Math.random()*20000));    
        } 
        catch (Exception e) 
        {
            e.printStackTrace();
        }
        if(i>stc.peek())
        {
            int a=stc.pop();
            stc.push(i);
            stc.push(a);
        }
        else
        {
            stc.push(i);
        }
        System.out.println("Pushed : "+stc.peek());
        lv.setVacant(stc.peek());
    }
}
