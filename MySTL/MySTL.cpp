/********************************************************************

Copyright (C), 2021

FileName: MySTL.cpp

Description:

Author: mawenxue

Created: 2021/03/12

history: 2021-3-12 13:27 by mawenxue

*********************************************************************/

#include <iostream>
#include "MyList.h"

template<class T>
void PrintMyList(MyList<T>& myList)
{
    MyListNode<T>* pHeader = myList.GetHeader();
    MyListNode<T>* pTail = myList.GetTail();

    MyListNode<T>* pCurNode = pHeader->m_pNext;
    while (pCurNode != pTail)
    {
        std::cout << pCurNode->m_value << "\t";
        pCurNode = pCurNode->m_pNext;
    }

    std::cout << std::endl;
}


int main()
{
    MyList<int32_t> myList;

    PrintMyList<int32_t>(myList);
    for (int i = 0; i<10; i++)
    {
        int32_t curValue = myList.Insert(i + 1);
        std::cout << "myList.GetNodeCount()=" << myList.GetNodeCount()
            << ", myList.GetLength()=" << myList.GetLength()
            << ", curValue="<< curValue
            << std::endl;
    }
    PrintMyList<int32_t>(myList);

    int32_t* value_before = myList.Get(2);
	std::cout << "before myList.GetNodeCount()=" << myList.GetNodeCount()
		<< ", myList.GetLength()=" << myList.GetLength()
		<< ", value_before=" << *value_before
		<< std::endl;
    bool isdeleteOk = myList.Delete(2);
    PrintMyList<int32_t>(myList);
    int32_t* value_after = myList.Get(2);
	std::cout << "after myList.GetNodeCount()=" << myList.GetNodeCount()
		<< ", myList.GetLength()=" << myList.GetLength()
		<< ", isdeleteOk=" << isdeleteOk
		<< ", value=" << *value_after
		<< std::endl;

    bool isSetOk = myList.Set(2, 3);
    PrintMyList<int32_t>(myList);
    int32_t* value_final = myList.Get(2);
    std::cout << "myList.GetNodeCount()=" << myList.GetNodeCount()
		<< ", myList.GetLength()=" << myList.GetLength()
		<< ", isSetOk=" << isSetOk
        << ", value_final=" << *value_final
		<< std::endl;

    return 0;
}