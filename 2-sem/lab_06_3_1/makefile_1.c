app.exe:
    lab_06

lab_06:
    lab_06_3_1.o min.o
    gcc lab_06_3_1.o min.o -o minimum -std=c99

lab_06_3_1.o:
    lab_06_3_1.c
    gcc -c lab_06_3_1.c -std=c99

min.o:
    min.c
    gcc -c min.c -std=c99

clean:
    rm -rf *.o lab_06
