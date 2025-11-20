#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main() {
    QueueEkspedisi queue;
    createQueue(queue);
    
    cout << "Memasukkan data paket sesuai soal..." << endl;
    
    // Input data paket sesuai soal
    Paket paket[] = {
        {"123456", "Hutao", 14, "Sumeru"},
        {"234567", "Ayaka", 10, "Fontaine"},
        {"345678", "Bennet", 7, "Nathan"},
        {"456789", "Furina", 16, "Liyue"},
        {"567890", "Nefer", 6, "Inazuma"}
    };
    
    // Enqueue semua data paket
    for (int i = 0; i < 5; i++) {
        if (!isFull(queue)) {
            if (isEmpty(queue)) {
                queue.Head = 0;
            }
            queue.Tail++;
            queue.dataPaket[queue.Tail] = paket[i];
        }
    }
    
    // 4) Tampilkan queue yang sudah diinputkan data paket
    cout << "\n4) Queue setelah diinputkan data paket:\n";
    viewQueue(queue);
    
    // 5) Lakukan deQueue sebanyak 1x
    cout << "\n5) Melakukan deQueue 1x...\n";
    deQueue(queue);
    
    // 6) Tampilkan queue yang sudah dilakukan deQueue 1x
    cout << "\n6) Queue setelah deQueue 1x:\n";
    viewQueue(queue);
    
    // Bagian B: Hitung total biaya pengiriman
    cout << "\n=== BAGIAN B ===\n";
    int total = TotalBiayaPengiriman(queue);
    cout << "Total Biaya Pengiriman: Rp " << total << endl;
    
    return 0;
}