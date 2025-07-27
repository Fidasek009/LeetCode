struct Solution;

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut x: i32 = x;
        let mut res: i32 = 0;

        while x != 0 {
            // prevent overflow
            if res > i32::MAX / 10 || res < i32::MIN / 10 {
                return 0;
            }

            res *= 10;
            res += x % 10;
            x /= 10;
        }

        return res;
    }
}


fn main() {
    assert!(Solution::reverse(123) == 321);
    assert!(Solution::reverse(-123) == -321);
    assert!(Solution::reverse(120) == 21);
    assert!(Solution::reverse(1534236469) == 0);
    assert!(Solution::reverse(-2147483648) == 0);
}
