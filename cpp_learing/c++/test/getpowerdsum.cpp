/*���һ��������int getpowerdsum(int a, int b)������0 < a < 10��1<b<10000��
���������a^b������λ������֮�ͣ������ظú�ֵ�����磬2^10=1024����ôgetpowerdsum(2, 10)�ķ���ֵΪ1+0+2+4=7��
����main����ִ�к�
int main(int argc, char** argv) {
	cout << getpowerdsum(9,10)<< endl;
}
ִ�н��Ϊ��
45
*/
#include<iostream>
using namespace std;

int getpowerdsum(int a, int b);

int main(int argc, char** argv) {
	cout << getpowerdsum(9,10)<< endl;
}

#include<vector>
int getpowerdsum(int a, int b)
{
	vector<int> vector={1};
	int mask=0;//��λת����
	for(auto i=0 ;i<b;i++){

		for(int j = 0; j < vector.size(); ++j){

			int num=vector[j]*a+mask;

			vector[j]=(num)%10;

			mask=0;

			if(num>=10){

				mask=num/10;

				if(i+1>=vector.size()){

					vector.push_back(0);
					
				}
			}
		}
	}
	int sum=0;

	for(auto &i:vector){

		sum+=i;
		
	}
	return sum;
}