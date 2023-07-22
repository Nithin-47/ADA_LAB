

void merge(vector<string>& names,vector<int>& array, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
  
        int *L = new int[n1];
        int *R = new int[n2];
        string *N1 = new string[n1];
        string *N2 = new string[n2];


    for (int i = 0; i < n1; i++)
       { 
        L[i] = array[l + i];
        N1[i] = names[l + i];
        }

        
    for (int j = 0; j < n2; j++)
      {  
          R[j] = array[m + 1 + j];
         N2[j] = names[m + 1 + j];
}
 
    int i = 0, j = 0;
    int k = l;
 
 
    while (i < n1 && j < n2) {
        if (L[n1] >= R[n2]) {
            array[k] = L[i];
            names[k] = N1[i];
            i++;
        }
        else {
            array[k] = R[j];
            names[k] = N2[j];
            j++;
        }
        k++;
    }
 
   
    while (i < n1) {
        array[k] = L[i];
        names[k] = N1[i];
        i++;
        k++;
    }
 
 
    while (j < n2) {
        array[k] = R[j];
        names[k] = N2[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
    delete[] N1;
    delete[] N2;
}
 

void mergeSort(vector<string>& names, vector<int>& array, int begin, int end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(names, array, begin, mid);
    mergeSort(names, array, mid + 1, end);
    merge(names, array, begin, mid, end);
}











class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    
    // vector<string> Names = names;
    mergeSort(names, heights, 0, heights.size()-1);



    return names;





    }
};


