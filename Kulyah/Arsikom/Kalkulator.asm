.data
promptA:      .asciiz "Masukkan bilangan pertama (a): "
promptB:      .asciiz "Masukkan bilangan kedua (b): "
menu:         .asciiz "\nPilih operasi:\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\nMasukkan pilihan (1-4): "
hasilMsg:     .asciiz "\nHasil: "
sisaMsg:      .asciiz "  Sisa: "
errMsg:       .asciiz "\nPilihan tidak valid!\n"

.text
main:
    # Input bilangan pertama
    li $v0, 4
    la $a0, promptA
    syscall

    li $v0, 5
    syscall
    move $t0, $v0     # simpan a

    # Input bilangan kedua
    li $v0, 4
    la $a0, promptB
    syscall

    li $v0, 5
    syscall
    move $t1, $v0     # simpan b

    # Tampilkan menu
    li $v0, 4
    la $a0, menu
    syscall

    # Input pilihan operasi
    li $v0, 5
    syscall
    move $t2, $v0

    # Percabangan pilihan
    beq $t2, 1, tambah
    beq $t2, 2, kurang
    beq $t2, 3, kali
    beq $t2, 4, bagi
    j error

# -----------------------
# Operasi Penjumlahan
# -----------------------
tambah:
    add $t3, $t0, $t1
    j output_int

# -----------------------
# Operasi Pengurangan
# -----------------------
kurang:
    sub $t3, $t0, $t1
    j output_int

# -----------------------
# Operasi Perkalian
# -----------------------
kali:
    mul $t3, $t0, $t1
    j output_int

# -----------------------
# Operasi Pembagian
# -----------------------
bagi:
    beq $t1, $zero, error      # hindari pembagian nol
    div $t0, $t1
    mflo $t3      # hasil bagi
    mfhi $t4      # sisa
    j output_bagi

# -----------------------
# Output untuk operasi selain pembagian
# -----------------------
output_int:
    li $v0, 4
    la $a0, hasilMsg
    syscall

    li $v0, 1
    move $a0, $t3
    syscall

    j exit

# -----------------------
# Output khusus pembagian
# -----------------------
output_bagi:
    li $v0, 4
    la $a0, hasilMsg
    syscall

    li $v0, 1          # tampilkan hasil bagi
    move $a0, $t3
    syscall

    li $v0, 4          # tampilkan teks "Sisa:"
    la $a0, sisaMsg
    syscall

    li $v0, 1          # tampilkan sisa pembagian
    move $a0, $t4
    syscall

    j exit

# -----------------------
# Jika pilihan salah
# -----------------------
error:
    li $v0, 4
    la $a0, errMsg
    syscall
    j exit

# -----------------------
# Keluar program
# -----------------------
exit:
    li $v0, 10
    syscall
