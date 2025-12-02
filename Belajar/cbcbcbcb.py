# Soal: Manipulasi List
# Buatlah program yang melakukan operasi berikut pada list

# 1. Buat list berisi 5 angka
numbers = [10, 25, 15, 30, 20]

# 2. Tambahkan angka 35 ke akhir list
numbers.append(35)

# 3. Sisipkan angka 12 di posisi index 2
numbers.insert(2, 12)

# 4. Hapus angka 25 dari list
numbers.remove(25)

# 5. Urutkan list secara ascending
numbers.sort()

# 6. Tampilkan list akhir dan panjangnya
print("List akhir:", numbers)
print("Panjang list:", len(numbers))

# 7. Tampilkan elemen terbesar dan terkecil
print("Elemen terbesar:", max(numbers))
print("Elemen terkecil:", min(numbers))

# 8. Hitung jumlah semua elemen
print("Jumlah semua elemen:", sum(numbers))