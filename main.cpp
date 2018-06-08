#include <iostream>
#include <cmath>
#include <stdlib.h>
#define pi 3.141592654
using namespace std;

long double limit=1e-15, a=1.0, result=0.0, a2 =1.0, a3;
int n=1, counter;

void e_power_x(double x, long double &a, long double &a2, long double& result, int& n);
void ln(double x,long double &a,long double &result,int &n);
void sinn(double x,long double &a,long double &result,int &n,int &counter);
void cosin(double x,long double &a,long double &result,int &n,int &counter);


void tan_inv(double x,long double &a,long double &result,int &n,int &counter,long double &a2)
{

    a*=x*x*(-1);
    result+=a/((2*n)+1);
    if(fabs(result-a3)>limit){
        return;
    }
    else{
        a3=result;
        n++;
        tan_inv(x,a,result,n,counter,a2);
    }



}




int main()
{
    cout<<"            Calculating Using Maclaurin Series\n\n";
    cout<<"                             By:\n\n";
    cout<<"            Salma Essam Soliman        20170115\n\n";
    cout<<"            Shereen Hassan Mohammed    20170130\n\n";
    cout<<"------------------------------------------------------------\n\n";
    cout<<"Please choose what you want to calculate:\n";
    cout<<"\n1) e^x\n2) ln(1+x)\n3)sin(x)\n4)cos(x)\n5)tan^-1(x)\n";
    char choice;
    cout<<"\nPlease enter your choice:\n>>";
    cin>>choice;
    while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5')
    {
        cout<<"Please choose 1,2,3,4 or 5:\n>>";
        cin>>choice;
    }
    cout<<"\nPlease enter the value of x:\n>>";
    long double x;
    cin>>x;

    if(choice=='1')
    {
        while(x<0){
            cout<<"Please choose a value of x that belongs between 0 and positive infinity:\n>>";
            cin>>x;
        }
        result+=1;
        e_power_x(x,a,a2,result,n);
    }
    else if(choice=='2')
    {
        while(x>=1||x<=-1){
            cout<<"Please choose a value of x which belongs to ]-1,1[ :\n>>";
            cin>>x;
        }
        ln(x,a,result,n);
    }
    else if(choice=='3')
    {
         int yes=0;
        for(double degree=180.0;degree<=x;degree+=180){
            if(degree==x){
                result=0;
                yes=1;
                break;
            }
        }
        for(double degree2=-180.0;degree2>=x;degree2-=180){
             if(degree2==x){
                result=0;
                yes=1;
                break;
            }
        }
        if(yes==0){
        x*=(pi/180.0);
        counter=1;
        sinn(x,a,result,n,counter);
    }
    }
    else if(choice=='4')
    {
        int yes=0;
        for(double degree=90.0;degree<=x;degree+=180){
            if(degree==x){
                result=0;
                yes=1;
                break;
            }
        }
        for(double degree2=-90.0;degree2>=x;degree2-=180){
             if(degree2==x){
                result=0;
                yes=1;
                break;
            }
        }
        if(yes==0){

        x*=(pi/180.0);
        result=1;
        a=x;
        n=2;
        counter=1;
        cosin(x,a,result,n,counter);
        }
    }
    else if(choice=='5')
    {
        while(x>1||x<-1){
            cout<<"Please let x = [-1,1] :\n>>";
            cin>>x;
        }
        if(x==1){
            result=45;
        }
        else if(x==-1){
            result=-45;
        }
        else{
        counter=1;
        a=x;
        result=x;
        tan_inv(x,a,result,n,counter,a2);
        result*=(180.0/pi);
        }

    }

    cout<<"\nThe final result = "<<result<<endl;






    return 0;
}

void e_power_x(double x,long double &a,long double &a2,long double& result,int& n)
{

    a*=(x/n);
    result+=a;
    a3=result-a2;
    if(a3<=limit)
    {
        return;
    }
    else
    {
        n++;
        a2=result;
        e_power_x(x,a,a2,result,n);
    }

}


void ln(double x,long double &a,long double &result,int &n)
{

    a*=x;
    long double temp=a/n;

    if(n%2==0)
    {
        result-=temp;
    }
    else
    {
        result+=temp;
    }
    if(temp<=limit)
    {
        return;
    }
    else
    {

        n++;
        ln(x,a,result,n);
    }

}

void sinn(double x,long double &a,long double &result,int &n,int &counter)
{

    a*=x/n;

   if(n%2==1){
        if(counter%2==0)
    {
        a*=-1;
    }
    result+=a;
    if(counter%2==0)
    {
        a*=-1;
    }
    counter++;
   }

     if(abs(a)<=limit)
      {
          return;
      }
      else
      {

          n++;
          sinn(x,a,result,n,counter);
      }

}

void cosin(double x,long double &a,long double &result,int &n,int &counter)
{
    a*=x/n;
    if(n%2==0){
        if(counter%2==1){
            result-=a;
        }
        else{
            result+=a;
        }
        counter++;
    }
     if(abs(a)<=limit)
      {
          return;
      }
      else
      {

          n++;
          cosin(x,a,result,n,counter);
      }

}

