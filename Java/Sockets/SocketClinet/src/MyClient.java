import java.io.*;
import java.net.*;

public class MyClient {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 6666);
            DataOutputStream dout = new DataOutputStream(s.getOutputStream());
            dout.writeUTF("Hello My Name is Client");
            dout.flush();
            // dout.close();
            // print response from server
            DataInputStream dis = new DataInputStream(s.getInputStream());
            String str = (String) dis.readUTF();
            System.out.println("Server says: " + str);

            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}