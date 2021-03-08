#include<stdio.h>
#include<iostream>
using namespace std ;

int visited[4][3] = {{0,0,0},
				{0,1,0},
				{0,0,0},
				{0,0,0}
				} ;
string Result[10000] ;

int minCount =  10000000 ;
bool FindPrince(int arr[][3] , int n , int i , int j,int count,string list[]) ;

bool FindPrinceUP(int arr[][3] , int n, int i , int j ,int count ,string list[]) {
	visited[i][j] =  1 ; 
	if(arr[i][j]=='p')
	{
	
		
		if( minCount >= count ){
			minCount = count ;
			for(int kk = 0 ; kk < count ; kk++){
				Result[kk] = list[kk] ;
			}
		}
		
	
		return 1 ;
	}
	else if (i < n && j < 3 &&i >= 0 && j>=0 ){
		
	
		int flag[4]={0,0,0} ;
		//////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////
		if(i-1>= 0 && visited[i+1][j]==0){
			flag[0]=1;
			
			int visdown[n][3] ;
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visdown[k][l] = visited[k][l];
				}
			}
		
			list[count]="Up" ;
			int ii = FindPrinceUP(arr,n , i-1 , j,count+1,list);
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visited[k][l] = visdown[k][l];
				}
			}
			
			
		}
		//////////////////////////////////////////////////////////
		if(j+1 < 3 && visited[i][j+1]==0){
			flag[1]=1;
			
			int visdown[n][3] ;
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visdown[k][l] = visited[k][l];
				}
			}
			list[count]="left" ;
			int ii = FindPrinceUP(arr,n , i , j-1,count+1,list);
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visited[k][l] = visdown[k][l];
				}
			}
			
			
		}
		//////////////////////////////////////////////////////////
		if(j-1 >=0 && visited[i][j-1]==0){
		
			flag[2]=1;
			int visdown[n][3] ;
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visdown[k][l] = visited[k][l];
				}
			}
			
			list[count]="right" ;
			int ii = FindPrinceUP(arr,n , i , j-1,count+1,list);
		
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visited[k][l] = visdown[k][l];
				}
			}
			
		
		}
		//////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////
		
		if(flag[0]==0 and flag[1]==0 and flag[2]==0){
		
			return 0 ;
		}
			
	}
	else {
		
		
		return 0 ;
	}
}

				
bool FindPrinceDown(int arr[][3] , int n, int i , int j ,int count,string list[]) {
	visited[i][j] =  1 ; 
	if(arr[i][j]=='p')
	{
		
	
		if( minCount >= count ){
			minCount = count ;
			for(int kk = 0 ; kk < count ; kk++){
				Result[kk] = list[kk] ;
			}
		}
	
		return 1 ;
	}
	else if (i < n && j < 3 &&i >= 0 && j>=0 ){
		
	
		int flag[4]={0,0,0} ;
		//////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////
		if(i+1<n && visited[i+1][j]==0){
			flag[0]=1;
		
			int visdown[n][3] ;
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visdown[k][l] = visited[k][l];
				}
			}
			
			list[count]="Down" ;
			int ii = FindPrinceDown(arr,n , i+1 , j,count+1,list);
			
			
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visited[k][l] = visdown[k][l];
				}
			}
			
		
		}
		//////////////////////////////////////////////////////////
		if(j+1 < 3 && visited[i][j+1]==0){
			flag[1]=1;
			
		int visdown[n][3] ;
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visdown[k][l] = visited[k][l];
				}
			}
			list[count]="Left" ;
			int ii = FindPrinceDown(arr,n , i+1 , j,count+1,list);
			
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visited[k][l] = visdown[k][l];
				}
			}
			
			
		}
		//////////////////////////////////////////////////////////
		if(j-1 >=0 && visited[i][j-1]==0){
			flag[2]=1;
		
			int visdown[n][3] ;
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visdown[k][l] = visited[k][l];
				}
			}
			list[count]="right" ;
			int ii = FindPrinceDown(arr,n , i , j-1,count+1,list);
			
			
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visited[k][l] = visdown[k][l];
				}
			}
			
			
		}
		
		//////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////
		if(flag[0]==0 and flag[1]==0 and flag[2]==0){
			
			return 0 ;
		}
			
	}
	else {
		
		
		return 0 ;
	}
}

bool FindPrince(int arr[][3] , int n, int i , int j ,int count , string list[]) {
	
	
	visited[i][j] =  1 ; 
	
	
	if(arr[i][j]=='p')
	{
	
		
			
		if( minCount >= count ){
			minCount = count ;
			
			for(int kk = 0 ; kk < count ; kk++){
		
				Result[kk] = list[kk] ;
			}
		}
		count = 0 ;
	
		return 1 ;
	}
	else if (i < n && j < 3 &&i >= 0 && j>=0 ){
		
	
		int flag[4]={0,0,0} ;
		
		//////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////
		if(i+1<n && visited[i+1][j]==0){
			
			flag[0]=1;
			
			
			int visdown[n][3] ;
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					
					visdown[k][l] = visited[k][l];
				}
			}
			
			list[count]="Down" ;
			int ii = FindPrinceDown(arr,n , i+1 , j,count+1,list);
			
			
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					
					visited[k][l] = visdown[k][l];
				
				}
			
			}
			
		}
		
		//////////////////////////////////////////////////////////
		if(j+1 < 3 && visited[i][j+1]==0){
			flag[1]=1;
		
			int visdown[n][3] ;
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visdown[k][l] = visited[k][l];
				}
			}
			list[count]="Right" ;
			int ii = FindPrince(arr,n , i , j+1,count+1,list);
			
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visited[k][l] = visdown[k][l];
				}
			}
			
			
		}
	
		
		//////////////////////////////////////////////////////////
		if(j-1 >=0 && visited[i][j-1]==0){
			flag[2]=1;
		
			
			int visdown[n][3] ;
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visdown[k][l] = visited[k][l];
				}
			}
			
			list[count]="left" ;
			int ii = FindPrince(arr,n , i , j-1,count+1,list);
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visited[k][l] = visdown[k][l];
				}
			}
			
				
		}
		
		//////////////////////////////////////////////////////////
		if(i-1 >= 0 && visited[i-1][j]==0){
			flag[3]=1;
		
			int visdown[n][3] ;
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visdown[k][l] = visited[k][l];
				}
			}
			
			list[count]="UP" ;
			int ii = FindPrinceUP(arr,n , i-1 , j,count+1,list);
			
			
			for(int k = 0 ; k < n ; k++ ){
				for(int l = 0 ; l<3 ; l++){
					visited[k][l] = visdown[k][l];
				}
			}
			
			
		}
		
		//////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////
		if(flag[0]==0 and flag[1]==0 and flag[2]==0 and flag[3]==0){
		
			return 0 ;
		}
			
	}
	else {
		
		
		return 0 ;
	}
}
int main(){
	int n = 4;
	int array[n][3] = {
		{1,'p',1},
		{1,'m',1},
		{1,1,1},
		{1,1,1}}
		;
		string list[100000] ;
	
		int re = FindPrince(array,n,1,1,0,list) ;
		
		if(re == 1){
			
			cout<<"\n\n\n\n Question\n\n" ;
			
		
			for(int k = 0 ; k < n ; k++ ){
					for(int l = 0 ; l<3 ; l++){
						cout<<array[k][l]<<" " ;
					}
					cout<<"\n" ;
				}
			
		
			cout<<" Answer\n\n" ;
			
			for(int i = 0 ; i < minCount ; i++){
				
				cout<<Result[i]<<" " ;
			}	
		}
		
}
