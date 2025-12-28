import time
import random
import matplotlib.pyplot as plt
from prettytable import PrettyTable


class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash_function(self, key):
        return key % self.size

    def insert(self, key):
        index = self.hash_function(key)
        self.table[index].append(key)

    def search_iterative(self, key):
        index = self.hash_function(key)
        for item in self.table[index]:
            if item == key:
                return True
        return False
    def search_recursive(self, bucket, key, idx=0):
        if idx >= len(bucket):
            return False
        if bucket[idx] == key:
            return True
        return self.search_recursive(bucket, key, idx + 1)

    def recursive_wrapper(self, key):
        index = self.hash_function(key)
        return self.search_recursive(self.table[index], key)


n_values = []
recursive_times = []
iterative_times = []


def print_execution_table():
    table = PrettyTable()
    table.field_names = ["n", "Recursive Time (s)", "Iterative Time (s)"]

    for i in range(len(n_values)):
        table.add_row([
            n_values[i],
            f"{recursive_times[i]:.8f}",
            f"{iterative_times[i]:.8f}"
        ])
    print(table)


def update_graph():
    plt.figure(figsize=(9, 6))
    plt.plot(n_values, recursive_times, marker='o', label='Recursive')
    plt.plot(n_values, iterative_times, marker='o', label='Iterative')

    plt.title("Performance Comparison: Recursive vs Iterative\nHash Table Search")
    plt.xlabel("Number of Elements (n)")
    plt.ylabel("Execution Time (seconds)")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    print(n_values)
    plt.show()

while True:
    try:
        n = int(input("Masukkan jumlah data (n) atau -1 untuk keluar: "))
        if n == -1:
            print("Program selesai.")
            break
        if n <= 0:
            print("Masukkan nilai n > 0")
            continue

        n_values.append(n)

        hash_table = HashTable(size=max(10, n // 2))

        data = [random.randint(0, n // 2) for _ in range(n)]
        for item in data:
            hash_table.insert(item)

        search_key = -1
        start = time.perf_counter()
        hash_table.recursive_wrapper(search_key)
        recursive_times.append(time.perf_counter() - start)
        start = time.perf_counter()
        hash_table.search_iterative(search_key)
        iterative_times.append(time.perf_counter() - start)

    
        print_execution_table()
        update_graph()

    except ValueError:
        print("Input tidak valid.")
