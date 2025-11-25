.data
    prompt: .asciiz "Hasil perkalian (12 * 5) adalah: "
    newline: .asciiz "\n"

.text
.globl main

main:
    # 1. Inisialisasi Angka
    li $t0, 12   # Muat angka pertama (Multiplicand) ke $t0
    li $t1, 5    # Muat angka kedua (Multiplier) ke $t1

    # 2. Operasi Perkalian
    # Gunakan pseudo-instruction 'mul'
    mul $t2, $t0, $t1 # $t2 = $t0 * $t1 (yaitu 12 * 5 = 60)

    # 3. Output ke Konsol: Cetak Prompt
    li $v0, 4         # Kode layanan sistem untuk mencetak string (4)
    la $a0, prompt    # Muat alamat string 'prompt' ke $a0
    syscall

    # 4. Output ke Konsol: Cetak Hasil (Angka 60)
    li $v0, 1         # Kode layanan sistem untuk mencetak integer (1)
    move $a0, $t2     # Pindahkan hasil perkalian ($t2) ke register argumen $a0
    syscall

    # 5. Output ke Konsol: Cetak Baris Baru (Opsional, untuk kerapihan)
    li $v0, 4         # Kode layanan sistem untuk mencetak string (4)
    la $a0, newline   # Muat alamat string 'newline' ke $a0
    syscall

    # 6. Akhiri Program
    li $v0, 10        # Kode layanan sistem untuk keluar (exit) (10)
    syscall