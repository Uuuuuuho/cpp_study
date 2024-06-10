CC = g++
CXXFLAGS = -Wall

all: 01_stack2 02_list 02_array_list 02_doubly_linked_list 03_hash 03_hash1 03_hash2 04_binary_tree 05_maxheap 05_maxheap1 05_maxheap2 06_binary_search_tree 06_binary_search_tree1 07_mstree 08_kruskal 09_prim 10_sollin 11_heapsort 12_bubblesort 13_polynomial 14_equivalence 15_shortest_path 16_binary_search 17_merge_sort 18_quick_sort 19_insertion_sort

%.o: %.h %.cpp mstree.h
	$(CC) $(CXXFLAGS) %.h %.cpp -o %.exe

clean:
	rm -rf *.o *.exe *.gch`