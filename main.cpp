#include <iostream>
#include <thread>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "graphics.h"

using namespace std;

int c;
int meta_x = 600;

void* carrera(void*) {
    while (!kbhit()) {
        c = rand() % 4;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main() {
    initwindow(805, 550, "Carrera de Caballos", 100, 100);
    setbkcolor(RGB(0, 0, 0));
    cleardevice();
    readimagefile("imagen\\meta.JPG", 764, 20, 794, 432);
    outtextxy(760, 440, "META");

    pthread_t hilo;
    pthread_create(&hilo, NULL, carrera, NULL);
    int Cab_1 = 50, Cab_2 = 50, Cab_3 = 50, Cab_4 = 50;

    while (!kbhit()) {
        switch (c) {
            case 0:
                Cab_1++;
                readimagefile("imagen\\horse.JPG", Cab_1++, 0, 164 + Cab_1, 108);
                break;
            case 1:
                Cab_2++;
                readimagefile("imagen\\horse.JPG", Cab_2++, 108, 164 + Cab_2, 216);
                break;
            case 2:
                Cab_3++;
                readimagefile("imagen\\horse.JPG", Cab_3++, 216, 164 + Cab_3, 324);
                break;
            case 3:
                Cab_4++;
                readimagefile("imagen\\horse.JPG", Cab_4++, 324, 164 + Cab_4, 432);
                break;
        }

        delay(20);
        outtextxy(300, 500, "El caballo ganador es: ");
        if (Cab_1 >= meta_x) {
            outtextxy(450, 500, "Caballo UNO!!! ");
            break;
        } else if (Cab_2 >= meta_x) {
            outtextxy(450, 500, "Caballo DOS!!! ");
            break;
        } else if (Cab_3 >= meta_x) {
            outtextxy(450, 500, "Caballo TRES!!! ");
            break;
        } else if (Cab_4 >= meta_x) {
            outtextxy(450, 500, "Caballo CUATRO!!! ");
            break;
        }
    }

    pthread_join(hilo, NULL);
    return 0;
}
