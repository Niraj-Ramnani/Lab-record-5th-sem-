import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;

public class Program3 implements ActionListener{

	JButton b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19;
	
	JTextField tf;
	static double a=0,b=0,result=0;
	int operator=0;
	Program3()
	{
		
		JFrame f =new JFrame("Calculator Application by 22EARCS114");
		JLabel l=new JLabel("Calculator by Niraj");
		
		l.setBounds(80,30,200,30);
		l.setFont(new Font("Times New Roman",Font.BOLD,22));
		l.setForeground(Color.red);
		
		tf=new JTextField(20);
		tf.setBounds(50,80,260,35);
		tf.setFont(new Font ("Arial",Font.BOLD,20));
		tf.setHorizontalAlignment(JTextField.RIGHT);
		Border border = BorderFactory.createLineBorder(Color.BLUE, 5);
		tf.setBorder(border);
		
		b1 = new JButton("1");
		b2 = new JButton("2");
		b3 = new JButton("3");
		b4 = new JButton("4");
		b5 = new JButton("5");
		b6 = new JButton("6");
		b7 = new JButton("7");
		b8 = new JButton("8");
		b9 = new JButton("9");
		b10 = new JButton("0");
		b11 = new JButton("/");  
		b12 = new JButton(".");
		b13 = new JButton("+");
		b14 = new JButton("*");
		b15 = new JButton("-");
		b16 = new JButton("AC");
		b17 = new JButton("%");
		b18 = new JButton("Del");
		b19 = new JButton("=");

		b7.setBounds(50,150,60,25);
		b8.setBounds(120,150,60,25);
		b9.setBounds(190,150,60,25);
		b4.setBounds(50,200,60,25);
		b5.setBounds(120,200,60,25);
		b6.setBounds(190,200,60,25);
		b1.setBounds(50,250,60,25);
		b2.setBounds(120,250,60,25);
		b3.setBounds(190,250,60,25);
		b10.setBounds(50,300,60,25);
		b11.setBounds(260,150,60,25);
		b12.setBounds(120,300,60,25);
		b13.setBounds(190,300,60,25);
		b14.setBounds(260,200,60,25);
		b15.setBounds(260,250,60,25);
		b16.setBounds(260,300,60,25);
		b17.setBounds(50,350,60,25);
		b18.setBounds(120,350,60,25);
		b19.setBounds(190,350,130,25);
		
		f.add(tf);
		f.add(b1);
		f.add(b2);
		f.add(b3);
		f.add(b4);
		f.add(b5);
		f.add(b6);
		f.add(b7);
		f.add(b8);
		f.add(b9);
		f.add(b10);
		f.add(b11);
		f.add(b12);
		f.add(b13);
		f.add(b14);
		f.add(b15);
		f.add(b16);
		f.add(b17);
		f.add(b18);
		f.add(b19);
		f.add(l);
		f.setSize(410,450);
		f.setResizable(false);
		f.setLayout(null);
		f.setVisible(true);
		f.setResizable(false);
		
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
		b5.addActionListener(this);
		b6.addActionListener(this);
		b7.addActionListener(this);
		b8.addActionListener(this);
		b9.addActionListener(this);
		b10.addActionListener(this);
		b11.addActionListener(this);
		b12.addActionListener(this);
		b13.addActionListener(this);
		b14.addActionListener(this);
		b15.addActionListener(this);
		b16.addActionListener(this);
		b17.addActionListener(this);
		b18.addActionListener(this);
		b19.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==b1)
		{
			tf.setText(tf.getText().concat("1"));
		}
		if(e.getSource()==b2)
		{
			tf.setText(tf.getText().concat("2"));
		}
		if(e.getSource()==b3)
		{
			tf.setText(tf.getText().concat("3"));
		}
		if(e.getSource()==b4)
		{
			tf.setText(tf.getText().concat("4"));
		}
		if(e.getSource()==b5)
		{
			tf.setText(tf.getText().concat("5"));
		}
		if(e.getSource()==b6)
		{
			tf.setText(tf.getText().concat("6"));
		}
		if(e.getSource()==b7)
		{
			tf.setText(tf.getText().concat("7"));
		}
		if(e.getSource()==b8)
		{
			tf.setText(tf.getText().concat("8"));
		}
		if(e.getSource()==b9)
		{
			tf.setText(tf.getText().concat("9"));
		}
		if(e.getSource()==b10)
		{
			tf.setText(tf.getText().concat("0"));
		}
		if(e.getSource()==b12)
		{
			tf.setText(tf.getText().concat("."));
		}
		if(e.getSource()==b13)
		{
			a=Double.parseDouble(tf.getText());
			operator=1;
			tf.setText(null);
		}
		if(e.getSource()==b13)
		{
			a=Double.parseDouble(tf.getText());
			operator=1;
			tf.setText(null);
		}
		if(e.getSource()==b15)
		{
			a=Double.parseDouble(tf.getText());
			operator=2;
			tf.setText(null);
		}
		if(e.getSource()==b14)
		{
			a=Double.parseDouble(tf.getText());
			operator=3;
			tf.setText(null);
		}
		if(e.getSource()==b11)
		{
			a=Double.parseDouble(tf.getText());
			operator=4;
			tf.setText(null);
		}
		if(e.getSource()==b17)
		{
			b=Double.parseDouble(tf.getText());
			operator=5;
			switch(operator) {
			case 5 : result = (a*b)/100;
			break;
			}
			tf.setText(" "+result);
		}
		if(e.getSource()==b19)
		{
			b=Double.parseDouble(tf.getText());
			switch(operator)
			{
			case 1: result = a+b;
			break;
			
			case 2: result = a-b;
			break;
			
			case 3: result = a*b;
			break;
			
			case 4: result = a/b;
			break;
			}
			tf.setText(" "+result);
		}
		if(e.getSource()==b16)
		{
			tf.setText(null);
		}
		
		if(e.getSource()== b18)
		{
			String s = tf.getText();
			tf.setText(" ");
			for(int i=0;i<s.length()-1;i++) 
			{
				tf.setText(tf.getText()+s.charAt(i));
			}
		}
	}
	
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				new Program3();
			}
		});	
	
	}
}