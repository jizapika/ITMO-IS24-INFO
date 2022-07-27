import matplotlib.pyplot as plt
import math

# константы
q = 1.602176634 * 10**-19
m = 9.1093837815 * 10**-31
ep_0 = 8.854185 * 10**-12

# ввод данных (для моего варианта - это "0.1 0.21 850000 0.29")
print('Введите через пробел r, R, V0 и L в единицах СИ:')
r, R, V0, L = map(float, input().split())

# образуем класс, который будет хранить характеристики электрона
class electron:
  def __init__(self):
    self.t = 0
    self.dt = 10**-10
    self.x = 0
    self.y = (R + r) / 2
    self.Vx = V0
    self.Vy = 0
    self.tmax = L / V0
  def A(self, U):
    return - U * q / (math.log(R / r) * self.y * m)
  def made_way (self, U):
    while self.t < self.tmax and self.y > r:
      self.Vy += self.A(U) * self.dt
      self.y += self.Vy * self.dt
      self.x += self.Vx * self.dt
      self.t += self.dt
  def relations(self, U):
    array_t = []
    array_x = []
    array_y = []
    array_Vy = []
    array_a = []
    while self.t < self.tmax and self.y > r:
      array_t.append(self.t)
      array_x.append(self.x)
      array_y.append(self.y)
      array_Vy.append(self.Vy)
      array_a.append(self.A(U))
      self.Vy += self.A(U) * self.dt
      self.y += self.Vy * self.dt
      self.x += self.Vx * self.dt
      self.t += self.dt
    return array_t, array_x, array_y, array_Vy, array_a

# напишем поиск Umin при помощи двоичного поиска с относительной точностью в 1e-9
def find_Umin():
  Umin = 10**-9
  Umax = 10**9
  while Umax - Umin > 10**-9 * Umin:
    U = (Umax + Umin) / 2
    other = electron()
    other.made_way(U)
    if L > other.x:
      Umax = U
    else:
      Umin = U
  return Umin

# выведем найденную минимальную разность потенциалов
Umin = find_Umin()
print("Umin =", Umin)

# соберём данные электрона для построения графиков
our_electron = electron()
array_t, array_x, array_y, array_Vy, array_a = our_electron.relations(Umin)

plot_graph(array_x, array_y, "y(x)", "x, м", "y, м")
plot_graph(array_t, array_Vy, "Vy(t)", "t, с", "vy, м/с")
plot_graph(array_t, array_a, "ay(t)", "t, с", "ay, м/с^2")
plot_graph(array_t, array_y, "y(t)", "t, с", "y, м")

print("время полёта составляет", array_t[-1], "c")
print("конечная скорость составляет", (array_Vy[-1]**2 + V0**2)**0.5, "м/c")
