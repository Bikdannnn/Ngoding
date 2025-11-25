# 1. ABSTRACTION & CONTRACT: Kelas Induk Abstrak
from abc import ABC, abstractmethod

class Kendaraan(ABC):
    def __init__(self, merek, model):
        self.merek = merek
        self.model = model

    @abstractmethod
    def perilaku_inti(self):
        pass

    def info_dasar(self):
        return f"{self.merek} {self.model}"

# 2. CONSTRUCTOR & INHERITANCE Dan 3. ENCAPSULATION & VALIDATION
class Mobil(Kendaraan):
    def __init__(self, merek, model, tipe_mesin):
        # 2. Inheritance: Memanggil constructor induk
        super().__init__(merek, model)
        self.tipe_mesin = tipe_mesin
        # 3. Encapsulation: Atribut dilindungi
        self._kecepatan = 0

    # 3. Setter & Getter dengan Validasi
    @property
    def kecepatan(self):
        return self._kecepatan

    @kecepatan.setter
    def kecepatan(self, nilai_baru):
        if nilai_baru < 0 or not isinstance(nilai_baru, (int, float)):
            print(f"Kecepatan '{nilai_baru}' tidak valid. Dipertahankan: {self._kecepatan} km/jam.")
            return
        self._kecepatan = nilai_baru
        print(f"Kecepatan diatur: {self._kecepatan} km/jam.")

    # 1. Implementasi Abstraction
    def perilaku_inti(self):
        return f"Mobil ({self.tipe_mesin}) menyala dan melaju pada {self._kecepatan} km/jam."

# 4. POLYMORPHISM SETUP
class Motor(Kendaraan):
    def __init__(self, merek, model, kapasitas_cc):
        # 2. Constructor & Inheritance
        super().__init__(merek, model)
        self.kapasitas_cc = kapasitas_cc
        self._is_gas_ditarik = False

    # 4. Implementasi Abstraction (Perilaku berbeda)
    def perilaku_inti(self):
        self._is_gas_ditarik = True
        return f"Motor {self.model} ({self.kapasitas_cc}cc) dihidupkan dengan suara *vroom-vroom* dan siap melaju kencang."


# 5. POLYMORPHISM DEMONSTRATION
def demonstrasi_perilaku(objek):
    print(f"\nPerilaku Objek: {objek.info_dasar()}")
    print(f"Hasil: {objek.perilaku_inti()}")

if __name__ == "__main__":
    mobil_listrik = Mobil("Tesla", "Model Y", "Elektrik")
    motor_ninja = Motor("Kawasaki", "Ninja R15", 150)

    # 3. Demo Encapsulation & Validation
    print("\n[DEMO ENCAPSULATION & VALIDATION]")
    print(f"Kecepatan awal Mobil: {mobil_listrik.kecepatan} km/jam") # Getter
    mobil_listrik.kecepatan = 90  # Setter valid
    mobil_listrik.kecepatan = -5  # Setter gagal validasi
    print(f"Kecepatan akhir Mobil: {mobil_listrik.kecepatan} km/jam") # Getter

    # 5. Demo Polymorphism
    print("\n[DEMO POLYMORPHISM]")
    demonstrasi_perilaku(mobil_listrik)
    demonstrasi_perilaku(motor_ninja)
    
    print("\nDemonstrasi 5 Konsep OOP Selesai.")