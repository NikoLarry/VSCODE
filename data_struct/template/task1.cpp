/* #include<iostream>
#include<string.h>
using namespace std;
    main(){
        char s1[100] = "I like C++ very much\n";
        char s2[100] ="";
        int len1,len2;
        cout<<strlen(s2);
        strcpy(s2,"Do you like C++ ?\n");
        strcat(s1,s2);
        strcat(s1,"yes i do.");
        if (strcmp(s1,s2)!=0){
            len1 = strlen(s1); 
            len2 = strlen(s2);
            cout<<s1<<endl;
        }
        system("pause");
        return 0;
    } */
    /*C调佣函数写法*/
/* #include<iostream>
#include<string>
using namespace std;
 main(){
    string s1 = "i like C++";
    string s2;
    s2 = "yes,i do";
    s1+=s2;
    int n = s1.length();
    cout<<s1<<endl;
    cout<<n<<endl;
    system("pause");
    return 0;
} */

#include<iostream>
#include<string>
using namespace std;
/* main(){
    int i,j,*p1,*p2;
    i = 1;
    j = 1;
    p1 = &i;
    p2 = &j;
    int n = i+j;
    int m = *p1+*p2;
    cout<<n<<endl;
    cout<<m<<endl;
    system("pause");
    return 0;
} */
/*int f(int n){
    int y = f(n-1)-2*f(n-2)+f(n-3);
    return y;
}*/
int main(){
    /*int n,y,a[100]={1,0,1};
    for(n=3;n<100;n++){
        y = f(n);
        a[n] = y;
        cout<<a[n]<<endl;
    }
    return 0;*/
    cout<<"hello world"<<endl;
    return 0;
}

