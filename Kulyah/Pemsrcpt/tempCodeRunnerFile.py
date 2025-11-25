def is_leap_year(year: int) -> bool:
    return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

def is_palindrome(s: str) -> bool:
    cleaned = ''.join(ch.lower() for ch in s if ch.isalnum())
    return cleaned == cleaned[::-1]

def main():
    while True:
        print("1. Cek tahun kabisat\n2. Cek palindrome\n3. Keluar")
        choice = input("Pilihan (1/2/3): ").strip()
        if choice == "1":
            try:
                year = int(input("Masukkan tahun: ").strip())
            except ValueError:
                print("Masukkan angka valid.")
                continue
            print(f"{year} adalah{' ' if is_leap_year(year) else ' bukan '}tahun kabisat.")
        elif choice == "2":
            s = input("Masukkan teks/angka: ")
            print("Palindrome." if is_palindrome(s) else "Bukan palindrome.")
        elif choice == "3":
            print("Keluar.")
            break
        else:
            print("Pilihan tidak dikenal.")

if __name__ == "__main__":
    main()
