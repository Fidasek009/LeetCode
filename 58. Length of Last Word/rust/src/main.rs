struct Solution;

impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut i: usize = s.len() - 1;
        
        // skip spaces
        while s.chars().nth(i) == Some(' ') {
            i -= 1;
        }

        // remember word end
        let end_idx: usize = i;

        // read non-spaces
        while s.chars().nth(i) != Some(' ') {
            // reached start of string
            if i == 0 {
                return (end_idx + 1).try_into().unwrap();
            }
            i -= 1;
        }

        return (end_idx - i).try_into().unwrap();
    }
}


fn main() {
    let s1: String = String::from("Hello World!");
    println!("{}", s1);
    let res1: i32 = Solution::length_of_last_word(s1);
    assert!(res1 == 6);

    let s2: String = String::from("World!");
    print!("{}", s2);
    let res2: i32 = Solution::length_of_last_word(s2);
    assert!(res2 == 6)
}
