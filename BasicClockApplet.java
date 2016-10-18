import java.applet.Applet;
import java.awt.*;
import java.util.Date;

public class BasicClockApplet extends Applet implements Runnable
{
    Thread t;
    Graphics g;
    public void start()
    {
        t=new Thread(this);
        t.start();
    }
    public void paint(Graphics g)
    {
        Date d=new Date();
        int hour=d.getHours();
        int min=d.getMinutes();
        int sec=d.getSeconds();
        String str=String.valueOf(hour)+" : "+String.valueOf(min)+" : "+String.valueOf(sec);
        g.drawString(str, 100,100);
    }
    public void run()
    {
        while(true)
        {
        try {
            Thread.sleep(1000);
            repaint();
        } catch (Exception e) {}
        }
    }
}
