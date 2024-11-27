from cs50 import get_string

def main():
    text = get_string("Text: ")
    letters = int(count_letters(text))
    words = int(count_words(text))
    sentences = int(count_sentences(text))

    L = float(letters / words * 100)
    S = float(sentences / words * 100)
    index = float(0.0588 * L - 0.296 * S - 15.8)
    grade_result(index)

def count_letters(text):
    letters = int(0)
    for i in text:
        if i.isalpha():
            letters += 1
    return letters

def count_words(text):
    words = int(1)
    for i in text:
        if i.isspace():
            words+= 1
    return words

def count_sentences(text):
    sentences = int(0)
    for i in text:
        if i == "." or i == "?" or i == "!":
            sentences+= 1
    return sentences

def grade_result(index):
    grade = int(round(index))
    if grade >= 16:
        print("Grade 16+\n")

    elif grade < 1:
        print("Before Grade 1\n")

    else:
        print(f"Grade {grade}\n")


if __name__ == "__main__":
    main()
