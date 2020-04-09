#pragma once
//===================================================
#include <queue>

//===================================================
// MedianStorage is a class for storing numbers and calculating of median
// Computing of the median is based on "min-max-median heap" algoritm
// Time complexicity:
// addValue  -> O(log(n))
// getMedian -> O(1)

template <class T>
class MedianStorage
{
public:

	//-----------------------------------------------
	MedianStorage() = default;
	//-----------------------------------------------
	virtual ~MedianStorage() {}

	//-----------------------------------------------
	virtual void addValue(T aValue) 
	{
		if (m_maxHeap.empty() || aValue <= m_maxHeap.top())
		{
			m_maxHeap.push(aValue);
			if (m_maxHeap.size() > m_minHeap.size() + 1)
			{
				m_minHeap.push(m_maxHeap.top());
				m_maxHeap.pop();
			}
		}
		else
		{
			m_minHeap.push(aValue);
			if (m_minHeap.size() > m_maxHeap.size())
			{
				m_maxHeap.push(m_minHeap.top());
				m_minHeap.pop();
			}
		}
	}

	//-----------------------------------------------
	virtual T getMedian() const
	{
		if (m_maxHeap.empty())
			return 0;

		if (m_maxHeap.size() == m_minHeap.size())
			return (m_maxHeap.top() + m_minHeap.top()) / 2;
		else
			return m_maxHeap.top();
	}

protected:

	// max-heap
	std::priority_queue<T> m_maxHeap;
	// min-heap
	std::priority_queue<T, std::vector<T>, std::greater<> > m_minHeap;
};