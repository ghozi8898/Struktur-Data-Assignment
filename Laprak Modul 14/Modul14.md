# <h1 align="center">Laporan Praktikum Modul Graph (14)</h1>
<p align="center">Muhammad Fathir Al Ghozi</p>

## Dasar Teori
###
Dalam teori graf, sebuah graf dilambangkan sebagai G = (V, E) dengan V sebagai himpunan simpul dan E sebagai himpunan sisi yang menghubungkan pasangan simpul. Representasi adjacency list mengasosiasikan setiap simpul dengan daftar tetangganya, sehingga meminimalkan ruang untuk graf yang jarang (sparse) dibandingkan adjacency matrix yang memiliki ruang O(V²). Algoritma DFS menelusuri graf melalui jalur sedalam mungkin sebelum backtracking, sedangkan BFS menelusuri graf berdasarkan jarak dari simpul awal (level demi level).

## Guided 

### 1. graph.cpp

```C++

#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```


### 2. graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;      //menyimpan data node (misal: char/int)
    int visited;        //Penanda untuk traversal (0/1) (penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung
    adrNode Next;     //Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node;  //Pointer yang menunjuk ke lokasi node tujuan
    adrEdge Next;  //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang)
};

struct Graph {
    adrNode First;  //Pointer ke node pertama dalam list graph
};

void CreateGraph(Graph &G);  //prosedur untuk mengeset fitur dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data);  //alokasi node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);  //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data);  //menambahkan node ke dalam graph
adrNode FindNode(Graph G, infoGraph data);  //function untuk mencari alamat node berdasarkan nilai info yang diberikan
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan dua node (membuat edge dari info1 ke info2)
void DisconnectNode(adrNode node1, adrNode node2);  //prosedur untuk memutuskan hubungan dua node (menghapus edge dari node1 ke node2)
void DeleteNode(Graph &G, infoGraph X);  //prosedur untuk menghapus node X beserta semua Edge yang terhubung

void PrintInfoGraph(Graph G);  //Menampilkan isi graph(Adjency list)
void ResetVisited(Graph &G);  //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo);  //traversal Breadth Search / BFS (Menggunakan queue untuk menelusuri node berdasarkan tingkat)
void PrintDFS(Graph G, infoGraph StartInfo);  //traversal Depth First Search / DFS (menggunakan stack untuk menelusuri node secara mendalam)

#endif
```

### 3. main.cpp

```C++
#include "graph.h"
#include "graph.cpp"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    
    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "node E berhasil dihapus" << endl;
    } else {
        cout << "Node E tidak berhasil dihapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS

    return 0;
}
```
#### Output
<img width="1160" height="749" alt="image" src="https://github.com/user-attachments/assets/bed39a09-4f1d-4a6e-8054-fbfc2a5422f2" />

#### Full screenshot
<img width="1919" height="1014" alt="image" src="https://github.com/user-attachments/assets/e982516e-f7ac-455c-9519-9340d011fc19" />




## Unguided  2
### 2. Unguided 

### graph.cpp
```C++
#include "graph.h"
#include <queue>

/* === GRAPH DASAR === */
void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->Next;
    }
    return NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    if (FindNode(G, X) == NULL) {
        adrNode P = AllocateNode(X);
        if (G.first == NULL)
            G.first = P;
        else {
            adrNode Q = G.first;
            while (Q->Next != NULL)
                Q = Q->Next;
            Q->Next = P;
        }
    }
}

/* Graph Tidak Berarah → edge dua arah */
void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = AllocateEdge(N2);
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = AllocateEdge(N1);
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

/* === UTIL === */
void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

/* === DFS === */
void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1)
        return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->Node->visited == 0)
            PrintDFS(G, E->Node);
        E = E->Next;
    }
}

/* === BFS === */
void PrintBFS(Graph G, adrNode N) {
    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
}

```

### graph.h
```C++
#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

/* === PRIMITIF GRAPH === */
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);

void PrintInfoGraph(Graph G);

/* === TRAVERSAL === */
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif

