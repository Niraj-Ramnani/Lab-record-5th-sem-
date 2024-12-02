//write a java program to draw hello world, rectanlgle and fill and oval using swing applet 
//import java.awt.event.*;
import java.awt.*;
import java.applet.*;
import javax.swing.*;


public class Program4 extends Applet {
	
public void paint(Graphics g) 
{
	g.drawString("Hello World", 80, 20);
	g.drawRect(50, 50,250, 200);
	g.drawOval(125, 100, 100, 100);
	g.setColor(Color.RED);
	g.fillOval(125, 100,100, 100);
}

public static void main(String[] args) {
	JFrame f = new JFrame("Object Draw by Niraj : 22EARCS114");
	
	Program4 applet = new Program4();
	f.add(applet);
	f.setSize(450,400);
	f.setVisible(true);
}
}