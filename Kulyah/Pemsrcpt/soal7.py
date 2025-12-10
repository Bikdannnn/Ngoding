#Soal-7

nilai_tugas = [70, 80, 65, 90, 85, 75]

print("Nilai tugas sebelum diolah:", nilai_tugas)

max_nilai = max(nilai_tugas)
min_nilai = min(nilai_tugas)
nilai_tugas.remove(max_nilai)
nilai_tugas.remove(min_nilai)
rata_rata = sum(nilai_tugas) / len(nilai_tugas)

print("Nilai tugas setelah diolah (tanpa nilai tertinggi dan terendah):", nilai_tugas)
print("Rata-rata nilai tugas setelah diolah:", rata_rata)

nilai_diurutkan = sorted(nilai_tugas)
print("Nilai tugas diurutkan dari yang terendah ke tertinggi:", nilai_diurutkan)
