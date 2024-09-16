import java.awt.event.*;

import javax.swing.*;

public class LoginFormCreate implements ActionListener{

	JFrame f;
	JLabel title, username, password;
	JButton login, reset;
	JTextField inuser;
	JPasswordField inpass;
	JCheckBox cb;
	LoginFormCreate()
	{
		f = new JFrame("Login Authentification page - 22EARCS114");
		ImageIcon icon = new ImageIcon("C:\\Users\\niraj\\OneDrive\\Desktop\\practise\\LAB\\Lab-record-5th-sem-\\advance java lab\\login.jpg");
		f.setIconImage(icon.getImage());
		title = new JLabel("User Login");
		username= new JLabel("User name ");
//		title = new JLabel("Password");
		password =new JLabel("Password");
		inuser = new JTextField();
		inpass = new JPasswordField();
		cb = new JCheckBox("show your password");
		login = new JButton("Login");
		reset = new JButton("Reset");
		
		title.setBounds(200,20,100,20);
		username.setBounds(50,50,100,50);
		password.setBounds(50,100,100,50);
		inuser.setBounds(150,70,200,20);
		inpass.setBounds(150,110,200,20);
		cb.setBounds(100,150,200,20);
		login.setBounds(100,200,80,20);
		reset.setBounds(250,200,80,20);
		
		f.add(title);
		f.add(username);
		f.add(password);
		f.add(inuser);
		f.add(inpass);
		f.add(cb);
		f.add(login);
		f.add(reset);
		f.setSize(500,500);
		f.setLayout(null);
		f.setVisible(true);
		login.addActionListener(this);
		reset.addActionListener(this);
		cb.addActionListener(this);
		
	}
	
	public void actionPerformed(ActionEvent e) 
	{
		if(e.getSource()==login) 
		{
			if(inuser.getText().equals("Niraj") && inpass.getText().equals("2004") ) 
			{
				JOptionPane.showMessageDialog(f, "Login Successful");
			}
			else
			{
				JOptionPane.showConfirmDialog(f, "wrong password");
			}
		}
		if(e.getSource()==reset)
		{
			inpass.setEchoChar(' ');
			inuser.setText("");
		}
		if(e.getSource()==cb) 
		{
			if(cb.isSelected())
			{
				inpass.setEchoChar('\u0000');
			}
			else
				inpass.setEchoChar('*');
		}
	}
	
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				new LoginFormCreate();
			}
		});
	}
}