#include <iostream>
using namespace std;

// Ukuran maksimum stack
const int SIZE = 5;

// Stack dan variabel top untuk setiap tiang
int A[SIZE], topA = -1;
int B[SIZE], topB = -1;
int C[SIZE], topC = -1;

// Operasi dasar stack
void push(int stack[], int &top, int data) {
    top++;
    stack[top] = data;
}

int pop(int stack[], int &top) {
    int data = stack[top];
    top--;
    return data;
}

// Fungsi untuk memindahkan batu
void pindahkan(int stackAwal[], int &topAwal, int stackAkhir[], int &topAkhir, char asal, char tujuan) {
    int batu = pop(stackAwal, topAwal);
    push(stackAkhir, topAkhir, batu);
    cout << "Pindahkan batu " << batu << " dari " << asal << " ke " << tujuan << endl;
}

// Fungsi rekursif Menara Hanoi
void hanoi(int n, int A[], int &topA, int B[], int &topB, int C[], int &topC, char asal, char bantu, char tujuan) {
    if (n == 1) {
        pindahkan(A, topA, C, topC, asal, tujuan);
    } else {
        hanoi(n-1, A, topA, C, topC, B, topB, asal, tujuan, bantu);
        pindahkan(A, topA, C, topC, asal, tujuan);
        hanoi(n-1, B, topB, A, topA, C, topC, bantu, asal, tujuan);
    }
}

int main() {
    // Isi batu ke tiang A (30, 20, 10)
    push(A, topA, 30);
    push(A, topA, 20);
    push(A, topA, 10);

    // Mulai proses Hanoi
    hanoi(3, A, topA, B, topB, C, topC, 'A', 'B', 'C');

    return 0;
}
