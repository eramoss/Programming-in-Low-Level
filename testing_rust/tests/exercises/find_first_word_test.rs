use testing_rust::exercises;

#[test]
fn find_first_word_test() {
    let mut s = String::new();
    s.push_str("hello world");
    let index_first_word = exercises::find_first_word::first_word(&s);

    let s = &s[0..index_first_word];

    assert_eq!(s, "hello");
}

#[test]
fn string_diff_test() {
    let mut s = String::new();
    s.push_str("hello world");
    let index_first_word = exercises::find_first_word::first_word(&s);

    let x = &mut s[..index_first_word].to_owned();
    let y = &mut s[index_first_word..].to_owned();
    x.push_str(y);

    let is_equal = match x.cmp(&&mut s) {
        std::cmp::Ordering::Equal => true,
        std::cmp::Ordering::Greater => false,
        std::cmp::Ordering::Less => false,
    };
    assert!(is_equal);
}
