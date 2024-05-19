
#include<bits/stdc++.h>
using namespace std;


mt19937 seed(time(0));
uniform_real_distribution<float> distribution(0, 1);



double rectangle_area(double x1, double y1, double x2, double y2){
	double area;
	area=(x2-x1)*(y2-y1);
	return area;
}

///////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
bool is_it_between(double boundary1, double boundary2, double value) {
    bool result = false;
    if (value < boundary2 && boundary1 < value) {
        result= true;
    }

    return result;
}


bool is_it_same(double m_site1, double n_site1, double m_site2, double n_site2){
	bool result = false;
	if(m_site1==n_site2){
		return true;
	}
	if(m_site2==n_site1){
		return true;
	}
	if((m_site1==0.0 && n_site2==1.0) || (m_site1==1.0 && n_site2==0.0)){
		return true;
	}
	if((m_site2==0.0 && n_site1==1.0) || (m_site2==1.0 && n_site1==0.0)){
		return true;
	}
	return result;
}


bool is_neighbour(double a_site1, double b_site1, double c_site1, double d_site1, double a_site2, double b_site2, double c_site2, double d_site2, int site1, int site2){
	bool result = false;
	bool x_same = false;
	bool y_same = false;
	if(is_it_same(b_site1, d_site1, b_site2, d_site2)==1){
		y_same=true;
	}
	
	if(is_it_same(a_site1, c_site1, a_site2, c_site2)==1){
		x_same=true;
	}
	
	if(y_same){
		if(is_it_between(a_site1, c_site1, c_site2)||is_it_between(a_site2,c_site2,c_site1)){
			return true;
		}
		if(is_it_between(a_site1, c_site1, a_site2)||is_it_between(a_site2,c_site2,a_site1)){
			return true;
		}
		if(a_site1==a_site2 && c_site1==c_site2 && site1 != site2){
			return true;
		}
	
	}
	
	if(x_same){
		if(is_it_between(b_site1, d_site1, d_site2)||is_it_between(b_site2,d_site2,d_site1)){
			return true;
		}
		if(is_it_between(b_site1, d_site1, b_site2)||is_it_between(b_site2,d_site2,b_site1)){
			return true;
		}
		if(b_site1==b_site2 && d_site1==d_site2 && site1 != site2){
			return true;
		}
	
	
	}
	
	
	return result;
}



double x_cube(vector<double> a, vector<double> c){
	double sum=0.0, absVal, m, n;
	for(int i=0;i<a.size();i++){
		
		m=a.at(i);
		
		n=c.at(i);
		
		absVal=abs(m-n);
		sum=sum+pow(absVal, 3);
	}
	return sum;
}

double calculate_moment(vector<double> a, vector<double> b, vector<double> c, vector<double> d, int n){
	double sum=0.0, xAbsVal, yAbsVal, p , q, r, s, width_power = (4.0 / n) - 1.0;
	for(int i=0;i<a.size();i++){
		
		p=a.at(i);
		
		q=c.at(i);
		
		r=b.at(i);
		
		s=d.at(i);
		
		xAbsVal=abs(p-q);
		yAbsVal=abs(r-s);
		sum+=(pow(xAbsVal, n-1)*pow(yAbsVal, width_power));
	}
	return sum;
}


double no_of_rectangles(vector<double> a){
	return a.size();
}

double moments(vector<double> a, vector<double> b, vector<double> c, vector<double> d, double n) {
    double result = 0.0;
    double length = 0.0;
    double width = 0.0;
    double width_power = 0.0;
    for (int i = 0; i < a.size(); i++) {
        length=a[i]-c[i];
        width=b[i]-d[i];
        width_power = (4.0 / n) - 1.0;
        result += pow(length, n-1)*pow(width,width_power);
    }
    return result;
}


/////////////////////////////////


