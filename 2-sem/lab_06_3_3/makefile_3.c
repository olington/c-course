app.exe:
    lab_06

lab_06:
    lab_06_3_1.o
    gcc lab_06_3_1.o -std=c99

lab_06_3_1.o:
    lab_06_3_1.c
    gcc -c lab_06_3_1.c -std=c99

clean:
    rm -rf *.o lab_06

test.exe:
    lab_06

lab_06:
    lab_06_3_1.o
    gcc lab_06_3_1.o -std=c99

lab_06_3_1.o:
    lab_06_3_1.c
    gcc -c lab_06_3_1.c -std=c99

mod_test.o:
    mod_test.c
    gcc -c mod_test.c -std=c99

clean:
    rm -rf *.o lab_06
