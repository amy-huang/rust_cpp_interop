use mylib::printPhrase;

// fn printPhrase(phrase: &str) {
//     println!("{}", phrase);
// }

fn main() {
    let phrase = "Hello from Rust with ptr+len!";
    printPhrase(phrase.as_ptr(), phrase.len());
}