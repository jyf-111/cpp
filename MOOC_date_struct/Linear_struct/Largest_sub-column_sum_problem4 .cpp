/*给定K个整数组成的序列{ N1, N2, ..., NK}，“连续子列”被定义为{ Ni, Ni+1, ..., Nj}，
其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，
其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。*/

//online algorithm o(n)
struct array{
    int a[100001];
    int n;
};
int sub(array *a);

#include<iostream>

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
    std::cout << sub(a) << std::endl;

    delete[] a;
    return 0;
}

int sub(array *a){
    int thissum,maxsum;
    thissum=maxsum=0;
    for(int i = 0 ; i<a->n ;i++){
        //累加
        thissum+=a->a[i];
        
        if(thissum>maxsum){ //当前和大于最大和，重制最大和

            maxsum=thissum;
            
        }else if(thissum<0){ //当前和小于0舍弃
            thissum=0;
        }
    }
    return maxsum;
}