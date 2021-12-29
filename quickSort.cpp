#include<iostream>

using namespace std;



int partition(int *arr, int l, int r){
	int pivot = arr[r];
	int pIndex = l;
	for(int i=l;i<r;i++){
		if(arr[i] <= pivot){
			swap(arr[i], arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex], arr[r]);
	return pIndex;
}

void quickSort(int *arr, int l, int r){
	if(l < r){
		int j = partition(arr, l, r);
		quickSort(arr, l, j-1);
		quickSort(arr, j+1, r);
	}
}

int main(){
	int arr[] = {1, 0, 34, 43, 3, 2};
	for(int i=0;i<6;i++) cout<<arr[i]<<" ";
	cout<<endl;
	quickSort(arr, 0, 5); // size - 1
	for(int i=0;i<6;i++) cout<<arr[i]<<" ";
	
	return 0;
}
