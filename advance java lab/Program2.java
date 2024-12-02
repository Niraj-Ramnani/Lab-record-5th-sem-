import javax.swing.*;
import java.awt.event.*;
public class Program2 implements ActionListener{
	JFrame f;
	JLabel title,username,password;
	JTextField inuser;
	JPasswordField inpass;
	JCheckBox cb;
	JButton login , reset;
	Program2(){
		f = new JFrame("Login page roll no 22EARCS114");
		title = new JLabel("Login Page by Niraj");
		username = new JLabel("User Name");
		password = new JLabel("password");
		inuser = new JTextField();
		inpass = new JPasswordField();
		cb = new JCheckBox("Show Your Password ");
		login = new JButton("Login");
		reset = new JButton("Reset");
		title.setBounds(100,50,200,20);
		inuser.setBounds(160,80,150,20);
		username.setBounds(50,80,100,20);
		cb.setBounds(100,150,150,20);
		password.setBounds(50,120,100,20);
		inpass.setBounds(160,120,150,20);
		login.setBounds(100,190,80,20);
		reset.setBounds(190,190,80,20);
		f.add(title);
		f.add(username);
		f.add(password);
		f.add(inuser);
		f.add(inpass);
		f.add(cb);
		f.add(login);
		f.add(reset);
		f.setSize(400,400);
		f.setLayout(null);
		f.setVisible(true);
		login.addActionListener(this);
		reset.addActionListener(this);
		cb.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e) {
		
		if( e.getSource()==login) {
			if(inuser.getText().equals("niraj") && inpass.getText().equals("2004")) {
				JOptionPane.showMessageDialog(f, "Login Succesfull");
			}
			else 
				JOptionPane.showMessageDialog(f, "wrong credential");
				
			
		}
		if (e.getSource()==reset) {
			inuser.setText("");
			inpass.setText("");
		}
		if(e.getSource()==cb) {
			if(cb.isSelected()) {
				inpass.setEchoChar('\u0000');
			}
			else {
				inpass.setEchoChar('*');
			}
		}
	}
	public static void main(String[] args) {
		
		new Program2();
		

	}

}
