import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import com.toedter.calendar.*;

public class Program5 implements ActionListener {
	JFrame f;
	JPanel p1,p2;
	JLabel title,title1,un, fn, mn ,gen , Dob, Mb , Em ,Add, Cou, B,DoA;
	JButton Submit, Reset,Exit;
	JTextField user ,fou,mou,mb,em;
	JTextArea add,database;
	JCheckBox cb;
	JRadioButton male , female;
	JComboBox box4,box5;
	JDateChooser indob,indoa;
	
	Program5(){
		
		f = new JFrame("Student registration form by Niraj Ramnani 22EARCS114");
		
		p1 = new JPanel();
		p2 = new JPanel();
		
		p1.setBounds(30,20,450,720);
		p1.setBackground(Color.white);
		Border line=BorderFactory.createTitledBorder("Fill Registration form");
		p1.setBorder(line);
		p1.setLayout(null);
		p1.setVisible(true);
		
		p2.setBounds(500,20,500,500);
		p2.setBackground(Color.white);
		Border line1=BorderFactory.createTitledBorder("Student Database");
		p2.setBorder(line1);
		p2.setLayout(null);
		p2.setVisible(true);
		
		title1 = new JLabel("Student information");
		title1.setBounds(50,20,300,50);
		title1.setFont(new Font("Times New Roman",Font.BOLD,20));
		
		database = new JTextArea();
		database.setBounds(50,80,400,400);
		Border b = BorderFactory.createLineBorder(Color.black);
		database.setBorder(b);
		
		title = new JLabel("Student Registration Form by Niraj");
		un = new JLabel("Student's name");
		fn = new JLabel("Father name");
		mn = new JLabel("Mother name");
		gen = new JLabel("Gender");
		Dob = new JLabel("Date of Birth");
		Mb = new JLabel("Mobile Number");
		Em = new JLabel("E-Mail ID");
		Add = new JLabel("Address");
		Cou = new JLabel("Course");
		B = new JLabel("Branch");
		DoA = new JLabel("Date of Admission");
		
		user = new JTextField();
		fou = new JTextField();
		mou = new JTextField();
		mb = new JTextField();
		em = new JTextField();
		add = new JTextArea();
		add.setBorder(b);
		
		male = new JRadioButton("Male");
		female = new JRadioButton("Female");
		ButtonGroup bg=new ButtonGroup();
		bg.add(male);
		bg.add(female);

		
		
		String course[]= {"Select your Course","B.Tech","M.Tech","MBA","B.Sc"};
		box4=new JComboBox<>(course);
		
		String branch[]= {"Select your Branch","Computer Science","Artificial Intelligence And Data Science","Information Technology","Electronics and Communication Engineering","Mechanical Engineering"};
		box5=new JComboBox<>(branch);
		
		cb = new JCheckBox("Please accept the terms and condition");
		
		Submit = new JButton("Submit");
		Reset  = new JButton("Reset");
		Exit= new JButton("Exit");
		
		indob = new JDateChooser();
		indoa = new JDateChooser();

		title.setBounds(35,20,500,50);
		title.setFont(new Font("Times New Roman",Font.BOLD,25));
		title.setForeground(Color.red);

		un.setBounds(20,70,100,30);
		fn.setBounds(20,110,100,30);
		mn.setBounds(20,150,100,30);
		gen.setBounds(20,190,100,30);
		Dob.setBounds(20,230,100,30);
		Mb.setBounds(20,270,100,30);
		Em.setBounds(20,310,100,30);
		Add.setBounds(20,380,100,30);
		Cou.setBounds(20,470,100,30);
		B.setBounds(20,510,100,30);
		DoA.setBounds(20,550,120,30);
		
		user.setBounds(140,70,260,25);
		fou.setBounds(140,110,260,25);
		mou.setBounds(140,150,260,25);
		mb.setBounds(140,270,260,25);
		em.setBounds(140,310,260,25);
		add.setBounds(140,350,260,100);
		
		cb.setBounds(120,600,260,25);
		cb.setBackground(Color.white);
		p1.add(cb);
		
		male.setBounds(140,200,110,25);
		male.setBackground(Color.white);
		female.setBounds(250,200,110,25);
		female.setBackground(Color.white);
		
		Submit.setBounds(50,660,90,25);
		Reset.setBounds(190,660,90,25);
		Exit.setBounds(330,660,90,25);
		
		indob.setBounds(140,230,260,25);
		indoa.setBounds(140,550,260,25);
		
		box4.setBounds(140,470,260,25);
		box4.setBackground(Color.white);
		box5.setBounds(140,510,260,25);
		box5.setBackground(Color.white);
		
		p1.add(Submit);
		p1.add(Reset);
		p1.add(Exit);
		
		p1.add(title);
		p1.add(un);
		p1.add(fn);
		p1.add(mn);
		p1.add(gen);
		p1.add(Dob);
		p1.add(Mb);
		p1.add(Em);
		p1.add(Add);
		p1.add(Cou);
		p1.add(B);
		p1.add(DoA);
		
		p1.add(user);
		p1.add(fou);
		p1.add(mou);
		p1.add(add);
		p1.add(mb);
		p1.add(em);
		
		p1.add(male);
		p1.add(female);
		
		p1.add(indob);
		p1.add(indoa);
		p1.add(box4);
		p1.add(box5);
		
		p2.add(database);
		p2.add(title1);
		
		
		f.add(p1);
		f.add(p2);
		f.setSize(1050,800);
		f.setResizable(false);
		f.setLayout(null);
		f.setVisible(true);
		Submit.addActionListener(this);
		Reset.addActionListener(this);
		Exit.addActionListener(this);
		cb.addActionListener(this);
		
	}

	public void actionPerformed(ActionEvent e) 
	{
		if(e.getSource()== Submit) 
		{	
			if(cb.isSelected())
			{
				DateFormat df = new SimpleDateFormat("dd-MM-YYYY");
				
				
			     database.setText("Name :" + user.getText()+"\nfather Name :" + fou.getText()+"\nMother Name :"+mou.getText()+
					"\nGender :"+(male.isSelected()?"Male":"Female")+"\nDate of Birth :"+df.format(indob.getDate())+"\nAddress :"
					+ ""+add.getText()+"\nMobile No. :"+mb.getText()+"\nEmail id :"+em.getText()+"\ncourse :"+box4.getSelectedItem()
					+"\nBranch :"+box5.getSelectedItem()+"\nDate of Addmission"+df.format(indoa.getDate()) );
			}
			else
			{
				JOptionPane.showMessageDialog(f, "click on check Box");
			}
			
		}
		if(e.getSource()==Reset)
		{
			
			fou.setText("");
			user.setText("");
			mou.setText("");
			add.setText("");
			mb.setText("");
			em.setText("");
			male.setSelected(true);
			cb.setSelected(false);
			box4.setSelectedIndex(0);
			box5.setSelectedIndex(0);
			indob.setDate(null); 
			indoa.setDate(null);
		}

		if(e.getSource()==Exit)
        {       		
            System.exit(0);
        }
	}
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				new Program5();
			}
		});
	}
}
