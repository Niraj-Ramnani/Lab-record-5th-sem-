package aryacollege;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
import javax.swing.border.EtchedBorder;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.sql.*;
import java.awt.event.ActionEvent;

public class emp_from1 extends JFrame {
    private static final long serialVersionUID = 1L;
    private JPanel contentPane;
    private JTextField id;
    private JTextField name;
    private JTextField mobileNumber;
    private JTextField searchId;
    private JTable table;
    private DefaultTableModel tableModel;
    
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            try {
                emp_from1 frame = new emp_from1();
                frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }
    
    public emp_from1() {
        setTitle("Employee Management System by 22EARACS130");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 800, 500);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        contentPane.setLayout(null);

        JLabel Title = new JLabel("Emp Management By PRITY");
        Title.setHorizontalAlignment(SwingConstants.CENTER);
        Title.setForeground(new Color(0, 0, 255));
        Title.setFont(new Font("Tahoma", Font.BOLD, 20));
        Title.setBounds(241, 27, 303, 32);
        contentPane.add(Title);

        JPanel panel = new JPanel();
        panel.setBackground(Color.WHITE);
        panel.setBorder(new TitledBorder(new EtchedBorder(), "Enter Employee Details", TitledBorder.CENTER, TitledBorder.TOP, null, Color.RED));
        panel.setBounds(47, 98, 286, 251);
        contentPane.add(panel);
        panel.setLayout(null);

        JLabel lblId = new JLabel("Employee ID:");
        lblId.setFont(new Font("Times New Roman", Font.BOLD, 11));
        lblId.setBounds(10, 48, 82, 30);
        panel.add(lblId);

        id = new JTextField();
        id.setBounds(124, 54, 126, 19);
        panel.add(id);
        id.setColumns(10);

        JLabel lblName = new JLabel("Name:");
        lblName.setFont(new Font("Times New Roman", Font.BOLD, 11));
        lblName.setBounds(10, 88, 82, 30);
        panel.add(lblName);

        name = new JTextField();
        name.setBounds(124, 94, 126, 19);
        panel.add(name);
        name.setColumns(10);

        JLabel lblMobile = new JLabel("Mobile No:");
        lblMobile.setFont(new Font("Times New Roman", Font.BOLD, 11));
        lblMobile.setBounds(10, 128, 82, 30);
        panel.add(lblMobile);

        mobileNumber = new JTextField();
        mobileNumber.setBounds(124, 134, 126, 19);
        panel.add(mobileNumber);
        mobileNumber.setColumns(10);

        JButton btnSave = new JButton("Save");
        btnSave.setBounds(100, 180, 85, 21);
        panel.add(btnSave);

        JPanel panel2 = new JPanel();
        panel2.setForeground(Color.CYAN);
        panel2.setBorder(new TitledBorder(new EtchedBorder(), "Employee Database", TitledBorder.CENTER, TitledBorder.TOP, null, Color.RED));
        panel2.setBounds(423, 98, 286, 251);
        contentPane.add(panel2);
        panel2.setLayout(new BorderLayout());

        tableModel = new DefaultTableModel(new String[]{"Series No", "Name", "ID", "Mobile No"}, 0);
        table = new JTable(tableModel);
        JScrollPane scrollPane = new JScrollPane(table);
        panel2.add(scrollPane);
        
        JLabel lblSearch = new JLabel("Enter ID:");
        lblSearch.setFont(new Font("Times New Roman", Font.PLAIN, 11));
        lblSearch.setBounds(47, 359, 58, 30);
        contentPane.add(lblSearch);

        searchId = new JTextField();
        searchId.setBounds(132, 365, 96, 19);
        contentPane.add(searchId);
        searchId.setColumns(10);

        JButton btnSearch = new JButton("Search");
        btnSearch.setBounds(47, 397, 85, 21);
        contentPane.add(btnSearch);

        JButton btnUpdate = new JButton("Update");
        btnUpdate.setBounds(231, 397, 85, 21);
        contentPane.add(btnUpdate);

