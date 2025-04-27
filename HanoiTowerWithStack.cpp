#include <iostream>
using namespace std;


const int SIZE = 5;
struct Stack {
    int data[SIZE];
    int top;
};
Stack A, B, C;


void init(Stack &s) {
    s.top = -1;
}

// OPERASI STACK
void push(Stack &s, int data) {
    s.top++;
    s.data[s.top] = data;
}

int pop(Stack &s) {
    int data = s.data[s.top];
    s.top--;
    return data;
}

// FUNGSI MEMINDAHKAN LEMPENGAN 
void pindahkan(Stack &asal, Stack &tujuan, char namaAsal, char namaTujuan) {
    int batu = pop(asal);
    push(tujuan, batu);
    cout << "-> Pindahkan batu " << batu << " dari " << namaAsal << " ke " << namaTujuan << endl;
}

// FUNGSI UNTUK MENGATUR PEMINDAHAN LEMPENGAN 
void hanoi(int n, Stack &asal, Stack &bantu, Stack &tujuan, char namaAsal, char namaBantu, char namaTujuan) {
    if (n == 1) {
        pindahkan(asal, tujuan, namaAsal, namaTujuan);
    } else {
        hanoi(n-1, asal, tujuan, bantu, namaAsal, namaTujuan, namaBantu);
        pindahkan(asal, tujuan, namaAsal, namaTujuan);
        hanoi(n-1, bantu, asal, tujuan, namaBantu, namaAsal, namaTujuan);
    }
}


int main() {
cout << "===============================" << endl;
cout << " | Menara Hanoi dengan Stack | " << endl;
cout << "===============================" << endl;


    init(A);
    init(B);
    init(C);

    push(A, 3);
    push(A, 2);
    push(A, 1);

    hanoi(3, A, B, C, 'A', 'B', 'C');
    return 0;
}
