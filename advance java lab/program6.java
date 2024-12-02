import javax.swing.*;
import java.awt.event.*;
import java.sql.*;
import java.awt.Color;

public class program6 implements ActionListener {
	JFrame f;
	JLabel title, username, password;
	JButton login;
	JTextField inuser;
	JPasswordField inpass;
	
	program6() {
		f = new JFrame("Login Authentication Page through JDBC 22EARCS165 ");
		title = new JLabel("User Login");
		title.setForeground(Color.red);
		username = new JLabel("User Name");
		password = new JLabel("Password");
	    inuser = new JTextField();
	    inpass = new JPasswordField();
	    login = new JButton("Login");
	    title.setBounds(200,20,100,20);
	    username.setBounds(50,50,100,50);
	    password.setBounds(50,100,100,50);
	    inuser.setBounds(150,70,200,20);
	    inpass.setBounds(150,110,200,20);
	   	login.setBounds(200,200,80,20);
	  
	    f.add(title);
	    f.add(username);
	    f.add(password);
	    f.add(inuser);
	    f.add(inpass);
	    f.add(login);
	    f.setSize(500,350);
	    f.setLayout(null);
	    f.setVisible(true);
	    f.setResizable(false);
	    login.addActionListener(this);
	}
public void actionPerformed(ActionEvent e)
	{
		try 
			{
				Class.forName("com.mysql.cj.jdbc.Driver");
				Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/logintable", "root", "password");

				Statement stmt = con.createStatement();
				String sql = "Select *from usertable where user_name='"+inuser.getText()+"' and user_pass = '"+inpass.getText()+"'";
				ResultSet rs = stmt.executeQuery(sql);
				if(rs.next())
					JOptionPane.showMessageDialog(f, "Login successful");
				else
					JOptionPane.showMessageDialog(f, "Please, check your name and password.");
				con.close();
			}
		catch(Exception ea) 
		{
			System.out.print(ea);
		}
	}
	public static void main(String[] args) {
		new program6();	
	}
}