# Input daftar belanja dari user
raw_input = input("Masukkan daftar belanja (pisahkan dengan koma): ")

# Parsing: Split koma -> strip whitespace -> jadikan list
daftar_belanja = [item.strip() for item in raw_input.split(",")]

# Menampilkan hasil
print(f"Daftar belanja Anda: {daftar_belanja}")

data = [
    "Halo dunia",
    "Ini adalah sebuah kalimat panjang",
    "pendek",
    "Sangat pendek"
]

# Menentukan jumlah kata minimum
minimum_kata = 3

# Memfilter list
hasil_filter = [item for item in data if len(item.split()) >= minimum_kata]

# Menampilkan hasil
print(hasil_filter)