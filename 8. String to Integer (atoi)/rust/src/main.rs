struct Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        
        let mut i: usize = 0;

        // skip white spaces
        while i < s.len() && s.chars().nth(i) == Some(' ') {
            i += 1;
        }

        // read sign if present
        // no ternary operator?? Rust is for mentally ill ppl
        let sign: i32 = if s.chars().nth(i) == Some('-') { -1 } else { 1 };

        if let Some(c) = s.chars().nth(i) {
            if "+-".contains(c) {
                i += 1;
            }
        }

        // read digits
        let mut res: i32 = 0;

        while let Some(c) = s.chars().nth(i) {
            // everyone calls this a 'base' but rustaceans are more demenceans and call it 'radix'
            let digit: Option<u32> = c.to_digit(10);

            if digit.is_none() {
                break;
            }

            let new_res: Option<i32> = res.checked_mul(10)
                  .and_then(|res: i32| res.checked_add(digit.unwrap() as i32));
            
            // overflow
            if new_res.is_none() {
                return if sign == -1 { i32::MIN } else { i32::MAX };
            }

            res = new_res.unwrap();
            i += 1;
        }

        return sign * res as i32;
    }
}


fn main() {
    assert!(Solution::my_atoi(String::from("42")) == 42);
    assert!(Solution::my_atoi(String::from(" -042")) == -42);
    assert!(Solution::my_atoi(String::from("1337c0d3")) == 1337);
    assert!(Solution::my_atoi(String::from("0-1")) == 0);
    assert!(Solution::my_atoi(String::from("words and 987")) == 0);
    assert!(Solution::my_atoi(String::from("-91283472332")) == -2147483648);
    assert!(Solution::my_atoi(String::from("2147483648")) == 2147483647);
}
