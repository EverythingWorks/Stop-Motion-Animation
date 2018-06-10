fp = open("sam.txt", "w")
licz = 50
krok = 13
krok_sl = -10
poz_sl = 440
frame = 0
poz_l = - 30
poz_p_one=0
for i in range(80):

    fp.write("{}, 100\n\
kolor_wypelnienia 70 100 255\n\
prostokat 0 0 800 800 1\n\
kolor_wypelnienia 255 255 0\n\
kolo 320 60 50 1\n\
kolor_wypelnienia 0 210 0\n\
prostokat 0 200 800 800 1\n\
kolor_wypelnienia 200 0 0\n".format(frame))
    poz_l += krok
    poz_p_one += krok
 
#drugi samochodzik
    fp.write("kolor_wypelnienia 0 79 250\n\
pr {0} 300 {1} 320 1\n\
pr {3} 285 {2} 300 1\n\
tr {2} 285 {1} 300 {2} 300 1\n\
tr {3} 285 {3} 300 {0} 300 1\n\
kolor_wypelnienia 0 0 0\n\
kolo {4} 304 11 1\n\
kolo {5} 304 11 1\n".format(poz_l,poz_l+80, poz_l+40, poz_l+20, poz_l+66, poz_l+3))
    fp.write("kp 0 0 0\n\
ln {0} 301 {0} 319\n\
kolor_wypelnienia 150 150 150\n\
kolo {1} 307 8 1\n\
kolo {2} 307 8 1\n\
kolor_wypelnienia 102 184 212\n\
pr {3} 286 {4} 299 1\n\
tr {4} 286 {5} 299 {4} 299 1\n".format(poz_l+30, poz_l+69, poz_l+6, poz_l+21,poz_l+39, poz_l+75))
    fp.write("stop\n")
    frame += 1

    

krok = 10
poz_p_one = 800
poz_l = 0
size_x = 60
size_Y = 30
bang = False
poz_p = 800
poz_p_one = 800

"""
    kolor_wypelnienia 70 100 255
prostokat 0 0 800 800 1
kolor_wypelnienia 255 255 0
kolo 320 60 50 1
kolor_wypelnienia 0 210 0
prostokat 0 200 800 800 1

kolor_wypelnienia 250 0 62
pr 720 300 800 320 1
pr 760 285 780 300 1
tr 780 285 800 300 780 300 1
tr 760 285 760 300 720 300 1
kolor_wypelnienia 0 0 0
kolo 786 304 11 1
kolo 723 304 11 1
kp 0 0 0
ln 770 301 770 319
kolor_wypelnienia 150 150 150
kolo 789 307 8 1
kolo 726 307 8 1
kolor_wypelnienia 102 184 212
pr 761 286 779 299 1
tr 759 286 725 299 759 299 1



kolor_wypelnienia 0 79 250
pr 0 300 80 320 1
pr 20 285 40 300 1
tr 40 285 80 300 40 300 1
tr 20 285 20 300 0 300 1
kolor_wypelnienia 0 0 0
kolo 66 304 11 1
kolo 3 304 11 1
kp 0 0 0
ln 30 301 30 319
kolor_wypelnienia 150 150 150
kolo 69 307 8 1
kolo 6 307 8 1
kolor_wypelnienia 102 184 212
pr 21 286 39 299 1
tr 41 286 75 299 41 299 1
    """
while not bang:
    if poz_p_one <= poz_l+80:
        bang = True
    fp.write("{}, 100\n\
kolor_wypelnienia 70 100 255\n\
prostokat 0 0 800 800 1\n\
kolor_wypelnienia 255 255 0\n\
kolo 320 60 50 1\n\
kolor_wypelnienia 0 210 0\n\
prostokat 0 200 800 800 1\n".format(frame))
    fp.write("kolor_wypelnienia 250 0 62\n\
pr {0} 300 {1} 320 1\n\
pr {2} 285 {3} 300 1\n\
tr {3} 285 {1} 300 {3} 300 1\n\
tr {2} 285 {2} 300 {0} 300 1\n".format(poz_p_one-80, poz_p_one, poz_p_one-40, poz_p_one-20))
    fp.write("kolor_wypelnienia 0 0 0\n\
kolo {0} 304 11 1\n\
kolo {1} 304 11 1\n\
kp 0 0 0\n\
ln {2} 301 {2} 319\n".format(poz_p_one-14, poz_p_one-77, poz_p_one-30))
    fp.write("kolor_wypelnienia 150 150 150\n\
kolo {0} 307 8 1\n\
kolo {1} 307 8 1\n\
kolor_wypelnienia 102 184 212\n\
pr {2} 286 {3} 299 1\n\
tr {4} 286 {5} 299 {4} 299 1\n".format(poz_p_one-11, poz_p_one-74, poz_p_one-39, poz_p_one-21, poz_p_one-41, poz_p_one-75))
#drugi samochodzik
    fp.write("kolor_wypelnienia 0 79 250\n\
pr {0} 300 {1} 320 1\n\
pr {3} 285 {2} 300 1\n\
tr {2} 285 {1} 300 {2} 300 1\n\
tr {3} 285 {3} 300 {0} 300 1\n\
kolor_wypelnienia 0 0 0\n\
kolo {4} 304 11 1\n\
kolo {5} 304 11 1\n".format(poz_l,poz_l+80, poz_l+40, poz_l+20, poz_l+66, poz_l+3))
    fp.write("kp 0 0 0\n\
ln {0} 301 {0} 319\n\
kolor_wypelnienia 150 150 150\n\
kolo {1} 307 8 1\n\
kolo {2} 307 8 1\n\
kolor_wypelnienia 102 184 212\n\
pr {3} 286 {4} 299 1\n\
tr {4} 286 {5} 299 {4} 299 1\n".format(poz_l+30, poz_l+69, poz_l+6, poz_l+21,poz_l+39, poz_l+75))
    fp.write("stop\n")
    
    poz_p_one -= krok
    poz_l += krok
    frame += 1

for i in range(20):
    if i % 2:
        fp.write("{}, 100\n\
kolor_wypelnienia 200 200 0\n\
prostokat 0 0 800 800 1\nstop\n".format(frame))
    else:
        fp.write("{}, 100\n\
kolor_wypelnienia 200 0 0\n\
prostokat 0 0 800 800 1\nstop\n".format(frame))
    frame += 1

fp.write("{},  1000\n\
kolor_wypelnienia 200 0 0\n\
prostokat 0 0 800 800 1\n\
obraz 100 100 ./bang.png")
