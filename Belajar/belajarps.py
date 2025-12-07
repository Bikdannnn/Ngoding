wildan = [1, 2, 3, 4, 5, 9, 8, 7]

wildan.append(6)

wildan.sort()
wildan.remove(3)


print(wildan)
print("Panjang list:", len(wildan))
print("Elemen terbesar:", max(wildan))
print("Elemen terkecil:", min(wildan))
print("Jumlah semua elemen:", sum(wildan))

print([d for d in wildan if d > 2])

print([n for n in wildan if n % 2 == 0])
print([n for n in wildan if n % 2 != 0])

nilaimax = max(wildan)
nilaimin = min(wildan)
sorted_wildan = sorted(wildan)

print("Nilai terbesar:", nilaimax)
print("Nilai terkecil:", nilaimin) 
print("List terurut:", sorted_wildan)
print("List terbalik:", list(reversed(wildan)))
print("List isi wildan:", wildan)