        JButton btnDelete = new JButton("Delete");
        btnDelete.setBounds(423, 397, 85, 21);
        contentPane.add(btnDelete);

        JButton btnLoad = new JButton("Load");
        btnLoad.setBounds(624, 397, 85, 21);
        contentPane.add(btnLoad);

        btnSave.addActionListener(e -> saveEmployee());
        btnSearch.addActionListener(e -> searchEmployee());
        btnUpdate.addActionListener(e -> updateEmployee());
        btnDelete.addActionListener(e -> deleteEmployee());
        btnLoad.addActionListener(e -> loadEmployees());
    }
    
    private void saveEmployee() {
        String eid = id.getText();
        String ename = name.getText();
        String emobile = mobileNumber.getText();
        try (Connection con = connectToDatabase()) {
        	 String query1 = "SELECT * FROM employee WHERE id = ?";
             PreparedStatement pst1 = con.prepareStatement(query1);
             pst1.setString(1, eid);
             ResultSet rs = pst1.executeQuery();
             if(rs.next())
             {
            	 JOptionPane.showMessageDialog(this, "Employee already exits!");
            	 return;
            			
             }
            String query = "INSERT INTO employee(name, id, mobile_number) VALUES (?, ?, ?)";
            PreparedStatement pst = con.prepareStatement(query);
            pst.setString(1, ename);
            pst.setString(2, eid);
            pst.setString(3, emobile);
            pst.executeUpdate();
            JOptionPane.showMessageDialog(this, "Employee Saved Successfully!");
            clearFields();
            loadEmployees();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void searchEmployee() {
        String eid = searchId.getText();
        try (Connection con = connectToDatabase()) {
            String query = "SELECT * FROM employee WHERE id = ?";
            PreparedStatement pst = con.prepareStatement(query);
            pst.setString(1, eid);
            ResultSet rs = pst.executeQuery();
            if (rs.next()) {

            	 tableModel.setRowCount(0);
            	tableModel.addRow(new Object[]{rs.getInt("series_number"), rs.getString("name"), rs.getString("id"), rs.getString("mobile_number")});
            } else {
                JOptionPane.showMessageDialog(this, "Employee Not Found!");
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void updateEmployee() {
        String eid = id.getText();
        String ename = name.getText();
        String emobile = mobileNumber.getText();
        try (Connection con = connectToDatabase()) {
            String query = "UPDATE employee SET name = ?, mobile_number = ? WHERE id = ?";
            PreparedStatement pst = con.prepareStatement(query);
            pst.setString(1, ename);
            pst.setString(2, emobile);
            pst.setString(3, eid);
            pst.executeUpdate();
            JOptionPane.showMessageDialog(this, "Employee Updated Successfully!");
            clearFields();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void deleteEmployee() {
        String eid = searchId.getText();
        if(eid == null)
        {
        	JOptionPane.showMessageDialog(this, "Please enter a id ");
        	return;
        }
        try (Connection con = connectToDatabase()) {
            String query = "DELETE FROM employee WHERE id = ?";
            PreparedStatement pst = con.prepareStatement(query);
            pst.setString(1, eid);
            pst.executeUpdate();
            loadEmployees();
            JOptionPane.showMessageDialog(this, "Employee Deleted Successfully!");
            clearFields();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void loadEmployees() {
        try (Connection con = connectToDatabase()) {
            String query = "SELECT * FROM employee";
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(query);
            tableModel.setRowCount(0);
            while (rs.next()) {
                tableModel.addRow(new Object[]{rs.getInt("series_number"), rs.getString("name"), rs.getString("id"), rs.getString("mobile_number")});
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private void clearFields() {
        id.setText("");
        name.setText("");
        mobileNumber.setText("");
        searchId.setText("");
        id.requestFocus();
    }
   
    private Connection connectToDatabase() throws SQLException {
        return  DriverManager.getConnection("jdbc:mysql://localhost:3306/logindatabases","root","might100");
        		}
}
