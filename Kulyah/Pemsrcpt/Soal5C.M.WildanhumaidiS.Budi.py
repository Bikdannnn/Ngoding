import matplotlib.pyplot as plt

# M. Wildan Humaidi S. Budi D121241058

print("\n--- SOAL 5C: Visualisasi Data (Scatter Plot) ---")
print("Membuat plot...")

jam_belajar = [1, 2, 3, 4, 5]
skor_kuis = [55, 60, 67, 74, 88]

plt.figure(figsize=(8, 6))
plt.scatter(jam_belajar, skor_kuis, color='red', s=100, label='Data Mahasiswa')

plt.title('Hubungan Jam Belajar vs Skor Kuis (Tipe 5C)')
plt.xlabel('Jam Belajar (jam)')
plt.ylabel('Skor Kuis')
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend()

plt.show()