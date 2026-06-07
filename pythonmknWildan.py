import math

def f(x, y):
    return 1 + y**2

def euler(x0, y0, b, h):
    n = int(round((b - x0) / h))
    x, y = x0, y0
    for _ in range(n):
        y = y + h * f(x, y)
        x = x + h
    return y

def heun(x0, y0, b, h):
    n = int(round((b - x0) / h))
    x, y = x0, y0
    for _ in range(n):
        y_predict = y + h * f(x, y)
        y = y + (h / 2.0) * (f(x, y) + f(x + h, y_predict))
        x = x + h
    return y

def rk3(x0, y0, b, h):
    n = int(round((b - x0) / h))
    x, y = x0, y0
    for _ in range(n):
        k1 = h * f(x, y)
        k2 = h * f(x + h / 2.0, y + k1 / 2.0)
        k3 = h * f(x + h, y - k1 + 2.0 * k2)
        y = y + (k1 + 4.0 * k2 + k3) / 6.0
        x = x + h
    return y

def rk4(x0, y0, b, h):
    n = int(round((b - x0) / h))
    x, y = x0, y0
    for _ in range(n):
        k1 = h * f(x, y)
        k2 = h * f(x + h / 2.0, y + k1 / 2.0)
        k3 = h * f(x + h / 2.0, y + k2 / 2.0)
        k4 = h * f(x + h, y + k3)
        y = y + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0
        x = x + h
    return y

# Parameter Masukan
x0, y0 = 0.0, 0.0
b = 0.20
h = 0.10

# Perhitungan Solusi Eksak
sejati = math.tan(b)

# Eksekusi Program
print("=== HASIL PROGRAM KOMPUTER UNTUK y({b}) ===")
print("Solusi Sejati       : {sejati:.10f}")
print("Metode Euler        : {euler(x0, y0, b, h):.10f}")
print("Metode Heun         : {heun(x0, y0, b, h):.10f}")
print("Runge-Kutta Orde 3  : {rk3(x0, y0, b, h):.10f}")
print("Runge-Kutta Orde 4  : {rk4(x0, y0, b, h):.10f}")
