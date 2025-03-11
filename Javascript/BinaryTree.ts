class Node{
    data: number;
    left: Node | null;
    right: Node | null;
    constructor(data: number){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree{
    root: Node | null;
    constructor(){
        this.root = null;
    }

    buildPreOrderTree(nodes: number[], idx: {value: number}) : Node | null{
        idx.value++;
        if(idx.value >= nodes.length || nodes[idx.value] == -1){
            return null;
        }
        let newNode = new Node(nodes[idx.value]);
        newNode.left = this.buildPreOrderTree(nodes, idx);
        newNode.right = this.buildPreOrderTree(nodes, idx);

        return newNode;
    }

    printPreOrderTree(root: Node | null){
        if(root == null){
            return ;
        }
        process.stdout.write(root.data + " ");
        this.printPreOrderTree(root.left);
        this.printPreOrderTree(root.right);
    }
}

let nodes = [6, 3, 4, -1, -1, 7, -1, -1, 8, 9, -1, -1, 1, -1, -1];
let tree = new BinaryTree();
let root: Node | null =tree.buildPreOrderTree(nodes, {value: -1});
tree.printPreOrderTree(root);