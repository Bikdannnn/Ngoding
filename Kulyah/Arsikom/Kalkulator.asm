.data
promptA:      .asciiz "Masukkan bilangan pertama (a): "
promptB:      .asciiz "Masukkan bilangan kedua (b): "
menu:         .asciiz "\nPilih operasi:\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\nMasukkan pilihan (1-4): "
hasilMsg:     .asciiz "\nHasil: "
errMsg:       .asciiz "\nPilihan tidak valid!\n"

.text
main:
    # -------------------------
    # Input bilangan pertama (float)
    # -------------------------
    li $v0, 4
    la $a0, promptA
    syscall

    li $v0, 6      # read float
    syscall
    mov.s $f0, $f0 # simpan di f0
    mov.s $f20, $f0

    # -------------------------
    # Input bilangan kedua (float)
    # -------------------------
    li $v0, 4
    la $a0, promptB
    syscall

    li $v0, 6
    syscall
    mov.s $f22, $f0

    # -------------------------
    # Tampilkan menu operasi
    # -------------------------
    li $v0, 4
    la $a0, menu
    syscall

    li $v0, 5
    syscall
    move $t0, $v0   # pilihan

    # -------------------------
    # Pilih operasi
    # -------------------------
    beq $t0, 1, tambah
    beq $t0, 2, kurang
    beq $t0, 3, kali
    beq $t0, 4, bagi
    j error


# -------------------------
# Operasi Penjumlahan
# -------------------------
tambah:
    add.s $f12, $f20, $f22
    jal output_float_2
    j exit

# -------------------------
# Operasi Pengurangan
# -------------------------
kurang:
    sub.s $f12, $f20, $f22
    jal output_float_2
    j exit

# -------------------------
# Operasi Perkalian
# -------------------------
kali:
    mul.s $f12, $f20, $f22
    jal output_float_2
    j exit

# -------------------------
# Operasi Pembagian
# -------------------------
bagi:
    li.s $f2, 0.0
    c.eq.s $f22, $f2
    bc1t error     # jika b = 0.0

    div.s $f12, $f20, $f22
    jal output_float_2
    j exit


# -------------------------
# Jika pilihan salah
# -------------------------
error:
    li $v0, 4
    la $a0, errMsg
    syscall
    j exit


# ============================================================
# OUTPUT FLOAT 2 DIGIT DESIMAL
# ============================================================
output_float_2:
    # print "Hasil: "
    li $v0, 4
    la $a0, hasilMsg
    syscall

    # hasil float ada di $f12
    # kalikan ×100 untuk mendapat nilai integer
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
# Keluar program
# -------------------------
exit:
    li $v0, 10
    syscall
