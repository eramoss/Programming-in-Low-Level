#[derive(Debug)]
struct Point(u32, u32, u32);
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
    points: (Point, Point, Point, Point),
}

pub fn create_and_debugging_rect() {
    const SIZE: u32 = 16;
    let rect = Rectangle {
        height: 10,
        width: dbg!(20 * SIZE),
        points: (
            Point(20, 32, 20),
            Point(30, 52, 20),
            Point(20, 52, 20),
            Point(30, 32, 20),
        ),
    };
    println!("The area of the rectangle is: {}", rect.height * rect.width);
    dbg!(&rect.points);
    dbg!(&rect);
}
