wildan = [1, 2, 3, 4, 5]

wildan.append(6)

wildan.sort()
wildan.remove(3)


print(wildan)
print("Panjang list:", len(wildan))
print("Elemen terbesar:", max(wildan))
print("Elemen terkecil:", min(wildan))
print("Jumlah semua elemen:", sum(wildan))

print([d for d in wildan if d > 2])