//remote interface
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Adder extends Remote {
    // Method to add two numbers
    int add(int a, int b) throws RemoteException;
}