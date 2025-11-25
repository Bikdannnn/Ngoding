#Tugas 1 Pemrograman Script M. Wildan Humaidi S. Budi

#string
nama = "Wildan" 

#int
umur = 19 

#float
tinggi = 173.5

#boolean
sigma = True 

#none
hati = None

#list
list_hobi = ["solat", "mengaji", "olahraga", ] 
mhs_wildan = {
    "NIM":"D121241058",
    "Jurusan":"Teknik Infomatika"
}


#pemanggilan fungsi
umur_int=int(umur)
panjangnama =len(nama)
def printidentitas(nama, panjangnama, umur_int, tinggi, sigma):
    print(nama)
    print(umur_int)
    print(tinggi)
    print(sigma)

printidentitas(nama, panjangnama, umur, tinggi, sigma)
print(list_hobi[0], list_hobi[1], list_hobi[2])