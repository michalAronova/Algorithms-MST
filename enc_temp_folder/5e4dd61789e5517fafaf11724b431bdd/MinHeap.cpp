#include "MinHeap.h"

MinHeap::MinHeap(vector<int>& minArray)
{
	m_PriorityQueue = SetPairArray(minArray);
	m_heapSize = minArray.size();
	SetLocationArr();
	Build();
}

vector<HeapPair> MinHeap::SetPairArray(vector<int>& minArray)
{
	vector<HeapPair> pairArr;
	HeapPair currPair;
	for (int i = 0; i < minArray.size(); i++)
	{
		currPair.SetData(i + 1);
		currPair.SetPriority(minArray[i]);
		pairArr.push_back(currPair);
	}
	return pairArr;
}

void MinHeap::FixHeap(int index)
{
	int min;
	int left = Left(index);
	int right = Right(index);

	if (left < m_PriorityQueue.size() - 1 && m_PriorityQueue[left].GetPriority() < m_PriorityQueue[index].GetPriority())
	{
		min = left;
	}
	else
	{
		min = index;
	}
	if (right < m_PriorityQueue.size() - 1 && m_PriorityQueue[right].GetPriority() < m_PriorityQueue[min].GetPriority())
	{
		min = right;
	}

	if (min != index)
	{
		SwapPairsAndLocations(m_PriorityQueue[index], m_PriorityQueue[min]);
		FixHeap(min);
	}
}

void MinHeap::Build()
{
	for(int i = m_PriorityQueue.size()/2 - 1; i>=0 ; i--)
	{
		FixHeap(i);
	}
}
             
HeapPair MinHeap::DeleteMin()
{
	if (IsEmpty())
		throw "Can't delete minimum, heap is empty!";
	else
	{
		HeapPair deleted = m_PriorityQueue[0];
		m_PriorityQueue[0] = m_PriorityQueue[m_PriorityQueue.size() - 1];
		m_LocationsArray[deleted.GetData() - 1] = -1;
		m_LocationsArray[m_PriorityQueue[0].GetData() - 1] = 0;
		FixHeap(0);
		return deleted;
	}
}
bool MinHeap::IsEmpty()
{
	return m_PriorityQueue.size() == 0;
}

void MinHeap::DecreaseKey(int vertex, int newKey)
{
	int place = m_LocationsArray[vertex - 1];
	m_PriorityQueue[place].SetPriority(newKey);
	while(place > 0 && m_PriorityQueue[place].GetPriority() > m_PriorityQueue[Parent(place)].GetPriority())
	{
		SwapPairsAndLocations(m_PriorityQueue[place], m_PriorityQueue[Parent(place)]);
		place = Parent(place);
	}
}

void MinHeap::SetLocationArr()
{
	for(int i=0;i<m_PriorityQueue.size();i++)
	{
		m_LocationsArray.push_back(i);
	}
}

void MinHeap::Swap(HeapPair& pair1, HeapPair& pair2)
{
	HeapPair temp = pair1;
	pair1 = pair2;
	pair2 = temp;
}

void MinHeap::SwapLocations(int index1, int index2)
{
	int temp = m_LocationsArray[index1 - 1];
	m_LocationsArray[index1 - 1] = m_LocationsArray[index2 - 1];
	m_LocationsArray[index2 - 1] = temp;
}

void MinHeap::SwapPairsAndLocations(HeapPair& pair1, HeapPair&pair2)
{
	SwapLocations(pair1.GetData(), pair2.GetData());
	Swap(pair1, pair2);
}