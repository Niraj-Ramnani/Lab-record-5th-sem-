//server implementation
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class AdderImp1 extends UnicastRemoteObject implements Adder {
    // Constructor
    protected AdderImp1() throws RemoteException {
        super();
    }

    // Implement the add method
    public int add(int a, int b) throws RemoteException {
        return a + b;
    }
}