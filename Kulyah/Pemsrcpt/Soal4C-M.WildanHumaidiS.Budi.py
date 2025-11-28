import numpy as np

# M. Wildan Humaidi S. Budi D121241058

data_sales = np.array([150, 180, 140, 220, 240, 195, 170])
print(f"Data Awal: {data_sales}")

mean_val = np.mean(data_sales)
print(f"1. Mean (Rata-rata): {mean_val:.2f}")

std_val = np.std(data_sales)
print(f"2. Standard Deviation: {std_val:.2f}")

max_val = np.max(data_sales)
max_idx = np.argmax(data_sales)
min_val = np.min(data_sales)
min_idx = np.argmin(data_sales)

print(f"3. Nilai Max: {max_val} (pada indeks {max_idx})")
print(f"   Nilai Min: {min_val} (pada indeks {min_idx})")

norm_sales = (data_sales - min_val) / (max_val - min_val)
print("4. Hasil Normalisasi [0, 1]:")
print(norm_sales)