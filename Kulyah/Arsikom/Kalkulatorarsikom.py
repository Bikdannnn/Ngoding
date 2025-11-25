def main():
    try:
        a = float(input("Masukkan bilangan pertama (a): "))
    except ValueError:
        print("Input bukan angka valid.")
        return

    try:
        b = float(input("Masukkan bilangan kedua (b): "))
    except ValueError:
        print("Input bukan angka valid.")
        return

    print("\nPilih operasi:")
    print("1. Penjumlahan")
    print("2. Pengurangan")
    print("3. Perkalian")
    print("4. Pembagian")
    
    try:
        pilihan = int(input("Masukkan pilihan (1-4): "))
    except ValueError:
        print("\nPilihan tidak valid!")
        return

    hasil = 0.0

    if pilihan == 1:
        hasil = a + b
    elif pilihan == 2:
        hasil = a - b
    elif pilihan == 3:
        hasil = a * b
    elif pilihan == 4:
        if b == 0.0:
            print("\nPilihan tidak valid!")
            return
        hasil = a / b
    else:
        print("\nPilihan tidak valid!")
        return

    print(f"\nHasil: {hasil:.2f}")

if __name__ == "__main__":
    main()
