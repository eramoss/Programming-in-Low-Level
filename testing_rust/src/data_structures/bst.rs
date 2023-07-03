struct Node {
    value: i64,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    const fn new(value: i64) -> Self {
        Node {
            value,
            left: None,
            right: None,
        }
    }
}

struct Tree {
    root: Option<Node>,
    amount_of_child: i64,
}
impl Tree {
    fn new() -> Self {
        Tree {
            root: None,
            amount_of_child: 0,
        }
    }
    fn insert(&mut self, value: i64) {
        if self.root.is_none() {
            self.root = Some(Node::new(value));
        } else {
            let root = self.root.as_mut().expect("Root must be non-empty");
            if value < root.value {
                let new_node = Node::new(value);
                root.left = Some(Box::new(new_node));
                self.amount_of_child += 1;
            } else {
                let new_node = Node::new(value);
                root.right = Some(Box::new(new_node));
                self.amount_of_child += 1;
            }
        }
    }
}

#[test]
fn insert_as_root() {
    let mut tree = Tree::new();
    tree.insert(16);
    assert_eq!(tree.root.expect("").value, 16);
}

#[test]
fn add_node_as_child() {
    let mut tree = Tree::new();
    tree.insert(16);
    tree.insert(15);
    tree.insert(17);
    let root = tree.root.expect("");
    assert_eq!(root.left.expect("").value, 15);
    assert_eq!(root.right.expect("").value, 17);
}

#[test]
fn add_amount_child() {
    let mut tree = Tree::new();
    tree.insert(16);
    tree.insert(15);
    tree.insert(17);

    assert_eq!(tree.amount_of_child, 2);
}
