#include<bits/stdc++.h>
using namespace std;

#define N 4000

mt19937 seed(time(0));
uniform_real_distribution<double> distribution(0, 1);

////////////////////////////////////////////////////////////////////////////
struct output
{
   vector<int> A;
   vector<int> B;
};

struct output network_generator(int nodes, int edges) //return type is struct demo
{

   struct output output_member; 

  

   vector<int> a;
   vector<int> b;

   vector<int> c;
   vector<int> d;



   
   vector<int> index;

   for(int i=0;i<nodes;i++){
      a.push_back(i);
      b.push_back(i);
    
   }

   shuffle(a.begin(),a.end(),seed);
   shuffle(b.begin(),b.end(),seed);

   

   for(int i=0;i<nodes;i++){
      for(int j=0;j<nodes;j++){
       
         if((a.at(i)<b.at(j))){
            c.push_back(a.at(i));
            d.push_back(b.at(j));
         }
      }
   }

 

   for(int i=0;i<c.size();i++){
      
      index.push_back(i);
   }

   shuffle(index.begin(),index.end(),seed);


   for(int i=0;i<edges;i++){
      int num=index.at(i);
   
      output_member.A.push_back(c.at(num));
      output_member.B.push_back(d.at(num));
     
   }



   return output_member;
}
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////

int ptr[N];

void ptr_func(void){
   for(int i=0;i<N;i++){
      ptr[i]=-1;
   }
}

int findroot(int i){
   if(ptr[i]<0){
      return i;
   }
   
   return ptr[i]=findroot(ptr[i]);
}


int percolate(int a, int b) //return type is struct demo
{
   //struct demo demo_mem; //demo structure member declared

   
   int s1, s2;
   int r1, r2;
   int big=0;
   
   

   r1=findroot(a);
   r2=findroot(b);

   if(r2!=r1){
               
               if(ptr[r1]>ptr[r2]){
               
                  ptr[r2]=ptr[r2]+ptr[r1];
                  
                  ptr[r1]=r2;
                  
                  
                  r1=r2;
                  
               }else{
               
                  ptr[r1]=ptr[r1]+ptr[r2];
                  
                  ptr[r2]=r1;
                  
               }
            }

   for(int i=0;i<N;i++){
      if(-ptr[i]>big){
                  big=-ptr[i];
               }
   }

  
   return big;
}

////////////////////////////////////////////////////////////////////////////

int pi_func(int a, int b){
   int r1,r2, big;
   if(r1>0){
      r1=ptr[findroot(a)];
   }else{
      r1=ptr[a];
   }

   if(r2>0){
      r2=ptr[findroot(b)];
   }else{
      r2=ptr[b];
   }
   return (r1*r2);
}

////////////////////////////////////////////////////////////////////////////


struct demo
{
   //array declared inside structure
   //int arr[100];
   vector<int> vec;
};

////////////////////////////////////////////////////////////////////////////
//(int n)

//void exPerc
struct demo exPerc(vector<int> A, vector<int> B){

   struct demo demo_mem;

   ptr_func();

   int pi1, pi2, big=0, it=A.size();

   //cout<<"size of A "<<A.size()<<endl;


   for(int i=0;i<(it-2);i++){
      //cout<<"i. "<<i<<" "<<"A: "<<A.size()<<"    : ";
      first_task:
      int num=A.size();
      int index1=round((num-1)*distribution(seed));
      int index2=round((num-1)*distribution(seed));
      if(index1==index2){
         //cout<<"index "<<index1<<" "<<index2<<endl;
         goto first_task;
      }else{
         //cout<<"index "<<index1<<" "<<index2<<endl;

         pi1=pi_func(A.at(index1),B.at(index1));
         pi2=pi_func(A.at(index2),B.at(index2));

         if(pi1<pi2){
            big=percolate(A.at(index1),B.at(index1));
            A.erase(A.begin()+index1);
            B.erase(B.begin()+index1);
         }else{
            big=percolate(A.at(index2),B.at(index2));
            A.erase(A.begin()+index2);
            B.erase(B.begin()+index2);
         }
      }

      
      
      demo_mem.vec.push_back(big);


      //cout<<big<<endl;
   }



   
   return demo_mem;
   


}



int main(){

   ofstream file;
   file.open("exPerc.dat");

   struct output task;

   
   task=network_generator(N,N);
   //exPerc(task.A, task.B);

   ofstream file2;
   file2.open("networkPercolation.dat");
   //struct output task;

   
   //task=network_generator(N,N); 

   ptr_func();


   for (int i = 0; i < task.A.size(); i++) { 
     //cout<<task.A.at(i)<<" "<<task.B.at(i)<<endl;
      //cout<<i<<" "<<percolate(task.A.at(i),task.B.at(i))<<endl;
      file2<<(i*1.0/N)<<" "<<percolate(task.A.at(i),task.B.at(i))*1.0/N<<endl;
   }


   struct demo eP;
   //int Nor=5; //number of elements
   
   eP=exPerc(task.A,task.B); //address of arr
   
   //cout<<"The Vector is : ";
   for(int i=0;i<eP.vec.size();i++)
   {
      //cout<<a.vec.at(i)<<"\t";
      file<<(i*1.0)/N<<" "<<eP.vec.at(i)/(1.0*N)<<endl;
      //cout<<i<<" "<<eP.vec.at(i)<<endl;
   }
   
   cout<<"DONE!"<<endl;


   return 0;
}
