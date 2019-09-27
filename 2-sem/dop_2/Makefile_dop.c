app.exe:
    dop_3

dop_03:
    dop_03.o
    gcc dop_03.o -std=c99

dop_03.o:
    dop_03.c
    gcc -c dop_03.c -std=c99

clean:
    rm -rf *.o dop_03
