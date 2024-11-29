import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class server {
    public static void main(String[] args) {
        try {
            // Start the RMI registry
            LocateRegistry.createRegistry(1099);

            // Create and bind the Adder implementation
            AdderImp1 adder = new AdderImp1();
            Naming.rebind("rmi://localhost/AdderService", adder);

            System.out.println("Server is ready.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}