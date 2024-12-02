import java.rmi.Naming;

public class Client {
    public static void main(String[] args) {
        try {
            // Lookup the remote object
            Adder adder = (Adder) Naming.lookup("rmi://localhost/AdderService");

            // Call the add method
            System.out.println("This Program is solved by Niraj");
            int result = adder.add(10, 7);
            System.out.println("Result of adding 10 and 7: " + result);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}