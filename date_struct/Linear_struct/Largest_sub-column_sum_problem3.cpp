/*给定K个整数组成的序列{ N1, N2, ..., NK}，“连续子列”被定义为{ Ni, Ni+1, ..., Nj}，
其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，
其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。*/

//Divide and conquer algorithm  o(nln(n))
struct array{
    int a[100001];
    int n;
};
int sub(array *a, int left , int right);

#include<iostream>

#define max3(a,b,c) ((a>b)?a:(b>c)?b:c) //宏定义，三数最大值

int main()
{
    array *a = new array;
    int n;
    //输入个数
    std::cin >> n ;

    a->n=n;
    //输入
    for(int i = 0 ; i < a->n ; i++){
        std::cin >> a->a[i] ;
    }
    std::cout << sub(a,0,a->n-1) << std::endl;
    //释放new出的数组
    delete[] a;
    return 0;
}

int sub(array *a, int left ,int right){

    int mid = (left+right) / 2 ;

    int leftmaxsum = 0 ;
    int rightmaxsum = 0 ;     

    int leftms = 0 ; //左侧最大值
    int rightms = 0 ; //右侧最大值
    //退出条件
    if(left == right){
        return a->a[left] ;
    }
    leftms = sub(a,left,mid); //左最大子序列和 
    rightms = sub(a,mid+1,right); //右最大子序列和

    int tempsum = 0;

    for(int i = mid ; i >= 0 ; i--){
        tempsum+=a->a[i];
        if(tempsum>leftmaxsum){
            leftmaxsum = tempsum;
        }
    }

    tempsum = 0;
    for(int i = mid+1 ; i <= right ; i++){
        tempsum+=a->a[i];
        if(tempsum>rightmaxsum){
            rightmaxsum = tempsum;
        }
    }
    return max3(leftms,rightms,leftmaxsum+rightmaxsum);
}