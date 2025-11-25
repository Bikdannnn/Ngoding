# --- FUNGSI-FUNGSI INTI ---

def cek_kabisat(tahun):
    """
    Mengecek apakah suatu tahun adalah tahun kabisat.
    Mengembalikan True jika kabisat, False jika bukan.
    """
    return (tahun % 400 == 0) or (tahun % 100 != 0 and tahun % 4 == 0)

def cek_palindrom(input_data):
    """
    Mengecek apakah suatu string/angka adalah palindrom.
    Pengecekan mengabaikan spasi dan huruf besar/kecil.
    """
    # Ubah input (bisa angka/teks) menjadi string
    teks_asli = str(input_data)
    
    # Bersihkan string:
    # 1. Ubah semua jadi huruf kecil (.lower())
    # 2. Hapus semua spasi (.replace(" ", ""))
    teks_bersih = teks_asli.lower().replace(" ", "")
    
    # Balik string yang sudah bersih
    teks_terbalik = teks_bersih[::-1]
    
    # Kembalikan True jika sama, False jika beda
    return teks_bersih == teks_terbalik

# --- FUNGSI-FUNGSI PELAKSANA (Wrapper) ---

def jalankan_cek_kabisat():
    """
    Fungsi untuk menjalankan alur pengecekan tahun kabisat.
    Termasuk meminta input dan mencetak hasil.
    """
    print("\n--- 1. Pengecek Tahun Kabisat ---")
    try:
        tahun_input = int(input("Masukkan tahun (contoh: 2024): "))
        
        if cek_kabisat(tahun_input):
            print(f"Tahun {tahun_input} ADALAH tahun kabisat.")
        else:
            print(f"Tahun {tahun_input} BUKAN tahun kabisat.")
            
    except ValueError:
        print("Input tidak valid. Harap masukkan angka saja.")

def jalankan_cek_palindrom():
    """
    Fungsi untuk menjalankan alur pengecekan palindrom.
    Termasuk meminta input dan mencetak hasil.
    """
    print("\n--- 2. Pengecek Palindrom ---")
    
    # Meminta input (bisa teks atau angka)
    input_user = input("Masukkan kata, nama, kalimat, atau angka: ")

    # Pengecekan agar input tidak kosong
    if not input_user:
        print("Input tidak boleh kosong.")
        return

    # Cek dan cetak hasil
    if cek_palindrom(input_user):
        print(f"'{input_user}' ADALAH palindrom.")
    else:
        print(f"'{input_user}' BUKAN palindrom.")

# --- FUNGSI UTAMA (Menu) ---

def main():
    """
    Fungsi utama untuk menampilkan menu dan mengatur alur program.
    """
    # Loop akan terus berjalan sampai pengguna memilih '3' (Keluar)
    while True:
        # Tampilkan Pilihan Menu
        print("\n" + "="*30)
        print("  PROGRAM PENGECEK MULTIFUNGSI")
        print("="*30)
        print("Silakan pilih program:")
        print("  1. Cek Tahun Kabisat")
        print("  2. Cek Palindrom (Kata/Angka)")
        print("  3. Keluar")
        
        # Minta pilihan dari pengguna
        pilihan = input("Masukkan pilihan Anda (1, 2, atau 3): ")
        
        # Logika untuk menentukan pilihan
        if pilihan == '1':
            jalankan_cek_kabisat()
            print("-" * 30) # Garis pemisah
            
        elif pilihan == '2':
            jalankan_cek_palindrom()
            print("-" * 30) # Garis pemisah
            
        elif pilihan == '3':
            print("\nTerima kasih telah menggunakan program ini. Sampai jumpa!")
            break  # Hentikan loop 'while True' dan program berakhir
            
        else:
            print("\nPilihan tidak valid. Silakan masukkan 1, 2, atau 3.")
            print("-" * 30) # Garis pemisah

# Menjalankan fungsi utama saat script dieksekusi
if __name__ == "__main__":
    main()