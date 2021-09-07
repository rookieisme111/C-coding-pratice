#include <iostream>
#include <vector>
using namespace std;

void quick_Sort(vector<int> & ,int l, int r);
void show(int * nums,int len);
void Merge(vector<int>& arr , int p, int q, int r);
void Merge_sort(vector<int> & arr, int left, int right );

int main(){
    using namespace std;
    int n;
    cout << "Enter length of array n(n>=0)= ";
    cin >> n;
    cin.get();
    int i=0;
    int* nums = new int[n];
    cout << "enter " << i+1 << " number:";
    while (i<n && (cin >> nums[i])){
        ++i;
        if (i<n)
            cout << "enter " << i+1 << " number:";
    }
    show(nums,n);

    vector<int> arr(nums,nums+n);
    Merge_sort(arr,0,n-1);

    for (int j=0; j<n ; j++)
        cout << arr[j];

    system("pause");
    delete[] nums;
    return 0;


}

void show(int* nums, int n){
    for (int i=0; i<n; i++)
        cout << *(nums+i);
    cout << endl;
}


void quick_Sort(vector<int>& array, int left, int right)
{
	if(left < right)
	{
		int pivot = array[left];
		int low = left, high = right;
		while(low < high)
		{
			while(array[high] >= pivot && low < high)
				high--;
			array[low] = array[high];
			
			while(array[low] <= pivot && low < high)
				low++;
			array[high] = array[low];
		}
		array[low] = pivot;
		
		quick_Sort(array, left, low - 1);
		quick_Sort(array, low + 1, right);
	}
}

void Merge(vector<int> & arr, int p, int q, int r){
    int n = r-p+1;
    int left1 = p,left2 = q+1;
    int* tmp = new int[n];
    int i=0;
    while( left1<=q && left2<=r )
        tmp[i++]=arr[left1]<=arr[left2] ? arr[left1++] : arr[left2++];
    while( left1<=q )
        tmp[i++]=arr[left1++];
    while( left2<=r )
        tmp[i++]=arr[left2++];
    for (int j=0; j<n; j++)
        arr[p+j]=tmp[j];

    delete [] tmp;
}

void Merge_sort (vector<int> & arr, int left, int right){
    if(left==right)
        return;
    int mid = (left+right)/2;
    Merge_sort(arr,left,mid);
    Merge_sort(arr,mid+1,right);
    Merge(arr,left,mid,right);
}