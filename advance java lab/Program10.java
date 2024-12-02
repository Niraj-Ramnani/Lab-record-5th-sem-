import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Program10 {
    private static final String URL = "jdbc:mysql://localhost:3306/logintable";
    private static final String USER = "root";
    private static final String PASSWORD = ""; // Replace with your DB password

    public static Connection getConnection() throws SQLException {
       
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

 
    public static void main(String[] args) {
    	System.out.println("This program is solved by Niraj ");
        try (Connection conn = getConnection()) {
            if (conn != null) {
                System.out.println("Connected to the database successfully with jsp!");
            }
        } catch (SQLException e) {
            System.err.println("Database connection failed: " + e.getMessage());
        }
    }
}
