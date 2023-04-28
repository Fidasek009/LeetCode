pub fn is_palindrome(x: i32) -> bool {
    if x >= 0 {
        let s: Vec<char> = x.to_string().chars().collect::<Vec<char>>();

        for i in 0..s.len() / 2 {
            if s[i] != s[s.len()-1-i] {
                return false;
            }
        }
        return true;
    }
    else {return false;}
}


fn main() {
    let num: i32 = 121;

    println!("Answer: {}", is_palindrome(num));
}