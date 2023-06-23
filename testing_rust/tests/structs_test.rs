struct User {
    username: String,
    email: String,
    active: bool,
    sign_in_count: usize,
}

fn build_user(username: &str, email: &str) -> User {
    User {
        username: String::from(username),
        email: String::from(email),
        active: true,
        sign_in_count: 0,
    }
}

#[test]
fn same_user_different_email_test() {
    let user1 = build_user("eramoss", "edulramos@outlook.com");
    let user2 = build_user("eramoss", "test@outlook.com");

    assert_eq!(user1.username, user2.username);
    assert_ne!(user1.email, user2.email);
    assert_eq!(user1.active, user2.active);
    assert_eq!(user1.sign_in_count, user2.sign_in_count);
}
