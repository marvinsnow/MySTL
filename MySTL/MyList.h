#pragma once
#include <cstdint>

template<class T>
struct MyListNode
{
	MyListNode()
	{
		m_pPre = nullptr;
		m_pNext = nullptr;
	}


	MyListNode(T value)
	{
		m_value = value;
		m_pPre = nullptr;
		m_pNext = nullptr;
	}
	
	T m_value;
	MyListNode* m_pPre;
	MyListNode* m_pNext;
};

template<class T>
class MyList
{
public:
	MyList();
	~MyList();

public:
	T Insert(T value);
	bool Delete(int32_t index);
	T* Get(int32_t index);
	bool Set(int32_t index, T value);
public:
	size_t GetLength();
	size_t GetNodeCount();
	bool IsEmpty();
	MyListNode<T>* GetHeader();
	MyListNode<T>* GetTail();
private:
	void InitMyList();
private:
	MyListNode<T>* m_pHead;
	MyListNode<T>* m_pTail;

	size_t	m_length;
};

template<class T>
MyListNode<T>* MyList<T>::GetTail()
{
	return m_pTail;
}

template<class T>
MyListNode<T>* MyList<T>::GetHeader()
{
	return m_pHead;
}

template<class T>
MyList<T>::~MyList()
{
	MyListNode<T>* pCurNode = m_pHead->m_pNext;
	while (pCurNode != m_pTail)
	{
		MyListNode<T>* pTmpNode = pCurNode->m_pNext;

		pCurNode->m_pPre->m_pNext = pCurNode->m_pNext;
		pCurNode->m_pNext->m_pPre = pCurNode->m_pPre;

		delete pCurNode;
		--m_length;

		pCurNode = pTmpNode;
	}

	std::cout << "MyList length=" << m_length << ", nodeCount=" << GetNodeCount();

	delete m_pHead;
	delete m_pTail;	
}

template<class T>
MyList<T>::MyList()
{
	InitMyList();
}

template<class T>
size_t MyList<T>::GetNodeCount()
{
	size_t count = 0;
	MyListNode<T>* pCurNode = m_pHead->m_pNext;
	while (pCurNode != m_pTail)
	{
		++count;
		pCurNode = pCurNode->m_pNext;
	}

	return count;
}

template<class T>
bool MyList<T>::IsEmpty()
{
	return 0 == m_length;
}

template<class T>
size_t MyList<T>::GetLength()
{
	return m_length;
}

template<class T>
bool MyList<T>::Set(int32_t index, T value)
{
	int32_t max_index = GetNodeCount() - 1;
	if (index > max_index)
	{
		return false;
	}

	int32_t curIndex = 0;
	MyListNode<T>* pCurNode = m_pHead->m_pNext;
	while (pCurNode != m_pTail)
	{
		if (curIndex == index)
		{
			pCurNode->m_value = value;
			return true;
		}

		pCurNode = pCurNode->m_pNext;
		++curIndex;
	}

	return false;
}

template<class T>
T* MyList<T>::Get(int32_t index)
{
	int32_t max_index = GetNodeCount() - 1;
	if (index > max_index)
	{
		return nullptr;
	}

	int32_t curIndex = 0;
	MyListNode<T>* pCurNode = m_pHead->m_pNext;
	while (pCurNode != m_pTail)
	{
		if (curIndex == index)
		{
			return &pCurNode->m_value;
		}

		pCurNode = pCurNode->m_pNext;
		++curIndex;
	}

	return nullptr;
}

template<class T>
bool MyList<T>::Delete(int32_t index)
{
	int32_t curIndex = 0;
	MyListNode<T>* pCurNode = m_pHead->m_pNext;
	while (pCurNode != m_pTail)
	{
		if (curIndex == index)
		{
			pCurNode->m_pPre->m_pNext = pCurNode->m_pNext;
			pCurNode->m_pNext->m_pPre = pCurNode->m_pPre;
			delete pCurNode;
			--m_length;
			return true;
		}

		pCurNode = pCurNode->m_pNext;
		++curIndex;
	}

	return false;
}

template<class T>
T MyList<T>::Insert(T value)
{
	MyListNode<T>* pNewNode = new MyListNode<T>(value);
	m_pTail->m_pPre->m_pNext = pNewNode;
	pNewNode->m_pPre = m_pTail->m_pPre;
	pNewNode->m_pNext = m_pTail;
	m_pTail->m_pPre = pNewNode;

	++m_length;
	return pNewNode->m_value;
}

template<class T>
void MyList<T>::InitMyList()
{
	m_pHead = new MyListNode<T>();
	m_pTail = new MyListNode<T>();

	m_pHead->m_pNext = m_pTail;
	m_pTail->m_pPre = m_pHead;
	m_length = 0;
}


