#include<bits/stdc++.h>
using namespace std;


double coinToss(void){
	double randomNumber;
	randomNumber=(rand()/(1.0*RAND_MAX));

	return randomNumber;
}

int main(){
	srand(time(0));
	
	ofstream file;
	file.open("1.txt");
	
	ofstream fout;
	fout.open("log_log.txt");

	//cout<<coinToss()<<endl;
	int N=500;
	int E=25000000;
	int a[N]={0};
	
	
	for(int k=0;k<E;k++){
		int sum=0;
		for(int i=0;i<N;i++){
			double r=coinToss();
			if(r>0.5){
				sum=sum+1;
			}else{
				sum=sum-1;
			}
			if(sum==0){
				//cout<<i+1<<endl;
				a[i]=a[i]+1;
				break;
			}
		}
	}
	
	/*
	for(int i=0;i<N;i++){
		cout<<"m value"<<i+1<<" "<<a[i]<<endl;
		file<<(i+1)<<" "<<a[i]<<endl;
	}
	*/
	
	for(int i=1;i<N;i=i+2){
		//cout<<"m value"<<i+1<<" "<<a[i]<<endl;
		file<<(i+1)<<" "<<a[i]<<endl;
		fout<<log(i+1)<<" "<<log(a[i]/(1.0*E))<<endl;
	}
	
	return 0;
}
