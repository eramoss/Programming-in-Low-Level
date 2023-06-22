pub fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();

    for (iter, &value) in bytes.iter().enumerate() {
        if value == b' ' {
            return iter;
        }
    }
    return s.len();
}
