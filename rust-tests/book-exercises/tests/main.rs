use book_exercises::exercises::nth_fibonacci_num::nth_element;

#[test]
fn nth_element_test() {
    let x = nth_element(10);
    assert_eq!(x, 55);
}
