#Soal-5

# index 0 = jam 08.00–08.59, index 1 = 09.00–09.59, dst.
transaksi = [3, 5, 0, 7, 10, 4, 2, 8, 9, 1, 6, 3, 4]

total_transaksi = sum(transaksi)
print(f"Total transaksi: {total_transaksi}")

max_transaksi = max(transaksi)
index_max = transaksi.index(max_transaksi)
jam_mulai = 8 + index_max
jam_akhir = jam_mulai + 1
print(f"Transaksi tertinggi {max_transaksi} pesanan pada jam {jam_mulai:02d}.00–{jam_akhir:02d}.59")

jam_sibuk = [j for j in transaksi if j >= 5]
print(f"Transaksi jam sibuk: {jam_sibuk}")