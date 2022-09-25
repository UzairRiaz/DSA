public class App {
    public static void main(String[] args) throws Exception {
        LinkedList list = new DoubllyLinkedList();
        list.addNode(1);
        list.addNode(2);
        list.addNode(3);

        list.removeNode(2);

        list.printList();
    }
}
