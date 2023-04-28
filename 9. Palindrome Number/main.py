def isPalindrome(x: int) -> bool:
    return str(x) == str(x)[::-1]


def main():
    number = -121
    print(isPalindrome(number))


if __name__ == "__main__":
    main()