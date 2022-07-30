import math
# im(0,0,1) - идеальная мачта
# ip - идеальная пушка
# np - нормальная пушка (нормаль, от которой всё отсчитывается)
fr = open('input.txt', 'r', encoding = 'utf-8')
fw = open('output.txt', 'w', encoding = 'utf-8')
r = list(fr)
ux, uy = map(float, r[0].strip().split())
ax, ay = map(float, r[1].strip().split())
mx, my = map(float, r[2].strip().split())
wx, wy = map(float, r[3].strip().split())
uz = az = wz = imx = imy = 0
mz = imz = 1
# np = a X im
npx = ay * imz - az * imy
npy = az * imx - ax * imz
npz = ax * imy - ay * imx
# мой корабль - корабль врага: вектор ip(ipx, ipy, ipz)
ipx = wx - ux
ipy = wy - uy
ipz = wz - uz
# найдём угол между вектором нормальной пушки и вектором к врагу
a = math.acos((ipx * npx + ipy * npy + ipz * npz)/(math.sqrt(ipx * ipx + ipy * ipy + ipz * ipz)*math.sqrt(npx * npx + npy * npy + npz * npz)))
# если этот угол меньше 60, то атака с правой стороны, если больше 120, то с левой
psevdoscal = ipx * npy - npx * ipy
e = 0
a = 45*a/math.atan(1)
if a < 60 and psevdoscal >= 0:
    a = -a
    e = 1
elif a < 60 and psevdoscal < 0:
    e = 1
elif a > 120 and psevdoscal >= 0:
    e = 2
    a = a - 180
elif a > 120 and psevdoscal < 0:
    e = 2
    a = 180 - a
# также посчитаем угол мачты с нормальной пушкой, чтобы вывести ответ нужного знака
b = math.acos((mx * npx + my * npy + mz * npz)/(math.sqrt(mx * mx + my * my + mz * mz)*math.sqrt(npx * npx + npy * npy + npz * npz)))
b = 45*b/math.atan(1) - 90
if e == 2:
    fw.write("1\n" + str(a) + "\n" + str(b) + "\n" + "Never gonna give you up")
elif e == 1:
    fw.write("-1\n" + str(a) + "\n" + str(b) + "\n" + "Never gonna give you up")
else:
    fw.write("0\nCongratulations. You win!")
fr.close();
fw.close();
