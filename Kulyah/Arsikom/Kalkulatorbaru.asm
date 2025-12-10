.data
promptA:      .asciiz "\nMasukkan bilangan pertama (a): "
promptB:      .asciiz "Masukkan bilangan kedua (b): "
promptC:      .asciiz "Masukkan bilangan ketiga (c): "  # <-- Input Baru
menu:         .asciiz "\nPilih operasi:\n1. Penjumlahan (a+b+c)\n2. Pengurangan (a-b-c)\n3. Perkalian (a*b*c)\n4. Pembagian (a/b/c)\n5. Keluar\nMasukkan pilihan (1-5): " # <-- Menu Update
hasilMsg:     .asciiz "\nHasil: "
errMsg:       .asciiz "\nPilihan tidak valid atau pembagian dengan nol!\n"
byeMsg:       .asciiz "\nTerima kasih telah menggunakan kalkulator ini.\n"

.text
main:
    # -------------------------
    # LOOP UTAMA PROGRAM
    # -------------------------
loop_start:
    
    # -------------------------
    # Input bilangan pertama (float) -> $f20
    # -------------------------
    li $v0, 4
    la $a0, promptA
    syscall

    li $v0, 6      # read float
    syscall
    mov.s $f20, $f0

    # -------------------------
    # Input bilangan kedua (float) -> $f22
    # -------------------------
    li $v0, 4
    la $a0, promptB
    syscall

    li $v0, 6
    syscall
    mov.s $f22, $f0

    # -------------------------
    # Input bilangan ketiga (float) -> $f24  <-- BAGIAN BARU
    # -------------------------
    li $v0, 4
    la $a0, promptC
    syscall

    li $v0, 6
    syscall
    mov.s $f24, $f0

    # -------------------------
    # Tampilkan menu operasi
    # -------------------------
    li $v0, 4
    la $a0, menu
    syscall

    li $v0, 5       # read integer
    syscall
    move $t0, $v0   # simpan pilihan di t0

    # -------------------------
    # Pilih operasi
    # -------------------------
    beq $t0, 1, tambah
    beq $t0, 2, kurang
    beq $t0, 3, kali
    beq $t0, 4, bagi
    beq $t0, 5, keluar_program  # <-- Pilihan Exit
    j error


# -------------------------
# Operasi Penjumlahan (a + b + c)
# -------------------------
tambah:
    add.s $f12, $f20, $f22  # f12 = a + b
    add.s $f12, $f12, $f24  # f12 = (a + b) + c
    jal output_float_2
    j loop_start            # Kembali ke awal (Loop)

# -------------------------
# Operasi Pengurangan (a - b - c)
# -------------------------
kurang:
    sub.s $f12, $f20, $f22  # f12 = a - b
    sub.s $f12, $f12, $f24  # f12 = (a - b) - c
    jal output_float_2
    j loop_start

# -------------------------
# Operasi Perkalian (a * b * c)
# -------------------------
kali:
    mul.s $f12, $f20, $f22  # f12 = a * b
    mul.s $f12, $f12, $f24  # f12 = (a * b) * c
    jal output_float_2
    j loop_start

# -------------------------
# Operasi Pembagian (a / b / c)
# -------------------------
bagi:
    li.s $f2, 0.0
    
    # Cek apakah b = 0
    c.eq.s $f22, $f2
    bc1t error     
    
    # Cek apakah c = 0 (Input baru juga tidak boleh 0)
    c.eq.s $f24, $f2
    bc1t error

    div.s $f12, $f20, $f22  # f12 = a / b
    div.s $f12, $f12, $f24  # f12 = (a / b) / c
    jal output_float_2
    j loop_start


# -------------------------
# Jika pilihan salah / Error
# -------------------------
error:
    li $v0, 4
    la $a0, errMsg
    syscall
    j loop_start    # Jangan exit, tapi kembali minta input

# -------------------------
# Pilihan Keluar Program
# -------------------------
keluar_program:
    li $v0, 4
    la $a0, byeMsg
    syscall
    j exit


# ============================================================
# OUTPUT FLOAT 2 DIGIT DESIMAL (Tidak diubah dari aslinya)
# ============================================================
output_float_2:
    # print "Hasil: "
    li $v0, 4
    la $a0, hasilMsg
    syscall

    # hasil float ada di $f12
    # kalikan x100 untuk mendapat nilai integer
    li.s $f2, 100.0
    mul.s $f4, $f12, $f2

    cvt.w.s $f6, $f4     # convert to integer
    mfc1 $t1, $f6        # t1 = hasil*100

    # integer part = t1 / 100
    li $t2, 100
    div $t1, $t2
    mflo $t3             # t3 = integer part
    mfhi $t4             # t4 = fractional part (0-99)

    # print integer part
    li $v0, 1
    move $a0, $t3
    syscall

    # print '.'
    li $v0, 11
    li $a0, '.'
    syscall

    # Pastikan fraction positif (jika hasil negatif)
    abs $t4, $t4

    # fractional selalu 2 digit
    blt $t4, 10, zero_pad

print_fraction:
    li $v0, 1
    move $a0, $t4
    syscall
    jr $ra

zero_pad:
    # print 0 jika fractional < 10
    li $v0, 11
    li $a0, '0'
    syscall

    # print angka fractional
    li $v0, 1
    move $a0, $t4
    syscall
    jr $ra


# -------------------------
# Keluar program (Syscall)
# -------------------------
exit:
    li $v0, 10
    syscall