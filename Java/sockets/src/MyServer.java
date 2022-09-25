
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
            HashMap<Character, Integer> count = new HashMap<Character, Integer>();
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (count.containsKey(c)) {
                    count.put(c, count.get(c) + 1);
                } else {
                    count.put(c, 1);
                }
            }
            // get the most frequent characters and their counts
            HashMap<Character, Integer> mostFrequent = new HashMap<Character, Integer>();

            
            
            // ss.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}