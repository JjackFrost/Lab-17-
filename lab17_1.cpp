#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *A, int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << A[i];
        if((i + 1) % M == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *A, int N, int M){
    for(int i = 0; i < N*M; i++){
        A[i] = (rand() % 101/100.0);
    }
}

void findRowSum(const double *o,double *p,int q,int r)
{
	for(int i = 0 ; i < q ; i++)
	{
		double j = 0 ;
	 	for(int k = 0 ; k < r ;k++)
		{
			j += *((o + k) + (r * i));
		}
		p[i] = j;
	} 
}

void findColSum(const double *o,double *p,int q,int r)
{
	int i = 0, j = 0;
	p[j] = 0;
	for(int m = 0 ; m < r ; m++)
	{
		i = m;
		for(int n = 0 ; n < q ; n++)
		{
			p[j] += o[i];
			i += r;
		}
		j++;
		p[j] = 0;
	}
}



