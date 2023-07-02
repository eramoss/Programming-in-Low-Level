use std::vec;
use testing_rust::exercises::nth_fibonacci_num;

#[test]
fn add_n_nuns_to_vec() {
    let mut vec: Vec<usize> = vec![];

    for i in 0..10 {
        vec.push(nth_fibonacci_num::nth_element(i));
    }

    dbg!(vec);
}
