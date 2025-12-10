def main():
    print("=== PROGRAM ANALISA NILAI ===")
    
    # 1. Parsing Input
    input_str = input("Masukkan nilai (pisahkan dengan spasi): ")
    
    # 2. Handle Edge Case (Input Kosong)
    if not input_str.strip():
        print("Error: Tidak ada data yang dimasukkan!")
        return # Berhenti di sini

    try:
        # Konversi input ke list of integers
        nilai_list = list(map(int, input_str.split()))
    except ValueError:
        # Handle Edge Case (Input bukan angka)
        print("Error: Masukkan hanya angka!")
        return

    # 3. Sorting Data
    nilai_list.sort()
    
    # 4. Hitung Statistik
    nilai_max = max(nilai_list)
    nilai_min = min(nilai_list)
    rata_rata = sum(nilai_list) / len(nilai_list)
    
    # 5. Output Statistik dengan F-string
    print("-" * 30)
    print(f"Nilai Terurut : {nilai_list}")
    print(f"Nilai Tertinggi: {nilai_max}")
    print(f"Nilai Terendah : {nilai_min}")
    print(f"Rata-rata     : {rata_rata:.2f}")
    print("-" * 30)
    
    # 6. Struktur Pintu Bertingkat (Nested If)
    print("STATUS KELULUSAN:")
    if rata_rata >= 75:
        if nilai_min >= 60:
            print("RESULT: LULUS MURNI (Semua syarat terpenuhi)")
        else:
            print("RESULT: LULUS BERSYARAT (Perlu remedial untuk nilai terendah)")
    else:
        print("RESULT: TIDAK LULUS (Rata-rata di bawah KKM)")

main()
