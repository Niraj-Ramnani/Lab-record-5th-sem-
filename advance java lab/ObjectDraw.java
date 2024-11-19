//write a java program to draw hello world, rectanlgle and fill and oval using swing applet 
//import java.awt.event.*;
import java.awt.*;
import java.applet.*;
import javax.swing.*;


public class ObjectDraw extends Applet {
	
public void paint(Graphics g) 
{
	g.drawString("Hello World", 80, 20);
	g.drawRect(100, 100,100, 100);
	g.drawOval(100, 100, 100, 100);
	g.setColor(Color.RED);
	g.fillOval(100, 100,100, 100);
}

public static void main(String[] args) {
	JFrame f = new JFrame("Object Draw by Niraj : 22EARCS114");
	
	ObjectDraw applet = new ObjectDraw();
	f.add(applet);
	f.setSize(400,400);
	f.setVisible(true);
}
}