#include<stdio.h>
#include<stdlib.h>  //rand(), srand();
#include<time.h>    //time()
#include<string.h>  //memset()
void mkArr(int* arr, int size){
        int cnt = 0;
        int test[size];
        memset(test,0,size*4);
        srand(time(NULL));
        while(cnt<size){
                int num = rand()%size;
                if(test[num] == 0){
                        test[num] = 1;
                        arr[cnt] = num;
                        cnt++;
                }
        }
}
int main (int argc, char **argv){
	if (argc < 2)
		printf("argument only one\n");
	else if (argc > 2)
		printf("argument only one\n");
	int *arr;
	int ssize = atoi(argv[1]);
	arr = malloc(4 * ssize + 1);
        mkArr(arr,ssize);
        for(int i = 0; i<ssize; i++){
                printf("%d ",arr[i]);
        }
        return 0;
}
