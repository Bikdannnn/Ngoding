#soal-1

angka = [3, 10, 7, 8, 15, 22, 1]

genap = [n for n in angka if n % 2 == 0]
ganjil = [n for n in angka if n % 2 != 0]

print("Genap:", genap)
print("Ganjil:", ganjil)