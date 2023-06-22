pub fn nth_element(n: usize) -> usize {
    if n <= 2 {
        return 1;
    } else {
        return nth_element(n - 1) + nth_element(n - 2);
    }
}
