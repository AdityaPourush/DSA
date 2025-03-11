package BinaryTree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class LevelOrderTraversal {

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

        public void printLevelOrder(Node root){
            Queue<Node> q = new LinkedList<>();
            ArrayList<Integer> ans = new ArrayList<>();
            // root check
            if(root == null){
                return;
            }
            // putting root into both queue and array
            q.offer(root);
            ans.add(root.data);

            // loop
            while(!q.isEmpty()){
                Node top = q.peek();
                if(top.left != null){
                    q.offer(top.left);
                    ans.add(top.left.data);
                }
                if(top.right != null){
                    q.offer(top.right);
                    ans.add(top.right.data);
                }

                q.remove();
            }

            for (Integer an : ans) {
                System.out.print(an + " ");
            }
        }
    }

    public static void main(String[] args) {
        int[] nodes = {6, 3, 4, -1, -1, 7, 8, -1, -1, -1, 9, -1, 1, -1, -1};
        BinaryTree tree = new BinaryTree();
        tree.root = BinaryTree.BuildPreOrder(nodes);
        tree.printPreOrder(tree.root);
        System.out.println();
        tree.printLevelOrder(tree.root);
    }
}
