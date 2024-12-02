// Write a java program to design a form using basic swing components 
import java.awt.*;
import javax.swing.border.Border;
import javax.swing.*;

public class Program1{
	
	public static void main(String[] args) {
		JFrame f=new JFrame("GENERAL FORM BY NIRAJ RAMNANI - 22EARCS114 ");
		JPanel p=new JPanel();
		ImageIcon icon = new ImageIcon("C:\\Users\\niraj\\eclipse-workspace\\aryacollege\\src\\aryacollege\\formimg.png");
		f.setIconImage(icon.getImage());
		p.setBounds(30,20,420,400);
		p.setBackground(Color.white);
		Border bline=BorderFactory.createTitledBorder("General Form Design Layout");
		p.setBorder(bline);
		p.setLayout(null);
		p.setVisible(true);
		
		JLabel l1=new JLabel("Student General Form");
		JLabel l2=new JLabel("Name of Student");
		JLabel l3=new JLabel("Father's Name");
		JLabel l4=new JLabel("D.O.B");
		JLabel l5=new JLabel("Gender");
		JLabel l6=new JLabel("Course");
		JLabel l7=new JLabel("Branch");
		JLabel l8=new JLabel("College");
		
		l1.setBounds(130,20,200,30);
		l1.setFont(new Font("Times New Roman",Font.BOLD,20));
		l1.setForeground(Color.RED);
		l2.setBounds(20,60,100,30);
		l3.setBounds(20,100,100,30);
		l4.setBounds(20,140,100,30);
		l5.setBounds(20,180,100,30);
		l6.setBounds(20,220,100,30);
		l7.setBounds(20,260,100,30);
		l8.setBounds(20,300,100,30);
		
		p.add(l1);
		p.add(l2);
		p.add(l3);
		p.add(l4);
		p.add(l5);
		p.add(l6);
		p.add(l7);
		p.add(l8);
		
		JTextField t1=new JTextField(20);
		JTextField t2=new JTextField(20);
		
	    String date[] = {"Day", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
	    JComboBox<String> cb1 = new JComboBox<>(date);
		String month[]= {"Month","January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
		JComboBox<String> cb2=new JComboBox<>(month);
		String year[]= {"Year","1990","1991","1992","1993","1994","1995","1996","1997","1998","1999","2000","2001","2002","2003","2004","2005","2006","2007","2008","2009","2010","2011","2012","2013","2014","2015","2016","2017","2018","2019","2020","2021","2022","2023","2024"};
		JComboBox<String> cb3=new JComboBox<>(year);
		
		JRadioButton rb1=new JRadioButton("Male");
		JRadioButton rb2=new JRadioButton("Female");
		ButtonGroup bg=new ButtonGroup();
		bg.add(rb1);
		bg.add(rb2);
		
		String course[]= {"B.Tech","M.Tech","MBA","BBA","B.Sc","M.Sc","B.Ed","BCA","MCA"};
		JComboBox<String> cb4=new JComboBox<>(course);
		String branch[]= {"Computer Science","Artificial Intelligence And Data Science","Information Technology","Civil Engineering","Electronics and Communication Engineering","Mechanical Engineering","Chemical Engineering"};
		JComboBox<String> cb5=new JComboBox<>(branch);
		String college[]= {"Arya College of Engineering and Information Technology","Jaipur National University","Poornima College of Engineering","Swami Keshvanand Institute of Technology","Arya Institute Of Engineering Technology And Management","Yagyavalkya Institute of Technology"};
		JComboBox<String> cb6=new JComboBox<>(college);
		
		t1.setBounds(140,70,260,25);
		t2.setBounds(140,110,260,25);
		cb1.setBounds(140,150,70,25);
		cb1.setBackground(Color.white);
		cb2.setBounds(230,150,70,25);
		cb2.setBackground(Color.white);
		cb3.setBounds(330,150,70,25);
		cb3.setBackground(Color.white);
		rb1.setBounds(140,190,110,25);
		rb1.setBackground(Color.white);
		rb2.setBounds(260,190,110,25);
		rb2.setBackground(Color.white);
		cb4.setBounds(140,230,260,25);
		cb4.setBackground(Color.white);
		cb5.setBounds(140,270,160,25);
		cb5.setBackground(Color.white);
		cb6.setBounds(140,310,260,25);
		cb6.setBackground(Color.white);
		
		p.add(t1);
		p.add(t2);
		p.add(cb1);
		p.add(cb2);
		p.add(cb3);
		p.add(rb1);
		p.add(rb2);
		p.add(cb4);
		p.add(cb5);
		p.add(cb6);
		
		JButton b1 = new JButton("Submit");
		JButton b2 = new JButton("Reset");
		JButton b3 = new JButton("Exit");
		b1.setBounds(50,360,90,25);
		b2.setBounds(170,360,90,25);
		b3.setBounds(300,360,90,25);
		
		p.add(b1);
		p.add(b2);
		p.add(b3);
		
		f.add(p);
		f.setSize(500,500);
		f.setResizable(false);
		f.setLayout(null);
		f.setVisible(true);
		
		}
}