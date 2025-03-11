package BinaryTree;

import java.util.*;

public class PreInPostTraversal {

    static class Node{
        int data;
        Node left;
        Node right;

        Node(int val){
            this.data = val;
            this.left = null;
            this.right = null;
        }
    }

    public static class BinaryTree{
        Node root;
        BinaryTree(){
            this.root = null;
        }

        public void allTraversals(Node root){
            if(root == null){
                return;
            }

            List<Integer> PreOrder = new ArrayList<>();
            List<Integer> InOrder = new ArrayList<>();
            List<Integer> PostOrder = new ArrayList<>();

            Stack<Pair<Node, Integer>> stack = new Stack<>();
            stack.push(new Pair<>(root, 1));

            while(!stack.isEmpty()){
                Pair<Node, Integer> current = stack.pop();
                Node currentNode = current.getKey();
                int state = current.getValue();

                if(state == 1){
                    PreOrder.add(currentNode.data);
                    stack.push(new Pair<>(currentNode, state+1));

                    if(currentNode.left != null){
                        stack.push(new Pair<>(currentNode.left, 1));
                    }
                }
                else if(state == 2){
                    InOrder.add(currentNode.data);
                    stack.push(new Pair<>(currentNode, state+1));

                    if(currentNode.right != null){
                        stack.push(new Pair<>(currentNode.right, 1));
                    }
                }
                else {
                    PostOrder.add(currentNode.data);
                }
            }

            System.out.println("Preorder: " + PreOrder);
            System.out.println("Inorder: " + InOrder);
            System.out.println("PostOrder: " + PostOrder);
        }
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        tree.allTraversals(tree.root);
    }

    private static class Pair<K, V>{
        private K key;
        private V value;

        public Pair(K key, V value){
            this.key = key;
            this.value = value;
        }

        public K getKey(){
            return this.key;
        }

        public V getValue(){
            return this.value;
        }
    }
}
