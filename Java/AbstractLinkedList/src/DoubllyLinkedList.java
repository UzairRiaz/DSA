
public class DoubllyLinkedList extends LinkedList {
    DoubllyLinkedList() {
        super();
    }

    @Override
    public void addNode(int d) {
        Node newNode = new Node(d, null, null);
        if (this.isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            newNode.previous = this.tail;
            this.tail = newNode;
        }
        this.length++;
    }

    @Override
    public void printList() {
        Node temp = this.head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    @Override
    public void removeNode(int d) {
        try {
            if (this.isEmpty())
                throw new LLEException();
            Node temp = this.head;
            while (temp != null) {
                if (temp.data == d) {
                    if (temp == this.head) {
                        this.head = this.head.next;
                        this.head.previous = null;
                    } else if (temp == this.tail) {
                        this.tail = this.tail.previous;
                        this.tail.next = null;
                    } else {
                        temp.previous.next = temp.next;
                        temp.next.previous = temp.previous;
                    }
                    this.length--;
                    return;
                }
                temp = temp.next;
            }
            throw new NNFException();
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return;
        }
    }
}