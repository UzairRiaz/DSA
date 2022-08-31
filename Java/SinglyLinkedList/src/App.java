public class App {
    public static void main(String[] args) throws Exception {
        final LinkedList ls = new LinkedList();

        ls.add(1);
        ls.add(2);
        ls.add(3);
        ls.add(4);
        ls.add(5);
        ls.print();
        ls.remove(3);
        ls.print();
    }
}
