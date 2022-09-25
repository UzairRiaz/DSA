public abstract class LinkedList {
    Node head;
    Node tail;
    int length;

    LinkedList() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    public abstract void addNode(int d);

    public abstract void printList();

    public boolean isEmpty() {
        if (this.length == 0)
            return true;
        return false;
    }

    public int getLength() {
        return this.length;
    }

    public abstract void removeNode(int d);
}
