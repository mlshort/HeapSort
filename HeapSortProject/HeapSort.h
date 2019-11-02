/**
*  @file       HeapSort.h
*  @brief      Implementation of the Heap Sort algorithm
*
*  @author     Mark L. Short
*  @date       October 19, 2014
*  @cite       Introduction to Algorithms, Thomas H. Cormen, Charles E. Leiserson, 
*              Ronald L. Rivest, Clifford Stein
*/

#if !defined(__HEAPSORT_H__)
#define __HEAPSORT_H__

#ifndef _IOSTREAM_
    #include <iostream>
#endif

#ifndef _IOMANIP_
    #include <iomanip>
#endif

#if defined(UNICODE) || defined(_UNICODE)
    #define tcout std::wcout
#else
    #define tcout std::cout
#endif



constexpr const size_t INDEX_ERROR = (size_t) -1;

/**
 *  @brief  prints the contents of an array to standard out
 *
 *  @param [in] rg        address of the array to output
 *  @param [in] nSize     number of elements in the array
 */
template<typename T>
void printArray ( const T* rg, size_t nSize )
{
    tcout << _T("{ ");

    int iNewLineCtr = 0;
    for ( size_t i = 0; i < nSize; i++ )
    {
        tcout << std::setw(4) << rg[i].GetData() << ' ';
        iNewLineCtr++;

        if ((iNewLineCtr % 10) == 0)
            tcout << std::endl << _T("  ");
    }

    tcout << _T("}") << std::endl;
}


/**
 *  @brief Calculates a node's Parent index
 *
 *  @param [in] nIndex
 *
 *  @retval size_t   the index of the Parent
 *  @retval size_t   INDEX_ERROR on error
 */
constexpr size_t Parent ( size_t nIndex )
{
    if ( nIndex > 0 )
        return ( nIndex - 1 ) / 2;
    else
        return INDEX_ERROR; // error result
};

/**
 *  @brief Calculates the Left Child's index
 *
 *  @param [in] nIndex
 *
 *  @retval size_t   the index of the Left Child
 */
constexpr size_t Left ( size_t nIndex )
{
    return 2 * nIndex + 1;
};

/**
 *  @brief Calculates the Right Child's index
 *
 *  @param [in] nIndex
 *
 *  @retval size_t   the index of the Right Child
 */
constexpr size_t Right ( size_t nIndex )
{
    return 2 * nIndex + 2;
};

/**
 *  The MaxHeapify function, which runs in O(lg n) time, is the key to maintaining
 *  the max-heap property.
 *
 *  @param [in,out] rgHeapData   target array
 *  @param [in]     nHeapSize    number of elements of the array
 *  @param [in]     nRoot        index of the root node
 *
 */
template <typename T> 
void MaxHeapify ( T* rgHeapData, size_t nHeapSize, size_t nRoot)
{
    size_t nLargest    = nRoot; // initialize largest as the root
    size_t nLeftChild  = Left ( nRoot );
    size_t nRightChild = Right ( nRoot );

// find the index containing the largest value among { Root, Left Child, Right Child }
    if ( ( nLeftChild < nHeapSize ) && ( rgHeapData[nLeftChild] > rgHeapData[nRoot] ) )
        nLargest = nLeftChild;

    if ( ( nRightChild < nHeapSize ) && ( rgHeapData[nRightChild] > rgHeapData[nLargest] ) )
        nLargest = nRightChild;


    if ( nLargest != nRoot )
    {
// move the largest to the Root position
        std::swap ( rgHeapData[nRoot], rgHeapData[nLargest] );
// run again with the Root position of sub-tree
        MaxHeapify ( rgHeapData, nHeapSize, nLargest );
    }
};

/**
 *  The BuildMaxHeap function converts an Array into a max-heap in a bottom-up manner.
 *  Build's the heap in array a so that largest value is at rgHeapData[0]
 *  The BuildMaxHeap() operation is run once, and is O(n) in performance.
 *
 *  @param [in,out] rgHeapData  target array
 *  @param [in]     nHeapSize   number of elements of the array
 *
 */
template<typename T>
void BuildMaxHeap ( T* rgHeapData, size_t nHeapSize )
{
    size_t nRoot = Parent(nHeapSize);

    for (int i = nRoot; i >= 0; i--)
        MaxHeapify(rgHeapData, nHeapSize, i);
};

/**
 *  The HeapSort function, which runs in O(n lg n) time, sorts an array
 *  in place
 *
 *  @param [in, out] rgHeapData    an unordered array
 *  @param [in]      nHeapSize     the number of elements of the array
 *
 *  @sa https://en.wikipedia.org/wiki/Heapsort
 *
 */
template<typename T>
void HeapSort ( T* rgHeapData, size_t nHeapSize )
{
    // do some basic error checking before proceeding
    if ( ( rgHeapData == nullptr ) || ( nHeapSize < 1 ) )
        return;

    // transform the array into a heap
    BuildMaxHeap ( rgHeapData, nHeapSize );

#ifdef VERBOSE
    // print content of array after BuildMaxHeap has been called
    tcout << _T ( "Content of array after 'BuildMaxHeap' has been called" ) << std::endl;
    tcout << _T ( "-----------------------------------------------------" ) << std::endl;
    tcout << _T ( "heap_size:" ) << nHeapSize << std::endl;
    printArray ( rgHeapData, nHeapSize );
    tcout << std::endl;

    int iOutputCounter = 0;  // variable used to keep count of when to output array content
#endif

    // basically, what this is doing is using the heap-sort algorithm to:
    // 1. move the largest element to rgData[nLast]
    // 2. decrement the nLast position marker
    // 3. rebuild the heap in order to propagate the largest
    //    element of the new sub-heap to rgData[0] for the next iteration.

    // note - this just feels highly inefficient for what we are trying
    // to accomplish here....

    // One by one extract an element from heap
    for ( size_t nLast = nHeapSize - 1; nLast > 0; nLast-- )
    {
        // Move current root to end
        std::swap ( rgHeapData[0], rgHeapData[nLast] );

        // call max heapify on the reduced heap
        MaxHeapify ( rgHeapData, nLast, 0 );


#ifdef VERBOSE
/*
    Regarding 'heap_size':

    heap-sort is implemented as an algorithm and *not* a data-structure with
    integral characteristics nor attributes.  The algorithm has no concept of
    'heap_size' outside of what is passed in governing the limiting bounds of
    the array and what the 'nLast' variable used to denote the index of the
    last array element during the process of building a final, in-place, sorted
    array of values.

    In that context, 'nLast' will be used to satisfy the requirement of outputting
    a 'heap_size' value.
*/

        iOutputCounter++;
        
        if ( ( iOutputCounter % 10 ) == 0 )
        {
            // print content of array after BuildMaxHeap has been called
            tcout << _T ( "Content of array after " ) << iOutputCounter 
                  << _T ( " elements have been removed " ) << std::endl;
            tcout << _T ( "-------------------------------------------------------" ) << std::endl;

            tcout << _T ( "heap_size:" ) << nLast << std::endl;
            printArray ( rgHeapData, nLast );
            tcout << std::endl;
        }
#endif

    }

    return;

};


#endif