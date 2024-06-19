 #include<iostream>
 using namespace std;
 
 int BinarySearch(int a[],int l,int r,int key)
 {
     if(l<r)
     {
         int m = (l+r)/2;
         if(a[m]==key)    
         {
             return m;
         }
         else if(a[m]<key)
         {
             return BinarySearch(a,m+1,r,key);
         }
         else
         {
             return BinarySearch(a,l,m-1,key);    
         }
     }
     else
     {
         if(l==r)
         {
             if(a[l]==key)
             return l;
             else return -1;
         }
     }
     return -1;
     
 }
 
int main()
{
int a[9] = {10,11,12,45,89,130,170,190,200};

int key;
cout<<"Enter number to search \n";
cin>>key;

   for(int i=0 ;i<9 ;i++)
        {
    cout<<a[i]<<"\t" ;
        }
        
    cout<<endl;
    
int result = BinarySearch(a,0,8,key);

if(result ==-1)
{
  cout <<"Data Not found !!!";    
}
else
{
        cout<<"Data found in "<<result<<" index";
}


        
return 0;

}
