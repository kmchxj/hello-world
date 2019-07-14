#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

vector<vector<int>> findSumOf0(vector<int> a,int length)
{
    vector<vector<int>> result;
    if(length<3)
        return result;
    sort(a.begin(),a.end());
    for(int i=0;i<length-2;i++)
    {
        int target=0-a[i];
        int low=i+1;
        int high=length-1;
        while(low<high)
        {
            if(target>a[low]+a[high])
                low++;
            else if(target<a[low]+a[high])
                high--;
            else{
                //相等，则进入记录序列
                vector<int> temp(3);
                temp[0]=a[i];
                temp[1]=a[low];
                temp[2]=a[high];
                result.push_back(temp);
                while(low<high && a[low+1]==temp[1]) low++;
                while(low<high && a[high-1]==temp[2]) high--;
            }
        }
    }
    return result;
}


int main(int argc, char *argv[])
{
    int b[]={1,3,5,-2,-1,-9,10,4,-5};
    vector<int> a;
    for(int i=0;i<9;i++)
        a.push_back(b[i]);
    vector<vector<int>> result=findSumOf0(a,9);
    for(int i=0;i<result.size();i++)
    {
    	for(int j=0;j<3;j++)
    		cout<<result[i][j]<<" ";
    	cout<<endl;
	}
    //system("PAUSE");
    return EXIT_SUCCESS;
}

