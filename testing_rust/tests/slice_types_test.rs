#[test]
fn slicing_array_test() {
    let array = [2, 4, 6, 8, 10];
    let slice = &array[..3];

    assert_eq!(slice, [2, 4, 6]);
    assert_ne!(slice, array);
}

#[test]
fn slicing_string_test() {
    let str = "hello world".to_owned();
    let slice = &str[..5];

    assert_eq!(slice, "hello");
}
