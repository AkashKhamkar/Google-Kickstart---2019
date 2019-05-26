#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t,n,r,c,sr,sc,i;
    string str;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d%d%d%d",&n,&r,&c,&sr,&sc);
        cin>>str;
        int box[r][c];
        for(int j=1;j<=r;j++){
            for(int k=1;k<=c;k++){
                box[j][k]=0;
            }
        }
        box[sr][sc]=1;
        int p=sr,q=sc;
        for(int j=0;j<str.length();j++){
            ea: if((str[j]=='E')&&(box[p][q+1]==0)&&(q<c)){
                q=q+1;
                box[p][q]=1;
            }
            else if((str[j]=='E')&&(box[p][q+1]!=0)&&(q<c)){
                q++;
                goto ea;
            }
            wa: if((str[j]=='W')&&(box[p][q-1]==0)&&(q>1)){
                q=q-1;
                box[p][q]=1;
            }
            else if((str[j]=='W')&&(box[p][q-1]!=0)&&(q>1)){
                q--;
                goto wa;
            }
            qa: if((str[j]=='N')&&(box[p-1][q]==0)&&(p>1)){
                p=p-1;
                box[p][q]=1;
            }
            else if((str[j]=='N')&&(box[p-1][q]!=0)&&(p>1)){
                p--;
                goto qa;
            }
            ra: if((str[j]=='S')&&(box[p+1][q]==0)&&(p<r)){
                p=p+1;
                box[p][q]=1;
            }
            else if((str[j]=='S')&&(box[p+1][q]!=0)&&(p<r)){
                p++;
                goto ra;
            }
        }
        printf("Case #%d: %d %d",i+1,p,q);
    }
    return 0;
}