int main(){
	srand(time(0));
	
	double toss=distribution(seed);
	
	
	ofstream file;
	file.open("ngbr.dat");
	
	ofstream f1;
	f1.open("l.dat");
	
	ofstream f2;
	f2.open("file.dat");
	
	ofstream f3;
	f3.open("x_cube.dat");
	
	ofstream f4;
	f4.open("moment.dat");
	
	int N;
	cout<<"ENTER THE VALUE OF TIME: "<<endl;
	cin>>N;
	
	int mmnt;
	cout<<"MOMENT="<<endl;
	cin>>mmnt;
	
	
	vector<double> a;
	vector<double> b;
	vector<double> c;
	vector<double> d;
	vector<double> area;
	vector<double> ngbr;
	vector<double> dstr;
	vector<double> ngbr2;
	vector<double> xcube;
	vector<double> moment;
	vector<double> rectno;
	
	double ia=0.0;
	double ib=0.0;
	double ic=1.0;
	double id=1.0;
	
	
	
	double x=distribution(seed);
	double y=distribution(seed);
	
	
	
	
	a.push_back(ia);
	b.push_back(ib);
	c.push_back(ic);
	d.push_back(id);
	area.push_back(1.0);
	
	
	a.at(0)=ia;
	b.at(0)=ib;
	c.at(0)=x;
	d.at(0)=y;
	area.at(0)=rectangle_area(ia,ib,x,y);
	
	a.push_back(x);
	b.push_back(ib);
	c.push_back(ic);
	d.push_back(y);
	area.push_back(rectangle_area(x,ib,ic,y));
	
	
	a.push_back(x);
	b.push_back(y);
	c.push_back(ic);
	d.push_back(id);
	area.push_back(rectangle_area(x,y,ic,id));
	
	a.push_back(ia);
	b.push_back(y);
	c.push_back(x);
	d.push_back(id);
	area.push_back(rectangle_area(ia,y,x,id));
	
	
	double sum=0.0;
	
	for(int i=0;i<4;i++){
	
		sum=sum+area.at(i);
	}
	
	/////////
	
	
	
	for(int k=0;k<N;k++){
			double largest=0.0;
			double index=0;
			for(int i=0;i<area.size();i++){
				if(area.at(i)>largest){
					largest=area.at(i);
					index=i;
				}
			}
			
			
			
			double na=a.at(index);
			double nb=b.at(index);
			double mc=c.at(index);
			double md=d.at(index);
			double x1=distribution(seed);
			double y1=distribution(seed);
			
			x=na+(mc-na)*distribution(seed);
			y=nb+(md-nb)*distribution(seed);
			
			
			
			a.at(index)=na;
			b.at(index)=nb;
			c.at(index)=x;
			d.at(index)=y;
			area.at(index)=rectangle_area(na,nb,x,y);
			
			a.push_back(x);
			b.push_back(nb);
			c.push_back(mc);
			d.push_back(y);
			area.push_back(rectangle_area(x,nb,mc,y));
			
			
			a.push_back(x);
			b.push_back(y);
			c.push_back(mc);
			d.push_back(md);
			area.push_back(rectangle_area(x,y,mc,md));
			
			a.push_back(na);
			b.push_back(y);
			c.push_back(x);
			d.push_back(md);
			area.push_back(rectangle_area(na,y,x,md));
			
			/////////////
			
			xcube.push_back(x_cube(a,c));
			rectno.push_back(no_of_rectangles(a));
			moment.push_back(calculate_moment(a,b,c,d,mmnt));
			//moment.push_back(moments(a,b,c,d,3));
			/////////////
		}
			
		sum=0.0;
	
		for(int i=0;i<area.size();i++){
			//area.at(i)=rectangle_area(a.at(i),b.at(i),c.at(i),d.at(i));
			//cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<"      "<<area.at(i)<<endl;
			f2<<"set object rect from "<<a[i]<<","<<b[i]<<" to "<<c[i]<<","<<d[i]<<endl;
			sum=sum+area.at(i);
			
			
		}
		
		f2<<"set xr [0:1]"<<endl;
		f2<<"set yr [0:1]"<<endl;
		//cout<<"done"<<endl;
			
		
		//cout<<"area:  "<<rectangle_area(a.at(0),b.at(0),c.at(0),d.at(0))<<endl;
		cout<<"sum   :"<<sum<<endl;
			
		//cout<<"///////////////////////////////////////////////////////////////////////////////////////////"<<endl;	
		for(int i=0;i<area.size();i++){
				double count=0.0;
				double ct=0.0;
				for(int k=0;k<area.size();k++){
					/*
					if(if_neighbour(a[i],b[i],c[i],d[i],a[k],b[k],c[k],d[k])==1){
						count=count+1;
						
					}
					*/
					if(is_neighbour(a[i],b[i],c[i],d[i],a[k],b[k],c[k],d[k],i,k)==1){
						ct=ct+1;
					}
				
			}
			ngbr.push_back(count);
			ngbr2.push_back(ct);
		}
			
		
		
		
		int largest_value=0;
		for(int i=0;i<ngbr2.size();i++){
			if(ngbr2.at(i)>largest_value){
				largest_value=ngbr2.at(i);
			}
		}
		
		//cout<<" largest_value: "<<largest_value<<endl;
		
		
		
		
		for(int i=0;i<largest_value;i++){
			double num=0;
			for(int k=0;k<ngbr2.size();k++){
				if(ngbr2.at(k)==i){
					num=num+1;
				}
			}
			dstr.push_back(num);
		}
		
		
		for(int k=4;k<largest_value;k++){
			//cout<<k<<" "<<dstr.at(k)<<endl;
			file<<k<<" "<<dstr.at(k)<<endl;
			f1<<log(k)<<" "<<log(dstr.at(k))<<endl;
		}
		
		
		for(int i=0;i<xcube.size();i++){
			f3<<rectno.at(i)<<" "<<xcube.at(i)<<endl;
			f4<<rectno.at(i)<<" "<<moment.at(i)<<endl;
		
		}
		
		
	
		
	
	
	vector<vector<double>> vec;
	vec.push_back(rectno);
	vec.push_back(moment);
			
	file.close();	
	f1.close();	
	f2.close();
	f3.close();
	f4.close();		
			
			
			
			
	
	
	return 0;
}
