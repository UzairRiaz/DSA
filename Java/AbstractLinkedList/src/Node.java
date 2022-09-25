public class Node {
    int data;
    Node next;
    Node previous;

    Node(int d, Node n, Node p) {
        this.data = d;
        this.next = n;
        this.previous = p;
    }

    public void setData(int d) {
        this.data = d;
    }

    public int getData() {
        return this.data;
    }

    public void setNext(Node n) {
        this.next = n;
    }

    public Node getNext() {
        return this.next;
    }

    public void setPrevious(Node n) {
        this.previous = n;
    }

    public Node getPrevious() {
        return this.previous;
    }
}
