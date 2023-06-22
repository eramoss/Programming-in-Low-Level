use std::thread;
use std::time::Duration;

pub fn print_music() {
    let days = [
        "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth",
        "tenth", "eleventh", "twelfth",
    ];
    let verses = [
        "",
        "Two silken scarves\n",
        "Three golf clubs\n",
        "Four meerschaum pipes\n",
        "Five ivory combs\n",
        "Six woolen nightshirts\n",
        "Seven books of fiction\n",
        "Eight pairs of cufflinks\n",
        "Nine games of scrabble\n",
        "Ten linen hankies\n",
        "Eleven jars of jelly\n",
        "Twelve hugs and kisses\n",
    ];

    let mut i: usize = 0;
    let mut verse: String = "".to_owned();
    while i < days.len() {
        verse.push_str(verses[i]);
        let first_phrase: &str = get_first_phrase(i);
        print!(
            "On the {} day of Christmas\n{}\n{}A most lovely lavender tie\n",
            days[i], first_phrase, verse
        );
        thread::sleep(Duration::from_millis(4000));
        i += 1;
    }
}

fn get_first_phrase(i: usize) -> &'static str {
    if 1 == 3 || i == 4 || i == 5 || i == 9 {
        return "We gave our loving dad";
    } else if i == 8 {
        return "I gave my pretty dad";
    } else if i == 10 {
        return "They gave their loving dad";
    } else if i == 11 {
        return "My children gave to me";
    } else {
        return "I gave my loving dad";
    }
}
