.data
string1: .asciiz "Masukkan bilangan pertama: "
string2: .asciiz "Masukkan bilangan kedua: "
string3: .asciiz "Hasil perkalian adalah: "
string4: .asciiz "\n"
string5: .asciiz "Jika hasil perkalian = 99, maka program akan keluar.\n"
string6: .asciiz "Goodbye.."

.text
.globl main

main:
    # --- Print Header ---
    li $v0, 4            # syscall print string
    la $a0, string5
    syscall

    li $v0, 4            # syscall print string (newline)
    la $a0, string4
    syscall

loop_main:
    # --- Input 1 ---
    jal proc_input1      # panggil prosedur input 1
    or $s0, $zero, $v0   # simpan hasil ke $s0

    # --- Input 2 ---
    jal proc_input2      # panggil prosedur input 2
    or $s1, $zero, $v0   # simpan hasil ke $s1

    # --- Proses Kali ---
    jal proc_kali        # panggil prosedur kali
    or $s2, $zero, $v0   # simpan hasil perkalian ke $s2

    # --- Output ---
    jal proc_output      # panggil prosedur output
    
    # --- Newline ---
    li $v0, 4
    la $a0, string4
    syscall
    li $v0, 4
    la $a0, string4
    syscall

    # --- Cek Kondisi Keluar (99) ---
    li $t8, 99
    # Cek apakah hasil ($s2) != 99. Jika ya, ulang ke loop_main (bukan main awal agar tidak print header terus)
    bne $s2, $t8, loop_main 

    # --- Exit Program ---
    li $v0, 4
    la $a0, string6
    syscall
    
    li $v0, 10           # syscall exit
    syscall

# ----------------------------------------------
# Prosedur Input 1
# ----------------------------------------------
proc_input1:
    li $v0, 4
    la $a0, string1
    syscall
    
    li $v0, 5            # syscall read integer
    syscall
    jr $ra               # KEMBALI (Gunakan JR, bukan J)

# ----------------------------------------------
# Prosedur Input 2
# ----------------------------------------------
proc_input2:
    li $v0, 4
    la $a0, string2
    syscall
    
    li $v0, 5            # syscall read integer
    syscall
    jr $ra               # KEMBALI

# ----------------------------------------------
# Prosedur Perkalian (Loop Penjumlahan)
# ----------------------------------------------
proc_kali:
    or $t0, $zero, $zero # inisialisasi hasil = 0
    or $t1, $s1, $zero   # copy pengali ke $t1
    
    # Catatan: Algoritma ini hanya bekerja untuk bilangan positif
ulang: 
    beq $t1, $zero, exit_kali # jika pengali habis (0), keluar
    add $t0, $t0, $s0    # tambah hasil dengan bilangan pertama
    addi $t1, $t1, -1    # kurangi counter pengali
    j ulang

exit_kali:
    or $v0, $zero, $t0   # kembalikan hasil di $v0
    jr $ra

# ----------------------------------------------
# Prosedur Output
# ----------------------------------------------
proc_output:
    # Print text "Hasil..."
    li $v0, 4
    la $a0, string3
    syscall

    # Print Angka Hasil
    li $v0, 1            # syscall print integer
    or $a0, $zero, $s2   # PERBAIKAN: Ambil nilai dari $s2 (hasil yang disimpan di main)
    syscall
    
    jr $ra