use std::vec;
use testing_rust::exercises::nth_fibonacci_num;

#[test]
fn add_n_nuns_to_vec() {
    let mut vec: Vec<usize> = vec![];

    for i in 0..10 {
        vec.push(nth_fibonacci_num::nth_element(i));
    }

    dbg!(&vec);
    assert_eq!(vec.get(9), Some(&nth_fibonacci_num::nth_element(9)));
}

#[test]
fn rmv_num_from_vec() {
    let mut vec: Vec<usize> = vec![];
    for i in 0..10 {
        vec.push(i);
    }
    assert_eq!(vec.remove(5), 5);
}

#[test]
fn change_num_from_vec() {
    let mut vec: Vec<usize> = vec![1, 2, 3, 4];
    for i in &mut vec {
        *i = 50;
    }
    assert_eq!(vec[0], vec[1]);
}
