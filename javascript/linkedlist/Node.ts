class Node {
    private data: Number | null;
    private next: Node | null;
    constructor(d: Number, n: Node | null) {
        this.data = d;
        this.next = n;
    }

    getData() {
        return this.data;
    }
    getNext() {
        return this.next;
    }
    setNext(n: Node | null) {
        this.next = n;
    }

}

export default Node;