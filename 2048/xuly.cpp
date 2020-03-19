//
//  xuly.cpp
//  2048
//
//  Created by Truong Nguyen on 5/12/18.
//  Copyright © 2018 Truong Nguyen. All rights reserved.
//

#include "xuly.hpp"
#include <cstdlib>
#include <ctime>
int randomNumber(){
    srand(time(NULL));
    int a=rand() % 20;
    if(a) return 2;
    else return 4;
}
void randomvitri( int a[6][6]){
    srand(time(NULL));
    int x, y;
    do{
        x=rand() % 4 + 1;
        y=rand() % 4 + 1;
    }while(a[x][y] != 0);
    a[x][y] = randomNumber();
    
}
void right(int a[6][6], int n){
    int b=0;
    int r=0;
    for(int k=1; k<n-1; k++){
        for(int m=1; m<5; m++){
            if(a[k][m] != 0){
                for(int l=m+1; l<5; l++){
                    if(a[k][l] == 0) r++;
                }
            }
        }
    }
    for(int k=4; k>0; k--){
        // don cac so ve dieu huong sang phai
        for(int m=4; m>0; m--){
            if(a[k][m]==0){
                int e=m-1;
                while(a[k][e] == 0 && e>0){
                    e--;
                }
                a[k][m]=a[k][e];
                a[k][e]=0;
                
                
            }
        }
    }
    for(int k=4; k>0; k--){
        for(int i=4; i>1; i--){
            if(a[k][i] == a[k][i-1] && a[k][i] != 0){
                b++;
            }
        }
    }
    //cong don cac so sang pha
    if(b != 0 ){
        for(int k=4; k>0; k--){
            for(int i=4; i>0; i--){
                if(a[k][i]==a[k][i-1]){
                    a[k][i]=a[k][i]*2;
                    for(int j=i-1; j>0; j--){
                        a[k][j]=a[k][j-1];
                    }
                }
            }
        }
        randomvitri(a);
    }
    else if(b ==0){
        if(r != 0){
            randomvitri(a);
        }
    }
}
void left(int a[6][6], int n){
    int b=0;
    int r=0;
    for(int k=1; k<n-1; k++){
        for(int m=4; m>0; m--){
            if(a[k][m] != 0){
                for(int l=m-1; l>0; l--){
                    if(a[k][l] == 0) r++;
                }
            }
        }
    }
    for(int k=1; k<n-1; k++){
        //don cac so ve dieu huong sang trai
        for(int m=1; m<n-1; m++){
            if(a[k][m]==0){
                int e=m+1;
                while(a[k][e] == 0 && e<5){
                    e++;
                }
                a[k][m]=a[k][e];
                a[k][e]=0;
            }
        }
    }
    for(int k=4; k>0; k--){
        for(int i=1; i<4; i++){
            if(a[k][i] == a[k][i+1] && a[k][i] != 0){
                b++;
            }
        }
    }
    if( b != 0){
        for(int k=1; k<n-1; k++){
            for(int i=1; i<=n-2; i++){
                if(a[k][i]==a[k][i+1]){
                    a[k][i]=a[k][i]*2;
                    for(int j=i+1; j<n-1; j++){
                        a[k][j]=a[k][j+1];
                    }
                }
            }
        }
        randomvitri(a);
    }
    else if( b ==0){
        if(r != 0){
            randomvitri(a);
        }
    }
}
void down(int a[6][6], int n){
    int b=0;
    int r=0;
    for(int k=1; k<n-1; k++){
        for(int m=1; m<5; m++){
            if(a[m][k] != 0){
                for(int l=m+1; l<5; l++){
                    if(a[l][k] == 0) r++;
                }
            }
        }
    }
    //don cac so ve huong dieu huong xuong
    for(int k=4; k>0; k--){
        for(int m=4; m>0; m--){
            if(a[m][k]==0){
                int e=m-1;
                while(a[e][k] == 0 && e>0){
                    e--;
                }
                a[m][k]=a[e][k];
                a[e][k]=0;
            }
        }
    }
    for(int k=1; k<5; k++){
        for(int i=4; i>1; i--){
            if(a[i][k] == a[i-1][k] && a[i][k] !=0){
                b++;
            }
        }
    }
    if( b!=0){
        // cong don cac so xuong
        for(int k=4; k>0; k--){
            for(int i=4; i>0; i--){
                if(a[i][k]==a[i-1][k]){
                    a[i][k]=a[i][k]*2;
                    for(int j=i-1; j>0; j--){
                        a[j][k]=a[j-1][k];
                    }
                }
            }
        }
        randomvitri(a);
    }
    else if( b == 0 ){
        if( r != 0){
            randomvitri(a);
        }
    }
}
void up(int a[6][6], int n){
    int b=0;
    int r=0;
    for(int k=1; k<n-1; k++){
        for(int m=4; m>0; m--){
            if(a[m][k] != 0){
                for(int l=m-1; l>0; l--){
                    if(a[l][k] == 0) r++;
                }
            }
        }
    }
    for(int k=1; k<n-1; k++){
        //don cac so ve huong dieu huong len tren
        for(int m=1; m<n-1; m++){
            if(a[m][k]==0){
                int e=m+1;
                while(a[e][k] == 0 && e<5){
                    e++;
                }
                a[m][k]=a[e][k];
                a[e][k]=0;
                
                
            }
        }
    }
    //cong don len tren
    for(int k=1; k<5; k++){
        for(int i=1; i<4; i++){
            if(a[i][k] == a[i+1][k] && a[i][k] !=0){
                b++;
            }
        }
    }
    if( b!=0){
        for(int k=1; k<n-1; k++){
            for(int i=1; i<=n-2; i++){
                if(a[i][k]==a[i+1][k]){
                    a[i][k]=a[i][k]*2;
                    for(int j=i+1; j<n-1; j++){
                        a[j][k]=a[j+1][k];
                        
                    }
                }
            }
        }
        randomvitri(a);
    }
    else if( b==0 ){
        if(r != 0){
            randomvitri(a);
        }
    }
}
