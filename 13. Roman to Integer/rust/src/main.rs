// made b ChatGPT i gave up :P

use lazy_static::lazy_static;
use std::collections::HashMap;

lazy_static! {
    static ref ROMAN_TO_INT_MAP: HashMap<char, i32> = {
        let mut map = HashMap::new();
        map.insert('I', 1);
        map.insert('V', 5);
        map.insert('X', 10);
        map.insert('L', 50);
        map.insert('C', 100);
        map.insert('D', 500);
        map.insert('M', 1000);
        map
    };
}

struct Solution;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut result: i32 = 0;
        let chars: Vec<char> = s.chars().collect();

        for i in 0..chars.len() {
            let curr_val: i32 = *ROMAN_TO_INT_MAP.get(&chars[i]).unwrap();
            let next_val: i32 = if i < chars.len() - 1 {
                *ROMAN_TO_INT_MAP.get(&chars[i + 1]).unwrap()
            } else {
                0
            };

            if curr_val < next_val {
                result -= curr_val;
            } else {
                result += curr_val;
            }
        }
        result
    }
}


fn main() {
    let number: String = String::from("LVIII");

    println!("{}", Solution::roman_to_int(number));
}
