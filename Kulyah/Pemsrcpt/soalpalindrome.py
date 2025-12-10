# Soal-4 Palindrome Checker

def palindrome(word):
    word_clean = word.lower().replace(" ", "")
    return word_clean == word_clean[::-1]


input_text = input(" ")
words = [word.strip() for word in input_text.split()]  


sorted_palindrome = sorted(words, key=lambda x: (-len(x), x.lower()))


tespalindrome = [word for word in sorted_palindrome if palindrome(word)]
for word in tespalindrome:
    print(word)

if not tespalindrome:
    print("\nTidak ada kata palindrome.")
