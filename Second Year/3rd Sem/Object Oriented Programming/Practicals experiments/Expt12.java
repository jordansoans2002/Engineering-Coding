import java.applet.Applet;
import java.awt.*;

public class Expt12 extends Applet{
	public void paint(Graphics g){
		g.getString("Hello World",50,50);
		g.setColor(Color.Pink);
		g.setForeGround(Color.Green);
		g.setBackground(Color.Yellow);
	}
}