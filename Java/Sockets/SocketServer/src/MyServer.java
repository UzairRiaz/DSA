
import java.io.*;
import java.net.*;
import java.util.HashMap;

public class MyServer {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(6666);
            Socket s = ss.accept();// establishes connection
            DataInputStream dis = new DataInputStream(s.getInputStream());
            String str = (String) dis.readUTF();
            System.out.println("message= " + str);

            // get name

            String[] parts = str.split(" ");

            String name = parts[parts.length - 1];

            // send response
            DataOutputStream dout = new DataOutputStream(s.getOutputStream());
            dout.writeUTF("Hello " + name);

            ss.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}