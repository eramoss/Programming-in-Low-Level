#[derive(Clone, Debug)]
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
            let mut current = self.root.as_mut().unwrap();

            loop {
                if current.value > value {
                    if current.left.is_none() {
                        let new_node = Node::new(value);
                        current.left = Some(Box::new(new_node));
                        self.amount_of_child += 1;
                        break;
                    } else {
                        current = current.left.as_mut().unwrap();
                    }
                } else if current.value < value {
                    if current.right.is_none() {
                        let new_node = Node::new(value);
                        current.right = Some(Box::new(new_node));
                        self.amount_of_child += 1;
                        break;
                    } else {
                        current = current.right.as_mut().unwrap();
                    }
                } else {
                    eprintln!(
                        "Invalid data, node cannot be inserted with same data of other nodes"
                    );
                    break;
                }
            }
        }
    }

    fn search(&mut self, value: i64) -> Option<Node> {
        if self.root.is_none() {
            eprintln!("No root node found on search");
            return None;
        } else {
            let mut current = self.root.as_mut().unwrap();

            loop {
                if current.value == value {
                    let return_node = current.clone();
                    return Some(return_node);
                } else if current.value > value {
                    if current.left.is_none() {
                        return None;
                    }
                    current = current.left.as_mut().unwrap();
                } else if current.value < value {
                    if current.right.is_none() {
                        return None;
                    }
                    current = current.right.as_mut().unwrap();
                } else {
                    return None;
                }
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

#[test]
fn search_node() {
    let mut tree = Tree::new();
    tree.insert(16);
    tree.insert(15);
    tree.insert(17);
    tree.insert(12);
    tree.insert(13);

    let node_to_search = tree.search(12);
    assert_eq!(node_to_search.unwrap().value, 12);
}

fn print_in_order(root: Option<&Node>) {
    if root.is_some() {
        print_in_order(root.unwrap().left.as_deref()); // stack up until root is null
        dbg!(root.unwrap().value); // stack down
        print_in_order(root.unwrap().right.as_deref()); // stack up until root is null
    }
}
