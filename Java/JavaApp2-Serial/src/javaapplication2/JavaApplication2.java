package javaapplication2;
import java.io.*;
 
public class JavaApplication2 {

    public static void main(String[] args) throws IOException {
        ObjectOutputStream Out = new ObjectOutputStream(new FileOutputStream("objects.dat"));
        Lista<Integer> L = new Lista();
        L.Add_to_start(10);
        L.Add_to_end(2);
        Out.writeObject(L);
        Out.close();
        System.out.println(L.Delete_from_start());
        System.out.println(L.Delete_from_start());
        ObjectInputStream In = new ObjectInputStream(new FileInputStream("objects.dat"));
        try {
            L = (Lista<Integer>)In.readObject();
        } catch ( ClassNotFoundException e ){}
        System.out.println(L.Delete_from_start());
        System.out.println(L.Delete_from_start());
        
    }
    
}
