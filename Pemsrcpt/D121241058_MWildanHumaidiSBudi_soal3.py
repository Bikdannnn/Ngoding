#Soal-3

nilai = [80, 75, 90, 60, 85, 70, 95]

ratarata = sum(nilai) / len(nilai)
nilailulus = [n for n in nilai if n >= 80]

print("Rata-rata nilai:", ratarata)
print("Nilai yang lulus:", nilailulus)
print("Jumlah nilai yang lulus:", len(nilailulus))