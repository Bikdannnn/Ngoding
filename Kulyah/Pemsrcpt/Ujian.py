# -- jangan diubah, input nilai
nilai = list(map(int, input().split()))

# -- solusi mulai dari sini
# 1. Hitung nilai rata-rata
ratarata_nilai = f"{sum(nilai) / len(nilai):.2f}"

# 2. Buat list nilai yang lulus (>= 80)
lulus = [n for n in nilai if n >= 80]
    
# 3. Tampilkan hasil
print(ratarata_nilai)
print(lulus)
print(len(lulus))

# -- solusi selesai disini