package BinaryTree;

import java.util.*;
public class IterativePreOrder {

    static class Node{
        int data;
        Node left;
        Node right;

        public Node(int val){
            this.data = val;
            this.left = null;
            this.right = null;
        }
    }

    static class BinaryTree{
        Node root;
        public BinaryTree(){
            this.root = null;
        }

        static int idx = -1;
        public Node buildPreOrder(int[] nodes){
            idx++;
            if(idx >= nodes.length || nodes[idx] == -1){
                return null;
            }

            Node newNode = new Node(nodes[idx]);
            newNode.left = buildPreOrder(nodes);
            newNode.right = buildPreOrder(nodes);

            return newNode;
        }

        public void preOrderTraversal(Node root){
            Stack<Node> stack = new Stack<>();
            List<Integer> traversal = new ArrayList<>();
            stack.push(root);

            while(!stack.isEmpty()){
                Node currentNode = stack.pop();
                traversal.add(currentNode.data);
                if(currentNode.right != null){
                    stack.push(currentNode.right);
                }
                if(currentNode.left != null){
                    stack.push(currentNode.left);
                }
            }

            System.out.println("PreOrder Traversal: " + traversal);
        }
    }

    public static void main(String[] args) {
            BinaryTree tree = new BinaryTree();
            tree.root = new Node(1);
            tree.root.left = new Node(2);
            tree.root.right = new Node(3);
            tree.root.left.left = new Node(4);
            tree.root.left.right = new Node(5);

            tree.preOrderTraversal(tree.root);
    }
}
