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
use std::any::{Any, TypeId};
trait InstanceOf
where
    Self: Any,
{
    fn instance_of<U: ?Sized + Any>(&self) -> bool {
        TypeId::of::<Self>() == TypeId::of::<U>()
    }
}
// implement this trait for every type that implements `Any` (which is most types)
impl<T: ?Sized + Any> InstanceOf for T {}
#[test]
fn create_user_test() {
    let user = build_user("eramoss", "edulramos@outlook.com");

    assert!(user.instance_of::<User>());
}

#[test]
fn create_new_user_from_another_test() {
    let user = build_user("eramoss", "edulramos@outlook.com");
    let user1 = User {
        username: user.username.clone(),
        active: true,
        email: user.email.clone(),
        sign_in_count: 1,
    };

    assert_eq!(user1.email, user.email);
    assert_ne!(user.sign_in_count, user1.sign_in_count);
}
