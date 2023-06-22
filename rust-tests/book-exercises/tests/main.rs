use book_exercises::exercises::nth_fibonacci_num::nth_element;

#[test]
fn nth_element_test() {
    let semi_fibonacci_seq = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55];
    let rand_n = (rand::random::<usize>() % 9) + 1;
    let y = semi_fibonacci_seq[rand_n - 1];
    let x = nth_element(rand_n);
    assert_eq!(x, y);
}
