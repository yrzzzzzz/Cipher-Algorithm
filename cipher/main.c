#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void caesaren(){
    char pt[30];
    char ct[30];
    int key;
    printf("==========Caesar encryption==========\n");
    printf("plaintext:");
    scanf("%s",pt);
    printf("key=");
    scanf("%d",&key);
    for(int i=0;i<strlen(pt);i++){
        ct[i]=(pt[i]-'a'+key)%26+'a';
    }
    printf("ciphertext:");
    for(int i=0;i<strlen(pt);i++){
        printf("%c",ct[i]);
        
    }
    printf("\n==========Caesar encryption==========\n");
    
}
void caesarde(){
    char pt[30];
    char ct[30];
    int key;
    printf("==========Caesar decryption==========\n");
    printf("ciphertext:");
    scanf("%s",pt);
    printf("key=");
    scanf("%d",&key);
    printf("plaintext:");
    for(int i=0;i<strlen(pt);i++){
        ct[i]=((pt[i]-'a'-key)%26+26)%26+'a';
        printf("%c",ct[i]);
        
    }
    printf("\n==========Caesar decryption==========\n");
    
}



void Vigenereen(){
    int i,j;
    char pt[30];
    char ct[30];
    char Key[30];
    
    printf("==========Vigenere encryption==========\n");
    char matrix[26][26];
    char a='a';//build matrix
    int m=0,n=0;
    for(m=0;m<26;m++){
        for(n=0;n<26;n++){
            matrix[m][n]=a;
            a++;
            if(a>'z') a='a';
        }
        a='a'+m+1;
        if(a>'z') a='a';
    }
    printf("plaintext:");
    scanf("%s",pt);
    printf("key:");
    scanf("%s",Key);
    char tempcolumn[strlen(pt)];
    char temprow[strlen(pt)];
    int div=strlen(pt)/strlen(Key);
    int over=strlen(pt)%strlen(Key);
    for(int i=0;i<strlen(pt);i++)
    {
        tempcolumn[i]=Key[i]-97;
    }
    for(int i=0;i<strlen(pt);i++)
    {
        temprow[i]=pt[i]-97;
    }
    i=0;
    int w;
    if(strlen(pt)>strlen(Key)){
        i=0;
        for(int q=0;q<div;q++){
            for(w=0;w<strlen(Key);w++){
                tempcolumn[i]=Key[w]-97;
                i++;
            }
            i=i+strlen(Key)-w;
        }
        for(int q=0;q<over;q++){
            tempcolumn[i]=Key[q]-97;
            i++;
        }
    }
    printf("ciphertext:");
    for(int i=0;i<strlen(pt);i++)
    {
        ct[i]=matrix[temprow[i]][tempcolumn[i]];
        printf("%c",ct[i]);
    }
    printf("\n==========Vigenere encryption==========\n");
}



void Vigenerede(){
    int i,j;
    char pt[30];
    char ct[30];
    char Key[30];
    
    printf("==========Vigenere decryption==========\n");
    printf("ciphertext:");
    scanf("%s",ct);
    printf("key:");
    scanf("%s",Key);
    char tempcolumn[strlen(ct)];
    char temprow[strlen(ct)];
    int div=strlen(ct)/strlen(Key);
    int over=strlen(ct)%strlen(Key);
    for(int i=0;i<strlen(ct);i++)
    {
        tempcolumn[i]=Key[i]-97;
    }
    for(int i=0;i<strlen(ct);i++)
    {
        temprow[i]=ct[i]-97;
    }
    i=0;
    int w;
    if(strlen(ct)>strlen(Key)){
        i=0;
        for(int q=0;q<div;q++){
            for(w=0;w<strlen(Key);w++){
                tempcolumn[i]=Key[w]-97;
                i++;
            }
            i=i+strlen(Key)-w;
        }
        for(int q=0;q<over;q++){
            tempcolumn[i]=Key[q]-97;
            i++;
        }
    }
    for(int i=0;i<strlen(ct);i++){
        
        pt[i]=ct[i]-tempcolumn[i];
        if(pt[i]<97) pt[i]=pt[i]+26;
                printf("%c ",pt[i]);

    }

    printf("\n==========Vigenere decryption==========\n");
}


void matrixen()
{
    char pt[50];
    int klen;
    printf("==========Matrix encryption==========\n");
    printf("plaintext:");
    scanf("%s",pt);
    printf("length of key:");
    scanf("%d",&klen);
    int key[klen];
    if(strlen(pt)%klen!=0){
        while(strlen(pt)%klen!=0){
            strcat(pt,"%");
        }
    }
    printf("key:");
    for(int i=0;i<klen;i++)
        scanf("%d",&key[i]);
    int matrix[strlen(pt)/klen][klen];
    int o=0;
    for(int i=0;i<strlen(pt)/klen;i++){
        for(int j=0;j<klen;j++){
            matrix[i][j]=pt[o];
            o++;
        }
    }
    printf("matrix:\n");
    for(int i=0;i<strlen(pt)/klen;i++){
        for(int j=0;j<klen;j++){
            printf("%c\t",matrix[i][j]);
        }
        printf("\n");
    }
    printf("ciphertext:");
    for(int c=0;c<klen;c++){
    for(int i=0;i<strlen(pt)/klen;i++){
        printf("%c",matrix[i][key[c]-1]);
    }}



    printf("\n==========Matrix encryption==========\n");

}
void matrixde()
{
    char ct[50];
    int klen;
    printf("==========Matrix decryption==========\n");
    printf("ciphertext:");
    scanf("%s",ct);
    printf("length of key:");
    scanf("%d",&klen);
    int key[klen];
    printf("key:");
    for(int i=0;i<klen;i++)
        scanf("%d",&key[i]);
    int matrix[strlen(ct)/klen][klen];
    int o=0;
    for(int j=0;j<strlen(ct)/klen;j++){
        for(int i=0;i<klen;i++){
            matrix[i][key[j]-1]=ct[o];
            o++;
        }
    }
    

    printf("matrix:\n");
    for(int i=0;i<strlen(ct)/klen;i++){
        for(int j=0;j<klen;j++){
            printf("%c\t",matrix[i][j]);
        }
        printf("\n");
    }
    printf("plaintext:");
        for(int i=0;i<strlen(ct)/klen;i++){
            for(int o=0;o<klen;o++)
            printf("%c",matrix[i][o]);

}

    
    
    printf("\n==========Matrix decryption==========\n");
    
}
void main(){
        int function;
        printf("1.caesar encryption\n2.caesar decryption\n3.vigenere encryption\n4.vigenere decryption\n5.Matrix transposition encryption\n6.Matrix transposition decryption\nplesae choose the function:\n");
        scanf("%d",&function);
        switch (function) {
            case 1:
                caesaren();
                break;
            case 2:
                caesarde();
                break;
            case 3:
                Vigenereen();
                break;
            case 4:
                Vigenerede();
                break;
            case 5:
                matrixen();
                break;
            case 6:
                matrixde();
                break;
            default:
                break;
        }
}


