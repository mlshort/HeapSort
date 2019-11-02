/**
 * @file       HeapSortCopyCounter.cpp
 * @brief      Heap Sort Copy Counter class
 *
 * @author     Mark L. Short
 * @date       October 19, 2014
 */

#include "stdafx.h"
#include "HeapSortCopyCounter.h"

std::ostream& operator<< (std::ostream& os, const CHeapSortCopyCounter& rhs)
{
    os << rhs.m_iData;
    return os;
}

std::istream& operator>> (std::istream& is, CHeapSortCopyCounter& rhs)
{
    is >> rhs.m_iData;
    return is;
};