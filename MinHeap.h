#ifndef _MINHEAP_H
	#define  _MINHEAP_H

using namespace std;
#include <vector>

class HeapPair
{
private:
	int m_Data;
	int m_Priority;
public:
	HeapPair(int data = 0, int key = 0) { SetData(data); SetPriority(key); }
	void SetData(int data) { m_Data = data; }
	void SetPriority(int key) { m_Priority = key; }
	int GetData() { return m_Data; }
	int GetPriority() { return m_Priority; }
};

class MinHeap {
private:
	vector<HeapPair> m_PriorityQueue;
	vector<int> m_LocationsArray;

	void FixHeap(int index);

	static int Parent(int index) { return (index - 1) / 2; };
	static int Left(int index) { return 2 * index + 1; };
	static int Right(int index) { return 2 * index + 2; };

public:
	MinHeap(vector<int>& minArray);
	void             Build();
	HeapPair		 DeleteMin();								//DELETE MIN
	bool             IsEmpty();									//IS EMPTY
	void             DecreaseKey(int vertex, int newKey);		//DECREASE KEY

	vector<HeapPair> SetPairArray(vector<int>& minArray);
	void	SetLocationArr();
	void	SwapPairsAndLocations(HeapPair&, HeapPair&);
	void	Swap(HeapPair&, HeapPair&);
	void	SwapLocations(int index1, int index2);
};

#endif
	