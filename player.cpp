#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "list.h"
#include "player.h"
using namespace std;

void play_music (address P)
{
    string filename;

    filename=info(P).name;
    cout<<"Playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}

void play_next (address &P)
{
    P=next(P);
    play_music(P);
}

void play_prev (address &P)
{
    P=prev(P);
    play_music(P);
}

void play_last_played (address &P)
{
    play_music(P);
}

void play_repeat (list &L, address P)
{
    int n;

    cout<<"Repeat untuk : ";
    cin>>n;
    while (n>0)
    {
        P=first(L);
        play_music(P);
        play_next(P);
        while (P!=last(L))
        {
            play_next(P);
        }
        n--;
    }
}
