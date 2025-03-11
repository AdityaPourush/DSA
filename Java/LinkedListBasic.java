class Node{
    int data;
    Node next;

    public Node(int data){
        this.data = data;
        this.next = null;
    }
}

public class LinkedListBasic {
    public static void main(String[] args) {
        Node head = new Node(10);
        Node temp = head;
        temp.next = new Node(20);
        temp = temp.next;
        temp.next = new Node(30);
        temp=temp.next;
        temp.next = new Node(40);

        display(head);
    }

    public static void display(Node head){
        Node current = head;
        while(current != null){
            System.out.print(current.data + "->");
            current = current.next;
        }
        System.out.println("null");
    }
}
