#include<cstdio>
#include<stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;
    int expon;
    Polynomial link;
};

Polynomial ReadPoly();
void PrintPoly(Polynomial P);
void Attach( int c , int e , Polynomial *pRear);
Polynomial Mult( Polynomial P1 , Polynomial P2 );
Polynomial Add( Polynomial P1 , Polynomial P2 );

int main()
{
    Polynomial P1,P2,PP,PS;
    P1 = ReadPoly();
    P2 = ReadPoly();

    PP = Mult( P1 , P2 );
    PrintPoly(PP);

    PS = Add( P1 , P2 );
    PrintPoly(PS);

    return 0;
}

Polynomial ReadPoly()
{
    Polynomial P1=(Polynomial)malloc(sizeof(struct PolyNode));
    Polynomial Rear = P1;
    int c,e,N;

    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    Polynomial tem = P1;
    P1=P1->link;
    free(tem);
    return P1;

}
void PrintPoly(Polynomial P)
{
	int flag = 0;
	if (!P)
	{
		printf("0 0\n");
		return;
	}
	while (P)
	{
		if (!flag)
		{
			flag = 1;
		}
		else
		{
			printf(" ");
		}
		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
	printf("\n");
}
void Attach( int c , int e , Polynomial *pRear)
{
    Polynomial P;
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link=NULL;
    (*pRear)->link = P;
    *pRear = P;
}
Polynomial Mult( Polynomial P1 , Polynomial P2 )
{
    /*P1,P2有一个为空，返回NULL*/
    if(!P1||!P2){
        return NULL;
    }
    /*这两种情况也返回NULL*/
    if((P1->coef==0&&P1->expon==0)||(P2->expon==0&&P2->coef==0)){
        return NULL;
    }
    int c,e,ctem,etem;
    Polynomial t1 = P1,t2 = P2, Rear ,Rearbef ,tem;
    Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
    int flag = 0;
    P->link = NULL;
    Rear = P;
    /*插入法的思想*/
    while (t2)
    {
        c = t1->coef * t2->coef;
        e = t1->expon + t2->expon;
        /*系数相乘不可能事0*/
        Attach(c,e,&Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while(t1){
        t2 = P2;
        while(t2){
            //计算此项的系数和指数
            ctem = t1->coef * t2->coef;
            etem = t1->expon + t2->expon;
            //遍历当前链表，找到适合的插入位置
            Rear = P->link;
            Rearbef = P;
            while(Rear){
                flag = 0;
                if(Rear->expon == etem){
                    ctem += Rear->coef;
                    if(ctem!=0){
                        //若系数不为0，直接修改系数
                        Rear->coef=ctem;
                        t2 = t2->link;
                        break;
                    }else{
                        //若系数为0，则直接删除该结点
                        tem = Rear;
                        Rearbef->link = Rear->link;
                        free(tem);
                        t2 = t2->link;
                        flag = 1;
                        break;
                    }
                }else{
                    //若链表某一项的指数 > 当前的指数，说明要插入的点需要向后寻找
                    if(Rear->expon > etem){
                        Rearbef = Rear;
                        Rear = Rear->link;
                    }else{
                        //说明插入的位置在该位置的前一位
                        Polynomial X = (Polynomial)malloc(sizeof(struct PolyNode));
                        X->coef = ctem;
                        X->expon = etem;
                        X->link = Rear;
                        Rearbef->link = X;
                        t2=t2->link;
                        break;
                    }
                }
            }
            //若遍历到NULL还是没有找到合适的位置，则插入到最后一个
			if (Rear == NULL && flag == 0)
			{
				Polynomial x = (Polynomial)malloc(sizeof(struct PolyNode));
				x->coef = ctem;
				x->expon = etem;
				x->link = NULL;
				Rearbef->link = x;
				t2 = t2->link;
			}
        }
        //遍历下一个
        t1 = t1->link;
        
    }
    //去掉头结点，并且释放空间
	tem = P;
	P = P->link;
	free(tem);
	return P;
    
}
Polynomial Add( Polynomial P1 , Polynomial P2 )
{
    int e,c,coeftem;
    Polynomial Rear,tem;
    Polynomial t1 = P1 , t2 = P2;
    Polynomial P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link=NULL;
    Rear = P;
    //当t1,t2都不为空，开始遍历
    while(t1&&t2)
    {
        //t1系数大于t2系数
        if(t1->expon>t2->expon){
            //新建结点存储当前t2，插入到链表尾
            e = t1->expon;
            c = t1->coef;
            Attach(c,e,&Rear);
            t1=t1->link;
        }
        //t1系数大于t2系数
		else if (t1->expon < t2->expon)
		{
			//新建结点存储当前t2，插入到链表尾
			c = t2->coef;
			e = t2->expon;
			Attach(c, e, &Rear);
			t2 = t2->link;
		}
        //t1系数等于t2系数
		else{
            coeftem = t1->coef + t2->coef;
            //若系数不为0，则创建结点
            if(coeftem){
                c = coeftem;
                e = t2->expon;
                Attach(c,e,&Rear);
                
            }
            //向下遍历
                t1 = t1->link;
                t2 = t2->link;
        }

    }
    //当t1,t2其中之一为NULL，则将剩余全部插入到链表尾部
    while (t1)
	{
		c = t1->coef;
		e = t1->expon;
		Attach(c, e, &Rear);
		t1 = t1->link;
	}
	while (t2)
	{
		c = t2->coef;
		e = t2->expon;
		Attach(c, e, &Rear);
		t2 = t2->link;
	}
    //去掉头结点，并释放空间
    tem = P;
    P = P->link;
    free(tem);
    return P;
}