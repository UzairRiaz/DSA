import Node from "./Node";


class SingllyLinkedList {
    private head: Node | null;
    private tail: Node | null;
    private length: number;

    constructor() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    add(data: Number) {
        let newNode = new Node(data, null);
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail?.setNext(newNode);
            this.tail = newNode;
        }
        this.length++;
    }

    remove(data: Number) {
        let currentNode = this.head;
        let previousNode: Node | null = null;
        while (currentNode !== null) {
            if (currentNode.getData() === data) {
                if (previousNode !== null) {
                    previousNode.setNext(currentNode.getNext());
                } else {
                    this.head = currentNode.getNext();
                }
                this.length--;
            }
            previousNode = currentNode;
            currentNode = currentNode.getNext();
        }
    }

    reverse() {
        let currentNode = this.head;
        let previousNode: Node | null = null;
        let nextNode: Node | null = null;
        while (currentNode !== null) {
            nextNode = currentNode.getNext();
            currentNode.setNext(previousNode);
            previousNode = currentNode;
            currentNode = nextNode;
        }
        this.tail = this.head;
        this.head = previousNode;
    }
}

export default SingllyLinkedList;