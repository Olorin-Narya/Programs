class SortBuilder
{
public:
    static CommandSort *NewSort(const string typeofSort , const int * vetor)
    {
        if (typeofSort == 'MergeSort')
            return new MergeSort;
        if (typeofSort == 'QuickSort')
            return new QuickSort;
        if (typeofSort == 'ShellSort')
            return new ShellSort;
        if (typeofSort == 'TimSort')
            return new TimSort;
        if (typeofSort == 'HeapSort')
            return new HeapSort;
        if (typeofSort == 'InsertionSort')
            return new InsertionSort;
        return NULL;
    }
};
