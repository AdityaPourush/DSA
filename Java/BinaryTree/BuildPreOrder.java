package BinaryTree;

public class BuildPreOrder {
    public static class Node{
        int data;
        Node left;
        Node right;

        public Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    public static class BinaryTree{
        static int idx = -1;
        public Node buildPreOrderTree(int[] nodes){
            idx++;
            if(idx > nodes.length || nodes[idx] == -1){
                return null;
            }
            Node newNode = new Node(nodes[idx]);
            newNode.left = buildPreOrderTree(nodes);
            newNode.right = buildPreOrderTree(nodes);

            return newNode;
        }

        public void printPreOrder(Node root){
            System.out.print(root.data + " ");
            if(root.left != null){
                printPreOrder(root.left);
            }
            if(root.right != null){
                printPreOrder(root.right);
            }
        }

        public void printPreOrderOther(Node root){
            if(root == null){
                return;
            }
            System.out.print(root.data + " ");
            printPreOrderOther(root.left);
            printPreOrderOther(root.right);
        }
    }


    public static void main(String[] args) {
        int[] nodes = {6, 3, 4, -1, -1, 7, -1, -1, 8, 9, -1, -1, 1, -1, -1};
        BinaryTree tree = new BinaryTree();
        Node root = tree.buildPreOrderTree(nodes);
        tree.printPreOrderOther(root);
    }
}
