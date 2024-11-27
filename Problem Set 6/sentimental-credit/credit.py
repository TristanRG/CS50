def main():
    number = input("Number: ")

    if not luhn_check(number):
        print("INVALID")
        return

    if len(number) == 15 and (number.startswith("34") or number.startswith("37")):
        print("AMEX")
    elif len(number) == 16 and number[:2] in {"51", "52", "53", "54", "55"}:
        print("MASTERCARD")
    elif len(number) in {13, 16} and number.startswith("4"):
        print("VISA")
    else:
        print("INVALID")

def luhn_check(number):
    total = 0
    reverse_digits = number[::-1]

    for i, digit in enumerate(reverse_digits):
        n = int(digit)
        if i % 2 == 1:
            n *= 2
            if n > 9:
                n -= 9
        total += n

    return total % 10 == 0

if __name__ == "__main__":
    main()
