package stackApp1;

import java.awt.*;
public class liveDiagram 
{
    Frame f=new Frame();
    Label[][] desks=new Label[5][5];

    boolean status;

    void setVacant(int i)
    {
        desks[i/5][i%5].setBackground(new Color(58, 158, 85));
    }

    void setEngaged(int i)
    {
        desks[i/5][i%5].setBackground(new Color(224, 61, 61));
    }

    liveDiagram()
    {
        f.setLayout(new GridLayout(5,5,50,50));
        f.setSize(1000, 700);
        f.setBackground(new Color(50, 50, 50));
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                desks[i][j]=new Label(Integer.toString(i*5+j), Label.CENTER);
                desks[i][j].setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 18));
                desks[i][j].setForeground(new Color(200, 200, 200));
                desks[i][j].setBackground(new Color(58, 158, 85));
                f.add(desks[i][j]);
                System.out.println("i"+i+" j"+j);
            }
        }
        f.setVisible(true);
    }

    public static void main(String args[]) throws InterruptedException
    {
        liveDiagram lv=new liveDiagram();
        Thread.sleep(5000);
        System.out.println("Setting Engaged");
        lv.setEngaged(5);
        Thread.sleep(1000);
        lv.setEngaged(7);
        Thread.sleep(1000);
        lv.setVacant(5);
    }
}
