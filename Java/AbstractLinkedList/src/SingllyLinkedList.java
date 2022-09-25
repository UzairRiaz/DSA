public class SingllyLinkedList extends LinkedList {
    // constructor
    SingllyLinkedList() {
        super();
    }

    // add node to the end of the list
    public void addNode(int d) {
        Node newNode = new Node(d, null, null);
        if (this.isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.setNext(newNode);
            this.tail = newNode;
        }
        this.length++;
    }

    // print the list
    public void printList() {
        Node temp = this.head;
        while (temp != null) {
            System.out.print(temp.getData() + " ");
            temp = temp.getNext();
        }
        System.out.println();
    }

    // remove node from the list
    public void removeNode(int d) {
        try {
            if (this.isEmpty())
                throw new LLEException();
            Node temp = this.head;
            Node prev = null;
            while (temp != null) {
                if (temp.getData() == d) {
                    if (prev == null) {
                        this.head = temp.getNext();
                        this.length--;
                        return;
                    } else {
                        prev.setNext(temp.getNext());
                        this.length--;
                        return;
                    }
                }
                prev = temp;
                temp = temp.getNext();
            }
            throw new NNFException();
        } catch (Exception e) {
            System.out.println(e.getMessage());
            return;
        }
    }
}
