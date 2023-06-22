use book_exercises::exercises;

#[test]
fn find_first_word_test() {
    let mut s = String::new();
    s.push_str("hello world");
    let index_first_word = exercises::find_first_word::first_word(&s);
    s.truncate(index_first_word);
    assert_eq!(s, "hello");
}