```

### main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    /* Insert Node */
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');

    /* Connect Node */
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'E'));
    ConnectNode(FindNode(G, 'D'), FindNode(G, 'E'));

    cout << "Graph (Adjacency List):" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS Traversal: ";
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));

    cout << "\n\nBFS Traversal: ";
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));

    cout << endl;
    return 0;
}

```
#### Output
<img width="1039" height="344" alt="image" src="https://github.com/user-attachments/assets/4c0df645-ea61-48f4-bf5d-997199e28def" />

#### Full Screenshot
<img width="1919" height="1020" alt="image" src="https://github.com/user-attachments/assets/348ab270-2ea1-42cb-9f4d-20c62ae96f80" />


###
## Penjelasan
Program di atas mengimplementasikan struktur data graf tak berarah dengan representasi adjacency list multilist di mana setiap node menyimpan daftar sisi (edges) yang terhubung ke node lain menggunakan pointer. Fungsi-fungsi seperti InsertNode, ConnectNode, dan FindNode membangun graf dengan menambah simpul dan menghubungkannya dua arah, kemudian PrintInfoGraph menampilkan daftar tetangga setiap simpul. Bagian traversal menggunakan dua algoritma dasar dalam teori graf: Depth-First Search (DFS) yang menjelajah simpul sedalam mungkin secara rekursif, dan Breadth-First Search (BFS) yang menjelajah level demi level menggunakan queue, dengan penggunaan flag visited untuk menghindari kunjungan ulang ke simpul yang sama dalam satu kali traversal. Representasi adjacency list disimpan secara efisien hanya menyimpan sisi yang ada tanpa ruang ekstra seperti pada matriks kedekatan. 
Wikipedia

Dari sudut teori graf (graph theory), struktur graf didefinisikan sebagai pasangan himpunan simpul (vertices) dan sisi (edges), di mana algoritma traversal seperti DFS dan BFS merupakan prosedur standar untuk mengunjungi semua simpul dalam graf secara sistematik. DFS menelusuri jauh ke kedalaman terlebih dahulu sebelum kembali (backtracking), sedangkan BFS mengunjungi simpul menunggu di tingkat yang sama sebelum ke tingkat berikutnya, dan keduanya bekerja dalam kompleksitas waktu O(V+E) pada representasi adjacency list dengan V simpul dan E sisi. Representasi adjacency list dipilih karena efisien untuk graf yang tidak terlalu padat (sparse).

###
## Kesimpulan 
ADT Graph yang diimplementasikan pada kode tersebut berhasil merepresentasikan graf tidak berarah menggunakan adjacency list berbasis multilist, sehingga struktur graf dapat dibangun secara dinamis dan efisien dari sisi memori, khususnya untuk graf yang bersifat sparse. Operasi dasar seperti penambahan simpul, penghubungan antar simpul, serta penelusuran hubungan antar simpul dapat dilakukan secara sistematis melalui pointer, sesuai dengan konsep dasar struktur data graf.

Selain itu, penerapan algoritma Depth-First Search (DFS) dan Breadth-First Search (BFS) membuktikan bagaimana teori graf diterjemahkan ke dalam implementasi nyata untuk melakukan penelusuran simpul secara menyeluruh tanpa pengulangan, dengan kompleksitas waktu O(V + E). Dengan demikian, kode ini tidak hanya memenuhi kebutuhan fungsional praktikum, tetapi juga selaras dengan dasar teori graf dan algoritma traversal yang diakui secara akademik dan luas digunakan dalam pengembangan perangkat lunak serta pemodelan jaringan.

## Referensi
###
Putra, R. L. S., Sandy, M., & Aprilia Putri, A. (2025). Implementasi teori graf dan optimisasi algoritma Dijkstra, BFS dan DFS dalam menentukan jalur terpendek jaringan Toko Mixue di Jabodetabek berbasis Google Maps. Jurnal Multimedia dan Teknologi Informasi, 7(03), 619–629. https://doi.org/10.54209/jatilima.v7i03.1649
###
Kammer, F., & Sajenko, A. (2018). Linear-Time In-Place DFS and BFS on the Word RAM. arXiv. Presents theoretical underpinnings for efficient DFS and BFS traversal on adjacency structures.
###
Kolosovskiy, M. A. (2009). Data structure for representing a graph: combination of linked list and hash table. arXiv. This work discusses adjacency list advantages in graph representation and efficiency. 
###
Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to algorithms (4th ed.). MIT Press.
