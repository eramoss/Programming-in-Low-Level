pub mod exercises;
use std::io;

// use crate::exercises::guessing_game::guessing;
use crate::exercises::nth_fibonacci_num::nth_element;
// use crate::exercises::twelve_days_of_christmas::print_music;
fn main() {
    println!("Which the nth element of the fibonacci sequence: ");
    let mut n = String::new();

    io::stdin()
        .read_line(&mut n)
        .expect("impossible to read line");

    let n: usize = match n.trim().parse() {
        Ok(n) => n,
        Err(_) => panic!("impossible to parse"),
    };
    let n = nth_element(n);
    println!("{n}");
}
