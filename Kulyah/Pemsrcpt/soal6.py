#Soal-6

durasi_video = [5, 12, 8, 30, 25, 7, 15, 40, 3]

total_durasi = sum(durasi_video)
rata_durasi = total_durasi / len(durasi_video)
durasi_jam = round(float(total_durasi) / 60, 2)

print("Total durasi video (menit):", total_durasi)
print("Total durasi video (jam):", durasi_jam)

video_pendek = [d for d in durasi_video if d < 10]
print("Jumlah video pendek (<10 menit):", video_pendek)

video_panjang = [d for d in durasi_video if d > 20]
print("Jumlah video panjang (>20 menit):", video_panjang)

durasi_diurutkan = sorted(durasi_video)
print("Durasi video dari yang terpendek ke terpanjang:", durasi_diurutkan)
