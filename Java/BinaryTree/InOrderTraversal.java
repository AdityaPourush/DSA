package BinaryTree;

public class InOrderTraversal {

    static class Node{
        int data;
        Node left;
        Node right;

        public Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    static class BinaryTree{
        Node root;
        BinaryTree(){
            this.root = null;
        }

        static int idx = -1;
        public static Node BuildPreOrder(int[] nodes){
            idx++;
            if(idx >= nodes.length || nodes[idx] == -1){
                return null;
            }
            Node newNode = new Node(nodes[idx]);
            newNode.left = BuildPreOrder(nodes);
            newNode.right = BuildPreOrder(nodes);

            return newNode;
        }

        public void printPreOrder(Node root){
            if(root == null){
                return;
            }
            System.out.print(root.data + " ");
            printPreOrder(root.left);
            printPreOrder(root.right);
        }

        public void printInOrder(Node root){
            if(root == null){
                return;
            }
            printInOrder(root.left);
            System.out.print(root.data + " ");
            printInOrder(root.right);
        }

        public void printPostOrder(Node root){
            if(root == null){
                return;
            }
            printPostOrder(root.left);
            printPostOrder(root.right);
            System.out.print(root.data + " ");
        }
    }

    public static void main(String[] args) {
        int[] nodes = {6, 3, 4, -1, -1, 7, 8, -1, -1, -1, 9, -1, 1, -1, -1};
        BinaryTree tree = new BinaryTree();
        tree.root = BinaryTree.BuildPreOrder(nodes);
        tree.printPreOrder(tree.root);
        System.out.println();
        tree.printInOrder(tree.root);
        System.out.println();
        tree.printPostOrder(tree.root);
    }
}
