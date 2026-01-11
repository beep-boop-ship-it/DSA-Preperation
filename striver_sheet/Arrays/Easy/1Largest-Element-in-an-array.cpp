/*
    arr[] = {1,5,6,8,9,6,25}
    o/p ---> 25
*/


#include <iostream>
using namespace std;

int main(){
  int arr[5] = { -25,0,1,5,8};

  int ans = arr[0];
  for (int i = 0; i < arr.size(); i++){
        if(arr[i] > ans) ans = arr[i];
  cout<<"Max Element is --->"<<ans<<endl;
  return 0;

  }
  
